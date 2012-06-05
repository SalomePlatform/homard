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
  if ( !(dirchar = getenv("HOMARD_REP_EXE_PRIVATE")) )
  { dirchar = getenv("HOMARD_REP_EXE") ; }
  dir = std::string(dirchar);
  MESSAGE("HomardDriver, dirchar ="<<dirchar<<", dir ="<<dir);
  if ( !(execchar = getenv("HOMARD_EXE_PRIVATE")) )
  { execchar = getenv("HOMARD_EXE"); }
  executable = std::string(execchar);
  MESSAGE("HomardDriver, execchar ="<<execchar<<", executable ="<<executable);
  _HOMARD_Exec = dir + "/" + executable ;
  MESSAGE("HomardDriver, _HOMARD_Exec ="<<_HOMARD_Exec);
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
  MESSAGE("TexteInit, MessFile ="<<MessFile<<", DirCompute ="<<DirCompute<<", DirComputePa ="<<DirComputePa);
//
  _Texte  = "Action   homa\n" ;
  _Texte += "CCAssoci med\n" ;
  _Texte += "ModeHOMA 1\n" ;
  _Texte += "NumeIter " + _siter + "\n" ;
  _Texte += "ListeStd \"" + MessFile + "\"\n" ;
  _Texte += "# Maillages HOMARD \n" ;
  _Texte += "HOMaiN__ Mai" + _siter   + " \"" + DirComputePa + "/maill." + _siter   + ".hom.med\"\n" ;
  _Texte += "HOMaiNP1 Mai" + _siterp1 + " \"" + DirCompute   + "/maill." + _siterp1 + ".hom.med\"\n" ;
  _Texte += "RepeTrav \"" + DirCompute + "\"\n" ;
//
}

////=============================================================================
void HomardDriver::TexteMaillage( const std::string NomMesh, const std::string MeshFile, int apres )
{
  MESSAGE("TexteMaillage, NomMesh ="<<NomMesh<<", MeshFile ="<<MeshFile);
  std::string saux ;
  saux = "P1" ;
  if ( apres < 1 ) { saux = "__" ; }

  _Texte += "# Maillages Med " + saux + "\n" ;
  _Texte += "CCNoMN" + saux + " \"" + NomMesh  + "\"\n" ;
  _Texte += "CCMaiN" + saux + " \"" + MeshFile + "\"\n" ;
}

////=============================================================================
void HomardDriver::TexteConfRaffDera( int ConfType, int TypeAdap, int TypeRaff, int TypeDera )
{
  MESSAGE("TexteConfRaffDera, ConfType ="<<ConfType);
  MESSAGE("TexteConfRaffDera, TypeAdap ="<<TypeAdap<<", TypeRaff ="<<TypeRaff<<", TypeDera ="<<TypeDera);
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
  MESSAGE("TexteCompo, NumeComp = "<<NumeComp<<", NompCompo = "<<NompCompo);
  _Texte +="CCCoChaI \"" + NompCompo + "\"\n" ;
}

////=============================================================================
void HomardDriver::TexteZone( int NumeZone, int ZoneType, int TypeUse, double x0, double x1, double x2, double x3, double x4, double x5, double x6, double x7, double x8 )
{
  MESSAGE("TexteZone, NumeZone = "<<NumeZone<<", ZoneType = "<<ZoneType<<", TypeUse = "<<TypeUse);
  MESSAGE("TexteZone, coor = "<< x0<<","<<x1<< ","<< x2<< ","<< x3<<","<<x4<<","<<x5<<","<<x6<<","<<x7<<","<<x8);
//
  std::string saux, saux2 ;
//
// Type de zones
// On convertit le type de zone au sens du module HOMARD dans Salome, ZoneType, dans le
// type au sens de l'executable HOMARD, ZoneTypeHOMARD
// Attention a mettre le bon signe a ZoneTypeHOMARD :
//    >0 signifie que l'on raffinera les mailles contenues dans la zone,
//    <0 signifie que l'on deraffinera
//
  int ZoneTypeHOMARD ;
  if ( ZoneType >= 11 and ZoneType <= 13 ) { ZoneTypeHOMARD = 1 ; }
  else if ( ZoneType >= 31 and ZoneType <= 33 ) { ZoneTypeHOMARD = 3 ; }
  else if ( ZoneType >= 61 and ZoneType <= 63 ) { ZoneTypeHOMARD = 6 ; }
  else { ZoneTypeHOMARD = ZoneType ; }
//
  if ( TypeUse < 0 ) { ZoneTypeHOMARD = -ZoneTypeHOMARD ; }
//
  std::stringstream saux1 ;
  saux1 << NumeZone ;
  saux2 = saux1.str() ;
  saux = "#\n# Zone numero " + saux2 + "\n" ;
//
  { std::stringstream saux1 ;
    saux1 << NumeZone << " " << ZoneTypeHOMARD ;
    saux2 = saux1.str() ;
    saux += "ZoRaType " + saux2 + "\n" ;
  }
//
// Cas du rectangle
//
  if ( ZoneType == 11 ) // Z est constant X Homard <=> X Salome
//                                        Y Homard <=> Y Salome
  {
    saux += "#Rectangle\n" ;
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
  }
//
  else if ( ZoneType == 12 ) // X est constant X Homard <=> Y Salome
//                                             Y Homard <=> Z Salome
  {
    saux += "#Rectangle\n" ;
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x2 ;
      saux2 = saux1.str() ;
      saux += "ZoRaXmin " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x3 ;
      saux2 = saux1.str() ;
      saux += "ZoRaXmax " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x4 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYmin " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x5 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYmax " + saux2 + "\n" ;
    }
  }
//
  else if ( ZoneType == 13 ) // Y est constant X Homard <=> X Salome
//                                             Y Homard <=> Z Salome
  {
    saux += "#Rectangle\n" ;
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
      saux1 << NumeZone << " " << x4 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYmin " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x5 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYmax " + saux2 + "\n" ;
    }
  }
//
// Cas du parallelepipede
//
  else if ( ZoneType == 2 )
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
// Cas du disque
//
  else if ( ZoneType == 31 or ZoneType == 61 )
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
      saux1 << NumeZone << " " << x6 ;
      saux2 = saux1.str() ;
      if ( ZoneType == 61 ) { saux += "ZoRaRayE " + saux2 + "\n" ; }
      else                  { saux += "ZoRaRayo " + saux2 + "\n" ; }
    }
    if ( ZoneType == 61 )
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x8 ;
      saux2 = saux1.str() ;
      saux += "ZoRaRayI " + saux2 + "\n" ;
    }
  }
  else if ( ZoneType == 32 or ZoneType == 62 )
  {
    saux += "# Sphere\n" ;
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x1 ;
      saux2 = saux1.str() ;
      saux += "ZoRaXCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x2 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x6 ;
      saux2 = saux1.str() ;
      if ( ZoneType == 62 ) { saux += "ZoRaRayE " + saux2 + "\n" ; }
      else                  { saux += "ZoRaRayo " + saux2 + "\n" ; }
    }
    if ( ZoneType == 62 )
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x8 ;
      saux2 = saux1.str() ;
      saux += "ZoRaRayI " + saux2 + "\n" ;
    }
  }
  else if ( ZoneType == 33 or ZoneType == 63 )
  {
    saux += "# Sphere\n" ;
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x0 ;
      saux2 = saux1.str() ;
      saux += "ZoRaXCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x2 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYCen " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x6 ;
      saux2 = saux1.str() ;
      if ( ZoneType == 63 ) { saux += "ZoRaRayE " + saux2 + "\n" ; }
      else                  { saux += "ZoRaRayo " + saux2 + "\n" ; }
    }
    if ( ZoneType == 63 )
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x8 ;
      saux2 = saux1.str() ;
      saux += "ZoRaRayI " + saux2 + "\n" ;
    }
  }
//
// Cas de la sphere
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
// Cas du cylindre ou du tuyau
//
  else if ( ZoneType == 5 or ZoneType == 7 )
  {
    if ( ZoneType == 5 ) { saux += "# Cylindre\n" ; }
    else                 { saux += "# Tuyau\n" ; }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x0 ;
      saux2 = saux1.str() ;
      saux += "ZoRaXBas " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x1 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYBas " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x2 ;
      saux2 = saux1.str() ;
      saux += "ZoRaZBas " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x3 ;
      saux2 = saux1.str() ;
      saux += "ZoRaXAxe " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x4 ;
      saux2 = saux1.str() ;
      saux += "ZoRaYAxe " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x5 ;
      saux2 = saux1.str() ;
      saux += "ZoRaZAxe " + saux2 + "\n" ;
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x6 ;
      saux2 = saux1.str() ;
     if ( ZoneType == 5 ) { saux += "ZoRaRayo " + saux2 + "\n" ; }
     else                 { saux += "ZoRaRayE " + saux2 + "\n" ; }
    }
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x7 ;
      saux2 = saux1.str() ;
      saux += "ZoRaHaut " + saux2 + "\n" ;
    }
    if ( ZoneType == 7 )
    { std::stringstream saux1 ;
      saux1 << NumeZone << " " << x8 ;
      saux2 = saux1.str() ;
      saux += "ZoRaRayI " + saux2 + "\n" ;
    }
  }
//
  _Texte += saux + "#\n" ;
//
//   MESSAGE("A la fin de HomardDriver::TexteZone, _Texte ="<<_Texte);
}

////=============================================================================
void HomardDriver::TexteField( const std::string FieldName, const std::string FieldFile, int TimeStep, int Rank,
               int TypeThR, double ThreshR, int TypeThC, double ThreshC,
               int UsField, int UsCmpI )
{
  MESSAGE("TexteField, FieldName = "<<FieldName<<", FieldFile = "<<FieldFile);
  MESSAGE("TexteField, TimeStep = "<<TimeStep<<", Rank = "<<Rank);

  std::string saux, saux2 ;
//
//
  _Texte += "# Champ d'indicateurs\n" ;
  _Texte += "CCIndica \"" + FieldFile  + "\"\n" ;
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
  if ( UsField == 0 )
  { saux = "MAILLE" ; }
  if ( UsField == 1 )
  { saux = "SAUT" ; }
  if ( saux != " " )
  {
    _Texte += "CCModeFI " + saux  + "\n" ;
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
  MESSAGE("TexteGroup, GroupName = "<<GroupName);
//
  _Texte += "CCGroAda \"" + GroupName  + "\"\n" ;
//
}
////=============================================================================
void HomardDriver::TexteBoundaryOption( int BoundaryOption )
{
  MESSAGE("TexteBoundaryOption, BoundaryOption = "<<BoundaryOption);
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
  MESSAGE("TexteBoundaryDi, MeshName  = "<<MeshName);
  MESSAGE("TexteBoundaryDi, MeshFile  = "<<MeshFile);
//
  _Texte += "CCNoMFro \"" + MeshName + "\"\n" ;
  _Texte += "CCFronti \"" + MeshFile + "\"\n" ;
//
}
////=============================================================================
void HomardDriver::TexteBoundaryDiGr(  const std::string GroupName )
{
  MESSAGE("TexteBoundaryDiGr, GroupName  = "<<GroupName);
//
  _Texte += "CCGroFro \"" + GroupName + "\"\n" ;
//
}
////=============================================================================
void HomardDriver::TexteBoundaryAn( const std::string NameBoundary, int NumeBoundary, int BoundaryType, double x0, double x1, double x2, double x3, double x4, double x5, double x6 )
{
  MESSAGE("TexteBoundaryAn, NameBoundary = "<<NameBoundary);
//   MESSAGE("TexteBoundaryAn, NumeBoundary = "<<NumeBoundary);
  MESSAGE("TexteBoundaryAn, BoundaryType = "<<BoundaryType);
//   MESSAGE("TexteBoundaryAn, coor         = "<< x0<<","<<x1<< ","<< x2<< ","<< x3<<","<<x4<<","<<x5<<","<<x6);
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
    saux += "FANom " + saux2 + " \"" + NameBoundary + "\"\n" ;
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
  MESSAGE("TexteBoundaryAnGr, NameBoundary  = "<<NameBoundary);
//   MESSAGE("TexteBoundaryAnGr, NumeBoundary  = "<<NumeBoundary);
//   MESSAGE("TexteBoundaryAnGr, GroupName  = "<<GroupName);
//
// Commentaires
//
  std::string saux, saux2 ;
  std::stringstream saux1 ;
  saux1 << NumeBoundary ;
  saux2 = saux1.str() ;
  saux = "#\n# Lien Frontiere/Groupe numero " + saux2 + "\n" ;
//
  saux += "FGNomFro " + saux2 + " \"" + NameBoundary + "\"\n" ;
  saux += "FGNomGro " + saux2 + " \"" + GroupName + "\"\n" ;
//
  _Texte += saux + "#\n" ;
//
}
////=============================================================================
void HomardDriver::TexteFieldInterp( int TypeFieldInterp, const std::string FieldFile, const std::string MeshFile, int TimeStep, int Rank )
{
  MESSAGE("TexteFieldInterp, TypeFieldInterp = "<<TypeFieldInterp);
  MESSAGE("TexteFieldInterp, FieldFile = "<<FieldFile<<", MeshFile = "<<MeshFile);
  MESSAGE("TexteFieldInterp, TimeStep = "<<TimeStep<<", Rank = "<<Rank);
//
// Type d'interpolation
//
  _Texte += "# Interpolations des champs\n" ;
  _Texte += "CCSolN__ \"" + FieldFile + "\"\n" ;
  _Texte += "CCSolNP1 \"" + MeshFile  + "\"\n" ;
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
  MESSAGE("TexteFieldInterpName, NumeChamp = "<<NumeChamp<<", FieldName = "<<FieldName);
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
void HomardDriver::TexteAdvanced( int Pyram, int NivMax, double DiamMin, int AdapInit )
{
  MESSAGE("TexteAdvanced, Pyram ="<<Pyram<<", NivMax ="<<NivMax<<", DiamMin ="<<DiamMin<<", AdapInit ="<<AdapInit);
  std::string saux ;

  if ( Pyram > 0 )
  {
    _Texte += "# Autorisation de pyramides dans le maillage initial\n" ;
    _Texte += "TypeElem ignore_pyra\n" ;
  }
  if ( NivMax > 0 )
  {
    _Texte += "# Niveaux extremes\n" ;
    { std::stringstream saux1 ;
      saux1 << NivMax ;
      std::string saux2 = saux1.str() ;
      _Texte += "NiveauMa " + saux2 + "\n" ;
    }
  }
  if ( DiamMin > 0 )
  {
    _Texte += "# Diametre minimal\n" ;
    { std::stringstream saux1 ;
      saux1 << DiamMin ;
      std::string saux2 = saux1.str() ;
      _Texte += "DiametMi " + saux2  + "\n" ;
    }
  }
  if ( AdapInit != 0 )
  {
    if ( AdapInit > 0 )
    { _Texte += "# Raffinement" ; }
    else
    { _Texte += "# Deraffinement" ; }
    _Texte += " des regions sans indicateur\n" ;
    { std::stringstream saux1 ;
      saux1 << AdapInit ;
      std::string saux2 = saux1.str() ;
      _Texte += "AdapInit " + saux2 + "\n" ;
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
