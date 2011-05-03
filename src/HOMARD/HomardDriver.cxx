#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "Utils_SALOME_Exception.hxx"
#include "utilities.h"
#include "HomardDriver.hxx"

//=============================================================================
//=============================================================================
HomardDriver::HomardDriver(const std::string siter, const std::string siterp1):
  _HOMARD_Exec( "" ), _NomDir( "" ), _NomFichierConfBase( "HOMARD.Configuration" ),
  _NomFichierConf( "" ), _siter( "" ), _siterp1( "" ),
  _Texte( "" ), _bLu( false )
{
// Memorisation du nom complet de l'executable HOMARD
  char* dirchar; char* execchar;
  std::string dir;
  std::string executable;
  if ( !(dirchar = getenv("HOMARD_REP_EXE")) )
    dir = "/logiciels/HOMARD/HOMARD_PUBLIC/Linux64" ;
  else
    dir = std::string(dirchar);
  if ( !(execchar = getenv("HOMARD_EXE")) )
    executable = "HOMARD";
  else
    executable = std::string(execchar);
  _HOMARD_Exec = dir + "/" + executable ;
  MESSAGE("Dans HomardDriver::HomardDriver, _HOMARD_Exec ="<<_HOMARD_Exec);
//
  _siter = siter ;
  _siterp1 = siterp1 ;
}

//=============================================================================
//=============================================================================
HomardDriver::~HomardDriver()
{
}

////=============================================================================
void HomardDriver::TexteInit( const std::string DirCompute, const std::string DirComputePa, const std::string MessFile )
{
  MESSAGE("Dans HomardDriver::TexteInit, MessFile ="<<MessFile);
//
  _Texte  = "Action   homa\n" ;
  _Texte += "CCAssoci med\n" ;
  _Texte += "ModeHOMA 1\n" ;
  _Texte += "NumeIter " + _siter + "\n" ;
  _Texte += "ListeStd " + MessFile + "\n" ;
  _Texte += "# Maillages HOMARD \n" ;
  _Texte += "HOMaiN__ Mai" + _siter   + " " + DirComputePa + "/maill." + _siter   + ".hom.med\n" ;
  _Texte += "HOMaiNP1 Mai" + _siterp1 + " " + DirCompute   + "/maill." + _siterp1 + ".hom.med\n" ;
  _Texte += "RepeTrav " + DirCompute + "\n" ;
//
}

////=============================================================================
void HomardDriver::TexteMaillage( const std::string NomMesh, const std::string MeshFile, int apres )
{
  MESSAGE("Dans HomardDriver::TexteMaillage, NomMesh ="<<NomMesh<<", MeshFile ="<<MeshFile);
  std::string saux ;
  saux = "P1" ;
  if ( apres < 1 ) { saux = "__" ; }

  _Texte += "# Maillages Med " + saux + "\n" ;
  _Texte += "CCNoMN" + saux + " \"" + NomMesh  + "\"\n" ;
  _Texte += "CCMaiN" + saux + " " + MeshFile + "\n" ;
}

////=============================================================================
void HomardDriver::TexteConfRaffDera( int ConfType, int TypeAdap, int TypeRaff, int TypeDera )
{
  MESSAGE("Dans HomardDriver::TexteConfRaffDera, ConfType ="<<ConfType);
  MESSAGE("Dans HomardDriver::TexteConfRaffDera, TypeAdap ="<<TypeAdap<<", TypeRaff ="<<TypeRaff<<", TypeDera ="<<TypeDera);
//
// Type de conformite
//
  std::string saux ;
  switch (ConfType)
  {
    case 1: //
    {
      saux = "conforme" ;
      break;
    }
    case 2: //
    {
      saux = "non_conforme_1_noeud" ;
      break;
    }
    case 3: //
    {
      saux = "non_conforme_1_arete" ;
      break;
    }
    case 4: //
    {
      saux = "non_conforme_indicateur" ;
      break;
    }
  }
  _Texte += "# Type de conformite\nTypeConf " + saux + "\n" ;
//
// Type de raffinement/deraffinement
//
  if ( TypeAdap == -1 )
  {
    if ( TypeRaff == 1 )
    {
      saux = "TypeRaff uniforme\n" ;
    }
    else
    {
      saux = "TypeRaff non\n" ;
    }
    if ( TypeDera == 1 )
    {
      saux += "TypeDera uniforme" ;
    }
    else
    {
      saux += "TypeDera non" ;
    }
  }
  else
  {
    if ( TypeRaff == 1 )
    {
      saux = "TypeRaff libre\n" ;
    }
    else
    {
      saux = "TypeRaff non\n" ;
    }
    if ( TypeDera == 1 )
    {
      saux += "TypeDera libre" ;
    }
    else
    {
      saux += "TypeDera non" ;
    }
  }
  _Texte += "# Type de raffinement/deraffinement\n" + saux + "\n" ;
//
//   MESSAGE("A la fin de HomardDriver::TexteConfRaffDera, _Texte ="<<_Texte);
}
////=============================================================================
void HomardDriver::TexteCompo( int NumeComp, const std::string NompCompo)
{
  MESSAGE("Dans HomardDriver::TexteCompo, NumeComp = "<<NumeComp<<", NompCompo = "<<NompCompo);
  _Texte +="CCCoChaI \"" + NompCompo + "\"\n" ;
}

////=============================================================================
void HomardDriver::TexteZone( int NumeZone, int ZoneType, double x0, double x1, double x2, double x3, double x4, double x5 )
{
  MESSAGE("Dans HomardDriver::TexteZone, NumeZone = "<<NumeZone<<", ZoneType = "<<ZoneType);
  MESSAGE("Dans HomardDriver::TexteZone, coor = "<< x0<<","<<x1<< ","<< x2<< ","<< x3<<","<<x4<<","<<x5);
//
  std::string saux, saux2 ;
//
// Type de zones
//
  std::stringstream saux1 ;
  saux1 << NumeZone ;
  saux2 = saux1.str() ;
  saux = "#\n# Zone numero " + saux2 + "\n" ;
//
  { std::stringstream saux1 ;
    saux1 << NumeZone << " " << ZoneType ;
    saux2 = saux1.str() ;
    saux += "ZoRaType " + saux2 + "\n" ;
  }
//
// Cas du rectangle/parallelepipede
//
  if ( ZoneType == 2 )
  {
    saux += "# Boite\n" ;
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x0 ;
      saux2 = saux1.str() ;
      saux += "ZoRaXmin " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x1 ;
      saux2 = saux1.str() ;
      saux += "ZoRaXmax " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x2 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYmin " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x3 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYmax " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x4 ;
      saux2 = saux1.str() ;
      saux += "ZoRaZmin " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x5 ;
      saux2 = saux1.str() ;
      saux += "ZoRaZmax " + saux2 + "\n" ;
    }
  }
//
// Cas du cercle/sphere
//
  else if ( ZoneType == 4 )
  {
    saux += "# Sphere\n" ;
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x0 ;
      saux2 = saux1.str() ;
      saux += "ZoRaXCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x1 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x2 ;
      saux2 = saux1.str() ;
      saux += "ZoRaZCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x3 ;
      saux2 = saux1.str() ;
      saux += "ZoRaRayo " + saux2 + "\n" ;
    }
  }
//
  _Texte += saux + "#\n" ;
//
//   MESSAGE("A la fin de HomardDriver::TexteZone, _Texte ="<<_Texte);
}

////=============================================================================
void HomardDriver::TexteField( const std::string FieldName, const std::string FieldFile, int TimeStep, int Rank,
               int TypeThR, double ThreshR, int TypeThC, double ThreshC, int UsCmpI )
{
  MESSAGE("Dans HomardDriver::TexteField, FieldName = "<<FieldName<<", FieldFile = "<<FieldFile);
  MESSAGE("Dans HomardDriver::TexteField, TimeStep = "<<TimeStep<<", Rank = "<<Rank);

  std::string saux, saux2 ;
//
//
  _Texte += "# Champ d'indicateurs\n" ;
  _Texte += "CCIndica " + FieldFile  + "\n" ;
  _Texte += "CCNoChaI \"" + FieldName  + "\"\n" ;

// Cas ou on prend le dernier pas de temps
  if ( TimeStep == -2 )
  { _Texte += "CCNumPTI Last\n" ; }
// Cas avec pas de temps
  else if ( TimeStep >= 0 )
  {
    {
      std::stringstream saux1 ;
      saux1 << TimeStep ;
      saux2 = saux1.str() ;
      _Texte += "CCNumPTI " + saux2  + "\n" ;
    }
    {
      std::stringstream saux1 ;
      saux1 << Rank ;
      saux2 = saux1.str() ;
      _Texte += "CCNumOrI " + saux2  + "\n" ;
    }
  }
//
  saux = " " ;
  if ( TypeThR == 1 )
  { saux = "Hau" ; }
  if ( TypeThR == 2 )
  { saux = "HRe" ; }
  if ( TypeThR == 3 )
  { saux = "HPE" ; }
  if ( saux != " " )
  {
    std::stringstream saux1 ;
    saux1 << ThreshR ;
    saux2 = saux1.str() ;
    _Texte += "Seuil" + saux + " " + saux2  + "\n" ;
  }
//
  saux = " " ;
  if ( TypeThC == 1 )
  { saux = "Bas" ; }
  if ( TypeThC == 2 )
  { saux = "BRe" ; }
  if ( TypeThC == 3 )
  { saux = "BPE" ; }
  if ( saux != " " )
  {
    std::stringstream saux1 ;
    saux1 << ThreshC ;
    saux2 = saux1.str() ;
    _Texte += "Seuil" + saux + " " + saux2  + "\n" ;
  }
//
  saux = " " ;
  if ( UsCmpI == 0 )
  { saux = "L2" ; }
  if ( UsCmpI == 1 )
  { saux = "INFINI" ; }
  if ( UsCmpI == 2 )
  { saux = "V_RELATIVE" ; }
  if ( saux != " " )
  {
    _Texte += "CCUsCmpI " + saux  + "\n" ;
  }
}

////=============================================================================
void HomardDriver::TexteGroup( const std::string GroupName )
{
  MESSAGE("Dans HomardDriver::TexteGroup, GroupName = "<<GroupName);
//
  _Texte += "CCGroAda " + GroupName  + "\n" ;
//
}
////=============================================================================
void HomardDriver::TexteBoundaryOption( int BoundaryOption )
{
  MESSAGE("Dans HomardDriver::TexteBoundaryOption, BoundaryOption = "<<BoundaryOption);
//
// Type de suivi de frontiere
//
  std::stringstream saux1 ;
  saux1 << BoundaryOption ;
  std::string saux = saux1.str() ;
  _Texte += "SuivFron " + saux + "\n" ;
//
}
////=============================================================================
void HomardDriver::TexteBoundaryDi(  const std::string MeshName, const std::string MeshFile )
{
  MESSAGE("Dans HomardDriver::TexteBoundaryDi, MeshName  = "<<MeshName);
  MESSAGE("Dans HomardDriver::TexteBoundaryDi, MeshFile  = "<<MeshFile);
//
  _Texte += "CCNoMFro " + MeshName + "\n" ;
  _Texte += "CCFronti " + MeshFile + "\n" ;
//
}
////=============================================================================
void HomardDriver::TexteBoundaryDiGr(  const std::string GroupName )
{
  MESSAGE("Dans HomardDriver::TexteBoundaryDiGr, GroupName  = "<<GroupName);
//
  _Texte += "CCGroFro " + GroupName + "\n" ;
//
}
////=============================================================================
void HomardDriver::TexteBoundaryAn( const std::string NameBoundary, int NumeBoundary, int BoundaryType, double x0, double x1, double x2, double x3, double x4, double x5, double x6 )
{
  MESSAGE("Dans HomardDriver::TexteBoundaryAn, NameBoundary = "<<NameBoundary);
  MESSAGE("Dans HomardDriver::TexteBoundaryAn, NumeBoundary = "<<NumeBoundary);
  MESSAGE("Dans HomardDriver::TexteBoundaryAn, BoundaryType = "<<BoundaryType);
  MESSAGE("Dans HomardDriver::TexteBoundaryAn, coor         = "<< x0<<","<<x1<< ","<< x2<< ","<< x3<<","<<x4<<","<<x5<<","<<x6);
//
  std::string saux, saux2 ;
//
// Commentaires
//
  std::stringstream saux1 ;
  saux1 << NumeBoundary ;
  saux2 = saux1.str() ;
  saux = "#\n# Frontiere numero " + saux2 + "\n" ;
  if ( BoundaryType == 1 )
  { saux += "# Cylindre\n" ; }
  if ( BoundaryType == 2 )
  { saux += "# Sphere\n" ; }
//
// Le nom de la frontiere
//
  { std::stringstream saux1 ;
    saux1 << NumeBoundary ;
    saux2 = saux1.str() ;
    saux += "FANom " + saux2 + " '" + NameBoundary + "'\n" ;
  }
//
// Type de frontiere
//
  { std::stringstream saux1 ;
    saux1 << NumeBoundary << " " << BoundaryType ;
    saux2 = saux1.str() ;
    saux += "FAType " + saux2 + "\n" ;
  }
//
// Cas du cylindre
//
  if ( BoundaryType == 1 )
  {
    { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x0 ;
      saux2 = saux1.str() ;
      saux += "FAXCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x1 ;
      saux2 = saux1.str() ;
      saux += "FAYCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x2 ;
      saux2 = saux1.str() ;
      saux += "FAZCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x3 ;
      saux2 = saux1.str() ;
      saux += "FAXAxe " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x4 ;
      saux2 = saux1.str() ;
      saux += "FAYAxe " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x5 ;
      saux2 = saux1.str() ;
      saux += "FAZAxe " + saux2 + "\n" ;
    }
     { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x6 ;
      saux2 = saux1.str() ;
      saux += "FARayon " + saux2 + "\n" ;
    }
 }
//
// Cas de la sphere
//
  else if ( BoundaryType == 2 )
  {
    { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x0 ;
      saux2 = saux1.str() ;
      saux += "FAXCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x1 ;
      saux2 = saux1.str() ;
      saux += "FAYCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x2 ;
      saux2 = saux1.str() ;
      saux += "FAZCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeBoundary << " " << x3 ;
      saux2 = saux1.str() ;
      saux += "FARayon " + saux2 + "\n" ;
    }
  }
//
  _Texte += saux + "#\n" ;
//
}
////=============================================================================
void HomardDriver::TexteBoundaryAnGr( const std::string NameBoundary, int NumeBoundary, const std::string GroupName )
{
  MESSAGE("Dans HomardDriver::TexteBoundaryAnGr, NameBoundary  = "<<NameBoundary);
  MESSAGE("Dans HomardDriver::TexteBoundaryAnGr, NumeBoundary  = "<<NumeBoundary);
  MESSAGE("Dans HomardDriver::TexteBoundaryAnGr, GroupName  = "<<GroupName);
//
// Commentaires
//
  std::string saux, saux2 ;
  std::stringstream saux1 ;
  saux1 << NumeBoundary ;
  saux2 = saux1.str() ;
  saux = "#\n# Lien Frontiere/Groupe numero " + saux2 + "\n" ;
//
  saux += "FGNomFro " + saux2 + " '" + NameBoundary + "'\n" ;
  saux += "FGNomGro " + saux2 + " '" + GroupName + "'\n" ;
//
  _Texte += saux + "#\n" ;
//
}
////=============================================================================
void HomardDriver::TexteFieldInterp( int TypeFieldInterp, const std::string FieldFile, const std::string MeshFile, int TimeStep, int Rank )
{
  MESSAGE("Dans HomardDriver::TexteFieldInterp, TypeFieldInterp = "<<TypeFieldInterp);
  MESSAGE("Dans HomardDriver::TexteFieldInterp, FieldFile = "<<FieldFile<<", MeshFile = "<<MeshFile);
  MESSAGE("Dans HomardDriver::TexteFieldInterp, TimeStep = "<<TimeStep<<", Rank = "<<Rank);
//
// Type d'interpolation
//
  _Texte += "# Interpolations des champs\n" ;
  _Texte += "CCSolN__ " + FieldFile  + "\n" ;
  _Texte += "CCSolNP1 " + MeshFile  + "\n" ;
  if ( TypeFieldInterp == 1 )
  {
    _Texte += "CCChaTou oui\n" ;
  }
//
  _TimeStep = TimeStep ;
  _Rank = Rank ;
//
//  std::cerr << "A la fin de TexteFieldInterp _Texte ="<<_Texte << std::endl;
}
////=============================================================================
void HomardDriver::TexteFieldInterpName( int NumeChamp, const std::string FieldName)
{
  MESSAGE("Dans HomardDriver::TexteFieldInterpName, NumeChamp = "<<NumeChamp<<", FieldName = "<<FieldName);
  std::stringstream saux1 ;
  saux1 << NumeChamp+1 ;
  std::string saux = saux1.str() ;
  _Texte +="CCChaNom " + saux + " \"" + FieldName + "\"\n" ;
//
  MESSAGE("TexteFieldInterpName, _TimeStep = "<<_TimeStep<<", _Rank = "<<_Rank);
  if ( _TimeStep >= 0 )
  {
    {
      std::stringstream saux1 ;
      saux1 << _TimeStep ;
      std::string saux2 = saux1.str() ;
      _Texte += "CCChaPdT " + saux + " " + saux2  + "\n" ;
    }
    {
      std::stringstream saux1 ;
      saux1 << _Rank ;
      std::string saux2 = saux1.str() ;
      _Texte += "CCChaNuO " + saux + " " + saux2  + "\n" ;
    }
  }
}


////=============================================================================
void HomardDriver::CreeFichier( )
{
//
  _NomFichierConf = _NomFichierConfBase + "." + _siter + ".vers." + _siterp1 ;
//
  std::ofstream FicConf(_NomFichierConf.c_str(), std::ios::out ) ;
  if (FicConf.is_open() == true)
  {
    FicConf << _Texte << std::endl ;
  }
  FicConf.close() ;
//
}

////=============================================================================
int HomardDriver::ExecuteHomard()
{
// Copie des Fichiers HOMARD
  std::string commande= "cp " + _NomFichierConf + " " + _NomFichierConfBase ;
  system(commande.c_str());

  MESSAGE("ExecuteHomard");
  int codret = system(_HOMARD_Exec.c_str()) ;
  if ( codret != 0)
  {
      // GERALD -- QMESSAGE BOX
      MESSAGE ( "Erreur en executant HOMARD : " << codret );
//       ASSERT("Erreur en executant HOMARD" == 0);
  };

  return codret ;
}
