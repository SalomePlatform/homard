using namespace std;

#include "MonCreateZone.h"
#include "MonCreateHypothesis.h"

#include <QFileDialog>
#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>

#include <SUIT_Desktop.h>
#include <SUIT_MessageBox.h>
#include <SUIT_ResourceMgr.h>
#include <SUIT_Session.h>
#include <SUIT_ViewManager.h>

// ------------------------------------------------------------------------------------------------------------------------
MonCreateZone::MonCreateZone(MonCreateHypothesis* parent, bool modal,
                             HOMARD::HOMARD_Gen_var myHomardGen,
                             QString caseName) :
// ------------------------------------------------------------------------------------------------------------------------------
/* Constructs a MonCreateZone
   appele pour une vraie creation
   initialise une boite et non une sphere
*/
    QDialog(0), Ui_CreateZone(),
    _parent(parent),
    _aZoneName (""),
    _aCaseName(caseName),
    _ZoneType(2),
    _Xcentre(0), _Ycentre(0), _Zcentre(0), _Rayon(0),
    _ZoneXcentre(0), _ZoneYcentre(0), _ZoneZcentre(0), _ZoneRayon(0),
    _ZoneXmin(0), _ZoneXmax(0), _ZoneYmin(0), _ZoneYmax(0), _ZoneZmin(0), _ZoneZmax(0),
    _Xmin(0), _Xmax(0), _Xincr(0), _Ymin(0), _Ymax(0), _Yincr(0), _Zmin(0), _Zmax(0), _Zincr(0), _DMax(0),
    Chgt (false)
    {
      MESSAGE("Constructeur") ;
      _myHomardGen=HOMARD::HOMARD_Gen::_duplicate(myHomardGen);
      setupUi(this);
      setModal(modal);

    //  Gestion des icones
      SUIT_ResourceMgr* resMgr = SUIT_Session::session()->resourceMgr();
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "spherepoint.png" );
      QIcon IS=QIcon(pix);
      RBSphere->setIcon(IS);
      QPixmap pix2 = resMgr->loadPixmap( "HOMARD", "boxdxyz.png" );
      QIcon IS2=QIcon(pix2);
      RBBox->setIcon(IS2);

      InitConnect( );

      SetNewZoneName() ;
      InitValZone();           // Cherche les valeurs de la boite englobante le maillage
      InitMinMax();            // Initialise les bornes des boutons
      SetBox();                // Propose une boite en premier choix
    }
// --------------------------------------------------------------------------------------------------------------
MonCreateZone::MonCreateZone(MonCreateHypothesis* parent,
                             HOMARD::HOMARD_Gen_var myHomardGen,
                             QString caseName):
// --------------------------------------------------------------------------------------------------------------
// Constructeur appele par MonEditZone
//
    QDialog(0), Ui_CreateZone(),
     _myHomardGen(myHomardGen),
    _parent(parent),
    _aZoneName (""),
    _aCaseName(caseName),
    _ZoneType(2),
    _Xcentre(0), _Ycentre(0), _Zcentre(0), _Rayon(0),
    _ZoneXcentre(0), _ZoneYcentre(0), _ZoneZcentre(0), _ZoneRayon(0),
    _ZoneXmin(0), _ZoneXmax(0), _ZoneYmin(0), _ZoneYmax(0), _ZoneZmin(0), _ZoneZmax(0),
    // Pour affichage lors de l edition d une Zone sans nom de Cas
    _Xmin(1), _Xmax(1), _Xincr(1), _Ymin(1), _Ymax(1), _Yincr(1), _Zmin(1), _Zmax(1), _Zincr(1), _DMax(1),
    Chgt (false)
    {
  //  MESSAGE("Debut de  MonCreateZone")
      setupUi(this);
      SUIT_ResourceMgr* resMgr = SUIT_Session::session()->resourceMgr();
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "spherepoint.png" );
      QIcon IS=QIcon(pix);
      RBSphere->setIcon(IS);
      QPixmap pix2 = resMgr->loadPixmap( "HOMARD", "boxdxyz.png" );
      QIcon IS2=QIcon(pix2);
      RBBox->setIcon(IS2);
      setModal(true);
      InitConnect();
    }

// ------------------------------------------------------------------------
MonCreateZone::~MonCreateZone()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonCreateZone::InitConnect()
// ------------------------------------------------------------------------
{
    connect( RBBox,        SIGNAL(clicked()) , this, SLOT(SetBox()) ) ;
    connect( RBSphere,     SIGNAL(clicked()) , this, SLOT(SetSphere()) ) ;
    connect( buttonOk,     SIGNAL( pressed() ), this, SLOT( PushOnOK() ) );
    connect( buttonApply,  SIGNAL( pressed() ), this, SLOT( PushOnApply() ) );
    connect( buttonCancel, SIGNAL( pressed() ), this, SLOT( close() ) );
    connect( buttonHelp,   SIGNAL( pressed() ), this, SLOT( PushOnHelp() ) );
}
// ------------------------------------------------------------------------
void MonCreateZone::InitValZone()
// ------------------------------------------------------------------------
{
//
//  1. Les coordonnees extremes du maillage
//
    if (_aCaseName == QString("")) { return; }

    HOMARD::HOMARD_Cas_var aCas = _myHomardGen->GetCas(_aCaseName.toStdString().c_str());
    HOMARD::extrema_var  MesExtremes = aCas->GetBoundingBox();
    int num = MesExtremes->length() ;
    ASSERT(num == 10);
    _Xmin=MesExtremes[0]; _Xmax=MesExtremes[1]; _Xincr=MesExtremes[2];
    _Ymin=MesExtremes[3]; _Ymax=MesExtremes[4]; _Yincr=MesExtremes[5];
    _Zmin=MesExtremes[6]; _Zmax=MesExtremes[7]; _Zincr=MesExtremes[8];
    _DMax=MesExtremes[9];
     MESSAGE ("_Xmin : " << _Xmin << " _Xmax : " << _Xmax << " _Xincr : " << _Xincr ) ;
     MESSAGE ("_Ymin : " << _Ymin << " _Ymax : " << _Ymax << " _Yincr : " << _Yincr ) ;
     MESSAGE ("_Zmin : " << _Zmin << " _Zmax : " << _Zmax << " _Zincr : " << _Zincr) ;
     MESSAGE ("_DMax : " << _DMax);

//  2. Caracteristiques des zones
// en X
    if ( _Xincr < 0 )
    {
      _ZoneXmin = _Xmin;
      _ZoneXmax = _Xmax;
    }
    else
    {
      _ZoneXmin = _Xmin - _Xincr;
      _ZoneXmax = _Xmax + _Xincr;
    }
    _Xcentre=(_Xmin + _Xmax)/2.;
// en Y
    if ( _Yincr < 0 )
    {
      _ZoneYmin = _Ymin;
      _ZoneYmax = _Ymax;
    }
    else
    {
      _ZoneYmin = _Ymin - _Yincr;
      _ZoneYmax = _Ymax + _Yincr;
    }
    _Ycentre=(_Ymin + _Ymax)/2.;
// en Z
    if ( _Zincr < 0 )
    {
      _ZoneZmin = _Zmin;
      _ZoneZmax = _Zmax;
    }
    else
    {
      _ZoneZmin = _Zmin - _Zincr;
      _ZoneZmax = _Zmax + _Zincr;
    }
    _Zcentre=(_Zmin + _Zmax)/2.;
// Rayon
    _Rayon= _DMax/4.;
}

// ------------------------------------------------------------------------
void MonCreateZone::InitMinMax()
// ------------------------------------------------------------------------
{
// en X
    if ( _Xincr > 0) {
      SpinBox_Xmini->setRange(_ZoneXmin,_ZoneXmax);
      SpinBox_Xmaxi->setRange(_ZoneXmin,_ZoneXmax);
      SpinBox_Xmini->setSingleStep(_Xincr);
      SpinBox_Xmaxi->setSingleStep(_Xincr);
      SpinBox_Xcentre->setSingleStep(_Xincr);
    }
    else {
      SpinBox_Xmini->setValue(_ZoneXmin) ;
      SpinBox_Xmaxi->setValue(_ZoneXmax) ;
      SpinBox_Xmini->setEnabled(false) ;
      SpinBox_Xmaxi->setEnabled(false) ;
      SpinBox_Xcentre->setEnabled(false) ;
    }
// en Y
    if ( _Yincr > 0) {
      SpinBox_Ymini->setRange(_ZoneYmin,_ZoneYmax);
      SpinBox_Ymaxi->setRange(_ZoneYmin,_ZoneYmax);
      SpinBox_Ymini->setSingleStep(_Yincr);
      SpinBox_Ymaxi->setSingleStep(_Yincr);
      SpinBox_Ycentre->setSingleStep(_Yincr);
    }
    else {
      SpinBox_Ymini->setValue(_ZoneYmin) ;
      SpinBox_Ymaxi->setValue(_ZoneYmax) ;
      SpinBox_Ycentre->setValue(_Ycentre);
      SpinBox_Ymini->setEnabled(false) ;
      SpinBox_Ymaxi->setEnabled(false) ;
      SpinBox_Ycentre->setEnabled(false) ;
    }
// en Z
    if ( _Zincr > 0) {
      SpinBox_Zmini->setRange(_ZoneZmin,_ZoneZmax);
      SpinBox_Zmaxi->setRange(_ZoneZmin,_ZoneZmax);
      SpinBox_Zmini->setSingleStep(_Zincr);
      SpinBox_Zmaxi->setSingleStep(_Zincr);
      SpinBox_Zcentre->setSingleStep(_Zincr);
    }
    else {
      SpinBox_Zmini->setValue(_ZoneZmin) ;
      SpinBox_Zmaxi->setValue(_ZoneZmax) ;
      SpinBox_Zmini->setEnabled(false) ;
      SpinBox_Zmaxi->setEnabled(false) ;
      SpinBox_Zcentre->setEnabled(false) ;
    }
// Rayon
    SpinBox_Rayon->setSingleStep(_Rayon/10.);
    SpinBox_Rayon->setMinimum(0.);
}
// ------------------------------------------------------------------------
bool MonCreateZone::PushOnApply()
// ------------------------------------------------------------------------
// Appele lorsque l'un des boutons Ok ou Apply est presse
//
{
  std::cerr << LEZoneName->text().trimmed().toStdString() << std::endl;
  if (LEZoneName->text().trimmed()=="")
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_ZONE_NAME") );
    return false;
  }

  switch (_ZoneType)
  {
    case 2 : // il s agit d une boite
    {
      if ((_ZoneXmin != SpinBox_Xmini->value()) or (_ZoneXmax != SpinBox_Xmaxi->value()) or
          (_ZoneYmin != SpinBox_Ymini->value()) or (_ZoneYmax != SpinBox_Ymaxi->value()) or
          (_ZoneZmin != SpinBox_Zmini->value()) or (_ZoneZmax != SpinBox_Zmaxi->value()) )
          Chgt = true;
      break;
    }

    case 4 : // il s agit d une sphere
    {
      if ((_ZoneXcentre != SpinBox_Xcentre->value()) or (_ZoneYcentre != SpinBox_Ycentre->value())
      or  (_ZoneZcentre != SpinBox_Zcentre->value()) or (_ZoneRayon != SpinBox_Rayon->value()))
          Chgt = true;
          break;
    }
  }

  _ZoneXmin= SpinBox_Xmini->value(); _ZoneXmax= SpinBox_Xmaxi->value();
  _ZoneYmin= SpinBox_Ymini->value(); _ZoneYmax= SpinBox_Ymaxi->value();
  _ZoneZmin= SpinBox_Zmini->value(); _ZoneZmax= SpinBox_Zmaxi->value();

  _ZoneXcentre=SpinBox_Xcentre->value();_ZoneYcentre=SpinBox_Ycentre->value();
  _ZoneZcentre=SpinBox_Zcentre->value();_ZoneRayon=SpinBox_Rayon->value();

  if( _ZoneType == 2 )
  {
    if ((_ZoneXmin>= _ZoneXmax) and (_Xincr > 0)) {
      QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                QObject::tr("HOM_ZONE_LIMIT").arg("X") );
      return false; }

    if  ((_ZoneYmin>= _ZoneYmax) and (_Yincr > 0)) {
      QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                QObject::tr("HOM_ZONE_LIMIT").arg("Y") );
      return false; }

    if ((_ZoneZmin>= _ZoneZmax) and (_Zincr > 0)) {
      QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                QObject::tr("HOM_ZONE_LIMIT").arg("Z") );
      return false; }
  }

  bool bOK = CreateOrUpdateZone();
  return bOK;

}
// ---------------------------------------------------
bool MonCreateZone:: CreateOrUpdateZone()
//----------------------------------------------------
//  Creation de la zone
//  Mise a jour des attributs de la Zone

{
  if (_aZoneName != LEZoneName->text().trimmed())
  {
    try
    {
      _aZoneName = LEZoneName->text().trimmed();
      aZone = _myHomardGen->CreateZone( \
              CORBA::string_dup(_aZoneName.toStdString().c_str()), \
              CORBA::Long(_ZoneType) );
      _parent->addZone(_aZoneName);
    }
    catch( SALOME::SALOME_Exception& S_ex )
    {
      QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                QString(CORBA::string_dup(S_ex.details.text)) );
      return false;
    }
  }
// Mise en place des attributs
  aZone->SetZoneType(_ZoneType);
  aZone->SetBox(_ZoneXmin, _ZoneXmax, _ZoneYmin, _ZoneYmax, _ZoneZmin, _ZoneZmax);
  aZone->SetSphere(_ZoneXcentre, _ZoneYcentre, _ZoneZcentre, _ZoneRayon);
  aZone->SetLimit(_Xincr, _Yincr, _Zincr);

  HOMARD_UTILS::updateObjBrowser();
  return true;
}
// ------------------------------------------------------------------------
void MonCreateZone::PushOnOK()
// ------------------------------------------------------------------------
{
     if (PushOnApply()) this->close();
}
// ------------------------------------------------------------------------
void MonCreateZone::PushOnHelp()
// ------------------------------------------------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_zone.html") ) ;
}

// -----------------------------------
void MonCreateZone::SetNewZoneName()
// -----------------------------------
{
// Recherche d'un nom par defaut qui n'existe pas encore

  HOMARD::listeZones_var  MyZones = _myHomardGen->GetAllZones();
  int num = 0; QString aZoneName="";
  while (aZoneName=="" )
  {
    aZoneName.setNum(num+1) ;
    aZoneName.insert(0, QString("Zone_")) ;
    for ( int i=0; i<MyZones->length(); i++)
    {
      if ( aZoneName ==  QString(MyZones[i]))
      {
          num=num+1;
          aZoneName="";
          break;
      }
   }
  }
  LEZoneName->clear() ;
  LEZoneName->insert(aZoneName);
}
// ------------------------------------------------------------------------
void MonCreateZone::SetBox()
// ------------------------------------------------------------------------
{
  gBBox->setVisible(1);
  gBSphere->setVisible(0);
  adjustSize();
  _ZoneType=2;
// Sachant que l'increment est le 1/100eme de l'ecart (min/max), cela revient
// a initialiser la boite sur une boite 'centrale' comprise entre 2/5 et 3/5
  if ( _Xincr > 0 ) {
      SpinBox_Xmini->setValue(_Xcentre-10*_Xincr);
      SpinBox_Xmaxi->setValue(_Xcentre+10*_Xincr);
   }
  if ( _Yincr > 0 ) {
      SpinBox_Ymini->setValue(_Ycentre-10*_Yincr);
      SpinBox_Ymaxi->setValue(_Ycentre+10*_Yincr);
   }
  if ( _Zincr > 0 ) {
      SpinBox_Zmini->setValue(_Zcentre-10*_Zincr);
      SpinBox_Zmaxi->setValue(_Zcentre+10*_Zincr);
   }
}
// ------------------------------------------------------------------------
void MonCreateZone::SetSphere()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetSphere")
  gBBox->setVisible(0);
  gBSphere->setVisible(1);
  adjustSize();
  _ZoneType=4;
  if ( _Xincr > 0 ) {
     SpinBox_Xcentre->setValue(_Xcentre);
   }
  if ( _Yincr > 0 ) {
     SpinBox_Ycentre->setValue(_Ycentre);
   }
  if ( _Zincr > 0 ) {
     SpinBox_Zcentre->setValue(_Zcentre);
   }
   SpinBox_Rayon->setValue(_Rayon);
}


