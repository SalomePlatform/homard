.. _gui_create_zone:

La zone
=======
.. index:: single: zone
.. index:: single: 2D

L'objet zone contient toutes les d�finitions g�om�triques permettant de d�crire une zone � raffiner.

En 3D, il existe quatre types de zone :

  - Parall�l�pip�de
  - Cylindre
  - Tuyau
  - Sph�re

Leurs analogues en 2D sont :

  - Rectangle
  - Disque
  - Disque perc�

Le principe du raffinement selon des zones est le suivant. Chaque ar�te de maille dont les deux extr�mit�s
sont incluses dans une m�me zone sera coup�e. Ensuite HOMARD applique l'algorithme de traitement de la
conformit� pour produire un maillage correct.

.. note::
  Les valeurs propos�es par d�faut pour les dimensions des zones tiennent compte de la g�om�trie du maillage.

Nom de la zone
""""""""""""""
Un nom de zone est propos� automatiquement : Zone_1, Zone_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir �t� d�j� utilis� pour une autre zone.

Un parall�l�pip�de
""""""""""""""""""
.. index:: single: boite

Le parall�l�pip�de est obligatoirement parall�le aux axes de coordonn�es. Il est d�fini par ses extr�mes dans chaque direction.

.. image:: images/create_zone_1.png
   :align: center

Un cylindre
"""""""""""
.. index:: single: cylindre

Le cylindre est d�fini par son axe, un point de base positionn� sur l'axe, sa hauteur et son rayon. L'axe est d�fini par un vecteur qui doit �tre correctement orient� : on retiendra le volume partant de la base dans la direction du vecteur jusqu'� la hauteur retenue. La norme de ce vecteur n'est pas n�cessairement �gale � 1.

.. image:: images/create_zone_2.png
   :align: center

Un tuyau
""""""""
.. index:: single: tuyau

Le cylindre est d�fini par son axe, un point de base positionn� sur l'axe, sa hauteur et ses rayons interne et externe. L'axe est d�fini par un vecteur qui doit �tre correctement orient� : on retiendra le volume partant de la base dans la direction du vecteur jusqu'� la hauteur retenue. La norme de ce vecteur n'est pas n�cessairement �gale � 1.

.. image:: images/create_zone_3.png
   :align: center

Une sph�re
""""""""""
.. index:: single: sphere

La sph�re est d�finie par son centre et son rayon.

.. image:: images/create_zone_4.png
   :align: center

Un rectangle
""""""""""""
.. index:: single: rectangle

Le rectangle est obligatoirement parall�le aux axes de coordonn�es. Il est d�fini par ses extr�mes dans chacune des directions valides. La coordonn�e constante est affich�e pour information, mais n'est pas modifiable.

.. image:: images/create_zone_21.png
   :align: center

Un disque
"""""""""
.. index:: single: disque

Le disque est obligatoirement dans le plan des axes de coordonn�es. Il est d�fini par son centre et son rayon. La coordonn�e constante est affich�e pour information, mais n'est pas modifiable.

.. image:: images/create_zone_22.png
   :align: center

Un disque avec trou
"""""""""""""""""""
.. index:: single: disque avec trou

Le disque avec trou est obligatoirement dans le plan des axes de coordonn�es. Il est d�fini par son centre et ses rayons externe et interne. La coordonn�e constante est affich�e pour information, mais n'est pas modifiable.

.. image:: images/create_zone_23.png
   :align: center



M�thodes python correspondantes
"""""""""""""""""""""""""""""""
Consulter :ref:`tui_create_zone`
