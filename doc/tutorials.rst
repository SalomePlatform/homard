Exemples
========
.. index:: single: exemple
.. index:: single: python
On trouvera ici les instructions python pour quelques configurations caractéristiques. Les fichiers de données associés sont téléchargeables.

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
  # Case "Case_0"
  # =============
  Case_0 = homard.CreateCase('Case_0', 'MAILL', dircase+'/tutorial_1.00.med')
  Case_0.SetDirName(dircase)
  Case_0.SetConfType(1)
  #
  # Iterations
  # ==========
  # Iteration "Iter_0"
  Iter_0 = homard.CreateIteration('Iter_0', Case_0.GetIter0Name())
  Iter_0.SetMeshName('MESH')
  Iter_0.SetMeshFile(dircase+'/maill.01.med')
  homard.AssociateIterHypo('Iter_0', 'Hypo_0')
  codret = homard.Compute('Iter_0', 1)

  # Iteration "Iter_1"
  Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
  Iter_1.SetMeshName('MESH')
  Iter_1.SetMeshFile(dircase+'/maill.02.med')
  homard.AssociateIterHypo('Iter_1', 'Hypo_0')
  codret = homard.Compute('Iter_1', 1)

  # Iteration "Iter_2"
  Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1')
  Iter_2.SetMeshName('MESH')
  Iter_2.SetMeshFile(dircase+'/maill.03.med')
  homard.AssociateIterHypo('Iter_2', 'Hypo_0')
  codret = homard.Compute('Iter_2', 1)

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
  Zone_0 = homard.CreateZone('Zone_0', 2)
  Zone_0.SetBox(-0.1, 1.1, -0.1, 1.1, 0.9, 1.1)
  #
  # Sphere "Zone_1"
  Zone_1 = homard.CreateZone('Zone_1', 4)
  Zone_1.SetSphere(0., 0., 0., 1.05)
  #
  # Box "Zone_2"
  Zone_2 = homard.CreateZone('Zone_2', 2)
  Zone_2.SetBox(-0.1, 0.51, -0.1, 0.51, -0.1, 0.51)
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
  # Case "Case_0"
  # =============
  Case_0 = homard.CreateCase('Case_0', 'MZERO', dircase+'/tutorial_2.00.med')
  Case_0.SetDirName(dircase)
  #
  # Iteration "Iter_0"
  # ==================
  Iter_0 = homard.CreateIteration('Iter_0', Case_0.GetIter0Name())
  Iter_0.SetMeshName('M_1')
  Iter_0.SetMeshFile(dircase+'/maill.01.med')
  homard.AssociateIterHypo('Iter_0', 'Hypo_0')
  codret = homard.Compute('Iter_0', 1)
  #
  # Iteration "Iter_1"
  # ==================
  Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
  Iter_1.SetMeshName('M_2')
  Iter_1.SetMeshFile(dircase+'/maill.02.med')
  homard.AssociateIterHypo('Iter_1', 'Hypo_1')
  codret = homard.Compute('Iter_1', 1)

.. note::
  Téléchargement des fichiers

  * :download:`maillage initial<files/tutorial_2.00.med.gz>`
  * :download:`commandes python<files/tutorial_2.py>`


Raffinement selon un champ
""""""""""""""""""""""""""
.. index:: single: champ

On procède ici au raffinement selon un champ. Les hypothèses servent à définir le nom du champ et les seuils de raffinement/déraffinement. La donnée du fichier et des instants est faite dans l'itération. Des champs sur les noeuds ou sur les mailles sont interpolés.
::

  dircase = "/tmp"
  #
  # Hypothesis "Hypo_0"
  # ===================
  Hypo_0 = homard.CreateHypothesis('Hypo_0')
  Hypo_0.SetAdapRefinUnRef(1, 1, 0)
  # Characterization of the field
  Hypo_0.SetField('SOLU_0__QIRE_ELEM_SIGM__________')
  Hypo_0.SetUseComp(0)
  Hypo_0.AddComp('ERREST          ')
  Hypo_0.SetRefinThr(3, 1.0)
  Hypo_0.SetTypeFieldInterp(2)
  Hypo_0.AddFieldInterp('SOLU_0__DEPL____________________')
  Hypo_0.AddFieldInterp('SOLU_0__ERRE_ELEM_SIGM__________')
  #
  # Hypothesis "Hypo_1"
  # ===================
  Hypo_1 = homard.CreateHypothesis('Hypo_1')
  Hypo_1.SetAdapRefinUnRef(1, 1, 1)
  # Characterization of the field
  Hypo_1.SetField('SOLU_1__QIRE_ELEM_SIGM__________')
  Hypo_1.SetUseComp(0)
  Hypo_1.AddComp('ERREST          ')
  Hypo_1.SetRefinThr(3, 1.5)
  Hypo_1.SetUnRefThr(3, 6.)
  Hypo_1.SetTypeFieldInterp(2)
  Hypo_1.AddFieldInterp('SOLU_1__DEPL____________________')
  Hypo_1.AddFieldInterp('SOLU_1__QIRE_ELEM_SIGM__________')
  #
  # Case "Case_0"
  # =============
  Case_0 = homard.CreateCase('Case_0', 'G_0', dircase+'/tutorial_3.00.med')
  Case_0.SetDirName(dircase)
  #
  # Iteration "Iter_0"
  # ==================
  Iter_0 = homard.CreateIteration('Iter_0', Case_0.GetIter0Name())
  Iter_0.SetMeshName('H_1')
  Iter_0.SetMeshFile(dircase+'/maill.01.med')
  Iter_0.SetFieldFile(dircase+'/tutorial_3.00.med')
  Iter_0.SetTimeStepRank( 1, 1)
  homard.AssociateIterHypo('Iter_0', 'Hypo_0')
  codret = homard.Compute('Iter_0', 1)
  #
  # Iteration "Iter_1"
  # ==================
  Iter_1 = homard.CreateIteration('Iter_1', 'Iter_0')
  Iter_1.SetMeshName('H_2')
  Iter_1.SetMeshFile('/tmp/maill.02.med')
  Iter_1.SetFieldFile(dircase+'/tutorial_3.01.med')
  Iter_1.SetTimeStepRank(1, 1)
  homard.AssociateIterHypo('Iter_1', 'Hypo_1')
  codret = homard.Compute('Iter_1', 1)

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
  Boundary_1 = homard.CreateBoundary('intersection', 0)
  Boundary_1.SetMeshFile(dircase+'/tutorial_4.fr.med')
  Boundary_1.SetMeshName('PIQUAGE')
  #
  Boundary_2 = homard.CreateBoundary('cyl_1_ext', 1)
  Boundary_2.SetCylinder(0.0, 25., -25., 25., 50., 75., 100.)
  #
  Boundary_3 = homard.CreateBoundary('cyl_2_ext', 1)
  Boundary_3.SetCylinder(17.5, -2.5, -12.5, -100., -75., -25., 50.)
  #
  Boundary_4 = homard.CreateBoundary('cyl_1_int', 1)
  Boundary_4.SetCylinder(0.0, 25., -25., 25., 50., 75., 75.)
  #
  Boundary_5 = homard.CreateBoundary('cyl_2_int', 1)
  Boundary_5.SetCylinder(17.5, -2.5, -12.5, -100., -75., -25., 25.)
  #
  # Hypothesis "Hypo"
  # ===================
  # Creation of the hypothesis Hypo_1
  Hypo_1 = homard.CreateHypothesis('Hypo_1')
  Hypo_1.SetAdapRefinUnRef(-1, 1, 0)
  Hypo_1.AddGroup('T1_INT')
  Hypo_1.AddGroup('T2_INT')
  # Creation of the hypothesis Hypo_2
  Hypo_2 = homard.CreateHypothesis('Hypo_2')
  Hypo_2.SetAdapRefinUnRef(-1, 1, 0)
  Hypo_2.AddGroup('T1_EXT')
  Hypo_2.AddGroup('T2_EXT')
  #
  # Case "Case"
  # =============
  Case = homard.CreateCase('Case', 'PIQUAGE', dircase+'/tutorial_4.00.med')
  Case.SetDirName(dircase)
  Case.AddBoundaryGroup( 'intersection', '' )
  Case.AddBoundaryGroup( 'cyl_1_ext', 'T1_EXT' )
  Case.AddBoundaryGroup( 'cyl_2_ext', 'T2_EXT' )
  Case.AddBoundaryGroup( 'cyl_1_int', 'T1_INT' )
  Case.AddBoundaryGroup( 'cyl_2_int', 'T2_INT' )
  #
  # Creation of the iterations
  # ==========================
  # Creation of the iteration Iter_1
  Iter_1 = homard.CreateIteration('Iter_1', Case.GetIter0Name() )
  Iter_1.SetMeshName('PIQUAGE_1')
  Iter_1.SetMeshFile(dircase+'/maill.01.med')
  homard.AssociateIterHypo('Iter_1', 'Hypo_1')
  codret = homard.Compute('Iter_1', 1)
  # Creation of the iteration Iter_2
  Iter_2 = homard.CreateIteration('Iter_2', 'Iter_1' )
  Iter_2.SetMeshName('PIQUAGE_2')
  Iter_2.SetMeshFile(dircase+'/maill.02.med')
  homard.AssociateIterHypo('Iter_2', 'Hypo_2')
  codret = homard.Compute('Iter_2', 1)

.. note::
  Téléchargement des fichiers

  * :download:`maillage initial<files/tutorial_4.00.med.gz>`
  * :download:`maillage de la frontière discrète<files/tutorial_4.fr.med.gz>`
  * :download:`commandes python<files/tutorial_4.py>`


.. toctree::
   :maxdepth: 2
