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

#include "MonCreateBoundaryAn.h"
#include "MonCreateCase.h"

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
MonCreateBoundaryAn::MonCreateBoundaryAn(MonCreateCase* parent, bool modal,
                             HOMARD::HOMARD_Gen_var myHomardGen,
                             QString caseName) :
// ------------------------------------------------------------------------------------------------------------------------------
/* Constructs a MonCreateBoundaryAn
   appele pour une vraie creation
   initialise un cylindre et non une sphere
*/
    QDialog(0), Ui_CreateBoundaryAn(),
    _parent(parent),
    _aBoundaryAnName (""),
    _aCaseName(caseName),
    _BoundaryType(1),
    _BoundaryAnXcentre(0), _BoundaryAnYcentre(0), _BoundaryAnZcentre(0), _BoundaryAnRayon(0),
    _BoundaryAnXaxis(0), _BoundaryAnYaxis(0), _BoundaryAnZaxis(0),
    _Xcentre(0), _Ycentre(0), _Zcentre(0), _Rayon(0),
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
      QPixmap pix2 = resMgr->loadPixmap( "HOMARD", "cylinderpointvector.png" );
      QIcon IS2=QIcon(pix2);
      RBCylindre->setIcon(IS2);

      InitConnect( );

      SetNewBoundaryAnName() ;
      InitValBoundaryAn();          // Cherche les valeurs de la boite englobante le maillage
      InitMinMax();                 // Initialise les bornes des boutons
      SetCylinder();                // Propose un cylindre en premier choix
    }
// --------------------------------------------------------------------------------------------------------------
MonCreateBoundaryAn::MonCreateBoundaryAn(MonCreateCase* parent,
                             HOMARD::HOMARD_Gen_var myHomardGen,
                             QString caseName):
// --------------------------------------------------------------------------------------------------------------
// Constructeur appele par MonEditBoundaryAn
//
    QDialog(0), Ui_CreateBoundaryAn(),
     _myHomardGen(myHomardGen),
    _parent(parent),
    _aBoundaryAnName (""),
    _aCaseName(caseName),
    _BoundaryType(1),
    _BoundaryAnXcentre(0), _BoundaryAnYcentre(0), _BoundaryAnZcentre(0), _BoundaryAnRayon(0),
    _BoundaryAnXaxis(0), _BoundaryAnYaxis(0), _BoundaryAnZaxis(0),
    // Pour affichage lors de l edition d une BoundaryAn sans nom de Cas
    _Xcentre(0), _Ycentre(0), _Zcentre(0), _Rayon(0),
    _Xmin(1), _Xmax(1), _Xincr(1), _Ymin(1), _Ymax(1), _Yincr(1), _Zmin(1), _Zmax(1), _Zincr(1), _DMax(1),
    Chgt (false)
    {
  //  MESSAGE("Debut de  MonCreateBoundaryAn")
      setupUi(this);
      SUIT_ResourceMgr* resMgr = SUIT_Session::session()->resourceMgr();
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "spherepoint.png" );
      QIcon IS=QIcon(pix);
      RBSphere->setIcon(IS);
      QPixmap pix2 = resMgr->loadPixmap( "HOMARD", "cylinderpointvector.png" );
      QIcon IS2=QIcon(pix2);
      RBCylindre->setIcon(IS2);
      setModal(true);
      InitConnect();
    }

// ------------------------------------------------------------------------
MonCreateBoundaryAn::~MonCreateBoundaryAn()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::InitConnect()
// ------------------------------------------------------------------------
{
    connect( RBCylindre,   SIGNAL(clicked()) , this, SLOT(SetCylinder()) ) ;
    connect( RBSphere,     SIGNAL(clicked()) , this, SLOT(SetSphere()) ) ;
    connect( buttonOk,     SIGNAL( pressed() ), this, SLOT( PushOnOK() ) );
    connect( buttonApply,  SIGNAL( pressed() ), this, SLOT( PushOnApply() ) );
    connect( buttonCancel, SIGNAL( pressed() ), this, SLOT( close() ) );
    connect( buttonHelp,   SIGNAL( pressed() ), this, SLOT( PushOnHelp() ) );
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::InitValBoundaryAn()
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

//  2. Caracteristiques des frontieres
// en X
    _Xcentre=(_Xmin + _Xmax)/2.;
// en Y
    _Ycentre=(_Ymin + _Ymax)/2.;
// en Z
    _Zcentre=(_Zmin + _Zmax)/2.;
// Rayon
    _Rayon= _DMax/4.;
}

// ------------------------------------------------------------------------
void MonCreateBoundaryAn::InitMinMax()
// ------------------------------------------------------------------------
{
// en X
  SpinBox_Xaxis->setSingleStep(0.1);
  SpinBox_Xcentre->setSingleStep(_Xincr);
//en Y
  SpinBox_Yaxis->setSingleStep(0.1);
  SpinBox_Ycentre->setSingleStep(_Yincr);
//en Z
  SpinBox_Zaxis->setSingleStep(0.1);
  SpinBox_Zcentre->setSingleStep(_Zincr);
// Rayon
  SpinBox_Radius->setSingleStep(_Rayon/10.);
  SpinBox_Radius->setMinimum(0.);
  SpinBox_Rayon->setSingleStep(_Rayon/10.);
  SpinBox_Rayon->setMinimum(0.);
}
// ------------------------------------------------------------------------
bool MonCreateBoundaryAn::PushOnApply()
// ------------------------------------------------------------------------
// Appele lorsque l'un des boutons Ok ou Apply est presse
//
{
  std::cerr << LEBoundaryName->text().trimmed().toStdString() << std::endl;
  if (LEBoundaryName->text().trimmed()=="")
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_BOUN_NAME") );
    return false;
  }

  switch (_BoundaryType)
  {
      case 1 : // il s agit d un cylindre
      {
        if ((_BoundaryAnXcentre != SpinBox_Xcent->value())  or
            (_BoundaryAnYcentre != SpinBox_Ycent->value())  or
            (_BoundaryAnZcentre != SpinBox_Zcent->value())  or
            (_BoundaryAnRayon   != SpinBox_Radius->value()) or
            (_BoundaryAnXaxis   != SpinBox_Xaxis->value()) or
            (_BoundaryAnYaxis   != SpinBox_Yaxis->value()) or
            (_BoundaryAnZaxis   != SpinBox_Zaxis->value()) )
        {
          Chgt = true;
          _BoundaryAnXaxis= SpinBox_Xaxis->value();
          _BoundaryAnYaxis= SpinBox_Yaxis->value();
          _BoundaryAnZaxis= SpinBox_Zaxis->value();
          _BoundaryAnXcentre=SpinBox_Xcent->value();
          _BoundaryAnYcentre=SpinBox_Ycent->value();
          _BoundaryAnZcentre=SpinBox_Zcent->value();
          _BoundaryAnRayon=SpinBox_Radius->value();
          double daux = _BoundaryAnXaxis*_BoundaryAnXaxis + _BoundaryAnYaxis*_BoundaryAnYaxis + _BoundaryAnZaxis*_BoundaryAnZaxis ;
          if ( daux < 0.0000001 )
          {
            QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                      QObject::tr("HOM_AXE") );
            return false;
          }
        }
        break;
      }

      case 2 : // il s agit d une sphere
      {
        if ((_BoundaryAnXcentre != SpinBox_Xcentre->value()) or
            (_BoundaryAnYcentre != SpinBox_Ycentre->value()) or
            (_BoundaryAnZcentre != SpinBox_Zcentre->value()) or
            (_BoundaryAnRayon   != SpinBox_Rayon->value())  )
        {
           Chgt = true;
          _BoundaryAnXcentre=SpinBox_Xcentre->value();
          _BoundaryAnYcentre=SpinBox_Ycentre->value();
          _BoundaryAnZcentre=SpinBox_Zcentre->value();
          _BoundaryAnRayon=SpinBox_Rayon->value();
        }
        break;
      }
  }

  bool bOK = CreateOrUpdateBoundaryAn();
  return bOK;

}
// ---------------------------------------------------
bool MonCreateBoundaryAn:: CreateOrUpdateBoundaryAn()
//----------------------------------------------------
//  Creation de l'objet boundary
{
  if (_aBoundaryAnName != LEBoundaryName->text().trimmed())
  {
    _aBoundaryAnName = LEBoundaryName->text().trimmed();
    switch (_BoundaryType)
    {
      case 1 : // il s agit d un cylindre
      {
        aBoundaryAn = _myHomardGen->CreateBoundaryCylinder(CORBA::string_dup(_aBoundaryAnName.toStdString().c_str()), \
        _BoundaryAnXcentre, _BoundaryAnYcentre, _BoundaryAnZcentre, _BoundaryAnXaxis, _BoundaryAnYaxis, _BoundaryAnZaxis, _BoundaryAnRayon );
        break;
      }
      case 2 : // il s agit d une sphere
      {
        aBoundaryAn = _myHomardGen->CreateBoundarySphere(CORBA::string_dup(_aBoundaryAnName.toStdString().c_str()), \
        _BoundaryAnXcentre, _BoundaryAnYcentre, _BoundaryAnZcentre, _BoundaryAnRayon);
        break;
      }
    }
    _parent->addBoundaryAn(_aBoundaryAnName);
  }
// Mise en place des attributs
  aBoundaryAn->SetLimit(_Xincr, _Yincr, _Zincr);

  HOMARD_UTILS::updateObjBrowser();
  return true;
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::PushOnOK()
// ------------------------------------------------------------------------
{
     if (PushOnApply()) this->close();
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::PushOnHelp()
// ------------------------------------------------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_boundary.html#un-cylindre") ) ;
}

// -----------------------------------
void MonCreateBoundaryAn::SetNewBoundaryAnName()
// -----------------------------------
{
// Recherche d'un nom par defaut qui n'existe pas encore

  HOMARD::listeBoundarys_var  MyBoundaryAns = _myHomardGen->GetAllBoundarys();
  int num = 0; QString aBoundaryAnName="";
  while (aBoundaryAnName=="" )
  {
    aBoundaryAnName.setNum(num+1) ;
    aBoundaryAnName.insert(0, QString("Boun_")) ;
    for ( int i=0; i<MyBoundaryAns->length(); i++)
    {
      if ( aBoundaryAnName ==  QString(MyBoundaryAns[i]))
      {
          num=num+1;
          aBoundaryAnName="";
          break;
      }
   }
  }
  LEBoundaryName->clear() ;
  LEBoundaryName->insert(aBoundaryAnName);
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::SetCylinder()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetCylinder")
  gBCylindre->setVisible(1);
  gBSphere->setVisible(0);
  adjustSize();
  _BoundaryType=1;
  SpinBox_Xcent->setValue(_Xcentre);
  SpinBox_Xaxis->setValue(0.);
  SpinBox_Ycent->setValue(_Ycentre);
  SpinBox_Yaxis->setValue(0.);
  SpinBox_Zcent->setValue(_Zcentre);
  SpinBox_Zaxis->setValue(1.);
  SpinBox_Radius->setValue(_Rayon);
//   MESSAGE("Fin de SetCylinder")
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::SetSphere()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetSphere")
  gBCylindre->setVisible(0);
  gBSphere->setVisible(1);
  adjustSize();
  _BoundaryType=2;
  SpinBox_Xcentre->setValue(_Xcentre);
  SpinBox_Ycentre->setValue(_Ycentre);
  SpinBox_Zcentre->setValue(_Zcentre);
  SpinBox_Rayon->setValue(_Rayon);
//   MESSAGE("Fin de SetSphere")
}


