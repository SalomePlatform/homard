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
#  File   : Makefile.in
#  Author : Nicolas REJNERI, Paul RASCLE
#  Modified by : Alexander BORODIN (OCN) - autotools usage
#  Module : HOMARD

import salome
salome.salome_init()

import HOMARD

#
# initialize engine
#
homard = salome.lcc.FindOrLoadComponent("FactoryServer", "HOMARD")

def test_save(fname):
    #
    # create new study
    #
    study = salome.myStudyManager.NewStudy("HOMARD")
    homard.SetCurrentStudy(study)
    #
    # create case
    #
    case_1 = homard.CreateCas("Case 1")
    case_1.SetNomDir("/tmp/homard")
    case_1.SetTypeConf(12)
    case_1.SetBoiteEnglobante([1.2,2.3,3.4,4.5,5.6,6.7,7.8,8.9,9.10,10.11])
    #
    # create hypothesis 1
    #
    hypo_1 = homard.CreateHypothese("Hypothesis 1")
    hypo_1.SetTypeAdapRaffDera(2,3,4)
    hypo_1.SetField("Field 1", 12, 3.45, 67, 23.343)
    hypo_1.AjoutComposant("Comp 1")
    hypo_1.AjoutComposant("Comp 2")
    hypo_1.AjoutComposant("Comp 3")
    #
    # create hypothesis 2
    #
    hypo_2 = homard.CreateHypothese("Hypothesis 2")
    hypo_2.SetTypeAdapRaffDera(20,30,40)
    hypo_2.SetField("Field 2", 5, 12.67223, 900, 6.5434)
    hypo_2.AjoutComposant("Comp 123")
    #
    # create iteration 1
    #
    iter_1 = homard.CreateIteration("Iteration 1")
    iter_1.SetEtat(True)
    iter_1.SetNumIter(56)
    iter_1.SetMeshFile("/aaaa/bbbb/AAAAA.med")
    iter_1.SetNomMesh("My Mesh")
    iter_1.SetField("Field 1", 42, 522)
    #
    # create iteration 2
    #
    iter_2 = homard.CreateIteration("Iteration 2")
    iter_2.SetEtat(False)
    iter_2.SetNumIter(57)
    iter_2.SetMeshFile("/cccc/cccc/asd.med")
    iter_2.SetNomMesh("MeshXZY")
    iter_2.SetField("Field 2", 22222, 50000)
    #
    # create iteration 3 (not published)
    #
    iter_3 = homard.CreateIteration("Iteration 3")
    iter_3.SetEtat(True)
    iter_3.SetNumIter(666)
    iter_3.SetMeshFile("/not/assigned/iteration/file.med")
    iter_3.SetNomMesh("NOT ASSIGNED")
    iter_3.SetField("Field XXX", 999, -1)
    #
    # create zone 1
    #
    zone_1 = homard.CreateZone("Zone 1")
    zone_1.SetBox(1.,2.,3.,4.,5.,6.)
    zone_1.SetTypeZone(5454)
    #
    # create zone 2
    #
    zone_2 = homard.CreateZone("Zone 2")
    zone_2.SetSphere(12.3, 3.4, .56, 6.5)
    zone_2.SetTypeZone(6545)
    #
    # associate objects
    #
    homard.AssocieCasIteration("Case 1", "Iteration 1")
    homard.AssocieCasIteration("Case 1", "Iteration 2")
    homard.AssocieHypoIteration("Iteration 1", "Hypothesis 1")
    homard.AssocieHypoZone("Zone 1", "Hypothesis 1")
    homard.AssocieHypoIteration("Iteration 2", "Hypothesis 2")
    homard.AssocieHypoZone("Zone 2", "Hypothesis 2")
    homard.AssocieIterationIteration("Iteration 1", "Iteration 2")
    #
    # save study
    #
    salome.myStudyManager.SaveAs(fname, study, 0)
    #
    # close study
    #
    salome.myStudyManager.Close(study)
    #
    pass

def test_load(fname):
    #
    # load study and 
    #
    study = salome.myStudyManager.Open(fname)
    #
    # load homard data
    #
    comp = study.FindComponent("HOMARD")
    builder = study.NewBuilder()
    builder.LoadWith(comp, homard)
    #
    # dump study id
    #
    print homard.GetCurrentStudy()._get_StudyId()
    #
    # dump case 1
    #
    case_1 = homard.GetCas("Case 1")
    print "Case: ",          case_1.GetNomCas()
    print "-> nom dir:",     case_1.GetNomDir()
    print "-> type conf:",   case_1.GetTypeConf()
    print "-> boite:",       case_1.GetBoiteEnglobante()
    print "---"
    #
    # dump hypothesis 1
    #
    hypo_1 = homard.GetHypothesis("Hypothesis 1")
    print "Hypothesis: ",    hypo_1.GetNomHypothesis()
    print "-> type:",        hypo_1.GetTypeAdapRaffDera()
    print "-> field name:",  hypo_1.GetFieldName()
    print "-> composants:",  hypo_1.GetComposants()
    print "-> zones:",       hypo_1.GetZones()
    print "---"
    #
    # dump hypothesis 2
    #
    hypo_2 = homard.GetHypothesis("Hypothesis 2")
    print "Hypothesis: ",    hypo_2.GetNomHypothesis()
    print "-> type:",        hypo_2.GetTypeAdapRaffDera()
    print "-> field name:",  hypo_2.GetFieldName()
    print "-> composants:",  hypo_2.GetComposants()
    print "-> zones:",       hypo_2.GetZones()
    print "---"
    #
    # dump zone 1
    #
    zone_1 = homard.GetZone("Zone 1")
    print "Zone: ",          zone_1.GetNomZone()
    print "-> type zone:",   zone_1.GetTypeZone()
    print "-> shere:",       zone_1.GetSphere()
    print "-> box:",         zone_1.GetBox()
    print "-> hypotheses:",  zone_1.GetHypo()
    print "---"
    #
    # dump zone 1
    #
    zone_2 = homard.GetZone("Zone 2")
    print "Zone: ",          zone_2.GetNomZone()
    print "-> type zone:",   zone_2.GetTypeZone()
    print "-> shere:",       zone_2.GetSphere()
    print "-> box:",         zone_2.GetBox()
    print "-> hypotheses:",  zone_2.GetHypo()
    print "---"
    #
    # dump iteration 1
    #
    iter_1 = homard.GetIteration("Iteration 1")
    print "Iteration: ",     iter_1.GetNomIter()
    print "-> etat:",        iter_1.GetEtat()
    print "-> num iter:",    iter_1.GetNumIter()
    print "-> nom mesh:",    iter_1.GetNomMesh()
    print "-> mesh file:",   iter_1.GetMeshFile()
    print "-> field:",       iter_1.GetFieldFileName()
    print "-> time step:",   iter_1.GetTimeStep()
    print "-> rank:",        iter_1.GetRank()
    print "-> parent iter:", iter_1.GetIterParent()
    print "-> hypothesis:",  iter_1.GetNomHypo()
    print "-> case:",        iter_1.GetNomCas()
    print "---"
    #
    # dump iteration 2
    #
    iter_2 = homard.GetIteration("Iteration 2")
    print "Iteration: ",     iter_2.GetNomIter()
    print "-> etat:",        iter_2.GetEtat()
    print "-> num iter:",    iter_2.GetNumIter()
    print "-> nom mesh:",    iter_2.GetNomMesh()
    print "-> mesh file:",   iter_2.GetMeshFile()
    print "-> field:",       iter_2.GetFieldFileName()
    print "-> time step:",   iter_2.GetTimeStep()
    print "-> rank:",        iter_2.GetRank()
    print "-> parent iter:", iter_2.GetIterParent()
    print "-> hypothesis:",  iter_2.GetNomHypo()
    print "-> case:",        iter_2.GetNomCas()
    print "---"
    #
    # dump iteration 3
    #
    iter_3 = homard.GetIteration("Iteration 3")
    print "Iteration: ",     iter_3.GetNomIter()
    print "-> etat:",        iter_3.GetEtat()
    print "-> num iter:",    iter_3.GetNumIter()
    print "-> nom mesh:",    iter_3.GetNomMesh()
    print "-> mesh file:",   iter_3.GetMeshFile()
    print "-> field:",       iter_3.GetFieldFileName()
    print "-> time step:",   iter_3.GetTimeStep()
    print "-> rank:",        iter_3.GetRank()
    print "-> parent iter:", iter_3.GetIterParent()
    print "-> hypothesis:",  iter_3.GetNomHypo()
    print "-> case:",        iter_3.GetNomCas()
    print "---"

# test file name
filename = "/tmp/save_homard.hdf"

# run tests
test_save(filename)
test_load(filename)
