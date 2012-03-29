
Introduction
============
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
==========================================

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




