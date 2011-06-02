#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-

# Copyright (C) 2011  CEA/DEN, EDF R&D
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
__revision__ = "V1.1"
#
# ==================================
# Repertoire a personnaliser
# Ce repertoire contient les fichiers de donnees : tutorial_3.00.med, tutorial_3.01.med
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
# Hypothesis "Hypo_0"
# ===================
Hypo_0 = homard.CreateHypothesis('Hypo_0')
Hypo_0.SetAdapRefinUnRef(1, 1, 0)
# Characterization of the field
Hypo_0.SetField('SOLU_0__QIRE_ELEM_SIGM__________')
Hypo_0.SetUseComp(0)
Hypo_0.AddComp('ERREST          ')
Hypo_0.SetRefinThr(3, 1.0)
Hypo_0.SetTypeFieldInterp(2)
Hypo_0.AddFieldInterp('SOLU_0__DEPL____________________')
Hypo_0.AddFieldInterp('SOLU_0__ERRE_ELEM_SIGM__________')
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
Hypo_1.SetTypeFieldInterp(2)
Hypo_1.AddFieldInterp('SOLU_1__DEPL____________________')
Hypo_1.AddFieldInterp('SOLU_1__QIRE_ELEM_SIGM__________')
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
Iter_0.SetFieldFile(dircase+'/tutorial_3.00.med')
Iter_0.SetTimeStepRank( 1, 1)
homard.AssociateIterHypo('Iter_0', 'Hypo_0')
codret = homard.Compute('Iter_0', 1)
#
# Iteration "Iter_1"
# ==================
Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
Iter_1.SetMeshName('H_2')
Iter_1.SetMeshFile(dircase+'/maill.02.med')
Iter_1.SetFieldFile(dircase+'/tutorial_3.01.med')
Iter_1.SetTimeStepRank(1, 1)
homard.AssociateIterHypo('Iter_1', 'Hypo_1')
codret = homard.Compute('Iter_1', 1)

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
