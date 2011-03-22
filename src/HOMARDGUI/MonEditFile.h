#ifndef MON_EDITFILE_H
#define MON_EDITFILE_H


#include <SALOMEconfig.h>
#include "SALOME_Selection.h"
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)
#include CORBA_CLIENT_HEADER(HOMARD_Cas)

#include "EditFile.h"
#include <QWidget>

class QListBox;
class QDialog;

class MonEditFile : public QWidget, public Ui_EditFile
{
    Q_OBJECT

public:
    MonEditFile( QWidget* parent,  bool modal,
                 HOMARD::HOMARD_Gen_var myHomardGen,
                 QString FileName );
    ~MonEditFile();

protected :

    HOMARD::HOMARD_Gen_var _myHomardGen;
    QString _aFileName ;

    virtual void InitConnect();
    virtual void EditText();

public slots:
    virtual void PushOnPrint();

};

#endif // MON_EDITFILE_H
