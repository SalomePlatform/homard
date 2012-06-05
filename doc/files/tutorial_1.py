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
__revision__ = "V1.2"
#
# ==================================
# Repertoire a personnaliser
# Ce repertoire contient les fichiers de donnees : tutorial_1.00.med
# Ce repertoire contiendra les fichiers de resultats : maill.01.med, maill.02.med, maill.03.med
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
# Hypothesis "Hypo_0"
# ===================
Hypo_0 = homard.CreateHypothesis('Hypo_0')
Hypo_0.SetAdapRefinUnRef(-1, 1, 0)
#
# Case "Case_1"
# =============
Case_1 = homard.CreateCase('Case_1', 'MAILL', dircase+'/tutorial_1.00.med')
Case_1.SetDirName(dircase)
Case_1.SetConfType(1)
#
# Iterations
# ==========
# Iteration "Iter_0"
Iter_0 = homard.CreateIteration('Iter_0', Case_1.GetIter0Name())
Iter_0.SetMeshName('MESH')
Iter_0.SetMeshFile(dircase+'/maill.01.med')
homard.AssociateIterHypo('Iter_0', 'Hypo_0')
codret = Iter_0.Compute(1)

# Iteration "Iter_1"
Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
Iter_1.SetMeshName('MESH')
Iter_1.SetMeshFile(dircase+'/maill.02.med')
homard.AssociateIterHypo('Iter_1', 'Hypo_0')
codret = Iter_1.Compute(1)

# Iteration "Iter_2"
Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1')
Iter_2.SetMeshName('MESH')
Iter_2.SetMeshFile(dircase+'/maill.03.med')
homard.AssociateIterHypo('Iter_2', 'Hypo_0')
codret = Iter_2.Compute(1)

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
