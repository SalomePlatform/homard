using namespace std;

#include "MonCreateHypothesis.h"
#include "MonCreateListGroup.h"
#include "MonCreateIteration.h"
#include "MonCreateZone.h"
#include "MonEditZone.h"

#include <QFileDialog>
#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>

// -------------------------------------------------------------------------------
MonCreateHypothesis::MonCreateHypothesis(MonCreateIteration* parent, bool modal,
                                         HOMARD::HOMARD_Gen_var myHomardGen,
                                         QString aHypothesisName,
                                         QString caseName, QString aFieldFile)
// ---------------------------------------------------------------------------------
/* Constructs a MonCreateHypothesis */
    :
    QDialog(0), Ui_CreateHypothesis(),
    _parent(parent), _aHypothesisName(aHypothesisName),
    _aCaseName(caseName), _aFieldFile(aFieldFile), 
    _aFieldName(""),
    _aTypeAdap(-2), _aTypeRaff(1), _aTypeDera(0),
    _TypeThR(3), _ThreshR(0),
    _TypeThC(0), _ThreshC(0),
    _UsCmpI(0), _TypeFieldInterp(0)
{
      MESSAGE("Constructeur") ;
      _myHomardGen=HOMARD::HOMARD_Gen::_duplicate(myHomardGen);
      setupUi(this);
      setModal(modal);
      InitConnect();

      SetNewHypothesisName();
      if (_aFieldFile != QString("")) {
          RBChamp->setChecked(1);
          SetChamp();
      } else {
          RBUniforme->setChecked(1);
          SetUniforme();
      }
      SetFieldNo();
}

// ------------------------------------------------------------------------
MonCreateHypothesis::~MonCreateHypothesis()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::InitConnect()
// ------------------------------------------------------------------------
{
    connect( RBUniforme,   SIGNAL(clicked()), this, SLOT(SetUniforme()));
    connect( RBChamp,      SIGNAL(clicked()), this, SLOT(SetChamp()));
    connect( RBZone,       SIGNAL(clicked()), this, SLOT(SetZone()));
    connect( RBUniRaff,    SIGNAL(clicked()), this, SLOT(SetUniRaff()));
    connect( RBUniDera,    SIGNAL(clicked()), this, SLOT(SetUniDera()));
    connect( CBFieldName,  SIGNAL(activated(int)), this, SLOT( SetFieldName()));
    connect( RBRPE,        SIGNAL(clicked()), this, SLOT(SetRPE()));
    connect( RBRRel,       SIGNAL(clicked()), this, SLOT(SetRRel()));
    connect( RBRAbs,       SIGNAL(clicked()), this, SLOT(SetRAbs()));
    connect( RBRNo,        SIGNAL(clicked()), this, SLOT(SetRNo()));
    connect( RBCPE,        SIGNAL(clicked()), this, SLOT(SetCPE()));
    connect( RBCRel,       SIGNAL(clicked()), this, SLOT(SetCRel()));
    connect( RBCAbs,       SIGNAL(clicked()), this, SLOT(SetCAbs()));
    connect( RBCNo,        SIGNAL(clicked()), this, SLOT(SetCNo()));
    connect( RBL2,         SIGNAL(clicked()), this, SLOT(SetUCL2()));
    connect( RBInf,        SIGNAL(clicked()), this, SLOT(SetUCInf()));
    connect( PBZoneNew,    SIGNAL(pressed()), this, SLOT(PushZoneNew()));
    connect( PBZoneEdit,   SIGNAL(pressed()), this, SLOT(PushZoneEdit()) );
    connect( PBZoneDelete, SIGNAL(pressed()), this, SLOT(PushZoneDelete()) );
    connect( CBGroupe,     SIGNAL(stateChanged(int)), this, SLOT(SetFiltrage()));
    connect( RBFieldNo,    SIGNAL(clicked()), this, SLOT(SetFieldNo()));
    connect( RBFieldAll,   SIGNAL(clicked()), this, SLOT(SetFieldAll()));
    connect( RBFieldChosen,SIGNAL(clicked()), this, SLOT(SetFieldChosen()));
    connect( buttonOk,     SIGNAL(pressed()), this, SLOT( PushOnOK()));
    connect( buttonApply,  SIGNAL(pressed()), this, SLOT( PushOnApply()));
    connect( buttonCancel, SIGNAL(pressed()), this, SLOT(close()));
    connect( buttonHelp,   SIGNAL(pressed()), this, SLOT( PushOnHelp()));
}

// ------------------------------------------------------------------------
bool MonCreateHypothesis::PushOnApply()
// ------------------------------------------------------------------------
// Appele lorsque l'un des boutons Ok ou Apply est presse
//
{
// Verifications


  if (LEHypothesisName->text().trimmed()=="") {
    QMessageBox::information( 0, "Error",
                              "The hypothesis must be named.",
                              QMessageBox::Ok + QMessageBox::Default );
    return false;
  }

  if (VerifieZone()     == false)  return false;
  if (VerifieComposant() == false)  return false;

// Creation de l'objet CORBA si ce n'est pas deja fait sous le meme nom
  if (LEHypothesisName->text().trimmed() != _aHypothesisName)
  {
    _aHypothesisName=LEHypothesisName->text().trimmed();
    try
    {
     _aHypothesis=_myHomardGen->CreateHypothesis(CORBA::string_dup(_aHypothesisName.toStdString().c_str()) );
     _parent->addHypothese(_aHypothesisName);
    }
    catch( SALOME::SALOME_Exception& S_ex )
    {
      QMessageBox::information( 0, "Error",
                  QString(CORBA::string_dup(S_ex.details.text)),
                  QMessageBox::Ok + QMessageBox::Default );
      return false;
    }
  }

// Mise en place des attributs
  _aHypothesis->SetAdapRefinUnRef(_aTypeAdap,_aTypeRaff,_aTypeDera);
  _aHypothesis->SetTypeFieldInterp(_TypeFieldInterp);
  _aHypothesis->SetCaseCreation(_aCaseName.toStdString().c_str());

  AssocieLesZones();
  AssocieComposants();
  AssocieLesGroupes();
  AssocieFieldInterp();

  HOMARD_UTILS::updateObjBrowser();
  return true;
}


// ------------------------------------------------------------------------
void MonCreateHypothesis::PushOnOK()
// ------------------------------------------------------------------------
{
     if (PushOnApply()) this->close();
     if ( _parent ) { _parent->raise(); _parent->activateWindow(); };
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::PushOnHelp()
// ------------------------------------------------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_hypothese.html"));
}
// -------------------------------------------------
void MonCreateHypothesis::SetNewHypothesisName()
// --------------------------------------------------
{

  HOMARD::listeHypotheses_var  MyHypos = _myHomardGen->GetAllHypotheses();
  int num = 0;// 
  QString aHypothesisName="";
  while (aHypothesisName=="" )
  {
    aHypothesisName.setNum(num+1) ;
    aHypothesisName.insert(0, QString("Hypo_")) ;
    for ( int i=0; i<MyHypos->length(); i++)
    {
      if ( aHypothesisName ==  QString(MyHypos[i]))
      {
          num=num+1;
          aHypothesisName="";
          break;
      }
    }
  }
  LEHypothesisName->setText(aHypothesisName);
}

//
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetUniforme()
// ------------------------------------------------------------------------
{
  GBFieldManagement->setVisible(0);
  if ( _TypeFieldInterp == 0 ) { GBFieldFile->setVisible(0); }
  else                         { GBFieldFile->setVisible(1); }
  GBAreaManagement->setVisible(0);
  GBUniform->setVisible(1);
  adjustSize();
  _aTypeAdap = -1 ;
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetChamp()
// ------------------------------------------------------------------------
{
  if (_aFieldFile == QString(""))
  {
     QMessageBox::information( 0, "Error",
                              QString("Enter FieldFile please "),
                              QMessageBox::Ok + QMessageBox::Default );
     close();
     if ( _parent ) { _parent->raise(); _parent->activateWindow(); };
     return;
  }
  LEFieldFile->setText(_aFieldFile);
  LEFieldFile->setReadOnly(1);
  InitFields();
  GBUniform->setVisible(0);
  GBAreaManagement->setVisible(0);
  GBFieldManagement->setVisible(1);
  GBFieldFile->setVisible(1);

  GBUniform->adjustSize();
  GBAreaManagement->adjustSize();
  GBFieldManagement->adjustSize();
  GBFieldFile->adjustSize();
  adjustSize();

  _aTypeAdap = 1 ;
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetZone()
// ------------------------------------------------------------------------
{
  GetAllZones();
  GBUniform->setVisible(0);
  GBFieldManagement->setVisible(0);
  if ( _TypeFieldInterp == 0 ) { GBFieldFile->setVisible(0); }
  else                         { GBFieldFile->setVisible(1); }
  GBAreaManagement->setVisible(1);
  adjustSize();
  _aTypeRaff = 1 ;
  _aTypeDera = 0 ;
  _aTypeAdap = 0 ;
}

// ------------------------------------------------------------------------
void MonCreateHypothesis::PushZoneNew()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de PushZoneNew")
  MonCreateZone *aDlg = new MonCreateZone(this, TRUE, HOMARD::HOMARD_Gen::_duplicate(_myHomardGen), _aCaseName) ;
  aDlg->show();
}

// ------------------------------------------------------------------------
void MonCreateHypothesis::PushZoneEdit()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de PushZoneEdit")
  int colonne = TWZone->currentColumn();
  QTableWidgetItem * monItem = TWZone->currentItem();
  if (colonne !=1  or monItem == NULL) 
  {
    QMessageBox::information( 0, "Error",
                              "Please, Select a Zone",
                              QMessageBox::Ok + QMessageBox::Default );
    return;
  }
  QString zoneName = monItem->text().trimmed();
  MonEditZone *aDlg = new MonEditZone(this, TRUE, HOMARD::HOMARD_Gen::_duplicate(_myHomardGen), _aCaseName, zoneName) ;
  aDlg->show();
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::PushZoneDelete()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de PushZoneDelete")
  QMessageBox::information( 0, "Error",
                            "Inactive button.",
                            QMessageBox::Ok + QMessageBox::Default );
  return;
}

// ------------------------------------------------------------------------
void MonCreateHypothesis::GetAllZones()
// ------------------------------------------------------------------------
// Recuperation de toutes les zones enregistrees dans l'arbre d'etude
{
  HOMARD::listeZones_var  mesZones = _myHomardGen->GetAllZones();
  TWZone->clear();
  int stop=TWZone->rowCount();
  for ( int row=0; row< stop; row++)
  {
     TWZone->removeRow(row);
  }
  TWZone->setRowCount(0);
  int row=0;
  for (int i=0; i<mesZones->length(); i++)
  {
    TWZone->insertRow(row);
    TWZone->setItem( row, 0, new QTableWidgetItem( QString ("") ) );
    TWZone->item( row, 0 )->setFlags( 0 );
    TWZone->item( row, 0 )->setFlags( Qt::ItemIsUserCheckable|Qt::ItemIsEnabled  );
    TWZone->item( row, 0 )->setCheckState( Qt::Unchecked );
    TWZone->setItem( row, 1, new QTableWidgetItem(QString(mesZones[i])));
    TWZone->item( row, 1 )->setFlags(Qt::ItemIsEnabled |Qt::ItemIsSelectable );
    row=row+1;
  }
  TWZone->resizeColumnsToContents();
  TWZone->resizeRowsToContents();
  TWZone->clearSelection();
}
    
// ------------------------------------------------------------------------
void MonCreateHypothesis::addZone(QString newZone)
// ------------------------------------------------------------------------
{
  int row = TWZone->rowCount() ;
  TWZone->setRowCount( row+1 );
  TWZone->setItem( row, 0, new QTableWidgetItem( 0 ) );
  TWZone->item( row, 0 )->setFlags( Qt::ItemIsEditable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled  );
  TWZone->item( row, 0 )->setCheckState( Qt::Checked );
  TWZone->setItem( row, 1, new QTableWidgetItem( newZone ) );
  TWZone->scrollToItem( TWZone->item( row, 1 ) );
  TWZone->resizeRowsToContents();
  TWZone->resizeColumnToContents(1);
  TWZone->clearSelection();
  TWZone->item( row, 1 )->setFlags( Qt::ItemIsEnabled |Qt::ItemIsSelectable );
}

// ------------------------------------------------------------------------
QStringList MonCreateHypothesis::GetZonesChecked()
// ------------------------------------------------------------------------
// Retourne les zones enregistrees
{
  QStringList ListeZone ;
  for ( int row=0; row< TWZone->rowCount(); row++)
  {
      if ( TWZone->item( row, 0 )->checkState() ==  Qt::Checked )
          ListeZone.insert(0, QString(TWZone->item(row, 1)->text()) ) ;
  }
  return ListeZone ;
}

// ------------------------------------------------------------------------
QStringList MonCreateHypothesis::GetListCompChecked()
// ------------------------------------------------------------------------
// Retourne les composantes retenues
{
  MESSAGE( "Dans GetListCompChecked" );
  QStringList ListeComposant ;

  ListeComposant.clear();
  for ( int row=0; row< TWCMP->rowCount(); row++)
      if ( TWCMP->item( row, 0 )->checkState() ==  Qt::Checked )
          ListeComposant.insert(0, QString(TWCMP->item(row, 1)->text()) ) ;
  // Choix du texte des radio-boutons selon 1 ou plusieurs composantes
  if ( ListeComposant.count() < 2 )
  { RBL2->setText(QString("Absolute value"));
    RBInf->setText(QString("Relative value"));
  }
  else
  { RBL2->setText(QString("L2 norm"));
    RBInf->setText(QString("Infinite Norm"));
  }
  return ListeComposant ;
//
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::AssocieFieldInterp()
// ------------------------------------------------------------------------
{
  if ( _TypeFieldInterp != 2 ) return;
  for ( int row=0; row< TWField->rowCount(); row++)
      if ( TWField->item( row, 0 )->checkState() ==  Qt::Checked )
      { _aHypothesis->AddFieldInterp(TWField->item(row, 1)->text().toStdString().c_str()); }
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetUniRaff()
// ------------------------------------------------------------------------
{
  _aTypeRaff = 1 ;
  _aTypeDera = 0 ;
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetUniDera()
// ------------------------------------------------------------------------
{
  _aTypeRaff = 0 ;
  _aTypeDera = 1 ;
}

// ------------------------------------------------------------------------
void MonCreateHypothesis::InitFields()
// ------------------------------------------------------------------------
{
  CBFieldName->clear();
  std::list<QString> listeChamp = HOMARD_QT_COMMUN::GetListeChamps(QString(_aFieldFile) );
  // Mise en place de la liste dans le menu pour l'indicateur d'erreur
  std:: list<QString>::const_iterator it;
  for ( it=listeChamp.begin() ; it != listeChamp.end(); it++)
  {
       CBFieldName->insertItem(0,QString(*it));
  }
  SetFieldName();
}
// ---------------------------------------
void MonCreateHypothesis::SetFieldName()
// -------------------------------------------
{
  _aFieldName=CBFieldName->currentText();
  if (QString(_aFieldFile) == QString("") or QString(_aFieldName) == QString("") ) { return; }

  for ( int row=0; row < TWCMP->rowCount() ; row++)
  {
     TWCMP->removeRow(row);
  }
  //TWCMP->setRowCount(0);
  //TWCMP->resizeRowsToContents();

  std::list<QString>  maListe =HOMARD_QT_COMMUN::GetListeComposants(_aFieldFile, _aFieldName);
  std::list<QString>::const_iterator it;
  for ( it=maListe.begin() ; it != maListe.end(); it++)
  {
       TWCMP->insertRow(0);
       TWCMP->setItem( 0, 0, new QTableWidgetItem( QString ("") ) );
       TWCMP->item( 0, 0 )->setFlags( 0 );
       TWCMP->item( 0, 0 )->setFlags( Qt::ItemIsUserCheckable|Qt::ItemIsEnabled  );
       TWCMP->item( 0, 0 )->setCheckState( Qt::Checked );
       TWCMP->setItem( 0, 1, new QTableWidgetItem(QString((*it))));
       TWCMP->item( 0, 1 )->setFlags( Qt::ItemIsEnabled |Qt::ItemIsSelectable );
  }
  TWCMP->resizeColumnsToContents();
  TWCMP->resizeRowsToContents();
  TWCMP->clearSelection();
  // Choix du texte des radio-boutons selon 1 ou plusieurs composantes
  if ( TWCMP->rowCount() == 1 )
  { RBL2->setText(QString("Absolute value"));
    RBInf->setText(QString("Relative value"));
  }
  else
  { RBL2->setText(QString("L2 norm"));
    RBInf->setText(QString("Infinite Norm"));
  }
  // Par defaut, on propose la valeur absolue / norme L2
  SetUCL2();
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetRPE()
// ------------------------------------------------------------------------
{
  _aTypeRaff = 1 ;
  _TypeThR = 3 ;
  RBRPE->setChecked(true);
  SpinBox_RPE->setEnabled(true);
  SpinBox_RRel->setEnabled(false);
  SpinBox_RAbs->setEnabled(false);
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetRRel()
// ------------------------------------------------------------------------
{
  _aTypeRaff = 1 ;
  _TypeThR = 2 ;
  RBRRel->setChecked(true);
  SpinBox_RPE->setEnabled(false);
  SpinBox_RRel->setEnabled(true);
  SpinBox_RAbs->setEnabled(false);
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetRAbs()
// ------------------------------------------------------------------------
{
  _aTypeRaff = 1 ;
  _TypeThR = 1 ;
  RBRAbs->setChecked(true);
  SpinBox_RPE->setEnabled(false);
  SpinBox_RRel->setEnabled(false);
  SpinBox_RAbs->setEnabled(true);
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetRNo()
// ------------------------------------------------------------------------
{
  _aTypeRaff = 0 ;
  _TypeThR = 0;
  RBRNo->setChecked(true);
  SpinBox_RPE->setEnabled(false);
  SpinBox_RRel->setEnabled(false);
  SpinBox_RAbs->setEnabled(false);
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetCPE()
// ------------------------------------------------------------------------
{
  _aTypeDera = 1 ;
  _TypeThC = 3 ;
  RBCPE->setChecked(true);
  SpinBox_CPE->setEnabled(true);
  SpinBox_CRel->setEnabled(false);
  SpinBox_CAbs->setEnabled(false);
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetCRel()
// ------------------------------------------------------------------------
{
  _aTypeDera = 1 ;
  _TypeThC = 2 ;
  RBCRel->setChecked(true);
  SpinBox_CPE->setEnabled(false);
  SpinBox_CRel->setEnabled(true);
  SpinBox_CAbs->setEnabled(false);
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetCAbs()
// ------------------------------------------------------------------------
{
  _aTypeDera = 1 ;
  _TypeThC = 1 ;
  RBCAbs->setChecked(true);
  SpinBox_CPE->setEnabled(false);
  SpinBox_CRel->setEnabled(false);
  SpinBox_CAbs->setEnabled(true);
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetCNo()
// ------------------------------------------------------------------------
{
  _aTypeDera = 0 ;
  _TypeThC = 0;
  RBCNo->setChecked(true);
  SpinBox_CPE->setEnabled(false);
  SpinBox_CRel->setEnabled(false);
  SpinBox_CAbs->setEnabled(false);
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetUCL2()
// ------------------------------------------------------------------------
{
  _UsCmpI = 0 ;
  RBL2->setChecked(true);
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetUCInf()
// ------------------------------------------------------------------------
{
  _UsCmpI = 1 ;
  RBInf->setChecked(true);
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetFiltrage()
// ------------------------------------------------------------------------
{
  if (!CBGroupe->isChecked()) return;
  MonCreateListGroup *aDlg = new MonCreateListGroup(this, NULL, TRUE, HOMARD::HOMARD_Gen::_duplicate(_myHomardGen),_aCaseName, _aListeGroupes) ;
  aDlg->show();
}

// ------------------------------------------------------------------------
void MonCreateHypothesis::setGroups(QStringList listGroup)
// ------------------------------------------------------------------------
{
    _aListeGroupes=listGroup;
}
// ------------------------------------------------------------------------
bool MonCreateHypothesis::VerifieZone()
// ------------------------------------------------------------------------
{
  if ( _aTypeAdap != 0 ) return true;
  _aListeZone = GetZonesChecked() ;
  if (_aListeZone.count() == 0)
  {
     QMessageBox::information( 0, "Error",
                              QString("At least, one zone must be given."),
                              QMessageBox::Ok + QMessageBox::Default );
     return false;
  }
  return true;
}
// ------------------------------------------------------------------------
bool MonCreateHypothesis::VerifieComposant()
// ------------------------------------------------------------------------
{
  if ( _aTypeAdap != 1 ) return true;
  _aListeComposant = GetListCompChecked() ;
  if (_aListeComposant.count() == 0)
  {
     QMessageBox::information( 0, "Error",
                              QString("At least, one composant must be given."),
                               QMessageBox::Ok + QMessageBox::Default );
     return false;
  }
  return true;
}

// ------------------------------------------------------------------------
void MonCreateHypothesis::AssocieLesZones()
// ------------------------------------------------------------------------
{
  if ( _aTypeAdap != 0 ) return;
  _aListeZone = GetZonesChecked() ;
  for ( int i=0 ; i< _aListeZone.count() ; i++ )
      { _myHomardGen->AssociateHypoZone(_aListeZone[i].toStdString().c_str(),_aHypothesisName.toStdString().c_str()); }
};
// ------------------------------------------------------------------------
void MonCreateHypothesis::AssocieComposants()
// ------------------------------------------------------------------------
{
  if ( _aTypeAdap != 1 ) return;
  MESSAGE( "Dans AssocieComposants, _TypeThC : " << _TypeThC );
  MESSAGE( "Dans AssocieComposants, _TypeThR : " << _TypeThR );

  _ThreshR = 0;
  if ( _TypeThR == 1 ) { _ThreshR = SpinBox_RAbs->value();}
  if ( _TypeThR == 2 ) { _ThreshR = SpinBox_RRel->value();}
  if ( _TypeThR == 3 ) { _ThreshR = SpinBox_RPE->value(); }

  _ThreshC = 0;
  if ( _TypeThC == 1 ) { _ThreshC = SpinBox_CAbs->value();}
  if ( _TypeThC == 2 ) { _ThreshC = SpinBox_CRel->value();}
  if ( _TypeThC == 3 ) { _ThreshC = SpinBox_CPE->value(); }

  _aFieldName=CBFieldName->currentText();
  _aHypothesis->SetField(CORBA::string_dup(_aFieldName.toStdString().c_str()) ) ;
  _aHypothesis->SetRefinThr( _TypeThR, _ThreshR ) ;
  _aHypothesis->SetUnRefThr( _TypeThC, _ThreshC ) ;
  _aHypothesis->SetUseComp( _UsCmpI ) ;
  _aListeComposant = GetListCompChecked() ;
  for ( int i=0 ; i< _aListeComposant.count() ; i++ )
      { _aHypothesis->AddComp(_aListeComposant[i].toStdString().c_str()); }
};
// ------------------------------------------------------------------------
void MonCreateHypothesis::AssocieLesGroupes()
// ------------------------------------------------------------------------
{
  HOMARD::ListGroupType_var aSeqGroupe = new HOMARD::ListGroupType;
  aSeqGroupe->length(_aListeGroupes.size());
  QStringList::const_iterator it;
  int i=0;
  for (it = _aListeGroupes.constBegin(); it != _aListeGroupes.constEnd(); it++)
     aSeqGroupe[i++]=(*it).toStdString().c_str();
  _aHypothesis->SetGroups(aSeqGroupe);

}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetFieldNo()
// ------------------------------------------------------------------------
// Par defaut, on n'interpole rien
{
  if ( _aTypeAdap == 1 ) { GBFieldFile->setVisible(1); }
  else                   { GBFieldFile->setVisible(0); }
  TWField->setVisible(0);
//
   adjustSize();
  _TypeFieldInterp = 0 ;
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetFieldAll()
// ------------------------------------------------------------------------
// Par defaut, on interpole tout
{
  if (_aFieldFile == QString(""))
  {
     QMessageBox::information( 0, "Error",
                              QString("Enter FieldFile please "),
                              QMessageBox::Ok + QMessageBox::Default );
     close();
     if ( _parent ) { _parent->raise(); _parent->activateWindow(); };
     return;
  }
  LEFieldFile->setText(_aFieldFile);
  LEFieldFile->setReadOnly(1);
  GBFieldFile->setVisible(1);
  TWField->setVisible(0);
//
  _TypeFieldInterp = 1 ;
   adjustSize();
}
// ------------------------------------------------------------------------
void MonCreateHypothesis::SetFieldChosen()
// ------------------------------------------------------------------------
{
  if (_aFieldFile == QString(""))
  {
     QMessageBox::information( 0, "Error",
                              QString("Enter FieldFile please "),
                              QMessageBox::Ok + QMessageBox::Default );
     close();
     if ( _parent ) { _parent->raise(); _parent->activateWindow(); };
     return;
  }
  LEFieldFile->setText(_aFieldFile);
  LEFieldFile->setReadOnly(1);
  GBFieldFile->setVisible(1);
  // Recuperation de la liste des champs contenus dans le fichier _aFieldFile
  std::list<QString> listeChamp = HOMARD_QT_COMMUN::GetListeChamps(QString(_aFieldFile) );

  // Initialisation de la table
  TWField->clear();
  for ( int row=0; row< TWField->rowCount(); row++)
     TWField->removeRow(row);

  TWField->setRowCount(0);
  std:: list<QString>::const_iterator it;
  int row=0;
  for ( it=listeChamp.begin() ; it != listeChamp.end(); it++)
  {
    TWField->insertRow(row);
    TWField->setItem( row, 0, new QTableWidgetItem( QString ("") ) );
    TWField->item( row, 0 )->setFlags( 0 );
    TWField->item( row, 0 )->setFlags( Qt::ItemIsUserCheckable|Qt::ItemIsEnabled  );
    TWField->item( row, 0 )->setCheckState( Qt::Unchecked );
    TWField->setItem( row, 1, new QTableWidgetItem(QString(*it)));
    TWField->item( row, 1 )->setFlags(Qt::ItemIsEnabled |Qt::ItemIsSelectable );
    row=row+1;
  }
  TWField->resizeColumnsToContents();
  TWField->resizeRowsToContents();
  TWField->clearSelection();
  TWField->setVisible(1);

  _TypeFieldInterp = 2 ;
   adjustSize();
}
