.. _tui_create_boundary:

La fronti�re
============

.. index:: single: boundary
.. index:: single: fronti�re
.. index:: single: cylindre
.. index:: single: sphere

Les variables sont d�crites dans :ref:`gui_create_boundary`.

M�thodes de la classe homard
""""""""""""""""""""""""""""
Ces m�thodes retournent une instance de la classe boundary.

+----------------------------------------------------------------------------------------+
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryDi                                                           |
|                                                                                        |
| **CreateBoundaryDi(boundary_name, mesh_name, mesh_file)**                              |
|                                                                                        |
|     - ``boundary_name`` : le nom de la fronti�re discr�te                              |
|     - ``mesh_name`` : le nom du maillage de la fronti�re                               |
|     - ``mesh_file`` : le nom du fichier contenant ce maillage                          |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryCylinder                                                     |
|                                                                                        |
| **CreateBoundaryCylinder(boundary_name, Xcen, Ycen, Zcen, Xaxe, Yaxe, Zaxe, R)**       |
|                                                                                        |
|     - ``boundary_name`` : le nom de la fronti�re analytique bas�e sur un cylindre      |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonn�es d'un point sur l'axe du cylindre      |
|     - ``Xaxe``, ``Yaxe``, ``Zaxe`` : vecteur de l'axe                                  |
|     - ``R`` : rayon du cylindre                                                        |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundarySphere                                                       |
|                                                                                        |
| **CreateBoundarySphere(boundary_name, Xcen, Ycen, Zcen, R)**                           |
|                                                                                        |
|     - ``boundary_name`` : le nom de la fronti�re analytique bas�e sur une sphere       |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonn�es du centre de la sph�re                |
|     - ``R`` : rayon de la sph�re                                                       |
+----------------------------------------------------------------------------------------+

M�thodes de la classe boundary
""""""""""""""""""""""""""""""

+-------------------------------------------------------------------+
+-------------------------------------------------------------------+
| .. module:: GetName                                               |
|                                                                   |
| **GetName()**                                                     |
|     Retourne le nom de la fronti�re                               |
+-------------------------------------------------------------------+
| .. module:: GetBoundaryType                                       |
|                                                                   |
| **GetBoundaryType()**                                             |
|     Retourne le type de la fronti�re :                            |
|                                                                   |
|         * 0 : discr�te                                            |
|         * 1 : cylindre                                            |
|         * 2 : sph�re                                              |
+-------------------------------------------------------------------+
| .. module:: GetCoords                                             |
|                                                                   |
| **GetCoords()**                                                   |
|     Retourne un tableau contenant les coordonn�es de la fronti�re |
|     dans l'ordre d'entr�e dans le CreateBoundaryXXXX associ�      |
+-------------------------------------------------------------------+


Exemple
"""""""
Cr�ation d'une fronti�re discr�te, d'une fronti�re sph�rique, puis d'une fronti�re cylindrique : ::

    inter = homard.CreateBoundaryDi("INTERSECTION", 'PIQUAGE', dircase+'/tutorial_4.fr.med')
    fron_1 = homard.CreateBoundarySphere("FRON_1", 12.3, 3.4, .56, 6.5)
    fron_2 = homard.CreateBoundaryCylinder('CYL_1', 0.0, 25., -25., 25., 50., 75., 100.)


Saisie graphique correspondante
"""""""""""""""""""""""""""""""
Consulter :ref:`gui_create_boundary`
