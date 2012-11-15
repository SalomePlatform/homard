.. _gui_create_case:

Le cas
======
.. index:: single: cas

La d�finition du cas se fait par la donn�e des informations suivantes :

  - Un nom
  - Un r�pertoire
  - Le fichier du maillage initial
  - Le type de conformit� pour la s�rie d'adaptations envisag�es
  - Les �ventuelles fronti�res courbes � respecter

.. image:: images/create_case_1.png
   :align: center


Le nom du cas
"""""""""""""
Un nom de cas est propos� automatiquement : Case_1, Case_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir d�j� �t� utilis� pour un autre cas.

Le r�pertoire
"""""""""""""
Le r�pertoire est celui qui contiendra les fichiers produits par les adaptations successives. Ce r�pertoire doit exister. Par d�faut, Salome propose ``/tmp``. Ce choix peut �tre modifi�, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche. C'est dans ce r�pertoire que seront export�s les maillages au format MED, dans des fichiers de nom ``maill.xx.med``, o� ``xx`` est un num�ro d'ordre cr�� automatiquement ; ces noms de fichiers seront visibles dans l'arbre d'�tudes.

.. image:: images/create_case_2.png
   :align: center

.. index:: single: maillage;initial
.. index:: single: MED

Le maillage initial
"""""""""""""""""""
Le maillage initial doit se trouver dans un fichier au format MED. Classiquement, il aura �t� produit par le logiciel de calcul avec lequel on travaille. Mais il peut �galement avoir �t� cr�� avec le module SMESH et export� au format MED. Le nom du fichier peut �tre fourni, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche.

.. image:: images/create_case_3.png
   :align: center

.. note::
  Le fichier ne doit contenir qu'un seul maillage.

.. warning::
  Le maillage ne doit pas �tre lui-m�me le produit d'une adaptation de maillage par HOMARD, sous peine de perdre la coh�rence entre les diff�rents niveaux de raffinement/d�raffinement

.. index:: single: type de conformit�

Le type de conformit�
"""""""""""""""""""""
Les it�rations qui seront calcul�es pour ce cas devront toutes respecter le m�me comportement vis-�-vis de la conformit�.

L'option par d�faut, 'conforme', implique que les maillages produits par HOMARD seront conformes au sens des �l�ments finis. C'est le choix classique de la plupart des logiciels de simulation par �l�ments finis.

N�anmoins, si le calcul est possible avec des maillages non conformes, on a le choix entre 3 possibilit�s :

.. image:: images/create_case_4.png
   :align: center

* 1 noeud par maille : une maille ne peut poss�der qu'un seul noeud de non conformit� avec ses voisines.
* 1 noeud par ar�te : chaque ar�te d'une maille peut �tre d�coup�e sans que la maille voisine par cette ar�te ne le soit.
* quelconque : aucune limitation sur les raccords de conformit� d'une maille � l'autre.

.. index:: single: fronti�re

Les fronti�res courbes
""""""""""""""""""""""
Quand le bord du domaine est courbe, HOMARD sait placer les nouveaux noeuds sur ces fronti�res pour �viter des singularit�s artificielles. Cette technique est aussi applicable � une courbure int�rieure � un domaine.

Deux cas de figure sont pr�sents :

* courbe 1D : cette courbe peut �tre d�finie dans un plan, par exemple pour un calcul 2D. Elle peut �galement �tre d�finie dans l'espace 3D, par exemple pour l'intersection de deux surfaces. Une ligne � suivre est d�crite de mani�re discr�te.
* surface : une surface � suivre est d�crite de mani�re analytique.

On cochera le ou les boutons voulus :

.. image:: images/create_case_5.png
   :align: center

La d�finition des fronti�res est d�crite dans :ref:`gui_create_boundary`.

.. index:: single: pyramide

Les options avanc�es
""""""""""""""""""""
Par d�faut, aucune option avanc�e n'est active.

N�anmoins, on peut d�finir une oprion avanc�e :

.. image:: images/create_case_7.png
   :align: center

Par d�faut, HOMARD sait traiter des maillages en 2 ou 3 dimensions et comportant les mailles suivantes :
   - mailles-points
   - segments
   - triangles
   - quadrangles
   - t�tra�dres
   - hexa�dres
   - prismes

Si le maillage initial comporte des pyramides, il y a arr�t en erreur. Toutefois, si on est certain que les raffinements ult�rieurs ne toucheront aucune des ar�tes des pyramides, on cochera la case "Pyramides autoris�es". Les adaptations se d�rouleront normalement et les pyramides seront restitu�es telles quelles dans le maillage final.

L'arbre d'�tude
"""""""""""""""
A l'issue de cette cr�ation de cas, l'arbre d'�tudes a �t� enrichi de ce nouveau cas. On y trouve l'it�ration initiale, identifi�e par le nom du maillage qui a �t� lu dans le fichier fourni.

.. image:: images/create_case_6.png
   :align: center



M�thodes python correspondantes
"""""""""""""""""""""""""""""""
Consulter :ref:`tui_create_case`

