// Copyright (C) 2011-2013  CEA/DEN, EDF R&D
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
// Remarques :
// L'ordre de description des fonctions est le meme dans tous les fichiers
// HOMARD_aaaa.idl, HOMARD_aaaa.hxx, HOMARD_aaaa.cxx, HOMARD_aaaa_i.hxx, HOMARD_aaaa_i.cxx :
// 1. Les generalites : Name, Delete, DumpPython, Dump, Restore
// 2. Les caracteristiques
// 3. Le lien avec les autres structures
//
// Quand les 2 fonctions Setxxx et Getxxx sont presentes, Setxxx est decrit en premier
//

#include "HOMARD_YACS_i.hxx"
#include "HOMARD_Gen_i.hxx"
#include "HOMARD_YACS.hxx"
#include "HOMARD_DriverTools.hxx"

#include "SALOMEDS_Tool.hxx"

#include "utilities.h"

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_YACS_i::HOMARD_YACS_i()
{
  MESSAGE( "Default constructor, not for use" );
  ASSERT( 0 );
}
//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_YACS_i::HOMARD_YACS_i( CORBA::ORB_ptr orb,
                                        HOMARD::HOMARD_Gen_var engine )
{
  MESSAGE("constructor");
  _gen_i = engine;
  _orb = orb;
  myHomardYACS = new ::HOMARD_YACS();
  ASSERT( myHomardYACS );
}
//=============================================================================
/*!
 *  standard destructor
 */
//=============================================================================
HOMARD_YACS_i::~HOMARD_YACS_i()
{
}
//=============================================================================
//=============================================================================
// Generalites
//=============================================================================
//=============================================================================
void HOMARD_YACS_i::SetName( const char* Name )
{
  ASSERT( myHomardYACS );
  myHomardYACS->SetName( Name );
}
//=============================================================================
char* HOMARD_YACS_i::GetName()
{
  ASSERT( myHomardYACS );
  return CORBA::string_dup( myHomardYACS->GetName().c_str() );
}
//=============================================================================
CORBA::Long HOMARD_YACS_i::Delete( CORBA::Long Option )
{
  ASSERT( myHomardYACS );
  char* YACSName = GetName() ;
  MESSAGE ( "Delete : destruction du schema " << YACSName << ", Option = " << Option );
  return _gen_i->DeleteYACS(YACSName, Option) ;
}
//=============================================================================
char* HOMARD_YACS_i::GetDumpPython()
{
  ASSERT( myHomardYACS );
  return CORBA::string_dup( myHomardYACS->GetDumpPython().c_str() );
}
//=============================================================================
std::string HOMARD_YACS_i::Dump() const
{
  return HOMARD::Dump( *myHomardYACS );
}
//=============================================================================
bool HOMARD_YACS_i::Restore( const std::string& stream )
{
  return HOMARD::Restore( *myHomardYACS, stream );
}
//=============================================================================
//=============================================================================
// Caracteristiques
//=============================================================================
//=============================================================================
void HOMARD_YACS_i::SetType( CORBA::Long Type )
{
  ASSERT( myHomardYACS );
  myHomardYACS->SetType( Type );
}
//=============================================================================
CORBA::Long HOMARD_YACS_i::GetType()
{
  ASSERT( myHomardYACS );
  return  CORBA::Long( myHomardYACS->GetType() );
}
void HOMARD_YACS_i::SetDirName( const char* NomDir )
{
  ASSERT( myHomardYACS );
  myHomardYACS->SetDirName( NomDir );
}
//=============================================================================
char* HOMARD_YACS_i::GetDirName()
{
  ASSERT( myHomardYACS );
  return CORBA::string_dup( myHomardYACS->GetDirName().c_str() );
}
//=============================================================================
void HOMARD_YACS_i::SetMeshFile( const char* MeshFile )
{
  ASSERT( myHomardYACS );
  myHomardYACS->SetMeshFile( MeshFile );
}
//=============================================================================
char* HOMARD_YACS_i::GetMeshFile()
{
  ASSERT( myHomardYACS );
  return CORBA::string_dup( myHomardYACS->GetMeshFile().c_str() );
}
//=============================================================================
void HOMARD_YACS_i::SetScriptFile( const char* ScriptFile )
{
  ASSERT( myHomardYACS );
  myHomardYACS->SetScriptFile( ScriptFile );
}
//=============================================================================
char* HOMARD_YACS_i::GetScriptFile()
{
  ASSERT( myHomardYACS );
  return CORBA::string_dup( myHomardYACS->GetScriptFile().c_str() );
}
//=============================================================================
//=============================================================================
// Liens avec les autres structures
//=============================================================================
//=============================================================================
void HOMARD_YACS_i::SetCaseName( const char* NomCas )
{
  ASSERT( myHomardYACS );
  myHomardYACS->SetCaseName( NomCas );
}
//=============================================================================
char* HOMARD_YACS_i::GetCaseName()
{
  ASSERT( myHomardYACS );
  return CORBA::string_dup( myHomardYACS->GetCaseName().c_str() );
}
//=============================================================================
CORBA::Long HOMARD_YACS_i::Write()
{
  MESSAGE ( "Write : ecriture du schema");
  ASSERT( myHomardYACS );
//
// Le repertoire du cas
  std::string casename = GetCaseName() ;
  HOMARD::HOMARD_Cas_ptr caseyacs = _gen_i->GetCase(casename.c_str()) ;
  std::string dirnamecase = caseyacs->GetDirName() ;
// Le nom par defaut du fichier du schema
  std::string YACSFile ;
  YACSFile = dirnamecase + "/schema.xml" ;
//
  return WriteOnFile(YACSFile.c_str()) ;
}
//=============================================================================
CORBA::Long HOMARD_YACS_i::WriteOnFile( const char* YACSFile )
{
  MESSAGE ( "WriteOnFile : ecriture du schema sur " << YACSFile );
  ASSERT( myHomardYACS );
//
// Nom du schema
  char* nomYACS = GetName() ;
  MESSAGE ( "WriteOnFile : ecriture du schema " << nomYACS);
  return _gen_i->YACSWriteOnFile(nomYACS, YACSFile) ;
}
//=============================================================================
//=============================================================================
//=============================================================================
// Divers
//=============================================================================
//=============================================================================
