// Copyright (C) 2021  CEA/DEN, EDF R&D
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
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

#include "HOMARD_Gen_i_Session.hxx"
#include "SALOMEDS_Study_i.hxx"
#include "SALOME_KernelServices.hxx"

HOMARD_Gen_i_Session::HOMARD_Gen_i_Session( CORBA::ORB_ptr orb, PortableServer::POA_ptr poa, PortableServer::ObjectId* contId, const char* instanceName, const char* interfaceName ):HOMARD_Gen_i(orb,poa,contId,instanceName,interfaceName)
{
    myStudy = SALOMEDS::Study::_duplicate(KERNEL::getStudyServant());
}

//=============================================================================
extern "C"
{
  HOMARDENGINE_EXPORT
  PortableServer::ObjectId* HOMARDEngine_factory(CORBA::ORB_ptr orb,
						  PortableServer::POA_ptr poa,
						  PortableServer::ObjectId* contId,
						  const char* instanceName,
						  const char* interfaceName)
  {
    MESSAGE("PortableServer::ObjectId* HOMARDEngine_factory()");
    HOMARD_Gen_i_Session* myHOMARD_Gen = new HOMARD_Gen_i_Session(orb, poa, contId, instanceName, interfaceName);
    return myHOMARD_Gen->getId();
  }
}
