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

#include "HOMARD_Cas_i.hxx"
#include "HOMARD_Gen_i.hxx"
#include "HOMARD_Cas.hxx"
#include "HOMARD_DriverTools.hxx"

#include "utilities.h"
#include <vector>

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Cas_i::HOMARD_Cas_i()
{
  MESSAGE( "Default constructor, not for use" );
  ASSERT( 0 );
}

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Cas_i::HOMARD_Cas_i( CORBA::ORB_ptr orb,
                            HOMARD::HOMARD_Gen_var engine )
{
  MESSAGE( "HOMARD_Cas_i" );
  _gen_i = engine;
  _orb = orb;
  myHomardCas = new ::HOMARD_Cas();
  ASSERT( myHomardCas );
}

//=============================================================================
/*!
 *  standard destructor
 */
//=============================================================================
HOMARD_Cas_i::~HOMARD_Cas_i()
{
}

//=============================================================================
/*!
 */
//=============================================================================
void HOMARD_Cas_i::SetDirName( const char* NomDir )
{
  ASSERT( myHomardCas );
  myHomardCas->SetDirName( NomDir );
}

//=============================================================================
/*!
 */
//=============================================================================
void HOMARD_Cas_i::SetName( const char* NomCas )
{
  ASSERT( myHomardCas );
  myHomardCas->SetName( NomCas );
}

//=============================================================================
/*!
 */
//=============================================================================
char* HOMARD_Cas_i::GetName()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetName().c_str() );
}

//=============================================================================
/*!
 */
//=============================================================================
char* HOMARD_Cas_i::GetDumpPython()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetDumpPython().c_str() );
}

//=============================================================================
char* HOMARD_Cas_i::GetDirName()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetDirName().c_str() );
}

//=============================================================================
void HOMARD_Cas_i::SetConfType( CORBA::Long ConfType )
{
  ASSERT( myHomardCas );
  myHomardCas->SetConfType( ConfType );
}
//=============================================================================
CORBA::Long HOMARD_Cas_i::GetNumber()
{
  ASSERT( myHomardCas );
  return myHomardCas->GetNumber();
}

//=============================================================================
CORBA::Long HOMARD_Cas_i::GetConfType()
{
  ASSERT( myHomardCas );
  return myHomardCas->GetConfType();
}

//=============================================================================
void HOMARD_Cas_i::AddIteration( const char* NomIteration )
{
  ASSERT( myHomardCas );
  myHomardCas->AddIteration( NomIteration );
}

//=============================================================================
char* HOMARD_Cas_i::GetIter0Name()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetIter0Name().c_str() );
}
//=============================================================================
HOMARD::extrema* HOMARD_Cas_i::GetBoundingBox()
{
  ASSERT(myHomardCas );
  HOMARD::extrema_var aResult = new HOMARD::extrema();
  std::vector<double> LesExtremes = myHomardCas->GetBoundingBox();
  ASSERT( LesExtremes.size() == 10 );
  aResult->length( 10 );
  for ( int i = 0; i < LesExtremes.size(); i++ )
  {
    aResult[i] = LesExtremes[i];
  }
  return aResult._retn();
}
//=============================================================================
void HOMARD_Cas_i::SetBoundingBox( const HOMARD::extrema& LesExtrema )
{
  ASSERT( myHomardCas );
  std::vector<double> VExtrema;
  ASSERT( LesExtrema.length() == 10 );
  VExtrema.resize( LesExtrema.length() );
  for ( int i = 0; i < LesExtrema.length(); i++ )
  {
    VExtrema[i] = LesExtrema[i];
  }

  myHomardCas->SetBoundingBox( VExtrema );
}
//=============================================================================
void HOMARD_Cas_i::AddGroup( const char* Group)
{
  ASSERT( myHomardCas );
  myHomardCas->AddGroup( Group );
}
//=============================================================================
void HOMARD_Cas_i::SetGroups( const HOMARD::ListGroupType& ListGroup )
{
  ASSERT( myHomardCas );
  std::list<std::string> ListString ;
  for ( int i = 0; i < ListGroup.length(); i++ )
  {
    ListString.push_back(std::string(ListGroup[i]));
  }

  myHomardCas->SetGroups( ListString );
}
//=============================================================================
HOMARD::ListGroupType* HOMARD_Cas_i::GetGroups()
{
  ASSERT(myHomardCas );
  const std::list<std::string>& ListString = myHomardCas->GetGroups();
  HOMARD::ListGroupType_var aResult = new HOMARD::ListGroupType();
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
void HOMARD_Cas_i::AddBoundaryGroup( const char* Boundary, const char* Group)
{
  MESSAGE ("AddBoundaryGroup");
  ASSERT( myHomardCas );
  myHomardCas->AddBoundaryGroup( Boundary, Group );
}
//=============================================================================
HOMARD::ListBoundaryGroupType* HOMARD_Cas_i::GetBoundaryGroup()
{
  MESSAGE ("GetBoundaryGroup");
  ASSERT(myHomardCas );
  const std::list<std::string>& ListString = myHomardCas->GetBoundaryGroup();
  HOMARD::ListBoundaryGroupType_var aResult = new HOMARD::ListBoundaryGroupType();
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
void HOMARD_Cas_i::SetPyram( CORBA::Long Pyram )
{
  MESSAGE ("SetPyram, Pyram = " << Pyram );
  ASSERT( myHomardCas );
  myHomardCas->SetPyram( Pyram );
}
//=============================================================================
CORBA::Long HOMARD_Cas_i::GetPyram()
{
  MESSAGE ("GetPyram");
  ASSERT( myHomardCas );
  return myHomardCas->GetPyram();
}
//=============================================================================
std::string HOMARD_Cas_i::Dump() const
{
  return HOMARD::Dump( *myHomardCas );
}

//=============================================================================
bool HOMARD_Cas_i::Restore( const std::string& stream )
{
  return HOMARD::Restore( *myHomardCas, stream );
}
