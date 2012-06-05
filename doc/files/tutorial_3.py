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
# Hypothesis "Hypo_0vers1"
# ========================
Hypo_0vers1 = homard.CreateHypothesis('Hypo_0vers1')
Hypo_0vers1.SetAdapRefinUnRef(1, 1, 0)
# Characterization of the field
Hypo_0vers1.SetField('SOLU_0__QIRE_ELEM_SIGM__________')
Hypo_0vers1.SetUseComp(0)
Hypo_0vers1.AddComp('ERREST          ')
Hypo_0vers1.SetRefinThr(3, 1.0)
Hypo_0vers1.SetTypeFieldInterp(2)
Hypo_0vers1.AddFieldInterp('SOLU_0__DEPL____________________')
Hypo_0vers1.AddFieldInterp('SOLU_0__ERRE_ELEM_SIGM__________')
#
# Hypothesis "Hypo_1vers2"
# ========================
Hypo_1vers2 = homard.CreateHypothesis('Hypo_1vers2')
Hypo_1vers2.SetAdapRefinUnRef(1, 1, 1)
# Characterization of the field
Hypo_1vers2.SetField('SOLU_1__QIRE_ELEM_SIGM__________')
Hypo_1vers2.SetUseComp(0)
Hypo_1vers2.AddComp('ERREST          ')
Hypo_1vers2.SetRefinThr(3, 1.5)
Hypo_1vers2.SetUnRefThr(3, 6.)
Hypo_1vers2.SetTypeFieldInterp(2)
Hypo_1vers2.AddFieldInterp('SOLU_1__DEPL____________________')
Hypo_1vers2.AddFieldInterp('SOLU_1__QIRE_ELEM_SIGM__________')
#
# Hypothesis "Hypo_1vers2_bis"
# ============================
Hypo_1vers2_bis = homard.CreateHypothesis('Hypo_1vers2_bis')
Hypo_1vers2_bis.SetAdapRefinUnRef(1, 1, 1)
# Characterization of the field
Hypo_1vers2_bis.SetField('SOLU_1__DEPL____________________')
Hypo_1vers2_bis.SetUseComp(1)
Hypo_1vers2_bis.AddComp('DX')
Hypo_1vers2_bis.AddComp('DY')
Hypo_1vers2_bis.AddComp('DZ')
Hypo_1vers2_bis.SetRefinThr(1, 0.0001)
Hypo_1vers2_bis.SetUnRefThr(1, 0.000001)
Hypo_1vers2_bis.SetTypeFieldInterp(0)
#
# Case "Case_1"
# =============
Case_1 = homard.CreateCase('Case_1', 'G_0', dircase+'/tutorial_3.00.med')
Case_1.SetDirName(dircase)
#
# Iteration "Iter_1"
# ==================
Iter_1 = homard.CreateIteration('Iter_1', Case_1.GetIter0Name())
Iter_1.SetMeshName('H_1')
Iter_1.SetMeshFile(dircase+'/maill.01.med')
Iter_1.SetFieldFile(dircase+'/tutorial_3.00.med')
Iter_1.SetTimeStepRank( 1, 1)
homard.AssociateIterHypo('Iter_1', 'Hypo_0vers1')
codret = Iter_1.Compute(1)
#
# Iteration "Iter_2"
# ==================
Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1')
Iter_2.SetMeshName('H_2')
Iter_2.SetMeshFile(dircase+'/maill.02.med')
Iter_2.SetFieldFile(dircase+'/tutorial_3.01.med')
Iter_2.SetTimeStepRank(1, 1)
homard.AssociateIterHypo('Iter_2', 'Hypo_1vers2')
codret = Iter_2.Compute(1)
#
# Iteration "Iter_2_bis"
# ======================
Iter_2_bis = homard.CreateIteration('Iter_2_bis', 'Iter_1')
Iter_2_bis.SetMeshName('H_2_bis')
Iter_2_bis.SetMeshFile(dircase+'/maill.02.bis.med')
Iter_2_bis.SetFieldFile(dircase+'/tutorial_3.01.med')
Iter_2_bis.SetTimeStepRank(1, 1)
homard.AssociateIterHypo('Iter_2_bis', 'Hypo_1vers2_bis')
codret = Iter_2_bis.Compute(1)
#
if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
