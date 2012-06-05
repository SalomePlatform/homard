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

#ifndef _HOMARD_CAS_I_HXX_
#define _HOMARD_CAS_I_HXX_

#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(HOMARD_Gen)
#include CORBA_SERVER_HEADER(HOMARD_Cas)

#include "SALOME_Component_i.hxx"
#include "SALOME_NamingService.hxx"
#include "Utils_CorbaException.hxx"

#include <string>

class HOMARD_Cas;

class HOMARD_Cas_i:
  public virtual Engines_Component_i,
  public virtual POA_HOMARD::HOMARD_Cas,
  public virtual PortableServer::ServantBase
{
public:
  HOMARD_Cas_i( CORBA::ORB_ptr orb, HOMARD::HOMARD_Gen_var gen_i );
  HOMARD_Cas_i();

  virtual ~HOMARD_Cas_i();

  void                   SetDirName( const char* NomDir );
  char*                  GetDirName();

  void                   SetName( const char* NomCas );
  char*                  GetName();

  void                   SetConfType( CORBA::Long ConfType );
  CORBA::Long            GetConfType();

  void                   AddIteration( const char* NomIteration );
  char*                  GetIter0Name();

  HOMARD::extrema*       GetBoundingBox();
  void                   SetBoundingBox( const HOMARD::extrema& LesExtremes );

  HOMARD::ListGroupType* GetGroups();
  void                   AddGroup( const char* Group);
  void                   SetGroups(const HOMARD::ListGroupType& ListGroup);

  HOMARD::ListBoundaryGroupType*  GetBoundaryGroup();
  void                   AddBoundaryGroup( const char* Boundary, const char* Group);

  void                   SetPyram( CORBA::Long Pyram );
  CORBA::Long            GetPyram();

  std::string            Dump() const;
  bool                   Restore( const std::string& stream );

  char *		 GetDumpPython();
  CORBA::Long            GetNumber();

private:
  ::HOMARD_Cas*          myHomardCas;

  CORBA::ORB_ptr         _orb;
  HOMARD::HOMARD_Gen_var _gen_i;
};

#endif
