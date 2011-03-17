#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-
"""
Exemple de couplage HOMARD-Salome
Copyright EDF-R&D 1996, 2010
"""
__revision__ = "V1.0"
#
import salome
salome.salome_init()
import HOMARD
#
homard = salome.lcc.FindOrLoadComponent("FactoryServer", "HOMARD")
study_main = salome.myStudyManager.NewStudy("HOMARD")
homard.SetCurrentStudy(salome.myStudy)
#
dircase = "/tmp"
#
# Hypothesis "Hypo_0"
# ===================
Hypo_0 = homard.CreateHypothesis('Hypo_0')
Hypo_0.SetAdapRefinUnRef(1, 1, 0)
# Characterization of the field
Hypo_0.SetField('SOLU_0__QIRE_ELEM_SIGM__________')
Hypo_0.SetUseComp(0)
Hypo_0.AddComp('ERREST          ')
Hypo_0.SetRefinThr(3, 1.0)
#
# Hypothesis "Hypo_1"
# ===================
Hypo_1 = homard.CreateHypothesis('Hypo_1')
Hypo_1.SetAdapRefinUnRef(1, 1, 1)
# Characterization of the field
Hypo_1.SetField('SOLU_1__QIRE_ELEM_SIGM__________')
Hypo_1.SetUseComp(0)
Hypo_1.AddComp('ERREST          ')
Hypo_1.SetRefinThr(3, 1.5)
Hypo_1.SetUnRefThr(3, 6.)
#
# Case "Case_0"
# =============
Case_0 = homard.CreateCase('Case_0', 'G_0', dircase+'/tutorial_3.00.med')
Case_0.SetDirName(dircase)
#
# Iteration "Iter_0"
# ==================
Iter_0 = homard.CreateIteration('Iter_0', Case_0.GetIter0Name())
Iter_0.SetMeshName('H_1')
Iter_0.SetMeshFile(dircase+'/maill.01.med')
Iter_0.SetField(dircase+'/tutorial_3.00.med', 1, 1)
homard.AssociateIterHypo('Iter_0', 'Hypo_0')
codret = homard.Compute('Iter_0', 1)
#
# Iteration "Iter_1"
# ==================
Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
Iter_1.SetMeshName('H_2')
Iter_1.SetMeshFile('/tmp/maill.02.med')
Iter_1.SetField(dircase+'/tutorial_3.01.med', 1, 1)
homard.AssociateIterHypo('Iter_1', 'Hypo_1')
codret = homard.Compute('Iter_1', 1)

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
