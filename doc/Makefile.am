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
#  Author : Vasily Rusyaev (Open Cascade NN)
#  Module : doc
#
include $(top_srcdir)/adm_local/unix/make_common_starter.am

if SPHINX_IS_OK

homarddoc_DATA=html/index.html
html/index.html:$(RSTFILES)
	make htm

endif

homarddocdir=$(docdir)/gui/HOMARD

SPHINXOPTS      =
SOURCEDIR       = $(srcdir)
SPHINXBUILD     = sphinx-build
PAPEROPT_a4     = -D latex_paper_size=a4
ALLSPHINXOPTS   = -d doctrees $(PAPEROPT_a4) $(SPHINXOPTS) $(SOURCEDIR)

htm:
	mkdir -p html doctrees
	$(SPHINXBUILD) -c $(top_builddir)/doc -b html $(ALLSPHINXOPTS) html
	@echo
	@echo "Build finished. The HTML pages are in html."

RSTFILES= \
glossaire.rst \
gui_create_boundary.rst \
gui_create_case.rst \
gui_create_hypothese.rst \
gui_create_iteration.rst \
gui_create_zone.rst \
gui_homard.rst \
gui_usage.rst \
index.rst \
intro.rst \
tui_create_boundary.rst \
tui_create_case.rst \
tui_create_hypothese.rst \
tui_create_iteration.rst \
tui_create_zone.rst \
tui_homard.rst \
tui_usage.rst \
tutorials.rst

EXTRA_DIST+= $(RSTFILES) images files

usr_docs: 
	make install-data-local

docs: usr_docs

install-data-local:
	$(INSTALL) -d $(DESTDIR)$(homarddocdir)
	if test -d "html"; then b=; else b="$(srcdir)/"; fi; \
	if test -d $$b"html"; then cp -rf $$b"html"/* $(DESTDIR)$(homarddocdir); fi;

uninstall-local:
	chmod -R +w $(DESTDIR)$(homarddocdir)
	rm -rf $(DESTDIR)$(homarddocdir)/*

clean-local:
	-rm -rf doctrees
	if test -d "html"; then rm -rf html ; fi

dist-hook:
	if test -d "html"; then b=; else b="$(srcdir)/"; fi; \
	if test -d $$b"html"; then cp -rf $$b"html" $(distdir) ; fi
