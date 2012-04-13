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
#  Author : Paul RASCLE, EDF
#  Modified by : Alexander BORODIN (OCN) - autotools usage
#  Module : HOMARD
#  $Header$
#
include $(top_srcdir)/adm_local/unix/make_common_starter.am

# header files 
salomeinclude_HEADERS =         \
	HOMARD_Cas_i.hxx        \
	HOMARD_Hypothesis_i.hxx \
	HOMARD_Iteration_i.hxx  \
	HOMARD_Zone_i.hxx       \
	HOMARD_Gen_i.hxx        \
	HOMARD_Boundary_i.hxx   \
        HomardMedCommun.h

# Libraries targets

lib_LTLIBRARIES = libHOMARDEngine.la

dist_libHOMARDEngine_la_SOURCES = \
	HOMARD_Cas_i.cxx          \
	HOMARD_Hypothesis_i.cxx   \
	HOMARD_Iteration_i.cxx    \
	HOMARD_Gen_i.cxx          \
	HOMARD_Zone_i.cxx         \
	HOMARD_Boundary_i.cxx     \
        HomardMedCommun.cxx



# additionnal information to compil and link file
libHOMARDEngine_la_CPPFLAGS = 		      \
	$(CORBA_CXXFLAGS) 		      \
	$(CORBA_INCLUDES)		      \
	$(KERNEL_CXXFLAGS)		      \
	$(MED3_INCLUDES)		      \
	$(SMESH_CXXFLAGS) 		      \
	$(GEOM_CXXFLAGS) 		      \
	-I$(srcdir)/../HOMARD 		      \
	-I$(srcdir)/../HOMARDGUI              \
	-I$(top_builddir)/idl	    	      \
        -I$(GEOM_ROOT_DIR)/include/salome     \
        -I$(SMESH_ROOT_DIR)/include/salome     \
        -I$(MED_ROOT_DIR)/include/salome      \
	-I$(top_builddir)/adm_local/unix


libHOMARDEngine_la_LDFLAGS  =            \
	../../idl/libSalomeIDLHOMARD.la  \
	../HOMARD/libHOMARDImpl.la       \
	$(KERNEL_LDFLAGS)                \
	$(MED3_LIBS)                     \
	-lSalomeContainer                \
	-lSalomeNS                       \
	-lRegistry                       \
	-lSalomeHDFPersist               \
	-lSalomeLifeCycleCORBA           \
	-lTOOLSDS                        \
	-lSalomeGenericObj               \
        $(SMESH_LDFLAGS)                 \
	-lSalomeIDLSMESH                 \
        -lSMESHClient
