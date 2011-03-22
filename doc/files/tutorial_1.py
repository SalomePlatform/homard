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
Hypo_0.SetAdapRefinUnRef(-1, 1, 0)
#
# Case "Case_0"
# =============
Case_0 = homard.CreateCase('Case_0', 'MAILL', dircase+'/tutorial_1.00.med')
Case_0.SetDirName(dircase)
Case_0.SetConfType(1)
#
# Iterations
# ==========
# Iteration "Iter_0"
Iter_0 = homard.CreateIteration('Iter_0', Case_0.GetIter0Name())
Iter_0.SetMeshName('MESH')
Iter_0.SetMeshFile(dircase+'/maill.01.med')
homard.AssociateIterHypo('Iter_0', 'Hypo_0')
codret = homard.Compute('Iter_0', 1)

# Iteration "Iter_1"
Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
Iter_1.SetMeshName('MESH')
Iter_1.SetMeshFile(dircase+'/maill.02.med')
homard.AssociateIterHypo('Iter_1', 'Hypo_0')
codret = homard.Compute('Iter_1', 1)

# Iteration "Iter_2"
Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1')
Iter_2.SetMeshName('MESH')
Iter_2.SetMeshFile(dircase+'/maill.03.med')
homard.AssociateIterHypo('Iter_2', 'Hypo_0')
codret = homard.Compute('Iter_2', 1)

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
