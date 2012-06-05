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
//  File   : HOMARD_Iteration.hxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD

#ifndef _HOMARD_ITER_HXX_
#define _HOMARD_ITER_HXX_

#include <string>
#include <list>

class  HOMARD_Iteration
{
public:
  HOMARD_Iteration();
  ~HOMARD_Iteration();

  void                          SetName( const char* NomIter );
  std::string                   GetName() const;
  std::string                   GetDumpPython() const;

  void                          SetEtat( bool etat );
  bool                          GetEtat() const;

  void                          SetNumber( int NumIter );
  int                           GetNumber() const;

  void                          SetMeshFile( const char* MeshFile );
  std::string                   GetMeshFile() const;

  void                          SetMeshName( const char* NomMesh );
  std::string                   GetMeshName() const;

  void                          SetFieldFile( const char* FieldFile );
  std::string                   GetFieldFile() const;
  void                          SetTimeStepRank( int TimeStep, int Rank );
  int                           GetTimeStep() const;
  int                           GetRank() const;

  void                          SetIterParent( const char* iterParent );
  std::string                   GetIterParent() const;

  void                          AddIteration( const char* iter );
  const std::list<std::string>& GetIterations() const;
  void                          SupprIterations();

  void                          SetHypoName( const char* NomHypo );
  std::string                   GetHypoName() const;

  void                          SetCaseName( const char* NomCas );
  std::string                   GetCaseName() const;

  void                          SetDirName( const char* NomDir );
  std::string                   GetDirName() const;

  void                          SetMessFile( const char* MessFile );
  std::string                   GetMessFile() const;

private:
  std::string                   _NomIter;
  bool                          _Etat;
  int                           _NumIter;
  std::string                   _NomMesh;
  std::string                   _MeshFile;
  std::string                   _FieldFile;
  int                           _TimeStep;
  int                           _Rank;
  std::string                   _MessFile;
  std::string                   _IterParent;
  std::string                   _NomHypo;
  std::string                   _NomCas;
  std::string                   _NomDir;
  std::list<std::string>        _mesIterFilles;
};

#endif
