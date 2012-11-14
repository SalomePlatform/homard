.. _tui_create_zone:

La zone
=======

.. index:: single: zone
.. index:: single: boite
.. index:: single: sphere
.. index:: single: cylindre
.. index:: single: tuyau
.. index:: single: disque
.. index:: single: disque avec trou
.. index:: single: 2D

Les variables sont d�crites dans :ref:`gui_create_zone`.

M�thodes de la classe homard
""""""""""""""""""""""""""""

Ces m�thodes retournent une instance de la classe zone.

+----------------------------------------------------------------------------------+
+----------------------------------------------------------------------------------+
| .. module:: CreateZoneBox                                                        |
|                                                                                  |
| **CreateZoneBox(zone_name, Xmin, Xmax, Ymin, Ymax, Zmin, Zmax)**                 |
|     Retourne une instance de la classe ``zone`` de type parall�l�pip�dique       |
|     apr�s sa cr�ation                                                            |
|                                                                                  |
|     - ``zone_name`` : le nom de la zone bas�e sur un parall�l�pip�de             |
|     - ``Xmin``, ``Xmax`` : coordonn�es extr�mes selon X                          |
|     - ``Ymin``, ``Ymax`` : coordonn�es extr�mes selon Y                          |
|     - ``Zmin``, ``Zmax`` : coordonn�es extr�mes selon Z                          |
+----------------------------------------------------------------------------------+
| .. module:: CreateZoneCylinder                                                   |
|                                                                                  |
| **CreateZoneCylinder(zone_name, Xbase, Ybase, Zbase, Xaxe, Yaxe, Zaxe, R, H)**   |
|     Retourne une instance de la classe ``zone`` de type cylindrique              |
|     apr�s sa cr�ation                                                            |
|                                                                                  |
|     - ``zone_name`` : le nom de la zone bas�e sur un cylindre                    |
|     - ``Xbase``, ``Ybase``, ``Zbase`` : coordonn�es d'un point de base           |
|       positionn� sur l'axe                                                       |
|     - ``Xaxe``, ``Yaxe``, ``Zaxe`` : vecteur de l'axe                            |
|     - ``R`` : rayon du cylindre                                                  |
|     - ``H`` : hauteur du cylindre                                                |
+----------------------------------------------------------------------------------+
| .. module:: CreateZonePipe                                                       |
|                                                                                  |
| **CreateZonePipe(zone_name, Xbase, Ybase, Zbase, Xaxe, Yaxe, Zaxe, R, H, Rint)** |
|     Retourne une instance de la classe ``zone`` de type tuyau                    |
|     apr�s sa cr�ation                                                            |
|                                                                                  |
|     - ``zone_name`` : le nom de la zone bas�e sur un tuyau                       |
|     - ``Xbase``, ``Ybase``, ``Zbase`` : coordonn�es d'un point de base           |
|       positionn� sur l'axe                                                       |
|     - ``Xaxe``, ``Yaxe``, ``Zaxe`` : vecteur de l'axe                            |
|     - ``R`` : rayon externe du tuyau                                             |
|     - ``H`` : hauteur du tuyau                                                   |
|     - ``R`` : rayon interne du tuyau                                             |
+----------------------------------------------------------------------------------+
| .. module:: CreateZoneSphere                                                     |
|                                                                                  |
| **CreateZoneSphere(zone_name, Xcen, Ycen, Zcen, R)**                             |
|     Retourne une instance de la classe ``zone`` de type sph�rique                |
|     apr�s sa cr�ation                                                            |
|                                                                                  |
|     - ``zone_name`` : le nom de la zone bas�e sur une sph�re                     |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonn�es du centre de la sph�re          |
|     - ``R`` : rayon de la sph�re                                                 |
+----------------------------------------------------------------------------------+
| .. module:: CreateZoneBox2D                                                      |
|                                                                                  |
| **CreateZoneBox2D(zone_name, Umin, Umax, Vmin, Vmax, Orient)**                   |
|     Retourne une instance de la classe ``zone`` de type rectangulaire            |
|     apr�s sa cr�ation                                                            |
|                                                                                  |
|     - ``zone_name`` : le nom de la zone bas�e sur un rectangle                   |
|     - ``Umin``, ``Umax`` : coordonn�es extr�mes pour la 1�re dimension           |
|     - ``Vmin``, ``Vmax`` : coordonn�es extr�mes pour la 2nde dimension           |
|     - ``Orient`` : entier pr�cisant la convention d'orientation du plan          |
+----------------------------------------------------------------------------------+
| .. module:: CreateZoneDisk                                                       |
|                                                                                  |
| **CreateZoneDisk(zone_name, Ucen, Vcen, R, Orient)**                             |
|     Retourne une instance de la classe ``zone`` de type disque                   |
|     apr�s sa cr�ation                                                            |
|                                                                                  |
|     - ``zone_name`` : le nom de la zone bas�e sur un disque plein                |
|     - ``Ucen``, ``Vcen`` : coordonn�es du centre du disque                       |
|     - ``R`` : rayon du disque                                                    |
|     - ``Orient`` : entier pr�cisant la convention d'orientation du plan          |
+----------------------------------------------------------------------------------+
| .. module:: CreateZoneDiskWithHole                                               |
|                                                                                  |
| **CreateZoneDiskWithHole(zone_name, Ucen, Vcen, R, Rint, Orient)**               |
|     Retourne une instance de la classe ``zone`` de type disque trou�             |
|     apr�s sa cr�ation                                                            |
|                                                                                  |
|     - ``zone_name`` : le nom de la zone bas�e sur un disque trou�                |
|     - ``Ucen``, ``Vcen`` : coordonn�es du centre du disque                       |
|     - ``R`` : rayon externe du disque                                            |
|     - ``Rint`` : rayon interne du disque                                         |
|     - ``Orient`` : entier pr�cisant la convention d'orientation du plan          |
+----------------------------------------------------------------------------------+



+---------------------------------------------------------------+
+---------------------------------------------------------------+
|   La convention d'orientation du plan est la m�me que celle   |
|   utilis�e dans les autres modules de Salome, en particulier  |
|   GEOM :                                                      |
|                                                               |
|     1. plan XY ; U <==> X et V <==> Y                         |
|     2. plan YZ ; U <==> Y et V <==> Z                         |
|     3. plan ZX ; U <==> Z et V <==> X                         |
+---------------------------------------------------------------+


.. note::
  Les fonctions d�finissant des zones 2D ne doivent �tre utilis�es que si l'int�gralit� du
  maillage est 2D, dans un des plans de coordonn�es.




+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetZone                                           |
|                                                               |
| **GetZone(zone_name)**                                        |
|     Retourne l'instance de la classe ``zone`` connue par      |
|     son nom                                                   |
|                                                               |
|     - ``zone_name`` : le nom de la zone                       |
+---------------------------------------------------------------+
| .. module:: GetAllZones                                       |
|                                                               |
| **GetAllZones()**                                             |
|     Retourne la liste des noms de toutes les zones cr��es     |
|                                                               |
+---------------------------------------------------------------+


M�thodes de la classe zone
""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de la zone                                |
+---------------------------------------------------------------+
| .. module:: GetZoneType                                       |
|                                                               |
| **GetZoneType()**                                             |
|     Retourne le type de la zone                               |
|                                                               |
|         * 2 : parall�l�pip�de                                 |
|         * 3 : sph�re                                          |
|         * 5 : cylindre                                        |
|         * 7 : tuyau                                           |
|         * 11, 12, 13 : rectangle et orientation 1, 2 ou 3     |
|         * 31, 32, 33 : disque et orientation 1, 2 ou 3        |
|         * 61, 62, 63 : disque perc� et orientation 1, 2 ou 3  |
+---------------------------------------------------------------+
| .. module:: GetCoords                                         |
|                                                               |
| **GetCoords()**                                               |
|     Retourne un tableau contenant les coordonn�es de la zone  |
|     dans l'ordre d'entr�e dans le CreateZoneXXXX associ�      |
+---------------------------------------------------------------+


Exemple
"""""""
La cr�ation d'une bo�te 3D ou d'un disque dans le plan XY se fait ainsi : ::

    zone_1 = homard.CreateZoneBox ("BLOC", -1., 1., -30., 40., 10.5, 20.8)
    zone_2 = homard.CreateZoneDisk ("disque", 1., 3., 43.25, 1)


Saisie graphique correspondante
"""""""""""""""""""""""""""""""
Consulter :ref:`gui_create_zone`

.. warning::
  En mode graphique, si on �dite une zone et que l'on modifie une des dimensions, toutes les it�rations qui ont �t� calcul�es pr�c�demment avec cette zone sont invalid�es. En mode python, cela n'est plus vrai : les it�rations restent telles quelles.



