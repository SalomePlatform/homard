#!/usr/bin/env python3
# Copyright (C) 2011-2024  CEA, EDF
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#

usage="""USAGE: runHOMARD.py [options]

[command line options] :
--help                        : affichage de l'aide
--gui                         : lancement du GUI
--logger                      : redirection des messages dans un fichier
--xterm                       : les serveurs ouvrent une fen??tre xterm et les messages sont affich??s dans cette fen??tre
--modules=module1,module2,... : o?? modulen est le nom d'un module Salome ?? charger dans le catalogue
--containers=cpp,python,superv: lancement des containers cpp, python et de supervision
--killall                     : arr??t des serveurs de salome

 La variable d'environnement <modulen>_ROOT_DIR doit etre pr??alablement
 positionn??e (modulen doit etre en majuscule).
 KERNEL_ROOT_DIR est obligatoire.
"""

# -----------------------------------------------------------------------------
#
# Fonction d'arr??t de salome
#

def killSalome():
   print("arret des serveurs SALOME")
   for pid, cmd in list(process_id.items()):
      print("arret du process %s : %s"% (pid, cmd[0]))
      try:
         os.kill(pid, signal.SIGKILL)
      except:
         print("  ------------------ process %s : %s inexistant"% (pid, cmd[0]))
   print("arret du naming service")
   os.system("killall -9 omniNames")
   
# -----------------------------------------------------------------------------
#
# Fonction message
#

def message(code, msg=''):
    if msg: print(msg)
    sys.exit(code)

import sys,os,string,glob,time,signal,pickle,getopt

init_time=os.times()
opts, args=getopt.getopt(sys.argv[1:], 'hmglxck:', ['help','modules=','gui','logger','xterm','containers=','killall'])
modules_root_dir={}
process_id={}
liste_modules={}
liste_containers={}
with_gui=0
with_logger=0
with_xterm=0

with_container_cpp=0
with_container_python=0
with_container_superv=0

try:
  for o, a in opts:
    if o in ('-h', '--help'):
      print(usage)
      sys.exit(1)
    elif o in ('-g', '--gui'):
      with_gui=1
    elif o in ('-l', '--logger'):
      with_logger=1
    elif o in ('-x', '--xterm'):
      with_xterm=1
    elif o in ('-m', '--modules'):
      liste_modules = [x.upper() for x in a.split(',')]
    elif o in ('-c', '--containers'):
      liste_containers = [x.lower() for x in a.split(',')]
      for r in liste_containers:
        if r not in ('cpp', 'python', 'superv'):
           message(1, 'Invalid -c/--containers option: %s' % a)
      if 'cpp' in liste_containers:
         with_container_cpp = 1
      else:
         with_container_cpp = 0
      if 'python' in liste_containers:
         with_container_python = 1
      else:
         with_container_python = 0
      if 'superv' in liste_containers:
         with_container_superv = 1
      else:
         with_container_superv = 0
    elif o in ('-k', '--killall'):
      filedict='/tmp/'+os.getenv('USER')+'_SALOME_pidict'
      #filedict='/tmp/'+os.getlogin()+'_SALOME_pidict'
      found = 0
      try:
         fpid=open(filedict, 'r')
         found = 1
      except:
         print("le fichier %s des process SALOME n'est pas accessible"% filedict)

      if found:
         process_id=pickle.load(fpid)
         fpid.close()
         killSalome()
         process_id = {}
         os.remove(filedict)

except getopt.error as msg:
  print(usage)
  sys.exit(1)

# -----------------------------------------------------------------------------
#
# V??rification des variables d'environnement
#
try:
  kernel_root_dir=os.environ["KERNEL_ROOT_DIR"]
  modules_root_dir["KERNEL"]=kernel_root_dir
except:
  print(usage)
  sys.exit(1)

for module in liste_modules :
   try:
      module=module.upper()
      module_root_dir=os.environ[module +"_ROOT_DIR"]
      modules_root_dir[module]=module_root_dir
   except:
      print(usage)
      sys.exit(1)

# il faut KERNEL en premier dans la liste des modules
# - l'ordre des modules dans le catalogue sera identique
# - la liste des modules presents dans le catalogue est exploit??e pour charger les modules CORBA python,
#   il faut charger les modules python du KERNEL en premier

if "KERNEL" in liste_modules:liste_modules.remove("KERNEL")
liste_modules[:0]=["KERNEL"]
#print liste_modules
#print modules_root_dir

os.environ["SALOMEPATH"]=":".join(list(modules_root_dir.values()))
if "SUPERV" in liste_modules:with_container_superv=1


# -----------------------------------------------------------------------------
#
# D??finition des classes d'objets pour le lancement des Server CORBA
#

class Server:
   CMD=[]
   if with_xterm:
     ARGS = ['xterm', '-iconic', '-sb', '-sl', '500', '-e']
   else:
      ARGS = []

   def run(self):
      args = self.ARGS+self.CMD
      #print "args = ", args
      pid = os.spawnvp(os.P_NOWAIT, args[0], args)
      process_id[pid]=self.CMD

class CatalogServer(Server):
   SCMD1=['SALOME_ModuleCatalog_Server','-common']
   home_dir=os.path.expanduser("~")
   SCMD2=['-personal',os.path.join(home_dir,'Salome', 'resources', 'CatalogModulePersonnel.xml')]

   def setpath(self,liste_modules):
      cata_path=[]
      for module in liste_modules:
          module_root_dir=modules_root_dir[module]
          module_cata=module+"Catalog.xml"
          print("   ", module_cata)
          cata_path.extend(glob.glob(os.path.join(module_root_dir,"share","salome","resources",module_cata)))
      self.CMD = self.SCMD1 + [':'.join(cata_path)] + self.SCMD2

class SalomeDSServer(Server):
   CMD=['SALOMEDS_Server']

class RegistryServer(Server):
   CMD=['SALOME_Registry_Server', '--salome_session','theSession']

class ContainerCPPServer(Server):
   CMD=['SALOME_Container','FactoryServer','-ORBInitRef','NameService=corbaname::localhost']

class ContainerPYServer(Server):
   CMD=['SALOME_ContainerPy.py','FactoryServerPy','-ORBInitRef','NameService=corbaname::localhost']

class ContainerSUPERVServer(Server):
   CMD=['SALOME_Container','SuperVisionContainer','-ORBInitRef','NameService=corbaname::localhost']

class LoggerServer(Server):
   CMD=['SALOME_Logger_Server', 'logger.log']

class SessionLoader(Server):
   CMD=['SALOME_Session_Loader']
   if with_container_cpp:
       CMD=CMD+['CPP']
   if with_container_python:
       CMD=CMD+['PY']
   if with_container_superv:
       CMD=CMD+['SUPERV']
   if with_gui:
       CMD=CMD+['GUI']

class SessionServer(Server):
   CMD=['SALOME_Session_Server']

class NotifyServer(Server):
   CMD=['notifd','-c','${KERNEL_ROOT_DIR}/share/salome/resources/channel.cfg -DFactoryIORFileName=/tmp/${LOGNAME}_rdifact.ior -DChannelIORFileName=/tmp/${LOGNAME}_rdichan.ior']

# -----------------------------------------------------------------------------
#
# Fonction de test
#

def test(clt):
   """
        Test function that creates an instance of PYHELLO component
        usage : pyhello=test(clt)
   """
   # create an LifeCycleCORBA instance
   import LifeCycleCORBA 
   lcc = LifeCycleCORBA.LifeCycleCORBA(clt.orb)
   import PYHELLO_ORB
   pyhello = lcc.FindOrLoadComponent("FactoryServerPy", "PYHELLO")
   return pyhello

# -----------------------------------------------------------------------------
#
# Fonctions helper pour ajouter des variables d'environnement
#

def add_path(directory):
   os.environ["PATH"]=directory + ":" + os.environ["PATH"]

def add_ld_library_path(directory):
   os.environ["LD_LIBRARY_PATH"]=directory + ":" + os.environ["LD_LIBRARY_PATH"]

def add_python_path(directory):
   os.environ["PYTHONPATH"]=directory + ":" + os.environ["PYTHONPATH"]
   sys.path[:0]=[directory]

# -----------------------------------------------------------------------------
#
# initialisation des variables d'environnement
#

python_version="python%d.%d" % sys.version_info[0:2]

#
# Ajout du chemin d'acces aux executables de KERNEL dans le PATH
#

add_path(os.path.join(kernel_root_dir,"bin","salome"))
#print "PATH=",os.environ["PATH"]

#
# Ajout des modules dans le LD_LIBRARY_PATH
#
for module in liste_modules:
    module_root_dir=modules_root_dir[module]
    add_ld_library_path(os.path.join(module_root_dir,"lib","salome"))
#print "LD_LIBRARY_PATH=",os.environ["LD_LIBRARY_PATH"]

#
# Ajout des modules dans le PYTHONPATH (KERNEL prioritaire, donc en dernier)
#

liste_modules_reverse=liste_modules[:]
liste_modules_reverse.reverse()
#print liste_modules
#print liste_modules_reverse
for module in liste_modules_reverse:
    module_root_dir=modules_root_dir[module]
    add_python_path(os.path.join(module_root_dir,"bin","salome"))
    add_python_path(os.path.join(module_root_dir,"lib",python_version,"site-packages","salome"))
    add_python_path(os.path.join(module_root_dir,"lib","salome"))
    add_python_path(os.path.join(module_root_dir,"lib",python_version,"site-packages","salome","shared_modules"))

#print "PYTHONPATH=",sys.path

import orbmodule

#
# -----------------------------------------------------------------------------
#

def startGUI():
  import SALOME
  session=clt.waitNS("/Kernel/Session",SALOME.Session)

  #
  # Activation du GUI de Session Server
  #

  session.GetInterface()
  
#
# -----------------------------------------------------------------------------
#

def startSalome():

  #
  # Lancement Session Loader
  #
  SessionLoader().run()

  #
  # Initialisation ORB et Naming Service
  #
  clt=orbmodule.client()

  # (non obligatoire) Lancement Logger Server et attente de sa 
  #  disponibilite dans le naming service
  #
  if with_logger:
    LoggerServer().run()
    clt.waitLogger("Logger")

  #
  # Lancement Registry Server
  #
  RegistryServer().run()

  #
  # Attente de la disponibilit?? du Registry dans le Naming Service
  #
  clt.waitNS("/Registry")

  #
  # Lancement Catalog Server
  #
  cataServer=CatalogServer()
  cataServer.setpath(liste_modules)
  cataServer.run()

  #
  # Attente de la disponibilit?? du Catalog Server dans le Naming Service
  #
  import SALOME_ModuleCatalog
  clt.waitNS("/Kernel/ModulCatalog",SALOME_ModuleCatalog.ModuleCatalog)

  #
  # Lancement SalomeDS Server
  #
  os.environ["CSF_PluginDefaults"]=os.path.join(kernel_root_dir,"share","salome","resources")
  os.environ["CSF_SALOMEDS_ResourcesDefaults"]=os.path.join(kernel_root_dir,"share","salome","resources")
  SalomeDSServer().run()

  if "GEOM" in liste_modules:
    print("GEOM OCAF Resources")
    os.environ["CSF_GEOMDS_ResourcesDefaults"] = os.path.join(modules_root_dir["GEOM"], "share", "salome", "resources")


  #
  # Attente de la disponibilit?? du SalomeDS dans le Naming Service
  #
  clt.waitNS("/Study")

  #
  # Lancement Session Server
  #
  SessionServer().run()

  #
  # Attente de la disponibilit?? du Session Server dans le Naming Service
  #
  import SALOME
  session=clt.waitNS("/Kernel/Session",SALOME.Session)

  #
  # Lancement containers
  #
  theComputer = os.getenv("HOSTNAME")
  theComputer = theComputer.split('.')[0]

  #
  # Lancement Container C++ local
  #
  if with_container_cpp:
    ContainerCPPServer().run()
    #
    # Attente de la disponibilit?? du Container C++ local
    # dans le Naming Service
    #
    clt.waitNS("/Containers/" + theComputer + "/FactoryServer")
  #
  # Lancement Container Python local
  #
  if with_container_python:
    ContainerPYServer().run()
    #
    # Attente de la disponibilit?? du Container Python local
    #  dans le Naming Service
    #
    clt.waitNS("/Containers/" + theComputer + "/FactoryServerPy")

  if with_container_superv:
    #
    # Lancement Container Supervision local
    #
    ContainerSUPERVServer().run()
    #
    # Attente de la disponibilit?? du Container Supervision local
    # dans le Naming Service
    #
    clt.waitNS("/Containers/" + theComputer + "/SuperVisionContainer")
  #
  # Activation du GUI de Session Server
  #
  #session.GetInterface()

  end_time = os.times()
  print()
  print("Start SALOME, elpased time : %5.1f seconds"% (end_time[4] - init_time[4]))

  return clt

#
# -----------------------------------------------------------------------------
#

if __name__ == "__main__":
   import codecs
   clt=None
   try:
      clt = startSalome()
   except:
      print()
      print()
      print("--- erreur au lancement Salome ---")
   
   #print process_id
   
   
   filedict='/tmp/'+os.getenv('USER')+'_SALOME_pidict'
   #filedict='/tmp/'+os.getlogin()+'_SALOME_pidict'
   
   with codecs.open(filedict, 'w') as fpid:
      pickle.dump(process_id, fpid)
   
   print("""

Sauvegarde du dictionnaire des process dans , %s
Pour tuer les process SALOME, executer : python killSalome.py depuis
une console, ou bien killSalome() depuis le present interpreteur,
s'il n'est pas ferm??.

runHOMARD, avec l'option --killall, commence par tuer les process restants 
d'une execution pr??c??dente.

Pour lancer uniquement le GUI, executer startGUI() depuis le present interpreteur,
s'il n'est pas ferm??.

""" % filedict)
   
   #
   #  Impression arborescence Naming Service
   #
   
   if clt != None:
     print()
     print(" --- registered objects tree in Naming Service ---")
     clt.showNS()
     session=clt.waitNS("/Kernel/Session")
     catalog=clt.waitNS("/Kernel/ModulCatalog")
     import socket
     container =  clt.waitNS("/Containers/" + socket.gethostname().split('.')[0] + "/FactoryServerPy")
   
   if os.path.isfile("~/.salome/pystartup"):
      with codecs.open(os.path.expanduser("~/.salome/pystartup")) as f:
          PYTHONSTARTUP = f.read()
   else:
      PYTHONSTARTUP="""
# Add auto-completion and a stored history file of commands to your Python
# interactive interpreter. Requires Python 2.0+, readline. Autocomplete is
# bound to the TAB key by default (you can change it - see readline docs).
#
# Store the history in ~/.salome/pyhistory,
#
import atexit
import os
import readline
import rlcompleter
readline.parse_and_bind('tab: complete')

historyPath = os.path.expanduser("~/.salome/pyhistory")

def save_history(historyPath=historyPath):
    import readline
    readline.write_history_file(historyPath)

if os.path.exists(historyPath):
    readline.read_history_file(historyPath)

atexit.register(save_history)
del os, atexit, readline, rlcompleter, save_history, historyPath
"""
      with codecs.open(os.path.expanduser("~/.salome/pystartup"), 'w') as f:
          f.write(PYTHONSTARTUP)

   exec(PYTHONSTARTUP, {})
