#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Copyright (C) 2011-2016  CEA/DEN, EDF R&D
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
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
Copyright EDF-R&D 1996, 2010, 2014
"""
__revision__ = "V2.1"
#
import os
import sys
#
# ==================================
PATH_HOMARD = os.getenv('HOMARD_ROOT_DIR')
# Repertoire des donnees du tutorial
DATA_TUTORIAL = os.path.join(PATH_HOMARD, "share", "doc", "salome", "gui", "HOMARD", "fr", "_downloads")
DATA_TUTORIAL = os.path.normpath(DATA_TUTORIAL)
sys.path.append(DATA_TUTORIAL)
from tutorial_util import gzip_gunzip
from tutorial_util import creation_dircase
# ==================================
DIRCASE = creation_dircase(3)
gzip_gunzip(DATA_TUTORIAL, 3, -1)
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
# Hypothese "hypo_0vers1"
# =======================
hypo_0vers1 = homard.CreateHypothesis('hypo_0vers1')
# Characterization of the field
hypo_0vers1.SetField('SOLU_0__QIRE_ELEM_SIGM__________')
hypo_0vers1.SetUseComp(0)
hypo_0vers1.AddComp('ERREST          ')
hypo_0vers1.SetRefinThr(3, 1.0)
hypo_0vers1.SetTypeFieldInterp(2)
hypo_0vers1.AddFieldInterp('SOLU_0__DEPL____________________')
hypo_0vers1.AddFieldInterp('SOLU_0__ERRE_ELEM_SIGM__________')
#
# Hypothese "hypo_1vers2"
# =======================
hypo_1vers2 = homard.CreateHypothesis('hypo_1vers2')
# Characterization of the field
hypo_1vers2.SetField('SOLU_1__QIRE_ELEM_SIGM__________')
hypo_1vers2.SetUseComp(0)
hypo_1vers2.AddComp('ERREST          ')
hypo_1vers2.SetRefinThr(3, 1.5)
hypo_1vers2.SetUnRefThr(3, 6.)
hypo_1vers2.SetTypeFieldInterp(2)
hypo_1vers2.AddFieldInterp('SOLU_1__DEPL____________________')
hypo_1vers2.AddFieldInterp('SOLU_1__QIRE_ELEM_SIGM__________')
#
# Hypothese "hypo_1vers2_bis"
# ===========================
hypo_1vers2_bis = homard.CreateHypothesis('hypo_1vers2_bis')
# Characterization of the field
hypo_1vers2_bis.SetField('SOLU_1__DEPL____________________')
hypo_1vers2_bis.SetUseComp(1)
hypo_1vers2_bis.AddComp('DX')
hypo_1vers2_bis.AddComp('DY')
hypo_1vers2_bis.AddComp('DZ')
hypo_1vers2_bis.SetRefinThr(1, 0.0001)
hypo_1vers2_bis.SetUnRefThr(1, 0.000001)
hypo_1vers2_bis.SetTypeFieldInterp(0)
#
# Cas
# ===
case_3 = homard.CreateCase('Case_3', 'G_0', DATA_TUTORIAL+'/tutorial_3.00.med')
case_3.SetDirName(DIRCASE)
#
# Iteration "iter_3_1"
# ====================
iter_3_1 = case_3.NextIteration('iter_3_1')
iter_3_1.SetMeshName('H_1')
iter_3_1.SetMeshFile(DIRCASE+'/maill.01.med')
iter_3_1.SetFieldFile(DATA_TUTORIAL+'/tutorial_3.00.med')
iter_3_1.SetTimeStepRank( 1, 1)
iter_3_1.AssociateHypo('hypo_0vers1')
error = iter_3_1.Compute(1, 2)
#
# Iteration "iter_3_2"
# ====================
iter_3_2 = iter_3_1.NextIteration('iter_3_2')
iter_3_2.SetMeshName('H_2')
iter_3_2.SetMeshFile(DIRCASE+'/maill.02.med')
iter_3_2.SetFieldFile(DATA_TUTORIAL+'/tutorial_3.01.med')
iter_3_2.SetTimeStepRank(1, 1)
iter_3_2.AssociateHypo('hypo_1vers2')
error = iter_3_2.Compute(1, 2)
#
# Iteration "iter_3_2_bis"
# ========================
iter_3_2_bis = iter_3_1.NextIteration('iter_3_2_bis')
iter_3_2_bis.SetMeshName('H_2_bis')
iter_3_2_bis.SetMeshFile(DIRCASE+'/maill.02.bis.med')
iter_3_2_bis.SetFieldFile(DATA_TUTORIAL+'/tutorial_3.01.med')
iter_3_2_bis.SetTimeStepRank(1, 1)
iter_3_2_bis.AssociateHypo('hypo_1vers2_bis')
error = iter_3_2_bis.Compute(1, 2)

# ==================================
gzip_gunzip(DATA_TUTORIAL, 3, 1)
# ==================================

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(True)
