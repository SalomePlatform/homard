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

#ifndef HOMARDQTCOMMUN_H
#define HOMARDQTCOMMUN_H


#include <SALOMEconfig.h>
#include "SALOME_Selection.h"
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)
#include CORBA_CLIENT_HEADER(HOMARD_Cas)

#include <qstring.h>
#include <vector>
#include <set>

class QComboBox;


namespace HOMARD_QT_COMMUN
{
    QString PushNomFichier(bool avertir=true);
    QString LireNomMaillage(int Medidt,int MeshId);
    QString LireNomMaillage(QString aFile);

    int     OuvrirFichier(QString aFile);

    std::list<QString> GetListeChamps(QString aFile);
    std::list<QString> GetListeComposants(QString aFile, QString aChamp);

    QString SelectionArbreEtude(QString commentaire, int grave );
    QString SelectionCasEtude();

};

#endif // HOMARDQTCOMMUN_H
