.. _gui_intro:

Introduction
============

Pr�sentation g�n�rale
"""""""""""""""""""""
Le logiciel HOMARD est destin� � adapter les maillages dans le cadre des codes de calculs par �l�ments ou volumes finis. Ce logiciel, r�alis� par EDF R&D, proc�de par raffinement et d�raffinement des maillages bidimensionnels ou tridimensionnels. Il est con�u pour �tre utilis� ind�pendamment du code de calcul auquel il est coupl�.

Raffiner le maillage signifie d�couper des mailles d�sign�es selon des indications founies par l'utilisateur. D�raffiner le maillage signifie revenir en arri�re sur des d�coupages pr�c�demment r�alis�s : ainsi, en aucun cas HOMARD ne peut simplifier un maillage existant qui aura �t� cr�� trop fin. Le d�raffinement prend toute son importance dans les calculs quand la zone d'int�r�t se d�place au cours du calcul pour ne plus tenir compte de raffinements pr�c�demment r�alis�s et qui deviennent inutiles. On en trouvera une illustration au bas de cette page.

HOMARD sait traiter des maillages en 2 ou 3 dimensions et comportant les mailles suivantes :
   - mailles-points
   - segments
   - triangles
   - quadrangles
   - t�tra�dres
   - hexa�dres
   - prismes

Ces mailles peuvent �tre pr�sentes simultan�ment. Par exemple, HOMARD saura adapter un maillage comportant des triangles et des quadrangles.
Les noeuds accept�s sont �videmment les noeuds qui sont les sommets des mailles, ce qui correspond � la description classique � en degr� 1 � . Si les �l�ments sont d�crits � en degr� 2 �, les noeuds compl�mentaires sont g�r�s. En revanche, il ne peut pas y avoir cohabitation de mailles d�crites en degr� 1 et d'autres d�crites en degr� 2. Enfin, HOMARD sait prendre en compte des noeuds isol�s, qui n'appartiendraient � aucune d�finition de mailles : ils ressortiront tels quels du processus d'adaptation.

Le cas des pyramides est � part. Pour un maillage comportant des hexa�dres ou des prismes, la mise en conformit� du maillage issu du raffinement cr�e des pyramides pour assurer la liaison entre deux r�gions de niveaux de raffinement diff�rents. Ces pyramides sont g�r�es comme toutes les mailles de transition et ne sont pas red�coup�es par la suite. En revanche, si le maillage initial contient des pyramides, HOMARD ne saura pas l'adapter et �mettra un message d'erreur. Dans certains cas particuliers, on pourra n�anmoins traiter un tel maillage, comme il est d�crit dans la rubrique 'Options avanc�es' de :ref:`gui_create_case`).

Plusieurs motivations apparaissent pour adapter un maillage :

  - on veut simplifier la r�alisation du maillage d'une g�om�trie complexe : on part d'un maillage grossier et on confie � un processus automatique la charge de le raffiner.
  - on veut s'assurer de la convergence de la solution num�rique : plut�t que de r�aliser � la main des maillages de plus en plus fins, on laisse le logiciel chercher lui-m�me les endroits o� il faudrait affiner le maillage pour augmenter la pr�cision du r�sultat.
  - les conditions du calcul changent au cours de son d�roulement : les zones qui doivent �tre maill�es finement se d�placent. Si on maille fin partout d�s le d�but, le maillage est trop gros. En adaptant au fur et � mesure, le maillage ne sera fin qu'aux endroits n�cessaires : sa taille sera r�duite et la qualit� de la solution sera bonne.

Dans tous les cas, le principe de l'adaptation de maillage reste le m�me. Sur le maillage de d�part, on r�alise le calcul standard. Avec une analyse de la solution num�rique obtenue, on estime l'erreur qui a �t� commise par rapport � la solution r�elle. Cette estimation se repr�sente par une valeur d'indicateur d'erreur dans chaque maille du calcul. A partir de l�, on applique le principe suivant : les mailles o� l'indicateur d'erreur est fort devraient �tre plus petites et, r�ciproquement, les mailles o� l'indicateur d'erreur est faible pourraient �tre plus grandes. Avec cette information, on alimente HOMARD qui va modifier le maillage en cons�quence. Sur le nouveau maillage, on recommencera alors le calcul.
Sch�matiquement, une it�ration d'adaptation de maillage se pr�sente ainsi. Le logiciel calcule la solution num�rique sur le maillage n�k, puis en d�duit les valeurs de l'indicateur d'erreur sur tout le maillage. A partir de la connaissance du maillage n�k et de l'indicateur n�k, HOMARD cr�e le nouveau maillage n�k+1.

.. image:: images/intro_1.png
   :align: center

Au final, la cha�ne compl�te part du maillage initial produit par un mailleur. Elle comprend des maillons successifs (calcul d'indicateur / adaptation) comme sur la figure ci-apr�s.

.. image:: images/intro_2.png
   :align: center

Des variantes de ce sch�ma de base sont possibles. Si aucun calcul d'erreur n'est disponible dans le logiciel coupl�, on peut utiliser un champ pour piloter l'adaptation. Un champ de contraintes en m�caniques peut �tre utilis� : raffiner l� o� les contraintes sont importantes est souvent efficace pour am�liorer la qualit� de la simulation. On peut �galement adapter en fonction du saut d'une variable d'une maille � sa voisine ou dans une zone connue a priori. Gr�ce � ses nombreuses options, HOMARD permet d'envisager de multiples sc�narios d'adaptation de maillage.

.. note::
  Pour une description plus compl�te, voir :download:`Description g�n�rale de HOMARD <files/HOMARD_0.pdf>`.


Quelques illustrations de maillage adapt�s
""""""""""""""""""""""""""""""""""""""""""
.. index:: single: illustration

+---------------------------------------------------------------+
+---------------------------------------------------------------+
|                                                               |
| .. image:: images/intro_3.png                                 |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: images/intro_4.png                                 |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: images/intro_5.png                                 |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: images/intro_6.png                                 |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: images/intro_7.png                                 |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: images/intro_8.gif                                 |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+

D�marrage rapide
""""""""""""""""
.. index:: single: d�marrage
.. index:: single: exemple

L'ensemble des options de pilotage du module HOMARD dans Salome est d�crit dans le :ref:`gui_usage`. Mais on trouvera ici le B.A. BA pour d�couvrir l'utilisation de HOMARD � partir d'un exemple simple. Imaginons que l'on a effectu� un calcul de thermique sur un maillage donn�. On a r�cup�r� en sortie de ce calcul un fichier au format MED, contenant le maillage et le champ des temp�ratures aux noeuds. On aimerait adapter le maillage de telle sorte que l'�cart de temp�rature entre deux noeuds voisins soit inf�rieur � une valeur donn�e.

La premi�re action n�cessite de lancer le module HOMARD, en cr�ant une nouvelle �tude, selon le principe qui a �t� retenu pour tous les autres modules de Salome.

.. image:: images/homard_1.png
   :align: center

Une fois le module HOMARD activ�, on cr�e un cas par le choix "*Nouveau cas*" dans le menu HOMARD. La fen�tre suivante appara�t :

.. image:: images/intro_31.png
   :align: center

Il faut fournir deux informations : le r�pertoire qui contiendra les fichiers produits par les adaptations successives et le fichier issu du calcul que l'on vient de faire. On valide par "Appliquer et fermer".

.. image:: images/intro_32.png
   :align: center

L'arbre d'�tudes est enrichi de ce cas. On d�plie le cas jusqu'� afficher le maillage correspondant � l'it�ration 0. On d�signe cette it�ration initiale et on demande une nouvelle it�ration par "*Nouvelle it�ration*" dans le menu HOMARD ou � la souris. La fen�tre suivante appara�t :

.. image:: images/intro_33.png
   :align: center

On d�signe le fichier issu du calcul que l'on vient de faire et qui contient le champ de temp�rature. C'est le m�me que celui qui a �t� donn� dans la d�finition du cas.

.. image:: images/intro_34.png
   :align: center

On clique sur "Nouveau" dans la rubrique hypoth�se. La fen�tre suivante appara�t :

.. image:: images/intro_35.png
   :align: center

On modifie les options par d�faut pour correspondre � notre choix de pilotage de l'adaptation. La s�lection d'un pilotage par les saut entre �l�ments et d'un seuil absolu de 4.0 va demander le d�coupage de chaque ar�te de maille o� le temp�rature varie de plus de 4.0 degr�s entre les deux extr�mit�s de l'ar�te.

.. image:: images/intro_36.png
   :align: center

On valide par "Appliquer et fermer" cette cr�ation d'hypoth�se, puis la cr�ation de la nouvelle it�ration. On se retrouve avec un arbre d'�tudes enrichi avec la description de l'hypoth�se cr��e et de l'it�ration � calculer, rep�r�e par une icone "en attente".

Lancer l'adaptation s'obtient en s�lectionnant l'it�ration � calculer. On choisit ensuite "*Calculer*" dans le menu HOMARD ou � la souris. L'arbre d'�tudes s'enrichit de fichiers d'informations et du nom du fichier au format MED qui contient le nouveau maillage, ``maill.01.med``. On remarque qu'il est plac� dans le r�pertoire qui a �t� d�sign� � la cr�ation du cas.

.. image:: images/intro_37.png
   :align: center

A ce stade, on va utiliser ce nouveau maillage pour un deuxi�me calcul, dans les m�mes conditions que le premier. Une fois que ce nouveau calcul est achev�, on peut d�cider de poursuivre le processus d'adaptation. Pour cela on revient dans Salome et on active le module HOMARD. On d�signe l'it�ration que l'avait calcul�e pr�c�demment "*Iter_1*" et on demande une nouvelle it�ration. La fen�tre suivante appara�t :

.. image:: images/intro_38.png
   :align: center

Comme on continue l'adaptation avec le m�me crit�re de saut de temp�rature entre noeuds voisins, on garde l'hypoth�se "*Hypo_1*". Il suffit de d�signer le fichier issu du calcul que l'on vient de faire et qui contient le nouveau champ de temp�rature.

.. image:: images/intro_39.png
   :align: center

Comme pr�c�demment, on lance l'adaptation et on r�cup�re les r�sultats dans le r�pertoire du cas, dont le maillage ``maill.02.med``.

.. image:: images/intro_40.png
   :align: center

On peut alors lancer un nouveau calcul sur ce nouveau maillage et poursuiver cette alternance calcul/adaptation jusqu'� l'obtention du r�sultat attendu.
