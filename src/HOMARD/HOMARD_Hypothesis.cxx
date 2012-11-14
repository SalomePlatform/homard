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
//  File   : HOMARD_Hypothesis.cxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD

#include "HOMARD_Hypothesis.hxx"
#include "utilities.h"

//=============================================================================
/*!
 *  default constructor:
 */
//=============================================================================
HOMARD_Hypothesis::HOMARD_Hypothesis():
  _NomHypo(""), _NomCasCreation(""),
  _TypeAdap(-1), _TypeRaff(0), _TypeDera(0),
  _Field(""),
  _TypeThR(0), _ThreshR(0),
  _TypeThC(0), _ThreshC(0),
  _UsField(0), _UsCmpI(0),  _TypeFieldInterp(0)
{
  MESSAGE("HOMARD_Hypothesis");
}

//=============================================================================
/*!
 */
//=============================================================================
HOMARD_Hypothesis::~HOMARD_Hypothesis()
{
  MESSAGE("~HOMARD_Hypothesis");
}

//=============================================================================
/*!
 */
//=============================================================================
void HOMARD_Hypothesis::SetCaseCreation( const char* NomCasCreation )
{
  _NomCasCreation = std::string( NomCasCreation );
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Hypothesis::GetCaseCreation() const
{
  return _NomCasCreation;
}
//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Hypothesis::SetName( const char* NomHypo )
{
  _NomHypo = std::string( NomHypo );
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Hypothesis::GetName() const
{
  return _NomHypo;
}
//=============================================================================
std::string HOMARD_Hypothesis::GetDumpPython() const
{
  std::ostringstream aScript;
  aScript << "\n# Creation of the hypothesis " << _NomHypo << "\n" ;
  aScript << "\t" << _NomHypo << " = homard.CreateHypothesis(\"" << _NomHypo << "\")\n";
  aScript << "\t" << _NomHypo << ".SetAdapRefinUnRef(" << _TypeAdap << ", " << _TypeRaff << ", " << _TypeDera << ")\n";

// Raffinement selon des zones geometriques
  std::list<std::string>::const_iterator it = _ListZone.begin();
  int TypeUse ;
  while(it != _ListZone.end())
  {
      aScript << "\thomard.AssociateHypoZone(\""<< _NomHypo << "\", \"" << *it;
      it++;
      if ( *it == "1" ) { TypeUse =  1 ; }
      else              { TypeUse = -1 ; }
      aScript << "\", " << TypeUse << ")\n";
      it++;
  }

// Raffinement selon un champ
  if ( _TypeAdap == 1 )
  {
    aScript << "\t" << _NomHypo << ".SetField(\"" << _Field << "\")\n";
    aScript << "\t" << _NomHypo << ".SetUseField(" << _UsField << ")\n";
    aScript << "\t" << _NomHypo << ".SetUseComp(" << _UsCmpI << ")\n";
    std::list<std::string>::const_iterator it_comp = _ListComposant.begin();
    while(it_comp != _ListComposant.end())
    {
      aScript << "\t" << _NomHypo << ".AddComp(\"" << *it_comp << "\")\n";
      it_comp++;
    }
    if ( _TypeRaff == 1 )
    {
      aScript << "\t" << _NomHypo << ".SetRefinThr(" << _TypeThR << ", " << _ThreshR << ")\n";
    }
    if ( _TypeDera == 1 )
    {
      aScript << "\t" << _NomHypo << ".SetUnRefThr(" << _TypeThC << ", " << _ThreshC << ")\n";
    }
  }

// Filtrage du raffinement par des groupes
   for ( it=_ListGroupSelected.begin(); it!=_ListGroupSelected.end();it++)
       aScript << "\t" << _NomHypo << ".AddGroup(\""  << (*it) <<  "\")\n" ;

// Interpolation champ
  aScript << "\t" << _NomHypo << ".SetTypeFieldInterp(" << _TypeFieldInterp << ")\n";
  if ( _TypeFieldInterp == 2 )
  {
    std::list<std::string>::const_iterator it_champ = _ListFieldInterp.begin();
    while(it_champ != _ListFieldInterp.end())
    {
      aScript << "\t" << _NomHypo << ".AddFieldInterp(\"" << *it_champ << "\")\n";
      it_champ++;
    }
  }
  if ( _NivMax > 0 )
  {
    aScript << "\t" <<_NomHypo << ".SetNivMax(" << _NivMax << ")\n";
  }
  if ( _DiamMin > 0 )
  {
    aScript << "\t" <<_NomHypo << ".SetDiamMin(" << _DiamMin << ")\n";
  }
  if ( _AdapInit != 0 )
  {
    aScript << "\t" <<_NomHypo << ".SetAdapInit(" << _AdapInit << ")\n";
  }
  if ( _LevelOutput != 0 )
  {
    aScript << "\t" <<_NomHypo << ".SetLevelOutput(" << _LevelOutput << ")\n";
  }

  return aScript.str();
}


//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Hypothesis::SetAdapType( int TypeAdap )
{
  ASSERT (!((TypeAdap < -1) or (TypeAdap > 1)));
  _TypeAdap = TypeAdap;
}

//=============================================================================
/*!
*/
//=============================================================================
int HOMARD_Hypothesis::GetAdapType() const
{
  return _TypeAdap;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Hypothesis::SetRefinTypeDera( int TypeRaff, int TypeDera )
{
  ASSERT(!(( TypeRaff < 0) or (TypeRaff > 1)));
  _TypeRaff = TypeRaff;
  ASSERT(! ((TypeDera < 0) or (TypeDera > 1)));
  _TypeDera = TypeDera;
}

//=============================================================================
/*!
*/
//=============================================================================
int HOMARD_Hypothesis::GetRefinType() const
{
  return _TypeRaff;
}

//=============================================================================
/*!
*/
//=============================================================================
int HOMARD_Hypothesis::GetUnRefType() const
{
  return _TypeDera;
}

//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Hypothesis::SetField( const char* FieldName )
{
  _Field = std::string( FieldName );
  MESSAGE( "SetField : FieldName = " << FieldName );
}
//=============================================================================
void HOMARD_Hypothesis::SetRefinThr( int TypeThR, double ThreshR )
{
  MESSAGE( "SetRefinThr : TypeThR = " << TypeThR << ", ThreshR = " << ThreshR );
  ASSERT(!(( TypeThR < 0) or (TypeThR > 3 )));
  _TypeThR = TypeThR;
  _ThreshR = ThreshR;
}
//=============================================================================
void HOMARD_Hypothesis::SetUnRefThr( int TypeThC, double ThreshC )
{
  ASSERT(!((TypeThC < 0) or (TypeThC > 3)));
  _TypeThC = TypeThC;
  _ThreshC = ThreshC;
}
//=============================================================================
void HOMARD_Hypothesis::SetUseComp( int UsCmpI )
{
  ASSERT(!((UsCmpI < 0) or (UsCmpI > 2)));
  _UsCmpI = UsCmpI;
}
//=============================================================================
void HOMARD_Hypothesis::SetUseField( int UsField )
{
  ASSERT(!((UsField < 0) or (UsField > 1 )));
  _UsField = UsField;
}

//=============================================================================
/*!
*/
//=============================================================================
std::string HOMARD_Hypothesis::GetFieldName() const
{
  return _Field;
}
//=============================================================================
int HOMARD_Hypothesis::GetRefinThrType() const
{
  return _TypeThR;
}
//=============================================================================
double HOMARD_Hypothesis::GetThreshR() const
{
  return _ThreshR;
}
//=============================================================================
int HOMARD_Hypothesis::GetUnRefThrType() const
{
  return _TypeThC;
}

//=============================================================================
double HOMARD_Hypothesis::GetThreshC() const
{
  return _ThreshC;
}
//=============================================================================
int HOMARD_Hypothesis::GetUseField() const
{
  return _UsField;
}
//=============================================================================
int HOMARD_Hypothesis::GetUseCompI() const
{
  return _UsCmpI;
}
//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Hypothesis::AddIteration( const char* NomIteration )
{
  _ListIter.push_back( std::string( NomIteration ) );
}
//=============================================================================
void HOMARD_Hypothesis::SupprIterations()
{
  _ListIter.clear();
}
//=============================================================================
const std::list<std::string>& HOMARD_Hypothesis::GetIterations() const
{
  return _ListIter;
}
//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Hypothesis::AddZone( const char* NomZone, int TypeUse )
{
  _ListZone.push_back( std::string( NomZone ) );
  std::stringstream saux1 ;
  saux1 << TypeUse ;
  std::string saux2 = saux1.str() ;
  _ListZone.push_back( saux2 );
}
//=============================================================================
void HOMARD_Hypothesis::SupprZone( const char* NomZone )
{
  std::list<std::string>::iterator it = find( _ListZone.begin(), _ListZone.end(), NomZone );
  if ( it != _ListZone.end() )
  {
    _ListZone.erase( it );
  }
}
//=============================================================================
void HOMARD_Hypothesis::SupprZones()
{
  _ListZone.clear();
}
//=============================================================================
const std::list<std::string>& HOMARD_Hypothesis::GetZones() const
{
  return _ListZone;
}
//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Hypothesis::AddComp( const char* NomComposant )
{
  _ListComposant.push_back( std::string( NomComposant ) );
}
//=============================================================================
void HOMARD_Hypothesis::SupprComp()
{
  std::cerr << "HOMARD_Hypothesis::SupprComp" << std::endl;
  _ListComposant.clear();
}
//=============================================================================
const std::list<std::string>& HOMARD_Hypothesis::GetListComp() const
{
  return _ListComposant;
}
//=============================================================================
/*!
*/
//=============================================================================
const std::list<std::string>& HOMARD_Hypothesis::GetGroups() const
{
  return _ListGroupSelected;
}
//=============================================================================
void HOMARD_Hypothesis::SetGroups( const std::list<std::string>& ListGroup )
{
  _ListGroupSelected.clear();
  std::list<std::string>::const_iterator it = ListGroup.begin();
  while(it != ListGroup.end())
    _ListGroupSelected.push_back((*it++));
}
//=============================================================================
void HOMARD_Hypothesis::AddGroup( const char* Group)
{
  _ListGroupSelected.push_back(Group);
}
//=============================================================================
/*!
*/
//=============================================================================
void HOMARD_Hypothesis::SetTypeFieldInterp( int TypeFieldInterp )
{
  ASSERT (!((TypeFieldInterp < -1) or (TypeFieldInterp > 2)));
  _TypeFieldInterp = TypeFieldInterp;
}

//=============================================================================
/*!
*/
//=============================================================================
int HOMARD_Hypothesis::GetTypeFieldInterp() const
{
  return _TypeFieldInterp;
}
/*!
*/
//=============================================================================
void HOMARD_Hypothesis::AddFieldInterp( const char* FieldInterp )
{
  _ListFieldInterp.push_back( std::string( FieldInterp ) );
}
//=============================================================================
void HOMARD_Hypothesis::SupprFieldInterp()
{
  std::cerr << "HOMARD_Hypothesis::SupprFieldInterpp" << std::endl;
  _ListFieldInterp.clear();
}
//=============================================================================
const std::list<std::string>& HOMARD_Hypothesis::GetListFieldInterp() const
{
  return _ListFieldInterp;
}
//=============================================================================
void HOMARD_Hypothesis::SetNivMax( int NivMax )
//=============================================================================
{
  _NivMax = NivMax;
}
//=============================================================================
const int HOMARD_Hypothesis::GetNivMax() const
//=============================================================================
{
  return _NivMax;
}
//=============================================================================
void HOMARD_Hypothesis::SetAdapInit( int AdapInit )
//=============================================================================
{
  _AdapInit = AdapInit;
}
//=============================================================================
const int HOMARD_Hypothesis::GetAdapInit() const
//=============================================================================
{
  return _AdapInit;
}
//=============================================================================
void HOMARD_Hypothesis::SetDiamMin( double DiamMin )
//=============================================================================
{
  _DiamMin = DiamMin;
}
//=============================================================================
const double HOMARD_Hypothesis::GetDiamMin() const
//=============================================================================
{
  return _DiamMin;
}
//=============================================================================
void HOMARD_Hypothesis::SetLevelOutput( int LevelOutput )
//=============================================================================
{
  _LevelOutput = LevelOutput;
}
//=============================================================================
const int HOMARD_Hypothesis::GetLevelOutput() const
//=============================================================================
{
  return _LevelOutput;
}
