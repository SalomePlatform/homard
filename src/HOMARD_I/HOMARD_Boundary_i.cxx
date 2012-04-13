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

#include "HOMARD_Boundary_i.hxx"
#include "HOMARD_Gen_i.hxx"
#include "HOMARD_Boundary.hxx"
#include "HOMARD_DriverTools.hxx"

#include "utilities.h"

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Boundary_i::HOMARD_Boundary_i()
{
  MESSAGE( "Default constructor, not for use" );
  ASSERT( 0 );
}

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Boundary_i::HOMARD_Boundary_i( CORBA::ORB_ptr orb,
			      HOMARD::HOMARD_Gen_var engine )
{
  MESSAGE( "HOMARD_Boundary_i" );
  _gen_i = engine;
  _orb = orb;
  myHomardBoundary = new ::HOMARD_Boundary();
  ASSERT( myHomardBoundary );
}
//=============================================================================
/*!
 *  standard destructor
 */
//=============================================================================

HOMARD_Boundary_i::~HOMARD_Boundary_i()
{
}

//=============================================================================
/*!
 */
//=============================================================================
void HOMARD_Boundary_i::SetName( const char* NomBoundary )
{
  ASSERT( myHomardBoundary );
  myHomardBoundary->SetName( NomBoundary );
}

//=============================================================================
char* HOMARD_Boundary_i::GetName()
{
  ASSERT( myHomardBoundary );
  return CORBA::string_dup( myHomardBoundary->GetName().c_str() );
}

//=============================================================================
char* HOMARD_Boundary_i::GetDumpPython()
{
  ASSERT( myHomardBoundary );
  return CORBA::string_dup( myHomardBoundary->GetDumpPython().c_str() );
}


//=============================================================================
void HOMARD_Boundary_i::SetBoundaryType( CORBA::Long BoundaryType )
{
  ASSERT( myHomardBoundary );
  myHomardBoundary->SetBoundaryType( BoundaryType );
}

//=============================================================================
CORBA::Long HOMARD_Boundary_i::GetBoundaryType()
{
  ASSERT( myHomardBoundary );
  return  CORBA::Long( myHomardBoundary->GetBoundaryType() );
}

//=============================================================================
void HOMARD_Boundary_i::SetMeshFile( const char* MeshFile )
{
  ASSERT( myHomardBoundary );
  myHomardBoundary->SetMeshFile( MeshFile );
  _gen_i->PublishResultInSmesh(MeshFile, 0);
}
//=============================================================================
char* HOMARD_Boundary_i::GetMeshFile()
{
  ASSERT( myHomardBoundary );
  return CORBA::string_dup( myHomardBoundary->GetMeshFile().c_str() );
}

//=============================================================================
void HOMARD_Boundary_i::SetMeshName( const char* MeshName )
{
  ASSERT( myHomardBoundary );
  myHomardBoundary->SetMeshName( MeshName );
}

//=============================================================================
char* HOMARD_Boundary_i::GetMeshName()
{
  ASSERT( myHomardBoundary );
  return CORBA::string_dup( myHomardBoundary->GetMeshName().c_str() );
}


//=============================================================================
void HOMARD_Boundary_i::SetCylinder( double X0, double X1, double X2, double X3, double X4, double X5, double X6 )
{
  ASSERT( myHomardBoundary );
  myHomardBoundary->SetCylinder( X0, X1, X2, X3, X4, X5, X6 );
}
//=============================================================================
void HOMARD_Boundary_i::SetSphere( double Xcentre, double Ycentre, double ZCentre, double rayon )
{
  ASSERT( myHomardBoundary );
  myHomardBoundary->SetSphere( Xcentre, Ycentre, ZCentre, rayon );
}

//=============================================================================
HOMARD::double_array* HOMARD_Boundary_i::GetCoords()
{
  ASSERT( myHomardBoundary );
  HOMARD::double_array_var aResult = new HOMARD::double_array();
  std::vector<double> mesCoor = myHomardBoundary->GetCoords();
  aResult->length( mesCoor .size() );
  std::vector<double>::const_iterator it;
  int i = 0;
  for ( it = mesCoor.begin(); it != mesCoor.end(); it++ )
    aResult[i++] = (*it);
  return aResult._retn();
}

//=============================================================================
void HOMARD_Boundary_i::SetLimit( double Xincr, double Yincr, double Zincr )
{
  ASSERT( myHomardBoundary );
  myHomardBoundary->SetLimit( Xincr, Yincr, Zincr );
}

//=============================================================================
HOMARD::double_array* HOMARD_Boundary_i::GetLimit()
{
  ASSERT( myHomardBoundary );
  HOMARD::double_array_var aResult = new HOMARD::double_array();
  std::vector<double> mesCoor = myHomardBoundary->GetLimit();
  aResult->length( mesCoor .size() );
  std::vector<double>::const_iterator it;
  int i = 0;
  for ( it = mesCoor.begin(); it != mesCoor.end(); it++ )
    aResult[i++] = (*it);
  return aResult._retn();
}
//=============================================================================
/*!
 */
//=============================================================================
void HOMARD_Boundary_i::SetCaseCreation( const char* NomCaseCreation )
{
  ASSERT( myHomardBoundary );
  myHomardBoundary->SetCaseCreation( NomCaseCreation );
}

//=============================================================================
char* HOMARD_Boundary_i::GetCaseCreation()
{
  ASSERT( myHomardBoundary );
  return CORBA::string_dup( myHomardBoundary->GetCaseCreation().c_str() );
}
//=============================================================================
void HOMARD_Boundary_i::AddGroup( const char* Group)
{
  ASSERT( myHomardBoundary );
  myHomardBoundary->AddGroup( Group );
}
//=============================================================================
void HOMARD_Boundary_i::SetGroups(const HOMARD::ListGroupType& ListGroup)
{
  ASSERT( myHomardBoundary );
  std::list<std::string> ListString;
  for ( int i = 0; i < ListGroup.length(); i++ )
  {
      ListString.push_back(std::string(ListGroup[i]));
  }
  myHomardBoundary->SetGroups( ListString );
}
//=============================================================================
HOMARD::ListGroupType*  HOMARD_Boundary_i::GetGroups()
{
  ASSERT( myHomardBoundary );
  const std::list<std::string>& ListString = myHomardBoundary->GetGroups();
  HOMARD::ListGroupType_var aResult = new HOMARD::ListGroupType;
  aResult->length( ListString.size() );
  std::list<std::string>::const_iterator it;
  int i = 0;
  for ( it = ListString.begin(); it != ListString.end(); it++ )
  {
    aResult[i++] = CORBA::string_dup( (*it).c_str() );
  }
  return aResult._retn();
}



//=============================================================================
std::string HOMARD_Boundary_i::Dump() const
{
  return HOMARD::Dump( *myHomardBoundary );
}

//=============================================================================
bool HOMARD_Boundary_i::Restore( const std::string& stream )
{
  return HOMARD::Restore( *myHomardBoundary, stream );
}
