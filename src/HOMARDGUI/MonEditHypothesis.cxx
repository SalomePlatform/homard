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

#include "MonEditHypothesis.h"
#include "MonEditListGroup.h"

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>
// ----------------------------------------------------------------------------
MonEditHypothesis::MonEditHypothesis( MonCreateIteration* parent, bool modal,
                                      HOMARD::HOMARD_Gen_var myHomardGen,
                                      QString aHypothesisName,
                                      QString caseName,  QString aFieldFile ):
// ----------------------------------------------------------------------------
/* Constructs a MonEditHypothesis
    herite de MonCreateHypothesis
*/
    MonCreateHypothesis(parent, modal,myHomardGen, aHypothesisName, caseName, aFieldFile)
{
    MESSAGE("Hypothese " << aHypothesisName.toStdString().c_str());
    setWindowTitle(QObject::tr("HOM_HYPO_EDIT_WINDOW_TITLE"));
    _aHypothesis    = _myHomardGen->GetHypothesis(_aHypothesisName.toStdString().c_str());
    if (caseName == QString("") ){ _aCaseName = _aHypothesis->GetCaseCreation();}
    InitValEdit();
    InitGroupes();
}
// ------------------------------
MonEditHypothesis::~MonEditHypothesis()
// ------------------------------
{
}
// ------------------------------
void MonEditHypothesis::InitGroupes()
// ------------------------------
{
    HOMARD::ListGroupType_var maListe = _aHypothesis->GetGroups();
    for ( int i = 0; i < maListe->length(); i++ )
       _aListeGroupes << QString(maListe[i]);

    if (maListe->length() == 0) { CBGroupe->hide();}
}

// ------------------------------
void MonEditHypothesis::InitValEdit()
// ------------------------------
{
  MESSAGE("Debut de InitValEdit");
  LEHypothesisName->setText(_aHypothesisName);
  LEHypothesisName->setReadOnly(true);
  HOMARD::listeTypes_var ListTypes (_aHypothesis->GetAdapRefinUnRef());
  ASSERT( ListTypes->length()==3) ;
  _aTypeAdap = ListTypes[0];
  _aTypeRaff = ListTypes[1];
  _aTypeDera = ListTypes[2];

  if (_aTypeAdap == -1) InitAdaptUniforme();
  if (_aTypeAdap ==  0) InitAdaptZone();
  if (_aTypeAdap ==  1) InitAdaptChamps();

  RBUniDera->setDisabled(true);
  RBUniRaff->setDisabled(true);

  InitFieldInterp();

  if (_aTypeAdap == 1 or _TypeFieldInterp >= 1 )
  {
    if (_aFieldFile == QString("")) { GBFieldFile->setVisible(0); }
    else
    {
      GBFieldFile->setVisible(1);
      LEFieldFile->setText(_aFieldFile);
      LEFieldFile->setReadOnly(1);
    }
  }
  else
  {
    GBFieldFile->setVisible(0);
  }
// Les options avancees (non modifiables)
  CBAdvanced->setVisible(0) ;
  int NivMax = _aHypothesis->GetNivMax();
  double DiamMin = _aHypothesis->GetDiamMin();
  int AdapInit = _aHypothesis->GetAdapInit();
  int LevelOutput = _aHypothesis->GetLevelOutput();
  if ( NivMax > 0 or DiamMin > 0 or AdapInit != 0 or LevelOutput != 0 )
  { GBAdvancedOptions->setVisible(1);
    if ( NivMax > 0 )
    { spinBoxNivMax->setValue(NivMax);
      spinBoxNivMax->setDisabled(true); }
    else
    { TLMaximalLevel->setVisible(0);
      spinBoxNivMax->setVisible(0); }
    if ( DiamMin > 0 )
    { doubleSpinBoxDiamMin->setValue(DiamMin);
      doubleSpinBoxDiamMin->setDisabled(true); }
    else
    { TLMinimalDiameter->setVisible(0);
      doubleSpinBoxDiamMin->setVisible(0); }
    if ( AdapInit != 0 )
    {
      if ( AdapInit > 0 )
      { RBAIR->setChecked(true); }
      else
      { RBAID->setChecked(true); }
      RBAIN->setEnabled(false);
      RBAIR->setEnabled(false);
      RBAID->setEnabled(false);
    }
    else
    { GBAdapInit->setVisible(0) ;
    }
    if ( LevelOutput != 0 )
    {
      CBLevelOutput->setChecked(true);
      CBLevelOutput->setEnabled(false);
    }
    else
    { CBLevelOutput->setVisible(0) ;
    }
  }
  else
  { GBAdvancedOptions->setVisible(0); }
//
  adjustSize();
}
// ----------------------------------------
void MonEditHypothesis::InitAdaptUniforme()
// ----------------------------------------
// Affichage des informations pour une adaptation uniforme
{
//  Choix des options generales
    GBFieldManagement->setVisible(0);
    GBAreaManagement->setVisible(0);
    GBUniform->setVisible(1);
    adjustSize();
    RBUniforme->setChecked(true);
    RBUniforme->setEnabled(false);
    RBChamp->setEnabled(false);
    RBZone->setEnabled(false);
//
// Raffinement ou deraffinement ?
    if (_aTypeDera == 0)
    {
        ASSERT(_aTypeRaff==1);
        RBUniDera->setChecked(false);
        RBUniRaff->setChecked(true);
    }
    if (_aTypeDera == 1)
    {
        ASSERT(_aTypeRaff==0);
        RBUniDera->setChecked(true);
        RBUniRaff->setChecked(false);
    }
//
}
// -------------------------------------
void MonEditHypothesis::InitAdaptZone()
// -------------------------------------
// Affichage des informations pour une adaptation selon des zones :
{
    MESSAGE ("Debut de InitAdaptZone");
//  Choix des options generales
    GBUniform->setVisible(0);
    GBFieldManagement->setVisible(0);
    GBAreaManagement->setVisible(1);
    adjustSize();
    RBZone->setChecked(true);
    RBChamp->setEnabled(false);
    RBUniforme->setEnabled(false);
    RBZone->setEnabled(false);

//  Recuperation de toutes les zones decrites et notation de celles retenues
    GetAllZones();
    HOMARD::listeZonesHypo_var mesZonesAvant = _aHypothesis->GetZones();
    for (int i=0; i<mesZonesAvant->length(); i++)
    {
    MESSAGE ("i"<<i<<", zone :"<<string(mesZonesAvant[i])<<", type :"<<string(mesZonesAvant[i+1]));
      for ( int j =0 ; j < TWZone->rowCount(); j++)
      {
    MESSAGE (". j"<<j<<", zone :"<<TWZone->item(j,2)->text().toStdString());
        if ( TWZone->item(j,2)->text().toStdString() == string(mesZonesAvant[i]) )
        {
    MESSAGE ("OK avec "<<string(mesZonesAvant[i]));
          if ( string(mesZonesAvant[i+1]) == "1" )
          {
    MESSAGE ("... RAFF");
            TWZone->item( j,0 )->setCheckState( Qt::Checked );
            TWZone->item( j,1 )->setCheckState( Qt::Unchecked ); }
          else
          {
    MESSAGE ("... DERA");
            TWZone->item( j,0 )->setCheckState( Qt::Unchecked );
            TWZone->item( j,1 )->setCheckState( Qt::Checked ); }
          break;
        }
      }
      i += 1 ;
    }
//
//  Inactivation des choix
    for ( int j =0 ; j < TWZone->rowCount(); j++)
    {
      TWZone->item( j, 0 )->setFlags(0);
      TWZone->item( j, 1 )->setFlags(0);
    }
    PBZoneNew->setVisible(0);
//
}
// -------------------------------------
void MonEditHypothesis::InitAdaptChamps()
// -------------------------------------
// Affichage des informations pour une adaptation selon un champ :
// . Nom du champ
// . Composantes
// . Seuils
// . Absolu/relatif
{
    MESSAGE ("Debut de InitAdaptChamps");
//  Choix des options generales
    GBUniform->setVisible(0);
    GBAreaManagement->setVisible(0);
    GBFieldManagement->setVisible(1);
    adjustSize();
    RBChamp->setChecked(true);
    RBUniforme->setEnabled(false);
    RBChamp->setEnabled(false);
    RBZone->setEnabled(false);



    HOMARD::InfosHypo_var  aInfosHypo = _aHypothesis->GetField();
    _aFieldName =  aInfosHypo->FieldName;
    _TypeThR = aInfosHypo->TypeThR;
    _ThreshR = aInfosHypo->ThreshR;
    _TypeThC = aInfosHypo->TypeThC;
    _ThreshC = aInfosHypo->ThreshC;
    _UsField = aInfosHypo->UsField;
    _UsCmpI  = aInfosHypo->UsCmpI;


    CBFieldName->insertItem(0,_aFieldName);
    CBFieldName->setCurrentIndex(0);
    CBFieldName->setEnabled(false);
    //SetFieldName(Qt::Unchecked);

    HOMARD::listeComposantsHypo_var mesComposantsAvant = _aHypothesis->GetListComp();
    TWCMP->clear();
    TWCMP->setRowCount(0);
    TWCMP->resizeRowsToContents();
    for (int i=0; i<mesComposantsAvant->length(); i++)
    {
       TWCMP->insertRow(0);
       TWCMP->setItem( 0, 0, new QTableWidgetItem( QString ("") ) );
       TWCMP->item( 0, 0 )->setFlags( Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
       TWCMP->item( 0, 0 )->setCheckState(Qt::Checked );
       TWCMP->item( 0, 0 )->setFlags( 0 );
       TWCMP->setItem( 0, 1, new QTableWidgetItem(QString(mesComposantsAvant[i]).trimmed()));
       TWCMP->item( 0, 1 )->setFlags( Qt::ItemIsEnabled |Qt::ItemIsSelectable );
    }
    TWCMP->resizeColumnsToContents();
    TWCMP->resizeRowsToContents();
    TWCMP->clearSelection();

  // Les seuils de raffinement
  RBRAbs->setEnabled(false) ;
  RBRRel->setEnabled(false) ;
  RBRPE->setEnabled(false) ;
  RBRNo->setEnabled(false) ;
  if (_aTypeRaff== 0 )
  {
    SetRNo();
    RBRNo->setEnabled(true) ;
  }
  else
  {
    if ( _TypeThR == 1 ) { SpinBox_RAbs->setValue(_ThreshR); SetRAbs(); RBRAbs->setEnabled(true);}
    if ( _TypeThR == 2 ) { SpinBox_RRel->setValue(_ThreshR); SetRRel(); RBRRel->setEnabled(true);}
    if ( _TypeThR == 3 ) { SpinBox_RPE->setValue(_ThreshR);  SetRPE();  RBRPE->setEnabled(true);}
  }

  // Les seuils de deraffinement
  RBCAbs->setEnabled(false) ;
  RBCRel->setEnabled(false) ;
  RBCPE->setEnabled(false) ;
  RBCNo->setEnabled(false) ;
  if (_aTypeDera== 0 )
  {
    SetCNo();
    RBCNo->setEnabled(true) ;
  }
  else
  {
    if ( _TypeThC == 1 ) { SpinBox_CAbs->setValue(_ThreshC); SetCAbs(); RBCAbs->setEnabled(true);}
    if ( _TypeThC == 2 ) { SpinBox_CRel->setValue(_ThreshC); SetCRel(); RBCRel->setEnabled(true);}
    if ( _TypeThC == 3 ) { SpinBox_CPE->setValue(_ThreshC);  SetCPE(); RBCPE->setEnabled(true);}
  }
  // Le choix de la prise en compte des composantes
  if ( TWCMP->rowCount() == 1 )
  { RBL2->setText(QObject::tr("HOM_HYPO_NORM_ABS"));
    RBInf->setText(QObject::tr("HOM_HYPO_NORM_REL"));
  }
  else
  { RBL2->setText(QObject::tr("HOM_HYPO_NORM_L2"));
    RBInf->setText(QObject::tr("HOM_HYPO_NORM_INF"));
  }
  if ( _UsField == 0 ) { CBJump->hide(); }
  else
  {
    CBJump->setChecked(true);
    CBJump->setEnabled(false);
  }
  if ( _UsCmpI == 0 )
  {
    RBL2->setChecked(true);
    RBL2->setEnabled(true);
    RBInf->setEnabled(false) ;
  }
  else
  {
    RBL2->setEnabled(false) ;
    RBInf->setChecked(true);
    RBInf->setEnabled(true);
  }
}
// -------------------------------------
void MonEditHypothesis::InitFieldInterp()
// -------------------------------------
// Affichage des informations pour les interpolations
{
    MESSAGE ("Debut de InitFieldInterp");
//  Choix des options generales
    _TypeFieldInterp = _aHypothesis->GetTypeFieldInterp();
    MESSAGE ("_TypeFieldInterp = " << _TypeFieldInterp);
//
//  Aucune interpolation
    if ( _TypeFieldInterp == 0 )
    {
      RBFieldNo->setChecked(true);
      TWField->setVisible(0);
    }
//  Interpolation de tous les champs
    if ( _TypeFieldInterp == 1 )
    {
      RBFieldAll->setChecked(true);
      TWField->setVisible(0);
    }
//  Interpolation de champs choisis
    if ( _TypeFieldInterp == 2 )
    {
      RBFieldChosen->setChecked(true);
//
      TWField->setVisible(1);
      HOMARD::listFieldInterpHypo_var mesChampsAvant = _aHypothesis->GetListFieldInterp();
      TWField->clear();
      TWField->setRowCount(0);
      TWField->resizeRowsToContents();
      for (int i=0; i<mesChampsAvant->length(); i++)
      {
        TWField->insertRow(0);
        TWField->setItem( 0, 0, new QTableWidgetItem( QString ("") ) );
        TWField->item( 0, 0 )->setFlags( Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        TWField->item( 0, 0 )->setCheckState(Qt::Checked );
        TWField->item( 0, 0 )->setFlags( 0 );
        TWField->setItem( 0, 1, new QTableWidgetItem(QString(mesChampsAvant[i]).trimmed()));
        TWField->item( 0, 1 )->setFlags( Qt::ItemIsEnabled |Qt::ItemIsSelectable );
      }
      TWField->resizeColumnsToContents();
      TWField->resizeRowsToContents();
      TWField->clearSelection();
    }
    RBFieldNo->setEnabled(false) ;
    RBFieldAll->setEnabled(false) ;
    RBFieldChosen->setEnabled(false) ;
}

// -------------------------------------
bool MonEditHypothesis::PushOnApply()
// -------------------------------------
{
// Pour du raffinement selon un champ, les seuils ont-ils change ?
  if ( _aTypeAdap ==  1 )
  {
    if (_aTypeRaff!= 0 )
    {
      if (_TypeThR == 1) { _ThreshR = SpinBox_RAbs->value(); }
      if (_TypeThR == 2) { _ThreshR = SpinBox_RRel->value(); }
      if (_TypeThR == 3) { _ThreshR = SpinBox_RPE->value();  }
      _aHypothesis->SetRefinThr(_TypeThR, _ThreshR) ;
    }
    if (_aTypeDera!= 0 )
    {
      if (_TypeThC == 1) { _ThreshC = SpinBox_CAbs->value() ; }
      if (_TypeThC == 2) { _ThreshC = SpinBox_CRel->value() ; }
      if (_TypeThC == 3) { _ThreshC = SpinBox_CPE->value() ; }
      _aHypothesis->SetUnRefThr(_TypeThC, _ThreshC) ;
    }

    _myHomardGen->InvalideHypo(_aHypothesisName.toStdString().c_str());
    HOMARD_UTILS::updateObjBrowser();
  }
  return true;
};
// ------------------------------------------------------------------------
void MonEditHypothesis::SetFiltrage()
// ------------------------------------------------------------------------
{
  if (CBGroupe->isChecked())
  {
    MonEditListGroup *aDlg = new MonEditListGroup(this, NULL, TRUE, HOMARD::HOMARD_Gen::_duplicate(_myHomardGen),_aCaseName, _aListeGroupes) ;
    aDlg->show();
  }
}

