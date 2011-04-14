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
