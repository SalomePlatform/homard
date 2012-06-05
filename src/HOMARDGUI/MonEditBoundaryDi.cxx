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

#include "MonEditBoundaryDi.h"
#include "MonEditListGroup.h"

#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>


// -------------------------------------------------------------------------------------------------------------------------------------
MonEditBoundaryDi::MonEditBoundaryDi( MonCreateCase* parent, bool modal,
                                      HOMARD::HOMARD_Gen_var myHomardGen,
                                      QString caseName, QString BoundaryName):
// -------------------------------------------------------------------------------------------------------------------------------------
/* Constructs a MonEditBoundaryDi
    herite de MonCreateBoundaryDi
*/
    MonCreateBoundaryDi(parent, modal, myHomardGen, caseName, BoundaryName)
{
    MESSAGE("Debut de Boundary pour " << BoundaryName.toStdString().c_str());
    setWindowTitle(QObject::tr("HOM_BOUN_D_EDIT_WINDOW_TITLE"));
    try
    {
     _aBoundary=_myHomardGen->GetBoundary(CORBA::string_dup(_aBoundaryName.toStdString().c_str()));
     if (caseName==QString("")) { _aCaseName=_aBoundary->GetCaseCreation();}
     InitValEdit();
    }
    catch( SALOME::SALOME_Exception& S_ex )
    {
      QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                QString(CORBA::string_dup(S_ex.details.text)) );
      return;
    }

    HOMARD::ListGroupType_var maListe = _aBoundary->GetGroups();
    for ( int i = 0; i < maListe->length(); i++ )
       _listeGroupesBoundary << QString(maListe[i]);

}
// ------------------------------
MonEditBoundaryDi::~MonEditBoundaryDi()
// ------------------------------
{
}

// ------------------------------
void MonEditBoundaryDi::InitValEdit()
// ------------------------------
{
      LEBoundaryName->setText(_aBoundaryName);
      LEBoundaryName->setReadOnly(true);

      QString aMeshFile = _aBoundary->GetMeshFile();
      LEFileName->setText(aMeshFile);
      LEFileName->setReadOnly(1);
      PushFichier->setVisible(0);
      adjustSize();
}
// ------------------------------
bool MonEditBoundaryDi::PushOnApply()
// ------------------------------
{
     return true;
}
// ------------------------------------------------------------------------
void MonEditBoundaryDi::SetFiltrage()
// // ------------------------------------------------------------------------
{
  if (!CBGroupe->isChecked()) return;
  if (_aCaseName.toStdString().c_str() == QString())
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_BOUN_CASE") );
    return;
  }
  HOMARD::HOMARD_Cas_var monCas= _myHomardGen->GetCas(_aCaseName.toStdString().c_str());
  HOMARD::ListGroupType_var _listeGroupesCas = monCas->GetGroups();

  MonEditListGroup *aDlg = new MonEditListGroup(NULL,this,  TRUE, HOMARD::HOMARD_Gen::_duplicate(_myHomardGen),
                            _aCaseName, _listeGroupesBoundary) ;
  aDlg->show();
}

