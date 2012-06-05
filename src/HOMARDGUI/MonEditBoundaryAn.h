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

#ifndef MON_EDITBOUNDARYAN_H
#define MON_EDITBOUNDARYAN_H

#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)

#include <MonCreateBoundaryAn.h>

class MonEditBoundaryAn : public MonCreateBoundaryAn
{
    Q_OBJECT
public:
    MonEditBoundaryAn( MonCreateCase* parent, bool modal,
                 HOMARD::HOMARD_Gen_var myHomardGen,
                 QString caseName, QString zoneName);
    virtual ~MonEditBoundaryAn();

protected :
    void SetCylinder();
    void SetSphere();
    bool CreateOrUpdateBoundaryAn();
    void InitValEdit();
    void InitValBoundaryAnLimit();
    void InitValBoundaryAnCylindre();
    void InitValBoundaryAnSphere();

public slots:

};

#endif // MON_EDITZONE_H
