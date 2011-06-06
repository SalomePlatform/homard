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
//  File   : HomardConfigFile.hxx
//  Author : Paul RASCLE, EDF
//  Module : SMESH


#ifndef _HOMARD_CONFIG_FILE
#define _HOMARD_CONFIG_FILE

#include <string>
#include <map>
#include <list>

using namespace std;

class HomardConfigFile
{
	typedef string motcle;
	typedef string valeur;

public  :
	HomardConfigFile();
	~HomardConfigFile();
         bool initVal(const string motclef ,const string valeur);
         bool createFile();
         void setBilan(bool etat);
         string getMyDir();

protected :

	std::list<motcle> _motscle_ss_valeur;
	std::list<motcle> _motscle_oui_non ;
	std::list<motcle> _motscle_autre;

	std::map <motcle,valeur> _dictValeur;
	std::map <motcle,int>    _dictValeuroui;

        string _nomFichier;
        string _prefix;
        bool   _bBilan;
        string _myDir;

        bool cherche_dans_liste(std::list<motcle> & liste , const motcle motclef);
} ;
#endif 
