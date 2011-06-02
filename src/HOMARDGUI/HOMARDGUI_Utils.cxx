// Copyright (C) 2011  CEA/DEN, EDF R&D
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


#include "HOMARDGUI_Utils.h"

#include "OB_Browser.h"

#include "SUIT_Desktop.h"
#include "SUIT_Application.h"
#include "SUIT_Session.h"

#include "LightApp_SelectionMgr.h"
#include "SalomeApp_Application.h"
#include "SalomeApp_Module.h"
#include "SalomeApp_Study.h"

#include "SALOME_ListIO.hxx"
#include "SALOME_ListIteratorOfListIO.hxx"

#include "SALOMEconfig.h"
#include "utilities.h"
#include <string>
#include <HOMARDGUI.h>


#include <qstring.h>
#include <qstringlist.h>
#include <sys/stat.h>
#include <dirent.h>

SALOME_ListIO HOMARD_UTILS::mySelected;

//================================================================
// Function : GetCStudy
// Returne un pointeur sur l'etude courante
//================================================================
 _PTR(Study) HOMARD_UTILS::GetCStudy(const SalomeApp_Study* theStudy)
{
    return theStudy->studyDS();
}
    
    
//================================================================
// Function : GetActiveStudy
// Returne un pointeur sur l'etude active
//================================================================
SUIT_Study* HOMARD_UTILS::GetActiveStudy()
{
    SUIT_Application* app = SUIT_Session::session()->activeApplication();
    if (app)
      return app->activeStudy();
    else
      return NULL;
}
    
//================================================================
// Function : GetActiveStudyDocument
// Returne un pointeur sur l'etude active
//================================================================
_PTR(Study) HOMARD_UTILS::GetActiveStudyDocument()
{
    SalomeApp_Study* aStudy = dynamic_cast<SalomeApp_Study*>(GetActiveStudy());
    if (aStudy){
      return aStudy->studyDS();
    }
    else
      return _PTR(Study)();
}
    
//================================================================
// Function : updateObjBrowser
// Purpose  : met a jour l arbre d 'etude pour Homard
//================================================================
void HOMARD_UTILS::updateObjBrowser()
{
    SalomeApp_Application* app = dynamic_cast<SalomeApp_Application*>(SUIT_Session::session()->activeApplication());
    if (app) {
      //  Le nom identifiant doit etre la valeur du parametre
      // name de la section HOMARD du fichier SalomeApp.xml 
      CAM_Module* module = app->module("Homard" );
      SalomeApp_Module* appMod = dynamic_cast<SalomeApp_Module*>( module );
      if ( appMod ) {
        app->updateObjectBrowser();
        appMod->updateObjBrowser( true );
      }
      else 
        MESSAGE( "---   HOMARD::updateObjBrowser: appMod = NULL");
    }
}

//================================================================
// Function : selectedIO
// Return the list of selected SALOME_InteractiveObject's
//================================================================
const SALOME_ListIO& HOMARD_UTILS::selectedIO()
{
      SalomeApp_Application* app = dynamic_cast< SalomeApp_Application* > ( SUIT_Session::session()->activeApplication() );
      LightApp_SelectionMgr* aSelectionMgr = app->selectionMgr();
      if( aSelectionMgr )
      {
	      aSelectionMgr->selectedObjects( mySelected );
              for (SALOME_ListIteratorOfListIO it (mySelected); it.More(); it.Next()) 
		 SCRUTE(it.Value()->getEntry());
      };
      return mySelected;
	       
}
    
//================================================================
// Function : IObjectCount
// Return the number of selected objects
//================================================================
int HOMARD_UTILS::IObjectCount()
{
      SalomeApp_Application* app = dynamic_cast< SalomeApp_Application* >( SUIT_Session::session()->activeApplication() );
      LightApp_SelectionMgr* aSelectionMgr = app->selectionMgr();
      if( aSelectionMgr )
      {
	      aSelectionMgr->selectedObjects( mySelected );
	      SCRUTE(mySelected.Extent());
              return mySelected.Extent();
      }
      return 0;
}
    
//================================================================
// Function : firstIObject
// Purpose  :  Return the first selected object in the selected object list
//================================================================
Handle(SALOME_InteractiveObject) HOMARD_UTILS::firstIObject()
{
      const SALOME_ListIO& aList = selectedIO();
      return aList.Extent() > 0 ? aList.First() : Handle(SALOME_InteractiveObject)();
}

//================================================================
// Function : lastIObject
// Return the last selected object in the selected object list
//================================================================
Handle(SALOME_InteractiveObject) HOMARD_UTILS::lastIObject()
{
      const SALOME_ListIO& aList = selectedIO();
      return aList.Extent() > 0 ? aList.Last() : Handle(SALOME_InteractiveObject)();
}

//================================================================
// Function : isXmgrace
// Retourne vrai si le fichier associe est de type ASCII
//================================================================
bool HOMARD_UTILS::isXmgrace(_PTR(SObject) MonObj)
{
   _PTR(GenericAttribute) anAttr;
   if (!MonObj->FindAttribute(anAttr, "AttributeComment")) return false;
   _PTR(AttributeComment) aFileComment (anAttr);
   std::string Type = aFileComment->Value();
   if (QString(Type.c_str()) == QString("HomardOuputQual")) return true;
   return false;
}
//================================================================
// Retourne vrai si l objet est du type voulu
// . Dans le cas d'un cas, d'une hypothese, d'une zone, on se contente
// d'une comparaison simple entre le type stocke et TypeObject.
// . Pour l'iteration, le type stocke en attribut est sous la forme
// "IterationHomard" + le nom de l'iteration precedente.
// Il faut donc regarder si la chaine commence par TypeObject.
// . Idem pour le fichier de messages : "Mess " + numero d'iteration
//
// On filtre ce genre de situation avec option :
//  -1 : comparaison totale
//   0 : comparaison sur le debut de la chaine
//================================================================
bool HOMARD_UTILS::isObject(_PTR(SObject) MonObj, QString TypeObject, int option)
{
//   MESSAGE("isObject, TypeObject = "<<TypeObject.toStdString().c_str()<<", option = "<<option);
// Existence d'un attribut ?
  _PTR(GenericAttribute) anAttr;
  if ( !MonObj->FindAttribute(anAttr, "AttributeComment") ) return false;
// Quel type ?
  _PTR(AttributeComment) aComment (anAttr);
  QString Type = QString(aComment->Value().c_str());
//   MESSAGE("Type = "<<Type.toStdString().c_str());
// Est-ce le bon ?
  bool bOK = false ;
  if ( option == 0 )
  {
    int position = Type.lastIndexOf(TypeObject);
    if ( position == 0 ) { bOK = true ; }
  }
  else
  {
    if ( Type == TypeObject ) { bOK = true ; }
  }
  return bOK ;
}
//================================================================
// Retourne vrai si l objet est une frontiere analytique
//================================================================
bool HOMARD_UTILS::isBoundaryAn(_PTR(SObject) MonObj)
{
   return isObject( MonObj, QString("BoundaryAnHomard"), -1 ) ;
}
//================================================================
// Retourne vrai si l objet est une frontiere discrete
//================================================================
bool HOMARD_UTILS::isBoundaryDi(_PTR(SObject) MonObj)
{
   return isObject( MonObj, QString("BoundaryDiHomard"), -1 ) ;
}
//================================================================
// Retourne vrai si l objet est une zone
//================================================================
bool HOMARD_UTILS::isZone(_PTR(SObject) MonObj)
{
   return isObject( MonObj, QString("ZoneHomard"), -1 ) ;
}
//================================================================
// Retourne vrai si l objet est une Hypothese
//================================================================
bool HOMARD_UTILS::isHypo(_PTR(SObject) MonObj)
{
   return isObject( MonObj, QString("HypoHomard"), -1 ) ;
}
//================================================================
// Retourne vrai si l objet est une iteration
//================================================================
bool HOMARD_UTILS::isIter(_PTR(SObject) MonObj)
{
   return isObject( MonObj, QString("IterationHomard"), 0 ) ;
}
//================================================================
// Retourne vrai si l objet est un cas
//================================================================
bool HOMARD_UTILS::isCase(_PTR(SObject) MonObj)
{
   return isObject( MonObj, QString("CasHomard"), -1 ) ;
}
//================================================================
// Retourne vrai si l objet est un fichier de messages
//================================================================
bool HOMARD_UTILS::isFileMess(_PTR(SObject) MonObj)
{
   return isObject( MonObj, QString("Mess"), 0 ) ;
}
//================================================================
// Retourne vrai si l objet est un fichier de bilan
//================================================================
bool HOMARD_UTILS::isFileSummary(_PTR(SObject) MonObj)
{
   return isObject( MonObj, QString("Summary"), 0 ) ;
}
//================================================================
// Function : ChercheFileDansSelection
// Retourne Le nom du fichier associe
//================================================================
QString HOMARD_UTILS::ChercheFileDansSelection()
{
   MESSAGE("ChercheFileDansSelection");
   int nbSel = HOMARD_UTILS::IObjectCount() ;
   if (nbSel > 1 or nbSel == 0) return QString::null;

   Handle(SALOME_InteractiveObject) aIO = HOMARD_UTILS::firstIObject();
   ASSERT(aIO);
   if (!( aIO->hasEntry())) return QString::null; 

   _PTR(Study) myStudy = HOMARD_UTILS::GetActiveStudyDocument();
   _PTR(SObject) aSObj ( myStudy->FindObjectID( aIO->getEntry() ) );
   if (!aSObj) return QString::null;

   _PTR(GenericAttribute) anAttr;
   if (!aSObj->FindAttribute(anAttr, "AttributeExternalFileDef")) return QString::null;
   _PTR(AttributeExternalFileDef) aFileName (anAttr);
   std::string aFile = aFileName->Value();
   SCRUTE(aFile);
   return QString(aFile.c_str());
}

//============================================================
// Function ChercheDansDir
// Cherche tous les fichiers dans la directory qui correspondent 
// a la fois a la base et au numero d iteration, numero d iteration +1
// exple info.00.bilan
// ou qual.tetr.00.dat
//================================================================================
QStringList HOMARD_UTILS::ChercheDansDir(QString direct, QString base, int numIter)
//================================================================================
{
    QStringList liste;


    QString strNum = QString("");
    if (numIter != -1) strNum = HOMARD_UTILS::Transforme(numIter);
    QString strNum1 = QString("");
    if (numIter != -1) strNum1 = HOMARD_UTILS::Transforme(numIter+1);

    struct dirent **namelist;
    int n = scandir(direct.toLatin1(), &namelist, 0, alphasort);
    while(n--) 
    {
       QString fich =QString( namelist[n]->d_name);
       if (fich.contains(base) > 0) 
       {
	 if (numIter != -1)
	 {
	   if ((fich.contains(strNum)>0) or (fich.contains(strNum1)>0))
	      liste.append(fich);
         }
	 else
	 {
	   liste.append(fich);
         }
       }
    }
    return liste;
}

QString HOMARD_UTILS::Transforme(int num)
{
    std::ostringstream nb ;
    nb << std::setw(2) << std::setfill('0') << num ;
    QString retour= QString(nb.str().c_str());
    return retour;

}

//=============================================================================
void HOMARD_UTILS::AddNewRoot(int Tag, QString Racine)
//=============================================================================
{
     _PTR(Study) myStudy = HOMARD_UTILS::GetActiveStudyDocument();
     ASSERT(myStudy);
     _PTR(StudyBuilder) myBuilder( myStudy->NewBuilder() );
     ASSERT(myBuilder);
     _PTR(SComponent)  aFather=myStudy->FindComponent("HOMARD");
     ASSERT(aFather);
    
     _PTR(SObject) InfoRoot = myBuilder->NewObjectToTag (aFather, Tag);
     _PTR(GenericAttribute) anAttr;
    anAttr = myBuilder->FindOrCreateAttribute(InfoRoot, "AttributeName");
    _PTR(AttributeName) aName (anAttr);
    aName->SetValue(Racine.toStdString());
}
//=============================================================================
void HOMARD_UTILS::RangeSousTag(int Tag,QString FileName, int TagFichier, QString Comment,QString FileDir)
//=============================================================================
{
    _PTR(SObject) Root;
     _PTR(Study) myStudy = HOMARD_UTILS::GetActiveStudyDocument();
     ASSERT(myStudy);
     _PTR(StudyBuilder) myBuilder( myStudy->NewBuilder() );
     ASSERT(myBuilder);
     _PTR(SComponent)  aFather=myStudy->FindComponent("HOMARD");
     ASSERT(aFather);
     bool found = aFather->FindSubObject(Tag,Root);
     ASSERT(found);

     _PTR(SObject) MonInfo = myBuilder->NewObjectToTag (Root, TagFichier);
     ASSERT(MonInfo);
     _PTR(GenericAttribute) anAttr;
     anAttr = myBuilder->FindOrCreateAttribute(MonInfo, "AttributeName");
    _PTR(AttributeName) aName (anAttr);
     aName->SetValue(FileName.toStdString());
     QString FileComplet = FileDir +QString("/") +FileName;
     anAttr = myBuilder->FindOrCreateAttribute(MonInfo, "AttributeExternalFileDef");
    _PTR(AttributeExternalFileDef) aFile (anAttr);
     aFile->SetValue((FileComplet).toStdString());
     anAttr = myBuilder->FindOrCreateAttribute(MonInfo, "AttributeComment");
    _PTR(AttributeComment) aComment (anAttr);
     aComment->SetValue(Comment.toStdString());
}

//=========================================================================================================
void HOMARD_UTILS::PushOnHelp(QString monFichierAide)
{
     LightApp_Application* app = (LightApp_Application*)(SUIT_Session::session()->activeApplication());
     if (app) {
        HOMARDGUI* aHomardGUI = dynamic_cast<HOMARDGUI*>( app->module( "Homard" ) );
        app->onHelpContextModule(aHomardGUI ? app->moduleName(aHomardGUI->moduleName()) : QString(""), monFichierAide);
     }

}
//=========================================================================================================
