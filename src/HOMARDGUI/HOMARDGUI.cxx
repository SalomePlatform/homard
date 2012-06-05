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

//  File   : HOMARDGUI.cxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD

using namespace std;
#include "HOMARDGUI.h"

// SALOME Includes
#include "Utils_ORB_INIT.hxx"
#include "Utils_SINGLETON.hxx"
#include "SALOME_LifeCycleCORBA.hxx"

#include "SUIT_ResourceMgr.h"
#include "SUIT_MessageBox.h"
#include "SUIT_Session.h"
#include "SUIT_ViewWindow.h"
#include "SUIT_ViewManager.h"
#include <SUIT_Desktop.h>

#include "CAM_Module.h"
#include "OB_Browser.h"

#include "SALOME_ListIO.hxx"
#include "SALOME_ListIteratorOfListIO.hxx"

#include "SalomeApp_Application.h"
#include "SalomeApp_DataModel.h"
#include "SalomeApp_Study.h"
#include "LightApp_SelectionMgr.h"
#include "LightApp_Selection.h"
#include <LightApp_Preferences.h>
#include "SalomeApp_Module.h"
#include "SALOMEconfig.h"
#include <SALOME_LifeCycleCORBA.hxx>

#include <utilities.h>


// QT Includes
#include <QMenu>
#include "MonCreateCase.h"
#include "MonCreateIteration.h"
#include "MonEditFile.h"
#include "MonEditCase.h"
#include "MonEditIteration.h"
#include "MonEditHypothesis.h"
#include "MonEditZone.h"
#include "MonEditBoundaryAn.h"
#include "MonEditBoundaryDi.h"
#include "HomardQtCommun.h"

// BOOST Includes
#include <boost/shared_ptr.hpp>

//Pour le _CAST
#include "SALOMEDS_Study.hxx"
#include "HOMARDGUI_Utils.h"

static CORBA::ORB_var _orb;

//=======================================================================
// function : HOMARDGUI()
// purpose  : Constructor
//=======================================================================
HOMARDGUI::HOMARDGUI(const QString&) :
           SalomeApp_Module( "HOMARD" ), // default name
           LightApp_Module( "HOMARD" )
{
}


//=======================================================================
// function : ~HOMARDGUI()
// purpose  : Destructor
//=======================================================================
HOMARDGUI::~HOMARDGUI()
{
}

//=======================================================================
// function : InitHOMARDGen
// launch HOMARD component and return a handle
//=======================================================================
HOMARD::HOMARD_Gen_var HOMARDGUI::InitHOMARDGen(SalomeApp_Application* app)
{
  Engines::EngineComponent_var comp = app->lcc()->FindOrLoad_Component( "FactoryServer","HOMARD" );
  HOMARD::HOMARD_Gen_var clr = HOMARD::HOMARD_Gen::_narrow(comp);
  ASSERT(!CORBA::is_nil(clr));
  return clr;
}

//=======================================================================
// Module's initialization
void HOMARDGUI::initialize( CAM_Application* app )
//=======================================================================
{
  SalomeApp_Module::initialize( app );
  InitHOMARDGen(dynamic_cast<SalomeApp_Application*>( app ));
  anId = 0;
  createActions();
  createMenus();
}

//================================================
// function : createHOMARDAction
// create an item in status bar and Homard menu
//================================================
void HOMARDGUI::createHOMARDAction( const int id, const QString& po_id, const QString& icon_id, const int key, const bool toggle  )
{
//   MESSAGE("HOMARDGUI::createHOMARDAction");
  QIcon icon;
  QWidget* parent = application()->desktop();
  SUIT_ResourceMgr* resMgr = application()->resourceMgr();
  QPixmap pix;
  if ( icon_id.length() )
     pix = resMgr->loadPixmap( "HOMARD", tr( icon_id .toLatin1().data()) );
  else
     pix = resMgr->loadPixmap( "HOMARD", tr( QString( "ICO_%1" ).arg( po_id ).toLatin1().data()), false );
  if ( !pix.isNull() )
      icon = QIcon( pix );

  QString tooltip    = tr(QString( "HOM_TOP_%1" ).arg( po_id ).toLatin1().data()),
          menu       = tr(QString( "HOM_MEN_%1" ).arg( po_id ).toLatin1().data()),
          status_bar = tr(QString( "HOM_STB_%1" ).arg( po_id ).toLatin1().data());

  createAction( id, tooltip, icon, menu, status_bar, key, parent, toggle, this, SLOT( OnGUIEvent() )  );
}

//================================================
// function : createAction
// constructs Homard menu
// calls createHOMARDAction for each item
//================================================
void HOMARDGUI::createActions(){
//
  createHOMARDAction( 1101, "NEW_CASE",       "cas_calcule.png"  );
  createHOMARDAction( 1102, "NEW_ITERATION",  "iter_next.png"    );
  createHOMARDAction( 1111, "COMPUTE",        "mesh_compute.png" );
  createHOMARDAction( 1120, "EDIT_CASE",      "whatis.png"       );
  createHOMARDAction( 1121, "EDIT_ITERATION", "whatis.png"       );
  createHOMARDAction( 1122, "EDIT_HYPO",      "whatis.png"       );
  createHOMARDAction( 1123, "EDIT_ZONE",      "whatis.png"       );
  createHOMARDAction( 1124, "EDIT_BOUNDARY",  "whatis.png"       );
  createHOMARDAction( 1130, "EDIT_MESS_FILE", "texte.png"        );
//
}

//================================================
// function : createPreferences
// No preferences for Homard
// Just a test
//================================================
void HOMARDGUI::createPreferences(){
   QString toto = tr( "PREF_GROUP_GENERAL" );
   int tabId  = addPreference( tr( "PREF_GROUP_GENERAL" ) );
   int genGroup = addPreference( tr( "PREF_TAB_SETTINGS" ), tabId );
   addPreference( tr( "PREF_TEST" ), genGroup, LightApp_Preferences::Color, "Homard", "shading_color" );
}


//================================================
// function : createMenus
//                Verifier l'avant dernier nombre passe en parametre
//================================================
void HOMARDGUI::createMenus(){
  MESSAGE("HOMARDGUI::createMenus")
  int HOMARD_Id  = createMenu( tr( "HOMARD" ),  -1,  5, 10 );
  createMenu( 1101, HOMARD_Id, -1 ); //Create_Case
  createMenu( 1102, HOMARD_Id, -1 ); //Create_Iteration
  createMenu( 1111, HOMARD_Id, -1 ); //COMPUTE
  createMenu( separator(), HOMARD_Id,-1);
  createMenu( 1120, HOMARD_Id, -1 ); //Edit_Case
  createMenu( 1121, HOMARD_Id, -1 ); //Edit_Iteration
  createMenu( 1122, HOMARD_Id, -1 ); //Edit Hypo
  createMenu( 1123, HOMARD_Id, -1 ); //Edit_Zone
  createMenu( 1124, HOMARD_Id, -1 ); //Edit_Boundary
  createMenu( separator(), HOMARD_Id,-1);
  createMenu( 1130, HOMARD_Id, -1 ); //EditAsciiFile pour le fichier listeStd ou bilan
}

//================================================
void HOMARDGUI::OnGUIEvent()
//================================================
{
  MESSAGE("HOMARDGUI::OnGUIEvent()")
  setOrb();
  const QObject* obj = sender();
  if ( !obj || !obj->inherits( "QAction" ) )
       return;
  int id = actionId((QAction*)obj);
  bool ret;
  if ( id != -1 )
      ret = OnGUIEvent( id );
  MESSAGE("************** End of HOMARDGUI::OnGUIEvent()");
}

//=======================================================================
// Method OnGUIEvent pour Homard
//=======================================================================
bool HOMARDGUI::OnGUIEvent (int theCommandID)
{
  MESSAGE("HOMARDGUI::OnGUIEvent(int)");
  SalomeApp_Application* app = dynamic_cast< SalomeApp_Application* >( application() );
  if ( !app ) return false;

  SalomeApp_Study* stud = dynamic_cast<SalomeApp_Study*> ( app->activeStudy() );
  if ( !stud ) {
    MESSAGE ( "FAILED to cast active study to SalomeApp_Study" );
    return false;
  }

  SUIT_Desktop* parent = application()->desktop();
  HOMARD::HOMARD_Gen_var homardGen = HOMARDGUI::InitHOMARDGen(app);

  if (!CORBA::is_nil(homardGen))
  {
    // Set current study
    SalomeApp_Study* aSAStudy =dynamic_cast<SalomeApp_Study*>(app->activeStudy());
    _PTR(Study) aStudy = aSAStudy->studyDS();
    SALOMEDS::Study_ptr aStudyDS;
    if (aStudy)
      aStudyDS = _CAST(Study,aStudy)->GetStudy();
      homardGen->SetCurrentStudy(aStudyDS);
   }
  getApp()->updateObjectBrowser();

  SCRUTE(theCommandID);
  switch (theCommandID)
  {
    case 1101: // Creation d un Cas
    {
      MESSAGE("etape 1101")
      MESSAGE("command " << theCommandID << " activated");
      MonCreateCase *aDlg = new MonCreateCase( parent, TRUE,
                            HOMARD::HOMARD_Gen::_duplicate(homardGen) ) ;
      aDlg->show();
      break;
    }

    case 1102: // Creation d une Iteration
    {
      MESSAGE("command " << theCommandID << " activated");
      QString IterParentName=HOMARD_QT_COMMUN::SelectionArbreEtude(QString("IterationHomard"), 0);
      MESSAGE("IterParentName " << IterParentName.toStdString().c_str() << " choisi dans arbre");
      MonCreateIteration *IterDlg = new MonCreateIteration( parent, true,
                                     HOMARD::HOMARD_Gen::_duplicate(homardGen), IterParentName ) ;
      IterDlg->show();
      break;
    }

    case 1111: // Compute une Iteration
    {
      MESSAGE("command " << theCommandID << " activated");
      QString monIter=HOMARD_QT_COMMUN::SelectionArbreEtude(QString("IterationHomard"), 1);
      if (monIter == QString("")) break;
      try
      {
        homardGen->Compute(monIter.toStdString().c_str(), 0);
      }
      catch( SALOME::SALOME_Exception& S_ex )
      {
        QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                  QString(CORBA::string_dup(S_ex.details.text)) );
        getApp()->updateObjectBrowser();
        return false;
      }
      break;
    }

    case 1120: // Edition d un cas
    {
      MESSAGE("command " << theCommandID << " activated avec objet " << _ObjectName.toStdString().c_str() );
      _PTR(SObject) obj = chercheMonObjet();
      if ((obj) and (HOMARD_UTILS::isCase(obj)))
      {
          MonEditCase *aDlg = new MonEditCase(parent, true, HOMARD::HOMARD_Gen::_duplicate(homardGen), _ObjectName ) ;
          aDlg->show();
      }
    }

    case 1121: // Edition d une iteration
    {
      MESSAGE("command " << theCommandID << " activated avec objet " << _ObjectName.toStdString().c_str() );
      _PTR(SObject) obj = chercheMonObjet();
      if ((obj) and (HOMARD_UTILS::isIter(obj)))
      {
          MonEditIteration *aDlg = new MonEditIteration(parent, true, HOMARD::HOMARD_Gen::_duplicate(homardGen), QString(""), _ObjectName ) ;
          aDlg->show();
      }
    }

    case 1122: // Edition d une hypothese
    {
      MESSAGE("command " << theCommandID << " activated avec objet " << _ObjectName.toStdString().c_str() );
      _PTR(SObject) obj = chercheMonObjet();
      if ((obj) and (HOMARD_UTILS::isHypo(obj)))
      {
          MonEditHypothesis *aDlg = new MonEditHypothesis(0, true, HOMARD::HOMARD_Gen::_duplicate(homardGen),  _ObjectName, QString(""), QString("")) ;
          aDlg->show();
      }
    }

    case 1123: // Edition d une zone
    {
      MESSAGE("command " << theCommandID << " activated avec objet " << _ObjectName.toStdString().c_str() );
      _PTR(SObject) obj = chercheMonObjet();
      if ((obj) and (HOMARD_UTILS::isZone(obj)))
      {
          MonEditZone *aDlg = new MonEditZone(0, TRUE, HOMARD::HOMARD_Gen::_duplicate(homardGen), QString(""), _ObjectName ) ;
          aDlg->show();
      }
    }

    case 1124: // Edition d une frontiere
    {
      MESSAGE("command " << theCommandID << " activated avec objet " << _ObjectName.toStdString().c_str() );
      _PTR(SObject) obj = chercheMonObjet();
      if ((obj))
      {
          if (HOMARD_UTILS::isBoundaryDi(obj))
          {
              MESSAGE(".. Lancement de MonEditBoundaryDi" );
              MonEditBoundaryDi *aDlg = new MonEditBoundaryDi(0, TRUE, HOMARD::HOMARD_Gen::_duplicate(homardGen), QString(""), _ObjectName ) ;
              aDlg->show();
          }
          if (HOMARD_UTILS::isBoundaryAn(obj))
          {
              MESSAGE(".. Lancement de MonEditBoundaryAn" );
              MonEditBoundaryAn *aDlg = new MonEditBoundaryAn(0, TRUE, HOMARD::HOMARD_Gen::_duplicate(homardGen), QString(""), _ObjectName ) ;
              aDlg->show();
          }
      }
    }

    case 1130: // Edition du fichier mess
    {
      MESSAGE("command " << theCommandID << " activated avec objet " << _ObjectName.toStdString().c_str() );
      _PTR(SObject) obj = chercheMonObjet();
      if ((obj) and ((HOMARD_UTILS::isFileMess(obj) or HOMARD_UTILS::isFileSummary(obj))))
      {
          MonEditFile *aDlg = new MonEditFile( 0, true, HOMARD::HOMARD_Gen::_duplicate(homardGen), _ObjectName ) ;
          aDlg->show();
      }
     }
  }
  getApp()->updateObjectBrowser();
  return true;
}

//=============================================================================
/*!
 *
 */
//=============================================================================

// Module's engine IOR
//=============================================================================
QString HOMARDGUI::engineIOR() const
//=============================================================================
{
  CORBA::String_var anIOR = getApp()->orb()->object_to_string( InitHOMARDGen(getApp()) );
  return QString( anIOR.in() );
}

// Module's activation
//=============================================================================
bool HOMARDGUI::activateModule( SUIT_Study* theStudy )
//=============================================================================
{
  bool bOk = SalomeApp_Module::activateModule( theStudy );

  setMenuShown( true );
  setToolShown( true );

  return bOk;
}

// Module's deactivation
//=============================================================================
bool HOMARDGUI::deactivateModule( SUIT_Study* theStudy )
//=============================================================================
{
  setMenuShown( false );
  setToolShown( false );

  return SalomeApp_Module::deactivateModule( theStudy );
}

// Default windows
//=============================================================================
void HOMARDGUI::windows( QMap<int, int>& theMap ) const
//=============================================================================
{
  theMap.clear();
  theMap.insert( SalomeApp_Application::WT_ObjectBrowser, Qt::LeftDockWidgetArea );
  theMap.insert( SalomeApp_Application::WT_PyConsole,     Qt::BottomDockWidgetArea );
}

//=============================================================================
void HOMARDGUI::setOrb()
//=============================================================================
{
  try
  {
     ORB_INIT &init = *SINGLETON_<ORB_INIT>::Instance();
     ASSERT(SINGLETON_<ORB_INIT>::IsAlreadyExisting());
     _orb = init( 0 , 0 );
  }
  catch (...)
  {
     INFOS("internal error : orb not found");
     _orb = 0;
  }
	    ASSERT(! CORBA::is_nil(_orb));
}
//========================================
_PTR(SObject) HOMARDGUI::chercheMonObjet()
//========================================
{

    SALOMEDSClient_SObject* aSO = NULL;
    _PTR(SObject) obj;
    SALOME_ListIO lst;
    getApp()->selectionMgr()->selectedObjects( lst );
    if (  lst.Extent() == 1 )
    {
	Handle(SALOME_InteractiveObject) io = lst.First();
	SalomeApp_Study* appStudy = dynamic_cast<SalomeApp_Study*>( application()->activeStudy() );
	_PTR(Study) study = appStudy->studyDS();
	_PTR(SObject) obj = study->FindObjectID( io->getEntry() );
	_ObjectName = QString( obj->GetName().c_str() );
        return obj;
     }
     else
         return _PTR(SObject)(aSO);
}
//=============================================================================
void HOMARDGUI::contextMenuPopup( const QString& client, QMenu* menu, QString& title )
//=============================================================================
{
  MESSAGE("Debut de HOMARDGUI::contextMenuPopup");
  _PTR(SObject) obj = chercheMonObjet();
  if ( obj )
  {
    title = QString( obj->GetName().c_str() );
    _ObjectName = title;
    SUIT_ResourceMgr* resMgr = SUIT_Session::session()->resourceMgr();
//
    if ( HOMARD_UTILS::isBoundaryAn(obj) )
    {
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "whatis.png" );
      menu->addAction(QIcon(pix), tr(QString("HOM_MEN_EDIT_BOUNDARY").toLatin1().data()), this,SLOT(EditBoDi()));
    }
    else if ( HOMARD_UTILS::isBoundaryDi(obj) )
    {
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "whatis.png" );
      menu->addAction(QIcon(pix), tr(QString("HOM_MEN_EDIT_BOUNDARY").toLatin1().data()), this,SLOT(EditBoDi()));
    }
    else if ( HOMARD_UTILS::isZone(obj) )
    {
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "whatis.png" );
      menu->addAction(QIcon(pix), tr(QString("HOM_MEN_EDIT_ZONE").toLatin1().data()), this,SLOT(EditZone()));
    }
    else if ( HOMARD_UTILS::isHypo(obj) )
    {
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "whatis.png" );
      menu->addAction(QIcon(pix), tr(QString("HOM_MEN_EDIT_HYPO").toLatin1().data()), this,SLOT(EditHypo()));
    }
    else if ( HOMARD_UTILS::isIter(obj) )
    {
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "iter_next.png" );
      menu->addAction(QIcon(pix), tr(QString("HOM_MEN_NEW_ITERATION").toLatin1().data()), this,SLOT(NextIter()));
      QPixmap pix1 = resMgr->loadPixmap( "HOMARD", "whatis.png" );
      menu->addAction(QIcon(pix1), tr(QString("HOM_MEN_EDIT_ITERATION").toLatin1().data()), this,SLOT(EditIter()));
      QPixmap pix2 = resMgr->loadPixmap( "HOMARD", "mesh_compute.png" );
      menu->addAction(QIcon(pix2), tr(QString("HOM_MEN_COMPUTE").toLatin1().data()), this,SLOT(LanceCalcul()));
    }
    else if ( HOMARD_UTILS::isCase(obj) )
    {
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "whatis.png" );
      menu->addAction(QIcon(pix), tr(QString("HOM_MEN_EDIT_CASE").toLatin1().data()), this,SLOT(EditCase()));
    }
    else if ( HOMARD_UTILS::isFileMess(obj) or HOMARD_UTILS::isFileSummary(obj) )
    {
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "texte.png" );
      menu->addAction(QIcon(pix), tr(QString("HOM_MEN_EDIT_MESS_FILE").toLatin1().data()), this,SLOT(EditAsciiFile()));
    }
  }
}

void HOMARDGUI::NextIter()
{
  this->OnGUIEvent(1102);
}

void HOMARDGUI::LanceCalcul()
{
  this->OnGUIEvent(1111);
}

void HOMARDGUI::EditCase()
{
  this->OnGUIEvent(1120);
}

void HOMARDGUI::EditIter()
{
  this->OnGUIEvent(1121);
}

void HOMARDGUI::EditHypo()
{
  this->OnGUIEvent(1122);
}

void HOMARDGUI::EditZone()
{
  this->OnGUIEvent(1123);
}

void HOMARDGUI::EditBoDi()
{
  this->OnGUIEvent(1124);
}

void HOMARDGUI::EditAsciiFile()
{
  this->OnGUIEvent(1130);
}
//
//=============================================================================
// Export the module
//=============================================================================
extern "C" {
  Standard_EXPORT CAM_Module* createModule()
  {
    return new HOMARDGUI("");
  }
}

