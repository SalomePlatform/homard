.. _tui_create_hypothese:

L'hypoth�se
===========

.. index:: single: it�ration
.. index:: single: hypoth�se
.. index:: single: zone

Les variables sont d�crites dans :ref:`gui_create_hypothese`.

M�thodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: CreateHypothesis                                  |
|                                                               |
| **CreateHypothesis(hypo_name)**                               |
|     Retourne une instance de la classe hypothese              |
|                                                               |
|     - ``hypo_name`` : le nom de l'hypoth�se                   |
+---------------------------------------------------------------+
| .. module:: AssociateHypoZone                                 |
|                                                               |
| **AssociateHypoZone(hypo_name, zone_name, type_use)**         |
|                                                               |
|     - ``hypo_name`` : le nom de l'hypoth�se                   |
|     - ``zone_name`` : le nom de la zone � associer            |
|     - ``type_use``  : entier pr�cisant l'usage de la zone     |
|                                                               |
|         * 1 : raffinement                                     |
|         * -1 : d�raffinement                                  |
+---------------------------------------------------------------+

M�thodes de la classe hypothese
"""""""""""""""""""""""""""""""

G�n�ralit�s
^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de l'hypoth�se                            |
+---------------------------------------------------------------+
| .. module:: SetAdapRefinUnRef                                 |
|                                                               |
| **SetAdapRefinUnRef(Adap, Refin, UnRef)**                     |
|                                                               |
|     - ``Adap`` : entier pr�cisant le type d'adaptation        |
|                                                               |
|         * -1 : uniforme                                       |
|         * 0 : selon des zones                                 |
|         * 1 : selon un champ                                  |
|                                                               |
|     - ``Refin`` : entier pr�cisant si le raffinement est actif|
|                                                               |
|         * 0 : inactif                                         |
|         * 1 : actif                                           |
|                                                               |
|     - ``UnRef`` : entier pr�cisant si d�raffinement est actif |
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
|     Retourne le type de d�raffinement                         |
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
|     - ``use_field`` : entier pr�cisant l'usage du champ       |
|                                                               |
|        * 0 : valeur par �l�ment (d�faut)                      |
|        * 1 : saut entre un �l�ment et ses voisins             |
+---------------------------------------------------------------+
| .. module:: SetRefinThr                                       |
|                                                               |
| **SetRefinThr(type_thres, threshold)**                        |
|                                                               |
|     - ``type_thres`` : entier pr�cisant le type de seuil en   |
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
|     - ``type_thres`` : entier pr�cisant le type de seuil en   |
|       d�raffinement                                           |
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
|     Retourne le type de seuil de d�raffinement                |
+---------------------------------------------------------------+


Les composantes du champ
^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddComp                                           |
|                                                               |
| **AddComp(comp_name)**                                        |
|                                                               |
|     - ``comp_name`` : nom d'une composante � prendre en       |
|       compte                                                  |
+---------------------------------------------------------------+
| .. module:: SetUseComp                                        |
|                                                               |
| **SetUseComp(use_comp)**                                      |
|                                                               |
|     - ``use_comp`` : entier pr�cisant l'usage des composantes |
|                                                               |
|        * 0 : norme L2 (d�faut)                                |
|        * 1 : norme infinie                                    |
|        * 2 : valeur relative, si une seule composante         |
+---------------------------------------------------------------+
| .. module:: GetListComp                                       |
|                                                               |
| **GetListComp()**                                             |
|     Retourne la liste des composantes utilis�es               |
+---------------------------------------------------------------+

Le filtrage par les groupes
^^^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddGroup                                          |
|                                                               |
| **AddGroup(group_name)**                                      |
|                                                               |
|     - ``group_name`` : nom du groupe � prendre en compte      |
+---------------------------------------------------------------+
| .. module:: GetGroups                                         |
|                                                               |
| **GetGroups()**                                               |
|     Retourne la liste des groupes utilis�s pour le filtrage   |
+---------------------------------------------------------------+

Les options avanc�es
^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetNivMax                                         |
|                                                               |
| **SetNivMax(nivmax)**                                         |
|                                                               |
|     - ``nivmax`` : niveau de raffinement � ne pas d�passer    |
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
|     - ``diammin`` : diam�tre minimal voulu pour une maille    |
+---------------------------------------------------------------+
| .. module:: GetDiamMin                                        |
|                                                               |
| **GetDiamMin()**                                              |
|     Retourne le diam�tre minimal voulu                        |
+---------------------------------------------------------------+


Exemple
"""""""
La cr�ation de l'objet hypo_1 se fait ainsi : ::

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
  En mode graphique, si on �dite une hypoth�se et que l'on modifie une de ses caract�ristiques, par exemple le seuil de raffinement, toutes les it�rations qui ont �t� calcul�es pr�c�demment avec cette hypoth�se sont invalid�es. En mode python, cela n'est plus vrai : les it�rations restent telles quelles.
