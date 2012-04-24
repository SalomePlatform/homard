# -*- coding: iso-8859-1 -*-
# Copyright (C) 2011-2012  CEA/DEN, EDF R&D
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License.
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
"""
Python script for HOMARD
Copyright EDF-R&D 2010
Test test_1
"""
__revision__ = "V1.6"

######################################################################################
Test_Name = "test_1"
n_iter_test_file = 3
######################################################################################
import os
import sys
import tempfile
import HOMARD
import salome
#
pathHomard=os.getenv('HOMARD_ROOT_DIR')
Rep_Test = os.path.join(pathHomard,"share/salome/resources/homard")
Rep_Test_Resu = tempfile.mktemp()
os.mkdir(Rep_Test_Resu)

salome.salome_init()
import iparameters
ipar = iparameters.IParameters(salome.myStudy.GetCommonParameters("Interface Applicative", 1))
ipar.append("AP_MODULES_LIST", "Homard")
######################################################################################
######################################################################################
def homard_exec(theStudy):
  """
Python script for HOMARD
Copyright EDF-R&D 2010
  """
  error = 0
#
  while not error :
  #
    homard.SetCurrentStudy(theStudy)
  #
  # Creation of the zones
  # =====================
  # Creation of the box Zone_1
    Zone_1 = homard.CreateZoneBox('Zone_1', -0.01, 1.01, -0.01, 0.4, -0.01, 0.6)

  # Creation of the sphere Zone_2
    Zone_2 = homard.CreateZoneSphere('Zone_2', 0.5, 0.6, 0.7, 0.75)
  #
  # Creation of the hypotheses
  # ==========================
  # Creation of the hypothesis a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM
    a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM = homard.CreateHypothesis('a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM')
    a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM.SetAdapRefinUnRef(1, 1, 0)
    a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM.SetField('RESU____ERRE_ELEM_SIGM__________')
    a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM.SetUseComp(0)
    a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM.AddComp('ERREST')
    a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM.SetRefinThr(3, 10.1)
    a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM.SetTypeFieldInterp(2)
    a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM.AddFieldInterp('RESU____DEPL____________________')
    a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM.AddFieldInterp('RESU____ERRE_ELEM_SIGM__________')
  # Creation of the hypothesis Zones_1_et_2
    Zones_1_et_2 = homard.CreateHypothesis('Zones_1_et_2')
    Zones_1_et_2.SetAdapRefinUnRef(0, 1, 0)
    homard.AssociateHypoZone('Zones_1_et_2', 'Zone_1', 1)
    homard.AssociateHypoZone('Zones_1_et_2', 'Zone_2', 1)
  #
  # Creation of the cases
  # =====================
    # Creation of the case zzzz121b
    Case_1 = homard.CreateCase('zzzz121b', 'MAILL', os.path.join(Rep_Test, Test_Name + '.00.med'))
    Case_1.SetDirName(Rep_Test_Resu)
    Case_1.SetConfType(1)
  #
  # Creation of the iterations
  # ==========================
  # Creation of the iteration I1
    I1 = homard.CreateIteration('I1', Case_1.GetIter0Name() )
    I1.SetMeshName('M1')
    I1.SetMeshFile(os.path.join(Rep_Test_Resu, 'maill.01.med'))
    I1.SetFieldFile(os.path.join(Rep_Test, Test_Name + '.00.med'))
    I1.SetTimeStepRank(1, 1)
    homard.AssociateIterHypo('I1', 'a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM')
    error = I1.Compute(1)
    if error :
      error = 1
      break

  # Creation of the iteration I2
    I2 = homard.CreateIteration('I2', 'I1')
    I2.SetMeshName('M2')
    I2.SetMeshFile(os.path.join(Rep_Test_Resu, 'maill.02.med'))
    I2.SetFieldFile(os.path.join(Rep_Test, Test_Name + '.01.med'))
    I2.SetTimeStepRank(1, 1)
    homard.AssociateIterHypo('I2', 'a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM')
    error = I2.Compute(1)
    if error :
      error = 2
      break

  # Creation of the iteration I3
    I3 = homard.CreateIteration('I3', 'I2')
    I3.SetMeshName('M3')
    I3.SetMeshFile(os.path.join(Rep_Test_Resu, 'maill.03.med'))
    homard.AssociateIterHypo('I3', 'Zones_1_et_2')
    error = I3.Compute(1)
    if error :
      error = 3
      break
  #
    break
  #
    return error

######################################################################################

homard = salome.lcc.FindOrLoadComponent('FactoryServer', 'HOMARD')
#
# Exec of HOMARD-SALOME
#
try :
  error_main = homard_exec(salome.myStudy)
  if error_main :
    raise Exception('Pb in homard_exec at iteration %d' %error_main )
except :
  raise Exception('Pb in homard_exec at iteration %d' %error_main )
  sys.exit(1)
#
# Test of the result
#
s_iter_test_file = str(n_iter_test_file)
test_file_suff = "apad.0" + s_iter_test_file + ".bilan"
rep_test_file = "I0" + s_iter_test_file
#
test_file = os.path.join(Rep_Test, Test_Name + "." + test_file_suff)
mess_error_ref = "\nReference file: " + test_file
try :
  file = open (test_file, "r")
  mess_ref = file.readlines()
  file.close()
except :
  mess_error = mess_error_ref + "\nThis file does not exist.\n"
  raise Exception(mess_error)
  sys.exit(2)
#
test_file = os.path.join(Rep_Test_Resu, rep_test_file, test_file_suff)
if os.path.isfile (test_file) :
   file = open (test_file, "r")
   mess = file.readlines()
   file.close()
else :
  mess_error  = "\nResult file: " + test_file
  mess_error += "\nThis file does not exist.\n"
  raise Exception(mess_error)
  sys.exit(2)

nblign = len(mess_ref)
if ( len(mess) != nblign ):
  mess_error = mess_error_ref +  "\nResult file: " + test_file
  mess_error += "\nThe number of lines of the files are not the same.\n"
  raise Exception(mess_error)
  sys.exit(2)

for num in range(nblign) :
   if (( "creation" not in mess_ref[num] ) and ( mess_ref[num] != mess[num])) :
       message_erreur = "\nRefe : " + mess_ref[num]
       message_erreur += "Test : " + mess[num][:-1]
       message_erreur += "\nThe test is different from the reference."
       raise Exception(message_erreur)
       sys.exit(10)
#
if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
  iparameters.getSession().restoreVisualState(1)

