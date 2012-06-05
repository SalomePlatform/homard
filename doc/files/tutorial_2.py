#!/usr/bin/env python
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
Exemple de couplage HOMARD-Salome
Copyright EDF-R&D 1996, 2010
"""
__revision__ = "V1.3"
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
Zone_0 = homard.CreateZoneBox ('Zone_0', -0.1, 1.1, -0.1, 1.1, 0.9, 1.1)
#
# Sphere "Zone_1"
Zone_1 = homard.CreateZoneSphere ('Zone_1', 0., 0., 0., 1.05)
#
# Box "Zone_2"
Zone_2 = homard.CreateZoneBox ('Zone_2', -0.1, 0.51, -0.1, 0.51, -0.1, 0.51)
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
# Case "Case_1"
# =============
Case_1 = homard.CreateCase('Case_1', 'MZERO', dircase+'/tutorial_2.00.med')
Case_1.SetDirName(dircase)
#
# Iteration "Iter_0"
# ==================
Iter_0 = homard.CreateIteration('Iter_0', Case_1.GetIter0Name())
Iter_0.SetMeshName('M_1')
Iter_0.SetMeshFile(dircase+'/maill.01.med')
homard.AssociateIterHypo('Iter_0', 'Hypo_0')
codret = Iter_0.Compute(1)
#
# Iteration "Iter_1"
# ==================
Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
Iter_1.SetMeshName('M_2')
Iter_1.SetMeshFile(dircase+'/maill.02.med')
homard.AssociateIterHypo('Iter_1', 'Hypo_1')
codret = Iter_1.Compute(1)

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
