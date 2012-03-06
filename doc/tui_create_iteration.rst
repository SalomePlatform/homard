.. _tui_create_iteration:

L'it�ration
===========

.. index:: single: it�ration
.. index:: single: hypoth�se
.. index:: single: zone

Les variables sont d�crites dans :ref:`gui_create_iteration`.

M�thodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: CreateIteration                                   |
|                                                               |
| **CreateIteration(iter_name, iter_parent_name)**              |
|     Retourne une instance de la classe iteration              |
|                                                               |
|     - ``iter_name`` : le nom de l'it�ration                   |
|     - ``iter_parent_name`` : le nom de l'it�ration m�re       |
|                                                               |
| Par d�faut :                                                  |
|                                                               |
|  * le maillage produit a le m�me nom que l'it�ration          |
+---------------------------------------------------------------+
| .. module:: AssociateIterHypo                                 |
|                                                               |
| **AssociateIterHypo(iter_name, hypo_name)**                   |
|                                                               |
|     - ``iter_name`` : le nom de l'it�ration                   |
|     - ``hypo_name`` : le nom de l'hypoth�se � associer        |
+---------------------------------------------------------------+

M�thodes de la classe iteration
"""""""""""""""""""""""""""""""

G�n�ralit�s
^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. index:: single: Compute                                    |
|                                                               |
| **Compute(option)**                                           |
|     Calcule le maillage correspondant � l'it�ration           |
|                                                               |
|     - ``option`` : un entier pr�cisant ce qui se passe quand  |
|       des fichiers de r�sultats existent d�j�                 |
|                                                               |
|         * 0 : arr�t en erreur                                 |
|         * 1 : �crasement des anciens fichiers                 |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : adaptation r�ussie                              |
|         * autre valeur : probl�me                             |
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de l'it�ration                            |
+---------------------------------------------------------------+
| .. module:: GetNumber                                         |
|                                                               |
| **GetNumber()**                                               |
|     Retourne le num�ro de l'it�ration.                        |
|                                                               |
|     L'it�ration 0 est celle associ�e au maillage initial.     |
|     Ensuite, une it�ration de num�ro N est issue de           |
|     l'adaptation d'une it�ration de num�ro N-1.               |
+---------------------------------------------------------------+
| .. module:: GetIterParent                                     |
|                                                               |
| **GetIterParent()**                                           |
|     Retourne le nom de l'it�ration m�re                       |
+---------------------------------------------------------------+
| .. module:: GetHypoName                                       |
|                                                               |
| **GetHypoName()**                                             |
|     Retourne le nom de l'hypoth�se associ�e                   |
+---------------------------------------------------------------+
| .. module:: GetCaseName                                       |
|                                                               |
| **GetCaseName()**                                             |
|     Retourne le nom du cas associ�                            |
+---------------------------------------------------------------+
| .. module:: GetState                                          |
|                                                               |
| **GetState()**                                                |
|     Retourne l'�tat de l'it�ration                            |
|                                                               |
|     - ``0`` : it�ration non calcul�e                          |
|     - ``1`` : it�ration calcul�e correctement                 |
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
|     - ``TimeStep`` : l'instant o� est pris le champ           |
|     - ``Rank`` : le num�ro d'ordre o� est pris le champ       |
+---------------------------------------------------------------+
| .. module:: GetFieldFileName                                  |
|                                                               |
| **GetFieldFileName()**                                        |
|     Retourne le nom du fichier du champ                       |
+---------------------------------------------------------------+
| .. module:: GetTimeStep                                       |
|                                                               |
| **GetTimeStep()**                                             |
|     Retourne l'instant o� est pris le champ                   |
+---------------------------------------------------------------+
| .. module:: GetRank                                           |
|                                                               |
| **GetRank()**                                                 |
|     Retourne le num�ro d'ordre o� est pris le champ           |
+---------------------------------------------------------------+

Exemple
"""""""
.. index:: single: maillage;initial

Pour la cr�ation de la premi�re it�ration, il faut r�cup�rer le nom qui a �t� donn� � celle qui correspond au maillage initial. Ce nom s'obtient avec la m�thode ``GetIter0Name`` appliqu�e au cas. ::

    iter_name = "Iteration_1"
    iter_1 = homard.CreateIteration(iter_name, case_1.GetIter0Name())
    iter_1.SetField(field_file, 0, 0)
    iter_1.SetMeshName("maill_01")
    iter_1.SetMeshFile("/local00/M.01.med")
    homard.AssociateIterHypo(iter_name, "HypoField")
    codret = iter_1.Compute(1)

Pour la cr�ation d'une it�ration suivante, on donnera le nom de l'it�ration parent de laquelle on part. ::

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
