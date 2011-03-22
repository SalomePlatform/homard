using namespace std;

#include "MonEditBoundaryAn.h"

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include <utilities.h>


// ------------------------------------------------------------------------
MonEditBoundaryAn::MonEditBoundaryAn( MonCreateCase* parent, bool modal,
                          HOMARD::HOMARD_Gen_var myHomardGen,
                          QString caseName, QString zoneName ):
// ------------------------------------------------------------------------
/* Constructs a MonEditBoundaryAn
    herite de MonCreateBoundaryAn
*/
    MonCreateBoundaryAn(parent, myHomardGen, caseName)
{
    MESSAGE("Debut de MonEditBoundaryAn pour " << zoneName.toStdString().c_str());
    setWindowTitle(QObject::tr("HOM_BOUN_A_EDIT_WINDOW_TITLE"));
    _aBoundaryAnName=zoneName;
    aBoundaryAn = _myHomardGen->GetBoundary(_aBoundaryAnName.toStdString().c_str());
    InitValEdit();
}
// ------------------------------------------------------------------------
MonEditBoundaryAn::~MonEditBoundaryAn()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonEditBoundaryAn::InitValEdit()
// ------------------------------------------------------------------------
{
    LEBoundaryName->setText(_aBoundaryAnName);
    LEBoundaryName->setReadOnly(true);
    _BoundaryType = aBoundaryAn->GetBoundaryType();
    InitValBoundaryAnLimit();
    if (_aCaseName != QString("")) InitValBoundaryAn();
    switch (_BoundaryType)
    {
      case 1 : // il s agit d une boite
      {
        InitValBoundaryAnCylindre();
        SetCylinder();
        break;
      }
      case 2: // il s agit d une sphere
      {
        InitValBoundaryAnSphere();
        SetSphere();
        break;
      }
    };
}
// ------------------------------------------------------------------------
void MonEditBoundaryAn::InitValBoundaryAnLimit()
// ------------------------------------------------------------------------
{
      HOMARD::double_array_var  mesCoordLimits = aBoundaryAn->GetLimit();
      ASSERT(mesCoordLimits->length() == 3 );
      _Xincr=mesCoordLimits[0];
      _Yincr=mesCoordLimits[1];
      _Zincr=mesCoordLimits[2];

}
// ------------------------------------------------------------------------
void MonEditBoundaryAn::InitValBoundaryAnCylindre()
// ------------------------------------------------------------------------
{
      HOMARD::double_array_var  mesCoordBoundary = aBoundaryAn->GetCylinder();
      ASSERT(mesCoordBoundary->length() == 7 );
      _BoundaryAnXcentre=mesCoordBoundary[0];
      _BoundaryAnYcentre=mesCoordBoundary[1];
      _BoundaryAnZcentre=mesCoordBoundary[2];
      _BoundaryAnXaxis=mesCoordBoundary[3];
      _BoundaryAnYaxis=mesCoordBoundary[4];
      _BoundaryAnZaxis=mesCoordBoundary[5];
      _BoundaryAnRayon=mesCoordBoundary[6];

}
// ------------------------------------------------------------------------
void MonEditBoundaryAn::InitValBoundaryAnSphere()
// ------------------------------------------------------------------------
{
      HOMARD::double_array_var  mesCoordBoundary = aBoundaryAn->GetSphere();
      ASSERT(mesCoordBoundary->length() == 4 );
      _BoundaryAnXcentre=mesCoordBoundary[0];
      _BoundaryAnYcentre=mesCoordBoundary[1];
      _BoundaryAnZcentre=mesCoordBoundary[2];
      _BoundaryAnRayon=mesCoordBoundary[3];

}
// ------------------------------------------------------------------------
void MonEditBoundaryAn::SetCylinder()
// ------------------------------------------------------------------------
{
  gBCylindre->setVisible(1);
  gBSphere->setVisible(0);
  RBCylindre->setChecked(1);
  adjustSize();
  _BoundaryType=1;
  RBSphere->setDisabled(true);
  adjustSize();

  SpinBox_Xcent->setValue(_BoundaryAnXcentre);
  SpinBox_Ycent->setValue(_BoundaryAnYcentre);
  SpinBox_Zcent->setValue(_BoundaryAnZcentre);

  SpinBox_Xaxis->setValue(_BoundaryAnXaxis);
  SpinBox_Yaxis->setValue(_BoundaryAnYaxis);
  SpinBox_Zaxis->setValue(_BoundaryAnZaxis);


  SpinBox_Xaxis->setSingleStep(0.1);
  SpinBox_Xcentre->setSingleStep(_Xincr);
  SpinBox_Yaxis->setSingleStep(0.1);
  SpinBox_Ycentre->setSingleStep(_Yincr);
  SpinBox_Zaxis->setSingleStep(0.1);
  SpinBox_Zcentre->setSingleStep(_Zincr);
// Rayon
  SpinBox_Radius->setValue(_BoundaryAnRayon);
  SpinBox_Radius->setSingleStep(_BoundaryAnRayon/10.);

}
// ------------------------------------------------------------------------
void MonEditBoundaryAn::SetSphere()
// ------------------------------------------------------------------------
{
  gBCylindre->setVisible(0);
  gBSphere->setVisible(1);
  RBSphere->setChecked(1);
  RBCylindre->setDisabled(true);
  adjustSize();
  _BoundaryType=2 ;

  SpinBox_Xcentre->setValue(_BoundaryAnXcentre);
  if ( _Xincr > 0) { SpinBox_Xcentre->setSingleStep(_Xincr); }
  else             { SpinBox_Xcentre->setSingleStep(1) ; }

  SpinBox_Ycentre->setValue(_BoundaryAnYcentre);
  if ( _Yincr > 0) { SpinBox_Ycentre->setSingleStep(_Yincr); }
  else             { SpinBox_Ycentre->setSingleStep(1) ; }

  SpinBox_Zcentre->setValue(_BoundaryAnZcentre);
  if ( _Zincr > 0) { SpinBox_Zcentre->setSingleStep(_Zincr); }
  else             { SpinBox_Zcentre->setSingleStep(1);}

  SpinBox_Rayon->setMinimum(0.);
  SpinBox_Rayon->setValue(_BoundaryAnRayon);
}


// ---------------------------------------------------
bool MonEditBoundaryAn::CreateOrUpdateBoundaryAn()
//----------------------------------------------------
//  Pas de Creation de la zone
//  Mise a jour des attributs de la BoundaryAn

{
  try
  {
    aBoundaryAn->SetBoundaryType(_BoundaryType);
    switch (_BoundaryType)
    {
        case 1 : // il s agit d un cylindre
        {
          aBoundaryAn->SetCylinder(_BoundaryAnXcentre, _BoundaryAnYcentre, _BoundaryAnZcentre, _BoundaryAnXaxis, _BoundaryAnYaxis, _BoundaryAnZaxis, _BoundaryAnRayon );
          break;
        }

        case 2 : // il s agit d une sphere
        {
          aBoundaryAn->SetSphere(_BoundaryAnXcentre, _BoundaryAnYcentre, _BoundaryAnZcentre, _BoundaryAnRayon);
          break;
        }
    }
    if (Chgt) _myHomardGen->InvalideBoundary(_aBoundaryAnName.toStdString().c_str());
    HOMARD_UTILS::updateObjBrowser();
  }
  catch( const SALOME::SALOME_Exception& S_ex ) {
       SalomeApp_Tools::QtCatchCorbaException( S_ex );
       return false;
  }
  return true;
}

