.. _tui_create_boundary:

La frontière
============

.. index:: single: boundary
.. index:: single: frontière
.. index:: single: cylindre
.. index:: single: sphere

Les variables sont décrites dans :ref:`gui_create_boundary`.

Méthodes de la classe homard
""""""""""""""""""""""""""""
Ces méthodes retournent une instance de la classe boundary.

+----------------------------------------------------------------------------------------+
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryDi                                                           |
|                                                                                        |
| **CreateBoundaryDi(boundary_name, mesh_name, mesh_file)**                              |
|                                                                                        |
|     - ``boundary_name`` : le nom de la frontière discrète                              |
|     - ``mesh_name`` : le nom du maillage de la frontière                               |
|     - ``mesh_file`` : le nom du fichier contenant ce maillage                          |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryCylinder                                                     |
|                                                                                        |
| **CreateBoundaryCylinder(boundary_name, Xcen, Ycen, Zcen, Xaxe, Yaxe, Zaxe, R)**       |
|                                                                                        |
|     - ``boundary_name`` : le nom de la frontière analytique basée sur un cylindre      |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonnées d'un point sur l'axe du cylindre      |
|     - ``Xaxe``, ``Yaxe``, ``Zaxe`` : vecteur de l'axe                                  |
|     - ``R`` : rayon du cylindre                                                        |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundarySphere                                                       |
|                                                                                        |
| **CreateBoundarySphere(boundary_name, Xcen, Ycen, Zcen, R)**                           |
|                                                                                        |
|     - ``boundary_name`` : le nom de la frontière analytique basée sur une sphere       |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonnées du centre de la sphère                |
|     - ``R`` : rayon de la sphère                                                       |
+----------------------------------------------------------------------------------------+

Méthodes de la classe boundary
""""""""""""""""""""""""""""""

+-------------------------------------------------------------------+
+-------------------------------------------------------------------+
| .. module:: GetName                                               |
|                                                                   |
| **GetName()**                                                     |
|     Retourne le nom de la frontière                               |
+-------------------------------------------------------------------+
| .. module:: GetBoundaryType                                       |
|                                                                   |
| **GetBoundaryType()**                                             |
|     Retourne le type de la frontière :                            |
|                                                                   |
|         * 0 : discrète                                            |
|         * 1 : cylindre                                            |
|         * 2 : sphère                                              |
+-------------------------------------------------------------------+
| .. module:: GetCoords                                             |
|                                                                   |
| **GetCoords()**                                                   |
|     Retourne un tableau contenant les coordonnées de la frontière |
|     dans l'ordre d'entrée dans le CreateBoundaryXXXX associé      |
+-------------------------------------------------------------------+


Exemple
"""""""
Création d'une frontière discrète, d'une frontière sphèrique, puis d'une frontière cylindrique : ::

    inter = homard.CreateBoundaryDi("INTERSECTION", 'PIQUAGE', dircase+'/tutorial_4.fr.med')
    fron_1 = homard.CreateBoundarySphere("FRON_1", 12.3, 3.4, .56, 6.5)
    fron_2 = homard.CreateBoundaryCylinder('CYL_1', 0.0, 25., -25., 25., 50., 75., 100.)


Saisie graphique correspondante
"""""""""""""""""""""""""""""""
Consulter :ref:`gui_create_boundary`
