//  HOMARD HOMARD : implementaion of HOMARD idl descriptions
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
//  File   : HOMARD_Cas.cxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD

#include "HOMARD_Cas.hxx"
#include "utilities.h"
#include <iostream>

#ifndef WIN32
# include <unistd.h>
#endif

//=============================================================================
/*!
 *  default constructor:
 *  Par defaut, l'adaptation est conforme, sans suivi de frontiere
 */
//=============================================================================
HOMARD_Cas::HOMARD_Cas():
  _NomCas(""), _NomDir("/tmp"), _ConfType(1)
{
  MESSAGE("HOMARD_Cas");
}
//=============================================================================
HOMARD_Cas::~HOMARD_Cas()
//=============================================================================
{
  MESSAGE("~HOMARD_Cas");
}

//=============================================================================
void HOMARD_Cas::SetDirName( const char* NomDir )
//=============================================================================
{
     MESSAGE("SetDirName, NomDir :  "<<NomDir);
     if (chdir(NomDir) == 0)
     {
       _NomDir = std::string( NomDir );
     }
    else
    {
       // GERALD -- QMESSAGE BOX
       // std::cerr << "Pb pour entrer dans le repertoire :  "<<NomDir << std::endl;
       _NomDir = "/tmp";
    };
}

//=============================================================================
std::string HOMARD_Cas::GetDirName() const
//=============================================================================
{
  return _NomDir;
}

//=============================================================================
void HOMARD_Cas::SetName( const char* NomCas )
//=============================================================================
{
  _NomCas = std::string( NomCas );
}

//=============================================================================
std::string HOMARD_Cas::GetName() const
//=============================================================================
{
  return _NomCas;
}


//=============================================================================
std::string HOMARD_Cas::GetDumpPython() const
//=============================================================================
{
  std::ostringstream aScript;
  aScript << "\t" <<_NomCas << ".SetDirName(\"";
  aScript << _NomDir << "\")\n";
  aScript << "\t" <<_NomCas << ".SetConfType(";
  aScript << _ConfType << ")\n";
// Suivi de frontieres
  std::list<std::string>::const_iterator it = _ListBoundaryGroup.begin();
  while(it != _ListBoundaryGroup.end())
  {
    aScript << "\t" <<_NomCas << ".AddBoundaryGroup(\"";
    aScript << *it << "\", \"";
    it++;
    aScript << *it << "\")\n";
    it++;
  }
  if ( _Pyram > 0 )
  {
    aScript << "\t" <<_NomCas << ".SetPyram(";
    aScript << _Pyram << ")\n";
  }

  return aScript.str();
}
//=============================================================================
void HOMARD_Cas::AddIteration( const char* NomIteration )
//=============================================================================
{
  _ListIter.push_back( std::string( NomIteration ) );
}

//=============================================================================
const std::list<std::string>& HOMARD_Cas::GetIterations() const
//=============================================================================
{
  return _ListIter;
}

//=============================================================================
void HOMARD_Cas::SupprIterations()
//=============================================================================
{
  _ListIter.clear();
}

//=============================================================================
std::string HOMARD_Cas::GetIter0Name() const
//=============================================================================
{
// Par construction de la liste, l'iteration a ete mise en tete.
  return (*(_ListIter.begin()));
}

//=============================================================================
void HOMARD_Cas::SetConfType( int Conftype )
//=============================================================================
{
  _ConfType = Conftype;
}
//=============================================================================
const int HOMARD_Cas::GetConfType() const
//=============================================================================
{
  return _ConfType;
}
//=============================================================================
int HOMARD_Cas::GetNumber()
//=============================================================================

{
  return _ListIter.size();
}
//
// La boite englobante
//
//=============================================================================
void HOMARD_Cas::SetBoundingBox( const std::vector<double>& extremas )
//=============================================================================
{
  _Boite.clear();
  _Boite.resize( extremas.size() );
  for ( int i = 0; i < extremas.size(); i++ )
    _Boite[i] = extremas[i];
}

//=============================================================================
const std::vector<double>& HOMARD_Cas::GetBoundingBox() const
//=============================================================================
{
  return _Boite;
}
//
// Les groupes
//
//=============================================================================
const std::list<std::string>& HOMARD_Cas::GetGroups() const
//=============================================================================
{
  return _ListGroup;
}
//=============================================================================
void HOMARD_Cas::SupprGroups()
//=============================================================================
{
  _ListGroup.clear();
}
//=============================================================================
void HOMARD_Cas::SetGroups( const std::list<std::string>& ListGroup )
//=============================================================================
{
  _ListGroup.clear();
  std::list<std::string>::const_iterator it = ListGroup.begin();
  while(it != ListGroup.end())
  {
    _ListGroup.push_back((*it++));
  }
}
//=============================================================================
void HOMARD_Cas::AddGroup( const char* Group )
{
  _ListGroup.push_back(Group);
}
//
// Les frontieres
//
//=============================================================================
const std::list<std::string>& HOMARD_Cas::GetBoundaryGroup() const
//=============================================================================
{
  return _ListBoundaryGroup;
}
//=============================================================================
void HOMARD_Cas::AddBoundaryGroup( const char* Boundary, const char* Group )
{
  _ListBoundaryGroup.push_back( Boundary );
  _ListBoundaryGroup.push_back( Group    );
}
//=============================================================================
void HOMARD_Cas::SupprBoundaryGroup()
//=============================================================================
{
  _ListBoundaryGroup.clear();
}
//=============================================================================
void HOMARD_Cas::SetPyram( int Pyram )
//=============================================================================
{
  MESSAGE ("SetPyram, Pyram = " << Pyram );
  _Pyram = Pyram;
}
//=============================================================================
const int HOMARD_Cas::GetPyram() const
//=============================================================================
{
  MESSAGE ("GetPyram, Pyram = " << _Pyram );
  return _Pyram;
}
