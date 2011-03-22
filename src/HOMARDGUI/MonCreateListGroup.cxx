using namespace std;

#include "MonCreateListGroup.h"
#include "MonCreateHypothesis.h"
#include "MonCreateBoundaryDi.h"

#include <QFileDialog>
#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>

#include <SUIT_Desktop.h>
#include <SUIT_MessageBox.h>
#include <SUIT_ResourceMgr.h>
#include <SUIT_Session.h>
#include <SUIT_ViewManager.h>

// --------------------------------------------------------------------------------------------------------------
MonCreateListGroup::MonCreateListGroup(MonCreateHypothesis* parentHyp, MonCreateBoundaryDi* parentBound, bool modal, 
                                       HOMARD::HOMARD_Gen_var myHomardGen, QString aCaseName,  QStringList listeGroupesHypo) : 
// --------------------------------------------------------------------------------------------------------------
//
    QDialog(0), Ui_CreateListGroup(),
    _aCaseName (aCaseName),
    _listeGroupesHypo (listeGroupesHypo),
    _parentHyp(parentHyp),
    _parentBound(parentBound)
{
    MESSAGE("Debut de  MonCreateListGroup")
     _myHomardGen=HOMARD::HOMARD_Gen::_duplicate(myHomardGen);
    setupUi(this);
    setModal(modal);
    InitConnect();
    InitGroupes();
}
// --------------------------------------------------------------------------------------------------------------
MonCreateListGroup::MonCreateListGroup(MonCreateHypothesis* parentHyp, MonCreateBoundaryDi* parentBound,  
                                       HOMARD::HOMARD_Gen_var myHomardGen, QString aCaseName,  QStringList listeGroupesHypo) : 
// --------------------------------------------------------------------------------------------------------------
//
    QDialog(0), Ui_CreateListGroup(),
    _aCaseName (aCaseName),
    _listeGroupesHypo (listeGroupesHypo),
    _parentHyp(parentHyp),
    _parentBound(parentBound)
{
    _myHomardGen=HOMARD::HOMARD_Gen::_duplicate(myHomardGen);
    setupUi(this);
    InitConnect();
}

// ------------------------------------------------------------------------
MonCreateListGroup::~MonCreateListGroup()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonCreateListGroup::InitConnect()
// ------------------------------------------------------------------------
{
    connect( buttonOk,     SIGNAL( pressed() ), this, SLOT( PushOnOK() ) );
    connect( buttonApply,  SIGNAL( pressed() ), this, SLOT( PushOnApply() ) );
    connect( buttonCancel, SIGNAL( pressed() ), this, SLOT( close() ) );
    connect( buttonHelp,   SIGNAL( pressed() ), this, SLOT( PushOnHelp() ) );
}
// ------------------------------------------------------------------------
bool MonCreateListGroup::PushOnApply()
// ------------------------------------------------------------------------
// Appele lorsque l'un des boutons Ok ou Apply est presse
//
{
  QStringList ListeGroup ;
  for ( int row=0; row< TWGroupe->rowCount(); row++)
  {
      if ( TWGroupe->item( row, 0 )->checkState() ==  Qt::Checked )
          ListeGroup.insert(0, QString(TWGroupe->item(row, 1)->text()) );
  }
  if ( _parentHyp )   { _parentHyp->setGroups(ListeGroup);};
  if ( _parentBound ) { _parentBound->setGroups(ListeGroup);};
  return true;
}


// ------------------------------------------------------------------------
void MonCreateListGroup::PushOnOK()
// ------------------------------------------------------------------------
{
     if (PushOnApply()) this->close();
     if ( _parentHyp )   { _parentHyp->raise(); _parentHyp->activateWindow(); };
     if ( _parentBound ) { _parentBound->raise(); _parentBound->activateWindow(); };
}
// ------------------------------------------------------------------------
void MonCreateListGroup::PushOnHelp()
// ------------------------------------------------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_hypothese.html"));
}
// ------------------------------------------------------------------------
void MonCreateListGroup::InitGroupes()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de InitGroupes ");
  for ( int row=0; row< TWGroupe->rowCount(); row++)
      TWGroupe->removeRow(row);
  TWGroupe->setRowCount(0);
  if (_aCaseName == QString("")) { return; };
  HOMARD::HOMARD_Cas_var monCas= _myHomardGen->GetCas(_aCaseName.toStdString().c_str());
  HOMARD::ListGroupType_var _listeGroupesCas = monCas->GetGroups();
  for ( int i = 0; i < _listeGroupesCas->length(); i++ )
  {
    TWGroupe->insertRow(i);
    TWGroupe->setItem( i, 0, new QTableWidgetItem( QString ("") ) );
    TWGroupe->item( i, 0 )->setFlags( 0 );
    TWGroupe->item( i, 0 )->setFlags( Qt::ItemIsUserCheckable|Qt::ItemIsEnabled  );
    if (_listeGroupesHypo.contains (QString((_listeGroupesCas)[i])))
      {TWGroupe->item( i, 0 )->setCheckState( Qt::Checked );}
    else
      {TWGroupe->item( i, 0 )->setCheckState( Qt::Unchecked );}
    TWGroupe->setItem( i, 1, new QTableWidgetItem(QString((_listeGroupesCas)[i]).trimmed()));
    TWGroupe->item( i, 1 )->setFlags(Qt::ItemIsEnabled |Qt::ItemIsSelectable );
  }
  TWGroupe->resizeColumnsToContents();
  TWGroupe->resizeRowsToContents();
  TWGroupe->clearSelection();
  MESSAGE("Fin de InitGroupes ");
}

