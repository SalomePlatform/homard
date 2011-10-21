Exemples
========
.. index:: single: exemple
.. index:: single: python

On trouvera ici les instructions python pour quelques configurations caractéristiques. Les fichiers de données associés sont téléchargeables. Il faut penser à modifier le contenu de la variable ``dircase`` : c'est le répertoire dans lequel les fichiers med auront été enregistrés. C'est dans ce répertoire que seront écrits les fichiers résultant des adaptations successives.

Raffinement uniforme
""""""""""""""""""""
.. index:: single: raffinement;uniforme

On fera ici trois raffinements uniformes successifs du maillage contenu dans le fichier ``tutorial_1.00.med``. Quelques remarques :
  * la même hypothèse est utilisée à chaque itération
  * le maillage produit porte toujours le même nom. Cela ne pose pas de problème car il est stocké dans des fichiers différents.

 ::

  dircase = "/tmp"
  #
  # Hypothesis "Hypo_0"
  # ===================
  Hypo_0 = homard.CreateHypothesis('Hypo_0')
  Hypo_0.SetAdapRefinUnRef(-1, 1, 0)
  #
  # Case "Case_1"
  # =============
  Case_1 = homard.CreateCase('Case_1', 'MAILL', dircase+'/tutorial_1.00.med')
  Case_1.SetDirName(dircase)
  Case_1.SetConfType(1)
  #
  # Iterations
  # ==========
  # Iteration "Iter_0"
  Iter_0 = homard.CreateIteration('Iter_0', Case_1.GetIter0Name())
  Iter_0.SetMeshName('MESH')
  Iter_0.SetMeshFile(dircase+'/maill.01.med')
  homard.AssociateIterHypo('Iter_0', 'Hypo_0')
  codret = Iter_0.Compute(1)

  # Iteration "Iter_1"
  Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
  Iter_1.SetMeshName('MESH')
  Iter_1.SetMeshFile(dircase+'/maill.02.med')
  homard.AssociateIterHypo('Iter_1', 'Hypo_0')
  codret = Iter_1.Compute(1)

  # Iteration "Iter_2"
  Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1')
  Iter_2.SetMeshName('MESH')
  Iter_2.SetMeshFile(dircase+'/maill.03.med')
  homard.AssociateIterHypo('Iter_2', 'Hypo_0')
  codret = Iter_2.Compute(1)

.. note::
  Téléchargement des fichiers

  * :download:`maillage initial<files/tutorial_1.00.med.gz>`
  * :download:`commandes python<files/tutorial_1.py>`


Raffinement par des zones
"""""""""""""""""""""""""
.. index:: single: zone

On procède ici au raffinement selon des zones. Pour passer du maillage initial au maillage 'M_1', on utilise une boîte encadrant le plan z=1 et une sphère centrée sur l'origine de rayon 1.05. Puis pour passer du maillage 'M_1' au maillage 'M_2', on remplace la sphère par une boîte encadrant le cube de côté 0.5, pointant sur l'origine. On notera que le type de raffinement n'a pas été précisé ; par défaut, il sera donc conforme.
::

  dircase = "/tmp"
  #
  # Creation of the zones
  # =====================
  # Box "Zone_0"
  Zone_0 = homard.CreateZoneBox('Zone_0', -0.1, 1.1, -0.1, 1.1, 0.9, 1.1)
  #
  # Sphere "Zone_1"
  Zone_1 = homard.CreateZoneSphere('Zone_1', 0., 0., 0., 1.05)
  #
  # Box "Zone_2"
  Zone_2 = homard.CreateZoneBox('Zone_2', -0.1, 0.51, -0.1, 0.51, -0.1, 0.51)
  #
  # Hypothesis "Hypo_0"
  # ===================
  Hypo_0 = homard.CreateHypothesis('Hypo_0')
  Hypo_0.SetAdapRefinUnRef(0, 1, 0)
  homard.AssociateHypoZone('Zone_1', 'Hypo_0')
  homard.AssociateHypoZone('Zone_0', 'Hypo_0')
  #
  # Hypothesis "Hypo_1"
  # ===================
  Hypo_1 = homard.CreateHypothesis('Hypo_1')
  Hypo_1.SetAdapRefinUnRef(0, 1, 0)
  homard.AssociateHypoZone('Zone_0', 'Hypo_1')
  homard.AssociateHypoZone('Zone_2', 'Hypo_1')
  #
  # Case "Case_1"
  # =============
  Case_1 = homard.CreateCase('Case_1', 'MZERO', dircase+'/tutorial_2.00.med')
  Case_1.SetDirName(dircase)
  #
  # Iteration "Iter_0"
  # ==================
  Iter_0 = homard.CreateIteration('Iter_0', Case_1.GetIter0Name())
  Iter_0.SetMeshName('M_1')
  Iter_0.SetMeshFile(dircase+'/maill.01.med')
  homard.AssociateIterHypo('Iter_0', 'Hypo_0')
  codret = Iter_0.Compute(1)
  #
  # Iteration "Iter_1"
  # ==================
  Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
  Iter_1.SetMeshName('M_2')
  Iter_1.SetMeshFile(dircase+'/maill.02.med')
  homard.AssociateIterHypo('Iter_1', 'Hypo_1')
  codret = Iter_1.Compute(1)

.. note::
  Téléchargement des fichiers

  * :download:`maillage initial<files/tutorial_2.00.med.gz>`
  * :download:`commandes python<files/tutorial_2.py>`


Raffinement selon un champ
""""""""""""""""""""""""""
.. index:: single: champ

On procède ici au raffinement selon un champ. Les hypothèses servent à définir le nom du champ et les seuils de raffinement/déraffinement. La donnée du fichier et des instants est faite dans l'itération. Des champs sur les noeuds ou sur les mailles sont interpolés.
Pour adapter le maillage H_1 issu de l'itération Iter_1, deux variantes sont appliquées. Dans la première, Iter_2, le champ est un champ scalaire d'indicateurs d'erreur et on découpe les 1.5% de mailles où l'erreur est la plus grande. Dans la seconde variante, Iter_2_bis, on se base sur un champ vectoriel et on examine le saut de ce vecteur entre une maille et ses voisines : on découpera là où la norme infinie de ce saut est supérieure au seuil absolu de 0.0001.
::

  dircase = "/tmp"
  #
  # Hypothesis "Hypo_0vers1"
  # ========================
  Hypo_0vers1 = homard.CreateHypothesis('Hypo_0vers1')
  Hypo_0vers1.SetAdapRefinUnRef(1, 1, 0)
  # Characterization of the field
  Hypo_0vers1.SetField('SOLU_0__QIRE_ELEM_SIGM__________')
  Hypo_0vers1.SetUseComp(0)
  Hypo_0vers1.AddComp('ERREST          ')
  Hypo_0vers1.SetRefinThr(3, 1.0)
  Hypo_0vers1.SetTypeFieldInterp(2)
  Hypo_0vers1.AddFieldInterp('SOLU_0__DEPL____________________')
  Hypo_0vers1.AddFieldInterp('SOLU_0__ERRE_ELEM_SIGM__________')
  #
  # Hypothesis "Hypo_1vers2"
  # ========================
  Hypo_1vers2 = homard.CreateHypothesis('Hypo_1vers2')
  Hypo_1vers2.SetAdapRefinUnRef(1, 1, 1)
  # Characterization of the field
  Hypo_1vers2.SetField('SOLU_1__QIRE_ELEM_SIGM__________')
  Hypo_1vers2.SetUseComp(0)
  Hypo_1vers2.AddComp('ERREST          ')
  Hypo_1vers2.SetRefinThr(3, 1.5)
  Hypo_1vers2.SetUnRefThr(3, 6.)
  Hypo_1vers2.SetTypeFieldInterp(2)
  Hypo_1vers2.AddFieldInterp('SOLU_1__DEPL____________________')
  Hypo_1vers2.AddFieldInterp('SOLU_1__QIRE_ELEM_SIGM__________')
  #
  # Hypothesis "Hypo_1vers2_bis"
  # ============================
  Hypo_1vers2_bis = homard.CreateHypothesis('Hypo_1vers2_bis')
  Hypo_1vers2_bis.SetAdapRefinUnRef(1, 1, 1)
  # Characterization of the field
  Hypo_1vers2_bis.SetField('SOLU_1__DEPL____________________')
  Hypo_1vers2_bis.SetUseComp(1)
  Hypo_1vers2_bis.AddComp('DX')
  Hypo_1vers2_bis.AddComp('DY')
  Hypo_1vers2_bis.AddComp('DZ')
  Hypo_1vers2_bis.SetRefinThr(1, 0.0001)
  Hypo_1vers2_bis.SetUnRefThr(1, 0.000001)
  Hypo_1vers2_bis.SetTypeFieldInterp(0)
  #
  # Case "Case_1"
  # =============
  Case_1 = homard.CreateCase('Case_1', 'G_0', dircase+'/tutorial_3.00.med')
  Case_1.SetDirName(dircase)
  #
  # Iteration "Iter_1"
  # ==================
  Iter_1 = homard.CreateIteration('Iter_1', Case_1.GetIter0Name())
  Iter_1.SetMeshName('H_1')
  Iter_1.SetMeshFile(dircase+'/maill.01.med')
  Iter_1.SetFieldFile(dircase+'/tutorial_3.00.med')
  Iter_1.SetTimeStepRank( 1, 1)
  homard.AssociateIterHypo('Iter_1', 'Hypo_0vers1')
  codret = Iter_1.Compute(1)
  #
  # Iteration "Iter_2"
  # ==================
  Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1')
  Iter_2.SetMeshName('H_2')
  Iter_2.SetMeshFile(dircase+'/maill.02.med')
  Iter_2.SetFieldFile(dircase+'/tutorial_3.01.med')
  Iter_2.SetTimeStepRank(1, 1)
  homard.AssociateIterHypo('Iter_2', 'Hypo_1vers2')
  codret = Iter_2.Compute(1)
  #
  # Iteration "Iter_2_bis"
  # ======================
  Iter_2_bis = homard.CreateIteration('Iter_2_bis', 'Iter_1')
  Iter_2_bis.SetMeshName('H_2_bis')
  Iter_2_bis.SetMeshFile(dircase+'/maill.02.bis.med')
  Iter_2_bis.SetFieldFile(dircase+'/tutorial_3.01.med')
  Iter_2_bis.SetTimeStepRank(1, 1)
  homard.AssociateIterHypo('Iter_2_bis', 'Hypo_1vers2_bis')
  codret = Iter_2_bis.Compute(1)

.. note::
  Téléchargement des fichiers

  * :download:`maillage et champ étape 0<files/tutorial_3.00.med.gz>`
  * :download:`maillage et champ étape 1<files/tutorial_3.01.med.gz>`
  * :download:`commandes python<files/tutorial_3.py>`


Suivi de frontières courbes
"""""""""""""""""""""""""""
.. index:: single: champ

On teste ici le suivi des frontières courbes : des frontières analytiques pour décrire les différentes surfaces des tuyaux et une frontière discrète pour décrire les lignes d'intersection des deux tuyaux. Le pilotage du raffinement est le suivant : raffinement uniforme de toutes les mailles contenues dans des groupes désignés.
::

  dircase = "/tmp"
  #
  # Creation of the boundaries
  # ==========================
  Boundary_1 = homard.CreateBoundaryDi('intersection', 'PIQUAGE', dircase+'/tutorial_4.fr.med')
  #
  Boundary_2 = homard.CreateBoundaryCylinder('cyl_1_ext', 0.0, 25., -25., 25., 50., 75., 100.)
  #
  Boundary_3 = homard.CreateBoundaryCylinder('cyl_2_ext', 17.5, -2.5, -12.5, -100., -75., -25., 50.)
  #
  Boundary_4 = homard.CreateBoundaryCylinder('cyl_1_int', 0.0, 25., -25., 25., 50., 75., 75.)
  #
  Boundary_5 = homard.CreateBoundaryCylinder('cyl_2_int', 17.5, -2.5, -12.5, -100., -75., -25., 25.)
  #
  # Hypothesis "Hypo"
  # ===================
  # Creation of the hypothesis Hypo_1
  Hypo_1 = homard.CreateHypothesis('Hypo_1')
  Hypo_1.SetAdapRefinUnRef(-1, 1, 0)
  Hypo_1.AddGroup('T1_INT_I')
  Hypo_1.AddGroup('T1_INT_O')
  Hypo_1.AddGroup('T2_INT')
  # Creation of the hypothesis Hypo_2
  Hypo_2 = homard.CreateHypothesis('Hypo_2')
  Hypo_2.SetAdapRefinUnRef(-1, 1, 0)
  Hypo_2.AddGroup('T1_EXT_I')
  Hypo_2.AddGroup('T1_EXT_O')
  Hypo_2.AddGroup('T2_EXT')
  #
  # Case "Case"
  # =============
  Case = homard.CreateCase('Case', 'PIQUAGE', dircase+'/tutorial_4.00.med')
  Case.SetDirName(dircase)
  Case.AddBoundaryGroup( 'intersection', '' )
  Case.AddBoundaryGroup( 'cyl_1_ext', 'T1_EXT_I' )
  Case.AddBoundaryGroup( 'cyl_1_ext', 'T1_EXT_O' )
  Case.AddBoundaryGroup( 'cyl_2_ext', 'T2_EXT' )
  Case.AddBoundaryGroup( 'cyl_1_int', 'T1_INT_I' )
  Case.AddBoundaryGroup( 'cyl_1_int', 'T1_INT_O' )
  Case.AddBoundaryGroup( 'cyl_2_int', 'T2_INT' )
  #
  # Creation of the iterations
  # ==========================
  # Creation of the iteration Iter_1
  Iter_1 = homard.CreateIteration('Iter_1', Case.GetIter0Name() )
  Iter_1.SetMeshName('PIQUAGE_1')
  Iter_1.SetMeshFile(dircase+'/maill.01.med')
  homard.AssociateIterHypo('Iter_1', 'Hypo_1')
  codret = Iter_1.Compute(1)
  # Creation of the iteration Iter_2
  Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1' )
  Iter_2.SetMeshName('PIQUAGE_2')
  Iter_2.SetMeshFile(dircase+'/maill.02.med')
  homard.AssociateIterHypo('Iter_2', 'Hypo_2')
  codret = Iter_2.Compute(1)

.. note::
  Téléchargement des fichiers

  * :download:`maillage initial<files/tutorial_4.00.med.gz>`
  * :download:`maillage de la frontière discrète<files/tutorial_4.fr.med.gz>`
  * :download:`commandes python<files/tutorial_4.py>`


Instructions spécifiques au 2D
""""""""""""""""""""""""""""""
.. index:: single: 2D

Les instructions pour adapter un maillage 2D sont exactement identiques à celles nécessaires à l'adaptation d'un maillage 3D. La seule exception concerne le raffinement selon des zones géométriques : des fonctions différentes sont utilisées pour pouvoir définir des zones 2D. On donne alors les coordonnées 2D des zones, en précisant l'orientation du plan du maillage.
Dans le cas présenté ici, on raffine une première fois toutes les mailles contenues dans un disque percé, puis dans une seconde itération, toutes les mailles contenues dans un rectangle. On notera l'utilisation du suivi des frontières circulaires du domaine.
::

  dircase = "/tmp"
  #
  # Creation of the boundaries
  # ==========================
  # Creation of the discrete boundary Boun_1
  Boun_1 = homard.CreateBoundaryDi('Boun_1', 'MAIL_EXT', dircase+'/tutorial_5.fr.med')
  #
  # Creation of the zones
  # =====================
  # Creation of the disk with hole enveloppe
  enveloppe = homard.CreateZoneDiskWithHole( 'enveloppe', 0., 0., 250., 193., 1 )
  # Creation of the rectangle quart_sup
  quart_sup = homard.CreateZoneBox2D( 'quart_sup', 0., 250., 0., 250., 1 )
  #
  # Hypothesis
  # ==========
  # Creation of the hypothesis Hypo_1
  Hypo_1 = homard.CreateHypothesis('Hypo_1')
  Hypo_1.SetAdapRefinUnRef(0, 1, 0)
  homard.AssociateHypoZone('enveloppe', 'Hypo_1')
  # Creation of the hypothesis Hypo_2
  Hypo_2 = homard.CreateHypothesis('Hypo_2')
  Hypo_2.SetAdapRefinUnRef(0, 1, 0)
  homard.AssociateHypoZone('quart_sup', 'Hypo_2')
  #
  # Case "Case_1"
  # =============
  Case_1 = homard.CreateCase('Case_1', 'COEUR_2D', dircase+'/tutorial_5.00.med')
  Case_1.SetDirName(dircase)
  Case_1.SetConfType(3)
  Case_1.AddBoundaryGroup('Boun_1', '')
  #
  # Iteration "Iter_1"
  # ==================
  Iter_1 = homard.CreateIteration('Iter_1', Case_1.GetIter0Name())
  Iter_1.SetMeshName('COEUR_2D_01')
  Iter_1.SetMeshFile(dircase+'/maill.01.med')
  homard.AssociateIterHypo('Iter_1', 'Hypo_1')
  codret = Iter_1.Compute(1)
  #
  # Iteration "Iter_2"
  # ==================
  Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1')
  Iter_2.SetMeshName('COEUR_2D_02')
  Iter_2.SetMeshFile(dircase+'/maill.02.med')
  homard.AssociateIterHypo('Iter_2', 'Hypo_2')
  codret = Iter_2.Compute(1)

.. note::
  Téléchargement des fichiers

  * :download:`maillage initial<files/tutorial_5.00.med.gz>`
  * :download:`maillage de la frontière discrète<files/tutorial_5.fr.med.gz>`
  * :download:`commandes python<files/tutorial_5.py>`


.. toctree::
   :maxdepth: 2
