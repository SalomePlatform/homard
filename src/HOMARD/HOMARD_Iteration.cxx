//  HOMARD HOMARD : implementation of HOMARD idl descriptions
//
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
//  File   : HOMARD_Iteration.cxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD

#include "HOMARD_Iteration.hxx"
#include "utilities.h"

//=============================================================================
/*!
 *  default constructor:
 */
//=============================================================================
HOMARD_Iteration::HOMARD_Iteration():
  _NomIter( "" ), _Etat( false ),
 _NumIter( -1 ),
  _NomMesh( "" ), _MeshFile( "" ),
  _FieldFile( "" ), _TimeStep( -1 ), _Rank( -1 ),
  _MessFile( "" ),
  _IterParent( "" ),
  _NomHypo( "" ), _NomCas( "" ), _NomDir( "" )
{
  MESSAGE("HOMARD_Iter");
}

//=============================================================================
/*!
 *
 */
//=============================================================================
HOMARD_Iteration::~HOMARD_Iteration()
{
  MESSAGE("~HOMARD_Iteration");
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetName( const char* NomIter )
{
  _NomIter = std::string( NomIter );
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Iteration::GetName() const
{
  return _NomIter;
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Iteration::GetDumpPython() const
{
  if (_IterParent == "") return std::string(" ") ;   // Pas de creation explicite de iteration 0";

  std::ostringstream aScript;
  aScript << "\n# Creation of the iteration " << _NomIter << "\n";
  if( _NumIter == 1 )
  {
       aScript << "\t" << _NomIter << " = homard.CreateIteration(\"";
       aScript <<  _NomIter << "\", "<<  _NomCas << ".GetIter0Name() )\n";
  }
   else
  {
       aScript << "\t" << _NomIter << " = homard.CreateIteration(\"";
       aScript <<  _NomIter << "\", \"" << _IterParent << "\")\n";
  }
// Le nom du maillage produit
  aScript << "\t" << _NomIter << ".SetMeshName(\"" << _NomMesh << "\")\n" ;
// Le fichier du maillage produit
  aScript << "\t" << _NomIter << ".SetMeshFile(\"" << _MeshFile << "\")\n";
// Le fichier des champs, avec l'instant eventuel
  if ( _FieldFile != "" ) {
    aScript << "\t" << _NomIter << ".SetFieldFile(\"" << _FieldFile << "\")\n";
    if ( ( _TimeStep != -1 ) and ( _Rank != -1 ) ) {
      aScript << "\t" << _NomIter << ".SetTimeStepRank( " << _TimeStep << ", " << _Rank << " )\n";
    }
  }

  aScript << "\thomard.AssociateIterHypo(\"" <<_NomIter << "\", \"" << _NomHypo << "\")\n";
  if (_Etat == true)
  {
     aScript << "\tcodret = " <<_NomIter << ".Compute(1)\n";
  }
  else
  {
     aScript << "\t#codret = " <<_NomIter << ".Compute(1)\n";
  }

  return aScript.str();
}
//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetEtat( bool etat )
{
  _Etat = etat;
}

//=============================================================================
/*!
*/
//=============================================================================
bool HOMARD_Iteration::GetEtat() const
{
  return _Etat;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetNumber( int NumIter )
{
  _NumIter = NumIter;
}

//=============================================================================
/*!
*/
//=============================================================================
int HOMARD_Iteration::GetNumber() const
{
  return _NumIter;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetMeshName( const char* NomMesh )
{
  _NomMesh = std::string( NomMesh );
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Iteration::GetMeshName() const
{
  return _NomMesh;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetIterParent( const char* IterParent )
{
  _IterParent = IterParent;
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Iteration::GetIterParent() const
{
  return _IterParent;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::AddIteration( const char* NomIteration )
{
  _mesIterFilles.push_back( std::string( NomIteration ) );
}

//=============================================================================
/*!
*/
//=============================================================================
const std::list<std::string>& HOMARD_Iteration::GetIterations() const
{
  return _mesIterFilles;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SupprIterations()
{
  _mesIterFilles.clear();
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetHypoName( const char* NomHypo )
{
  _NomHypo = std::string( NomHypo );
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Iteration::GetHypoName() const
{
  return _NomHypo;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetMeshFile( const char* MeshFile )
{
  _MeshFile = std::string( MeshFile );
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Iteration::GetMeshFile() const
{
  return _MeshFile;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetFieldFile( const char* FieldFile )
{
  _FieldFile = std::string( FieldFile );
}
//=============================================================================
std::string HOMARD_Iteration::GetFieldFile() const
{
  return _FieldFile;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetTimeStepRank( int TimeStep, int Rank )
{
  _TimeStep = TimeStep;
  _Rank = Rank;
}
//=============================================================================
int HOMARD_Iteration::GetTimeStep() const
{
  return _TimeStep;
}
//=============================================================================
int HOMARD_Iteration::GetRank() const
{
  return _Rank;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetCaseName( const char* NomCas )
{
  _NomCas = std::string( NomCas );
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Iteration::GetCaseName() const
{
  return _NomCas;
}
//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetDirName( const char* NomDir )
{
  _NomDir = std::string( NomDir );
}
//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Iteration::GetDirName() const
{
   return _NomDir;
}
/*!
*/
//=============================================================================
void HOMARD_Iteration::SetMessFile( const char* MessFile )
{
  _MessFile = std::string( MessFile );
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Iteration::GetMessFile() const
{
  return _MessFile;
}
