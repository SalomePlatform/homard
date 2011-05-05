#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-
"""
Exemple de couplage HOMARD-Salome
Copyright EDF-R&D 1996, 2010
"""
__revision__ = "V1.1"
#
# ==================================
# Repertoire a personnaliser
# Ce repertoire contient les fichiers de donnees : tutorial_2.00.med
# Ce repertoire contiendra les fichiers de resultats : maill.01.med, maill.02.med
dircase = "/tmp"
# ==================================
#
import salome
salome.salome_init()
import HOMARD
#
homard = salome.lcc.FindOrLoadComponent("FactoryServer", "HOMARD")
study_main = salome.myStudyManager.NewStudy("HOMARD")
homard.SetCurrentStudy(salome.myStudy)
#
# Creation of the zones
# =====================
# Box "Zone_0"
Zone_0 = homard.CreateZone('Zone_0', 2)
Zone_0.SetBox(-0.1, 1.1, -0.1, 1.1, 0.9, 1.1)
#
# Sphere "Zone_1"
Zone_1 = homard.CreateZone('Zone_1', 4)
Zone_1.SetSphere(0., 0., 0., 1.05)
#
# Box "Zone_2"
Zone_2 = homard.CreateZone('Zone_2', 2)
Zone_2.SetBox(-0.1, 0.51, -0.1, 0.51, -0.1, 0.51)
#
# Hypothesis "Hypo_0"
# ===================
Hypo_0 = homard.CreateHypothesis('Hypo_0')
Hypo_0.SetAdapRefinUnRef(0, 1, 0)
homard.AssociateHypoZone('Zone_1', 'Hypo_0')
homard.AssociateHypoZone('Zone_0', 'Hypo_0')
#
# Hypothesis "Hypo_1"
# ===================
Hypo_1 = homard.CreateHypothesis('Hypo_1')
Hypo_1.SetAdapRefinUnRef(0, 1, 0)
homard.AssociateHypoZone('Zone_0', 'Hypo_1')
homard.AssociateHypoZone('Zone_2', 'Hypo_1')
#
# Case "Case_0"
# =============
Case_0 = homard.CreateCase('Case_0', 'MZERO', dircase+'/tutorial_2.00.med')
Case_0.SetDirName(dircase)
#
# Iteration "Iter_0"
# ==================
Iter_0 = homard.CreateIteration('Iter_0', Case_0.GetIter0Name())
Iter_0.SetMeshName('M_1')
Iter_0.SetMeshFile(dircase+'/maill.01.med')
homard.AssociateIterHypo('Iter_0', 'Hypo_0')
codret = homard.Compute('Iter_0', 1)
#
# Iteration "Iter_1"
# ==================
Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
Iter_1.SetMeshName('M_2')
Iter_1.SetMeshFile(dircase+'/maill.02.med')
homard.AssociateIterHypo('Iter_1', 'Hypo_1')
codret = homard.Compute('Iter_1', 1)

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
