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

+----------------------------------------------------------------+
+================================================================+
| .. module:: CreateBoundary                                     |
|                                                                |
| **CreateBoundary(boundary_name, boundary_type)**               |
|                                                                |
|     - ``boundary_name`` : le nom de la zone                    |
|     - ``boundary_type`` : entier précisant le type de frontière|
|                                                                |
|         * 1 : cylindre                                         |
|         * 2 : sphère                                           |
+----------------------------------------------------------------+

Méthodes de la classe boundary
""""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+===============================================================+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de la frontière                           |
+---------------------------------------------------------------+
| .. module:: GetBoundaryType                                   |
|                                                               |
| **GetBoundaryType()**                                         |
|     Retourne le type de la frontière                          |
+---------------------------------------------------------------+
| .. module:: SetCylinder                                       |
|                                                               |
| **SetCylinder(Xcen, Ycen, Zcen, Xaxe, Yaxe, Zaxe, R)**        |
|                                                               |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonnées d'un point   |
|        sur l'axe du cylindre                                  |
|     - ``Xaxe``, ``Yaxe``, ``Zaxe`` : vecteur de l'axe         |
|     - ``R`` : rayon du cylindre                               |
+---------------------------------------------------------------+
| .. module:: SetSphere                                         |
|                                                               |
| **SetSphere(Xcen, Ycen, Zcen, R)**                            |
|                                                               |
|     - ``Xcen`` : X du centre                                  |
|     - ``Ycen`` : Y du centre                                  |
|     - ``Zcen`` : Z du centre                                  |
|     - ``R`` : rayon de la sphère                              |
+---------------------------------------------------------------+


Exemple
"""""""
Création d'une frontière sphérique, puis d'une frontière cylindrique : ::

    fron_1 = homard.CreateBoundary("FRON_1", 2)
    fron_1.SetSphere(12.3, 3.4, .56, 6.5)
    fron_2 = homard.CreateBoundary('CYL_1', 1)
    fron_2.SetCylinder(0.0, 25., -25., 25., 50., 75., 100.)


