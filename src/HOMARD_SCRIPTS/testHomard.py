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
homard=salome.lcc.FindOrLoadComponent("FactoryServer","HOMARD")
import os
home=os.environ["HOME"]
etape0= home+"essai/etape0"
archive=+"/archives"
FichierConfiguration=etape0+"HOMARD.Configuration.0.vers.1"
monCas=homard.CreateCas("MonCas",etape0)
print monCas
monCas.AjoutIter(1,FichierConfiguration)
print "ici"
monCas.CalculIter(1)
print "la"
