.. _tui_create_boundary:

L'hypoth�se
===========
.. index:: single: hypoth�se

L'hypoth�se contient toutes les param�tres de pilotage d'une adaptation d'un maillage. Cette op�ration permet de r�aliser l'it�ration � laquelle elle est attach�e.

Il existe trois classes d'hypoth�ses :

  - Uniforme sur tout le maillage,
  - Selon un champ,
  - En fonction de zone g�om�trique.

.. image:: images/create_hypothese_1.png
   :align: center


Nom de l'hypoth�se
""""""""""""""""""
Un nom de l'hypoth�se est propos� automatiquement : Hypo_1, Hypo_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir �t� utilis� pour une hypoth�se pr�c�dente.

Adaptation uniforme
"""""""""""""""""""
Par d�faut on propose un raffinement uniforme. Quand on part d'un maillage qui a d�j� �t� raffin�, l'option de d�raffinement supprimera les mailles produites.

Adaptation selon un champ
"""""""""""""""""""""""""

.. note::
  Pour pouvoir adapter le maillage selon un champ il faut avoir au pr�alable d�sign� le fichier med contenant le champ. Cela se fait dans la fen�tre de construction de l'it�ration (voir :ref:`gui_create_iteration`). Le nom du fichier qui a �t� s�lectionn� est affich� sans modification possible ici :

.. image:: images/create_hypothese_ch_1.png
   :align: center

Le champ voulu est � choisir dans la liste des champs contenus dans le fichier.
Une fois ce champ choisi, la liste des ses composantes s'affiche. Il suffit de d�signer la (ou les) composantes d�sir�es.

Si l'on choisit une seule composante, par d�faut, c'est sa valeur absolue qui sera utilis�e, mais il est possible d'utiliser la valeur relative. Dans le cas de plusieurs composantes, par d�faut HOMARD utilisera la norme L2 (euclidienne). On peut toutefois choisir d'utiliser la norme infinie (le max des valeurs absolues des composantes).

On peut choisir de ne pas utiliser directement le champ, mais sa variation d'un �l�ment � ses voisins. Pour cela, on activera le bouton "*Saut entre �l�ments*".

.. image:: images/create_hypothese_ch_2.png
   :align: center


Le raffinement se fait selon un seuil qui d�finit un crit�re haut de raffinement. Toutes les mailles pour lesquelles l'indicateur est sup�rieur � ce crit�re seront raffin�es.
Pour le choix du crit�re, trois variantes sont possible :

  - selon un pourcentage de mailles � raffiner, nombre r�el compris entre 0 et 100 ; HOMARD raffinera les x% des mailles qui ont la plus grande valeur du champ.
  - selon une valeur relative du champ, nombre compris entre 0 et 100 ; HOMARD raffinera les mailles o� le champ est sup�rieur � x% de l'intervalle [mini,maxi].
  - selon une valeur absolue ; toutes les mailles avec une valeur de champ sup�rieure � cette valeur seront raffin�es.

La m�me convention s'applique au d�raffinement, en rempla�ant sup�rieur par inf�rieur. On peut inactiver une des fonctions (raffinement ou d�raffinement) en cochant le bouton ad_hoc.

.. image:: images/create_hypothese_ch_3.png
   :align: center


Adaptation selon une zone
"""""""""""""""""""""""""
.. index:: single: zone

Au d�marrage, il faut cr�er une premi�re zone par activation du bouton "*Nouveau*" (voir :ref:`gui_create_zone`) :

.. image:: images/create_hypothese_zo_1.png
   :align: center

Lorsque des zones ont d�j� �t� cr��es, la liste appara�t dans la fen�tre, ce qui permet de s�lectionner les zones voulues. On doit alors pr�ciser si une zone est utilis�e pour raffiner toutes les mailles dont une ar�te est contenue dans la zone, ou si la zone est utilis�e pour d�raffiner les mailles int�rieures � la zone. Si aucun choix n'est fait, la zone est ignor�e dans cette hypoth�se.

.. image:: images/create_hypothese_zo_2.png
   :align: center


Filtrage par les groupes
""""""""""""""""""""""""
.. index:: single: groupe

On peut restreindre l'application de l'hypoth�se d'adaptation � des groupes. Ainsi les mailles n'appartenant pas � ces groupes ne seront pas modidi�es, sauf par contamination ult�rieure du raffinement pour assurer la conformit� du maillage final.
On coche le bouton associ� :

.. image:: images/create_hypothese_gr_1.png
   :align: center

La liste des groupes de mailles pr�sents dans le maillage est affich�e. Il suffit de cocher ceux voulus pour restreindre l'hypoth�se d'adaptation.

.. image:: images/create_hypothese_gr_2.png
   :align: center


Interpolation de champs
"""""""""""""""""""""""
.. index:: single: interpolation

.. note::
  Pour pouvoir interpoler un champ de l'ancien vers le nouveau maillage, il faut avoir au pr�alable d�sign� le fichier med contenant le champ. Cela se fait dans la fen�tre de construction de l'it�ration (voir :ref:`gui_create_iteration`).

Par d�faut, aucun champ n'est interpol�. A contrario, on peut demander l'interpolation de tous les champs pr�sents dans le fichier fourni :

.. image:: images/create_hypothese_ch_4.png
   :align: center

Si on veut choisir les champs � interpoler, il faut les cocher dans la liste de tous les champs pr�sents dans le fichier fourni :

.. image:: images/create_hypothese_ch_5.png
   :align: center


Les options avanc�es
""""""""""""""""""""
Si la case "Options avanc�es" n'est pas coch�e, aucune contrainte suppl�mentaire n'est d�finie.
Si la case est coch�e, on d�finira les options avanc�es.

Une premi�re s�rie d'options portent sur la finesse maximale de maillage que l'on ne veut pas d�passer. Deux directives sont possibles, s�par�ment ou ensemble. On peut imposer une taille de maille minimale : une maille dont le diam�tre est inf�rieur � cette limite ne sera plus d�coup�e. Par d�faut, on propose un diam�tre minimal nul, ce qui revient � ne rien imposer. On peut imposer un niveau de raffinement maximal. Par d�faut, le maximum est � 99, ce qui �quivaut en g�n�ral � ne rien imposer.

La deuxi�me s�rie d'options n'a d'int�r�t que dans le cas o� l'adaptation est pilot� par un champ et que ce champ n'est pas d�fini partout dans le maillage. Cela arrive par exemple quand on construit un champ bas� sur une distance dans un plan alors que le domaine est 3D : le champ ne sera pas d�fini sur les noeuds hors du plan. Pour de tels champs, cette option permet de pr�ciser le comportement que l'on souhaite dans les r�gions o� le champ n'est pas d�fini. Par d�faut, il ne se passe rien : les mailles sont gard�es telles quelles. On peut choisir les deux autres variantes : raffiner, toutes les mailles seront a priori coup�es, ou d�raffiner, toutes les mailles seront candidates au d�raffinement.

Le dernier choix porte sur une sortie suppl�mentaire de l'adaptation. Si la case est coch�e, le fichier MED en sortie contiendra un champ contenant le niveau de raffinement de chaque maille. La convention est celle de HOMARD : une maille du maillage initial est de niveau 0, une maille issue d'un raffinement d'une maille initiale porte le niveau 1, etc. Les mailles de transition qui sont produites entre deux mailles de niveau diff�rents, n et n+1, sont affect�es du demi-niveau n+0,5. Par d�faut, la case n'est pas coch�e et le champ n'est pas produit.

.. image:: images/create_hypothese_av_1.png
   :align: center

.. index:: single: arbre d'�tude

L'arbre d'�tude
"""""""""""""""
.. index:: single: arbre d'�tude

L'arbre d'�tudes contient les hypoth�ses cr��es et les it�rations qui les utilisent. La description des zones qui leur sont �ventuellement attach�es est pr�sente.

.. image:: images/create_hypothese_2.png
   :align: center



M�thodes python correspondantes
"""""""""""""""""""""""""""""""
Consulter :ref:`tui_create_hypothese`
