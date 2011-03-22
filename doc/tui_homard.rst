.. _tui_homard:

L'adaptation
============

.. index:: single: it�ration
.. index:: single: calcul

M�thodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+===============================================================+
| .. index:: single: Compute                                    |
|                                                               |
| **Compute(iter_name, option)**                                |
|     Calcule l'adaptation de maillage correspondant �          |
|     une it�ration                                             |
|                                                               |
|     - ``iter_name`` : le nom de l'it�ration                   |
|     - ``option`` : un entier pr�cisant ce qui se passe quand  |
|     des fichiers de r�sultats existent d�j�                   |
|         * 0 : arr�t en erreur                                 |
|         * 1 : �crasement des anciens fichiers                 |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : adaptation r�ussie                              |
|         * autre valeur : probl�me                             |
+---------------------------------------------------------------+


Exemple
"""""""
Le calcul de l'it�ration de nom "Iteration_1" avec �crasement des anciens fichiers de r�sultat se fait ainsi : ::

    iter_name = "Iteration_1"
    codret = homard.Compute(iter_name, 1)
