using namespace std;

#include "MonEditIteration.h"

#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>


// -------------------------------------------------------------------------------------------------------------------------------------
MonEditIteration::MonEditIteration ( QWidget* parent, bool modal,
                                     HOMARD::HOMARD_Gen_var myHomardGen,
                                     QString IterParentName, QString IterName ):
// -------------------------------------------------------------------------------------------------------------------------------------
/* Constructs a MonEditIteration
    herite de MonCreateIteration
*/
   MonCreateIteration(parent, modal, myHomardGen, IterParentName),
   _rank(0), _step(0), _IterationName(""), _FieldFile(""),_aTypeAdap()
{
    MESSAGE("Debut de  MonEditIteration" << IterName.toStdString().c_str());
    setWindowTitle(QObject::tr("HOM_ITER_EDIT_WINDOW_TITLE"));
    _IterationName = IterName;
    aIter = _myHomardGen->GetIteration(_IterationName.toStdString().c_str());

//  Attention au cas ou c'est une iteration initiale : il faut inhiber l'essentiel
    int number = aIter->GetNumber() ;
    if ( number == 0 ) { InitValEdit0(); }
    else               { InitValEdit(); }
}
// ------------------------------
MonEditIteration::~MonEditIteration()
// ------------------------------
{
}

// ------------------------------
void MonEditIteration::InitValEdit0()
// ------------------------------
//    Cas d'une iteration 0
{
//
      LEIterationName->setText(_IterationName);
      LEIterationName->setReadOnly(true);

//    Invisibilite de l'iteration parent
      Iter_Parent->setVisible(0);
      PBIterParent->setVisible(0);
      LEIterationParentName->setVisible(0);

//    Affichage bloque du nom du maillage de l'iteration courante
      QString MeshName = aIter->GetMeshName();
      Mesh_n->setText(QObject::tr("HOM_ITER_STARTING_POINT_0"));
      LEMeshName_n->setText(MeshName);
      LEMeshName_n->setReadOnly(1);

//    Message general
      Mesh_np1->setText(QObject::tr("HOM_ITER_STARTING_POINT_1"));
      LEMeshName_np1->setVisible(0);
//
//    Invisibilite des hypotheses et des champs
      Hypothese->setVisible(0);
      GBField->setVisible(0);
      adjustSize();
//
}
// ------------------------------
void MonEditIteration::InitValEdit()
// ------------------------------
//    Cas d'une iteration > 0
{
//    Affichage bloque du nom de l'iteration
      LEIterationName->setText(_IterationName);
      LEIterationName->setReadOnly(true);

//    Affichage bloque du nom de l'iteration parent
      _IterParentName = aIter->GetIterParent();
      LEIterationParentName->setText(_IterParentName);
      LEIterationParentName->setReadOnly(true);
      PBIterParent->setEnabled(false);
      PBIterParent->setVisible(0);

//    Affichage bloque du nom du maillage de l'iteration parent
      aIterParent = _myHomardGen->GetIteration(_IterParentName.toStdString().c_str());
      QString MeshNameParent = aIterParent->GetMeshName();
      LEMeshName_n->setText(MeshNameParent);
      LEMeshName_n->setReadOnly(1);

//    Affichage bloque du nom du maillage de l'iteration courante
      QString MeshName = aIter->GetMeshName();
      LEMeshName_np1->setText(MeshName);
      LEMeshName_np1->setReadOnly(1);

//    Affichage de la bonne hypothese
      QString HypoName = aIter->GetHypoName();
      CBHypothese->insertItem(0,HypoName);
      CBHypothese->setCurrentIndex(0);
      CBHypothese->setEnabled(false);
      PBHypoNew->setVisible(0);

//    Pour une adaptation selon un champ
      HOMARD::HOMARD_Hypothesis_var myHypo = _myHomardGen->GetHypothesis(HypoName.toStdString().c_str()) ;
      _aTypeAdap = myHypo->GetAdapType() ;
      if ( _aTypeAdap == 1 )
      {
          _FieldFile = aIter->GetFieldFile();
          LEFieldFile->setText(_FieldFile);
          _step = aIter->GetTimeStep() ;
          SpinBox_TimeStep->setValue(_step);
          _rank = aIter->GetRank() ;
          SpinBox_Rank->setValue(_rank);

// Cas ou on prend le dernier pas de temps ou sans pas de temps
          if ( _step <= -1 )
          {
            Rank->setVisible(0);
            SpinBox_Rank->setVisible(0);
            TimeStep->setVisible(0);
            SpinBox_TimeStep->setVisible(0);

            if ( _step == -2 ) { RBLast->setChecked(true); }
            else               { RBNo->setChecked(true); }
          }

// Cas avec pas de temps
          else
          {
            Rank->setVisible(1);
            SpinBox_Rank->setVisible(1);
            TimeStep->setVisible(1);
            SpinBox_TimeStep->setVisible(1);
            RBChosen->setChecked(true);
          }
      }
      else
      {
          GBField->setVisible(0);
      }
      adjustSize();
//
}

// -------------------------------------
bool MonEditIteration::PushOnApply()
// -------------------------------------
{
  if ( _aTypeAdap ==  1)
  {
// Pour du raffinement selon un champ, les instants ont-ils change ?
    if ( (_FieldFile != LEFieldFile->text().trimmed()) or
       (  _rank != SpinBox_Rank->value())  or
       (  _step != SpinBox_TimeStep->value()))
    {
      _FieldFile = LEFieldFile->text().trimmed();
      _rank = SpinBox_Rank->value();
      _step = SpinBox_TimeStep->value();
      aIter->SetFieldFile(CORBA::string_dup(_FieldFile.toStdString().c_str()));
      aIter->SetTimeStepRank(_step, _rank);
      _myHomardGen->InvalideIter(_IterationName.toStdString().c_str());
      HOMARD_UTILS::updateObjBrowser();
    }
  }
  return true;

};
