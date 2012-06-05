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

#include "HomardQtCommun.h"
#include "HOMARDGUI_Utils.h"

#include <utilities.h>

#include <qmessagebox.h>
#include <qcombobox.h>
#include <qfiledialog.h>
#include <qstring.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


#include "SalomeApp_Tools.h"

using namespace std;
extern "C"
{
#include <med.h>
}


// ============================================================================
QString HOMARD_QT_COMMUN::SelectionArbreEtude(QString commentaire, int grave )
// ============================================================================
// Regarde si l'objet selectionne correspond a un objet de tyoe
// commentaire. si c'est le cas, retourne le nom de  cet objet,
// sinon retourne une QString("")
// Si grave = 0, ce n'est pas grave de ne rien trouver et pas de message
// Si grave = 1, ce n'est pas grave de ne rien trouver mais on emet un message
{
  int nbSel = HOMARD_UTILS::IObjectCount() ;
  if ( nbSel == 0 )
  {
    if ( grave == 1 )
    {
      QMessageBox::warning( 0, QObject::tr("HOM_WARNING"),
                                QObject::tr("HOM_SELECT_OBJECT_1") );
    }
    return QString("");
  }
  if ( nbSel > 1 )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_SELECT_OBJECT_2") );
    return QString("");
  }
//
  Handle(SALOME_InteractiveObject) aIO = HOMARD_UTILS::firstIObject();
  if ( aIO->hasEntry() )
  {
    _PTR(Study) aStudy = HOMARD_UTILS::GetActiveStudyDocument();
    _PTR(SObject) aSO ( aStudy->FindObjectID( aIO->getEntry() ) );
    _PTR(GenericAttribute) anAttr;
    if (aSO->FindAttribute(anAttr, "AttributeComment") )
    {
      _PTR(AttributeComment) attributComment = anAttr;
      QString aComment= QString(attributComment->Value().data());
      int iteration = aComment.lastIndexOf(commentaire);
      if ( iteration !=0  )
      {
        QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                  QObject::tr("HOM_SELECT_OBJECT_3").arg(commentaire) );
        return QString("");
      }
      if (aSO->FindAttribute(anAttr, "AttributeName") )
      {
        _PTR(AttributeName) attributName = anAttr;
        QString aName= QString(attributName->Value().data());
        return aName;
      }
    }
  }
//
  return QString("");
}

// =======================================================================
QString HOMARD_QT_COMMUN::SelectionCasEtude()
// =======================================================================
{
  QString aName    = QString("");
  int nbSel = HOMARD_UTILS::IObjectCount() ;
  if ( nbSel == 0 )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_SELECT_OBJECT_1") );
    return QString("");
  }
  if ( nbSel > 1 )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_SELECT_OBJECT_2") );
    return QString("");
  }
  Handle(SALOME_InteractiveObject) aIO = HOMARD_UTILS::firstIObject();
  if ( aIO->hasEntry() )
  {
	_PTR(Study) aStudy = HOMARD_UTILS::GetActiveStudyDocument();
	_PTR(SObject) aSO ( aStudy->FindObjectID( aIO->getEntry() ) );
        _PTR(SObject) aSObjCas = aSO->GetFather();
	_PTR(GenericAttribute) anAttr;
	if (aSObjCas->FindAttribute(anAttr, "AttributeName") )
        {
            _PTR(AttributeName) attributName = anAttr;
            aName= QString(attributName->Value().data());
        }
        return aName;
    }
    return QString("");
}

// =======================================================================
QString HOMARD_QT_COMMUN::PushNomFichier(bool avertir)
// =======================================================================
// Gestion les boutons qui permettent  de
// 1) retourne le nom d'un fichier par une fenetre de dialogue si aucun
//    objet est selectionne dans l arbre d etude
// 2) retourne le nom du fichier asocie a l objet
//    selectionne dans l arbre d etude
{
  MESSAGE("HOMARD_QT_COMMUN::PushNomFichier");
  QString aFile=QString::null;
  int nbSel = HOMARD_UTILS::IObjectCount() ;
  if ( nbSel == 0 )
  {
    aFile = QFileDialog::getOpenFileName(0,QString("File Selection"),QString("") ,QString("Med files (*.med);;all (*) ") );
  }
  if (nbSel > 1)
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_SELECT_FILE_2") );
  }
  if (nbSel == 1)
  {
    Handle(SALOME_InteractiveObject) aIO = HOMARD_UTILS::firstIObject();
    if ( aIO->hasEntry() )
    {
      _PTR(Study) aStudy = HOMARD_UTILS::GetActiveStudyDocument();
      _PTR(SObject) aSO ( aStudy->FindObjectID( aIO->getEntry() ) );
      _PTR(GenericAttribute) anAttr;
      _PTR(AttributeFileType) aFileType;
      _PTR(AttributeExternalFileDef) aFileName;
      if (aSO) {
        if (aSO->FindAttribute(anAttr, "AttributeFileType") ) {
          aFileType=anAttr;
          QString fileType=QString(aFileType->Value().data());
          if ( fileType==QString("FICHIERMED")) {
            if (aSO->FindAttribute(anAttr,"AttributeExternalFileDef")) {
            aFileName=anAttr;
            aFile= QString(aFileName->Value().data()); }
          }
        }
      }
    }

    if ( aFile==QString::null )
    {
      if ( avertir ) {
        QMessageBox::warning( 0, QObject::tr("HOM_WARNING"),
                                QObject::tr("HOM_SELECT_STUDY") );
      }
      aFile = QFileDialog::getOpenFileName();
      if (!aFile.isEmpty())
      {
        aFile=aFile;
      }
    }
  }
  return aFile;

}


// =======================================================================
int HOMARD_QT_COMMUN::OuvrirFichier(QString aFile)
// =======================================================================
// renvoie le medId associe au fichier Med apres ouverture
{
  med_int medIdt = MEDfileOpen(aFile.toStdString().c_str(),MED_ACC_RDONLY);
  if (medIdt <0)
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_MED_FILE_1") );
  }
  return (int) medIdt;
}

// ======================================================
QString HOMARD_QT_COMMUN::LireNomMaillage(QString aFile)
// ========================================================
{
  med_int medIdt = HOMARD_QT_COMMUN::OuvrirFichier(aFile);
  med_int numberOfMeshes = MEDnMesh(medIdt) ;
  if (numberOfMeshes == 0 )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_MED_FILE_2") );
  }
  if (numberOfMeshes > 1 )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_MED_FILE_3") );
  }

  QString nomMaillage= HOMARD_QT_COMMUN::LireNomMaillage(medIdt,1);
  MEDfileClose(medIdt);
  return nomMaillage;
}
// =======================================================================
QString HOMARD_QT_COMMUN::LireNomMaillage(int medIdt ,int meshId)
// =======================================================================
{
  QString NomMaillage=QString::null;
  char meshname[MED_NAME_SIZE+1];
  med_int spacedim,meshdim;
  med_mesh_type meshtype;
  char descriptionription[MED_COMMENT_SIZE+1];
  char dtunit[MED_SNAME_SIZE+1];
  med_sorting_type sortingtype;
  med_int nstep;
  med_axis_type axistype;
  int naxis = MEDmeshnAxis(medIdt,1);
  char *axisname=new char[naxis*MED_SNAME_SIZE+1];
  char *axisunit=new char[naxis*MED_SNAME_SIZE+1];
  med_err aRet = MEDmeshInfo(medIdt,
                          meshId,
                          meshname,
                          &spacedim,
                          &meshdim,
                          &meshtype,
                          descriptionription,
                          dtunit,
                          &sortingtype,
                          &nstep,
                          &axistype,
                          axisname,
                          axisunit);

  if ( aRet < 0 )
  {
  QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                            QObject::tr("HOM_MED_FILE_4") );
  }
  else
  {
    NomMaillage=QString(meshname);
  }
  return NomMaillage;
}


// =======================================================================
std::list<QString> HOMARD_QT_COMMUN::GetListeChamps(QString aFile)
// =======================================================================
{
// Il faut voir si plusieurs maillages

  MESSAGE("HOMARD_QT_COMMUN::GetListeChamps");
  std::list<QString> ListeChamp;

  char *comp, *unit;
  char nomcha  [MED_NAME_SIZE+1];
  char meshname[MED_NAME_SIZE+1];
  med_field_type typcha;
  med_int ncomp;
  med_bool local;
  med_int nbofcstp;

  SCRUTE(aFile.toStdString());
  med_int medIdt = HOMARD_QT_COMMUN::OuvrirFichier(aFile);
  if ( medIdt < 0 ) { return ListeChamp; }

  // Le fichier Med est lisible
  // Lecture du maillage

  // Lecture du nombre de champs
  med_int ncha = MEDnField(medIdt) ;
  if (ncha < 1 )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                            QObject::tr("HOM_MED_FILE_5") );
    MEDfileClose(medIdt);
    return ListeChamp;
  }

  for (int i=0; i< ncha; i++)
  {
    /* Lecture du type du champ, des noms des composantes et du nom de l'unite*/
    ncomp = MEDfieldnComponent(medIdt,i+1);
    comp = (char*) malloc(ncomp*MED_SNAME_SIZE+1);
    unit = (char*) malloc(ncomp*MED_SNAME_SIZE+1);
    char dtunit[MED_SNAME_SIZE+1];
    if ( MEDfieldInfo(medIdt,i+1,nomcha,meshname,&local,&typcha,comp,unit,dtunit,&nbofcstp) < 0 )
    {
      QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                QObject::tr("HOM_MED_FILE_6") );
      MEDfileClose(medIdt);
      return ListeChamp;
    }

    ListeChamp.push_back(QString(nomcha));
    free(comp);
    free(unit);
  }
  MEDfileClose(medIdt);
  return ListeChamp;
}

// ======================================================================================
std::list<QString> HOMARD_QT_COMMUN::GetListeComposants(QString aFile, QString aChamp)
// ======================================================================================
{
  MESSAGE ( "GetListeComposants pour le fichier " << aFile.toStdString().c_str());
  MESSAGE ( "GetListeComposants pour le champ " << aChamp.toStdString().c_str());

  std::list<QString> ListeComposants;

  char *comp, *unit;
  char nomcha  [MED_NAME_SIZE+1];
  char meshname[MED_NAME_SIZE+1];
  med_field_type typcha;
  med_int ncomp;
  med_bool local;
  med_int nbofcstp;

  int medIdt = HOMARD_QT_COMMUN::OuvrirFichier(aFile);
  if ( medIdt < 0 ) { return ListeComposants; }


  // Lecture du nombre de champs
  med_int ncha = MEDnField(medIdt) ;
  if (ncha < 1 )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                            QObject::tr("HOM_MED_FILE_5") );
    MEDfileClose(medIdt);
    return ListeComposants;
  }

  for (int i=0; i< ncha; i++)
  {
    /* Lecture du type du champ, des noms des composantes et du nom de l'unite*/
    ncomp = MEDfieldnComponent(medIdt,i+1);
    comp = (char*) malloc(ncomp*MED_SNAME_SIZE+1);
    unit = (char*) malloc(ncomp*MED_SNAME_SIZE+1);
    char dtunit[MED_SNAME_SIZE+1];

    if ( MEDfieldInfo(medIdt,i+1,nomcha,meshname,&local,&typcha,comp,unit,dtunit,&nbofcstp) < 0 )
    {
      QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                QObject::tr("HOM_MED_FILE_6") );
      MEDfileClose(medIdt);
      return ListeComposants;
    }
    
    if ( QString(nomcha) != aChamp ) {
      free(comp);
      free(unit);
      continue;
    }

    for (int j = 0; j <ncomp; j++)
    {
      char cible[MED_SNAME_SIZE +1];
      strncpy(cible,comp+j*MED_SNAME_SIZE,MED_SNAME_SIZE );
      cible[MED_SNAME_SIZE ]='\0';
      ListeComposants.push_back(QString(cible));
    }
    break;
  }
  free(comp);
  free(unit);
  MEDfileClose(medIdt);
  return ListeComposants;
}
