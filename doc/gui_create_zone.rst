.. _gui_create_zone:

La zone
=======
.. index:: single: zone

L'objet zone contient toutes les définitions géométriques permettant de décrire une zone à raffiner.

Il existe deux types de zone :

  - Parallélépipède
  - Sphère

Nom de la zone
""""""""""""""
Un nom de zone est proposé automatiquement : Zone_1, Zone_2, etc. Ce nom peut être modifié. Il ne doit pas avoir été déjà utilisé pour une autre zone.

Un parallélépipède
""""""""""""""""""
.. index:: single: boite

Le parallélépipède est forcément parallèle aux axes de coordonnées. Il est défini par ses extrêmes dans chaque direction.

.. image:: images/create_zone_1.png
   :align: center

Une sphère
""""""""""
.. index:: single: sphere

La sphère est définie par son centre et son rayon.

.. image:: images/create_zone_2.png
   :align: center

.. note::
  Les valeurs proposées par défaut tiennent compte de la géométrie du maillage.



