
Introduction
============
Le logiciel HOMARD est destin� � adapter les maillages dans le cadre des codes de calculs par �l�ments ou volumes finis. Ce logiciel, r�alis� par EDF R&D, proc�de par raffinement et d�raffinement des maillages bidimensionnels ou tridimensionnels. Il est con�u pour �tre utilis� ind�pendamment du code de calcul auquel il est coupl�.

Plusieurs motivations apparaissent pour adapter un maillage :

  - on veut simplifier la r�alisation du maillage d'une g�om�trie complexe : on par d'une version grossi�re et on confie � un processus automatique la charge de le raffiner.
  - on veut s'assurer de la convergence de la solution num�rique : plut�t que de r�aliser � la main des maillages de plus en plus fins, on laisse le logiciel chercher lui-m�me les endroits o� il faudrait affiner le maillage pour augmenter la pr�cision du r�sultat.
  - les conditions du calcul changent au cours de son d�roulement : les zones qui doivent �tre maill�es finement se d�placent. Si on maille fin partout d�s le d�but, le maillage est trop gros. En adaptant au fur et � mesure, le maillage ne sera fin qu'aux endroits n�cessaires : sa taille sera r�duite et la qualit� de la solution sera bonne.

Dans tous les cas, le principe de l'adaptation de maillage reste le m�me. Sur le maillage de d�part, on r�alise le calcul standard. A partir d'une analyse de la solution num�rique obtenue, on estime l'erreur qui a �t� commise par rapport � la solution r�elle. Cette estimation se repr�sente par une valeur d'indicateur d'erreur dans chaque maille du calcul. A partir de l�, on applique le principe suivant : les mailles o� l'indicateur d'erreur est fort devraient �tre plus petites et r�ciproquement, les mailles o� l'indicateur d'erreur est faible pourraient �tre plus grandes. Avec cette information, on alimente HOMARD qui va modifier le maillage en cons�quence. Sur le nouveau maillage, on recommencera alors le calcul.
Sch�matiquement, une it�ration d'adaptation de maillage se pr�sente ainsi. Le logiciel calcule la solution num�rique sur le maillage n�k, puis en d�duit les valeurs de l'indicateur d'erreur sur tout le maillage. A partir de la connaissance du maillage n�k et de l'indicateur n�k, HOMARD cr�e le nouveau maillage n�k+1.

.. image:: images/intro_1.png
   :align: center

Au final, la cha�ne compl�te part du maillage initial produit par un mailleur. Elle comprend des maillons successifs (calcul d'indicateur / adaptation) comme sur la figure ci-apr�s.

.. image:: images/intro_2.png
   :align: center

A partir de ce sch�ma de base, des variantes sont possibles. Si aucun calcul d'erreur n'est disponible dans le logiciel coupl�, on peut utiliser un champ pour piloter l'adaptation. Un champ de contraintes en m�caniques peut �tre utilis� : raffiner l� o� les contraintes sont importantes est souvent efficace pour am�liorer la qualit� de la simulation. On peut �galement adapter en fonction du saut d'une variable d'une maille � sa voisine ou dans une zone connue a priori. Gr�ce � ses nombreuses options, HOMARD permet d'envisager de nombreux sc�narios d'adaptation de maillage.

.. note::
  Pour une description plus compl�te, voir :download:`Description g�n�rale de HOMARD <files/HOMARD_0.pdf>`.
