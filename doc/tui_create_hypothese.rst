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
|     Retourne une instance de la classe ``hypothese``          |
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
| .. module:: GetHypothesis                                     |
|                                                               |
| **GetHypothesis(hypo_name)**                                  |
|     Retourne l'instance de la classe ``hypothese`` connue par |
|     son nom                                                   |
|                                                               |
|     - ``hypo_name`` : le nom de l'hypoth�se                   |
+---------------------------------------------------------------+
| .. module:: GetAllHypotheses                                  |
|                                                               |
| **GetAllHypotheses()**                                        |
|     Retourne la liste des noms de toutes les hypoth�ses cr��es|
|                                                               |
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
|     Affecte le mode d'adaptation associ� � l'hypoth�se        |
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
|     Attribue un nom de champ � l'hypoth�se                    |
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
|     Attribue un mode d'usage du champ � l'hypoth�se           |
|                                                               |
|     - ``use_field`` : entier pr�cisant l'usage du champ       |
|                                                               |
|        * 0 : valeur par �l�ment (d�faut)                      |
|        * 1 : saut entre un �l�ment et ses voisins             |
+---------------------------------------------------------------+
| .. module:: SetRefinThr                                       |
|                                                               |
| **SetRefinThr(type_thres, threshold)**                        |
|     D�finit les seuils en raffinement                         |
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
|     D�finit les seuils en d�raffinement                       |
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
|     Ajoute une composante du champ � consid�rer               |
|                                                               |
|     - ``comp_name`` : nom d'une composante � prendre en       |
|       compte                                                  |
+---------------------------------------------------------------+
| .. module:: SetUseComp                                        |
|                                                               |
| **SetUseComp(use_comp)**                                      |
|     D�finit l'usage des composantes                           |
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
|     Ajoute un groupe au filtrage                              |
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
|     D�finit le niveau maximal de raffinement                  |
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
|     D�finit le diam�tre minimal des futures mailles           |
|                                                               |
|     - ``diammin`` : diam�tre minimal voulu pour une maille    |
+---------------------------------------------------------------+
| .. module:: GetDiamMin                                        |
|                                                               |
| **GetDiamMin()**                                              |
|     Retourne le diam�tre minimal voulu                        |
+---------------------------------------------------------------+
| .. module:: SetAdapInit                                       |
|                                                               |
| **SetAdapInit(option)**                                       |
|     D�finit le traitement � appliquer aux mailles o�          |
|     le champ de pilotage du raffinement n'est pas d�fini      |
|                                                               |
|     - ``option`` : entier pr�cisant le choix retenu           |
|                                                               |
|         *  0 : aucun effet (d�faut)                           |
|         *  1 : les mailles sans indicateurs sont raffin�es    |
|         * -1 : les mailles sans indicateurs sont d�raffin�es  |
+---------------------------------------------------------------+
| .. module:: GetAdapInit                                       |
|                                                               |
| **GetAdapInit()**                                             |
|     Retourne le type de traitement � appliquer aux mailles o� |
|     le champ de pilotage du raffinement n'est pas d�fini      |
+---------------------------------------------------------------+
| .. module:: SetLevelOutput                                    |
|                                                               |
| **SetLevelOutput(option)**                                    |
|     Pr�cise si on veut r�cup�rer le niveau de raffinement des |
|     mailles sous la forme d'un champ                          |
|                                                               |
|     - ``option`` : entier pr�cisant le choix retenu           |
|                                                               |
|         *  0 : aucun effet (d�faut)                           |
|         *  1 : le champ est produit                           |
+---------------------------------------------------------------+
| .. module:: GetLevelOutput                                    |
|                                                               |
| **GetLevelOutput()**                                          |
|     Retourne le choix retenu pour la r�cup�ration du niveau   |
|     de raffinement                                            |
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
