using namespace std;

#include "MonEditListGroup.h"
#include <utilities.h>

//---------------------------------------------------------------------
MonEditListGroup::MonEditListGroup( MonCreateHypothesis* parentHyp,
                                    MonCreateBoundaryDi* parentBound,
                                    bool modal,
                                    HOMARD::HOMARD_Gen_var myHomardGen,
                                    QString aCaseName,
                                    QStringList listeGroupesHypo):
//---------------------------------------------------------------------
MonCreateListGroup(parentHyp,parentBound,myHomardGen,aCaseName,listeGroupesHypo)
{
  MESSAGE("Debut de MonEditListGroup");
    setWindowTitle(QObject::tr("HOM_GROU_EDIT_WINDOW_TITLE"));
  setModal(true);
  InitGroupes();
}

//------------------------------------
MonEditListGroup:: ~MonEditListGroup()
//------------------------------------
{
}
// -------------------------------------
void MonEditListGroup:: InitGroupes()
// -------------------------------------
{
  for (int i = 0; i < _listeGroupesHypo.size(); i++ )
  {
     std::cerr << _listeGroupesHypo[i].toStdString().c_str() << std::endl;
     TWGroupe->insertRow(i);
     TWGroupe->setItem( i, 0, new QTableWidgetItem( QString ("") ) );
     TWGroupe->item( i, 0 )->setFlags( 0 );
     TWGroupe->item( i, 0 )->setCheckState( Qt::Checked );
     TWGroupe->setItem( i, 1, new QTableWidgetItem(_listeGroupesHypo[i]));
   }
   TWGroupe->resizeRowsToContents();
}


