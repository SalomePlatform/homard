// Copyright (C) 2011-2012  CEA/DEN, EDF R&D
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//

using namespace std;

#include "MonEditCase.h"

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>


// -------------------------------------------------------------
MonEditCase::MonEditCase ( QWidget* parent, bool modal,
                           HOMARD::HOMARD_Gen_var myHomardGen,
                           QString CaseName ):
// -------------------------------------------------------------
/* Constructs a MonEditCase
    herite de MonCreateCase
*/
   MonCreateCase(parent, modal, myHomardGen)
{
    MESSAGE("Debut de MonEditCase" << CaseName.toStdString().c_str());
    setWindowTitle(QObject::tr("HOM_CASE_EDIT_WINDOW_TITLE"));
    _aCaseName = CaseName;
    aCase = _myHomardGen->GetCas(_aCaseName.toStdString().c_str());
    InitValEdit();
}
// ------------------------------
MonEditCase::~MonEditCase()
// ------------------------------
{
}


// ------------------------------
void MonEditCase::InitValEdit()
// ------------------------------
{
  MESSAGE("InitValEdit");
  LECaseName->setText(_aCaseName);
  LECaseName->setReadOnly(true);

  QString aDirName = aCase->GetDirName();
  LEDirName->setText(aDirName);
  LEDirName->setReadOnly(true);
  PushDir->setVisible(0);

  QString _aitername=aCase->GetIter0Name();
  HOMARD::HOMARD_Iteration_var aIter = _myHomardGen->GetIteration(_aitername.toStdString().c_str());
  QString aFileName = aIter->GetMeshFile();
  LEFileName->setText(aFileName);
  LEFileName->setReadOnly(true);
  PushFichier->setVisible(0);

  int ConfType=aCase->GetConfType();
  if(ConfType==1)
  {
      GBTypeNoConf->setVisible(0);
      RBConforme->setChecked(true);
  }
  else
  {
    RBNonConforme->setChecked(true);
    GBTypeNoConf->setVisible(1);
    RB1NpM->setEnabled(false);
    RB1NpA->setEnabled(false);
    RBQuelconque->setEnabled(false);
  };

  if (_ConfType==2) { RB1NpM->setChecked(true);};
  if (_ConfType==3) { RB1NpA->setChecked(true);};
  if (_ConfType==4) { RBQuelconque->setChecked(true);};

  RBNonConforme->setEnabled(false);
  RBConforme->setEnabled(false);

//    Non affichage du mode de suivi de frontiere
  CBBoundaryA->setVisible(0);
  GBBoundaryA->setVisible(0);
  CBBoundaryD->setVisible(0);
  GBBoundaryD->setVisible(0);

//    On passe en revue tous les couples (frontiere,groupe) du cas
  HOMARD::ListBoundaryGroupType_var mesBoundarys = aCase->GetBoundaryGroup();
  if (mesBoundarys->length()>0)
  {
    QStringList ListeFron ;
    QString NomFron ;
    bool BounDi = false ;
    bool BounAn = false ;
    for (int i=0; i<mesBoundarys->length(); i++)
    {
//        Nom de la frontiere
      NomFron = mesBoundarys[i++];
      MESSAGE("NomFron "<<NomFron.toStdString().c_str());
//        L'objet associe pour en deduire le type
      HOMARD::HOMARD_Boundary_var myBoundary = _myHomardGen->GetBoundary(NomFron.toStdString().c_str());
      int type_obj = myBoundary->GetBoundaryType() ;
//        C'est une frontiere discrete
//        Rermarque : on ne gere pas les groupes
      if ( type_obj==0 )
      {
        BounDi = true ;
        CBBoundaryDi->addItem(NomFron);
      }
//        C'est une frontiere analytique
      else
      {
        BounAn = true ;
        int nbcol = TWBoundary->columnCount();
//          On ajoute une ligne pour le groupe
        TWBoundary->insertRow(0);
//          La colonne 0 comporte le nom du groupe
        TWBoundary->setItem( 0, 0, new QTableWidgetItem(QString(mesBoundarys[i]).trimmed()));
//             TWBoundary->item( 0, 0 )->setFlags(Qt::ItemIsEnabled |Qt::ItemIsSelectable );
//          Chacune des colonnes suivantes est associé a une frontiere deja presente : on y met une
//          case non cochee
        for ( int j = 1; j < nbcol; j++ )
        {
          TWBoundary->setItem( 0, j, new QTableWidgetItem( QString ("") ) );
          TWBoundary->item( 0, j )->setFlags( 0 );
          TWBoundary->item( 0, j )->setFlags( Qt::ItemIsUserCheckable  );
          TWBoundary->item( 0, j )->setCheckState( Qt::Unchecked );
        }
//          On cherche si la frontiere en cours d'examen a deja ete rencontree :
//          si oui, on stocke son numero de colonne
        int ok = -1 ;
        for ( int nufr = 0 ; nufr<ListeFron.size(); nufr++)
        { if ( ListeFron[nufr] == NomFron ) ok = nufr+1 ; }
//            si non, on ajoute une colonne
        if ( ok < 0 )
        {
          ListeFron.append(NomFron);
          ok = ListeFron.size() ;
          addBoundaryAn(NomFron);
        }
//          on coche la case correspondant au couple (frontiere,groupe) en cours d'examen
        TWBoundary->item( 0, ok )->setCheckState( Qt::Checked );
      }
    }
    MESSAGE("BounDi "<<BounDi<<", BounAn "<<BounAn);
    if ( BounAn )
    { GBBoundaryA->setVisible(1);
//    On rend les cases non modifiables.
//    On ne peut pas le faire pour tout le tableau sinon on perd l'ascenseur !
      int nbcol = TWBoundary->columnCount();
      int nbrow = TWBoundary->rowCount();
      for ( int i = 0; i < nbrow; i++ )
      { for ( int j = 0; j < nbcol; j++ ) TWBoundary->item( i, j )->setFlags( Qt::ItemIsSelectable ); }
//    on met un nom blanc au coin
      QTableWidgetItem *__colItem = new QTableWidgetItem();
      __colItem->setText(QApplication::translate("CreateCase", "", 0, QApplication::UnicodeUTF8));
      TWBoundary->setHorizontalHeaderItem(0, __colItem);
//    on cache les boutons inutiles
      PBBoundaryAnNew->setVisible(0);
      PBBoundaryAnHelp->setVisible(0);
    }
    if ( BounDi )
    { GBBoundaryD->setVisible(1);
      CBBoundaryDi->setDisabled(true);
      PBBoundaryDiNew->setVisible(0);
      PBBoundaryDiHelp->setVisible(0); }
  }
//
// Les options avancees (non modifiables)
  CBAdvanced->setVisible(0) ;
  CBAdvanced->setEnabled(false) ;
  int Pyram = aCase->GetPyram();
  MESSAGE("Pyram "<<Pyram);
  if ( Pyram > 0 )
  { GBAdvancedOptions->setVisible(1);
    CBPyramid->setChecked(true);
    CBPyramid->setEnabled(false);
  }
  else
  { GBAdvancedOptions->setVisible(0);
    CBPyramid->setChecked(false);
 }
//
  adjustSize();
}

// -------------------------------------
bool MonEditCase::PushOnApply()
// -------------------------------------
{
  return true ;
};
