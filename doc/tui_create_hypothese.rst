.. _tui_create_hypothese:

L'hypothèse
===========

.. index:: single: itération
.. index:: single: hypothèse
.. index:: single: zone

Les variables sont décrites dans :ref:`gui_create_hypothese`.

Méthodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: CreateHypothesis                                  |
|                                                               |
| **CreateHypothesis(hypo_name)**                               |
|     Retourne une instance de la classe ``hypothese``          |
|                                                               |
|     - ``hypo_name`` : le nom de l'hypothèse                   |
+---------------------------------------------------------------+
| .. module:: AssociateHypoZone                                 |
|                                                               |
| **AssociateHypoZone(hypo_name, zone_name, type_use)**         |
|                                                               |
|     - ``hypo_name`` : le nom de l'hypothèse                   |
|     - ``zone_name`` : le nom de la zone à associer            |
|     - ``type_use``  : entier précisant l'usage de la zone     |
|                                                               |
|         * 1 : raffinement                                     |
|         * -1 : déraffinement                                  |
+---------------------------------------------------------------+
| .. module:: GetHypothesis                                     |
|                                                               |
| **GetHypothesis(hypo_name)**                                  |
|     Retourne l'instance de la classe ``hypothese`` connue par |
|     son nom                                                   |
|                                                               |
|     - ``hypo_name`` : le nom de l'hypothèse                   |
+---------------------------------------------------------------+
| .. module:: GetAllHypotheses                                  |
|                                                               |
| **GetAllHypotheses()**                                        |
|     Retourne la liste des noms de toutes les hypothèses créées|
|                                                               |
+---------------------------------------------------------------+

Méthodes de la classe hypothese
"""""""""""""""""""""""""""""""

Généralités
^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de l'hypothèse                            |
+---------------------------------------------------------------+
| .. module:: SetAdapRefinUnRef                                 |
|                                                               |
| **SetAdapRefinUnRef(Adap, Refin, UnRef)**                     |
|     Affecte le mode d'adaptation associé à l'hypothèse        |
|                                                               |
|     - ``Adap`` : entier précisant le type d'adaptation        |
|                                                               |
|         * -1 : uniforme                                       |
|         * 0 : selon des zones                                 |
|         * 1 : selon un champ                                  |
|                                                               |
|     - ``Refin`` : entier précisant si le raffinement est actif|
|                                                               |
|         * 0 : inactif                                         |
|         * 1 : actif                                           |
|                                                               |
|     - ``UnRef`` : entier précisant si déraffinement est actif |
|                                                               |
|         * 0 : inactif                                         |
|         * 1 : actif                                           |
|                                                               |
+---------------------------------------------------------------+
| .. module:: GetAdapType                                       |
|                                                               |
| **GetAdapType()**                                             |
|     Retourne le type d'adaptation                             |
+---------------------------------------------------------------+
| .. module:: GetRefinType                                      |
|                                                               |
| **GetRefinType()**                                            |
|     Retourne le type de raffinement                           |
+---------------------------------------------------------------+
| .. module:: GetUnRefType                                      |
|                                                               |
| **GetUnRefType()**                                            |
|     Retourne le type de déraffinement                         |
+---------------------------------------------------------------+

Le champ et les seuils
^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetField                                          |
|                                                               |
| **SetField(field_name)**                                      |
|     Attribue un nom de champ à l'hypothèse                    |
|                                                               |
|     - ``field_name`` : le nom du champ                        |
+---------------------------------------------------------------+
| .. module:: GetFieldName                                      |
|                                                               |
| **GetFieldName()**                                            |
|     Retourne le nom du champ                                  |
+---------------------------------------------------------------+
| .. module:: SetUseField                                       |
|                                                               |
| **SetUseField(use_field)**                                    |
|     Attribue un mode d'usage du champ à l'hypothèse           |
|                                                               |
|     - ``use_field`` : entier précisant l'usage du champ       |
|                                                               |
|        * 0 : valeur par élément (défaut)                      |
|        * 1 : saut entre un élément et ses voisins             |
+---------------------------------------------------------------+
| .. module:: SetRefinThr                                       |
|                                                               |
| **SetRefinThr(type_thres, threshold)**                        |
|     Définit les seuils en raffinement                         |
|                                                               |
|     - ``type_thres`` : entier précisant le type de seuil en   |
|       raffinement                                             |
|                                                               |
|        * 1 : valeur absolue                                   |
|        * 2 : valeur relative en %                             |
|        * 3 : fraction des mailles en %                        |
|                                                               |
|     - ``threshold`` : valeur du seuil                         |
+---------------------------------------------------------------+
| .. module:: GetRefinThrType                                   |
|                                                               |
| **GetRefinThrType()**                                         |
|     Retourne le type de seuil de raffinement                  |
+---------------------------------------------------------------+
| .. module:: SetUnRefThr                                       |
|                                                               |
| **SetUnRefThr(type_thres, threshold)**                        |
|     Définit les seuils en déraffinement                       |
|                                                               |
|     - ``type_thres`` : entier précisant le type de seuil en   |
|       déraffinement                                           |
|                                                               |
|        * 1 : valeur absolue                                   |
|        * 2 : valeur relative en %                             |
|        * 3 : fraction des mailles en %                        |
|                                                               |
|     - ``threshold`` : valeur du seuil                         |
+---------------------------------------------------------------+
| .. module:: GetUnRefThrType                                   |
|                                                               |
| **GetUnRefThrType()**                                         |
|     Retourne le type de seuil de déraffinement                |
+---------------------------------------------------------------+


Les composantes du champ
^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddComp                                           |
|                                                               |
| **AddComp(comp_name)**                                        |
|     Ajoute une composante du champ à considérer               |
|                                                               |
|     - ``comp_name`` : nom d'une composante à prendre en       |
|       compte                                                  |
+---------------------------------------------------------------+
| .. module:: SetUseComp                                        |
|                                                               |
| **SetUseComp(use_comp)**                                      |
|     Définit l'usage des composantes                           |
|                                                               |
|     - ``use_comp`` : entier précisant l'usage des composantes |
|                                                               |
|        * 0 : norme L2 (défaut)                                |
|        * 1 : norme infinie                                    |
|        * 2 : valeur relative, si une seule composante         |
+---------------------------------------------------------------+
| .. module:: GetListComp                                       |
|                                                               |
| **GetListComp()**                                             |
|     Retourne la liste des composantes utilisées               |
+---------------------------------------------------------------+

Le filtrage par les groupes
^^^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddGroup                                          |
|                                                               |
| **AddGroup(group_name)**                                      |
|     Ajoute un groupe au filtrage                              |
|                                                               |
|     - ``group_name`` : nom du groupe à prendre en compte      |
+---------------------------------------------------------------+
| .. module:: GetGroups                                         |
|                                                               |
| **GetGroups()**                                               |
|     Retourne la liste des groupes utilisés pour le filtrage   |
+---------------------------------------------------------------+

Les options avancées
^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetNivMax                                         |
|                                                               |
| **SetNivMax(nivmax)**                                         |
|     Définit le niveau maximal de raffinement                  |
|                                                               |
|     - ``nivmax`` : niveau de raffinement à ne pas dépasser    |
+---------------------------------------------------------------+
| .. module:: GetNivMax                                         |
|                                                               |
| **GetNivMax()**                                               |
|     Retourne le niveau maximal de raffinement                 |
+---------------------------------------------------------------+
| .. module:: SetDiamMin                                        |
|                                                               |
| **SetDiamMin(diammin)**                                       |
|     Définit le diamètre minimal des futures mailles           |
|                                                               |
|     - ``diammin`` : diamètre minimal voulu pour une maille    |
+---------------------------------------------------------------+
| .. module:: GetDiamMin                                        |
|                                                               |
| **GetDiamMin()**                                              |
|     Retourne le diamètre minimal voulu                        |
+---------------------------------------------------------------+
| .. module:: SetAdapInit                                       |
|                                                               |
| **SetAdapInit(option)**                                       |
|     Définit le traitement à appliquer aux mailles où          |
|     le champ de pilotage du raffinement n'est pas défini      |
|                                                               |
|     - ``option`` : entier précisant le choix retenu           |
|                                                               |
|         *  0 : aucun effet (défaut)                           |
|         *  1 : les mailles sans indicateurs sont raffinées    |
|         * -1 : les mailles sans indicateurs sont déraffinées  |
+---------------------------------------------------------------+
| .. module:: GetAdapInit                                       |
|                                                               |
| **GetAdapInit()**                                             |
|     Retourne le type de traitement à appliquer aux mailles où |
|     le champ de pilotage du raffinement n'est pas défini      |
+---------------------------------------------------------------+
| .. module:: SetLevelOutput                                    |
|                                                               |
| **SetLevelOutput(option)**                                    |
|     Précise si on veut récupérer le niveau de raffinement des |
|     mailles sous la forme d'un champ                          |
|                                                               |
|     - ``option`` : entier précisant le choix retenu           |
|                                                               |
|         *  0 : aucun effet (défaut)                           |
|         *  1 : le champ est produit                           |
+---------------------------------------------------------------+
| .. module:: GetLevelOutput                                    |
|                                                               |
| **GetLevelOutput()**                                          |
|     Retourne le choix retenu pour la récupération du niveau   |
|     de raffinement                                            |
+---------------------------------------------------------------+


Exemple
"""""""
La création de l'objet hypo_1 se fait ainsi : ::

    hypo_1 = homard.CreateHypothesis("HypoField")
    hypo_1.SetAdapRefinUnRef(1, 1, 0)
    hypo_1.SetField("INDICATEUR")
    hypo_1.AddComp("INDX")
    hypo_1.AddComp("INDZ")
    hypo_1.SetRefinThr(1, 80.)


Saisie graphique correspondante
"""""""""""""""""""""""""""""""
Consulter :ref:`gui_create_hypothese`

.. warning::
  En mode graphique, si on édite une hypothèse et que l'on modifie une de ses caractéristiques, par exemple le seuil de raffinement, toutes les itérations qui ont été calculées précédemment avec cette hypothèse sont invalidées. En mode python, cela n'est plus vrai : les itérations restent telles quelles.
