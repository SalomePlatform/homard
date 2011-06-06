//  HOMARD HOMARD : implementaion of HOMARD idl descriptions
//
// Copyright (C) 2011  CEA/DEN, EDF R&D
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
//  File   : HOMARD_Zone.cxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD

#include "HOMARD_Zone.hxx"
#include "utilities.h"

//=============================================================================
/*!
 *  default constructor:
 */
//=============================================================================
HOMARD_Zone::HOMARD_Zone():
  _NomZone( "" ),_ZoneType( 2 ),
  _Xmin( 0 ), _Xmax( 0 ), _Ymin( 0 ), _Ymax( 0 ), _Zmin( 0 ), _Zmax( 0 ),
  _Xcentre( 0 ), _Ycentre( 0 ), _Zcentre( 0 ), _rayon( 0 ),
  _Xincr( 0 ), _Yincr( 0 ), _Zincr( 0 )
{
  MESSAGE("HOMARD_Zone");
}

//=============================================================================
HOMARD_Zone::~HOMARD_Zone()
{
  MESSAGE("~HOMARD_Zone");
}

//=============================================================================
void HOMARD_Zone::SetName( const char* NomZone )
{
  _NomZone = std::string( NomZone );
}

//=============================================================================
std::string HOMARD_Zone::GetName() const
{
  return _NomZone;
}

//=============================================================================
std::string HOMARD_Zone::GetDumpPython() const
{
  std::ostringstream aScript;
  aScript << "\n# Creation of the ";
  if ( _ZoneType == 2 ) { aScript << "box "  << _NomZone << "\n";}
  if ( _ZoneType == 4 ) { aScript << "sphere " << _NomZone << "\n"; }

  aScript << "\t" << _NomZone << " = homard.CreateZone('" << _NomZone ;
  aScript << "', " << _ZoneType << ")\n";
//
  switch (_ZoneType)
  {
    case 2:
    {
      aScript << "\t" << _NomZone << ".SetBox(" ;
      aScript << _Xmin << ", " << _Xmax << ", " << _Ymin << ", " << _Ymax << ", " << _Zmin << ", " << _Zmax << ")\n";
      break;
    }

    case 4:
    {
      aScript << "\t" << _NomZone << ".SetSphere(" ;
      aScript << _Xcentre << ", " << _Ycentre << ", " << _Zcentre << ", " << _rayon << ")\n";
      break;
    }
  }

  return aScript.str();
}


//=============================================================================
void HOMARD_Zone::SetZoneType( int ZoneType )
{
  _ZoneType = ZoneType;
}

//=============================================================================
int HOMARD_Zone::GetZoneType() const
{
  return _ZoneType;
}

//======================================================================
void HOMARD_Zone::SetLimit( double X0, double X1, double X2 )
{
  _Xincr = X0; _Yincr = X1; _Zincr = X2;
}
//=======================================================================================
void HOMARD_Zone::SetBox( double X0, double X1, double X2, double X3, double X4, double X5 )
{
  _Xmin = X0; _Xmax = X1;
  _Ymin = X2; _Ymax = X3;
  _Zmin = X4; _Zmax = X5;
}

//======================================================================
void HOMARD_Zone::SetSphere( double X0, double X1, double X2, double X3 )
{
  _Xcentre = X0; _Ycentre = X1; _Zcentre = X2;
  _rayon = X3;
}

//=======================================================================================
std::vector<double> HOMARD_Zone::GetLimit() const
{
  std::vector<double> mesLimit;
  mesLimit.push_back( _Xincr );
  mesLimit.push_back( _Yincr );
  mesLimit.push_back( _Zincr );
  return mesLimit;
}

//=======================================================================================
std::vector<double> HOMARD_Zone::GetBox() const
{
  std::vector<double> mesCoor;
  mesCoor.push_back( _Xmin ); mesCoor.push_back( _Xmax );
  mesCoor.push_back( _Ymin ); mesCoor.push_back( _Ymax );
  mesCoor.push_back( _Zmin ); mesCoor.push_back( _Zmax );
  return mesCoor;
}

//=======================================================================================
std::vector<double> HOMARD_Zone::GetSphere() const
{
  std::vector<double> mesCoor;
  mesCoor.push_back( _Xcentre );
  mesCoor.push_back( _Ycentre );
  mesCoor.push_back( _Zcentre ); 
  mesCoor.push_back( _rayon );
  return mesCoor;
}

//=============================================================================
void HOMARD_Zone::AddHypo( const char* NomHypo )
{
  _ListHypo.push_back( std::string( NomHypo ) );
}

//=============================================================================
void HOMARD_Zone::SupprHypo( const char* NomHypo )
{
  std::list<std::string>::iterator it = find( _ListHypo.begin(), _ListHypo.end(), NomHypo );
  if ( it != _ListHypo.end() ) 
  {
    MESSAGE ("Dans SupprHypo pour " << NomHypo);
    _ListHypo.erase( it );
  }
}

//=============================================================================
const std::list<std::string>& HOMARD_Zone::GetHypo() const
{
  return _ListHypo;
}

//=============================================================================
void HOMARD_Zone::SupprHypos()
{
  _ListHypo.clear();
}
