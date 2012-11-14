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

#include "MonCreateIteration.h"
#include "MonCreateHypothesis.h"
#include "MonEditHypothesis.h"

#include <QFileDialog>
#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>


// -----------------------------------------------------------------------------------------------------
MonCreateIteration::MonCreateIteration(QWidget* parent, bool modal,
                                       HOMARD::HOMARD_Gen_var myHomardGen, QString IterParentName ):
// -----------------------------------------------------------------------------------------------------
/* Constructs a MonCreateIteration
 * Inherits from CasHomard
 * Sets attributes to default values
 */
    QDialog(0),
    Ui_CreateIteration(),
    _IterationName(""),
    _IterParentName(IterParentName),
    _CaseName("")
    {
      MESSAGE("Constructeur");
      _myHomardGen=HOMARD::HOMARD_Gen::_duplicate(myHomardGen);
      setupUi(this);
      setModal(modal);
      InitConnect();

      SetNewIterationName();
      GetHypotheses();
      if (_IterParentName != QString(""))
         { SetIterParentName(); }
      else
         {setModal(false); /* permet selection de l iteration dans l arbre d etude */}
      SetTSNo();
    }

// ------------------------------------------------------------------------
MonCreateIteration::~MonCreateIteration()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonCreateIteration::InitConnect()
// ------------------------------------------------------------------------
{
    connect( PBIterParent,  SIGNAL(pressed()), this, SLOT( SetIterParentName()));
    connect( PBHypoEdit,    SIGNAL(pressed()), this, SLOT( PushHypoEdit() ) );
    connect( PBHypoNew,     SIGNAL(pressed()), this, SLOT( PushHypoNew() ) );
    connect( PushFieldFile, SIGNAL(pressed()), this, SLOT( SetFieldFile() ) );
    connect( RBNo,          SIGNAL(clicked()), this, SLOT( SetTSNo()));
    connect( RBLast,        SIGNAL(clicked()), this, SLOT( SetTSLast()));
    connect( RBChosen,      SIGNAL(clicked()), this, SLOT( SetTSChosen()));

    connect( buttonOk,     SIGNAL(pressed()), this, SLOT( PushOnOK() ) );
    connect( buttonApply,  SIGNAL(pressed()), this, SLOT( PushOnApply() ) );
    connect( buttonCancel, SIGNAL(pressed()), this, SLOT( close() ) );
    connect( buttonHelp,   SIGNAL(pressed()), this, SLOT( PushOnHelp() ) );
}
// ------------------------------------------------------------------------
void MonCreateIteration::GetHypotheses()
// ------------------------------------------------------------------------
{
     HOMARD::listeHypotheses_var  mesHypotheses = _myHomardGen->GetAllHypotheses();
     for (int i=0; i<mesHypotheses->length(); i++)
     {
         CBHypothese->addItem(QString(mesHypotheses[i]));
     }
}

// ------------------------------------------------------------------------
bool MonCreateIteration::PushOnApply()
// ------------------------------------------------------------------------
// Appele lorsque l'un des boutons Ok ou Apply est presse
{
  MESSAGE("MonCreateIteration::PushOnApply");
//
  QString aIterationName = LEIterationName->text().trimmed();
  if ( aIterationName == QString (""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_ITER_NAME") );
    return false;
  }

  if ( _IterParentName == QString (""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_ITER_STARTING_POINT") );
    return false;
  }
  QString aMeshName_np1=LEMeshName_np1->text().trimmed();
  if (aMeshName_np1 == "" )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_ITER_MESH") );
    return false;
  }
  QString monHypoName=CBHypothese->currentText();
  if (monHypoName == "" )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_ITER_HYPO") );
    return false;
  }
  HOMARD::HOMARD_Hypothesis_var _myHypothesis = _myHomardGen->GetHypothesis(monHypoName.toStdString().c_str());
  HOMARD::listeTypes_var ListTypes (_myHypothesis->GetAdapRefinUnRef());
  int TypeAdap = ListTypes[0];
  if ( TypeAdap == 1 and LEFieldFile->text().trimmed() == QString("") )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_ITER_FIELD_FILE") );
    return false;
  }

  MESSAGE ("aMeshName_np1.toStdString " << aMeshName_np1.toStdString());
  MESSAGE ("_CaseName.toStdString " << _CaseName.toStdString() );
  MESSAGE ("_IterParentName.toStdString " << _IterParentName.toStdString() );

// Creation de l'objet CORBA si ce n'est pas deja fait sous le meme nom
  if (_IterationName != aIterationName)
  {
    try
    {
      _IterationName = aIterationName;
      std::cerr << _IterationName.toStdString() << std::endl;
      aIter = _myHomardGen->CreateIteration( \
               CORBA::string_dup(_IterationName.toStdString().c_str()),
               CORBA::string_dup(_IterParentName.toStdString().c_str()));
    }
    catch( SALOME::SALOME_Exception& S_ex )
    {
      QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                QString(CORBA::string_dup(S_ex.details.text)) );
       return false;
    }
  }

// Mise en place des attributs
  const char* IterName = aIter->GetName() ;
  std::cerr << IterName << std::endl;

  if ( LEFieldFile->text().trimmed() != QString(""))
  {
    QString FieldFile=LEFieldFile->text().trimmed();
    int rank = SpinBox_Rank->value();
    int step = SpinBox_TimeStep->value();
    aIter->SetFieldFile(CORBA::string_dup(FieldFile.toStdString().c_str()));
    aIter->SetTimeStepRank(step,rank);
  }
  _myHomardGen->AssociateIterHypo (IterName, monHypoName.toStdString().c_str());
  aIter->SetMeshName(CORBA::string_dup(aMeshName_np1.toStdString().c_str()));

  HOMARD_UTILS::updateObjBrowser();
  return true;
}

// ------------------------------------------------------------------------
void MonCreateIteration::PushOnOK()
// ------------------------------------------------------------------------
{
     bool bOK = PushOnApply();
     if ( bOK )  this->close();
}

// ------------------------------------------------------------------------
void MonCreateIteration::PushOnHelp()
// ------------------------------------------------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_iteration.html"));
}

// ------------------------------------------------------------------------
void MonCreateIteration::SetIterParentName()
// ------------------------------------------------------------------------
{
  if (_IterParentName == QString("")) {
    _IterParentName=HOMARD_QT_COMMUN::SelectionArbreEtude(QString("IterationHomard"), 1);
    if (_IterParentName == QString("")) { raise();return;};
  }
  _CaseName=HOMARD_QT_COMMUN::SelectionCasEtude();
  HOMARD::HOMARD_Iteration_var aIterParent = _myHomardGen->GetIteration(_IterParentName.toStdString().c_str()) ;
  QString MeshName = aIterParent->GetMeshName();

  LEMeshName_n->setText(MeshName);
  LEMeshName_n->setReadOnly(1);
  LEMeshName_np1->setText(MeshName);

  LEIterationParentName->setText(_IterParentName);
}

// -------------------------------------------------
void MonCreateIteration::SetNewIterationName()
// --------------------------------------------------
{
// Recherche d'un nom par defaut qui n'existe pas encore

  HOMARD::listeIterations_var  myIters=_myHomardGen->GetAllIterations();
  int num = 0;//
  QString aIterationName="";
  while (aIterationName=="" )
  {
    aIterationName.setNum(num+1) ;
    aIterationName.insert(0, QString("Iter_"));
    for ( int i=0; i< myIters->length(); i++)
    {
      if ( aIterationName ==  QString((myIters)[i]))
      {
          num=num+1;
          aIterationName="";
          break;
      }
   }
  }
  LEIterationName->setText(aIterationName);
}


// ------------------------------------------------------------------------
void MonCreateIteration::PushHypoEdit()
// ------------------------------------------------------------------------
{
  if (CBHypothese->currentText() == QString(""))  return;
  if (_IterParentName == QString(""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_ITER_STARTING_POINT") );
    raise();
    return;
  }
  QString aFieldFile=LEFieldFile->text().trimmed();
  MonEditHypothesis *HypoDlg = new MonEditHypothesis(this,TRUE, HOMARD::HOMARD_Gen::_duplicate(_myHomardGen),CBHypothese->currentText(), _CaseName, aFieldFile) ;
  HypoDlg->show();
}

// ------------------------------------------------------------------------
void MonCreateIteration::addHypothese(QString newHypothese)
// ------------------------------------------------------------------------
{
  CBHypothese->insertItem(0,newHypothese);
  CBHypothese->setCurrentIndex(0);
}
// ------------------------------------------------------------------------
void MonCreateIteration::PushHypoNew()
// ------------------------------------------------------------------------
{
  if (_IterParentName == QString(""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_ITER_STARTING_POINT") );
    raise();
    return;
  }
  if ( _CaseName == QString(""))
  {
        _CaseName = _myHomardGen->GetCaseName(CORBA::string_dup(_IterParentName.toStdString().c_str()));
  }
  QString aFieldFile=LEFieldFile->text().trimmed();
  MonCreateHypothesis *HypoDlg = new MonCreateHypothesis(this,TRUE,HOMARD::HOMARD_Gen::_duplicate(_myHomardGen),QString(""),_CaseName, aFieldFile) ;
  HypoDlg->show();
}

// ------------------------------------------------------------------------
void MonCreateIteration::SetFieldFile()
// ------------------------------------------------------------------------

{
  QString fileName0 = LEFieldFile->text().trimmed();
  QString fileName = HOMARD_QT_COMMUN::PushNomFichier(false);
  if (fileName.isEmpty()) fileName = fileName0 ;
  LEFieldFile->setText(fileName);
  raise();
}
// ------------------------------------------------------------------------
void MonCreateIteration::SetTSNo()
// ------------------------------------------------------------------------
// Si on ne tient pas compte du pas de temps, on declare que le pas de temps
// vaut -1, valeur par defaut de med
{
  Rank->setVisible(0);
  SpinBox_Rank->setVisible(0);
  SpinBox_Rank->setValue(-1);

  TimeStep->setVisible(0);
  SpinBox_TimeStep->setVisible(0);
  SpinBox_TimeStep->setValue(-1);

  adjustSize();
}
// ------------------------------------------------------------------------
void MonCreateIteration::SetTSLast()
// ------------------------------------------------------------------------
// Si on choisit le dernier instant, on declare que le pas de temps vaut -2
{
  Rank->setVisible(0);
  SpinBox_Rank->setVisible(0);
  SpinBox_Rank->setValue(-2);

  TimeStep->setVisible(0);
  SpinBox_TimeStep->setVisible(0);
  SpinBox_TimeStep->setValue(-2);

  adjustSize();
}
// ------------------------------------------------------------------------
void MonCreateIteration::SetTSChosen()
// ------------------------------------------------------------------------
// Si choisit un instant, on prepositionne a 0
{
  Rank->setVisible(1);
  SpinBox_Rank->setVisible(1);
  SpinBox_Rank->setValue(0);

  TimeStep->setVisible(1);
  SpinBox_TimeStep->setVisible(1);
  SpinBox_TimeStep->setValue(0);

  adjustSize();
}

