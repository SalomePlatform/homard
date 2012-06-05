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
//  File   : HOMARD_Boundary.hxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD

#ifndef _HOMARD_Boundary_HXX_
#define _HOMARD_Boundary_HXX_

#include <vector>
#include <string>
#include <list>

class HOMARD_Boundary
{
public:
  HOMARD_Boundary();
  ~HOMARD_Boundary();

  void                          SetName( const char* NomBoundary );
  std::string                   GetName() const;
  std::string                   GetDumpPython() const;

  void                          SetLimit( double X0, double X1, double X2 );
  std::vector<double>           GetLimit() const;

  void                          SetMeshFile( const char* MeshFile );
  std::string                   GetMeshFile() const;

  void                          SetMeshName( const char* MeshName );
  std::string                   GetMeshName() const;

  void                          SetCylinder( double X0, double X1, double X2, double X3,
                                             double X4, double X5, double X6 );
  void                          SetSphere( double X0, double X1, double X2, double X3 );
  std::vector<double>           GetCoords() const;

  void                          SetBoundaryType( int BoundaryType );
  int                           GetBoundaryType() const;

  std::string                   GetCaseCreation() const;
  void                          SetCaseCreation( const char* NomCasCreation );

  void                          AddGroup( const char* LeGroupe);
  void                          SetGroups(const std::list<std::string>& ListGroup );
  const std::list<std::string>& GetGroups() const;

private:
  std::string                   _NomBoundary;
  std::string                   _NomCasCreation;
  std::string                   _MeshFile;
  std::string                   _MeshName;
  int                           _BoundaryType;
  double                        _Xmin, _Xmax, _Ymin, _Ymax, _Zmin, _Zmax;
  double                        _Xaxe, _Yaxe, _Zaxe;
  double                        _Xcentre, _Ycentre, _Zcentre, _rayon;
  double                        _Xincr, _Yincr, _Zincr;

  std::list<std::string>        _ListGroupSelected;

};


#endif
