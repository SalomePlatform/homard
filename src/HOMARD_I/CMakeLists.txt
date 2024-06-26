# Copyright (C) 2012-2024  CEA, EDF
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

# --- options ---
# additional include directories
INCLUDE_DIRECTORIES(
  ${OMNIORB_INCLUDE_DIR}
  ${KERNEL_INCLUDE_DIRS}
  ${MEDFILE_INCLUDE_DIRS}
  ${SMESH_INCLUDE_DIRS}
  ${GEOM_INCLUDE_DIRS}
  ${MEDCOUPLING_INCLUDE_DIRS}
  ${HDF5_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR}
  ${PROJECT_BINARY_DIR}/idl
  ${PROJECT_BINARY_DIR}/adm_local/unix
  ${PROJECT_SOURCE_DIR}/src/FrontTrack
  ${PROJECT_SOURCE_DIR}/src/HOMARD
  ${PROJECT_SOURCE_DIR}/src/HOMARDGUI
)
# additional preprocessor / compiler flags
ADD_DEFINITIONS(
  ${OMNIORB_DEFINITIONS}
)

# libraries to link to
SET(_link_LIBRARIES
  ${MEDFILE_C_LIBRARIES}
  ${KERNEL_SalomeContainer}
  ${KERNEL_SalomeNS}
  ${KERNEL_Registry}
  ${KERNEL_SalomeHDFPersist}
  ${KERNEL_SalomeLifeCycleCORBA}
  ${KERNEL_TOOLSDS}
  ${KERNEL_SalomeGenericObj}
  ${SMESH_SalomeIDLSMESH}
  ${SMESH_SMESHEngine}
  FrontTrack
  SalomeIDLHOMARD
  HOMARDImpl
)

# --- headers ---

# header files / no moc processing
SET(HOMARDEngine_HEADERS
  HOMARD_Cas_i.hxx
  HOMARD_Hypothesis_i.hxx
  HOMARD_Iteration_i.hxx
  HOMARD_Zone_i.hxx
  HOMARD_Gen_i.hxx
  HOMARD_Gen_i_Session.hxx
  HOMARD_Gen_i_No_Session.hxx
  HOMARD_Boundary_i.hxx
  HOMARD_YACS_i.hxx
  HomardMedCommun.h
  HOMARD_i.hxx
)

# --- sources ---

# sources / static
SET(HOMARDEngine_SOURCES
  HOMARD_Cas_i.cxx
  HOMARD_Hypothesis_i.cxx
  HOMARD_Iteration_i.cxx
  HOMARD_Gen_i.cxx
  HOMARD_Gen_i_Session.cxx
  HOMARD_Gen_i_No_Session.cxx
  HOMARD_Zone_i.cxx
  HOMARD_Boundary_i.cxx
  HOMARD_YACS_i.cxx
  HomardMedCommun.cxx
)

# --- rules ---

ADD_LIBRARY(HOMARDEngine ${HOMARDEngine_SOURCES})
TARGET_LINK_LIBRARIES(HOMARDEngine ${_link_LIBRARIES} )
INSTALL(TARGETS HOMARDEngine EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})

INSTALL(FILES ${HOMARDEngine_HEADERS} DESTINATION ${SALOME_INSTALL_HEADERS})
