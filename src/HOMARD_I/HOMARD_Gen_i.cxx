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

#include "HOMARD_Gen_i.hxx"
#include "HOMARD_Cas_i.hxx"
#include "HOMARD_Hypothesis_i.hxx"
#include "HOMARD_Iteration_i.hxx"
#include "HOMARD_Boundary_i.hxx"
#include "HOMARD_Zone_i.hxx"
#include "HomardDriver.hxx"
#include "HOMARD_DriverTools.hxx"
#include "HomardMedCommun.h"

#include "utilities.h"
#include "Utils_SINGLETON.hxx"
#include "Utils_CorbaException.hxx"
#include "SALOMEDS_Tool.hxx"
#include "SALOME_LifeCycleCORBA.hxx"
#include "SALOMEconfig.h"
#include CORBA_CLIENT_HEADER(SALOME_ModuleCatalog)
#include CORBA_CLIENT_HEADER(SMESH_Gen)

#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sys/stat.h>
#include <set>
#include <vector>
#include <stdio.h>


using  namespace std;

//=======================================================================
//function : RemoveTabulation
//purpose  :
//=======================================================================
std::string RemoveTabulation( std::string theScript )
{
  std::string::size_type aPos = 0;
  while( aPos < theScript.length() )
  {
    aPos = theScript.find( "\n\t", aPos );
    if( aPos == std::string::npos )
      break;
    theScript.replace( aPos, 2, "\n" );
    aPos++;
  }
  return theScript;
}

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Gen_i::HOMARD_Gen_i( CORBA::ORB_ptr orb,
                            PortableServer::POA_ptr poa,
                            PortableServer::ObjectId * contId,
                            const char *instanceName,
                            const char *interfaceName) :
Engines_Component_i(orb, poa, contId, instanceName, interfaceName)
{
  MESSAGE("constructor");
  _thisObj = this;
  _id = _poa->activate_object(_thisObj);

  myHomard = new ::HOMARD_Gen();
  _NS = SINGLETON_<SALOME_NamingService>::Instance();
  ASSERT(SINGLETON_<SALOME_NamingService>::IsAlreadyExisting());
  _NS->init_orb(_orb);
}

//=================================
/*!
 *  standard destructor
 */
//================================
HOMARD_Gen_i::~HOMARD_Gen_i()
{
}
//=============================================================================
/*!
 *  Ajoute le composant homard dans l etude si necessaire
 */
//=============================================================================
void HOMARD_Gen_i::addInStudy(SALOMEDS::Study_ptr theStudy)
{
  ASSERT(!CORBA::is_nil(theStudy));
  MESSAGE("addInStudy: ajout eventuel du composant HOMARD dans current study ID = " << GetCurrentStudyID()) ;
  SALOMEDS::StudyBuilder_var myBuilder = theStudy->NewBuilder();

  // Create SComponent labelled 'homard' if it doesn't already exit
  SALOMEDS::SComponent_var homardFather = theStudy->FindComponent(ComponentDataType());
  if (CORBA::is_nil(homardFather))
  {
    myBuilder->NewCommand();
    MESSAGE("Add Component HOMARD");

    bool aLocked = theStudy->GetProperties()->IsLocked();
    if (aLocked) theStudy->GetProperties()->SetLocked(false);

    homardFather = myBuilder->NewComponent(ComponentDataType());
    SALOMEDS::GenericAttribute_var anAttr = myBuilder->FindOrCreateAttribute(homardFather,"AttributeName");
    SALOMEDS::AttributeName_var aName = SALOMEDS::AttributeName::_narrow(anAttr);
    CORBA::Object_var objVarN = _NS->Resolve("/Kernel/ModulCatalog");
    SALOME_ModuleCatalog::ModuleCatalog_var Catalogue =
                SALOME_ModuleCatalog::ModuleCatalog::_narrow(objVarN);
    SALOME_ModuleCatalog::Acomponent_var Comp = Catalogue->GetComponent(ComponentDataType());
    if (!Comp->_is_nil())
    {
      aName->SetValue(ComponentDataType());
    }

    anAttr = myBuilder->FindOrCreateAttribute(homardFather,"AttributePixMap");
    SALOMEDS::AttributePixMap_var aPixmap = SALOMEDS::AttributePixMap::_narrow(anAttr);
    aPixmap->SetPixMap("HOMARD_2.png");
    myBuilder->DefineComponentInstance(homardFather, HOMARD_Gen::_this());

    if (aLocked) theStudy->GetProperties()->SetLocked(true);
    myBuilder->CommitCommand();
  }
}

//=============================================================================
/*!
 *
 *  Set current study
 */
//=============================================================================
void HOMARD_Gen_i::SetCurrentStudy(SALOMEDS::Study_ptr theStudy)
{
  MESSAGE("SetCurrentStudy: current study Id = " << GetCurrentStudyID());
  myCurrentStudy = SALOMEDS::Study::_duplicate(theStudy);
  this->addInStudy(myCurrentStudy);
}

//=============================================================================
SALOMEDS::Study_ptr HOMARD_Gen_i::GetCurrentStudy()
//=============================================================================
{
  MESSAGE("GetCurrentStudy: study Id = " << GetCurrentStudyID());
  return SALOMEDS::Study::_duplicate(myCurrentStudy);
}

//=============================================================================
CORBA::Long HOMARD_Gen_i::GetCurrentStudyID()
//=============================================================================
{
  return myCurrentStudy->_is_nil() ? -1 : myCurrentStudy->StudyId();
}

//=============================================================================
void HOMARD_Gen_i::AssociateCaseIter(const char* nomCas, const char* nomIter, const char* labelIter)
{
  MESSAGE( "AssociateCaseIter : " << nomCas << " ," << nomIter << ","  << labelIter );
  IsValidStudy () ;

  HOMARD::HOMARD_Cas_var myCase = myContextMap[GetCurrentStudyID()]._mesCas[nomCas];
  if (CORBA::is_nil(myCase))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Case ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

  HOMARD::HOMARD_Iteration_var myIteration = myContextMap[GetCurrentStudyID()]._mesIterations[nomIter];
  if (CORBA::is_nil(myIteration))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Case ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

  SALOMEDS::StudyBuilder_var aStudyBuilder = myCurrentStudy->NewBuilder();
  SALOMEDS::SObject_var aCasSO = SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(myCase)));
  if (CORBA::is_nil(aCasSO))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Case ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

  aStudyBuilder->NewCommand();
  SALOMEDS::SObject_var newStudyIter = aStudyBuilder->NewObject(aCasSO);
  PublishInStudyAttr(aStudyBuilder, newStudyIter, nomIter , labelIter,
                     "iter_non_calculee.png", _orb->object_to_string(myIteration)) ;
  aStudyBuilder->CommitCommand();

  myCase->AddIteration(nomIter);
  myIteration->SetCaseName(nomCas);
}

//=====================================================================================
void HOMARD_Gen_i::SetEtatIter(const char* nomIter, const CORBA::Boolean EtatCalcul)
//=====================================================================================
{
  MESSAGE( "SetEtatIter : nomIter  = " << nomIter << " etat " << EtatCalcul );
  HOMARD::HOMARD_Iteration_var myIteration = myContextMap[GetCurrentStudyID()]._mesIterations[nomIter];
  if (CORBA::is_nil(myIteration))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Iteration ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

  myIteration->SetEtat(EtatCalcul);

  SALOMEDS::StudyBuilder_var aStudyBuilder = myCurrentStudy->NewBuilder();
  SALOMEDS::SObject_var aIterSO = SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(myIteration)));
  if (CORBA::is_nil(myIteration))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Iteration ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

  int number = myIteration->GetNumber() ;
  const char* icone ;
  if ( number == 0 )
    icone = "iter0.png" ;
  else if (EtatCalcul)
    icone = "iter_calculee.png" ;
  else
    icone = "iter_non_calculee.png" ;
  PublishInStudyAttr(aStudyBuilder, aIterSO, NULL , NULL, icone, NULL) ;

  aStudyBuilder->CommitCommand();

}
//=====================================================================================
void HOMARD_Gen_i::InvalideBoundary(const char* BoundaryName)
//=====================================================================================
{
  MESSAGE( "InvalideBoundary : BoundaryName    = " << BoundaryName  );
  HOMARD::HOMARD_Boundary_var myBoundary = myContextMap[GetCurrentStudyID()]._mesBoundarys[BoundaryName];
  if (CORBA::is_nil(myBoundary))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Boundary ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };
  SALOME::ExceptionStruct es;
  es.type = SALOME::BAD_PARAM;
  es.text = "No change is allowed in boundary. Ask for evolution.";
  throw SALOME::SALOME_Exception(es);
  return ;
/*  HOMARD::listeHypo* maListe = myBoundary->GetHypo();
  int numberOfHypo = maListe->length();
  for (int NumeHypo = 0; NumeHypo< numberOfHypo; NumeHypo++)
  {
      std::string nomHypo = std::string((*maListe)[NumeHypo]);
      InvalideHypo(nomHypo.c_str());
  }*/
}
//=====================================================================================
void HOMARD_Gen_i::InvalideZone(const char* ZoneName)
//=====================================================================================
{
  MESSAGE( "InvalideZone : ZoneName    = " << ZoneName  );
  HOMARD::HOMARD_Zone_var myZone = myContextMap[GetCurrentStudyID()]._mesZones[ZoneName];
  if (CORBA::is_nil(myZone))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Zone ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };
  HOMARD::listeHypo* maListe = myZone->GetHypo();
  int numberOfHypo = maListe->length();
  for (int NumeHypo = 0; NumeHypo< numberOfHypo; NumeHypo++)
  {
      std::string nomHypo = std::string((*maListe)[NumeHypo]);
      InvalideHypo(nomHypo.c_str());
  }
}
//=====================================================================================
void HOMARD_Gen_i::InvalideHypo(const char* nomHypo)
//=====================================================================================
{
  MESSAGE( "InvalideHypo : nomHypo    = " << nomHypo  );
  HOMARD::HOMARD_Hypothesis_var myHypo = myContextMap[GetCurrentStudyID()]._mesHypotheses[nomHypo];
  if (CORBA::is_nil(myHypo))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Hypothesis ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

  HOMARD::listeIters* maListe = myHypo->GetIterations();
  int numberOfIter = maListe->length();
  for (int NumeIter = 0; NumeIter< numberOfIter; NumeIter++)
  {
      std::string nomIter = std::string((*maListe)[NumeIter]);
      InvalideIter(nomIter.c_str());
  }
}
//
//=====================================================================================
void HOMARD_Gen_i::InvalideIter(const char* nomIter)
//=====================================================================================
{
  MESSAGE("InvalideIter : nomIter    = " << nomIter);
  SetEtatIter(nomIter,false);
  HOMARD::HOMARD_Iteration_var myIteration = myContextMap[GetCurrentStudyID()]._mesIterations[nomIter];
  if (CORBA::is_nil(myIteration))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Iteration ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

  HOMARD::listeIterFilles* maListe = myIteration->GetIterations();
  int numberOfIter = maListe->length();
  for (int NumeIter = 0; NumeIter< numberOfIter; NumeIter++)
  {
      std::string nomIterFille = std::string((*maListe)[NumeIter]);
      InvalideIter(nomIterFille.c_str());
  }

  SALOMEDS::SObject_var aIterSO = SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(myIteration)));
  SALOMEDS::ChildIterator_var  aIter = myCurrentStudy->NewChildIterator(aIterSO);
  for (; aIter->More(); aIter->Next())
  {
      SALOMEDS::SObject_var so = aIter->Value();
      SALOMEDS::GenericAttribute_var anAttr;
      if (!so->FindAttribute(anAttr, "AttributeComment")) continue;
      SALOMEDS::AttributeComment_var aCommentAttr = SALOMEDS::AttributeComment::_narrow(anAttr);
      std::string value (aCommentAttr->Value());
      if(value == std::string("HypoHomard")) continue;
      SALOMEDS::StudyBuilder_var aStudyBuilder = myCurrentStudy->NewBuilder();
      aStudyBuilder->RemoveObject(so);
  }
  const char * nomCas = myIteration->GetCaseName();
  HOMARD::HOMARD_Cas_var myCase = myContextMap[GetCurrentStudyID()]._mesCas[nomCas];
  if (CORBA::is_nil(myCase))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Case Context ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };
  const char* dirParent  = myCase->GetDirName();
  const char* nomDir     = myIteration->GetDirName();
  const char* nomFichier = myIteration->GetMeshFile();
  std::string commande= "rm -rf " + std::string(dirParent) + "/" + std::string(nomDir);
  commande = commande + ";rm -rf " + std::string(nomFichier);
  if ((system(commande.c_str())) != 0)
  {
        SALOME::ExceptionStruct es;
        es.type = SALOME::BAD_PARAM;
        es.text = "Menage du repertoire de calcul impossible" ;
        throw SALOME::SALOME_Exception(es);
        return ;
  }
// Suppression du maillage publie dans SMESH
  const char* MeshName = myIteration->GetMeshName();
  DeleteResultInSmesh(nomFichier, MeshName) ;
}
//
//=====================================================================================
void HOMARD_Gen_i::AssociateHypoZone(const char* nomHypothesis, const char* ZoneName, CORBA::Long TypeUse)
{
  MESSAGE ( "AssociateHypoZone : nomHypo = " << nomHypothesis << ", ZoneName= " << ZoneName << ", TypeUse = " << TypeUse);
  IsValidStudy () ;

  HOMARD::HOMARD_Hypothesis_var myHypo = myContextMap[GetCurrentStudyID()]._mesHypotheses[nomHypothesis];
  ASSERT(!CORBA::is_nil(myHypo));
  SALOMEDS::SObject_var aHypoSO = SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(myHypo)));
  ASSERT(!CORBA::is_nil(aHypoSO));

  HOMARD::HOMARD_Zone_var myZone = myContextMap[GetCurrentStudyID()]._mesZones[ZoneName];
  ASSERT(!CORBA::is_nil(myZone));
  SALOMEDS::SObject_var aZoneSO = SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(myZone)));
  ASSERT(!CORBA::is_nil(aZoneSO));
  SALOMEDS::StudyBuilder_var aStudyBuilder = myCurrentStudy->NewBuilder();
  aStudyBuilder->NewCommand();

  SALOMEDS::SObject_var aSubSO = aStudyBuilder->NewObject(aHypoSO);
  aStudyBuilder->Addreference(aSubSO, aZoneSO);
  aStudyBuilder->CommitCommand();

  myZone->AddHypo(nomHypothesis);
  myHypo->AddZone(ZoneName, TypeUse);
  MESSAGE ( "Fin de AssociateHypoZone");
};

//=====================================================================================
void HOMARD_Gen_i::DissociateHypoZone(const char* ZoneName, const char* nomHypothesis)
{
  MESSAGE ( "DissociateHypoZone : ZoneName= " << ZoneName << ", nomHypo = " << nomHypothesis);
  IsValidStudy () ;

  HOMARD::HOMARD_Hypothesis_var myHypo = myContextMap[GetCurrentStudyID()]._mesHypotheses[nomHypothesis];
  ASSERT(!CORBA::is_nil(myHypo));
  SALOMEDS::SObject_var aHypoSO = SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(myHypo)));
  ASSERT(!CORBA::is_nil(aHypoSO));

  HOMARD::HOMARD_Zone_var myZone = myContextMap[GetCurrentStudyID()]._mesZones[ZoneName];
  ASSERT(!CORBA::is_nil(myZone));
  SALOMEDS::SObject_var aZoneSO = SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(myZone)));
  ASSERT(!CORBA::is_nil(aZoneSO));


  SALOMEDS::StudyBuilder_var aStudyBuilder = myCurrentStudy->NewBuilder();

  SALOMEDS::ChildIterator_var it = myCurrentStudy->NewChildIterator(aHypoSO);
  for (; it->More(); it->Next())
  {
    SALOMEDS::SObject_var aHypObj = it->Value();
    SALOMEDS::SObject_var ptrObj;
    if (aHypObj->ReferencedObject(ptrObj))
    {
      if (std::string(ptrObj->GetName()) == std::string(aZoneSO->GetName()))
      {
        aStudyBuilder->NewCommand();
        aStudyBuilder->RemoveObject(aHypObj);
        aStudyBuilder->CommitCommand();
        break;
      }
    }
  }

  myZone->SupprHypo(nomHypothesis);
  myHypo->SupprZone(ZoneName);
};

//=============================================================================
void HOMARD_Gen_i::AssociateIterIter(const char* nomIterParent, const char* nomIter)
{
  MESSAGE ( "AssociateIterIter : nomIter       = " << nomIter << " nomIterParent = " << nomIterParent);
  IsValidStudy () ;

  HOMARD::HOMARD_Iteration_var myIterationParent = myContextMap[GetCurrentStudyID()]._mesIterations[nomIterParent];
  ASSERT(!CORBA::is_nil(myIterationParent));
  HOMARD::HOMARD_Iteration_var myIteration = myContextMap[GetCurrentStudyID()]._mesIterations[nomIter];
  ASSERT(!CORBA::is_nil(myIteration));

  myIterationParent->AddIteration(nomIter);
  myIteration->SetIterParent(nomIterParent);
}

//===================================================================================
void HOMARD_Gen_i::AssociateIterHypo(const char* nomIter, const char* nomHypo)
{
  MESSAGE("AssociateIterHypo : nomHypo = " << nomHypo << " nomIter = " << nomIter);
  IsValidStudy () ;

  HOMARD::HOMARD_Hypothesis_var myHypo = myContextMap[GetCurrentStudyID()]._mesHypotheses[nomHypo];
  ASSERT(!CORBA::is_nil(myHypo));
  SALOMEDS::SObject_var aHypoSO = SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(myHypo)));
  ASSERT(!CORBA::is_nil(aHypoSO));

  HOMARD::HOMARD_Iteration_var myIteration = myContextMap[GetCurrentStudyID()]._mesIterations[nomIter];
  ASSERT(!CORBA::is_nil(myIteration));
  SALOMEDS::SObject_var aIterSO = SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(myIteration)));
  ASSERT(!CORBA::is_nil(aIterSO));

  SALOMEDS::StudyBuilder_var aStudyBuilder = myCurrentStudy->NewBuilder();

  aStudyBuilder->NewCommand();

  SALOMEDS::SObject_var aSubSO = aStudyBuilder->NewObject(aIterSO);
  aStudyBuilder->Addreference(aSubSO, aHypoSO);

  aStudyBuilder->CommitCommand();

  myIteration->SetHypoName(nomHypo);
  myHypo->AddIteration(nomIter);
};

//=============================================================================
CORBA::Boolean HOMARD_Gen_i::VerifieDir(const char* nomDir)
{
  std::map<std::string, HOMARD::HOMARD_Cas_var>::const_iterator it;
  for (it  = myContextMap[GetCurrentStudyID()]._mesCas.begin();
	it != myContextMap[GetCurrentStudyID()]._mesCas.end(); it++)
  {
   if (std::string(nomDir) == std::string(it->second->GetDirName())) return false;
  }
  return true;
}

//=============================================================================
HOMARD::HOMARD_Cas_ptr HOMARD_Gen_i::CreateCase(const char* nomCas, const char* MeshName, const char* MeshFile)
{
  MESSAGE ( "CreateCase : nomCas = " << nomCas << ", MeshName = " << MeshName << ", MeshFile = " << MeshFile );
  IsValidStudy () ;

  if ((myContextMap[GetCurrentStudyID()]._mesCas).find(nomCas)!=(myContextMap[GetCurrentStudyID()]._mesCas).end())
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "This case has already been defined";
      throw SALOME::SALOME_Exception(es);
      return 0;
  };

  HOMARD::HOMARD_Cas_var myCase = newCase();
  myCase->SetName(nomCas);
  SALOMEDS::SObject_var aSO;
  PublishInStudy(myCurrentStudy, aSO, myCase, nomCas);
  myContextMap[GetCurrentStudyID()]._mesCas[nomCas] = myCase;


  std::vector<double> LesExtremes =GetBoundingBoxInMedFile(MeshFile);
  HOMARD::extrema_var aSeq = new HOMARD::extrema();
  if (LesExtremes.size()!=10) { return false; }
  aSeq->length(10);
  for (int i =0; i< LesExtremes.size(); i++)
       aSeq[i]=LesExtremes[i];
  myCase->SetBoundingBox(aSeq);

  std::set<std::string> LesGroupes  =GetListeGroupesInMedFile(MeshFile);
  HOMARD::ListGroupType_var aSeqGroupe = new HOMARD::ListGroupType;
  aSeqGroupe->length(LesGroupes.size());
  std::set<std::string>::const_iterator it;
  int i = 0;
  for (it=LesGroupes.begin() ; it != LesGroupes.end(); it++)
     aSeqGroupe[i++]=(*it).c_str();
  myCase->SetGroups(aSeqGroupe);

// Recherche d'un nom pour l'iteration 0. Par defaut, on prend le nom
// du maillage du cas. Si ce nom existe deja, on incremente avec 0, 1, 2, etc.
  int monNum=0;
  std::string nomIter = std::string(MeshName) ;
  while ((myContextMap[GetCurrentStudyID()]._mesIterations).find(nomIter) != (myContextMap[GetCurrentStudyID()]._mesIterations.end()))
  {
     std::ostringstream nom;
     nom << MeshName << monNum;
     nomIter=nom.str();
     monNum = monNum+1;
  }

  HOMARD::HOMARD_Iteration_var anIter = newIteration();
  myContextMap[GetCurrentStudyID()]._mesIterations[nomIter] = anIter;
  std::ostringstream DirName;
  DirName << "I_00";

  anIter->SetDirName(DirName.str().c_str());
  anIter->SetName(nomIter.c_str());
  anIter->SetMeshFile(MeshFile);
  anIter->SetMeshName(MeshName);
  anIter->SetNumber(0);

  AssociateCaseIter (nomCas,nomIter.c_str(),"IterationHomard");
  SetEtatIter(nomIter.c_str(),true);
//
  PublishResultInSmesh(MeshFile, 0);

// Valeurs par defaut des filtrages
  myCase->SetPyram(0);

  return HOMARD::HOMARD_Cas::_duplicate(myCase);
}

//=============================================================================
HOMARD::HOMARD_Cas_ptr HOMARD_Gen_i::GetCas(const char* nomCas)
{
  IsValidStudy () ;
  HOMARD::HOMARD_Cas_var myCase = myContextMap[GetCurrentStudyID()]._mesCas[nomCas];
  if (CORBA::is_nil(myCase))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Case";
      throw SALOME::SALOME_Exception(es);
      return 0;
  };

  return HOMARD::HOMARD_Cas::_duplicate(myCase);
}

//=============================================================================
HOMARD::HOMARD_Zone_ptr HOMARD_Gen_i::GetZone(const char* ZoneName)
{
  IsValidStudy () ;
  HOMARD::HOMARD_Zone_var myZone = myContextMap[GetCurrentStudyID()]._mesZones[ZoneName];
  ASSERT(!CORBA::is_nil(myZone));
  return HOMARD::HOMARD_Zone::_duplicate(myZone);
}

//=============================================================================
HOMARD::HOMARD_Hypothesis_ptr HOMARD_Gen_i::GetHypothesis(const char* nomHypothesis)
{
  MESSAGE ( "GetHypothesis : nomHypothesis = " << nomHypothesis );
  IsValidStudy () ;
  MESSAGE ( "GetHypothesis : GetCurrentStudyID() = " << GetCurrentStudyID() );
  HOMARD::HOMARD_Hypothesis_var myHypothesis = myContextMap[GetCurrentStudyID()]._mesHypotheses[nomHypothesis];
  ASSERT(!CORBA::is_nil(myHypothesis));
  return HOMARD::HOMARD_Hypothesis::_duplicate(myHypothesis);
}

//=============================================================================
HOMARD::HOMARD_Iteration_ptr  HOMARD_Gen_i::GetIteration(const char* nomIteration)
{
  IsValidStudy () ;
  HOMARD::HOMARD_Iteration_var myIteration = myContextMap[GetCurrentStudyID()]._mesIterations[nomIteration];
  ASSERT(!CORBA::is_nil(myIteration));
  return HOMARD::HOMARD_Iteration::_duplicate(myIteration);
}
//=============================================================================
HOMARD::HOMARD_Boundary_ptr HOMARD_Gen_i::GetBoundary(const char* nomBoundary)
{
  IsValidStudy () ;

  HOMARD::HOMARD_Boundary_var myBoundary = myContextMap[GetCurrentStudyID()]._mesBoundarys[nomBoundary];
  ASSERT(!CORBA::is_nil(myBoundary));
  return HOMARD::HOMARD_Boundary::_duplicate(myBoundary);
}

//=============================================================================
HOMARD::HOMARD_Hypothesis_ptr HOMARD_Gen_i::CreateHypothesis(const char* nomHypothesis)
{
  MESSAGE ( "CreateHypothesis : nomHypothesis  = " << nomHypothesis );
  IsValidStudy () ;

  if ((myContextMap[GetCurrentStudyID()]._mesHypotheses).find(nomHypothesis) != (myContextMap[GetCurrentStudyID()]._mesHypotheses).end())
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "This hypothesis is already defined.";
      throw SALOME::SALOME_Exception(es);
      return 0;
    }

  HOMARD::HOMARD_Hypothesis_var myHypothesis = newHypothesis();
  myHypothesis->SetName(nomHypothesis);
  myContextMap[GetCurrentStudyID()]._mesHypotheses[nomHypothesis] = myHypothesis;
  SALOMEDS::SObject_var aSO;
  PublishInStudy(myCurrentStudy, aSO, myHypothesis, nomHypothesis);

// Valeurs par defaut des options avancees
  myHypothesis->SetNivMax(-1);
  myHypothesis->SetDiamMin(-1.0);
  myHypothesis->SetAdapInit(0);

  return HOMARD::HOMARD_Hypothesis::_duplicate(myHypothesis);
}

//============================================================================================================
HOMARD::HOMARD_Iteration_ptr HOMARD_Gen_i::CreateIteration(const char* nomIteration, const char* nomIterParent)
//============================================================================================================
{
  MESSAGE ("CreateIteration : nomIteration  = " << nomIteration << "nomIterParent = " << nomIterParent);
  IsValidStudy () ;

  HOMARD::HOMARD_Iteration_var myIterationParent = myContextMap[GetCurrentStudyID()]._mesIterations[nomIterParent];
  if (CORBA::is_nil(myIterationParent))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "The parent iteration is not defined.";
      throw SALOME::SALOME_Exception(es);
      return 0;
  };

  const char* nomCas = GetCaseName(nomIterParent);
  MESSAGE ("CreateIteration : nomCas = " << nomCas);
  HOMARD::HOMARD_Cas_var myCase = myContextMap[GetCurrentStudyID()]._mesCas[nomCas];
  if (CORBA::is_nil(myCase))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Case Context ";
      throw SALOME::SALOME_Exception(es);
      return 0;
  };

  if ((myContextMap[GetCurrentStudyID()]._mesIterations).find(nomIteration)!=(myContextMap[GetCurrentStudyID()]._mesIterations).end())
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "This iteration is already defined. ";
      throw SALOME::SALOME_Exception(es);
      return 0;
  };

   HOMARD::HOMARD_Iteration_var myIteration = newIteration();
   if (CORBA::is_nil(myIteration))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Unable to create Iteration ";
      throw SALOME::SALOME_Exception(es);
      return 0;
  };
   myContextMap[GetCurrentStudyID()]._mesIterations[std::string(nomIteration)] = myIteration;
   myIteration->SetName(nomIteration);
   myIteration->SetMeshName(nomIteration);

   int numero = myIterationParent->GetNumber() + 1;
   myIteration->SetNumber(numero);

// Nombre d'iterations deja connues pour le cas, permettant
// la creation d'un sous-repertoire unique
   int nbitercase = myCase->GetNumber();
   std::ostringstream iaux ;
   iaux << std::setw(2) << std::setfill('0') << nbitercase ;
   std::stringstream DirName;
   DirName << "I" << iaux.str();
   myIteration->SetDirName(DirName.str().c_str());

// Le nom du fichier du maillage MED est indice par le nombre d'iterations du cas.
// Si on a une chaine unique depuis le depart, ce nombre est le meme que le
// numero d'iteration dans la sucession : maill.01.med, maill.02.med, etc... C'est le
// cas le plus frequent.
// Si on a plusieurs branches, donc des iterations a meme niveau d'adaptation, utiliser
// le nombre d'iterations du cas permet d'eviter les collisions.
   std::stringstream MeshFile;
   const char* nomDir = myCase->GetDirName();
   MeshFile << nomDir << "/maill." << iaux.str() << ".med";
   myIteration->SetMeshFile(MeshFile.str().c_str());

// Association avec le cas et l'iteration precedente
   std::string label = "IterationHomard_" + std::string(nomIterParent);
   AssociateCaseIter(nomCas, nomIteration, label.c_str());
   AssociateIterIter (nomIterParent,nomIteration);

   return HOMARD::HOMARD_Iteration::_duplicate(myIteration);
}


//=============================================================================
HOMARD::HOMARD_Boundary_ptr HOMARD_Gen_i::CreateBoundary(const char* BoundaryName, CORBA::Long BoundaryType)
{
  MESSAGE ("CreateBoundary : BoundaryName  = " << BoundaryName << ", BoundaryType = " << BoundaryType);
  IsValidStudy () ;

  if ((myContextMap[GetCurrentStudyID()]._mesBoundarys).find(BoundaryName)!=(myContextMap[GetCurrentStudyID()]._mesBoundarys).end())
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "This boundary has already been defined";
      throw SALOME::SALOME_Exception(es);
      return 0;
  };

  HOMARD::HOMARD_Boundary_var myBoundary = newBoundary();
  myBoundary->SetName(BoundaryName);
  myBoundary->SetBoundaryType(BoundaryType);

  myContextMap[GetCurrentStudyID()]._mesBoundarys[BoundaryName] = myBoundary;

  SALOMEDS::SObject_var aSO;
  SALOMEDS::SObject_var aResultSO=PublishInStudy(myCurrentStudy, aSO, myBoundary, BoundaryName);

  return HOMARD::HOMARD_Boundary::_duplicate(myBoundary);
}
//=============================================================================
HOMARD::HOMARD_Boundary_ptr HOMARD_Gen_i::CreateBoundaryDi(const char* BoundaryName, const char* MeshName, const char* MeshFile)
{
  MESSAGE ("CreateBoundaryDi : BoundaryName  = " << BoundaryName << "MeshName = " << MeshName );
  HOMARD::HOMARD_Boundary_var myBoundary = CreateBoundary(BoundaryName, 0);
  myBoundary->SetMeshFile( MeshFile ) ;
  myBoundary->SetMeshName( MeshName ) ;

  return HOMARD::HOMARD_Boundary::_duplicate(myBoundary);
}
//=============================================================================
HOMARD::HOMARD_Boundary_ptr HOMARD_Gen_i::CreateBoundaryCylinder(const char* BoundaryName,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre,
                                      CORBA::Double Xaxis, CORBA::Double Yaxis, CORBA::Double Zaxis,
                                      CORBA::Double Rayon)
{
  MESSAGE ("CreateBoundaryCylinder : BoundaryName  = " << BoundaryName ) ;
  HOMARD::HOMARD_Boundary_var myBoundary = CreateBoundary(BoundaryName, 1) ;
  myBoundary->SetCylinder( Xcentre, Ycentre, Zcentre, Xaxis, Yaxis, Zaxis, Rayon ) ;

  return HOMARD::HOMARD_Boundary::_duplicate(myBoundary) ;
}
//=============================================================================
HOMARD::HOMARD_Boundary_ptr HOMARD_Gen_i::CreateBoundarySphere(const char* BoundaryName,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre,
                                      CORBA::Double Rayon)
{
  MESSAGE ("CreateBoundarySphere : BoundaryName  = " << BoundaryName ) ;
  HOMARD::HOMARD_Boundary_var myBoundary = CreateBoundary(BoundaryName, 2) ;
  myBoundary->SetSphere( Xcentre, Ycentre, Zcentre, Rayon ) ;

  return HOMARD::HOMARD_Boundary::_duplicate(myBoundary) ;
}


//=============================================================================
HOMARD::HOMARD_Zone_ptr HOMARD_Gen_i::CreateZone(const char* ZoneName, CORBA::Long ZoneType)
{
  MESSAGE ("CreateZone : ZoneName  = " << ZoneName << ", ZoneType = " << ZoneType);
  IsValidStudy () ;

  if ((myContextMap[GetCurrentStudyID()]._mesZones).find(ZoneName)!=(myContextMap[GetCurrentStudyID()]._mesZones).end())
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "This zone has already been defined";
      throw SALOME::SALOME_Exception(es);
      return 0;
  };

  HOMARD::HOMARD_Zone_var myZone = newZone();
  myZone->SetName(ZoneName);
  myZone->SetZoneType(ZoneType);

  myContextMap[GetCurrentStudyID()]._mesZones[ZoneName] = myZone;

  SALOMEDS::SObject_var aSO;
  SALOMEDS::SObject_var aResultSO=PublishInStudy(myCurrentStudy, aSO, myZone, ZoneName);

  return HOMARD::HOMARD_Zone::_duplicate(myZone);
}
//=============================================================================
HOMARD::HOMARD_Zone_ptr HOMARD_Gen_i::CreateZoneBox(const char* ZoneName,
                                      CORBA::Double Xmini, CORBA::Double Xmaxi,
                                      CORBA::Double Ymini, CORBA::Double Ymaxi,
                                      CORBA::Double Zmini, CORBA::Double Zmaxi)
{
  MESSAGE ("CreateZoneBox : ZoneName  = " << ZoneName ) ;
  HOMARD::HOMARD_Zone_var myZone = CreateZone(ZoneName, 2) ;
  myZone->SetBox ( Xmini, Xmaxi, Ymini, Ymaxi, Zmini, Zmaxi) ;

  return HOMARD::HOMARD_Zone::_duplicate(myZone) ;
}
//=============================================================================
HOMARD::HOMARD_Zone_ptr HOMARD_Gen_i::CreateZoneSphere(const char* ZoneName,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre, CORBA::Double Rayon)
{
  MESSAGE ("CreateZoneSphere : ZoneName  = " << ZoneName ) ;
  HOMARD::HOMARD_Zone_var myZone = CreateZone(ZoneName, 4) ;
  myZone->SetSphere( Xcentre, Ycentre, Zcentre, Rayon ) ;

  return HOMARD::HOMARD_Zone::_duplicate(myZone) ;
}
//=============================================================================
HOMARD::HOMARD_Zone_ptr HOMARD_Gen_i::CreateZoneCylinder(const char* ZoneName,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre,
                                      CORBA::Double Xaxe, CORBA::Double Yaxe, CORBA::Double Zaxe,
                                      CORBA::Double Rayon, CORBA::Double Haut)
{
  MESSAGE ("CreateZoneCylinder : ZoneName  = " << ZoneName ) ;
  HOMARD::HOMARD_Zone_var myZone = CreateZone(ZoneName, 5) ;
  myZone->SetCylinder( Xcentre, Ycentre, Zcentre, Xaxe, Yaxe, Zaxe, Rayon, Haut ) ;

  return HOMARD::HOMARD_Zone::_duplicate(myZone) ;
}
//=============================================================================
HOMARD::HOMARD_Zone_ptr HOMARD_Gen_i::CreateZonePipe(const char* ZoneName,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre,
                                      CORBA::Double Xaxe, CORBA::Double Yaxe, CORBA::Double Zaxe,
                                      CORBA::Double Rayon, CORBA::Double Haut, CORBA::Double Rayonint)
{
  MESSAGE ("CreateZonePipe : ZoneName  = " << ZoneName ) ;
  HOMARD::HOMARD_Zone_var myZone = CreateZone(ZoneName, 7) ;
  myZone->SetPipe( Xcentre, Ycentre, Zcentre, Xaxe, Yaxe, Zaxe, Rayon, Haut, Rayonint ) ;

  return HOMARD::HOMARD_Zone::_duplicate(myZone) ;
}
//=============================================================================
HOMARD::HOMARD_Zone_ptr HOMARD_Gen_i::CreateZoneBox2D(const char* ZoneName,
                                      CORBA::Double Umini, CORBA::Double Umaxi,
                                      CORBA::Double Vmini, CORBA::Double Vmaxi,
                                      CORBA::Long Orient)
{
  MESSAGE ("CreateZoneBox2D : ZoneName  = " << ZoneName ) ;
//   MESSAGE ("Umini = " << Umini << ", Umaxi =" << Umaxi ) ;
//   MESSAGE ("Vmini = " << Vmini << ", Vmaxi =" << Vmaxi ) ;
//   MESSAGE ("Orient = " << Orient ) ;

  double Xmini, Xmaxi ;
  double Ymini, Ymaxi ;
  double Zmini, Zmaxi ;
  if ( Orient == 1 )
  { Xmini = Umini ;
    Xmaxi = Umaxi ;
    Ymini = Vmini ;
    Ymaxi = Vmaxi ;
    Zmini = 0. ;
    Zmaxi = 0. ; }
  else if ( Orient == 2 )
  { Xmini = 0. ;
    Xmaxi = 0. ;
    Ymini = Umini ;
    Ymaxi = Umaxi ;
    Zmini = Vmini ;
    Zmaxi = Vmaxi ; }
  else if ( Orient == 3 )
  { Xmini = Vmini ;
    Xmaxi = Vmaxi ;
    Ymini = 0. ;
    Ymaxi = 0. ;
    Zmini = Umini ;
    Zmaxi = Umaxi ; }
  else { ASSERT( Orient >= 1 and Orient <= 3 ) ; }

  HOMARD::HOMARD_Zone_var myZone = CreateZone(ZoneName, 10+Orient) ;
  myZone->SetBox ( Xmini, Xmaxi, Ymini, Ymaxi, Zmini, Zmaxi) ;

  return HOMARD::HOMARD_Zone::_duplicate(myZone) ;
}
//=============================================================================
HOMARD::HOMARD_Zone_ptr HOMARD_Gen_i::CreateZoneDisk(const char* ZoneName,
                                      CORBA::Double Ucentre, CORBA::Double Vcentre,
                                      CORBA::Double Rayon,
                                      CORBA::Long Orient)
{
  MESSAGE ("CreateZoneDisk : ZoneName  = " << ZoneName ) ;
  double Xcentre ;
  double Ycentre ;
  double Zcentre ;
  if ( Orient == 1 )
  { Xcentre = Ucentre ;
    Ycentre = Vcentre ;
    Zcentre = 0. ; }
  else if ( Orient == 2 )
  { Xcentre = 0. ;
    Ycentre = Ucentre ;
    Zcentre = Vcentre ; }
  else if ( Orient == 3 )
  { Xcentre = Vcentre ;
    Ycentre = 0. ;
    Zcentre = Ucentre ; }
  else { ASSERT( Orient >= 1 and Orient <= 3 ) ; }

  HOMARD::HOMARD_Zone_var myZone = CreateZone(ZoneName, 30+Orient) ;
  myZone->SetCylinder( Xcentre, Ycentre, Zcentre, 0., 0., 1., Rayon, 1. ) ;

  return HOMARD::HOMARD_Zone::_duplicate(myZone) ;
}
//=============================================================================
HOMARD::HOMARD_Zone_ptr HOMARD_Gen_i::CreateZoneDiskWithHole(const char* ZoneName,
                                      CORBA::Double Ucentre, CORBA::Double Vcentre,
                                      CORBA::Double Rayon, CORBA::Double Rayonint,
                                      CORBA::Long Orient)
{
  MESSAGE ("CreateZoneDiskWithHole : ZoneName  = " << ZoneName ) ;
  double Xcentre ;
  double Ycentre ;
  double Zcentre ;
  if ( Orient == 1 )
  { Xcentre = Ucentre ;
    Ycentre = Vcentre ;
    Zcentre = 0. ; }
  else if ( Orient == 2 )
  { Xcentre = 0. ;
    Ycentre = Ucentre ;
    Zcentre = Vcentre ; }
  else if ( Orient == 3 )
  { Xcentre = Vcentre ;
    Ycentre = 0. ;
    Zcentre = Ucentre ; }
  else { ASSERT( Orient >= 1 and Orient <= 3 ) ; }

  HOMARD::HOMARD_Zone_var myZone = CreateZone(ZoneName, 60+Orient) ;
  myZone->SetPipe( Xcentre, Ycentre, Zcentre, 0., 0., 1., Rayon, 1., Rayonint ) ;

  return HOMARD::HOMARD_Zone::_duplicate(myZone) ;
}




//=============================================================================
CORBA::Long HOMARD_Gen_i::Compute(const char* nomIteration, CORBA::Long etatMenage)
{
  MESSAGE ( "Compute : calcul de " << nomIteration );
  IsValidStudy () ;

  HOMARD::HOMARD_Iteration_var myIteration = myContextMap[GetCurrentStudyID()]._mesIterations[nomIteration];
  ASSERT(!CORBA::is_nil(myIteration));

// on ne calcule pas l iteration 0
  int NumeIter = myIteration->GetNumber();
  if ( NumeIter == 0 )
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "This iteration is the first of the case and cannot be computed.";
      throw SALOME::SALOME_Exception(es);
      return 1;
  };

// on verifie qu il y a une hypothese (erreur improbable);
  const char* nomHypo = myIteration->GetHypoName();
  if (std::string(nomHypo) == std::string(""))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text= "This iteration does not have any associated hypothesis.";
      throw SALOME::SALOME_Exception(es);
      return 2;
  }
  HOMARD::HOMARD_Hypothesis_var myHypo = myContextMap[GetCurrentStudyID()]._mesHypotheses[nomHypo];
  ASSERT(!CORBA::is_nil(myHypo));


  // A.4. L'iteration parent
  const char* nomIterationParent = myIteration->GetIterParent();
  HOMARD::HOMARD_Iteration_var myIterationParent = myContextMap[GetCurrentStudyID()]._mesIterations[nomIterationParent];
  ASSERT(!CORBA::is_nil(myIterationParent));
  if ( ! myIterationParent->GetEtat() )
  {
      /*
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      std::string text = "The iteration cannot be computed because the previous iteration " + std::string(nomIterationParent) + " is not valid.";
      es.text = CORBA::string_dup(text.c_str());
      throw SALOME::SALOME_Exception(es);
      return 0;
      */
      int codret = Compute(nomIterationParent, etatMenage);
      if (codret != 0)
      {
        // GERALD -- QMESSAGE BOX
        ASSERT("Pb au calcul de l'iteration precedente" == 0);
      }
  };

  const char* nomCas = myIteration->GetCaseName();
  HOMARD::HOMARD_Cas_var myCase = myContextMap[GetCurrentStudyID()]._mesCas[nomCas];
  ASSERT(!CORBA::is_nil(myCase));

  int codret = 0;
  std::stringstream saux0 ;
  saux0 << NumeIter - 1 ;
  std::string siter = saux0.str() ;
  if (NumeIter < 11) { siter = "0" + siter ; }
//
  std::stringstream saux1 ;
  saux1 << NumeIter ;
  std::string siterp1 = saux1.str() ;
  if (NumeIter < 10) { siterp1 = "0" + siterp1 ; }

  // B. Les repertoires
  // B.1. Le repertoire du cas
  const char* nomDir = myCase->GetDirName();
  MESSAGE ( ". nomDir = " << nomDir );

  // B.2. Le sous-repertoire de l'iteration a calculer, puis le repertoire complet a creer
  // B.2.1. Le nom du sous-repertoire
   const char* nomDirIt = myIteration->GetDirName();

  // B.2.2. Le nom complet du sous-repertoire
  std::stringstream DirCompute ;
  DirCompute << nomDir << "/" << nomDirIt;
  MESSAGE (". DirCompute = " << DirCompute.str() );

  // B.2.3. Si le sous-repertoire n'existe pas, on le cree
  //        Si le sous-repertoire existe :
  //         etatMenage = 0 : on sort en erreur si le repertoire n'est pas vide
  //         etatMenage = 1 : on fait le menage du repertoire
  if (chdir(DirCompute.str().c_str()) != 0)
  {
//  Creation du repertoire car il n'existe pas :
    if (mkdir(DirCompute.str().c_str(), S_IRWXU|S_IRGRP|S_IXGRP) != 0)
    {
       // GERALD -- QMESSAGE BOX
       std::cerr << "Pb Creation du repertoire DirCompute = " << DirCompute.str() << std::endl;
       ASSERT("Pb a la creation du repertoire" == 0);
    }
  }
  else
  {
//  Le repertoire existe et on fait le menage de son contenu :
    if (etatMenage != 0)
    {
       MESSAGE (". Menage du repertoire DirCompute = " << DirCompute.str());
       std::string commande= "rm -rf " + DirCompute.str()+"/*" ;
       int codret = system(commande.c_str());
       if (codret != 0)
       {
         // GERALD -- QMESSAGE BOX
         std::cerr << ". Menage du repertoire de calcul" << DirCompute.str() << std::endl;
         ASSERT("Pb au menage du repertoire de calcul" == 0);
       }
    }
    else
    {
//  Le repertoire existe et s'il n'est pas vide, on sort en erreur :
       DIR *dp;
       struct dirent *dirp;
       dp  = opendir(DirCompute.str().c_str());
       bool result = true;
       while ((dirp = readdir(dp)) != NULL && result )
       {
            std::string file_name(dirp->d_name);
            result = file_name.empty() || file_name == "." || file_name == ".."; //if any file - break and return false
       }
       closedir(dp);
       if ( result == false)
       {
          SALOME::ExceptionStruct es;
          es.type = SALOME::BAD_PARAM;
          std::string text = "Directory : " + DirCompute.str() + "is not empty";
          es.text = CORBA::string_dup(text.c_str());
          throw SALOME::SALOME_Exception(es);
          return 3;
       }
    }
  }

  // B.3. Le sous-repertoire de l'iteration precedente
  const char* nomDirItPa ;
  std::stringstream DirComputePa ;
  if (NumeIter == 1)
  {
    nomDirItPa = nomDirIt;
    DirComputePa << DirCompute.str();
  }
  else
  {
    nomDirItPa = myIterationParent->GetDirName();
    DirComputePa << nomDir << "/" << nomDirItPa;
  }
  MESSAGE( ". nomDirItPa = " << nomDirItPa);
  MESSAGE( ". DirComputePa = " << DirComputePa.str() );

  // B.4. Le fichier des messages
  chdir(DirCompute.str().c_str()) ;
  std::string MessFile = DirCompute.str() + "/Liste." + siter + ".vers." + siterp1 ;
  MESSAGE (". MessFile = " << MessFile);
  myIteration->SetMessFile(MessFile.c_str());

   // C. On passe dans le repertoire de l'iteration a calculer
  chdir(DirCompute.str().c_str()) ;

  // D. Les donnees du calcul HOMARD
  // D.1. Le type de conformite
  int ConfType = myCase->GetConfType();
  MESSAGE ( ". ConfType = " << ConfType );

  // D.2. Le maillage n
  const char* NomMeshParent = myIterationParent->GetMeshName();
  MESSAGE ( ". NomMeshParent = " << NomMeshParent );
  const char* MeshFileParent = myIterationParent->GetMeshFile();
  MESSAGE ( ". MeshFileParent = " << MeshFileParent );

  // D.3. Le maillage n+1
  const char* NomMesh = myIteration->GetMeshName();
  MESSAGE ( ". NomMesh = " << NomMesh );
  const char* MeshFile = myIteration->GetMeshFile();
  MESSAGE ( ". MeshFile = " << MeshFile );
  FILE *file = fopen(MeshFile,"r");
  if (file != NULL)
  {
     fclose(file);
     if (etatMenage == 0)
     {
          SALOME::ExceptionStruct es;
          es.type = SALOME::BAD_PARAM;
          std::string text = "MeshFile : " + std::string(MeshFile) + " already exists ";
          es.text = CORBA::string_dup(text.c_str());
          throw SALOME::SALOME_Exception(es);
          return 4;
     }
     else
     {
         std::string commande = "rm -f " + std::string(MeshFile);
         codret = system(commande.c_str());
         if (codret != 0)
         {
          SALOME::ExceptionStruct es;
          es.type = SALOME::BAD_PARAM;
          std::string text = "PB with meshfile destruction ";
          es.text = CORBA::string_dup(text.c_str());
          throw SALOME::SALOME_Exception(es);
          return 5;
         }
      }
  }
  else
  {
     codret = 0 ;
  };


  // D.4. Les types de raffinement et de deraffinement
  // Les appels corba sont lourds, il vaut mieux les grouper
  HOMARD::listeTypes* ListTypes = myHypo->GetAdapRefinUnRef();
  ASSERT(ListTypes->length() == 3);
  int TypeAdap = (*ListTypes)[0];
  int TypeRaff = (*ListTypes)[1];
  int TypeDera = (*ListTypes)[2];

  // D.6. L'option d'interpolation des champs
  int TypeFieldInterp = myHypo->GetTypeFieldInterp();

  // E. Texte du fichier de configuration
  // E.1. Incontournables du texte
  HomardDriver* myDriver = new HomardDriver(siter, siterp1);
  myDriver->TexteInit(DirCompute.str(), DirComputePa.str(),MessFile);
  myDriver->TexteMaillage(NomMeshParent, MeshFileParent, 0);
  myDriver->TexteMaillage(NomMesh, MeshFile, 1);
  myDriver->TexteConfRaffDera(ConfType, TypeAdap, TypeRaff, TypeDera);

  // E.2. Ajout des informations liees aux zones eventuelles
  if (TypeAdap == 0)
  {
    HOMARD::listeZonesHypo* ListZone = myHypo->GetZones();
    int numberOfZonesx2 = ListZone->length();
    int NumZone ;

    for (int iaux = 0; iaux< numberOfZonesx2; iaux++)
    {
      std::string ZoneName = std::string((*ListZone)[iaux]);
      MESSAGE ( "... ZoneName = " << ZoneName);
      HOMARD::HOMARD_Zone_var myZone = myContextMap[GetCurrentStudyID()]._mesZones[ZoneName];
      ASSERT(!CORBA::is_nil(myZone));

      int ZoneType = myZone->GetZoneType();
      std::string TypeUsestr = std::string((*ListZone)[iaux+1]);
      int TypeUse = atoi( TypeUsestr.c_str() );
      MESSAGE ( "... ZoneType = " << ZoneType << ", TypeUse = "<<TypeUse);
      NumZone = iaux/2 + 1 ;
      HOMARD::double_array* zone = myZone->GetCoords();
      if ( ZoneType == 2 or ( ZoneType>=11 and ZoneType <=13 ) ) // Cas d un parallelepipede ou d'un rectangle
      {
        myDriver->TexteZone(NumZone, ZoneType, TypeUse, (*zone)[0], (*zone)[1], (*zone)[2], (*zone)[3], (*zone)[4], (*zone)[5], 0., 0., 0.);
      }
      else if ( ZoneType == 4 ) // Cas d une sphere
      {
        myDriver->TexteZone(NumZone, ZoneType, TypeUse, (*zone)[0], (*zone)[1], (*zone)[2], (*zone)[3], 0., 0., 0., 0., 0.);
      }
      else if ( ZoneType == 5 or ( ZoneType>=31 and ZoneType <=33 ) ) // Cas d un cylindre ou d'un disque
      {
        myDriver->TexteZone(NumZone, ZoneType, TypeUse, (*zone)[0], (*zone)[1], (*zone)[2], (*zone)[3], (*zone)[4], (*zone)[5], (*zone)[6], (*zone)[7], 0.);
      }
      else if ( ZoneType == 7 or ( ZoneType>=61 and ZoneType <=63 ) ) // Cas d un tuyau ou disque perce
      {
        myDriver->TexteZone(NumZone, ZoneType, TypeUse, (*zone)[0], (*zone)[1], (*zone)[2], (*zone)[3], (*zone)[4], (*zone)[5], (*zone)[6], (*zone)[7], (*zone)[8]);
      }
      else { ASSERT("ZoneType est incorrect." == 0) ; }
      iaux += 1 ;
    }
  }
  // E.3. Ajout des informations liees aux champs eventuels
  if (TypeAdap == 1)
  {
//  Le fichier du champ
    char* FieldFile = myIteration->GetFieldFile();
    MESSAGE ( ". FieldFile = " << FieldFile );
    if (strlen(FieldFile) == 0)
    {
      // GERALD -- QMESSAGE BOX
      std::cerr << "Le fichier du champ n'a pas ete fourni." << std::endl;
      ASSERT("The file for the field is not given." == 0);
    }
//  Les caracteristiques d'instants
    int TimeStep = myIteration->GetTimeStep();
    MESSAGE( ". TimeStep = " << TimeStep );
    int Rank = myIteration->GetRank();
    MESSAGE( ". Rank = " << Rank );
//  Les informations sur les champ
    HOMARD::InfosHypo* aInfosHypo = myHypo->GetField();
//  Le nom
    const char* FieldName = aInfosHypo->FieldName;
//  Les seuils
    int TypeThR = aInfosHypo->TypeThR;
    double ThreshR = aInfosHypo->ThreshR;
    int TypeThC = aInfosHypo->TypeThC;
    double ThreshC = aInfosHypo->ThreshC;
//  Saut entre mailles ou non ?
    int UsField = aInfosHypo->UsField;
    MESSAGE( ". UsField = " << UsField );
//  L'usage des composantes
    int UsCmpI = aInfosHypo->UsCmpI;
    MESSAGE( ". UsCmpI = " << UsCmpI );
//
    myDriver->TexteField(FieldName, FieldFile, TimeStep, Rank, TypeThR, ThreshR, TypeThC, ThreshC, UsField, UsCmpI);
//
//  Les composantes
    HOMARD::listeComposantsHypo* mescompo = myHypo->GetListComp();
    int numberOfCompos = mescompo->length();
    MESSAGE( ". numberOfCompos = " << numberOfCompos );
    for (int NumeComp = 0; NumeComp< numberOfCompos; NumeComp++)
    {
      std::string nomCompo = std::string((*mescompo)[NumeComp]);
      MESSAGE( "... nomCompo = " << nomCompo );
      myDriver->TexteCompo(NumeComp, nomCompo);
    }
  }
  // E.4. Ajout des informations liees au filtrage eventuel par les groupes
  HOMARD::ListGroupType* listeGroupes = myHypo->GetGroups();
  int numberOfGroups = listeGroupes->length();
  MESSAGE( ". numberOfGroups = " << numberOfGroups );
  if (numberOfGroups > 0)
  {

    for (int NumGroup = 0; NumGroup< numberOfGroups; NumGroup++)
    {
      std::string GroupName = std::string((*listeGroupes)[NumGroup]);
      MESSAGE( "... GroupName = " << GroupName );
      myDriver->TexteGroup(GroupName);
    }
  }

  // E.5. Ajout des informations liees a l'eventuel suivi de frontiere
  // On ecrit d'abord la definition des frontieres, puis les liens avec les groupes
  std::list<std::string>  ListeBoundaryTraitees ;
  HOMARD::ListBoundaryGroupType* ListBoundaryGroupType = myCase->GetBoundaryGroup();
  int numberOfitems = ListBoundaryGroupType->length();
  MESSAGE ( "... number of string for Boundary+Group = " << numberOfitems);
  int BoundaryOption = 1 ;
  int NumBoundaryAnalytical = 0 ;
  for (int NumBoundary = 0; NumBoundary< numberOfitems; NumBoundary=NumBoundary+2)
  {
    std::string BoundaryName = std::string((*ListBoundaryGroupType)[NumBoundary]);
    MESSAGE ( "... BoundaryName = " << BoundaryName);
    int A_faire = 1 ;
    std::list<std::string>::const_iterator it = ListeBoundaryTraitees.begin();
    while (it != ListeBoundaryTraitees.end())
    {
      MESSAGE ( "... BoundaryNameTraitee = " << *it);
      if ( BoundaryName == *it ) { A_faire = 0 ; }
      it++;
    }
    if ( A_faire == 1 )
    {
// Caracteristiques de la frontiere
      HOMARD::HOMARD_Boundary_var myBoundary = myContextMap[GetCurrentStudyID()]._mesBoundarys[BoundaryName];
      ASSERT(!CORBA::is_nil(myBoundary));
      int BoundaryType = myBoundary->GetBoundaryType();
      MESSAGE ( "... BoundaryType = " << BoundaryType );
// Ecriture selon le type
      if (BoundaryType == 0) // Cas d une frontiere discrete
      {
        const char* MeshName = myBoundary->GetMeshName() ;
        const char* MeshFile = myBoundary->GetMeshFile() ;
        myDriver->TexteBoundaryDi( MeshName, MeshFile);
        BoundaryOption = BoundaryOption*2 ;
      }
      else // Cas d une frontiere analytique
      {
        NumBoundaryAnalytical++ ;
        HOMARD::double_array* coor = myBoundary->GetCoords();
        if (BoundaryType == 1) // Cas d un cylindre
        {
          myDriver->TexteBoundaryAn(BoundaryName, NumBoundaryAnalytical, BoundaryType, (*coor)[0], (*coor)[1], (*coor)[2], (*coor)[3], (*coor)[4], (*coor)[5], (*coor)[6]);
          BoundaryOption = BoundaryOption*3 ;
        }
        else if (BoundaryType == 2) // Cas d une sphere
        {
          myDriver->TexteBoundaryAn(BoundaryName, NumBoundaryAnalytical, BoundaryType, (*coor)[0], (*coor)[1], (*coor)[2], (*coor)[3], 0., 0., 0.);
          BoundaryOption = BoundaryOption*3 ;
        }
      }
// Memorisation du traitement
      ListeBoundaryTraitees.push_back( BoundaryName );
    }
  }
  NumBoundaryAnalytical = 0 ;
  for (int NumBoundary = 0; NumBoundary< numberOfitems; NumBoundary=NumBoundary+2)
  {
    std::string BoundaryName = std::string((*ListBoundaryGroupType)[NumBoundary]);
    MESSAGE ( "... BoundaryName = " << BoundaryName);
    HOMARD::HOMARD_Boundary_var myBoundary = myContextMap[GetCurrentStudyID()]._mesBoundarys[BoundaryName];
    ASSERT(!CORBA::is_nil(myBoundary));
    int BoundaryType = myBoundary->GetBoundaryType();
    MESSAGE ( "... BoundaryType = " << BoundaryType );
//  Recuperation du nom du groupe
    std::string GroupName = std::string((*ListBoundaryGroupType)[NumBoundary+1]);
    MESSAGE ( "... GroupName = " << GroupName);
    if (BoundaryType == 0) // Cas d une frontiere discrete
    {
      if ( GroupName.size() > 0 ) { myDriver->TexteBoundaryDiGr ( GroupName ) ; }
    }
    else // Cas d une frontiere analytique
    {
      NumBoundaryAnalytical++ ;
      myDriver->TexteBoundaryAnGr ( BoundaryName, NumBoundaryAnalytical, GroupName ) ;
    }
  }
  myDriver->TexteBoundaryOption(BoundaryOption);

  // E.6. Ajout des informations liees a l'eventuelle interpolation des champs
  MESSAGE( "... TypeFieldInterp = " << TypeFieldInterp );
  if (TypeFieldInterp != 0)
  {
//  Le fichier des champs
    char* FieldFile = myIteration->GetFieldFile();
    MESSAGE ( ". FieldFile = " << FieldFile );
    if (strlen(FieldFile) == 0)
    {
      // GERALD -- QMESSAGE BOX
      std::cerr << "Le fichier du champ n'a pas ete fourni." << std::endl;
      ASSERT("The file for the field is not given." == 0);
    }
//  Les caracteristiques d'instants
    int TimeStep = myIteration->GetTimeStep();
    MESSAGE( ". TimeStep = " << TimeStep );
    int Rank = myIteration->GetRank();
    MESSAGE( ". Rank = " << Rank );
//
    myDriver->TexteFieldInterp(TypeFieldInterp, FieldFile, MeshFile, TimeStep, Rank);
//  Les champs
    if (TypeFieldInterp == 2)
    {
      HOMARD::listFieldInterpHypo* meschamps = myHypo->GetListFieldInterp();
      int numberOfFields = meschamps->length();
      MESSAGE( ". numberOfFields = " << numberOfFields );
      for (int NumeChamp = 0; NumeChamp< numberOfFields; NumeChamp++)
      {
        std::string nomChamp = std::string((*meschamps)[NumeChamp]);
        MESSAGE( "... nomChamp = " << nomChamp );
        myDriver->TexteFieldInterpName(NumeChamp, nomChamp);
      }
    }
  }
  // E.7. Ajout des options avancees
  int Pyram = myCase->GetPyram();
  MESSAGE ( ". Pyram = " << Pyram );
  int NivMax = myHypo->GetNivMax();
  MESSAGE ( ". NivMax = " << NivMax );
  double DiamMin = myHypo->GetDiamMin() ;
  MESSAGE ( ". DiamMin = " << DiamMin );
  int AdapInit = myHypo->GetAdapInit();
  MESSAGE ( ". AdapInit = " << AdapInit );
  myDriver->TexteAdvanced(Pyram, NivMax, DiamMin, AdapInit);

  // F. Ecriture du texte dans le fichier
  if (codret == 0)
  {
    myDriver->CreeFichier();
  }

// G. Execution
//
  int codretexec = 12 ;
  if (codret == 0)
  {
    codretexec = myDriver->ExecuteHomard();
//
    MESSAGE ( "Erreur en executant HOMARD : " << codretexec );
    if (codretexec == 0)
    {
      SetEtatIter(nomIteration,true);
    }
    else
    {
      // GERALD -- QMESSAGE BOX
      SetEtatIter(nomIteration,false);
    }
  }

  // H. Gestion des resultats
  if (codret == 0)
  {
    // H.1. Le fichier des messages, dans tous les cas
    std::stringstream saux1 ;
    saux1 << "Mess " << NumeIter ;
    PublishFileUnderIteration(nomIteration, MessFile.c_str(), saux1.str().c_str());

    // H.2. Si tout s'est bien passe :
    if (codretexec == 0)
    {
    // H.2.1. Le fichier de bilan
      std::stringstream saux2 ;
      saux2 << "Summary " << NumeIter ;
      std::string SummaryFile = DirCompute.str() + "/apad." + siterp1 + ".bilan" ;
      PublishFileUnderIteration(nomIteration, SummaryFile.c_str(), saux2.str().c_str());
    // H.2.2. Le fichier de  maillage obtenu
      std::stringstream saux0 ;
      saux0 <<"Iteration " << NumeIter ;
      PublishFileUnderIteration(nomIteration, MeshFile, saux0.str().c_str());
      PublishResultInSmesh(MeshFile, 1);
    }
  // H.3 Message d'erreur en cas de probleme
    else
    {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      std::string text = "Error during the adaptation.\n" ;
      try
      {
          ifstream fichier(MessFile.c_str(), ios::in);
          string ligne;
          while(getline(fichier, ligne) and (ligne != "===== HOMARD ===== STOP ====="));
          while (getline(fichier, ligne)) { text += ligne+ "\n";};
      }
      catch (...) {
        text += "no log file ....";
      }
      es.text = CORBA::string_dup(text.c_str());
      throw SALOME::SALOME_Exception(es);
    }
  }

  // I. Menage
  if (codret == 0)
  {
    delete myDriver;
  }
  //
  return codretexec ;
}

//===========================================================================
SALOMEDS::SObject_ptr HOMARD_Gen_i::PublishInStudy(SALOMEDS::Study_ptr theStudy,
                                                   SALOMEDS::SObject_ptr theSObject,
                                                   CORBA::Object_ptr theObject,
                                                   const char* theName)
{
  MESSAGE("PublishInStudy pour " << theName);
  SALOMEDS::SObject_var aResultSO;
  if (CORBA::is_nil(theStudy))
  {
    SALOME::ExceptionStruct es;
    es.type = SALOME::BAD_PARAM;
    es.text = "Invalid Study Context ";
    throw SALOME::SALOME_Exception(es);
    return 0;
  };

// Recuperation de l'objet correspondant, en essayant chacun des types possibles
// Rq : Iteration est publiee ailleurs
  HOMARD::HOMARD_Cas_var        aCase  = HOMARD::HOMARD_Cas::_narrow(theObject);
  HOMARD::HOMARD_Hypothesis_var aHypo = HOMARD::HOMARD_Hypothesis::_narrow(theObject);
  HOMARD::HOMARD_Zone_var       aZone = HOMARD::HOMARD_Zone::_narrow(theObject);
  HOMARD::HOMARD_Boundary_var   aBoundary = HOMARD::HOMARD_Boundary::_narrow(theObject);

   addInStudy(theStudy);

// Controle de la non publication d'un objet de meme nom
   if ((!aHypo->_is_nil()) or (!aZone->_is_nil()) or (!aBoundary->_is_nil()))
    {
      SALOMEDS::Study::ListOfSObject_var listSO = theStudy->FindObjectByName(theName, ComponentDataType());
      if (listSO->length() >= 1)
      {
          MESSAGE("This name "<<theName<<" is already used "<<listSO->length()<<" time(s)");
          std::cerr <<"This name "<<theName<<" is already used "<<listSO->length()<<" time(s)" << std::endl;
          aResultSO = listSO[0];
          return aResultSO._retn();
      }
    }

  // Caracteristiques de l'etude
  SALOMEDS::StudyBuilder_var aStudyBuilder = theStudy->NewBuilder();
  aStudyBuilder->NewCommand();
  if(!aCase->_is_nil())
    aResultSO = PublishCaseInStudy(theStudy, aStudyBuilder, aCase, theName);
  else if(!aHypo->_is_nil())
    aResultSO = PublishHypotheseInStudy(theStudy, aStudyBuilder, aHypo, theName);
  else if(!aZone->_is_nil())
    aResultSO = PublishZoneInStudy(theStudy, aStudyBuilder, aZone, theName);
  else if(!aBoundary->_is_nil())
    aResultSO = PublishBoundaryInStudy(theStudy, aStudyBuilder, aBoundary, theName);

    aStudyBuilder->CommitCommand();
  return aResultSO._retn();
};
//=============================================================================
SALOMEDS::SObject_ptr HOMARD_Gen_i::PublishCaseInStudy(SALOMEDS::Study_ptr theStudy,
                                                       SALOMEDS::StudyBuilder_var aStudyBuilder,
                                                       HOMARD::HOMARD_Cas_ptr theObject, const char* theName)
{
  MESSAGE("PublishCaseInStudy pour "<<theName);
  SALOMEDS::SObject_var aResultSO;
  SALOMEDS::GenericAttribute_var anAttr;

  if (CORBA::is_nil(theObject)) {
    MESSAGE("HOMARD_Gen_i.cxx::theObject->_is_nil()");
    return aResultSO._retn();
  }
  if (theStudy->_is_nil()) {
    MESSAGE("HOMARD_Gen_i.cxx::theStudy->_is_nil()");
    return aResultSO._retn();
  }

  SALOMEDS::SComponent_var theFatherHomard = theStudy->FindComponent(ComponentDataType());
  if (theFatherHomard->_is_nil())
  {
    MESSAGE("theFatherHomard->_is_nil()");
    return aResultSO._retn();
  }

  aResultSO = aStudyBuilder->NewObject(theFatherHomard);
  PublishInStudyAttr(aStudyBuilder, aResultSO, theName, "CasHomard", "cas_calcule.png",
                     _orb->object_to_string(theObject) ) ;
  return aResultSO._retn();
}

//=============================================================================
SALOMEDS::SObject_ptr HOMARD_Gen_i::PublishZoneInStudy(SALOMEDS::Study_ptr theStudy,
                    SALOMEDS::StudyBuilder_var aStudyBuilder,
                   HOMARD::HOMARD_Zone_ptr theObject, const char* theName)
{
  MESSAGE("PublishZoneStudy pour "<<theName);
  SALOMEDS::SObject_var aResultSO;
  SALOMEDS::GenericAttribute_var anAttr;

  if (CORBA::is_nil(theObject))
  {
    MESSAGE("HOMARD_Gen_i.cxx::theObject->_is_nil()");
    return aResultSO._retn();
  }
  if (theStudy->_is_nil())
  {
    MESSAGE("HOMARD_Gen_i.cxx::theStudy->_is_nil()");
    return aResultSO._retn();
  }
  SALOMEDS::SComponent_var theFatherHomard = theStudy->FindComponent(ComponentDataType());
  if (theFatherHomard->_is_nil())
  {
    MESSAGE("theFatherHomard->_is_nil()");
    return aResultSO._retn();
  }

  // Caracteristique de la zone
  HOMARD::HOMARD_Zone_var myZone = myContextMap[GetCurrentStudyID()]._mesZones[theName];
  CORBA::Long ZoneType = myZone->GetZoneType();

  // On ajoute la categorie des zones dans l etude si necessaire
  SALOMEDS::SObject_var aSOZone;
  if (!theFatherHomard->FindSubObject(100, aSOZone))
  {
    MESSAGE("Ajout de la categorie des zones");
    aSOZone = aStudyBuilder->NewObjectToTag(theFatherHomard, 100);
    PublishInStudyAttr(aStudyBuilder, aSOZone, "Zones", "ZoneList", "zone_icone_2.png", NULL ) ;
  }
  else { MESSAGE("La categorie des zones existe deja."); }

  aResultSO = aStudyBuilder->NewObject(aSOZone);
  const char* icone ;
  switch (ZoneType)
  {
    case 11 :
    { }
    case 12 :
    { }
    case 13 :
    { icone = "boxdxy_2.png" ;
      break ;
    }
    case 2 :
    { icone = "boxdxyz_2.png" ;
      break ;
    }
    case 31 :
    { }
    case 32 :
    { }
    case 33 :
    { icone = "disk_2.png" ;
      break ;
     }
    case 4 :
    { icone = "spherepoint_2.png" ;
      break ;
    }
    case 5 :
    { icone = "cylinderpointvector_2.png" ;
      break ;
    }
    case 61 :
    { }
    case 62 :
    { }
    case 63 :
    { icone = "diskwithhole_2.png" ;
      break ;
     }
    case 7 :
    { icone = "pipe_2.png" ;
      break ;
    }
  }
  PublishInStudyAttr(aStudyBuilder, aResultSO, theName, "ZoneHomard", icone, _orb->object_to_string(theObject) ) ;

  return aResultSO._retn();
}
//=============================================================================
SALOMEDS::SObject_ptr HOMARD_Gen_i::PublishBoundaryInStudy(SALOMEDS::Study_ptr theStudy,
                   SALOMEDS::StudyBuilder_var aStudyBuilder,
                   HOMARD::HOMARD_Boundary_ptr theObject, const char* theName)
{
  MESSAGE("PublishBoundaryStudy pour "<<theName);
  SALOMEDS::SObject_var aResultSO;
  SALOMEDS::GenericAttribute_var anAttr;

  // Caracteristique de la Boundary
  HOMARD::HOMARD_Boundary_var myBoundary = myContextMap[GetCurrentStudyID()]._mesBoundarys[theName];

  // On recupere le module pere dans l etude
  SALOMEDS::SComponent_var       theFatherHomard = theStudy->FindComponent(ComponentDataType());
  if (theFatherHomard->_is_nil())
  {
    MESSAGE("theFatherHomard->_is_nil()");
    return aResultSO._retn();
  }

  // On ajoute la categorie des boundarys dans l etude si necessaire
  SALOMEDS::SObject_var aSOBoundary;
  if (!theFatherHomard->FindSubObject(101, aSOBoundary))
  {
    MESSAGE("Ajout de la categorie des boundarys");
    aSOBoundary = aStudyBuilder->NewObjectToTag(theFatherHomard, 101);
    PublishInStudyAttr(aStudyBuilder, aSOBoundary, "Boundaries", "BoundList", "zone_icone_2.png", NULL ) ;
  }
  else { MESSAGE("La categorie des boundarys existe deja."); }

  aResultSO = aStudyBuilder->NewObject(aSOBoundary);
  CORBA::Long BoundaryType = myBoundary->GetBoundaryType();
//   MESSAGE("BoundaryType : "<<BoundaryType);
  const char* icone ;
  const char* value ;
  switch (BoundaryType)
  {
    case 0 :
    { value = "BoundaryDiHomard" ;
      icone = "mesh_tree_mesh.png" ;
      break;
    }
    case 1 :
    { value = "BoundaryAnHomard" ;
      icone = "cylinderpointvector_2.png" ;
      break;
    }
    case 2 :
    { value = "BoundaryAnHomard" ;
      icone = "spherepoint_2.png" ;
      break;
    }
  }
  PublishInStudyAttr(aStudyBuilder, aResultSO, theName, value, icone, _orb->object_to_string(theObject));
  return aResultSO._retn();
}

//=============================================================================
SALOMEDS::SObject_ptr HOMARD_Gen_i::PublishHypotheseInStudy(SALOMEDS::Study_ptr theStudy,
                   SALOMEDS::StudyBuilder_var aStudyBuilder,
                   HOMARD::HOMARD_Hypothesis_ptr theObject, const char* theName)
{
  MESSAGE("PublishHypotheseInStudy pour "<<theName);
  SALOMEDS::SObject_var aResultSO;
  SALOMEDS::GenericAttribute_var anAttr;

  // On recupere le module pere dans l etude
  // On ajoute la categorie des hypotheses dans l etude si necessaire
  SALOMEDS::SComponent_var theFatherHomard = theStudy->FindComponent(ComponentDataType());
  if (theFatherHomard->_is_nil())
  {
    MESSAGE("theFatherHomard->_is_nil()");
    return aResultSO._retn();
  }
  SALOMEDS::SObject_var aSOHypothese;
  if (!theFatherHomard->FindSubObject(0, aSOHypothese))
  {
    MESSAGE("Ajout de la categorie des hypotheses");
    aSOHypothese = aStudyBuilder->NewObjectToTag(theFatherHomard, 0);
    PublishInStudyAttr(aStudyBuilder, aSOHypothese, "Hypothesis", "HypoList","hypotheses.png", NULL);
  }
  else { MESSAGE("La categorie des hypotheses existe deja."); }

// Creation du resultat dans l'etude
  aResultSO = aStudyBuilder->NewObject(aSOHypothese);
  PublishInStudyAttr(aStudyBuilder, aResultSO, theName, "HypoHomard", NULL, _orb->object_to_string(theObject) ) ;

  return aResultSO._retn();
}
//===========================================================================
void HOMARD_Gen_i::PublishInStudyAttr(SALOMEDS::StudyBuilder_var aStudyBuilder,
                                      SALOMEDS::SObject_var aResultSO,
                                      const char* name, const char* value, const char* icone, const char* ior)
{
  SALOMEDS::GenericAttribute_var anAttr ;
//  Ajout du nom
  if ( name != NULL )
  {
    anAttr = aStudyBuilder->FindOrCreateAttribute(aResultSO, "AttributeName");
    SALOMEDS::AttributeName_var aNameAttrib = SALOMEDS::AttributeName::_narrow(anAttr);
    aNameAttrib->SetValue(name);
  }

//  Ajout du commentaire
  if ( value != NULL )
  {
    anAttr = aStudyBuilder->FindOrCreateAttribute(aResultSO, "AttributeComment");
    SALOMEDS::AttributeComment_var aCommentAttrib = SALOMEDS::AttributeComment::_narrow(anAttr);
    aCommentAttrib->SetValue(value);
  }

//  Ajout de l'icone
  if ( icone != NULL  )
  {
    anAttr = aStudyBuilder->FindOrCreateAttribute(aResultSO,"AttributePixMap");
    SALOMEDS::AttributePixMap_var aPixmap = SALOMEDS::AttributePixMap::_narrow(anAttr);
    aPixmap->SetPixMap(icone);
  }

//  Ajout de l ior
  if ( ior != NULL  )
  {
    anAttr = aStudyBuilder->FindOrCreateAttribute(aResultSO, "AttributeIOR");
    SALOMEDS::AttributeIOR_var anIOR = SALOMEDS::AttributeIOR::_narrow(anAttr);
    anIOR->SetValue(ior);
  }
};

//=============================================================================
HOMARD::listeCases* HOMARD_Gen_i::GetAllCases()
{
  MESSAGE("GetAllCases");
  IsValidStudy () ;

  HOMARD::listeCases_var ret = new HOMARD::listeCases;
  ret->length(myContextMap[GetCurrentStudyID()]._mesCas.size());
  std::map<std::string, HOMARD::HOMARD_Cas_var>::const_iterator it;
  int i = 0;
  for (it  = myContextMap[GetCurrentStudyID()]._mesCas.begin();
	it != myContextMap[GetCurrentStudyID()]._mesCas.end(); it++)
  {
    ret[i++] = CORBA::string_dup((*it).first.c_str());
  }

  return ret._retn();
}

//=============================================================================
HOMARD::listeHypotheses* HOMARD_Gen_i::GetAllHypotheses()
{
  MESSAGE("GetAllHypotheses");
  IsValidStudy () ;

  HOMARD::listeHypotheses_var ret = new HOMARD::listeHypotheses;
  ret->length(myContextMap[GetCurrentStudyID()]._mesHypotheses.size());
  std::map<std::string, HOMARD::HOMARD_Hypothesis_var>::const_iterator it;
  int i = 0;
  for (it  = myContextMap[GetCurrentStudyID()]._mesHypotheses.begin();
  it != myContextMap[GetCurrentStudyID()]._mesHypotheses.end(); it++)
  {
    ret[i++] = CORBA::string_dup((*it).first.c_str());
  }

  return ret._retn();
}

//=============================================================================
HOMARD::listeZones* HOMARD_Gen_i::GetAllZones()
{
  MESSAGE("GetAllZones");
  IsValidStudy () ;

  HOMARD::listeZones_var ret = new HOMARD::listeZones;
  ret->length(myContextMap[GetCurrentStudyID()]._mesZones.size());
  std::map<std::string, HOMARD::HOMARD_Zone_var>::const_iterator it;
  int i = 0;
  for (it  = myContextMap[GetCurrentStudyID()]._mesZones.begin();
  it != myContextMap[GetCurrentStudyID()]._mesZones.end(); it++)
  {
    ret[i++] = CORBA::string_dup((*it).first.c_str());
  }

  return ret._retn();
}

//=============================================================================
HOMARD::listeIterations* HOMARD_Gen_i::GetAllIterations()
{
  MESSAGE("GetAllIterations");
  IsValidStudy () ;

  HOMARD::listeIterations_var ret = new HOMARD::listeIterations;
  ret->length(myContextMap[GetCurrentStudyID()]._mesIterations.size());
  std::map<std::string, HOMARD::HOMARD_Iteration_var>::const_iterator it;
  int i = 0;
  for (it  = myContextMap[GetCurrentStudyID()]._mesIterations.begin();
  it != myContextMap[GetCurrentStudyID()]._mesIterations.end(); it++)
  {
    ret[i++] = CORBA::string_dup((*it).first.c_str());
  }

  return ret._retn();
}
//=============================================================================
HOMARD::listeBoundarys* HOMARD_Gen_i::GetAllBoundarys()
{
  MESSAGE("GetAllBoundarys");
  IsValidStudy () ;

  HOMARD::listeBoundarys_var ret = new HOMARD::listeBoundarys;
  ret->length(myContextMap[GetCurrentStudyID()]._mesBoundarys.size());
  std::map<std::string, HOMARD::HOMARD_Boundary_var>::const_iterator it;
  int i = 0;
  for (it  = myContextMap[GetCurrentStudyID()]._mesBoundarys.begin();
  it != myContextMap[GetCurrentStudyID()]._mesBoundarys.end(); it++)
  {
    ret[i++] = CORBA::string_dup((*it).first.c_str());
  }

  return ret._retn();
}

//=============================================================================
char* HOMARD_Gen_i::GetCaseName(const char* nomIteration)
{
  if (CORBA::is_nil(myCurrentStudy))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Study Context ";
      throw SALOME::SALOME_Exception(es);
      return 0;
  };

  HOMARD::HOMARD_Iteration_var monIter = myContextMap[GetCurrentStudyID()]._mesIterations[nomIteration];
  ASSERT(!CORBA::is_nil(monIter));
  return CORBA::string_dup(monIter->GetCaseName());
}
//=============================================================================
void HOMARD_Gen_i::PublishResultInSmesh(const char* NomFich, CORBA::Long IconeType)
{
  MESSAGE( "PublishResultInSmesh " << NomFich);
  if (CORBA::is_nil(myCurrentStudy))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Study Context ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

// Le module SMESH est-il actif ?
  SALOMEDS::SObject_var aSmeshSO = myCurrentStudy->FindComponent("SMESH");
//
  if (!CORBA::is_nil(aSmeshSO))
  {
// On verifie que le fichier n est pas deja publie
    SALOMEDS::ChildIterator_var aIter = myCurrentStudy->NewChildIterator(aSmeshSO);
    for (; aIter->More(); aIter->Next())
    {
       SALOMEDS::SObject_var  aSO = aIter->Value();
       SALOMEDS::GenericAttribute_var aGAttr;
       if (aSO->FindAttribute(aGAttr,"AttributeExternalFileDef"))
       {
           SALOMEDS::AttributeExternalFileDef_var anAttr = SALOMEDS::AttributeExternalFileDef::_narrow(aGAttr);
           CORBA::String_var value=anAttr->Value();
           if (strcmp((const char*)value,NomFich) == 0)
           {
                // GERALD -- QMESSAGE BOX
                std::cerr << "fichier : "<< NomFich << " deja publie "<< std::endl;
                return;
           }
       }
     }

  }

// On enregistre le fichier
  MESSAGE( "Enregistrement du fichier");
  SALOME_LifeCycleCORBA* myLCC = new SALOME_LifeCycleCORBA(_NS);
  SMESH::SMESH_Gen_var aSmeshEngine = SMESH::SMESH_Gen::_narrow(myLCC->FindOrLoad_Component("FactoryServer","SMESH"));
  ASSERT(!CORBA::is_nil(aSmeshEngine));
  aSmeshEngine->SetCurrentStudy(myCurrentStudy);
  SMESH::DriverMED_ReadStatus theStatus;
  //aSmeshEngine->CreateMeshesFromMED(NomFich, theStatus);

// On met a jour les attributs AttributeExternalFileDef et AttributePixMap
  SMESH::mesh_array* mesMaillages=aSmeshEngine->CreateMeshesFromMED(NomFich, theStatus);
  for (int i = 0; i < mesMaillages->length();  i++)
  {
    MESSAGE( ". Mise a jour des attributs du maillage");
    SMESH::SMESH_Mesh_var monMaillage= (*mesMaillages)[i];
    SALOMEDS::SObject_var aSO=SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(monMaillage)));
    SALOMEDS::StudyBuilder_var aStudyBuilder = myCurrentStudy->NewBuilder();
    SALOMEDS::GenericAttribute_var aGAttr = aStudyBuilder->FindOrCreateAttribute(aSO, "AttributeExternalFileDef");
    SALOMEDS::AttributeExternalFileDef_var anAttr = SALOMEDS::AttributeExternalFileDef::_narrow(aGAttr);
    anAttr->SetValue(NomFich);
    SALOMEDS::GenericAttribute_var aPixMap = aStudyBuilder->FindOrCreateAttribute(aSO, "AttributePixMap" );
    SALOMEDS::AttributePixMap_var anAttr2 = SALOMEDS::AttributePixMap::_narrow(aPixMap);
//  IconeType = 0 : fichier issu d'une importation
//  IconeType = 1 : fichier issu d'une execution HOMARD
    const char* icone ;
    if ( IconeType == 0 ) { icone = "mesh_tree_importedmesh.png" ; }
    else                  { icone = "mesh_tree_mesh.png" ; }
    anAttr2->SetPixMap( icone );
  }

}
//=============================================================================
void HOMARD_Gen_i::DeleteResultInSmesh(const char* NomFich, const char* MeshName)
{
  MESSAGE (" DeleteResultInSmesh pour "<< NomFich << "et le maillage "<< MeshName);
  if (CORBA::is_nil(myCurrentStudy))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Study Context ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

// Le module SMESH est-il actif ?
  SALOMEDS::SObject_var aSmeshSO = myCurrentStudy->FindComponent("SMESH");
//
  if (CORBA::is_nil(aSmeshSO))
  {
      return ;
  };
// On verifie que le fichier est deja publie
  SALOMEDS::StudyBuilder_var myBuilder = myCurrentStudy->NewBuilder();
  SALOMEDS::ChildIterator_var aIter = myCurrentStudy->NewChildIterator(aSmeshSO);
  for (; aIter->More(); aIter->Next())
  {
     SALOMEDS::SObject_var  aSO = aIter->Value();
     SALOMEDS::GenericAttribute_var aGAttr;
     if (aSO->FindAttribute(aGAttr,"AttributeExternalFileDef"))
     {
       SALOMEDS::AttributeExternalFileDef_var anAttr = SALOMEDS::AttributeExternalFileDef::_narrow(aGAttr);
       CORBA::String_var value=anAttr->Value();
       if (strcmp((const char*)value,NomFich) == 0)
       {
         if (aSO->FindAttribute(aGAttr,"AttributeName"))
         {
           SALOMEDS::AttributeName_var anAttr2 = SALOMEDS::AttributeName::_narrow(aGAttr);
           CORBA::String_var value2=anAttr2->Value();
           if (strcmp((const char*)value2,MeshName) == 0)
           {
             myBuilder->RemoveObjectWithChildren( aSO ) ;
           }
         }
       }
     }
  }

}
//=============================================================================
void HOMARD_Gen_i::PublishFileUnderIteration(const char* NomIter, const char* NomFich, const char* Commentaire)
{
  if (CORBA::is_nil(myCurrentStudy))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Study Context ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

  HOMARD::HOMARD_Iteration_var myIteration = myContextMap[GetCurrentStudyID()]._mesIterations[NomIter];
  if (CORBA::is_nil(myIteration))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Iteration ";
      throw SALOME::SALOME_Exception(es);
      return ;
  };
  SALOMEDS::SObject_var aIterSO=SALOMEDS::SObject::_narrow(myCurrentStudy->FindObjectIOR(_orb->object_to_string(myIteration)));
  if (CORBA::is_nil(myIteration))
  {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid Iteration Study Object";
      throw SALOME::SALOME_Exception(es);
      return ;
  };

  SALOMEDS::StudyBuilder_var aStudyBuilder = myCurrentStudy->NewBuilder();

  aStudyBuilder->NewCommand();

  SALOMEDS::SObject_var aSubSO = aStudyBuilder->NewObject(aIterSO);
// Pour les fichiers med, on affiche une icone de maillage
// Pour les fichiers qui sont texte, on affiche une icone de fichier texte 'texte'
// Le reperage se fait par la 1ere lettre du commentaire : I pour Iteration n
  const char* icone ;
  const char* ior = " " ;
  if ( Commentaire[0] == 'I' )
  { icone = "med.png" ; }
  else
  { icone = "texte_2.png" ; }
  PublishInStudyAttr(aStudyBuilder, aSubSO, NomFich, Commentaire, icone, ior ) ;

  aStudyBuilder->CommitCommand();
}

//=====================================================================================
void HOMARD_Gen_i::IsValidStudy( )
//=====================================================================================
{
  MESSAGE( "IsValidStudy" );
  if (CORBA::is_nil(myCurrentStudy))
  {
    SALOME::ExceptionStruct es;
    es.type = SALOME::BAD_PARAM;
    es.text = "Invalid Study Context";
    throw SALOME::SALOME_Exception(es);
  };
  return ;
}

//===========================================================================
//
// Next functions are inherited from SALOMEDS::Driver interface
//
//===========================================================================

//===========================================================================
SALOMEDS::TMPFile* HOMARD_Gen_i::Save(SALOMEDS::SComponent_ptr theComponent,
                                      const char* theURL,
                                      CORBA::Boolean isMultiFile)
{
  MESSAGE (" Save pour theURL = "<< theURL);
  SALOMEDS::TMPFile_var aStreamFile;

  // get temporary directory name
  std::string tmpDir = isMultiFile ? std::string(theURL) : SALOMEDS_Tool::GetTmpDir();

  SALOMEDS::Study_var aStudy = theComponent->GetStudy();
  StudyContext& context = myContextMap[ aStudy->StudyId() ];

  // HOMARD data file name
  std::string aFileName = "";
  if (isMultiFile)
    aFileName = SALOMEDS_Tool::GetNameFromPath(aStudy->URL());
  aFileName += "_HOMARD.dat";

  // initialize sequence of file names
  SALOMEDS::ListOfFileNames_var aFileSeq = new SALOMEDS::ListOfFileNames;
  aFileSeq->length(1);
  aFileSeq[0] = CORBA::string_dup(aFileName.c_str()) ;

  // get full path to the data file
  aFileName = tmpDir + aFileName;

  // save data
  // -> create file
  std::ofstream f(aFileName.c_str());

  // clear temporary id map
  context._idmap.clear();

  int id = 1;

  // -> dump cases
  std::map<std::string, HOMARD::HOMARD_Cas_var>::const_iterator it_case;
  for (it_case = context._mesCas.begin(); it_case != context._mesCas.end(); ++it_case) {
    HOMARD::HOMARD_Cas_var aCas = it_case->second;
    PortableServer::ServantBase_var aServant = GetServant(aCas);
    HOMARD_Cas_i* aCasServant = dynamic_cast<HOMARD_Cas_i*>(aServant.in());
    if (aCasServant) {
      f << HOMARD::GetSignature(HOMARD::Case) << aCasServant->Dump() << std::endl;
      context._idmap[id++] = dynamic_cast<PortableServer::ServantBase*>(aCasServant);
    }
  }
  // -> dump zones
  std::map<std::string, HOMARD::HOMARD_Zone_var>::const_iterator it_zone;
  for (it_zone = context._mesZones.begin(); it_zone != context._mesZones.end(); ++it_zone) {
    HOMARD::HOMARD_Zone_var aZone = it_zone->second;
    PortableServer::ServantBase_var aServant = GetServant(aZone);
    HOMARD_Zone_i* aZoneServant = dynamic_cast<HOMARD_Zone_i*>(aServant.in());
    if (aZoneServant) {
      f << HOMARD::GetSignature(HOMARD::Zone) << aZoneServant->Dump() << std::endl;
      context._idmap[id++] = dynamic_cast<PortableServer::ServantBase*>(aZoneServant);
    }
  }
  // -> dump hypotheses
  std::map<std::string, HOMARD::HOMARD_Hypothesis_var>::const_iterator it_hypo;
  for (it_hypo = context._mesHypotheses.begin(); it_hypo != context._mesHypotheses.end(); ++it_hypo) {
    HOMARD::HOMARD_Hypothesis_var aHypo = it_hypo->second;
    PortableServer::ServantBase_var aServant = GetServant(aHypo);
    HOMARD_Hypothesis_i* aHypoServant = dynamic_cast<HOMARD_Hypothesis_i*>(aServant.in());
    if (aHypoServant) {
      f << HOMARD::GetSignature(HOMARD::Hypothesis) << aHypoServant->Dump() << std::endl;
      context._idmap[id++] = dynamic_cast<PortableServer::ServantBase*>(aHypoServant);
    }
  }
  // -> dump iterations
  std::map<std::string, HOMARD::HOMARD_Iteration_var>::const_iterator it_iter;
  for (it_iter = context._mesIterations.begin(); it_iter != context._mesIterations.end(); ++it_iter) {
    HOMARD::HOMARD_Iteration_var aIter = it_iter->second;
    PortableServer::ServantBase_var aServant = GetServant(aIter);
    HOMARD_Iteration_i* aIterServant = dynamic_cast<HOMARD_Iteration_i*>(aServant.in());
    if (aIterServant) {
      f << HOMARD::GetSignature(HOMARD::Iteration) << aIterServant->Dump() << std::endl;
      context._idmap[id++] = dynamic_cast<PortableServer::ServantBase*>(aIterServant);
    }
  }
  // -> dump boundaries
  std::map<std::string, HOMARD::HOMARD_Boundary_var>::const_iterator it_boundary;
  for (it_boundary = context._mesBoundarys.begin(); it_boundary != context._mesBoundarys.end(); ++it_boundary) {
    HOMARD::HOMARD_Boundary_var aBoundary = it_boundary->second;
    PortableServer::ServantBase_var aServant = GetServant(aBoundary);
    HOMARD_Boundary_i* aBoundaryServant = dynamic_cast<HOMARD_Boundary_i*>(aServant.in());
    if (aBoundaryServant) {
      f << HOMARD::GetSignature(HOMARD::Boundary) << aBoundaryServant->Dump() << std::endl;
      context._idmap[id++] = dynamic_cast<PortableServer::ServantBase*>(aBoundaryServant);
    }
  }
  // -> close file
  MESSAGE ("close file");
  f.close();

  // put temporary files to the stream
  MESSAGE ("put temporary files to the stream");
  aStreamFile = SALOMEDS_Tool::PutFilesToStream(tmpDir.c_str(), aFileSeq.in(), isMultiFile);

  // remove temporary files
  MESSAGE ("remove temporary files");
  if (!isMultiFile) SALOMEDS_Tool::RemoveTemporaryFiles(tmpDir.c_str(), aFileSeq.in(), true);

  // return data stream
  MESSAGE ("return data stream");
  return aStreamFile._retn();
};

//===========================================================================
SALOMEDS::TMPFile* HOMARD_Gen_i::SaveASCII(SALOMEDS::SComponent_ptr theComponent,
                                           const char* theURL,
                                           CORBA::Boolean isMultiFile)
{
  // No specific ASCII persistence
  SALOMEDS::TMPFile_var aStreamFile = Save(theComponent, theURL, isMultiFile);
  return aStreamFile._retn();
};

//===========================================================================
CORBA::Boolean HOMARD_Gen_i::Load(SALOMEDS::SComponent_ptr theComponent,
				   const SALOMEDS::TMPFile& theStream,
				   const char* theURL,
				   CORBA::Boolean isMultiFile)
{
  MESSAGE (" Load pour theURL = "<< theURL);
  SALOMEDS::Study_var aStudy = theComponent->GetStudy();

  // set current study
  if (myCurrentStudy->_is_nil() || aStudy->StudyId() != myCurrentStudy->StudyId())
    SetCurrentStudy(aStudy);

  // get temporary directory name
  std::string tmpDir = isMultiFile ? std::string(theURL) : SALOMEDS_Tool::GetTmpDir();

  // Convert the stream into sequence of files to process
  SALOMEDS::ListOfFileNames_var aFileSeq = SALOMEDS_Tool::PutStreamToFiles(theStream,
                                                                            tmpDir.c_str(),
                                                                            isMultiFile);
  // HOMARD data file name
  std::string aFileName = "";
  if (isMultiFile)
    aFileName = SALOMEDS_Tool::GetNameFromPath(aStudy->URL());
  aFileName = tmpDir + aFileName + "_HOMARD.dat";

  StudyContext& context = myContextMap[ aStudy->StudyId() ];

  // save data
  // -> create file
  std::ifstream f(aFileName.c_str());

  // clear context
  context._mesCas.clear();
  context._mesHypotheses.clear();
  context._mesIterations.clear();
  context._mesZones.clear();
  context._mesBoundarys.clear();
  context._idmap.clear();

  int id = 1;
  std::string line;

  while (f) {
    std::getline(f, line);
    std::string caseSignature = HOMARD::GetSignature(HOMARD::Case);
    std::string zoneSignature = HOMARD::GetSignature(HOMARD::Zone);
    std::string iterSignature = HOMARD::GetSignature(HOMARD::Iteration);
    std::string hypoSignature = HOMARD::GetSignature(HOMARD::Hypothesis);
    std::string bounSignature = HOMARD::GetSignature(HOMARD::Boundary);
    if (line.substr(0, caseSignature.size()) == caseSignature) {
      // re-create case
      MESSAGE (" Recreation du cas" );
      HOMARD::HOMARD_Cas_var aCase = newCase();
      PortableServer::ServantBase_var aServant = GetServant(aCase);
      HOMARD_Cas_i* aCaseServant = dynamic_cast<HOMARD_Cas_i*>(aServant.in());
      if (aCaseServant && aCaseServant->Restore(line.substr(caseSignature.size()))) {
        context._mesCas[aCase->GetName()] = aCase;
        context._idmap[id] = dynamic_cast<PortableServer::ServantBase*>(aCaseServant);
      }
    }
    else if (line.substr(0, zoneSignature.size()) == zoneSignature) {
      MESSAGE (" Recreation de la zone" );
      // re-create zone
      HOMARD::HOMARD_Zone_var aZone = newZone();
      PortableServer::ServantBase_var aServant = GetServant(aZone);
      HOMARD_Zone_i* aZoneServant = dynamic_cast<HOMARD_Zone_i*>(aServant.in());
      if (aZoneServant && aZoneServant->Restore(line.substr(zoneSignature.size()))) {
        context._mesZones[aZone->GetName()] = aZone;
        context._idmap[id] = dynamic_cast<PortableServer::ServantBase*>(aZoneServant);
      }
    }
    else if (line.substr(0, iterSignature.size()) == iterSignature) {
      // re-create iteration
      MESSAGE (" Recreation de l iteration" );
      HOMARD::HOMARD_Iteration_var aIter = newIteration();
      PortableServer::ServantBase_var aServant = GetServant(aIter);
      HOMARD_Iteration_i* aIterServant = dynamic_cast<HOMARD_Iteration_i*>(aServant.in());
      if (aIterServant && aIterServant->Restore(line.substr(iterSignature.size()))) {
        context._mesIterations[aIter->GetName()] = aIter;
        context._idmap[id] = dynamic_cast<PortableServer::ServantBase*>(aIterServant);
      }
    }
    else if (line.substr(0, hypoSignature.size()) == hypoSignature) {
      // re-create hypothesis
      MESSAGE (" Recreation de l hypothese" );
      HOMARD::HOMARD_Hypothesis_var aHypo = newHypothesis();
      PortableServer::ServantBase_var aServant = GetServant(aHypo);
      HOMARD_Hypothesis_i* aHypoServant = dynamic_cast<HOMARD_Hypothesis_i*>(aServant.in());
      if (aHypoServant && aHypoServant->Restore(line.substr(hypoSignature.size()))) {
        context._mesHypotheses[aHypo->GetName()] = aHypo;
        context._idmap[id] = dynamic_cast<PortableServer::ServantBase*>(aHypoServant);
      }
    }
    else if (line.substr(0, bounSignature.size()) == bounSignature) {
      // re-create boundary
      MESSAGE (" Recreation de la frontiere" );
      HOMARD::HOMARD_Boundary_var aBoundary = newBoundary();
      PortableServer::ServantBase_var aServant = GetServant(aBoundary);
      HOMARD_Boundary_i* aBoundaryServant = dynamic_cast<HOMARD_Boundary_i*>(aServant.in());
      if (aBoundaryServant && aBoundaryServant->Restore(line.substr(bounSignature.size()))) {
        context._mesBoundarys[aBoundary->GetName()] = aBoundary;
        context._idmap[id] = dynamic_cast<PortableServer::ServantBase*>(aBoundaryServant);
      }
    }
    id++;
  }

  // -> close file
  f.close();

  // Remove temporary files created from the stream
  if (!isMultiFile)
    SALOMEDS_Tool::RemoveTemporaryFiles(tmpDir.c_str(), aFileSeq.in(), true);

  return true;
};

//===========================================================================
CORBA::Boolean HOMARD_Gen_i::LoadASCII(SALOMEDS::SComponent_ptr theComponent,
					const SALOMEDS::TMPFile& theStream,
					const char* theURL,
					CORBA::Boolean isMultiFile)
{
  // No specific ASCII persistence
  return Load(theComponent, theStream, theURL, isMultiFile);
};

//===========================================================================
void HOMARD_Gen_i::Close(SALOMEDS::SComponent_ptr theComponent)
{
  if (theComponent->GetStudy()->StudyId() == GetCurrentStudyID()) {
    // clearing study context should be done here:
    // - destroy all servants and related CORBA objects
    // ... (TODO)
    // - remove context from myContextMap
    myContextMap.erase(theComponent->GetStudy()->StudyId());
    // - nullify myCurrentStudy
    myCurrentStudy = SALOMEDS::Study::_nil();
  }
};

//===========================================================================
char* HOMARD_Gen_i::ComponentDataType()
{
  return CORBA::string_dup("HOMARD");
};

//===========================================================================
char* HOMARD_Gen_i::IORToLocalPersistentID(SALOMEDS::SObject_ptr theSObject,
					    const char* IORString,
					    CORBA::Boolean isMultiFile,
					    CORBA::Boolean isASCII)
{
  CORBA::String_var aString("");
  if (!CORBA::is_nil(theSObject) && strcmp(IORString, "") != 0) {
    StudyContext context = myContextMap[ theSObject->GetStudy()->StudyId() ];
    CORBA::Object_var anObj = _orb->string_to_object(IORString);
    if (!CORBA::is_nil(anObj)) {
      PortableServer::ServantBase_var aServant = GetServant(anObj);
      PortableServer::ServantBase* aStorable = dynamic_cast<PortableServer::ServantBase*>(aServant.in());
      if (aStorable) {
	std::map<int, PortableServer::ServantBase*>::const_iterator it;
	for (it = context._idmap.begin(); it != context._idmap.end(); ++it) {
	  if (it->second == aStorable) {
	    std::stringstream os;
	    os << it->first;
	    aString = CORBA::string_dup(os.str().c_str());
	  }
	}
      }
    }
  }
  return aString._retn();
};

//===========================================================================
char* HOMARD_Gen_i::LocalPersistentIDToIOR(SALOMEDS::SObject_ptr theSObject,
					    const char* aLocalPersistentID,
					    CORBA::Boolean isMultiFile,
					    CORBA::Boolean isASCII)
{
  CORBA::String_var aString("");
  if (!CORBA::is_nil(theSObject) && strcmp(aLocalPersistentID, "") != 0) {
    StudyContext context = myContextMap[ theSObject->GetStudy()->StudyId() ];
    int id = atoi(aLocalPersistentID);
    if (id > 0 && context._idmap.find(id) != context._idmap.end()) {
      CORBA::Object_var object = _poa->servant_to_reference(context._idmap[ id ]);
      if (!CORBA::is_nil(object)) {
	aString = _orb->object_to_string(object);
      }
    }
  }
  return aString._retn();
};

//===========================================================================
CORBA::Boolean HOMARD_Gen_i::CanPublishInStudy(CORBA::Object_ptr theIOR)
{
  if(CORBA::is_nil(myCurrentStudy))
    return false;

  HOMARD::HOMARD_Cas_var aCas = HOMARD::HOMARD_Cas::_narrow(theIOR);
  if(!aCas->_is_nil())
    return true;

  HOMARD::HOMARD_Hypothesis_var aHypo = HOMARD::HOMARD_Hypothesis::_narrow(theIOR);
  if(!aHypo->_is_nil())
    return true;

  HOMARD::HOMARD_Zone_var aZone = HOMARD::HOMARD_Zone::_narrow(theIOR);
  if(!aZone->_is_nil())
    return true;

  HOMARD::HOMARD_Boundary_var aBoundary = HOMARD::HOMARD_Boundary::_narrow(theIOR);
  if(!aBoundary->_is_nil())
    return true;

  /* Iteration is not published directly
  HOMARD::HOMARD_Iteration_var aIter = HOMARD::HOMARD_Iteration::_narrow(theIOR);
  if(!aIter->_is_nil())
    return true;
  */
  return false;
};

//===========================================================================
CORBA::Boolean HOMARD_Gen_i::CanCopy(SALOMEDS::SObject_ptr theObject)
{
  // No Copy/Paste support
  return false;
};

//===========================================================================
SALOMEDS::TMPFile* HOMARD_Gen_i::CopyFrom(SALOMEDS::SObject_ptr theObject,
					   CORBA::Long& theObjectID)
{
  // No Copy/Paste support
  SALOMEDS::TMPFile_var aStreamFile = new SALOMEDS::TMPFile(0);
  return aStreamFile._retn();
};

//===========================================================================
CORBA::Boolean  HOMARD_Gen_i::CanPaste(const char *theComponentName,
					CORBA::Long theObjectID)
{
  // No Copy/Paste support
  return false;
};

//===========================================================================
SALOMEDS::SObject_ptr HOMARD_Gen_i::PasteInto(const SALOMEDS::TMPFile& theStream,
					       CORBA::Long theObjectID,
					       SALOMEDS::SObject_ptr theSObject)
{
  // No Copy/Paste support
  SALOMEDS::SObject_var aResultSO;
  return aResultSO._retn();
};

//===========================================================================
PortableServer::ServantBase_var HOMARD_Gen_i::GetServant(CORBA::Object_ptr theObject)
{
  PortableServer::Servant aServant = 0;
  if (!CORBA::is_nil(theObject)) {
    try {
      aServant = _poa->reference_to_servant(theObject);
    }
    catch (...) {
    }
  }
  return aServant;
}

//===========================================================================
HOMARD::HOMARD_Cas_ptr HOMARD_Gen_i::newCase()
{
  HOMARD::HOMARD_Gen_var engine = POA_HOMARD::HOMARD_Gen::_this();
  HOMARD_Cas_i* aServant = new HOMARD_Cas_i(_orb, engine);
  HOMARD::HOMARD_Cas_var aCase = HOMARD::HOMARD_Cas::_narrow(aServant->_this());
  return aCase._retn();
}

//===========================================================================
HOMARD::HOMARD_Hypothesis_ptr HOMARD_Gen_i::newHypothesis()
{
  HOMARD::HOMARD_Gen_var engine = POA_HOMARD::HOMARD_Gen::_this();
  HOMARD_Hypothesis_i* aServant = new HOMARD_Hypothesis_i(_orb, engine);
  HOMARD::HOMARD_Hypothesis_var aHypo = HOMARD::HOMARD_Hypothesis::_narrow(aServant->_this());
  return aHypo._retn();
}

//===========================================================================
HOMARD::HOMARD_Iteration_ptr HOMARD_Gen_i::newIteration()
{
  HOMARD::HOMARD_Gen_var engine = POA_HOMARD::HOMARD_Gen::_this();
  HOMARD_Iteration_i* aServant = new HOMARD_Iteration_i(_orb, engine);
  HOMARD::HOMARD_Iteration_var aIter = HOMARD::HOMARD_Iteration::_narrow(aServant->_this());
  return aIter._retn();
}

//===========================================================================
HOMARD::HOMARD_Boundary_ptr HOMARD_Gen_i::newBoundary()
{
  HOMARD::HOMARD_Gen_var engine = POA_HOMARD::HOMARD_Gen::_this();
  HOMARD_Boundary_i* aServant = new HOMARD_Boundary_i(_orb, engine);
  HOMARD::HOMARD_Boundary_var aBoundary = HOMARD::HOMARD_Boundary::_narrow(aServant->_this());
  return aBoundary._retn();
}
//===========================================================================
HOMARD::HOMARD_Zone_ptr HOMARD_Gen_i::newZone()
{
  HOMARD::HOMARD_Gen_var engine = POA_HOMARD::HOMARD_Gen::_this();
  HOMARD_Zone_i* aServant = new HOMARD_Zone_i(_orb, engine);
  HOMARD::HOMARD_Zone_var aZone = HOMARD::HOMARD_Zone::_narrow(aServant->_this());
  return aZone._retn();
}
//==========================================================================
Engines::TMPFile* HOMARD_Gen_i::DumpPython(CORBA::Object_ptr theStudy,
                                       CORBA::Boolean isPublished,
                                       CORBA::Boolean isMultiFile,
                                       CORBA::Boolean& isValidScript)
{
   MESSAGE ("Entree dans DumpPython");
   isValidScript=1;
   SALOMEDS::Study_var aStudy = SALOMEDS::Study::_narrow(theStudy);
   if(CORBA::is_nil(aStudy))
     return new Engines::TMPFile(0);

   SALOMEDS::SObject_var aSO = aStudy->FindComponent("HOMARD");
   if(CORBA::is_nil(aSO))
      return new Engines::TMPFile(0);

   std::string aScript = "\"\"\"\n";
   aScript += "Python script for HOMARD\n";
   aScript += "Copyright EDF-R&D 2010\n";
   aScript += "\"\"\"\n";
   aScript += "__revision__ = \"V1.2\"\n";
   aScript += "import HOMARD\n";
   if( isMultiFile )
      aScript += "import salome\n";
   aScript += "homard = salome.lcc.FindOrLoadComponent('FactoryServer','HOMARD')\n";
   if( isMultiFile ) {
      aScript += "def RebuildData(theStudy):\n";
      aScript += "\thomard.SetCurrentStudy(theStudy)\n";
   }
   else
      aScript += "\thomard.SetCurrentStudy(salome.myStudy)\n";


   if (myContextMap[GetCurrentStudyID()]._mesBoundarys.size() > 0)
   {
    aScript += "#\n# Creation of the boundaries";
    aScript +=  "\n# ==========================";
   }
   std::map<std::string, HOMARD::HOMARD_Boundary_var>::const_iterator it_boundary;
   for (it_boundary  = myContextMap[GetCurrentStudyID()]._mesBoundarys.begin();
        it_boundary != myContextMap[GetCurrentStudyID()]._mesBoundarys.end(); ++it_boundary)
   {
    HOMARD::HOMARD_Boundary_var maBoundary = (*it_boundary).second;
    CORBA::String_var dumpCorbaBoundary = maBoundary->GetDumpPython();
    std::string dumpBoundary = dumpCorbaBoundary.in();
    aScript+=dumpBoundary;
   }


   if (myContextMap[GetCurrentStudyID()]._mesZones.size() > 0)
   {
    aScript += "#\n# Creation of the zones";
    aScript +=  "\n# =====================";
   }
   std::map<std::string, HOMARD::HOMARD_Zone_var>::const_iterator it_zone;
   for ( it_zone  = myContextMap[GetCurrentStudyID()]._mesZones.begin();
         it_zone != myContextMap[GetCurrentStudyID()]._mesZones.end(); ++it_zone)
   {
    HOMARD::HOMARD_Zone_var maZone = (*it_zone).second;
    CORBA::String_var dumpCorbaZone = maZone->GetDumpPython();
    std::string dumpZone = dumpCorbaZone.in();
    aScript+=dumpZone;
   }


   aScript += "#\n# Creation of the hypotheses";
   aScript +=  "\n# ==========================";
   std::map<std::string, HOMARD::HOMARD_Hypothesis_var>::const_iterator it_hypo;
   for ( it_hypo  = myContextMap[GetCurrentStudyID()]._mesHypotheses.begin();
         it_hypo != myContextMap[GetCurrentStudyID()]._mesHypotheses.end(); it_hypo++)
   {
    HOMARD::HOMARD_Hypothesis_var monHypo = (*it_hypo).second;
    CORBA::String_var dumpCorbaHypo = monHypo->GetDumpPython();
    std::string dumpHypo = dumpCorbaHypo.in();
    aScript+=dumpHypo;
   }


   aScript += "#\n# Creation of the cases";
   aScript += "\n# =====================";
   std::map<std::string, HOMARD::HOMARD_Cas_var>::const_iterator it_cas;
   for (it_cas  = myContextMap[GetCurrentStudyID()]._mesCas.begin();
        it_cas != myContextMap[GetCurrentStudyID()]._mesCas.end(); it_cas++)
        {
           std::string nomCas = (*it_cas).first;
           std::string dumpCas = std::string("\n# Creation of the case ") ;
           dumpCas +=  nomCas + std::string("\n");
           dumpCas += std::string("\t") + nomCas;
           dumpCas += std::string(" = homard.CreateCase('") + nomCas + std::string("', '");

           HOMARD::HOMARD_Cas_var myCase = (*it_cas).second;
           CORBA::String_var cIter0= myCase->GetIter0Name();
           std::string iter0 = cIter0.in();

           HOMARD::HOMARD_Iteration_var myIteration = myContextMap[GetCurrentStudyID()]._mesIterations[iter0];
           CORBA::String_var cMesh0= myIteration->GetMeshFile();
           std::string mesh0 = cMesh0.in();
           CORBA::String_var cMeshName0= myIteration->GetMeshName();
           std::string meshName0 = cMeshName0.in();
           dumpCas += meshName0 + std::string("', '")+ mesh0 + std::string("')\n");
           CORBA::String_var dumpCorbaCase = myCase->GetDumpPython();
           std::string dumpCas2= dumpCorbaCase.in();

           aScript+=dumpCas + dumpCas2;
        };


   aScript += "#\n# Creation of the iterations" ;
   aScript += "\n# ==========================";
   std::map<std::string, HOMARD::HOMARD_Iteration_var>::const_iterator it_iter;
   for (it_iter  = myContextMap[GetCurrentStudyID()]._mesIterations.begin();
        it_iter != myContextMap[GetCurrentStudyID()]._mesIterations.end(); ++it_iter)
   {
    HOMARD::HOMARD_Iteration_var aIter = (*it_iter).second;
    CORBA::String_var dumpCorbaIter = aIter->GetDumpPython();
    std::string dumpIter = dumpCorbaIter.in();
    aScript+=dumpIter;
   }

    if( isMultiFile )
      aScript += "\n\tpass";
    aScript += "\n";

    if( !isMultiFile ) // remove unnecessary tabulation
      aScript = RemoveTabulation( aScript );

   const size_t aLen = strlen(aScript.c_str());
   char* aBuffer = new char[aLen+1];
   strcpy(aBuffer, aScript.c_str());

   CORBA::Octet* anOctetBuf =  (CORBA::Octet*)aBuffer;
   Engines::TMPFile_var aStreamFile = new Engines::TMPFile(aLen+1, aLen+1, anOctetBuf, 1);

   return aStreamFile._retn();
}

//=============================================================================
extern "C"
{
  PortableServer::ObjectId* HOMARDEngine_factory(CORBA::ORB_ptr orb,
						  PortableServer::POA_ptr poa,
						  PortableServer::ObjectId* contId,
						  const char* instanceName,
						  const char* interfaceName)
  {
    MESSAGE("PortableServer::ObjectId* HOMARDEngine_factory()");
    HOMARD_Gen_i* myHOMARD_Gen = new HOMARD_Gen_i(orb, poa, contId, instanceName, interfaceName);
    return myHOMARD_Gen->getId();
  }
}
