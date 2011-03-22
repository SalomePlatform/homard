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

+----------------------------------------------------------------+
+================================================================+
| .. module:: CreateBoundary                                     |
|                                                                |
| **CreateBoundary(boundary_name, boundary_type)**               |
|                                                                |
|     - ``boundary_name`` : le nom de la zone                    |
|     - ``boundary_type`` : entier pr�cisant le type de fronti�re|
|                                                                |
|         * 1 : cylindre                                         |
|         * 2 : sph�re                                           |
+----------------------------------------------------------------+

M�thodes de la classe boundary
""""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+===============================================================+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de la fronti�re                           |
+---------------------------------------------------------------+
| .. module:: GetBoundaryType                                   |
|                                                               |
| **GetBoundaryType()**                                         |
|     Retourne le type de la fronti�re                          |
+---------------------------------------------------------------+
| .. module:: SetCylinder                                       |
|                                                               |
| **SetCylinder(Xcen, Ycen, Zcen, Xaxe, Yaxe, Zaxe, R)**        |
|                                                               |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonn�es d'un point   |
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
|     - ``R`` : rayon de la sph�re                              |
+---------------------------------------------------------------+


Exemple
"""""""
Cr�ation d'une fronti�re sph�rique, puis d'une fronti�re cylindrique : ::

    fron_1 = homard.CreateBoundary("FRON_1", 2)
    fron_1.SetSphere(12.3, 3.4, .56, 6.5)
    fron_2 = homard.CreateBoundary('CYL_1', 1)
    fron_2.SetCylinder(0.0, 25., -25., 25., 50., 75., 100.)


