.. _glossaire:

Glossaire
=========

.. glossary::
   :sorted:

   raffinement
      Le raffinement est une op�ration consistant � d�couper les mailles s�lectionn�es.

   niveau
      Le niveau d'une maille est le nombre de d�coupages qu'il a fallu pour l'obtenir. Les mailles du maillage initial sont du niveau 0 par convention.

   d�raffinement
      Le d�raffinement est une op�ration consistant � supprimer des mailles. Il s'agit en fait d'annuler un pr�c�dent d�coupage : on ne reviendra jamais 'plus haut' que le maillage initial.

   zone
      Une zone est une r�gion qui d�finit un pilotage de raffinement : toutes les mailles dont au moins une ar�te est dans une zone seront raffin�es.

   cas
      Un cas est d�fini par un maillage initial et une succession d'adaptations.

   it�ration
      Une it�ration est le processus qui permet de passer d'un maillage � un autre au sein d'un cas. Une it�ration met en oeuvre du raffinement et/ou du d�raffinement selon l'hypoth�se qui lui est attach�e.

   hypoth�se
      Une hypoth�se d�crit les conditions de passage d'un maillage � un autre : raffinement et/ou d�raffinement, mode de pilotage, etc. Une hypoth�se est r�f�renc�e par une ou plusieurs it�rations.

   champ
      Un champ est exprim� sur un maillage, par noeud ou par maille, avec une ou plusieurs composantes. La valeur de ce champ pilote l'adaptation.

   MED
      C'est le format d'�change des maillages et des champs pour Salome.