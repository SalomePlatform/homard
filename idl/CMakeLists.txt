# Copyright (C) 2012-2025  CEA, EDF
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

INCLUDE(UseOmniORB)  # Provided by KERNEL

INCLUDE_DIRECTORIES(
  ${OMNIORB_INCLUDE_DIR}
  ${KERNEL_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR}/idl
)

SET(SalomeIDLHOMARD_IDLSOURCES
  HOMARD_Gen.idl
  HOMARD_Cas.idl
  HOMARD_Hypothesis.idl
  HOMARD_Iteration.idl
  HOMARD_Zone.idl
  HOMARD_Boundary.idl
  HOMARD_YACS.idl
)

SET(_idl_include_dirs
  ${KERNEL_ROOT_DIR}/idl/salome
)

SET(_idl_link_flags
  ${KERNEL_SalomeIDLKernel}
)

OMNIORB_ADD_MODULE(SalomeIDLHOMARD "${SalomeIDLHOMARD_IDLSOURCES}" "${_idl_include_dirs}" "${_idl_link_flags}")
INSTALL(TARGETS SalomeIDLHOMARD EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})

message (STATUS "OMNIORB_IDLCXXFLAGS=${OMNIORB_IDLCXXFLAGS}")
message (STATUS "OMNIORB_IDLPYFLAGS=${OMNIORB_IDLPYFLAGS}")
message (STATUS "OMNIORB_IDL_COMPILER=${OMNIORB_IDL_COMPILER}")
message (STATUS "KERNEL_ROOT_DIR=${KERNEL_ROOT_DIR}")

foreach(_idl_file ${SalomeIDLHOMARD_IDLSOURCES})
  get_filename_component(_id ${_idl_file} NAME_WE)
  add_custom_target(custom_idl_${_id} ALL
    COMMAND ${OMNIORB_IDL_COMPILER} -bpython -p${OMNIORB_PYTHON_BACKEND} -I${KERNEL_ROOT_DIR}/idl/salome ${CMAKE_CURRENT_SOURCE_DIR}/${_idl_file}
    DEPENDS ${_idl_file}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  message(STATUS "custom_idl_${_id} => ${OMNIORB_IDL_COMPILER} -bpython -p${OMNIORB_PYTHON_BACKEND} -I${KERNEL_ROOT_DIR}/idl/salome ${CMAKE_CURRENT_SOURCE_DIR}/${_idl_file}")
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${_id}_idl.py DESTINATION lib/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/site-packages/salome)
endforeach()

install(FILES __init__.py ${CMAKE_CURRENT_BINARY_DIR}/${_id}_idl.py DESTINATION lib/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/site-packages/salome/HOMARD)
