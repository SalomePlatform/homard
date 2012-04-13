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
# Author :
# Modified by : Alexander BORODIN (OCN) - autotools usage
#
# header files

include $(top_srcdir)/adm_local/unix/make_common_starter.am

salomeinclude_HEADERS =       \
	MonCreateBoundaryAn.h \
	CreateBoundaryAn.h    \
	MonEditBoundaryAn.h   \
	MonCreateBoundaryDi.h \
	CreateBoundaryDi.h    \
	MonEditBoundaryDi.h   \
	MonCreateCase.h       \
	CreateCase.h          \
	MonEditCase.h         \
	MonCreateZone.h       \
	CreateZone.h          \
	MonEditZone.h         \
	MonCreateHypothesis.h \
	CreateHypothesis.h    \
	MonEditHypothesis.h   \
	MonCreateListGroup.h  \
	CreateListGroup.h     \
	MonEditListGroup.h    \
	MonCreateIteration.h  \
	CreateIteration.h     \
	MonEditIteration.h    \
	HOMARDGUI.h           \
	HOMARDGUI_Utils.h     \
	EditFile.h            \
	MonEditFile.h         \
	HomardQtCommun.h


# Libraries targets
lib_LTLIBRARIES = libHOMARD.la

dist_libHOMARD_la_SOURCES =     \
	HOMARDGUI.cxx           \
	HOMARDGUI_Utils.cxx     \
	MonCreateBoundaryAn.cxx \
	MonEditBoundaryAn.cxx \
	MonCreateBoundaryDi.cxx \
	MonEditBoundaryDi.cxx \
	MonCreateCase.cxx       \
	MonEditCase.cxx         \
	MonCreateHypothesis.cxx \
	MonEditHypothesis.cxx   \
	MonCreateListGroup.cxx \
	MonEditListGroup.cxx \
	MonCreateIteration.cxx  \
	MonEditIteration.cxx    \
	MonCreateZone.cxx       \
	MonEditZone.cxx         \
	MonEditFile.cxx         \
	HomardQtCommun.cxx

# MOC pre-processing
MOC_FILES =                         \
	HOMARDGUI_moc.cxx           \
	MonCreateBoundaryAn_moc.cxx \
	MonEditBoundaryAn_moc.cxx   \
	MonCreateBoundaryDi_moc.cxx \
	MonEditBoundaryDi_moc.cxx   \
	MonCreateCase_moc.cxx       \
	MonEditCase_moc.cxx         \
	MonCreateZone_moc.cxx       \
	MonEditZone_moc.cxx         \
	MonCreateHypothesis_moc.cxx \
	MonEditHypothesis_moc.cxx   \
	MonCreateListGroup_moc.cxx  \
	MonEditListGroup_moc.cxx    \
	MonCreateIteration_moc.cxx  \
	MonEditIteration_moc.cxx    \
	MonEditFile_moc.cxx

nodist_libHOMARD_la_SOURCES = $(MOC_FILES)

libHOMARD_la_CPPFLAGS =          \
	$(QT_INCLUDES)           \
	$(CAS_CPPFLAGS)          \
	$(PYTHON_INCLUDES)       \
	$(MED3_INCLUDES)         \
	$(HDF5_INCLUDES)         \
	$(BOOST_CPPFLAGS)        \
	$(CORBA_CXXFLAGS)        \
	$(CORBA_INCLUDES)        \
	$(KERNEL_CXXFLAGS)       \
	$(GUI_CXXFLAGS)          \
	-I$(srcdir)/../HOMARD    \
	-I$(srcdir)/../HOMARD_I  \
	-I$(top_builddir)/idl    \
	-I$(top_builddir)        \
	-I$(VISU_ROOT_DIR)/include/salome  \
	-I$(MED_ROOT_DIR)/include/salome   \
	-I$(top_builddir)/adm_local/unix

libHOMARD_la_LDFLAGS  =                 \
	../../idl/libSalomeIDLHOMARD.la \
	../HOMARD_I/libHOMARDEngine.la  \
	$(KERNEL_LDFLAGS)               \
	$(MED3_LIBS)                    \
        -lSalomeLifeCycleCORBA          \
	$(GUI_LDFLAGS)                  \
	-lSalomeApp                     \
        -lSalomePyQtGUI

# resources files
nodist_salomeres_DATA =  \
	HOMARD_msg_en.qm \
	HOMARD_msg_fr.qm

UI_FILES = \
CreateBoundaryAn.ui \
CreateBoundaryDi.ui \
CreateCase.ui \
CreateHypothesis.ui \
CreateIteration.ui \
CreateListGroup.ui \
CreateZone.ui \
EditFile.ui

EXTRA_DIST += $(UI_FILES)
