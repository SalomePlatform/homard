.. _gui_create_zone:

La zone
=======
.. index:: single: zone

L'objet zone contient toutes les d�finitions g�om�triques permettant de d�crire une zone � raffiner.

Il existe deux types de zone :

  - Parall�l�pip�de
  - Sph�re

Nom de la zone
""""""""""""""
Un nom de zone est propos� automatiquement : Zone_1, Zone_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir �t� d�j� utilis� pour une autre zone.

Un parall�l�pip�de
""""""""""""""""""
.. index:: single: boite

Le parall�l�pip�de est forc�ment parall�le aux axes de coordonn�es. Il est d�fini par ses extr�mes dans chaque direction.

.. image:: images/create_zone_1.png
   :align: center

Une sph�re
""""""""""
.. index:: single: sphere

La sph�re est d�finie par son centre et son rayon.

.. image:: images/create_zone_2.png
   :align: center

.. note::
  Les valeurs propos�es par d�faut tiennent compte de la g�om�trie du maillage.



