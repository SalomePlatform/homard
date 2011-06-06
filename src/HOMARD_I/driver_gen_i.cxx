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

#include <utilities.h>
#include "driver_gen_i.h"


//===========================================================================
    Driver_Base_Gen_i::Driver_Base_Gen_i(CORBA::ORB_ptr orb,
			                 PortableServer::POA_ptr poa,
				         PortableServer::ObjectId * contId,
					 const char *instanceName,
					 const char *interfaceName) 
//     :Engines_Component_i(orb, poa, contId, instanceName, interfaceName)
  {
    MESSAGE("Driver_Base_Gen_i::Driver_Base_Gen_i : ");
  };

//===========================================================================
  Driver_Base_Gen_i::~Driver_Base_Gen_i()
  {
    MESSAGE("Driver_Base_Gen_i::~Driver_Base_Gen_i");
  };

//===========================================================================
  CORBA::Boolean Driver_Base_Gen_i::Load(SALOMEDS::SComponent_ptr theComponent,
				  const SALOMEDS::TMPFile & theStream,
				  const char* theURL,
				  bool isMultiFile)
  {
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("Driver_Base_Gen_i::Load");
    MESSAGE("Should be implemented");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    return false;
  };

//===========================================================================
  CORBA::Boolean Driver_Base_Gen_i::LoadASCII(SALOMEDS::SComponent_ptr theComponent,
				       const SALOMEDS::TMPFile & theStream,
				       const char* theURL,
				       bool isMultiFile)
  {
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("Driver_Base_Gen_i::LoadASCII");
    MESSAGE("Should be implemented");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    return false;
  };

//===========================================================================
  char* Driver_Base_Gen_i::LocalPersistentIDToIOR(SALOMEDS::SObject_ptr theSObject,
					   const char* aLocalPersistentID,
					   CORBA::Boolean isMultiFile,
					   CORBA::Boolean isASCII)
  {
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("Driver_Base_Gen_i::LocalPersistentIDToIOR");
    MESSAGE("Should be implemented");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    CORBA::String_var aString("");
    return aString._retn();
  };

//===========================================================================
  SALOMEDS::TMPFile* Driver_Base_Gen_i::Save(SALOMEDS::SComponent_ptr theComponent,
				      const char* theURL,
				      bool isMultiFile)
  {
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("Driver_Base_Gen_i::Save");
    MESSAGE("Should be implemented");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    SALOMEDS::TMPFile_var aStreamFile = new SALOMEDS::TMPFile(0);
    return aStreamFile._retn();
  };

//===========================================================================
  SALOMEDS::TMPFile* Driver_Base_Gen_i::SaveASCII(SALOMEDS::SComponent_ptr theComponent,
					   const char* theURL,
					   bool isMultiFile)
  {
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("Driver_Base_Gen_i::SaveASCII");
    MESSAGE("Should be implemented");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    SALOMEDS::TMPFile_var aStreamFile = new SALOMEDS::TMPFile(0);
    return aStreamFile._retn();
  };

//===========================================================================
  char* Driver_Base_Gen_i::IORToLocalPersistentID(SALOMEDS::SObject_ptr theSObject,
					   const char* IORString,
					   CORBA::Boolean isMultiFile,
					   CORBA::Boolean isASCII)
  {
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("Driver_Base_Gen_i::IORToLocalPersistentID");
    MESSAGE("Should be implemented");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    CORBA::String_var aString("");
    return aString._retn();
  };


//===========================================================================
  void Driver_Base_Gen_i::Close(SALOMEDS::SComponent_ptr theComponent)
  {
    MESSAGE("------------------------");
    MESSAGE("Driver_Base_Gen_i::Close");
    MESSAGE("------------------------");
  };

//===========================================================================
  char* Driver_Base_Gen_i::ComponentDataType()
  {
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("Driver_Base_Gen_i::ComponentDataType");
    MESSAGE("Should be implemented");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    return CORBA::string_dup("J aurais du nommer mon type prefere");
  };

//===========================================================================
  bool Driver_Base_Gen_i::CanPublishInStudy(CORBA::Object_ptr theIOR) 
  {
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("Driver_Base_Gen_i::CanPublishInStudy");
    MESSAGE("Should be implemented");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    return false;
  };

//===========================================================================
  SALOMEDS::SObject_ptr Driver_Base_Gen_i::PublishInStudy(SALOMEDS::Study_ptr theStudy,
						   SALOMEDS::SObject_ptr theSObject,
						   CORBA::Object_ptr theObject,
						   const char* theName)
    throw (SALOME::SALOME_Exception)
  {
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("Driver_Base_Gen_i::PublishInStudy");
    MESSAGE("Should be implemented");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    SALOMEDS::SObject_var aResultSO;
    return aResultSO._retn();
  };

//===========================================================================
  CORBA::Boolean Driver_Base_Gen_i::CanCopy(SALOMEDS::SObject_ptr theObject) 
  {
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("Driver_Base_Gen_i::CanCopy");
    MESSAGE("Should be implemented");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    //return false;
    return true;
  };

//===========================================================================
  SALOMEDS::TMPFile* Driver_Base_Gen_i::CopyFrom(SALOMEDS::SObject_ptr theObject,
		  			     CORBA::Long& theObjectID)
{
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("Driver_Base_Gen_i::CopyFrom");
    MESSAGE("Should be implemented");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    MESSAGE("--------------------------------------");
    SALOMEDS::TMPFile_var aStreamFile = new SALOMEDS::TMPFile(0);
    return aStreamFile._retn();
};

//===========================================================================
  SALOMEDS::SObject_ptr Driver_Base_Gen_i::PasteInto( const SALOMEDS::TMPFile & theStream,
		  			              CORBA::Long theObjectID,
						      SALOMEDS::SObject_ptr theSObject)
  {
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("Driver_Base_Gen_i::PasteInto");
    MESSAGE("Should be implemented");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    SALOMEDS::SObject_var aResultSO;
    return aResultSO._retn();
  };

//===========================================================================
   CORBA::Boolean  Driver_Base_Gen_i::CanPaste ( const char *theComponentName,
		  			         CORBA::Long theObjectID)
  {
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("Driver_Base_Gen_i::CanPaste");
    MESSAGE("Should be implemented");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    MESSAGE("-----------------------------------------");
    return false;
  };

  
