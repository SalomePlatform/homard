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

#include "MonCreateCase.h"
#include "MonCreateBoundaryAn.h"
#include "MonEditBoundaryAn.h"
#include "MonCreateBoundaryDi.h"
#include "MonEditBoundaryDi.h"

#include <QFileDialog>
#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>


// -----------------------------------------------------------------------------------------
MonCreateCase::MonCreateCase(QWidget* parent, bool modal, HOMARD::HOMARD_Gen_var myHomardGen)
// -----------------------------------------------------------------------------------------
/* Constructs a MonCreateCase
 * Inherits from CasHomard
 * Sets attributes to default values
 */
    :
    Ui_CreateCase(),
    _aCaseName(""),_aDirName(""),
    _ConfType(1),
    _Pyram(0)
{
      _myHomardGen=HOMARD::HOMARD_Gen::_duplicate(myHomardGen);
      setupUi(this);
      setModal(modal);
      InitConnect();

      SetNewCaseName() ;
      GBBoundaryA->setVisible(0);
      GBBoundaryD->setVisible(0);
      GBTypeNoConf->setVisible(0);
      adjustSize();
      GBAdvancedOptions->setVisible(0);
      CBPyramid->setChecked(false);
}

// ------------------------------------------------------------------------
MonCreateCase::~MonCreateCase()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonCreateCase::InitConnect()
// ------------------------------------------------------------------------
{
    connect( PushDir,        SIGNAL(pressed()), this, SLOT(SetDirName()));
    connect( PushFichier,    SIGNAL(pressed()), this, SLOT(SetFileName()));

    connect( RBConforme,     SIGNAL(clicked()), this, SLOT(SetConforme()));
    connect( RBNonConforme,  SIGNAL(clicked()), this, SLOT(SetNonConforme()));
    connect( RB1NpM,         SIGNAL(clicked()), this, SLOT(Set1NpM()));
    connect( RB1NpA,         SIGNAL(clicked()), this, SLOT(Set1NpA()));
    connect( RBQuelconque,   SIGNAL(clicked()), this, SLOT(SetQuelconque()));

    connect( CBBoundaryD,      SIGNAL(stateChanged(int)), this, SLOT(SetBoundaryD()));
    connect( PBBoundaryDiNew,  SIGNAL(pressed()), this, SLOT(PushBoundaryDiNew()));
    connect( PBBoundaryDiEdit, SIGNAL(pressed()), this, SLOT(PushBoundaryDiEdit()) );
    connect( PBBoundaryDiHelp, SIGNAL(pressed()), this, SLOT(PushBoundaryDiHelp()) );
    connect( CBBoundaryA,      SIGNAL(stateChanged(int)), this, SLOT(SetBoundaryA()));
    connect( PBBoundaryAnNew,  SIGNAL(pressed()), this, SLOT(PushBoundaryAnNew()));
    connect( PBBoundaryAnEdit, SIGNAL(pressed()), this, SLOT(PushBoundaryAnEdit()) );
    connect( PBBoundaryAnHelp, SIGNAL(pressed()), this, SLOT(PushBoundaryAnHelp()) );

    connect( CBAdvanced,     SIGNAL(stateChanged(int)), this, SLOT(SetAdvanced()));

    connect( buttonOk,       SIGNAL(pressed()), this, SLOT(PushOnOK()));
    connect( buttonApply,    SIGNAL(pressed()), this, SLOT(PushOnApply()));
    connect( buttonCancel,   SIGNAL(pressed()), this, SLOT(close()));
    connect( buttonHelp,     SIGNAL(pressed()), this, SLOT(PushOnHelp()));
    connect( LECaseName,     SIGNAL(textChanged(QString)), this, SLOT(CaseNameChanged()));
}
// ------------------------------------------------------------------------
void MonCreateCase::InitBoundarys()
// ------------------------------------------------------------------------
// Initialisation des menus avec les frontieres deja enregistrees
{
  MESSAGE("InitBoundarys");
// Pour les frontieres analytiques : la colonne des groupes
  HOMARD::ListGroupType_var _listeGroupesCas = aCase->GetGroups();
  QTableWidgetItem *__colItem = new QTableWidgetItem();
  __colItem->setText(QApplication::translate("CreateCase", "", 0, QApplication::UnicodeUTF8));
  TWBoundary->setHorizontalHeaderItem(0, __colItem);
  for ( int i = 0; i < _listeGroupesCas->length(); i++ )
  {
    TWBoundary->insertRow(i);
    TWBoundary->setItem( i, 0, new QTableWidgetItem(QString((_listeGroupesCas)[i]).trimmed()));
    TWBoundary->item( i, 0 )->setFlags(Qt::ItemIsEnabled |Qt::ItemIsSelectable );
  }
// Pour les frontieres discretes : la liste a saisir
// Pour les frontieres analytiques : les colonnes de chaque frontiere
  HOMARD::HOMARD_Boundary_var myBoundary ;
  HOMARD::listeBoundarys_var  mesBoundarys = _myHomardGen->GetAllBoundarys();
//   MESSAGE("Nombre de frontieres enregistrees : "<<mesBoundarys->length());
  for (int i=0; i<mesBoundarys->length(); i++)
  {
    myBoundary = _myHomardGen->GetBoundary(mesBoundarys[i]);
    int type_obj = myBoundary->GetBoundaryType() ;
    if ( type_obj==0 ) { CBBoundaryDi->addItem(QString(mesBoundarys[i])); }
    else               { addBoundaryAn(QString(mesBoundarys[i])); }
  }
// Ajustement
  TWBoundary->resizeColumnsToContents();
  TWBoundary->resizeRowsToContents();
  TWBoundary->clearSelection();
}
// -------------------------------
bool MonCreateCase::PushOnApply()
// --------------------------------
{
  MESSAGE("PushOnApply");
  QString aCaseName=LECaseName->text().trimmed();
  if ( aCaseName == "" )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_CASE_NAME") );
    return false;
  }

  QString aDirName=LEDirName->text().trimmed();
  if (aDirName == QString(""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_CASE_DIRECTORY_1") );
    return false;
  }
  if ((aDirName != _aDirName) and (_myHomardGen->VerifieDir( aDirName.toStdString().c_str()) == false))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_CASE_DIRECTORY_2") );
    return false;
  }
  if (chdir(aDirName.toStdString().c_str()) != 0)
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_CASE_DIRECTORY_3") );
    return false;
  }

  QString aFileName=LEFileName->text().trimmed();
  if (aFileName ==QString(""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_CASE_MESH") );
    return false;
  }

  QString aMeshName = HOMARD_QT_COMMUN::LireNomMaillage(aFileName);
  if (aMeshName == "" )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_MED_FILE_2") );
    return false;
  }

  if (CBBoundaryA->isChecked())
  {
    QStringList ListeGroup ;
    QString NomGroup ;
    int nbcol = TWBoundary->columnCount();
    int nbrow = TWBoundary->rowCount();
    for ( int col=1; col< nbcol; col++)
    {
      for ( int row=0; row< nbrow; row++)
      {
        if ( TWBoundary->item( row, col )->checkState() ==  Qt::Checked )
        {
//        Nom du groupe
          NomGroup = QString(TWBoundary->item(row, 0)->text()) ;
//           MESSAGE("NomGroup "<<NomGroup.toStdString().c_str());
          for ( int nugr = 0 ; nugr<ListeGroup.size(); nugr++)
          {
//             MESSAGE("....... "<<ListeGroup[nugr].toStdString().c_str());
            if ( NomGroup == ListeGroup[nugr] )
            {
              QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                        QObject::tr("HOM_CASE_GROUP").arg(NomGroup) );
              return false;
            }
          }
          ListeGroup.insert(0, NomGroup );
        }
      }
    }
  }

  if (aCaseName != _aCaseName )
  {
    _aCaseName = aCaseName;
    try
    {
    aCase = _myHomardGen->CreateCase( \
            CORBA::string_dup(_aCaseName.toStdString().c_str()),  \
            CORBA::string_dup(aMeshName.toStdString().c_str()),  \
            CORBA::string_dup(aFileName.toStdString().c_str()) );
    }
    catch( SALOME::SALOME_Exception& S_ex )
    {
      QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                QString(CORBA::string_dup(S_ex.details.text)) );
      try
      {
          aCase = _myHomardGen->GetCas(_aCaseName.toStdString().c_str());
          string iter0 = aCase->GetIter0Name();
          HOMARD::HOMARD_Iteration_var aIter =  _myHomardGen->GetIteration(iter0.c_str());
          QString aFileName = aIter->GetMeshFile();
          LEFileName->setText(aFileName);
          LEFileName->setReadOnly(true);
          PushFichier->hide();
      }
      catch( SALOME::SALOME_Exception& S_ex )  {};
      return false;
    }
    LEFileName->setReadOnly(true);
    PushFichier->hide();
    InitBoundarys();
  }

  aCase->SetDirName(aDirName.toStdString().c_str());
  _aDirName=aDirName;
  aCase->SetConfType(_ConfType);

// Enregistrement de la frontiere discrete
  if (CBBoundaryD->isChecked())
  {
    QString monBoundaryDiName=CBBoundaryDi->currentText();
    if (monBoundaryDiName != "" )
    {
      aCase->AddBoundaryGroup(monBoundaryDiName.toStdString().c_str(), "");
    }
  }

// Enregistrement des liens (groupe,frontiere analytique)
  if (CBBoundaryA->isChecked())
  {
    QString NomGroup ;
    int nbcol = TWBoundary->columnCount();
    int nbrow = TWBoundary->rowCount();
    for ( int col=1; col< nbcol; col++)
    {
      for ( int row=0; row< nbrow; row++)
      {
        if ( TWBoundary->item( row, col )->checkState() ==  Qt::Checked )
        {
//        Nom du groupe
          NomGroup = QString(TWBoundary->item(row, 0)->text()) ;
//        Nom de la frontiere
          QTableWidgetItem *__colItem = new QTableWidgetItem();
          __colItem = TWBoundary->horizontalHeaderItem(col);
          aCase->AddBoundaryGroup(QString(__colItem->text()).toStdString().c_str(), NomGroup.toStdString().c_str());
        }
      }
    }
  }

// Options avancees
  if (CBAdvanced->isChecked())
  {
// Autorisation des pyramides
    if (CBPyramid->isChecked()) { _Pyram = 1 ; }
  }

  HOMARD_UTILS::updateObjBrowser();
  return true;
}
// ---------------------------
void MonCreateCase::PushOnOK()
// ---------------------------
{
     bool bOK = PushOnApply();
     if ( bOK )  this->close();
}
//------------------------------
void MonCreateCase::PushOnHelp()
//-------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_case.html"));
}
// ---------------------------------
void MonCreateCase::SetNewCaseName()
// ------------------------------
{
  HOMARD::listeCases_var  MyCases = _myHomardGen->GetAllCases();
  int num = 0; QString aCaseName="";
  while (aCaseName=="" )
  {
    aCaseName.setNum(num+1) ;
    aCaseName.insert(0, QString("Case_")) ;
    for ( int i=0; i<MyCases->length(); i++)
    {
      if ( aCaseName ==  QString((MyCases)[i]))
      {
          num=num+1;
          aCaseName="";
          break;
      }
   }
  }
  LECaseName->clear() ;
  LECaseName->insert(aCaseName);
}

// ------------------------------------------------------------------------
void MonCreateCase::SetDirName()
// ------------------------------------------------------------------------
{
  QString aDirName=QFileDialog::getExistingDirectory ();
  if (!(aDirName.isEmpty()))LEDirName->setText(aDirName);
}
// ------------------------------------------------------------------------
void MonCreateCase::SetFileName()
// ------------------------------------------------------------------------
{
  QString fileName0 = LEFileName->text().trimmed();
  QString fileName = HOMARD_QT_COMMUN::PushNomFichier();
  if (fileName.isEmpty()) fileName = fileName0 ;
  LEFileName->setText(fileName);
}
// ------------------------------------------------------------------------
void MonCreateCase::SetConforme()
// ------------------------------------------------------------------------
{
  GBTypeNoConf->setVisible(0);
  adjustSize();
  _ConfType=1;
}
// ------------------------------------------------------------------------
void MonCreateCase::SetNonConforme()
// ------------------------------------------------------------------------
{
  GBTypeNoConf->setVisible(1);
  RB1NpM->setChecked(true);
  adjustSize();
  _ConfType=2;
}
// ------------------------------------------------------------------------
void MonCreateCase::Set1NpM()
// ------------------------------------------------------------------------
{
  _ConfType=2;
}
// ------------------------------------------------------------------------
void MonCreateCase::Set1NpA()
// ------------------------------------------------------------------------
{
  _ConfType=3;
}
// ------------------------------------------------------------------------
void MonCreateCase::SetQuelconque()
// ------------------------------------------------------------------------
{
  _ConfType=4;
}
// ------------------------------------------------------------------------
void MonCreateCase::SetBoundaryD()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetBoundaryD ");
  if (CBBoundaryD->isChecked())
  {
    bool bOK = PushOnApply();
    if (bOK) { GBBoundaryD->setVisible(1); }
    else     { GBBoundaryD->setVisible(0);
               CBBoundaryD->setChecked(0);
               CBBoundaryD->setCheckState(Qt::Unchecked); }
  }
  else { GBBoundaryD->setVisible(0); }
  adjustSize();
}
// ------------------------------------------------------------------------
void MonCreateCase::addBoundaryDi(QString newBoundary)
// ------------------------------------------------------------------------
{
  CBBoundaryDi->insertItem(0,newBoundary);
  CBBoundaryDi->setCurrentIndex(0);
}
// ------------------------------------------------------------------------
void MonCreateCase::PushBoundaryDiNew()
// ------------------------------------------------------------------------
{
   MonCreateBoundaryDi *BoundaryDlg = new MonCreateBoundaryDi(this, true,
                HOMARD::HOMARD_Gen::_duplicate(_myHomardGen), _aCaseName, "") ;
   BoundaryDlg->show();
}
// ------------------------------------------------------------------------
void MonCreateCase::PushBoundaryDiEdit()
// ------------------------------------------------------------------------
{
  if (CBBoundaryDi->currentText() == QString(""))  return;
  MonEditBoundaryDi *BoundaryDlg = new MonEditBoundaryDi(this, true,
       HOMARD::HOMARD_Gen::_duplicate(_myHomardGen), _aCaseName, CBBoundaryDi->currentText() ) ;
  BoundaryDlg->show();
}
// ------------------------------------------------------------------------
void MonCreateCase::PushBoundaryDiHelp()
// ------------------------------------------------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_boundary.html#frontiere-discrete") ) ;
}
// ------------------------------------------------------------------------
void MonCreateCase::SetBoundaryA()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetBoundaryA ");
  if (CBBoundaryA->isChecked())
  {
    bool bOK = PushOnApply();
    if (bOK) { GBBoundaryA->setVisible(1); }
    else     { GBBoundaryA->setVisible(0);
               CBBoundaryA->setChecked(0);
               CBBoundaryA->setCheckState(Qt::Unchecked); }
  }
  else { GBBoundaryA->setVisible(0); }
  adjustSize();
//
//   MESSAGE("Fin de SetBoundaryA ");
}
// ------------------------------------------------------------------------
void MonCreateCase::addBoundaryAn(QString newBoundary)
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de addBoundaryAn ");
// Ajout d'une nouvelle colonne
  int nbcol = TWBoundary->columnCount();
//   MESSAGE("nbcol " <<  nbcol);
  nbcol += 1 ;
  TWBoundary->setColumnCount ( nbcol ) ;
  QTableWidgetItem *__colItem = new QTableWidgetItem();
  __colItem->setText(QApplication::translate("CreateCase", newBoundary.toStdString().c_str(), 0, QApplication::UnicodeUTF8));
  TWBoundary->setHorizontalHeaderItem(nbcol-1, __colItem);
/*  TWBoundary->horizontalHeaderItem(nbcol-1)->setFlags( Qt::ItemIsSelectable|Qt::ItemIsEnabled );*/
// Chaque case est a cocher
  int nbrow = TWBoundary->rowCount();
//   MESSAGE("nbrow " <<  nbrow);
  for ( int i = 0; i < nbrow; i++ )
  {
    TWBoundary->setItem( i, nbcol-1, new QTableWidgetItem( QString ("") ) );
    TWBoundary->item( i, nbcol-1 )->setFlags( 0 );
    TWBoundary->item( i, nbcol-1 )->setFlags( Qt::ItemIsUserCheckable|Qt::ItemIsEnabled  );
    TWBoundary->item( i, nbcol-1 )->setCheckState( Qt::Unchecked );
  }
  TWBoundary->resizeColumnToContents(nbcol-1);
//   TWBoundary->resizeRowsToContents();
//   MESSAGE("Fin de addBoundaryAn ");
}
// ------------------------------------------------------------------------
void MonCreateCase::PushBoundaryAnNew()
// ------------------------------------------------------------------------
{
   MonCreateBoundaryAn *BoundaryDlg = new MonCreateBoundaryAn(this, true,
                HOMARD::HOMARD_Gen::_duplicate(_myHomardGen), _aCaseName) ;
   BoundaryDlg->show();
}
// ------------------------------------------------------------------------
void MonCreateCase::PushBoundaryAnEdit()
// ------------------------------------------------------------------------
{
  QString nom="";
  int nbcol = TWBoundary->columnCount();
  for ( int i = 1; i < nbcol; i++ )
  {
    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem = TWBoundary->horizontalHeaderItem(i);
    nom = QString(__colItem->text()) ;
    MESSAGE("nom "<<nom.toStdString().c_str());
    if (nom != QString(""))
    { MonEditBoundaryAn *BoundaryDlg = new MonEditBoundaryAn(this, true,
        HOMARD::HOMARD_Gen::_duplicate(_myHomardGen), _aCaseName, nom ) ;
      BoundaryDlg->show(); }
  }
}
// ------------------------------------------------------------------------
void MonCreateCase::PushBoundaryAnHelp()
// ------------------------------------------------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_boundary.html#frontiere-analytique") ) ;
}
// ------------------------------------------------------------------------
void MonCreateCase::CaseNameChanged()
// ------------------------------------------------------------------------
{
    if (_aCaseName != LECaseName->text().trimmed())
    {
       LEFileName->setReadOnly(false);
       PushFichier->show();
    }
}
// ------------------------------------------------------------------------
void MonCreateCase::SetAdvanced()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetAdvanced ");
  if (CBAdvanced->isChecked()) { GBAdvancedOptions->setVisible(1); }
  else
  { GBAdvancedOptions->setVisible(0);
    CBPyramid->setChecked(false);
    _Pyram = 0 ;
 }
  adjustSize();
}
