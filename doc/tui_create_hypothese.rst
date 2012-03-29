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
|     Retourne une instance de la classe hypothese              |
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
|                                                               |
|     - ``use_field`` : entier précisant l'usage du champ       |
|                                                               |
|        * 0 : valeur par élément (défaut)                      |
|        * 1 : saut entre un élément et ses voisins             |
+---------------------------------------------------------------+
| .. module:: SetRefinThr                                       |
|                                                               |
| **SetRefinThr(type_thres, threshold)**                        |
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
|                                                               |
|     - ``comp_name`` : nom d'une composante à prendre en       |
|       compte                                                  |
+---------------------------------------------------------------+
| .. module:: SetUseComp                                        |
|                                                               |
| **SetUseComp(use_comp)**                                      |
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
|                                                               |
|     - ``diammin`` : diamètre minimal voulu pour une maille    |
+---------------------------------------------------------------+
| .. module:: GetDiamMin                                        |
|                                                               |
| **GetDiamMin()**                                              |
|     Retourne le diamètre minimal voulu                        |
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
