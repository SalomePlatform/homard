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
  void        TexteZone( int NumeZone, int ZoneType, double x0, double x1, double x2, double x3, double x4, double x5 );
  void        TexteGroup( const std::string GroupName );
  void        TexteField( const std::string FieldName, const std::string FieldFile,
                          int TimeStep, int Rank,
                          int TypeThR, double ThreshR, int TypeThC, double ThreshC, int UsCmpI );
  void        TexteCompo( int NumeComp, const std::string NomCompo);

  void        TexteBoundaryOption( int BoundaryOption );
  void        TexteBoundaryDi( const std::string MeshName, const std::string MeshFile, const std::string GroupName );
  void        TexteBoundaryAn( int NumeBoundary, int BoundaryType, const std::string Group, double x0, double x1, double x2, double x3, double x4, double x5, double x6 );

  void        TexteFieldInterp( int TypeFieldInterp, const std::string FieldFile, const std::string MeshFile,
                                int TimeStep, int Rank );
  void        TexteFieldInterpName( int NumeChamp, const std::string FieldName);
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
