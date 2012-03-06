/********************************************************************************
** Form generated from reading UI file 'CreateCase.ui'
**
** Created: Wed Feb 15 18:15:40 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATECASE_H
#define CREATECASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateCase
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *hboxLayout;
    QLabel *Name;
    QLineEdit *LECaseName;
    QHBoxLayout *hboxLayout1;
    QLabel *Directory;
    QPushButton *PushDir;
    QLineEdit *LEDirName;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout2;
    QLabel *Mesh_2;
    QPushButton *PushFichier;
    QLineEdit *LEFileName;
    QSpacerItem *spacerItem1;
    QGroupBox *GBTypeConf;
    QHBoxLayout *hboxLayout3;
    QRadioButton *RBConforme;
    QRadioButton *RBNonConforme;
    QSpacerItem *spacerItem2;
    QGroupBox *GBTypeNoConf;
    QHBoxLayout *hboxLayout4;
    QRadioButton *RB1NpM;
    QRadioButton *RB1NpA;
    QRadioButton *RBQuelconque;
    QSpacerItem *spacerItem3;
    QHBoxLayout *hboxLayout5;
    QCheckBox *CBBoundaryD;
    QCheckBox *CBBoundaryA;
    QSpacerItem *spacerItem4;
    QGroupBox *GBBoundaryD;
    QGridLayout *gridLayout;
    QPushButton *PBBoundaryDiEdit;
    QPushButton *PBBoundaryDiNew;
    QComboBox *CBBoundaryDi;
    QSpacerItem *spacerItem5;
    QPushButton *PBBoundaryDiHelp;
    QGroupBox *GBBoundaryA;
    QFormLayout *formLayout;
    QTableWidget *TWBoundary;
    QGridLayout *gridLayout1;
    QPushButton *PBBoundaryAnEdit;
    QPushButton *PBBoundaryAnNew;
    QPushButton *PBBoundaryAnHelp;
    QSpacerItem *spacer;
    QCheckBox *CBAdvanced;
    QGroupBox *GBAdvancedOptions;
    QGridLayout *gridLayout2;
    QCheckBox *CBPyramid;
    QSpacerItem *spacer_3;
    QSpacerItem *spacer_4;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout3;
    QPushButton *buttonHelp;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QSpacerItem *spacer_2;

    void setupUi(QDialog *CreateCase)
    {
        if (CreateCase->objectName().isEmpty())
            CreateCase->setObjectName(QString::fromUtf8("CreateCase"));
        CreateCase->resize(601, 1070);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateCase->sizePolicy().hasHeightForWidth());
        CreateCase->setSizePolicy(sizePolicy);
        CreateCase->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(CreateCase);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Name = new QLabel(CreateCase);
        Name->setObjectName(QString::fromUtf8("Name"));

        hboxLayout->addWidget(Name);

        LECaseName = new QLineEdit(CreateCase);
        LECaseName->setObjectName(QString::fromUtf8("LECaseName"));
        LECaseName->setMinimumSize(QSize(382, 21));

        hboxLayout->addWidget(LECaseName);


        gridLayout_2->addLayout(hboxLayout, 0, 0, 1, 4);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        Directory = new QLabel(CreateCase);
        Directory->setObjectName(QString::fromUtf8("Directory"));

        hboxLayout1->addWidget(Directory);

        PushDir = new QPushButton(CreateCase);
        PushDir->setObjectName(QString::fromUtf8("PushDir"));
        PushDir->setAutoDefault(false);

        hboxLayout1->addWidget(PushDir);

        LEDirName = new QLineEdit(CreateCase);
        LEDirName->setObjectName(QString::fromUtf8("LEDirName"));
        LEDirName->setMinimumSize(QSize(382, 21));

        hboxLayout1->addWidget(LEDirName);


        gridLayout_2->addLayout(hboxLayout1, 1, 0, 1, 4);

        spacerItem = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacerItem, 2, 1, 1, 1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        Mesh_2 = new QLabel(CreateCase);
        Mesh_2->setObjectName(QString::fromUtf8("Mesh_2"));

        hboxLayout2->addWidget(Mesh_2);

        PushFichier = new QPushButton(CreateCase);
        PushFichier->setObjectName(QString::fromUtf8("PushFichier"));
        PushFichier->setAutoDefault(false);

        hboxLayout2->addWidget(PushFichier);

        LEFileName = new QLineEdit(CreateCase);
        LEFileName->setObjectName(QString::fromUtf8("LEFileName"));
        LEFileName->setMinimumSize(QSize(382, 21));

        hboxLayout2->addWidget(LEFileName);


        gridLayout_2->addLayout(hboxLayout2, 3, 0, 1, 4);

        spacerItem1 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacerItem1, 4, 1, 1, 3);

        GBTypeConf = new QGroupBox(CreateCase);
        GBTypeConf->setObjectName(QString::fromUtf8("GBTypeConf"));
        hboxLayout3 = new QHBoxLayout(GBTypeConf);
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        RBConforme = new QRadioButton(GBTypeConf);
        RBConforme->setObjectName(QString::fromUtf8("RBConforme"));
        RBConforme->setChecked(true);

        hboxLayout3->addWidget(RBConforme);

        RBNonConforme = new QRadioButton(GBTypeConf);
        RBNonConforme->setObjectName(QString::fromUtf8("RBNonConforme"));

        hboxLayout3->addWidget(RBNonConforme);


        gridLayout_2->addWidget(GBTypeConf, 5, 0, 1, 1);

        spacerItem2 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacerItem2, 6, 1, 1, 1);

        GBTypeNoConf = new QGroupBox(CreateCase);
        GBTypeNoConf->setObjectName(QString::fromUtf8("GBTypeNoConf"));
        hboxLayout4 = new QHBoxLayout(GBTypeNoConf);
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout4->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        RB1NpM = new QRadioButton(GBTypeNoConf);
        RB1NpM->setObjectName(QString::fromUtf8("RB1NpM"));

        hboxLayout4->addWidget(RB1NpM);

        RB1NpA = new QRadioButton(GBTypeNoConf);
        RB1NpA->setObjectName(QString::fromUtf8("RB1NpA"));

        hboxLayout4->addWidget(RB1NpA);

        RBQuelconque = new QRadioButton(GBTypeNoConf);
        RBQuelconque->setObjectName(QString::fromUtf8("RBQuelconque"));

        hboxLayout4->addWidget(RBQuelconque);


        gridLayout_2->addWidget(GBTypeNoConf, 7, 0, 1, 3);

        spacerItem3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacerItem3, 8, 1, 1, 3);

        hboxLayout5 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout5->setSpacing(6);
#endif
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        CBBoundaryD = new QCheckBox(CreateCase);
        CBBoundaryD->setObjectName(QString::fromUtf8("CBBoundaryD"));

        hboxLayout5->addWidget(CBBoundaryD);

        CBBoundaryA = new QCheckBox(CreateCase);
        CBBoundaryA->setObjectName(QString::fromUtf8("CBBoundaryA"));

        hboxLayout5->addWidget(CBBoundaryA);


        gridLayout_2->addLayout(hboxLayout5, 9, 0, 1, 2);

        spacerItem4 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacerItem4, 10, 1, 1, 1);

        GBBoundaryD = new QGroupBox(CreateCase);
        GBBoundaryD->setObjectName(QString::fromUtf8("GBBoundaryD"));
        sizePolicy.setHeightForWidth(GBBoundaryD->sizePolicy().hasHeightForWidth());
        GBBoundaryD->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(GBBoundaryD);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PBBoundaryDiEdit = new QPushButton(GBBoundaryD);
        PBBoundaryDiEdit->setObjectName(QString::fromUtf8("PBBoundaryDiEdit"));
        PBBoundaryDiEdit->setAutoDefault(false);

        gridLayout->addWidget(PBBoundaryDiEdit, 0, 3, 1, 1);

        PBBoundaryDiNew = new QPushButton(GBBoundaryD);
        PBBoundaryDiNew->setObjectName(QString::fromUtf8("PBBoundaryDiNew"));
        PBBoundaryDiNew->setAutoDefault(false);

        gridLayout->addWidget(PBBoundaryDiNew, 0, 2, 1, 1);

        CBBoundaryDi = new QComboBox(GBBoundaryD);
        CBBoundaryDi->setObjectName(QString::fromUtf8("CBBoundaryDi"));
        CBBoundaryDi->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(CBBoundaryDi, 0, 0, 1, 1);

        spacerItem5 = new QSpacerItem(40, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem5, 0, 1, 1, 1);

        PBBoundaryDiHelp = new QPushButton(GBBoundaryD);
        PBBoundaryDiHelp->setObjectName(QString::fromUtf8("PBBoundaryDiHelp"));
        PBBoundaryDiHelp->setAutoDefault(false);

        gridLayout->addWidget(PBBoundaryDiHelp, 0, 4, 1, 1);


        gridLayout_2->addWidget(GBBoundaryD, 11, 0, 1, 3);

        GBBoundaryA = new QGroupBox(CreateCase);
        GBBoundaryA->setObjectName(QString::fromUtf8("GBBoundaryA"));
        GBBoundaryA->setMinimumSize(QSize(548, 200));
        formLayout = new QFormLayout(GBBoundaryA);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        TWBoundary = new QTableWidget(GBBoundaryA);
        if (TWBoundary->columnCount() < 1)
            TWBoundary->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TWBoundary->setHorizontalHeaderItem(0, __qtablewidgetitem);
        TWBoundary->setObjectName(QString::fromUtf8("TWBoundary"));
        TWBoundary->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        TWBoundary->setShowGrid(true);
        TWBoundary->setRowCount(0);
        TWBoundary->setColumnCount(1);

        formLayout->setWidget(0, QFormLayout::LabelRole, TWBoundary);

        gridLayout1 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
        gridLayout1->setContentsMargins(0, 0, 0, 0);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        PBBoundaryAnEdit = new QPushButton(GBBoundaryA);
        PBBoundaryAnEdit->setObjectName(QString::fromUtf8("PBBoundaryAnEdit"));
        PBBoundaryAnEdit->setAutoDefault(false);

        gridLayout1->addWidget(PBBoundaryAnEdit, 1, 0, 1, 1);

        PBBoundaryAnNew = new QPushButton(GBBoundaryA);
        PBBoundaryAnNew->setObjectName(QString::fromUtf8("PBBoundaryAnNew"));
        PBBoundaryAnNew->setAutoDefault(false);

        gridLayout1->addWidget(PBBoundaryAnNew, 0, 0, 1, 1);

        PBBoundaryAnHelp = new QPushButton(GBBoundaryA);
        PBBoundaryAnHelp->setObjectName(QString::fromUtf8("PBBoundaryAnHelp"));
        PBBoundaryAnHelp->setAutoDefault(false);

        gridLayout1->addWidget(PBBoundaryAnHelp, 2, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout1);


        gridLayout_2->addWidget(GBBoundaryA, 12, 0, 1, 4);

        spacer = new QSpacerItem(239, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacer, 13, 0, 1, 1);

        CBAdvanced = new QCheckBox(CreateCase);
        CBAdvanced->setObjectName(QString::fromUtf8("CBAdvanced"));

        gridLayout_2->addWidget(CBAdvanced, 14, 0, 1, 1);

        GBAdvancedOptions = new QGroupBox(CreateCase);
        GBAdvancedOptions->setObjectName(QString::fromUtf8("GBAdvancedOptions"));
        gridLayout2 = new QGridLayout(GBAdvancedOptions);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        CBPyramid = new QCheckBox(GBAdvancedOptions);
        CBPyramid->setObjectName(QString::fromUtf8("CBPyramid"));

        gridLayout2->addWidget(CBPyramid, 0, 0, 1, 1);


        gridLayout_2->addWidget(GBAdvancedOptions, 15, 0, 1, 2);

        spacer_3 = new QSpacerItem(128, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(spacer_3, 15, 2, 1, 2);

        spacer_4 = new QSpacerItem(239, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacer_4, 16, 0, 1, 2);

        GroupButtons = new QGroupBox(CreateCase);
        GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
        gridLayout3 = new QGridLayout(GroupButtons);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        buttonHelp = new QPushButton(GroupButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
        buttonHelp->setAutoDefault(false);

        gridLayout3->addWidget(buttonHelp, 0, 4, 1, 1);

        buttonApply = new QPushButton(GroupButtons);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));
        buttonApply->setAutoDefault(false);

        gridLayout3->addWidget(buttonApply, 0, 1, 1, 1);

        buttonOk = new QPushButton(GroupButtons);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(false);

        gridLayout3->addWidget(buttonOk, 0, 0, 1, 1);

        buttonCancel = new QPushButton(GroupButtons);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setAutoDefault(false);

        gridLayout3->addWidget(buttonCancel, 0, 2, 1, 1);


        gridLayout_2->addWidget(GroupButtons, 17, 0, 1, 3);

        spacer_2 = new QSpacerItem(128, 25, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(spacer_2, 17, 3, 1, 1);


        retranslateUi(CreateCase);

        CBBoundaryDi->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CreateCase);
    } // setupUi

    void retranslateUi(QDialog *CreateCase)
    {
        CreateCase->setWindowTitle(QApplication::translate("CreateCase", "Create a case", 0, QApplication::UnicodeUTF8));
        Name->setText(QApplication::translate("CreateCase", "Name", 0, QApplication::UnicodeUTF8));
        Directory->setText(QApplication::translate("CreateCase", "Directory", 0, QApplication::UnicodeUTF8));
        PushDir->setText(QString());
        Mesh_2->setText(QApplication::translate("CreateCase", "Mesh", 0, QApplication::UnicodeUTF8));
        PushFichier->setText(QString());
        GBTypeConf->setTitle(QApplication::translate("CreateCase", "Conformity type", 0, QApplication::UnicodeUTF8));
        RBConforme->setText(QApplication::translate("CreateCase", "Conformal", 0, QApplication::UnicodeUTF8));
        RBNonConforme->setText(QApplication::translate("CreateCase", "Non conformal", 0, QApplication::UnicodeUTF8));
        GBTypeNoConf->setTitle(QApplication::translate("CreateCase", "Non conformal option", 0, QApplication::UnicodeUTF8));
        RB1NpM->setText(QApplication::translate("CreateCase", "1 hanging node per mesh", 0, QApplication::UnicodeUTF8));
        RB1NpA->setText(QApplication::translate("CreateCase", "1 node per edge", 0, QApplication::UnicodeUTF8));
        RBQuelconque->setText(QApplication::translate("CreateCase", "Free", 0, QApplication::UnicodeUTF8));
        CBBoundaryD->setText(QApplication::translate("CreateCase", "Discrete boundary", 0, QApplication::UnicodeUTF8));
        CBBoundaryA->setText(QApplication::translate("CreateCase", "Analytical boundary", 0, QApplication::UnicodeUTF8));
        GBBoundaryD->setTitle(QApplication::translate("CreateCase", "Discrete boundary", 0, QApplication::UnicodeUTF8));
        PBBoundaryDiEdit->setText(QApplication::translate("CreateCase", "Edit", 0, QApplication::UnicodeUTF8));
        PBBoundaryDiNew->setText(QApplication::translate("CreateCase", "New", 0, QApplication::UnicodeUTF8));
        PBBoundaryDiHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
        GBBoundaryA->setTitle(QApplication::translate("CreateCase", "Analytical boundary", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = TWBoundary->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CreateCase", "a_virer", 0, QApplication::UnicodeUTF8));
        PBBoundaryAnEdit->setText(QApplication::translate("CreateCase", "Edit", 0, QApplication::UnicodeUTF8));
        PBBoundaryAnNew->setText(QApplication::translate("CreateCase", "New", 0, QApplication::UnicodeUTF8));
        PBBoundaryAnHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
        CBAdvanced->setText(QApplication::translate("CreateCase", "Advanced options", 0, QApplication::UnicodeUTF8));
        GBAdvancedOptions->setTitle(QApplication::translate("CreateCase", "Advanced options", 0, QApplication::UnicodeUTF8));
        CBPyramid->setText(QApplication::translate("CreateCase", "Authorized pyramids", 0, QApplication::UnicodeUTF8));
        GroupButtons->setTitle(QString());
        buttonHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("CreateCase", "Apply", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("CreateCase", "OK", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CreateCase", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateCase: public Ui_CreateCase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATECASE_H
