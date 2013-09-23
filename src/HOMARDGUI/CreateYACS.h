/********************************************************************************
** Form generated from reading UI file 'CreateYACS.ui'
**
** Created: Mon Sep 23 13:29:12 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATEYACS_H
#define CREATEYACS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateYACS
{
public:
    QGridLayout *gridLayout_2;
    QLabel *Name;
    QLineEdit *LEName;
    QGridLayout *gridLayout;
    QLabel *Case;
    QPushButton *PBCaseName;
    QLineEdit *LECaseName;
    QHBoxLayout *_2;
    QLabel *Script;
    QPushButton *PBScriptFile;
    QLineEdit *LEScriptFile;
    QHBoxLayout *hboxLayout;
    QLabel *DirectoryStart;
    QPushButton *PBDir;
    QLineEdit *LEDirName;
    QHBoxLayout *_3;
    QLabel *MeshFile;
    QPushButton *PBMeshFile;
    QLineEdit *LEMeshFile;
    QGroupBox *GBTypeSchema;
    QHBoxLayout *_4;
    QRadioButton *RBConstant;
    QRadioButton *RBVariable;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonHelp;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QSpacerItem *spacer_2;

    void setupUi(QDialog *CreateYACS)
    {
        if (CreateYACS->objectName().isEmpty())
            CreateYACS->setObjectName(QString::fromUtf8("CreateYACS"));
        CreateYACS->resize(538, 340);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateYACS->sizePolicy().hasHeightForWidth());
        CreateYACS->setSizePolicy(sizePolicy);
        CreateYACS->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(CreateYACS);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Name = new QLabel(CreateYACS);
        Name->setObjectName(QString::fromUtf8("Name"));

        gridLayout_2->addWidget(Name, 0, 0, 1, 1);

        LEName = new QLineEdit(CreateYACS);
        LEName->setObjectName(QString::fromUtf8("LEName"));
        LEName->setMaxLength(32);

        gridLayout_2->addWidget(LEName, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Case = new QLabel(CreateYACS);
        Case->setObjectName(QString::fromUtf8("Case"));

        gridLayout->addWidget(Case, 0, 0, 1, 1);

        PBCaseName = new QPushButton(CreateYACS);
        PBCaseName->setObjectName(QString::fromUtf8("PBCaseName"));
        PBCaseName->setEnabled(true);
        PBCaseName->setMaximumSize(QSize(50, 27));

        gridLayout->addWidget(PBCaseName, 0, 1, 1, 1);

        LECaseName = new QLineEdit(CreateYACS);
        LECaseName->setObjectName(QString::fromUtf8("LECaseName"));
        LECaseName->setMinimumSize(QSize(382, 21));

        gridLayout->addWidget(LECaseName, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 3);

        _2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _2->setSpacing(6);
#endif
        _2->setContentsMargins(0, 0, 0, 0);
        _2->setObjectName(QString::fromUtf8("_2"));
        Script = new QLabel(CreateYACS);
        Script->setObjectName(QString::fromUtf8("Script"));

        _2->addWidget(Script);

        PBScriptFile = new QPushButton(CreateYACS);
        PBScriptFile->setObjectName(QString::fromUtf8("PBScriptFile"));
        PBScriptFile->setAutoDefault(false);

        _2->addWidget(PBScriptFile);

        LEScriptFile = new QLineEdit(CreateYACS);
        LEScriptFile->setObjectName(QString::fromUtf8("LEScriptFile"));
        LEScriptFile->setMinimumSize(QSize(382, 21));

        _2->addWidget(LEScriptFile);


        gridLayout_2->addLayout(_2, 2, 0, 1, 3);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        DirectoryStart = new QLabel(CreateYACS);
        DirectoryStart->setObjectName(QString::fromUtf8("DirectoryStart"));

        hboxLayout->addWidget(DirectoryStart);

        PBDir = new QPushButton(CreateYACS);
        PBDir->setObjectName(QString::fromUtf8("PBDir"));
        PBDir->setAutoDefault(false);

        hboxLayout->addWidget(PBDir);

        LEDirName = new QLineEdit(CreateYACS);
        LEDirName->setObjectName(QString::fromUtf8("LEDirName"));
        LEDirName->setMinimumSize(QSize(382, 21));

        hboxLayout->addWidget(LEDirName);


        gridLayout_2->addLayout(hboxLayout, 3, 0, 1, 3);

        _3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _3->setSpacing(6);
#endif
        _3->setContentsMargins(0, 0, 0, 0);
        _3->setObjectName(QString::fromUtf8("_3"));
        MeshFile = new QLabel(CreateYACS);
        MeshFile->setObjectName(QString::fromUtf8("MeshFile"));

        _3->addWidget(MeshFile);

        PBMeshFile = new QPushButton(CreateYACS);
        PBMeshFile->setObjectName(QString::fromUtf8("PBMeshFile"));
        PBMeshFile->setAutoDefault(false);

        _3->addWidget(PBMeshFile);

        LEMeshFile = new QLineEdit(CreateYACS);
        LEMeshFile->setObjectName(QString::fromUtf8("LEMeshFile"));
        LEMeshFile->setMinimumSize(QSize(382, 21));

        _3->addWidget(LEMeshFile);


        gridLayout_2->addLayout(_3, 4, 0, 1, 3);

        GBTypeSchema = new QGroupBox(CreateYACS);
        GBTypeSchema->setObjectName(QString::fromUtf8("GBTypeSchema"));
        _4 = new QHBoxLayout(GBTypeSchema);
#ifndef Q_OS_MAC
        _4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _4->setContentsMargins(9, 9, 9, 9);
#endif
        _4->setObjectName(QString::fromUtf8("_4"));
        RBConstant = new QRadioButton(GBTypeSchema);
        RBConstant->setObjectName(QString::fromUtf8("RBConstant"));
        RBConstant->setChecked(true);

        _4->addWidget(RBConstant);

        RBVariable = new QRadioButton(GBTypeSchema);
        RBVariable->setObjectName(QString::fromUtf8("RBVariable"));

        _4->addWidget(RBVariable);


        gridLayout_2->addWidget(GBTypeSchema, 5, 0, 1, 2);

        GroupButtons = new QGroupBox(CreateYACS);
        GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
        gridLayout1 = new QGridLayout(GroupButtons);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        buttonHelp = new QPushButton(GroupButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
        buttonHelp->setAutoDefault(false);

        gridLayout1->addWidget(buttonHelp, 0, 4, 1, 1);

        buttonApply = new QPushButton(GroupButtons);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));
        buttonApply->setAutoDefault(false);

        gridLayout1->addWidget(buttonApply, 0, 1, 1, 1);

        buttonOk = new QPushButton(GroupButtons);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(false);

        gridLayout1->addWidget(buttonOk, 0, 0, 1, 1);

        buttonCancel = new QPushButton(GroupButtons);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setAutoDefault(false);

        gridLayout1->addWidget(buttonCancel, 0, 2, 1, 1);


        gridLayout_2->addWidget(GroupButtons, 6, 0, 1, 2);

        spacer_2 = new QSpacerItem(128, 25, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(spacer_2, 6, 2, 1, 1);


        retranslateUi(CreateYACS);

        QMetaObject::connectSlotsByName(CreateYACS);
    } // setupUi

    void retranslateUi(QDialog *CreateYACS)
    {
        CreateYACS->setWindowTitle(QApplication::translate("CreateYACS", "Create YACS", 0, QApplication::UnicodeUTF8));
        Name->setText(QApplication::translate("CreateYACS", "Name", 0, QApplication::UnicodeUTF8));
        Case->setText(QApplication::translate("CreateYACS", "Case", 0, QApplication::UnicodeUTF8));
        PBCaseName->setText(QString());
        Script->setText(QApplication::translate("CreateYACS", "Script", 0, QApplication::UnicodeUTF8));
        PBScriptFile->setText(QString());
        DirectoryStart->setText(QApplication::translate("CreateYACS", "Directory", 0, QApplication::UnicodeUTF8));
        PBDir->setText(QString());
        MeshFile->setText(QApplication::translate("CreateYACS", "Mesh file", 0, QApplication::UnicodeUTF8));
        PBMeshFile->setText(QString());
        GBTypeSchema->setTitle(QApplication::translate("CreateYACS", "Type of schema", 0, QApplication::UnicodeUTF8));
        RBConstant->setText(QApplication::translate("CreateYACS", "Constant", 0, QApplication::UnicodeUTF8));
        RBVariable->setText(QApplication::translate("CreateYACS", "Variable", 0, QApplication::UnicodeUTF8));
        GroupButtons->setTitle(QString());
        buttonHelp->setText(QApplication::translate("CreateYACS", "Help", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("CreateYACS", "Apply", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("CreateYACS", "OK", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CreateYACS", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateYACS: public Ui_CreateYACS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEYACS_H
