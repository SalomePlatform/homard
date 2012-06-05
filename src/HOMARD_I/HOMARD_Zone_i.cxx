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

#include "HOMARD_Zone_i.hxx"
#include "HOMARD_Gen_i.hxx"
#include "HOMARD_Zone.hxx"
#include "HOMARD_DriverTools.hxx"

#include "utilities.h"

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Zone_i::HOMARD_Zone_i()
{
  MESSAGE( "Default constructor, not for use" );
  ASSERT( 0 );
}

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Zone_i::HOMARD_Zone_i( CORBA::ORB_ptr orb,
			      HOMARD::HOMARD_Gen_var engine )
{
  MESSAGE( "HOMARD_Zone_i" );
  _gen_i = engine;
  _orb = orb;
  myHomardZone = new ::HOMARD_Zone();
  ASSERT( myHomardZone );
}
//=============================================================================
/*!
 *  standard destructor
 */
//=============================================================================

HOMARD_Zone_i::~HOMARD_Zone_i()
{
}

//=============================================================================
/*!
 */
//=============================================================================
void HOMARD_Zone_i::SetName( const char* NomZone )
{
  ASSERT( myHomardZone );
  myHomardZone->SetName( NomZone );
}

//=============================================================================
char* HOMARD_Zone_i::GetName()
{
  ASSERT( myHomardZone );
  return CORBA::string_dup( myHomardZone->GetName().c_str() );
}

//=============================================================================
char* HOMARD_Zone_i::GetDumpPython()
{
  ASSERT( myHomardZone );
  return CORBA::string_dup( myHomardZone->GetDumpPython().c_str() );
}


//=============================================================================
void HOMARD_Zone_i::SetZoneType( CORBA::Long ZoneType )
{
  ASSERT( myHomardZone );
  myHomardZone->SetZoneType( ZoneType );
}

//=============================================================================
CORBA::Long HOMARD_Zone_i::GetZoneType()
{
  ASSERT( myHomardZone );
  return  CORBA::Long( myHomardZone->GetZoneType() );
}

//=============================================================================
void HOMARD_Zone_i::SetBox( double X0, double X1, double X2, double X3, double X4, double X5 )
{
  ASSERT( myHomardZone );
  myHomardZone->SetBox( X0, X1, X2, X3, X4, X5 );
}

//=============================================================================
HOMARD::double_array* HOMARD_Zone_i::GetCoords()
{
  ASSERT( myHomardZone );
  HOMARD::double_array_var aResult = new HOMARD::double_array();
  std::vector<double> mesCoor = myHomardZone->GetCoords();
  aResult->length( mesCoor .size() );
  std::vector<double>::const_iterator it;
  int i = 0;
  for ( it = mesCoor.begin(); it != mesCoor.end(); it++ )
    aResult[i++] = (*it);
  return aResult._retn();
}

//=============================================================================
void HOMARD_Zone_i::SetSphere( double Xcentre, double Ycentre, double Zcentre, double Rayon )
{
  ASSERT( myHomardZone );
  myHomardZone->SetSphere( Xcentre, Ycentre, Zcentre, Rayon );
}

//=============================================================================
void HOMARD_Zone_i::SetCylinder( double Xcentre, double Ycentre, double Zcentre,
                                 double Xaxis, double Yaxis, double Zaxis,
                                 double Rayon, double Haut )
{
  ASSERT( myHomardZone );
  myHomardZone->SetCylinder( Xcentre, Ycentre, Zcentre, Xaxis, Yaxis, Zaxis, Rayon, Haut );
}
//=============================================================================
void HOMARD_Zone_i::SetPipe( double Xcentre, double Ycentre, double Zcentre,
                             double Xaxis, double Yaxis, double Zaxis,
                             double Rayon, double Haut, double Rayonint )
{
  ASSERT( myHomardZone );
  myHomardZone->SetPipe( Xcentre, Ycentre, Zcentre, Xaxis, Yaxis, Zaxis, Rayon, Haut, Rayonint );
}

//=============================================================================
void HOMARD_Zone_i::SetLimit( double Xincr, double Yincr, double Zincr )
{
  MESSAGE ("SetLimit, Xincr : " << Xincr << ", Yincr : " << Yincr << ", Zincr : " << Zincr) ;
  ASSERT( myHomardZone );
  myHomardZone->SetLimit( Xincr, Yincr, Zincr );
}

//=============================================================================
HOMARD::double_array* HOMARD_Zone_i::GetLimit()
{
  ASSERT( myHomardZone );
  HOMARD::double_array_var aResult = new HOMARD::double_array();
  std::vector<double> mesCoor = myHomardZone->GetLimit();
  aResult->length( mesCoor .size() );
  std::vector<double>::const_iterator it;
  int i = 0;
  for ( it = mesCoor.begin(); it != mesCoor.end(); it++ )
    aResult[i++] = (*it);
  return aResult._retn();
}

//=============================================================================
void HOMARD_Zone_i::AddHypo( const char* NomHypo )
{
  MESSAGE ( " AddHypo, NomHypo= " << NomHypo);
  ASSERT( myHomardZone );
  myHomardZone->AddHypo( NomHypo );
  MESSAGE ( " FIn de AddHypo");
}

//=============================================================================
void HOMARD_Zone_i::SupprHypo( const char* NomHypo )
{
  ASSERT( myHomardZone );
  myHomardZone->SupprHypo( NomHypo );
}
//=============================================================================
HOMARD::listeHypo* HOMARD_Zone_i::GetHypo()
{
  ASSERT( myHomardZone );
  const std::list<std::string>& maListe = myHomardZone->GetHypo();
  HOMARD::listeHypo_var aResult = new HOMARD::listeHypo;
  aResult->length( maListe.size() );
  std:: list<std::string>::const_iterator it;
  int i = 0;
  for ( it = maListe.begin(); it != maListe.end(); it++ )
    aResult[i++] = CORBA::string_dup( (*it).c_str() );
  return aResult._retn();
}

//=============================================================================
std::string HOMARD_Zone_i::Dump() const
{
  return HOMARD::Dump( *myHomardZone );
}

//=============================================================================
bool HOMARD_Zone_i::Restore( const std::string& stream )
{
  return HOMARD::Restore( *myHomardZone, stream );
}
