.. _tui_create_case:

Le cas
======
.. index:: single: cas
.. index:: single: type de conformit�
.. index:: single: maillage;initial

Les variables sont d�crites dans :ref:`gui_create_case`.

M�thodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: CreateCase                                        |
|                                                               |
| **CreateCase(case_name, mesh_name, mesh_file)**               |
|     Retourne une instance de la classe cas                    |
|                                                               |
|     - ``case_name`` : le nom du cas                           |
|     - ``mesh_name`` : le nom du maillage initial              |
|     - ``mesh_file`` : le nom du fichier contenant ce maillage |
|                                                               |
| Par d�faut :                                                  |
|                                                               |
|  * le r�pertoire des r�sultats est ``/tmp``                   |
|  * l'adaptation est conforme                                  |
+---------------------------------------------------------------+


M�thodes de la classe cas
"""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom du cas                                    |
+---------------------------------------------------------------+
| .. module:: SetDirName                                        |
|                                                               |
| **SetDirName(dirname)**                                       |
|                                                               |
|     - ``dirname`` : le nom du r�pertoire des r�sutats         |
+---------------------------------------------------------------+
| .. module:: GetDirName                                        |
|                                                               |
| **GetDirName()**                                              |
|     Retourne le nom du r�pertoire des r�sutats associ� au cas |
+---------------------------------------------------------------+
| .. module:: SetConfType                                       |
|                                                               |
| **SetConfType(conf_type)**                                    |
|                                                               |
|     - ``conf_type`` : entier pr�cisant le mode de conformit�  |
|                                                               |
|         * 1 : conforme                                        |
|         * 2 : non conforme avec 1 noeud par maille            |
|         * 3 : non conforme avec 1 noeud par arete de maille   |
|         * 4 : non conforme quelconque                         |
+---------------------------------------------------------------+
| .. module:: GetConfType                                       |
|                                                               |
| **GetConfType()**                                             |
|     Retourne le type de conformit�                            |
+---------------------------------------------------------------+
| .. module:: GetIter0Name                                      |
|                                                               |
| **GetIter0Name()**                                            |
|     Retourne le nom de l'it�ration 0, associ�e au maillage    |
|     initial. Ce nom est mis automatiquement par le module     |
|     HOMARD et doit �tre utilis� pour encha�ner les adaptations|
+---------------------------------------------------------------+
| .. module:: AddBoundaryGroup                                  |
|                                                               |
| **AddBoundaryGroup(boundary, group)**                         |
|                                                               |
|     - ``boundary`` : nom d'une fronti�re courbe � suivre      |
|                                                               |
|     Pour une fronti�re discr�te :                             |
|                                                               |
|     . si toutes les lignes courbes sont suivies, le second    |
|       argument est une cha�ne vide.                           |
|     . si seulement certaines lignes courbes sont suivies,     |
|       ``group`` est le nom d'un groupe de segments � suivre.  |
|                                                               |
|     Pour une fronti�re analytique :                           |
|                                                               |
|     - ``group`` : nom d'un groupe de faces plac�es sur la     |
|       fronti�re                                               |
+---------------------------------------------------------------+

Les options avanc�es
^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetPyram                                          |
|                                                               |
| **SetPyram(option)**                                          |
|                                                               |
|     - ``option`` : entier pr�cisant le statut des pyramides   |
|       �ventuellement pr�sentes dans le maillage initial       |
|                                                               |
|         * 0 : pyramides refus�es (d�faut)                     |
|         * 1 : pyramides autoris�es                            |
+---------------------------------------------------------------+
| .. module:: GetPyram                                          |
|                                                               |
| **GetPyram()**                                                |
|     Retourne le statut accord� aux pyramides �ventuellement   |
|     pr�sentes dans le maillage initial                        |
+---------------------------------------------------------------+


Exemple
"""""""
La cr�ation de l'objet case_1 se fait ainsi : ::

    case_name = "CAS_1"
    mesh_name = "MAILL"
    mesh_file = "/local00/Salome/Adapt/m0.med"
    case_1 = homard.CreateCase(case_name, mesh_name, mesh_file)
    dirname = "/local00/Salome/Adapt/resu"
    case_1.SetDirName(dirname)
    case_1.SetConfType(1)
    case_1.AddBoundaryGroup( 'intersection', '' )
    case_1.AddBoundaryGroup( 'cyl_1', 'T1_EXT' )
    case_1.AddBoundaryGroup( 'cyl_1', 'T2_EXT' )
    case_1.AddBoundaryGroup( 'cyl_2', 'T_INT' )



Saisie graphique correspondante
"""""""""""""""""""""""""""""""
Consulter :ref:`gui_create_case`


