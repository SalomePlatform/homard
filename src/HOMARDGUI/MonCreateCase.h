#ifndef MON_CREATECASE_H
#define MON_CREATECASE_H

#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)
#include CORBA_CLIENT_HEADER(HOMARD_Cas)

#include <CreateCase.h>
#include <QWidget>

class MonCreateCase : public QDialog, public Ui_CreateCase
{
    Q_OBJECT

public:
    MonCreateCase( QWidget* parent, bool modal, HOMARD::HOMARD_Gen_var myHomardGen);
    ~MonCreateCase();

    void addBoundaryAn(QString newBoundary);
    void addBoundaryDi(QString newBoundary);

protected :
    QString _aCaseName;
    QString _aDirName;

    int _ConfType;


    HOMARD::HOMARD_Cas_var aCase ;
    HOMARD::HOMARD_Gen_var _myHomardGen;

    virtual void InitConnect();
    virtual void GetBoundarys();
    virtual void SetNewCaseName();

public slots:
    virtual void SetDirName();
    virtual void SetFileName();

    virtual void SetConforme();
    virtual void SetNonConforme();
    virtual void Set1NpM();
    virtual void Set1NpA();
    virtual void SetQuelconque();

    virtual void SetBoundaryD();
    virtual void PushBoundaryDiNew();
    virtual void PushBoundaryDiEdit();
    virtual void SetBoundaryA();
    virtual void PushBoundaryAnNew();
    virtual void PushBoundaryAnHelp();

    virtual void PushOnOK();
    virtual bool PushOnApply();
    virtual void PushOnHelp();

    virtual void CaseNameChanged();
};

#endif // MON_CREATECASE_H
