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

#include "HOMARD_Iteration_i.hxx"
#include "HOMARD_Gen_i.hxx"
#include "HOMARD_Iteration.hxx"
#include "HOMARD_DriverTools.hxx"

#include "SALOMEDS_Tool.hxx"

#include "utilities.h"

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Iteration_i::HOMARD_Iteration_i()
{
  MESSAGE( "Default constructor, not for use" );
  ASSERT( 0 );
}

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Iteration_i::HOMARD_Iteration_i( CORBA::ORB_ptr orb,
                                        HOMARD::HOMARD_Gen_var engine )
{
  MESSAGE("constructor");
  _gen_i = engine;
  _orb = orb;
  myHomardIteration = new ::HOMARD_Iteration();
  ASSERT( myHomardIteration );
}

//=============================================================================
/*!
 *  standard destructor
 */
//=============================================================================
HOMARD_Iteration_i::~HOMARD_Iteration_i()
{
}

//=============================================================================
/*!
 */
//=============================================================================
void HOMARD_Iteration_i::SetName( const char* NomIter )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetName( NomIter );
}

//=============================================================================
char* HOMARD_Iteration_i::GetName()
{
  ASSERT( myHomardIteration );
  return CORBA::string_dup( myHomardIteration->GetName().c_str() );
}

//=============================================================================
char* HOMARD_Iteration_i::GetDumpPython()
{
  ASSERT( myHomardIteration );
  return CORBA::string_dup( myHomardIteration->GetDumpPython().c_str() );
}

//=============================================================================
void HOMARD_Iteration_i::SetEtat( CORBA::Boolean Etat )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetEtat( Etat );
}

//=============================================================================
CORBA::Boolean HOMARD_Iteration_i::GetEtat()
{
  ASSERT( myHomardIteration );
  return CORBA::Boolean( myHomardIteration->GetEtat());
}

//=============================================================================
void HOMARD_Iteration_i::SetNumber( CORBA::Long NumIter )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetNumber( NumIter );
}

//=============================================================================
CORBA::Long HOMARD_Iteration_i::GetNumber()
{
  ASSERT( myHomardIteration );
  return  myHomardIteration->GetNumber() ;
}

//=============================================================================
void HOMARD_Iteration_i::SetMeshName( const char* NomMesh )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetMeshName( NomMesh );
}

//=============================================================================
char* HOMARD_Iteration_i::GetMeshName()
{
  ASSERT( myHomardIteration );
  return CORBA::string_dup( myHomardIteration->GetMeshName().c_str() );
}

//=============================================================================
char* HOMARD_Iteration_i::GetIterParent()
{
  ASSERT( myHomardIteration );
  return CORBA::string_dup( myHomardIteration->GetIterParent().c_str() );

}

//=============================================================================
HOMARD::listeIterFilles* HOMARD_Iteration_i::GetIterations()
{
  ASSERT( myHomardIteration );
  const std::list<std::string>& maListe = myHomardIteration->GetIterations();
  HOMARD::listeIterFilles_var aResult = new HOMARD::listeIterFilles;
  aResult->length( maListe.size() );
  std::list<std::string>::const_iterator it;
  int i = 0;
  for ( it = maListe.begin(); it != maListe.end(); it++ )
  {
    aResult[i++] = CORBA::string_dup( (*it).c_str() );
  }
  return aResult._retn();
}

//=============================================================================
void HOMARD_Iteration_i::SetIterParent( const char* NomIterParent )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetIterParent( NomIterParent );
}

//=============================================================================
void HOMARD_Iteration_i::AddIteration( const char* NomIter )
{
  ASSERT( myHomardIteration );
  myHomardIteration->AddIteration( NomIter );
}

//=============================================================================
CORBA::Long  HOMARD_Iteration_i::Compute(CORBA::Long etatMenage)
{
  MESSAGE ( "Compute : calcul d'une iteration" );
  ASSERT( myHomardIteration );
//
// Nom de l'iteration
  char* IterName = GetName() ;
  MESSAGE ( ". IterName = " << IterName );
// B. Calcul : on passe par la methode sur l'objet HOMARD
// Il serait plus elegant de tout faire ici, mais il est complexe de paser tout le contexte
  return _gen_i->Compute(IterName, etatMenage) ;
}

//=============================================================================
void HOMARD_Iteration_i::SetMeshFile( const char* MeshFile )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetMeshFile( MeshFile );
}

//=============================================================================
char* HOMARD_Iteration_i::GetMeshFile()
{
  ASSERT( myHomardIteration );
  return CORBA::string_dup( myHomardIteration->GetMeshFile().c_str() );
}

//=============================================================================
char* HOMARD_Iteration_i::GetCaseName()
{
  ASSERT( myHomardIteration );
  return CORBA::string_dup( myHomardIteration->GetCaseName().c_str() );
}

//=============================================================================
void HOMARD_Iteration_i::SetCaseName( const char* NomCas )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetCaseName( NomCas );
}

//=============================================================================
char* HOMARD_Iteration_i::GetDirName()
{
  ASSERT( myHomardIteration );
  return CORBA::string_dup( myHomardIteration->GetDirName().c_str() );
}

//=============================================================================
void HOMARD_Iteration_i::SetDirName( const char* NomDir )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetDirName( NomDir );
}

//=============================================================================
char* HOMARD_Iteration_i::GetHypoName()
{
  ASSERT( myHomardIteration );
  return CORBA::string_dup( myHomardIteration->GetHypoName().c_str() );

}

//=============================================================================
void HOMARD_Iteration_i::SetHypoName( const char* NomHypo )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetHypoName( NomHypo );
}

//=============================================================================
void HOMARD_Iteration_i::SetFieldFile( const char* FieldFile )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetFieldFile( FieldFile );
}

//=============================================================================
char* HOMARD_Iteration_i::GetFieldFile()
{
  ASSERT( myHomardIteration );
  return CORBA::string_dup( myHomardIteration->GetFieldFile().c_str() );
}

//=============================================================================
void HOMARD_Iteration_i::SetTimeStepRank( CORBA::Long TimeStep, CORBA::Long Rank )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetTimeStepRank( TimeStep, Rank );
}

//=============================================================================
CORBA::Long HOMARD_Iteration_i::GetTimeStep()
{
  ASSERT( myHomardIteration );
  return  CORBA::Long( myHomardIteration->GetTimeStep() );
}

//=============================================================================
CORBA::Long HOMARD_Iteration_i::GetRank()
{
  ASSERT( myHomardIteration );
  return  CORBA::Long( myHomardIteration->GetRank() );
}

//=============================================================================
void HOMARD_Iteration_i::SetMessFile( const char* MessFile )
{
  ASSERT( myHomardIteration );
  myHomardIteration->SetMessFile( MessFile );
}

//=============================================================================
char* HOMARD_Iteration_i::GetMessFile()
{
  ASSERT( myHomardIteration );
  return CORBA::string_dup( myHomardIteration->GetMessFile().c_str() );
}
//=============================================================================
std::string HOMARD_Iteration_i::Dump() const
{
  return HOMARD::Dump( *myHomardIteration );
}

//=============================================================================
bool HOMARD_Iteration_i::Restore( const std::string& stream )
{
  return HOMARD::Restore( *myHomardIteration, stream );
}
