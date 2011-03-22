using namespace std;

#include "MonEditZone.h"

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include <utilities.h>


// ------------------------------------------------------------------------
MonEditZone::MonEditZone( MonCreateHypothesis* parent, bool modal,
                          HOMARD::HOMARD_Gen_var myHomardGen,
                          QString caseName, QString zoneName ):
// ------------------------------------------------------------------------
/* Constructs a MonEditZone
    herite de MonCreateZone
*/
    MonCreateZone(parent, myHomardGen, caseName)
{
    MESSAGE("Debut de MonEditZone pour " << zoneName.toStdString().c_str());
    setWindowTitle(QObject::tr("HOM_ZONE_EDIT_WINDOW_TITLE"));
    _aZoneName=zoneName;
    aZone = _myHomardGen->GetZone(_aZoneName.toStdString().c_str());
    InitValEdit();
}
// ------------------------------------------------------------------------
MonEditZone::~MonEditZone()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonEditZone::InitValEdit()
// ------------------------------------------------------------------------
{
    LEZoneName->setText(_aZoneName);
    LEZoneName->setReadOnly(true);
    _ZoneType = aZone->GetZoneType();
    InitValZoneLimit();
    if (_aCaseName != QString("")) InitValZone();
    switch (_ZoneType)
    {
      case 2 : // il s agit d une boite
      {
        InitValZoneBox();
        SetBox();
        break;
      }
      case 4 : // il s agit d une sphere
      {
        InitValZoneSphere();
        SetSphere();
        break;
      }
    };
}
// ------------------------------------------------------------------------
void MonEditZone::InitValZoneLimit()
// ------------------------------------------------------------------------
{
      HOMARD::double_array_var  mesCoordLimits = aZone->GetLimit();
      ASSERT(mesCoordLimits->length() == 3 );
      _Xincr=mesCoordLimits[0];
      _Yincr=mesCoordLimits[1];
      _Zincr=mesCoordLimits[2];

}
// ------------------------------------------------------------------------
void MonEditZone::InitValZoneBox()
// ------------------------------------------------------------------------
{
      HOMARD::double_array_var  mesCoordZones = aZone->GetBox();
      ASSERT(mesCoordZones->length() == 6 );
      _ZoneXmin=mesCoordZones[0]; _ZoneXmax=mesCoordZones[1];
      _ZoneYmin=mesCoordZones[2]; _ZoneYmax=mesCoordZones[3];
      _ZoneZmin=mesCoordZones[4]; _ZoneZmax=mesCoordZones[5];

}
// ------------------------------------------------------------------------
void MonEditZone::InitValZoneSphere()
// ------------------------------------------------------------------------
{
      HOMARD::double_array_var  mesCoordZones = aZone->GetSphere();
      ASSERT(mesCoordZones->length() == 4 );
      _ZoneXcentre=mesCoordZones[0];
      _ZoneYcentre=mesCoordZones[1];
      _ZoneZcentre=mesCoordZones[2];
      _ZoneRayon=mesCoordZones[3];

}
// ------------------------------------------------------------------------
void MonEditZone::SetBox()
// ------------------------------------------------------------------------
{
  gBBox->setVisible(1);
  gBSphere->setVisible(0);
  RBBox->setChecked(1);
  adjustSize();
  _ZoneType=2;
  RBSphere->setDisabled(true);
  adjustSize();

  SpinBox_Xmini->setValue(_ZoneXmin);
  SpinBox_Xmaxi->setValue(_ZoneXmax);

  double incr ;
  if ( _Xincr > 0 ) {incr=_Xincr;} else{incr=1.;}
  SpinBox_Xmini->setSingleStep(incr);
  SpinBox_Xmaxi->setSingleStep(incr);

  SpinBox_Ymini->setValue(_ZoneYmin);
  SpinBox_Ymaxi->setValue(_ZoneYmax);
  if ( _Yincr > 0 ) {incr=_Yincr;} else{incr=1.;}
  SpinBox_Ymini->setSingleStep(incr);
  SpinBox_Ymaxi->setSingleStep(incr);

  SpinBox_Zmini->setValue(_ZoneZmin);
  SpinBox_Zmaxi->setValue(_ZoneZmax);
  if ( _Zincr > 0 ) {incr=_Zincr;} else{incr=1.;}
  SpinBox_Zmini->setSingleStep(incr);
  SpinBox_Zmaxi->setSingleStep(incr);

}
// ------------------------------------------------------------------------
void MonEditZone::SetSphere()
// ------------------------------------------------------------------------
{
  gBBox->setVisible(0);
  gBSphere->setVisible(1);
  RBSphere->setChecked(1);
  RBBox->setDisabled(true);
  adjustSize();
  _ZoneType=4 ;

  SpinBox_Xcentre->setValue(_ZoneXcentre);
  if ( _Xincr > 0) { SpinBox_Xcentre->setSingleStep(_Xincr); }
  else             { SpinBox_Xcentre->setSingleStep(1) ; }

  SpinBox_Ycentre->setValue(_ZoneYcentre);
  if ( _Yincr > 0) { SpinBox_Ycentre->setSingleStep(_Yincr); }
  else             { SpinBox_Ycentre->setSingleStep(1) ; }

  SpinBox_Zcentre->setValue(_ZoneZcentre);
  if ( _Zincr > 0) { SpinBox_Zcentre->setSingleStep(_Zincr); }
  else             { SpinBox_Zcentre->setSingleStep(1);}

  SpinBox_Rayon->setMinimum(0.);
  SpinBox_Rayon->setValue(_ZoneRayon);
}


// ---------------------------------------------------
bool MonEditZone::CreateOrUpdateZone()
//----------------------------------------------------
//  Pas de Creation de la zone
//  Mise a jour des attributs de la Zone

{
  try
  {
    aZone->SetZoneType(_ZoneType);
    aZone->SetBox(_ZoneXmin, _ZoneXmax, _ZoneYmin, _ZoneYmax, _ZoneZmin, _ZoneZmax);
    aZone->SetSphere(_ZoneXcentre, _ZoneYcentre, _ZoneZcentre, _ZoneRayon);
    if (Chgt) _myHomardGen->InvalideZone(_aZoneName.toStdString().c_str());
    HOMARD_UTILS::updateObjBrowser();
  }
  catch( const SALOME::SALOME_Exception& S_ex ) {
       SalomeApp_Tools::QtCatchCorbaException( S_ex );
       return false;
  }
  return true;
}

