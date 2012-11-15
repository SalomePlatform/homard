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
Copyright EDF-R&D 2011
Test test_3
"""
__revision__ = "V1.3"

######################################################################################
Test_Name = "test_3"
n_iter_test_file = 2
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
# Creation of the boundaries
# ==========================
# Creation of the discrete boundary
    Boundary_1 = homard.CreateBoundaryDi('courbes', 'COURBES', os.path.join(Rep_Test, Test_Name + '.fr.med'))
#
# Creation of the external cylinder
    Boundary_2 = homard.CreateBoundaryCylinder('cyl_ext', 50.0, 25., -25., 1., 0., 0., 100.)
#
# Creation of the internal cylinder
    Boundary_3 = homard.CreateBoundaryCylinder('cyl_int', 50.0, 25., -25., 1., 0., 0., 50.)
#
# Creation of the first sphere
    Boundary_4 = homard.CreateBoundarySphere('sphere_1', 50.0, 25., -25., 100.)
#
# Creation of the second sphere
    Boundary_5 = homard.CreateBoundarySphere('sphere_2', 450.0, 25., -25., 100.)
#
# Creation of the hypotheses
# ==========================
# Uniform refinement
    Hypo = homard.CreateHypothesis('Hypo')
    Hypo.SetAdapRefinUnRef(-1, 1, 0)
#
# Creation of the cases
# =====================
# Creation of the case Case_1
    Case_1 = homard.CreateCase('Case_1', 'MOYEU', os.path.join(Rep_Test, Test_Name + '.00.med'))
    Case_1.SetDirName(Rep_Test_Resu)
    Case_1.SetConfType(1)
    Case_1.AddBoundaryGroup('courbes', '')
    Case_1.AddBoundaryGroup('cyl_ext', 'EXT')
    Case_1.AddBoundaryGroup('cyl_int', 'INT')
    Case_1.AddBoundaryGroup('sphere_1', 'END_1')
    Case_1.AddBoundaryGroup('sphere_2', 'END_2')
#
# Creation of the iterations
# ==========================
# Creation of the iteration Iter_1
    Iter_1 = homard.CreateIteration('Iter_1', Case_1.GetIter0Name() )
    Iter_1.SetMeshName('MOYEU_1')
    Iter_1.SetMeshFile(os.path.join(Rep_Test_Resu, 'maill.01.med'))
    homard.AssociateIterHypo('Iter_1', 'Hypo')
    error = Iter_1.Compute(1)
    if error :
      error = 1
      break

# Creation of the iteration Iter_2
    Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1')
    Iter_2.SetMeshName('MOYEU_2')
    Iter_2.SetMeshFile(os.path.join(Rep_Test_Resu, 'maill.02.med'))
    homard.AssociateIterHypo('Iter_2', 'Hypo')
    error = Iter_2.Compute(1)
    if error :
      error = 2
      break
#
    break
#
  return error

######################################################################################

homard = salome.lcc.FindOrLoadComponent('FactoryServer', 'HOMARD')
assert homard is not None, "Impossible to load homard engine"

#
# Exec of HOMARD-SALOME
#
try :
  error_main = homard_exec(salome.myStudy)
  if error_main :
    raise Exception('Pb in homard_exec at iteration %d' %error_main )
except Exception, e:
  raise Exception('Pb in homard_exec: '+e.message)

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

