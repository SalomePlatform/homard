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

#ifndef _HOMARD_Boundary_I_HXX_
#define _HOMARD_Boundary_I_HXX_

#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(HOMARD_Gen)
#include CORBA_SERVER_HEADER(HOMARD_Boundary)

#include "SALOME_Component_i.hxx"
#include "SALOME_NamingService.hxx"
#include "Utils_CorbaException.hxx"

#include <string>

class HOMARD_Boundary;

class HOMARD_Boundary_i:
  public virtual Engines_Component_i,
  public virtual POA_HOMARD::HOMARD_Boundary,
  public virtual PortableServer::ServantBase
{
public:
  HOMARD_Boundary_i( CORBA::ORB_ptr orb, HOMARD::HOMARD_Gen_var gen_i );
  HOMARD_Boundary_i();

  virtual ~HOMARD_Boundary_i();

  void                   SetName( const char* NomBoundary );
  char*                  GetName();
  char*                  GetDumpPython();

  void                   SetBoundaryType( CORBA::Long BoundaryType );

  CORBA::Long            GetBoundaryType();

  void                   SetMeshFile( const char* MeshFile );
  char*                  GetMeshFile();

  void                   SetMeshName( const char* MeshName );
  char*                  GetMeshName();

  void                   SetCylinder( double Xcentre, double Ycentre, double ZCentre,
                                      double Xaxe, double Yaxe, double Zaxe,
                                      double rayon );
  void                   SetSphere( double Xcentre, double Ycentre, double ZCentre,
                                    double rayon );
  HOMARD::double_array*  GetCoords();

  HOMARD::double_array*  GetLimit();
  void                   SetLimit( double Xincr, double Yincr, double Zincr);


  std::string            Dump() const;
  bool                   Restore( const std::string& stream );

  void                   SetCaseCreation( const char* NomCaseCreation );
  char*                  GetCaseCreation();

  void                    AddGroup( const char* Group);
  void                    SetGroups(const HOMARD::ListGroupType& ListGroup);
  HOMARD::ListGroupType*  GetGroups();


private:
  ::HOMARD_Boundary*     myHomardBoundary;

  CORBA::ORB_ptr         _orb;
  HOMARD::HOMARD_Gen_var _gen_i;
};

#endif
