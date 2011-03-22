.. _tui_homard:

L'adaptation
============

.. index:: single: itération
.. index:: single: calcul

Méthodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+===============================================================+
| .. index:: single: Compute                                    |
|                                                               |
| **Compute(iter_name, option)**                                |
|     Calcule l'adaptation de maillage correspondant à          |
|     une itération                                             |
|                                                               |
|     - ``iter_name`` : le nom de l'itération                   |
|     - ``option`` : un entier précisant ce qui se passe quand  |
|     des fichiers de résultats existent déjà                   |
|         * 0 : arrêt en erreur                                 |
|         * 1 : écrasement des anciens fichiers                 |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : adaptation réussie                              |
|         * autre valeur : problème                             |
+---------------------------------------------------------------+


Exemple
"""""""
Le calcul de l'itération de nom "Iteration_1" avec écrasement des anciens fichiers de résultat se fait ainsi : ::

    iter_name = "Iteration_1"
    codret = homard.Compute(iter_name, 1)
