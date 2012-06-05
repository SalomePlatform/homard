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
#  Author : , CEA
#  Modified by : Alexander BORODIN (OCN) - autotools usage
#
include $(top_srcdir)/adm_local/unix/make_common_starter.am

# header files 
salomeinclude_HEADERS = \
	HOMARD_Cas.hxx \
	HOMARD_Boundary.hxx \
	HOMARD_Hypothesis.hxx \
	HOMARD_Iteration.hxx \
	HOMARD_Zone.hxx \
	HOMARD_Gen.hxx \
	HOMARD_DriverTools.hxx \
	HomardDriver.hxx

# Libraries targets
lib_LTLIBRARIES = libHOMARDImpl.la
dist_libHOMARDImpl_la_SOURCES = \
	HOMARD_Cas.cxx \
	HOMARD_Boundary.cxx \
	HOMARD_Hypothesis.cxx \
	HOMARD_Iteration.cxx \
	HOMARD_Zone.cxx \
	HOMARD_Gen.cxx \
	HOMARD_DriverTools.cxx \
	HomardDriver.cxx

libHOMARDImpl_la_CPPFLAGS = \
	$(KERNEL_CXXFLAGS)

libHOMARDImpl_la_LDFLAGS = \
	$(KERNEL_LDFLAGS) \
	-lSALOMELocalTrace

# check_PROGRAMS = testhomard
# 
# TESTS = $(check_PROGRAMS)
# 
# testhomard_SOURCES = testhomard.cxx
# 
# testhomard_LDADD = libHOMARDImpl.la
