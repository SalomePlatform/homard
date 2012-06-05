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

#ifndef MON_CREATEBOUNDARYAN_H
#define MON_CREATEBOUNDARYAN_H


#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)
#include CORBA_CLIENT_HEADER(HOMARD_Boundary)

#include <CreateBoundaryAn.h>
#include <QDialog>

class MonCreateCase;
class MonCreateBoundaryAn : public QDialog, public Ui_CreateBoundaryAn
{
    Q_OBJECT

public:
    MonCreateBoundaryAn( MonCreateCase* parent, bool modal,
                   HOMARD::HOMARD_Gen_var myHomardGen,
                   QString caseName);
    virtual ~MonCreateBoundaryAn();

protected :
    MonCreateBoundaryAn( MonCreateCase* parent,
                   HOMARD::HOMARD_Gen_var myHomardGen,
                   QString caseName);

    MonCreateCase * _parent;

    QString _aBoundaryAnName;
    QString _aCaseName;

    int _BoundaryType;
    double _BoundaryAnXcentre, _BoundaryAnYcentre, _BoundaryAnZcentre, _BoundaryAnRayon;
    double _BoundaryAnXaxis, _BoundaryAnYaxis, _BoundaryAnZaxis;
    double _Xmin, _Xmax, _Xincr, _Ymin, _Ymax, _Yincr, _Zmin, _Zmax, _Zincr, _DMax ;
    double _Xcentre, _Ycentre, _Zcentre, _Rayon ;


    bool Chgt;

    HOMARD::HOMARD_Boundary_var aBoundaryAn ;
    HOMARD::HOMARD_Gen_var _myHomardGen;

    virtual void InitConnect();
    virtual void InitValBoundaryAn();
    virtual void InitMinMax();
    virtual void SetNewBoundaryAnName();
    virtual bool CreateOrUpdateBoundaryAn();

public slots:
    virtual void SetCylinder();
    virtual void SetSphere();
    virtual void PushOnOK();
    virtual bool PushOnApply();
    virtual void PushOnHelp();

};

#endif // MON_CREATEBOUNDARYAN_H
