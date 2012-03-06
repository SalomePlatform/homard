.. _tui_create_iteration:

L'itération
===========

.. index:: single: itération
.. index:: single: hypothèse
.. index:: single: zone

Les variables sont décrites dans :ref:`gui_create_iteration`.

Méthodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: CreateIteration                                   |
|                                                               |
| **CreateIteration(iter_name, iter_parent_name)**              |
|     Retourne une instance de la classe iteration              |
|                                                               |
|     - ``iter_name`` : le nom de l'itération                   |
|     - ``iter_parent_name`` : le nom de l'itération mère       |
|                                                               |
| Par défaut :                                                  |
|                                                               |
|  * le maillage produit a le même nom que l'itération          |
+---------------------------------------------------------------+
| .. module:: AssociateIterHypo                                 |
|                                                               |
| **AssociateIterHypo(iter_name, hypo_name)**                   |
|                                                               |
|     - ``iter_name`` : le nom de l'itération                   |
|     - ``hypo_name`` : le nom de l'hypothèse à associer        |
+---------------------------------------------------------------+

Méthodes de la classe iteration
"""""""""""""""""""""""""""""""

Généralités
^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. index:: single: Compute                                    |
|                                                               |
| **Compute(option)**                                           |
|     Calcule le maillage correspondant à l'itération           |
|                                                               |
|     - ``option`` : un entier précisant ce qui se passe quand  |
|       des fichiers de résultats existent déjà                 |
|                                                               |
|         * 0 : arrêt en erreur                                 |
|         * 1 : écrasement des anciens fichiers                 |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : adaptation réussie                              |
|         * autre valeur : problème                             |
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de l'itération                            |
+---------------------------------------------------------------+
| .. module:: GetNumber                                         |
|                                                               |
| **GetNumber()**                                               |
|     Retourne le numéro de l'itération.                        |
|                                                               |
|     L'itération 0 est celle associée au maillage initial.     |
|     Ensuite, une itération de numéro N est issue de           |
|     l'adaptation d'une itération de numéro N-1.               |
+---------------------------------------------------------------+
| .. module:: GetIterParent                                     |
|                                                               |
| **GetIterParent()**                                           |
|     Retourne le nom de l'itération mère                       |
+---------------------------------------------------------------+
| .. module:: GetHypoName                                       |
|                                                               |
| **GetHypoName()**                                             |
|     Retourne le nom de l'hypothèse associée                   |
+---------------------------------------------------------------+
| .. module:: GetCaseName                                       |
|                                                               |
| **GetCaseName()**                                             |
|     Retourne le nom du cas associé                            |
+---------------------------------------------------------------+
| .. module:: GetState                                          |
|                                                               |
| **GetState()**                                                |
|     Retourne l'état de l'itération                            |
|                                                               |
|     - ``0`` : itération non calculée                          |
|     - ``1`` : itération calculée correctement                 |
+---------------------------------------------------------------+

Informations sur les maillages
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetMeshName                                       |
|                                                               |
| **GetMeshName()**                                             |
|     Retourne le nom du maillage produit                       |
+---------------------------------------------------------------+
| .. module:: SetMeshFile                                       |
|                                                               |
| **SetMeshFile(mesh_file)**                                    |
|                                                               |
|     - ``mesh_file`` : le nom du fichier qui contiendra        |
|       le maillage produit                                     |
+---------------------------------------------------------------+
| .. module:: GetMeshFile                                       |
|                                                               |
| **GetMeshFile()**                                             |
|     Retourne le nom du fichier du maillage produit            |
+---------------------------------------------------------------+

Informations sur le champ
^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetFieldFile                                      |
|                                                               |
| **SetFieldFile(field_file)**                                  |
|                                                               |
|     - ``field_file`` : le nom du fichier contenant le champ   |
+---------------------------------------------------------------+
| .. module:: SetTimeStepRank                                   |
|                                                               |
| **SetTimeStepRank(TimeStep, Rank)**                           |
|                                                               |
|     - ``TimeStep`` : l'instant où est pris le champ           |
|     - ``Rank`` : le numéro d'ordre où est pris le champ       |
+---------------------------------------------------------------+
| .. module:: GetFieldFileName                                  |
|                                                               |
| **GetFieldFileName()**                                        |
|     Retourne le nom du fichier du champ                       |
+---------------------------------------------------------------+
| .. module:: GetTimeStep                                       |
|                                                               |
| **GetTimeStep()**                                             |
|     Retourne l'instant où est pris le champ                   |
+---------------------------------------------------------------+
| .. module:: GetRank                                           |
|                                                               |
| **GetRank()**                                                 |
|     Retourne le numéro d'ordre où est pris le champ           |
+---------------------------------------------------------------+

Exemple
"""""""
.. index:: single: maillage;initial

Pour la création de la première itération, il faut récupérer le nom qui a été donné à celle qui correspond au maillage initial. Ce nom s'obtient avec la méthode ``GetIter0Name`` appliquée au cas. ::

    iter_name = "Iteration_1"
    iter_1 = homard.CreateIteration(iter_name, case_1.GetIter0Name())
    iter_1.SetField(field_file, 0, 0)
    iter_1.SetMeshName("maill_01")
    iter_1.SetMeshFile("/local00/M.01.med")
    homard.AssociateIterHypo(iter_name, "HypoField")
    codret = iter_1.Compute(1)

Pour la création d'une itération suivante, on donnera le nom de l'itération parent de laquelle on part. ::

    iter_name = "Iteration_2"
    iter_2 = homard.CreateIteration(iter_name, "Iteration_1")
    iter_2.SetField(field_file, 0, 0)
    iter_2.SetMeshName("maill_02")
    iter_2.SetMeshFile("/local00/M.02.med")
    homard.AssociateIterHypo(iter_name, "HypoField")
    codret = iter_2.Compute(1)


Saisie graphique correspondante
"""""""""""""""""""""""""""""""
Consulter :ref:`gui_create_iteration`
