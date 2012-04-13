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

using namespace std;

#include "MonCreateBoundaryDi.h"
#include "MonCreateListGroup.h"
#include "MonCreateCase.h"

#include <QFileDialog>
#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>

// -------------------------------------------------------------------------------
MonCreateBoundaryDi::MonCreateBoundaryDi(MonCreateCase* parent, bool modal,
                                         HOMARD::HOMARD_Gen_var myHomardGen,
                                         QString caseName, QString aBoundaryName)
// ---------------------------------------------------------------------------------
/* Constructs a MonCreateBoundaryDi */
    :
    QDialog(0), Ui_CreateBoundaryDi(),
    _parent(parent), _aBoundaryName(aBoundaryName),
    _myHomardGen(HOMARD::HOMARD_Gen::_duplicate(myHomardGen)),
    _aCaseName(caseName)
    {
      MESSAGE("Constructeur") ;
      setupUi(this);
      setModal(modal);
      InitConnect();

     if ( _aBoundaryName == QString("") ) {SetNewBoundaryName();};
    }

// ------------------------------------------------------------------------
MonCreateBoundaryDi::~MonCreateBoundaryDi()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonCreateBoundaryDi::InitConnect()
// ------------------------------------------------------------------------
{
    connect( PushFichier,  SIGNAL(pressed()), this, SLOT(SetMeshFile()));
    connect( buttonOk,     SIGNAL(pressed()), this, SLOT( PushOnOK()));
    connect( buttonApply,  SIGNAL(pressed()), this, SLOT( PushOnApply()));
    connect( buttonCancel, SIGNAL(pressed()), this, SLOT(close()));
    connect( buttonHelp,   SIGNAL(pressed()), this, SLOT( PushOnHelp()));
    connect( CBGroupe,     SIGNAL(stateChanged(int)), this, SLOT( SetFiltrage()));
}

// ------------------------------------------------------------------------
bool MonCreateBoundaryDi::PushOnApply()
// ------------------------------------------------------------------------
// Appele lorsque l'un des boutons Ok ou Apply est presse
//
{
// Verifications

  QString aBoundaryName=LEBoundaryName->text().trimmed();
  if (aBoundaryName=="") {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_BOUN_NAME") );
    return false;
  }

//  Le maillage de la frontiere discrete
  QString aMeshFile=LEFileName->text().trimmed();
  if (aMeshFile ==QString(""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_BOUN_MESH") );
    return false;
  }

//  Le nom du maillage de la frontiere discrete
  QString aMeshName = HOMARD_QT_COMMUN::LireNomMaillage(aMeshFile);
  if (aMeshName == "" )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_MED_FILE_2") );
    return false;
  }

// Creation de l'objet CORBA si ce n'est pas deja fait sous le meme nom
  if ( _aBoundaryName != aBoundaryName )
  {
   try
   {
     _aBoundaryName=aBoundaryName;
     _aBoundary=_myHomardGen->CreateBoundaryDi(CORBA::string_dup(_aBoundaryName.toStdString().c_str()), aMeshName.toStdString().c_str(), aMeshFile.toStdString().c_str());
     _parent->addBoundaryDi(_aBoundaryName);
     _aBoundary->SetCaseCreation(_aCaseName.toStdString().c_str());
   }
   catch( SALOME::SALOME_Exception& S_ex )
   {
      QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                QString(CORBA::string_dup(S_ex.details.text)) );
      return false;
   }
  }

// Les groupes
  AssocieLesGroupes();

  HOMARD_UTILS::updateObjBrowser();
  return true;
}


// ------------------------------------------------------------------------
void MonCreateBoundaryDi::PushOnOK()
// ------------------------------------------------------------------------
{
     if (PushOnApply()) this->close();
     if ( _parent ) { _parent->raise(); _parent->activateWindow(); };
}
// ------------------------------------------------------------------------
void MonCreateBoundaryDi::PushOnHelp()
// ------------------------------------------------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_boundary.html#frontiere-discrete"));
}
// ------------------------------------------------------------------------
void MonCreateBoundaryDi::AssocieLesGroupes()
// ------------------------------------------------------------------------
{
  HOMARD::ListGroupType_var aSeqGroupe = new HOMARD::ListGroupType;
  aSeqGroupe->length(_listeGroupesBoundary.size());
  QStringList::const_iterator it;
  int i=0;
  for (it = _listeGroupesBoundary.constBegin(); it != _listeGroupesBoundary.constEnd(); it++)
     aSeqGroupe[i++]=(*it).toStdString().c_str();
  _aBoundary->SetGroups(aSeqGroupe);

}

// -------------------------------------------------
void MonCreateBoundaryDi::SetNewBoundaryName()
// --------------------------------------------------
{

  HOMARD::listeBoundarys_var  MyBoundarys = _myHomardGen->GetAllBoundarys();
  int num = 0; QString aBoundaryName="";
  while (aBoundaryName == QString("") )
  {
    aBoundaryName.setNum(num+1) ;
    aBoundaryName.insert(0, QString("Boun_")) ;
    for ( int i=0; i<MyBoundarys->length(); i++)
    {
      if ( aBoundaryName ==  QString(MyBoundarys[i]))
      {
          num=num+1;
          aBoundaryName="";
          break;
      }
   }
  }
  LEBoundaryName->setText(aBoundaryName);
}
// ------------------------------------------------------------------------
void MonCreateBoundaryDi::SetMeshFile()
// ------------------------------------------------------------------------
{
  QString aMeshFile = HOMARD_QT_COMMUN::PushNomFichier();
  if (!(aMeshFile.isEmpty())) LEFileName->setText(aMeshFile);
}

// ------------------------------------------------------------------------
void MonCreateBoundaryDi::setGroups (QStringList listGroup)
// ------------------------------------------------------------------------
{
    _listeGroupesBoundary = listGroup;
}
// ------------------------------------------------------------------------
void MonCreateBoundaryDi::SetFiltrage()
// // ------------------------------------------------------------------------
{
  if (!CBGroupe->isChecked()) return;
  if (_aCaseName.toStdString().c_str() == QString()) {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_BOUN_CASE") );
    return;
  }

  MonCreateListGroup *aDlg = new MonCreateListGroup(NULL,this,  TRUE, HOMARD::HOMARD_Gen::_duplicate(_myHomardGen),
                            _aCaseName, _listeGroupesBoundary) ;
  aDlg->show();
}

