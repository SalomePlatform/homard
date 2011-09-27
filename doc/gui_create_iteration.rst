.. _gui_create_iteration:

L'it�ration
===========
.. index:: single: it�ration

La d�finition d'une it�ration se fait par la donn�e des informations suivantes :

  - L'it�ration pr�c�dente
  - Le nom du maillage r�sultat
  - L'hypoth�se utilis�e
  - Eventuellement, le fichier du champ d'indicateurs d'erreur

.. image:: images/create_iteration_1.png
   :align: center

Le nom de l'it�ration
"""""""""""""""""""""
Un nom de cas est propos� automatiquement : Iter_1, Iter_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir �t� utilis� pour une it�ration pr�c�dente.

L'it�ration pr�c�dente
""""""""""""""""""""""
L'it�ration pr�c�dente est choisie dans l'arbre d'�tude. Le nom du maillage correspondant sera affich�.

.. index:: single: maillage;r�sultat

Le nom du maillage r�sultat
"""""""""""""""""""""""""""
L'it�ration en cours de cr�ation produira un maillage. Ce maillage sera connu sous un nom. Ce nom est fourni en le tapant dans la zone de texte. Par d�faut, on propose un nom identique � celui de l'it�ration pr�c�dente.

.. index:: single: champ
.. index:: single: MED

Le champ
""""""""
Pour cr�er ou utiliser une hypoth�se d'adaptation bas�e sur un champ exprim� sur le maillage, on doit fournir le fichier o� se trouve le champ. C'est �galement le cas si on veut interpoler des champs du maillage n au maillage n+1. Ce fichier est au format MED. Classiquement, il aura �t� produit par le logiciel de calcul avec lequel on travaille. Le nom du fichier peut �tre fourni, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche.


.. image:: images/create_iteration_2.png
   :align: center

Dans le cas o� des pas de temps ont �t� d�finis, une solution simple consiste � traiter les champs au dernier pas de temps enregistr� dans le fichier. Si on veut d�finir un autre pas de temps, on coche le bouton "*Pas de temps choisi*". Les valeurs de 'Pas de temps' et de 'Num�ro d'ordre' sont celles correspondant � la convention MED (time step / rank). Ces valeurs d�pendent de la logique qui a �t� retenue par le logiciel qui a �crit le fichier. Souvent ces deux valeurs sont identiques mais il arrive que l'on disjoigne les pas de temps et les intervalles d'archivage.

.. image:: images/create_iteration_3.png
   :align: center

.. index:: single: hypoth�se

L'hypoth�se utilis�e
""""""""""""""""""""
L'it�ration en cours pilotera l'adaptation par HOMARD selon un sc�nario d�fini dans une hypoth�se. Celle-ci est choisie dans la liste des hypoth�ses existantes.

Au d�marrage, il faut cr�er une premi�re hypoth�se par activation du bouton "*Nouveau*" (voir :ref:`gui_create_hypothese`) :

.. image:: images/create_iteration_4.png
   :align: center

Ensuite, si une hypoth�se pr�c�demment d�finie convient, il suffit de la s�lectionner dans la liste propos�e. Sinon, il faut cr�er une nouvelle hypoth�se par activation du bouton "*Nouveau*", puis la s�lectionner dans la liste propos�e :

.. image:: images/create_iteration_5.png
   :align: center


.. note::
  Si on envisage une adaptation selon les valeurs d'un champ sur le maillage, il faut avoir renseign� les informations sur ce champ avant de cr�er une nouvelle hypoth�se.

.. index:: single: arbre d'�tude

L'arbre d'�tude
"""""""""""""""
A l'issue de cette cr�ation d'it�ration, l'arbre d'�tudes a �t� enrichi. On y trouve l'it�ration initiale, identifi�e par le nom du maillage qui a �t� lu dans le fichier fourni, l'it�ration courante, identifi�e par son nom. On trouve aussi l'hypoth�se qui lui est attach�e. L'ic�ne en regard de l'it�ration permet de diff�rencier les it�rations calcul�es ou non.

.. image:: images/create_iteration_6.png
   :align: center

Quand plusieurs it�rations s'encha�nent, leur hypoth�se est visible dans l'arbre d'�tude. On remarquera dans la figure ci-apr�s que deux it�rations peuvent partager la m�me hypoth�se.

.. image:: images/create_iteration_7.png
   :align: center

M�thodes python correspondantes
"""""""""""""""""""""""""""""""
Consulter :ref:`tui_create_iteration`
