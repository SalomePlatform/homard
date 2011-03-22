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
