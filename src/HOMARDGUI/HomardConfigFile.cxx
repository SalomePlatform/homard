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

//
//  File   : HomardConfigFile.cxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD
//  cree un fichier de configuration HOMARD
    
using namespace std;

#include "HomardConfigFile.hxx"
#include "utilities.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




//=============================================================================
/*!
 *
 */
//=============================================================================

HomardConfigFile::HomardConfigFile():
			_nomFichier(string("HOMARD.Configuration")),
                        _prefix(string(""))
 {

        string t1[] = {string("CCMaiN__"), string("CCNoMN__"), string("CCSolN__"), string("CCFronti"), 
                       string("HOMaiN__"), string("RenumN__"), string("ListeStd"), string("PPBasFic"),
		       string("CCAssoci"), string("NumeIter"), string("CCMaiNP1"), string("CCNoMNP1"),
		       string("TypeElem"), string("TypeRaff"), string("TypeDera"), string("HOMaiN__"),
	               string("HOMaiNP1"), string("CCNoChaI"), string("CCCoChaI"), string("CCNumOrI"),
		       string("CCNumPTI"), string("SeuilBPE"), string("SeuilHPE"), string("CCIndica")};
        std::list<motcle> l1(t1,t1+24);
        _motscle_ss_valeur=l1;

        string t2[] = {string("Aucun0__"), string("Nb_Enti2"), string("Interpe3"), string("Qualite5"),
                       string("Nb_Enti7"), string("Connex11"), string("Taille13") };
        std::list<motcle> l2(t2,t2+7);
        _motscle_oui_non=l2;

        string t3[] = {string("ModeHOMA"), string("EcriFiHO")};
        std::list<motcle> l3(t3,t3+2);
        _motscle_autre=l3;

	_dictValeur[string("Nb_Enti2")]=string("oui") ;

        _dictValeuroui[string("Aucun0__")]=0;
        _dictValeuroui[string("Nb_Enti2")]=2;
        _dictValeuroui[string("Interpe3")]=3;
        _dictValeuroui[string("Qualite5")]=5;
        _dictValeuroui[string("Nb_Enti7")]=7;
        _dictValeuroui[string("Connex11")]=11;
        _dictValeuroui[string("Taille13")]=13;

 }
//=============================================================================
/*!
 *
 */
//=============================================================================
HomardConfigFile::~HomardConfigFile()
{
}
//=============================================================================
/*!
 *
 */
//=============================================================================
void HomardConfigFile::setBilan(bool etat)
{
	_bBilan = etat;
}
//=============================================================================
/*!
 *
 */
//=============================================================================
bool HomardConfigFile::initVal(const string motclef ,const string valeur)
{
	//SCRUTE(motclef);
	//SCRUTE(valeur);
        bool ok = false;
        if ( cherche_dans_liste(_motscle_ss_valeur, motclef))
        {
	   _dictValeur[motclef]=valeur;
           ok = true;
        }
	else
        {
           if ( cherche_dans_liste(_motscle_oui_non,motclef))
	   {	
		if (valeur =="oui" || valeur == "non")
		{
	   	   _dictValeur[motclef]=valeur;
                   ok = true;
		}
           }
           else
              if ( cherche_dans_liste(_motscle_autre,motclef))
	      // Il faudrait avoir un mecanisme de verification de la valeur //
	      // passee, non mis en place actuellement avec des strings ?    //
	      {	
	   	   _dictValeur[motclef]=valeur;
                   ok = true;
	      }	
        }
        return ok;
}

//=============================================================================
/*!
 *
 */
//=============================================================================
bool HomardConfigFile::cherche_dans_liste(std::list<motcle> & liste,  const motcle motclef )
{
     bool ok = false;
     std::list<motcle>::iterator it =liste.begin();
     while ( it != liste.end())
     {
	if ( *it == motclef)
        {
           ok = true;
           break;
        }
        it ++;
     }
     return ok;
}
    
//=============================================================================
/*!
 *
 */
//=============================================================================
string HomardConfigFile::getMyDir()
{
	return _myDir;
}
//=============================================================================
/*!
 *
 */
//=============================================================================
bool HomardConfigFile::createFile()
{
    bool ok = true;

    const char *a = "/tmp/ed.XXXXXX";
    char * cible = new char[15];
    strcpy(cible,a) ;
    mkdtemp(cible);
   
    _myDir = string(cible);
    string myfile=_myDir+string("/HOMARD.Configuration");

    try
    {
       
        ofstream ficHomard( myfile.c_str()) ;
        int typeBilan = 1;

        std::map<motcle,valeur>::iterator it = _dictValeur.begin();
        for (; it != _dictValeur.end(); it++)
        {
           motcle motclef=(*it).first;
           valeur valmot =(*it).second;
           if ( cherche_dans_liste(_motscle_oui_non,motclef))
           {
		if (valmot== "oui")
                {
		  typeBilan=typeBilan*_dictValeuroui[motclef]; 
                 }
           }
           else
	     ficHomard << motclef << " " << valmot << std::endl ; 
        }
		
        if (_bBilan  == true)
        {
          ficHomard << "TypeBila "<< typeBilan << std::endl ;
        }
        ficHomard.close();
    }
    catch (...)
    {
	ok = false;
    }
  return ok;
   
}
