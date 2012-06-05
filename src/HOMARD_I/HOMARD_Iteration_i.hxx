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

#ifndef _HOMARD_ITERATION_I_HXX_
#define _HOMARD_ITERATION_I_HXX_

#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(HOMARD_Gen)
#include CORBA_SERVER_HEADER(HOMARD_Iteration)

#include "SALOME_Component_i.hxx"
#include "SALOME_NamingService.hxx"
#include "Utils_CorbaException.hxx"

#include <string>

class HOMARD_Iteration;

class HOMARD_Iteration_i:
  public virtual Engines_Component_i,
  public virtual POA_HOMARD::HOMARD_Iteration,
  public virtual PortableServer::ServantBase
{
public:
  HOMARD_Iteration_i( CORBA::ORB_ptr orb,
                      HOMARD::HOMARD_Gen_var gen_i );
  HOMARD_Iteration_i();

  virtual ~HOMARD_Iteration_i();

  void                   SetName( const char* NomIteration );
  char*                  GetName();
  char*                  GetDumpPython();

  void                   SetEtat( CORBA::Boolean etat );
  CORBA::Boolean         GetEtat();

  void                   SetNumber( CORBA::Long NumIter );
  CORBA::Long            GetNumber();

  void                   SetMeshName( const char* NomMesh );
  char*                  GetMeshName();

  void                   SetMeshFile( const char* MeshFile );
  char*                  GetMeshFile();

  void                   SetFieldFile( const char* FieldFile );
  char*                  GetFieldFile();
  void                   SetTimeStepRank( CORBA::Long TimeStep, CORBA::Long Rank );
  CORBA::Long            GetTimeStep();
  CORBA::Long            GetRank();

  void                   SetMessFile( const char* MessFile );
  char*                  GetMessFile();

  void                   SetIterParent( const char* NomIterParent );
  char*                  GetIterParent();

  void                   AddIteration( const char* NomIteration );
  HOMARD::listeIterFilles* GetIterations();

  void                   SetCaseName( const char* NomCas );
  char*                  GetCaseName();

  void                   SetDirName( const char* NomDir );
  char*                  GetDirName();

  void                   SetHypoName( const char* NomHypo );
  char*                  GetHypoName();

  CORBA::Long            Compute(CORBA::Long etatMenage);

  std::string            Dump() const;
  bool                   Restore( const std::string& stream );

private:
  ::HOMARD_Iteration*    myHomardIteration;

  CORBA::ORB_ptr         _orb;
  HOMARD::HOMARD_Gen_var _gen_i;
};

#endif
