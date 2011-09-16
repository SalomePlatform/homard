.. _gui_create_boundary:

La fronti�re
============
.. index:: single: boundary
.. index:: single: fronti�re

L'objet fronti�re contient toutes les d�finitions g�om�triques permettant de d�crire une fronti�re courbe � suivre.

Il existe deux modes de description d'une fronti�re :

  - Discr�te : ce mode est utilis� pour d�crire une courbe 1D
  - Analytique : ce mode est utilis� pour d�crire une surface


Fronti�re discr�te
==================

Le suivi d'une fronti�re discr�te se fera en s�lectionnant une fronti�re choisie dans la liste des fronti�res discr�tes existantes.

Au d�marrage, la liste est vide. Il faut cr�er une premi�re fronti�re discr�te par activation du bouton "*Nouveau*" :

.. image:: images/create_boundary_di_1.png
   :align: center

La fen�tre propos�e invite au choix d'un fichier de maillage. Ce maillage est celui de toutes les lignes constituant la fronti�re. Un nom de fronti�re est propos� automatiquement : Boun_1, Boun_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir d�j� �t� utilis� pour une autre fronti�re.

.. image:: images/create_boundary_di_2.png
   :align: center

.. note::
  Le fichier ne doit contenir qu'un seul maillage.

Si des fronti�res discr�tes ont d�j� �t� d�finies pour un autre cas, on peut s�lectionner l'une d'elles. On peut �galement cr�er une nouvelle fronti�re discr�te par activation du bouton "*Nouveau*", comme expliqu� pr�c�demment.

.. image:: images/create_boundary_di_3.png
   :align: center



Fronti�re analytique
====================
Au d�marrage, Salome affiche un tableau avec un seule colonne. Cette colonne contient la liste de tous les groupes du maillage initial d�finissant le cas.

.. image:: images/create_boundary_an_1.png
   :align: center

Il faut cr�er une premi�re fronti�re analytique par activation du bouton "*Nouveau*". On aura le choix entre cylindre ou sph�re. Une fois que la fronti�re sera valid�e, son nom figurera en en-t�te d'une deuxi�me colonne.

.. image:: images/create_boundary_an_2.png
   :align: center

Il faut maintenant �tablir le lien entre le maillage d�finissant le cas et cette fronti�re d�crite analytiquement. Cela se fait en cochant les groupes des faces qui doivent se trouver sur la fronti�re.

.. image:: images/create_boundary_an_3.png
   :align: center

Cette op�ration est r�p�t�e autant de fois que l'on souhaite placer des faces du maillages sur une surface courbe :

.. image:: images/create_boundary_an_4.png
   :align: center

.. note::

  Un groupe peut tr�s bien ne jamais �tre coch� : cela signifie que les mailles qu'il d�finit n'appartiennent � aucune des fronti�res d�crites.

  Un groupe ne peut �tre coch� qu'une seule fois. En effet, des mailles surfaciques ne peuvent pas appartenir � plus d'une surface.

  Plusieurs groupes peuvent �tre coch�s pour une m�me fronti�re. Cela arrive quand le maillage initial de la zone a �t� subdivis� en plusieurs groupes : toutes les mailles surfaciques appartiennent � cette surface mais ont �t� r�parties en plusieurs groupes.

  Inversement, une fronti�re peut tr�s bien n'�tre retenue par aucun groupe. Cela arrive si elle a �t� d�finie pour un cas pr�c�dent et qu'elle est sans objet pour le cas en cours de d�finition.


Il existe deux types de fronti�re analytique :

  - Cylindre
  - Sph�re

.. note::
  Les valeurs num�riques propos�es par d�faut tiennent compte de la g�om�trie du maillage.


Un cylindre
"""""""""""
.. index:: single: cylindre

Le cylindre est d�fini par un point de l'axe, son axe et son rayon. L'axe est d�fini par un vecteur. La norme de ce vecteur n'est pas n�cessairement �gale � 1 ; de m�me, son orientation n'a aucune importance. Un nom de fronti�re est propos� automatiquement : Boun_1, Boun_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir d�j� �t� utilis� pour une autre fronti�re.

.. image:: images/create_boundary_an_cy.png
   :align: center

Une sph�re
""""""""""
.. index:: single: sphere

La sph�re est d�finie par son centre et son rayon. Un nom de fronti�re est propos� automatiquement : Boun_1, Boun_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir d�j� �t� utilis� pour une autre fronti�re.

.. image:: images/create_boundary_an_sp.png
   :align: center

.. index:: single: arbre d'�tude

L'arbre d'�tude
"""""""""""""""
A l'issue de cette cr�ation de fronti�res, l'arbre d'�tudes a �t� enrichi. On y trouve toutes les fronti�res cr��es, identifi�es par leur nom, avec la possibilit� de les �diter.

.. image:: images/create_boundary_1.png
   :align: center


M�thodes python correspondantes
"""""""""""""""""""""""""""""""
Consulter : :ref:`tui_create_boundary`



