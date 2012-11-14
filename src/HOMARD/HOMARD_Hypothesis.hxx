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
//  File   : HOMARD_Hypothesis.hxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD

#ifndef _HOMARD_HYPOTHESIS_HXX_
#define _HOMARD_HYPOTHESIS_HXX_

#include <string>
#include <list>

class HOMARD_Hypothesis
{
public:
  HOMARD_Hypothesis();
  ~HOMARD_Hypothesis();

  void                          SetName( const char* NomHypo );
  std::string                   GetName() const;
  void                          SetCaseCreation( const char* NomCasCreation );
  std::string                   GetCaseCreation() const;
  std::string                   GetDumpPython() const;

  void                          SetAdapType( int TypeAdap );
  int                           GetAdapType() const;

  void                          SetRefinTypeDera( int TypeRaff, int TypeDera );
  int                           GetRefinType() const;
  int                           GetUnRefType() const;

  void                          SetField( const char* FieldName );
  void                          SetRefinThr( int TypeThR, double ThreshR );
  void                          SetUnRefThr( int TypeThC, double ThreshC );
  void                          SetUseComp( int UsCmpI );
  void                          SetUseField( int UsField );
  std::string                   GetFieldName() const;
  int                           GetRefinThrType()   const;
  double                        GetThreshR()   const;
  int                           GetUnRefThrType()   const;
  double                        GetThreshC()   const;
  int                           GetUseField()    const;
  int                           GetUseCompI()    const;

  void                          AddComp( const char* NomComposant );
  void                          SupprComp();
  const std::list<std::string>& GetListComp() const;

  void                          AddIteration( const char* NomIter );
  void                          SupprIterations();
  const std::list<std::string>& GetIterations() const;

  void                          AddZone( const char* NomZone, int TypeUse );
  void                          SupprZone( const char* NomZone );
  void                          SupprZones();
  const std::list<std::string>& GetZones() const;

  void                          AddGroup( const char* LeGroupe);
  void                          SetGroups(const std::list<std::string>& ListGroup );
  const std::list<std::string>& GetGroups() const;

  void                          SetTypeFieldInterp( int TypeFieldInterp );
  int                           GetTypeFieldInterp() const;
  void                          AddFieldInterp( const char* FieldInterp );
  void                          SupprFieldInterp();
  const std::list<std::string>& GetListFieldInterp() const;

  void                          SetNivMax( int NivMax );
  const int                     GetNivMax() const;
  void                          SetDiamMin( double DiamMin );
  const double                  GetDiamMin() const;
  void                          SetAdapInit( int AdapInit );
  const int                     GetAdapInit() const;
  void                          SetLevelOutput( int LevelOutput );
  const int                     GetLevelOutput() const;


private:
  std::string                   _NomHypo;
  std::string                   _NomCasCreation;

  int                           _TypeAdap; // -1 pour une adapation Uniforme,
                                           //  0 si l adaptation depend des zones,
                                           //  1 pour des champs

  int                           _TypeRaff;
  int                           _TypeDera;

  std::string                   _Field;
  int                           _TypeThR;
  int                           _TypeThC;
  double                        _ThreshR;
  double                        _ThreshC;
  int                           _UsField;
  int                           _UsCmpI;
  int                           _TypeFieldInterp; // 0 pour aucune interpolation,
                                                  // 1 pour interpolation de tous les champs,
                                                  // 2 pour une liste
  int                           _NivMax;
  double                        _DiamMin;
  int                           _AdapInit;
  int                           _LevelOutput;

  std::list<std::string>        _ListIter;
  std::list<std::string>        _ListZone;
  std::list<std::string>        _ListComposant;
  std::list<std::string>        _ListGroupSelected;
  std::list<std::string>        _ListFieldInterp;
};

#endif
