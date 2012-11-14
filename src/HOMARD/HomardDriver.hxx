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

# ifndef __HOMARDDRIVER_H__
# define __HOMARDDRIVER_H__

#include <iostream>
#include <fstream>

class HomardDriver
{
public:
  HomardDriver(const std::string siter, const std::string siterp1);
  ~HomardDriver();
  //
  void        TexteInit( const std::string DirCompute, const std::string DirComputePa, const std::string MessFile );
  void        CreeFichier();
  void        TexteMaillage( const std::string NomMesh, const std::string MeshFile, int apres );
  void        TexteConfRaffDera( int ConfType, int TypeAdap, int TypeRaff, int TypeDera );
  void        TexteZone( int NumeZone, int ZoneType, int TypeUse, double x0, double x1, double x2, double x3, double x4, double x5, double x6, double x7, double x8 );
  void        TexteGroup( const std::string GroupName );
  void        TexteField( const std::string FieldName, const std::string FieldFile,
                          int TimeStep, int Rank,
                          int TypeThR, double ThreshR, int TypeThC, double ThreshC,
                          int UsField, int UsCmpI );
  void        TexteCompo( int NumeComp, const std::string NomCompo);

  void        TexteBoundaryOption( int BoundaryOption );
  void        TexteBoundaryDi( const std::string MeshName, const std::string MeshFile );
  void        TexteBoundaryDiGr( const std::string GroupName );
  void        TexteBoundaryAn( const std::string NameBoundary, int NumeBoundary, int BoundaryType, double x0, double x1, double x2, double x3, double x4, double x5, double x6 );
  void        TexteBoundaryAnGr( const std::string NameBoundary, int NumeBoundary, const std::string GroupName );

  void        TexteFieldInterp( int TypeFieldInterp, const std::string FieldFile, const std::string MeshFile,
                                int TimeStep, int Rank );
  void        TexteFieldInterpName( int NumeChamp, const std::string FieldName);
  void        TexteAdvanced( int Pyram, int NivMax, double DiamMin, int AdapInit, int LevelOutput);
  void        CloseFichier();
  //
  int         ExecuteHomard();
  //
  bool        LireFichier();
  bool        EcrireFichier();
  void        SetTexte( const std::string texte );
  std::string GetTexte();
  std::string GetFichierInfo();
  std::string GetFichierBasic();
  std::string GetFichierResultMed();
  std::string GetFichierHomard();
  int         GetFichierNumeroIter();

public:
  std::string _HOMARD_Exec;
  std::string _NomDir;
  std::string _NomFichierConfBase;
  std::string _NomFichierConf;
  std::string _siter;
  std::string _siterp1;
  std::string _Texte;
  int         _TimeStep;
  int         _Rank;
  bool _bLu;

private :
  std::string GetStringInTexte( std::string chaineCherchee, int longueur = 9 );
};

# endif         /* # ifndef __HOMARDDRIVER_H__ */
