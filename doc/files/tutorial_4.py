#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-
"""
Exemple de couplage HOMARD-Salome
Copyright EDF-R&D 1996, 2011
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
# Creation of the boundaries
# ==========================
Boundary_1 = homard.CreateBoundary('intersection', 0)
Boundary_1.SetMeshFile(dircase+'/tutorial_4.fr.med')
Boundary_1.SetMeshName('PIQUAGE')
#
Boundary_2 = homard.CreateBoundary('cyl_1_ext', 1)
Boundary_2.SetCylinder(0.0, 25., -25., 25., 50., 75., 100.)
#
Boundary_3 = homard.CreateBoundary('cyl_2_ext', 1)
Boundary_3.SetCylinder(17.5, -2.5, -12.5, -100., -75., -25., 50.)
#
Boundary_4 = homard.CreateBoundary('cyl_1_int', 1)
Boundary_4.SetCylinder(0.0, 25., -25., 25., 50., 75., 75.)
#
Boundary_5 = homard.CreateBoundary('cyl_2_int', 1)
Boundary_5.SetCylinder(17.5, -2.5, -12.5, -100., -75., -25., 25.)
#
# Hypothesis "Hypo"
# ===================
# Creation of the hypothesis Hypo_1
Hypo_1 = homard.CreateHypothesis('Hypo_1')
Hypo_1.SetAdapRefinUnRef(-1, 1, 0)
Hypo_1.AddGroup('T1_INT')
Hypo_1.AddGroup('T2_INT')
# Creation of the hypothesis Hypo_2
Hypo_2 = homard.CreateHypothesis('Hypo_2')
Hypo_2.SetAdapRefinUnRef(-1, 1, 0)
Hypo_2.AddGroup('T1_EXT')
Hypo_2.AddGroup('T2_EXT')
#
# Case "Case"
# =============
Case = homard.CreateCase('Case', 'PIQUAGE', dircase+'/tutorial_4.00.med')
Case.SetDirName(dircase)
Case.AddBoundaryGroup( 'intersection', '' )
Case.AddBoundaryGroup( 'cyl_1_ext', 'T1_EXT' )
Case.AddBoundaryGroup( 'cyl_2_ext', 'T2_EXT' )
Case.AddBoundaryGroup( 'cyl_1_int', 'T1_INT' )
Case.AddBoundaryGroup( 'cyl_2_int', 'T2_INT' )
#
# Creation of the iterations
# ==========================
# Creation of the iteration Iter_1
Iter_1 = homard.CreateIteration('Iter_1', Case.GetIter0Name() )
Iter_1.SetMeshName('PIQUAGE_1')
Iter_1.SetMeshFile(dircase+'/maill.01.med')
homard.AssociateIterHypo('Iter_1', 'Hypo_1')
codret = homard.Compute('Iter_1', 1)
# Creation of the iteration Iter_2
Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1' )
Iter_2.SetMeshName('PIQUAGE_2')
Iter_2.SetMeshFile(dircase+'/maill.02.med')
homard.AssociateIterHypo('Iter_2', 'Hypo_2')
codret = homard.Compute('Iter_2', 1)

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
