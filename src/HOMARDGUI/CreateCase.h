/********************************************************************************
** Form generated from reading ui file 'CreateCase.ui'
**
** Created: Mon Sep 12 15:31:56 2011
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

class Ui_CreateCase
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GBAdvancedOptions;
    QGridLayout *gridLayout1;
    QSpacerItem *spacerItem;
    QLabel *TLMinimalDiameter;
    QSpinBox *spinBoxNivMax;
    QDoubleSpinBox *doubleSpinBoxDiamMin;
    QLabel *TLMaximalLevel;
    QGroupBox *GBBoundaryA;
    QTableWidget *TWBoundary;
    QWidget *layoutWidget;
    QGridLayout *gridLayout2;
    QPushButton *PBBoundaryAnEdit;
    QPushButton *PBBoundaryAnNew;
    QPushButton *PBBoundaryAnHelp;
    QCheckBox *CBAdvanced;
    QGroupBox *GBBoundaryD;
    QGridLayout *gridLayout3;
    QPushButton *PBBoundaryDiEdit;
    QPushButton *PBBoundaryDiNew;
    QComboBox *CBBoundaryDi;
    QSpacerItem *spacerItem1;
    QPushButton *PBBoundaryDiHelp;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout4;
    QPushButton *buttonHelp;
    QPushButton *buttonCancel;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QHBoxLayout *hboxLayout;
    QCheckBox *CBBoundaryD;
    QCheckBox *CBBoundaryA;
    QHBoxLayout *hboxLayout1;
    QLabel *Name;
    QLineEdit *LECaseName;
    QHBoxLayout *hboxLayout2;
    QLabel *Directory;
    QPushButton *PushDir;
    QLineEdit *LEDirName;
    QHBoxLayout *hboxLayout3;
    QLabel *Mesh_2;
    QPushButton *PushFichier;
    QLineEdit *LEFileName;
    QSpacerItem *spacerItem2;
    QGroupBox *GBTypeConf;
    QHBoxLayout *hboxLayout4;
    QRadioButton *RBConforme;
    QRadioButton *RBNonConforme;
    QSpacerItem *spacerItem3;
    QGroupBox *GBTypeNoConf;
    QHBoxLayout *hboxLayout5;
    QRadioButton *RB1NpM;
    QRadioButton *RB1NpA;
    QRadioButton *RBQuelconque;
    QSpacerItem *spacerItem4;
    QSpacerItem *spacerItem5;
    QSpacerItem *spacerItem6;

    void setupUi(QDialog *CreateCase)
    {
    CreateCase->setObjectName(QString::fromUtf8("CreateCase"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(CreateCase->sizePolicy().hasHeightForWidth());
    CreateCase->setSizePolicy(sizePolicy);
    CreateCase->setAutoFillBackground(true);
    gridLayout = new QGridLayout(CreateCase);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    GBAdvancedOptions = new QGroupBox(CreateCase);
    GBAdvancedOptions->setObjectName(QString::fromUtf8("GBAdvancedOptions"));
    gridLayout1 = new QGridLayout(GBAdvancedOptions);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout1->addItem(spacerItem, 0, 2, 1, 1);

    TLMinimalDiameter = new QLabel(GBAdvancedOptions);
    TLMinimalDiameter->setObjectName(QString::fromUtf8("TLMinimalDiameter"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(TLMinimalDiameter->sizePolicy().hasHeightForWidth());
    TLMinimalDiameter->setSizePolicy(sizePolicy1);
    TLMinimalDiameter->setWordWrap(false);

    gridLayout1->addWidget(TLMinimalDiameter, 0, 0, 1, 1);

    spinBoxNivMax = new QSpinBox(GBAdvancedOptions);
    spinBoxNivMax->setObjectName(QString::fromUtf8("spinBoxNivMax"));
    spinBoxNivMax->setValue(99);

    gridLayout1->addWidget(spinBoxNivMax, 0, 4, 1, 1);

    doubleSpinBoxDiamMin = new QDoubleSpinBox(GBAdvancedOptions);
    doubleSpinBoxDiamMin->setObjectName(QString::fromUtf8("doubleSpinBoxDiamMin"));
    doubleSpinBoxDiamMin->setDecimals(5);

    gridLayout1->addWidget(doubleSpinBoxDiamMin, 0, 1, 1, 1);

    TLMaximalLevel = new QLabel(GBAdvancedOptions);
    TLMaximalLevel->setObjectName(QString::fromUtf8("TLMaximalLevel"));
    QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(TLMaximalLevel->sizePolicy().hasHeightForWidth());
    TLMaximalLevel->setSizePolicy(sizePolicy2);
    TLMaximalLevel->setWordWrap(false);

    gridLayout1->addWidget(TLMaximalLevel, 0, 3, 1, 1);


    gridLayout->addWidget(GBAdvancedOptions, 14, 0, 1, 1);

    GBBoundaryA = new QGroupBox(CreateCase);
    GBBoundaryA->setObjectName(QString::fromUtf8("GBBoundaryA"));
    GBBoundaryA->setMinimumSize(QSize(548, 200));
    TWBoundary = new QTableWidget(GBBoundaryA);
    TWBoundary->setObjectName(QString::fromUtf8("TWBoundary"));
    TWBoundary->setGeometry(QRect(4, 20, 371, 161));
    TWBoundary->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::NoEditTriggers|QAbstractItemView::SelectedClicked);
    TWBoundary->setShowGrid(true);
    TWBoundary->setRowCount(0);
    TWBoundary->setColumnCount(1);
    layoutWidget = new QWidget(GBBoundaryA);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(430, 40, 77, 95));
    gridLayout2 = new QGridLayout(layoutWidget);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(0);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    PBBoundaryAnEdit = new QPushButton(layoutWidget);
    PBBoundaryAnEdit->setObjectName(QString::fromUtf8("PBBoundaryAnEdit"));
    PBBoundaryAnEdit->setAutoDefault(false);

    gridLayout2->addWidget(PBBoundaryAnEdit, 1, 0, 1, 1);

    PBBoundaryAnNew = new QPushButton(layoutWidget);
    PBBoundaryAnNew->setObjectName(QString::fromUtf8("PBBoundaryAnNew"));
    PBBoundaryAnNew->setAutoDefault(false);

    gridLayout2->addWidget(PBBoundaryAnNew, 0, 0, 1, 1);

    PBBoundaryAnHelp = new QPushButton(layoutWidget);
    PBBoundaryAnHelp->setObjectName(QString::fromUtf8("PBBoundaryAnHelp"));
    PBBoundaryAnHelp->setAutoDefault(false);

    gridLayout2->addWidget(PBBoundaryAnHelp, 2, 0, 1, 1);


    gridLayout->addWidget(GBBoundaryA, 12, 0, 1, 2);

    CBAdvanced = new QCheckBox(CreateCase);
    CBAdvanced->setObjectName(QString::fromUtf8("CBAdvanced"));

    gridLayout->addWidget(CBAdvanced, 13, 0, 1, 1);

    GBBoundaryD = new QGroupBox(CreateCase);
    GBBoundaryD->setObjectName(QString::fromUtf8("GBBoundaryD"));
    QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(GBBoundaryD->sizePolicy().hasHeightForWidth());
    GBBoundaryD->setSizePolicy(sizePolicy3);
    gridLayout3 = new QGridLayout(GBBoundaryD);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(9);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    PBBoundaryDiEdit = new QPushButton(GBBoundaryD);
    PBBoundaryDiEdit->setObjectName(QString::fromUtf8("PBBoundaryDiEdit"));
    PBBoundaryDiEdit->setAutoDefault(false);

    gridLayout3->addWidget(PBBoundaryDiEdit, 0, 3, 1, 1);

    PBBoundaryDiNew = new QPushButton(GBBoundaryD);
    PBBoundaryDiNew->setObjectName(QString::fromUtf8("PBBoundaryDiNew"));
    PBBoundaryDiNew->setAutoDefault(false);

    gridLayout3->addWidget(PBBoundaryDiNew, 0, 2, 1, 1);

    CBBoundaryDi = new QComboBox(GBBoundaryD);
    CBBoundaryDi->setObjectName(QString::fromUtf8("CBBoundaryDi"));
    CBBoundaryDi->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    gridLayout3->addWidget(CBBoundaryDi, 0, 0, 1, 1);

    spacerItem1 = new QSpacerItem(40, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

    gridLayout3->addItem(spacerItem1, 0, 1, 1, 1);

    PBBoundaryDiHelp = new QPushButton(GBBoundaryD);
    PBBoundaryDiHelp->setObjectName(QString::fromUtf8("PBBoundaryDiHelp"));
    PBBoundaryDiHelp->setAutoDefault(false);

    gridLayout3->addWidget(PBBoundaryDiHelp, 0, 4, 1, 1);


    gridLayout->addWidget(GBBoundaryD, 11, 0, 1, 1);

    GroupButtons = new QGroupBox(CreateCase);
    GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
    gridLayout4 = new QGridLayout(GroupButtons);
    gridLayout4->setSpacing(6);
    gridLayout4->setMargin(9);
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    buttonHelp = new QPushButton(GroupButtons);
    buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
    buttonHelp->setAutoDefault(false);

    gridLayout4->addWidget(buttonHelp, 0, 3, 1, 1);

    buttonCancel = new QPushButton(GroupButtons);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
    buttonCancel->setAutoDefault(false);

    gridLayout4->addWidget(buttonCancel, 0, 2, 1, 1);

    buttonApply = new QPushButton(GroupButtons);
    buttonApply->setObjectName(QString::fromUtf8("buttonApply"));
    buttonApply->setAutoDefault(false);

    gridLayout4->addWidget(buttonApply, 0, 1, 1, 1);

    buttonOk = new QPushButton(GroupButtons);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
    buttonOk->setAutoDefault(false);

    gridLayout4->addWidget(buttonOk, 0, 0, 1, 1);


    gridLayout->addWidget(GroupButtons, 15, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    CBBoundaryD = new QCheckBox(CreateCase);
    CBBoundaryD->setObjectName(QString::fromUtf8("CBBoundaryD"));

    hboxLayout->addWidget(CBBoundaryD);

    CBBoundaryA = new QCheckBox(CreateCase);
    CBBoundaryA->setObjectName(QString::fromUtf8("CBBoundaryA"));

    hboxLayout->addWidget(CBBoundaryA);


    gridLayout->addLayout(hboxLayout, 9, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    Name = new QLabel(CreateCase);
    Name->setObjectName(QString::fromUtf8("Name"));

    hboxLayout1->addWidget(Name);

    LECaseName = new QLineEdit(CreateCase);
    LECaseName->setObjectName(QString::fromUtf8("LECaseName"));
    LECaseName->setMinimumSize(QSize(382, 21));

    hboxLayout1->addWidget(LECaseName);


    gridLayout->addLayout(hboxLayout1, 0, 0, 1, 2);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    Directory = new QLabel(CreateCase);
    Directory->setObjectName(QString::fromUtf8("Directory"));

    hboxLayout2->addWidget(Directory);

    PushDir = new QPushButton(CreateCase);
    PushDir->setObjectName(QString::fromUtf8("PushDir"));
    PushDir->setAutoDefault(false);

    hboxLayout2->addWidget(PushDir);

    LEDirName = new QLineEdit(CreateCase);
    LEDirName->setObjectName(QString::fromUtf8("LEDirName"));
    LEDirName->setMinimumSize(QSize(382, 21));

    hboxLayout2->addWidget(LEDirName);


    gridLayout->addLayout(hboxLayout2, 1, 0, 1, 1);

    hboxLayout3 = new QHBoxLayout();
    hboxLayout3->setSpacing(6);
    hboxLayout3->setMargin(0);
    hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
    Mesh_2 = new QLabel(CreateCase);
    Mesh_2->setObjectName(QString::fromUtf8("Mesh_2"));

    hboxLayout3->addWidget(Mesh_2);

    PushFichier = new QPushButton(CreateCase);
    PushFichier->setObjectName(QString::fromUtf8("PushFichier"));
    PushFichier->setAutoDefault(false);

    hboxLayout3->addWidget(PushFichier);

    LEFileName = new QLineEdit(CreateCase);
    LEFileName->setObjectName(QString::fromUtf8("LEFileName"));
    LEFileName->setMinimumSize(QSize(382, 21));

    hboxLayout3->addWidget(LEFileName);


    gridLayout->addLayout(hboxLayout3, 3, 0, 1, 2);

    spacerItem2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem2, 4, 0, 1, 1);

    GBTypeConf = new QGroupBox(CreateCase);
    GBTypeConf->setObjectName(QString::fromUtf8("GBTypeConf"));
    hboxLayout4 = new QHBoxLayout(GBTypeConf);
    hboxLayout4->setSpacing(6);
    hboxLayout4->setMargin(9);
    hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
    RBConforme = new QRadioButton(GBTypeConf);
    RBConforme->setObjectName(QString::fromUtf8("RBConforme"));
    RBConforme->setChecked(true);

    hboxLayout4->addWidget(RBConforme);

    RBNonConforme = new QRadioButton(GBTypeConf);
    RBNonConforme->setObjectName(QString::fromUtf8("RBNonConforme"));

    hboxLayout4->addWidget(RBNonConforme);


    gridLayout->addWidget(GBTypeConf, 5, 0, 1, 2);

    spacerItem3 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem3, 6, 0, 1, 1);

    GBTypeNoConf = new QGroupBox(CreateCase);
    GBTypeNoConf->setObjectName(QString::fromUtf8("GBTypeNoConf"));
    hboxLayout5 = new QHBoxLayout(GBTypeNoConf);
    hboxLayout5->setSpacing(6);
    hboxLayout5->setMargin(9);
    hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
    RB1NpM = new QRadioButton(GBTypeNoConf);
    RB1NpM->setObjectName(QString::fromUtf8("RB1NpM"));

    hboxLayout5->addWidget(RB1NpM);

    RB1NpA = new QRadioButton(GBTypeNoConf);
    RB1NpA->setObjectName(QString::fromUtf8("RB1NpA"));

    hboxLayout5->addWidget(RB1NpA);

    RBQuelconque = new QRadioButton(GBTypeNoConf);
    RBQuelconque->setObjectName(QString::fromUtf8("RBQuelconque"));

    hboxLayout5->addWidget(RBQuelconque);


    gridLayout->addWidget(GBTypeNoConf, 7, 0, 1, 2);

    spacerItem4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem4, 8, 0, 1, 1);

    spacerItem5 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem5, 10, 0, 1, 1);

    spacerItem6 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem6, 2, 1, 1, 1);


    retranslateUi(CreateCase);

    QSize size(599, 925);
    size = size.expandedTo(CreateCase->minimumSizeHint());
    CreateCase->resize(size);


    CBBoundaryDi->setCurrentIndex(-1);


    QMetaObject::connectSlotsByName(CreateCase);
    } // setupUi

    void retranslateUi(QDialog *CreateCase)
    {
    CreateCase->setWindowTitle(QApplication::translate("CreateCase", "Create a case", 0, QApplication::UnicodeUTF8));
    GBAdvancedOptions->setTitle(QApplication::translate("CreateCase", "Advanced options", 0, QApplication::UnicodeUTF8));
    TLMinimalDiameter->setText(QApplication::translate("CreateCase", "Minimal diameter", 0, QApplication::UnicodeUTF8));
    TLMaximalLevel->setText(QApplication::translate("CreateCase", "Maximal level", 0, QApplication::UnicodeUTF8));
    GBBoundaryA->setTitle(QApplication::translate("CreateCase", "Analytical boundary", 0, QApplication::UnicodeUTF8));
    if (TWBoundary->columnCount() < 1)
        TWBoundary->setColumnCount(1);

    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("CreateCase", "a_virer", 0, QApplication::UnicodeUTF8));
    TWBoundary->setHorizontalHeaderItem(0, __colItem);
    PBBoundaryAnEdit->setText(QApplication::translate("CreateCase", "Edit", 0, QApplication::UnicodeUTF8));
    PBBoundaryAnNew->setText(QApplication::translate("CreateCase", "New", 0, QApplication::UnicodeUTF8));
    PBBoundaryAnHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
    CBAdvanced->setText(QApplication::translate("CreateCase", "Advanced options", 0, QApplication::UnicodeUTF8));
    GBBoundaryD->setTitle(QApplication::translate("CreateCase", "Discrete boundary", 0, QApplication::UnicodeUTF8));
    PBBoundaryDiEdit->setText(QApplication::translate("CreateCase", "Edit", 0, QApplication::UnicodeUTF8));
    PBBoundaryDiNew->setText(QApplication::translate("CreateCase", "New", 0, QApplication::UnicodeUTF8));
    PBBoundaryDiHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
    GroupButtons->setTitle(QString());
    buttonHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateCase", "Cancel", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateCase", "Apply", 0, QApplication::UnicodeUTF8));
    buttonOk->setText(QApplication::translate("CreateCase", "OK", 0, QApplication::UnicodeUTF8));
    CBBoundaryD->setText(QApplication::translate("CreateCase", "Discrete boundary", 0, QApplication::UnicodeUTF8));
    CBBoundaryA->setText(QApplication::translate("CreateCase", "Analytical boundary", 0, QApplication::UnicodeUTF8));
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
    Q_UNUSED(CreateCase);
    } // retranslateUi

};

namespace Ui {
    class CreateCase: public Ui_CreateCase {};
} // namespace Ui

#endif // CREATECASE_H
