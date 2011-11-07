/********************************************************************************
** Form generated from reading ui file 'CreateHypothesis.ui'
**
** Created: Fri Oct 28 11:27:29 2011
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef CREATEHYPOTHESIS_H
#define CREATEHYPOTHESIS_H

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
#include <QtGui/QVBoxLayout>

class Ui_CreateHypothesis
{
public:
    QGridLayout *gridLayout;
    QLabel *Name;
    QLineEdit *LEHypothesisName;
    QGroupBox *GBTypeAdaptation;
    QHBoxLayout *hboxLayout;
    QRadioButton *RBUniforme;
    QRadioButton *RBChamp;
    QRadioButton *RBZone;
    QGroupBox *GBUniform;
    QGridLayout *gridLayout1;
    QRadioButton *RBUniDera;
    QRadioButton *RBUniRaff;
    QGroupBox *GBFieldFile;
    QGridLayout *gridLayout2;
    QLabel *FieldFile;
    QLineEdit *LEFieldFile;
    QGroupBox *GBFieldManagement;
    QGridLayout *gridLayout3;
    QHBoxLayout *hboxLayout1;
    QLabel *FieldName;
    QComboBox *CBFieldName;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout2;
    QTableWidget *TWCMP;
    QSpacerItem *spacerItem1;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout3;
    QRadioButton *RBL2;
    QRadioButton *RBInf;
    QCheckBox *CBJump;
    QHBoxLayout *hboxLayout4;
    QGroupBox *GBRefinementThresholds;
    QGridLayout *gridLayout4;
    QRadioButton *RBRPE;
    QDoubleSpinBox *SpinBox_RPE;
    QRadioButton *RBRRel;
    QDoubleSpinBox *SpinBox_RRel;
    QRadioButton *RBRAbs;
    QDoubleSpinBox *SpinBox_RAbs;
    QRadioButton *RBRNo;
    QGroupBox *GBCoarseningThresholds;
    QGridLayout *gridLayout5;
    QRadioButton *RBCPE;
    QDoubleSpinBox *SpinBox_CPE;
    QRadioButton *RBCRel;
    QDoubleSpinBox *SpinBox_CRel;
    QRadioButton *RBCAbs;
    QDoubleSpinBox *SpinBox_CAbs;
    QRadioButton *RBCNo;
    QGroupBox *GBAreaManagement;
    QGridLayout *gridLayout6;
    QTableWidget *TWZone;
    QVBoxLayout *vboxLayout1;
    QVBoxLayout *vboxLayout2;
    QPushButton *PBZoneNew;
    QPushButton *PBZoneEdit;
    QPushButton *PBZoneDelete;
    QSpacerItem *spacerItem2;
    QGroupBox *GBField;
    QGridLayout *gridLayout7;
    QGridLayout *gridLayout8;
    QRadioButton *RBFieldNo;
    QRadioButton *RBFieldAll;
    QRadioButton *RBFieldChosen;
    QTableWidget *TWField;
    QCheckBox *CBGroupe;
    QCheckBox *CBAdvanced;
    QGroupBox *GBAdvancedOptions;
    QGridLayout *gridLayout9;
    QSpacerItem *spacerItem3;
    QLabel *TLMinimalDiameter;
    QSpinBox *spinBoxNivMax;
    QDoubleSpinBox *doubleSpinBoxDiamMin;
    QLabel *TLMaximalLevel;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout10;
    QPushButton *buttonOk;
    QPushButton *buttonApply;
    QPushButton *buttonCancel;
    QPushButton *buttonHelp;

    void setupUi(QDialog *CreateHypothesis)
    {
    CreateHypothesis->setObjectName(QString::fromUtf8("CreateHypothesis"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(CreateHypothesis->sizePolicy().hasHeightForWidth());
    CreateHypothesis->setSizePolicy(sizePolicy);
    CreateHypothesis->setAutoFillBackground(true);
    CreateHypothesis->setSizeGripEnabled(true);
    gridLayout = new QGridLayout(CreateHypothesis);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    Name = new QLabel(CreateHypothesis);
    Name->setObjectName(QString::fromUtf8("Name"));

    gridLayout->addWidget(Name, 0, 0, 1, 1);

    LEHypothesisName = new QLineEdit(CreateHypothesis);
    LEHypothesisName->setObjectName(QString::fromUtf8("LEHypothesisName"));
    LEHypothesisName->setMinimumSize(QSize(382, 31));
    LEHypothesisName->setMaxLength(32);

    gridLayout->addWidget(LEHypothesisName, 0, 1, 1, 1);

    GBTypeAdaptation = new QGroupBox(CreateHypothesis);
    GBTypeAdaptation->setObjectName(QString::fromUtf8("GBTypeAdaptation"));
    hboxLayout = new QHBoxLayout(GBTypeAdaptation);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(9);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    RBUniforme = new QRadioButton(GBTypeAdaptation);
    RBUniforme->setObjectName(QString::fromUtf8("RBUniforme"));
    RBUniforme->setCheckable(true);

    hboxLayout->addWidget(RBUniforme);

    RBChamp = new QRadioButton(GBTypeAdaptation);
    RBChamp->setObjectName(QString::fromUtf8("RBChamp"));

    hboxLayout->addWidget(RBChamp);

    RBZone = new QRadioButton(GBTypeAdaptation);
    RBZone->setObjectName(QString::fromUtf8("RBZone"));

    hboxLayout->addWidget(RBZone);


    gridLayout->addWidget(GBTypeAdaptation, 1, 0, 1, 2);

    GBUniform = new QGroupBox(CreateHypothesis);
    GBUniform->setObjectName(QString::fromUtf8("GBUniform"));
    gridLayout1 = new QGridLayout(GBUniform);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    RBUniDera = new QRadioButton(GBUniform);
    RBUniDera->setObjectName(QString::fromUtf8("RBUniDera"));

    gridLayout1->addWidget(RBUniDera, 0, 1, 1, 1);

    RBUniRaff = new QRadioButton(GBUniform);
    RBUniRaff->setObjectName(QString::fromUtf8("RBUniRaff"));
    RBUniRaff->setChecked(true);

    gridLayout1->addWidget(RBUniRaff, 0, 0, 1, 1);


    gridLayout->addWidget(GBUniform, 2, 0, 1, 2);

    GBFieldFile = new QGroupBox(CreateHypothesis);
    GBFieldFile->setObjectName(QString::fromUtf8("GBFieldFile"));
    gridLayout2 = new QGridLayout(GBFieldFile);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    FieldFile = new QLabel(GBFieldFile);
    FieldFile->setObjectName(QString::fromUtf8("FieldFile"));

    gridLayout2->addWidget(FieldFile, 0, 0, 1, 1);

    LEFieldFile = new QLineEdit(GBFieldFile);
    LEFieldFile->setObjectName(QString::fromUtf8("LEFieldFile"));
    LEFieldFile->setMinimumSize(QSize(282, 31));

    gridLayout2->addWidget(LEFieldFile, 0, 1, 1, 1);


    gridLayout->addWidget(GBFieldFile, 3, 0, 1, 2);

    GBFieldManagement = new QGroupBox(CreateHypothesis);
    GBFieldManagement->setObjectName(QString::fromUtf8("GBFieldManagement"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(GBFieldManagement->sizePolicy().hasHeightForWidth());
    GBFieldManagement->setSizePolicy(sizePolicy1);
    gridLayout3 = new QGridLayout(GBFieldManagement);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(9);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    FieldName = new QLabel(GBFieldManagement);
    FieldName->setObjectName(QString::fromUtf8("FieldName"));

    hboxLayout1->addWidget(FieldName);

    CBFieldName = new QComboBox(GBFieldManagement);
    CBFieldName->setObjectName(QString::fromUtf8("CBFieldName"));
    QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(CBFieldName->sizePolicy().hasHeightForWidth());
    CBFieldName->setSizePolicy(sizePolicy2);
    CBFieldName->setEditable(false);
    CBFieldName->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    hboxLayout1->addWidget(CBFieldName);

    spacerItem = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);


    gridLayout3->addLayout(hboxLayout1, 0, 0, 1, 1);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    TWCMP = new QTableWidget(GBFieldManagement);
    TWCMP->setObjectName(QString::fromUtf8("TWCMP"));
    TWCMP->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::NoEditTriggers|QAbstractItemView::SelectedClicked);
    TWCMP->setShowGrid(true);
    TWCMP->setRowCount(0);
    TWCMP->setColumnCount(2);

    hboxLayout2->addWidget(TWCMP);

    spacerItem1 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem1);

    vboxLayout = new QVBoxLayout();
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    hboxLayout3 = new QHBoxLayout();
    hboxLayout3->setSpacing(6);
    hboxLayout3->setMargin(0);
    hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
    RBL2 = new QRadioButton(GBFieldManagement);
    RBL2->setObjectName(QString::fromUtf8("RBL2"));
    RBL2->setChecked(true);

    hboxLayout3->addWidget(RBL2);

    RBInf = new QRadioButton(GBFieldManagement);
    RBInf->setObjectName(QString::fromUtf8("RBInf"));
    RBInf->setChecked(false);

    hboxLayout3->addWidget(RBInf);


    vboxLayout->addLayout(hboxLayout3);

    CBJump = new QCheckBox(GBFieldManagement);
    CBJump->setObjectName(QString::fromUtf8("CBJump"));

    vboxLayout->addWidget(CBJump);


    hboxLayout2->addLayout(vboxLayout);


    gridLayout3->addLayout(hboxLayout2, 1, 0, 1, 1);

    hboxLayout4 = new QHBoxLayout();
    hboxLayout4->setSpacing(6);
    hboxLayout4->setMargin(0);
    hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
    GBRefinementThresholds = new QGroupBox(GBFieldManagement);
    GBRefinementThresholds->setObjectName(QString::fromUtf8("GBRefinementThresholds"));
    QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(GBRefinementThresholds->sizePolicy().hasHeightForWidth());
    GBRefinementThresholds->setSizePolicy(sizePolicy3);
    gridLayout4 = new QGridLayout(GBRefinementThresholds);
    gridLayout4->setSpacing(6);
    gridLayout4->setMargin(9);
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    RBRPE = new QRadioButton(GBRefinementThresholds);
    RBRPE->setObjectName(QString::fromUtf8("RBRPE"));
    RBRPE->setCheckable(true);
    RBRPE->setChecked(true);

    gridLayout4->addWidget(RBRPE, 0, 0, 1, 1);

    SpinBox_RPE = new QDoubleSpinBox(GBRefinementThresholds);
    SpinBox_RPE->setObjectName(QString::fromUtf8("SpinBox_RPE"));
    SpinBox_RPE->setDecimals(3);
    SpinBox_RPE->setMaximum(100);
    SpinBox_RPE->setSingleStep(0.1);
    SpinBox_RPE->setValue(3);

    gridLayout4->addWidget(SpinBox_RPE, 0, 1, 1, 1);

    RBRRel = new QRadioButton(GBRefinementThresholds);
    RBRRel->setObjectName(QString::fromUtf8("RBRRel"));

    gridLayout4->addWidget(RBRRel, 1, 0, 1, 1);

    SpinBox_RRel = new QDoubleSpinBox(GBRefinementThresholds);
    SpinBox_RRel->setObjectName(QString::fromUtf8("SpinBox_RRel"));
    SpinBox_RRel->setEnabled(false);
    SpinBox_RRel->setDecimals(3);
    SpinBox_RRel->setMaximum(100);
    SpinBox_RRel->setSingleStep(0.1);

    gridLayout4->addWidget(SpinBox_RRel, 1, 1, 1, 1);

    RBRAbs = new QRadioButton(GBRefinementThresholds);
    RBRAbs->setObjectName(QString::fromUtf8("RBRAbs"));

    gridLayout4->addWidget(RBRAbs, 2, 0, 1, 1);

    SpinBox_RAbs = new QDoubleSpinBox(GBRefinementThresholds);
    SpinBox_RAbs->setObjectName(QString::fromUtf8("SpinBox_RAbs"));
    SpinBox_RAbs->setEnabled(false);
    SpinBox_RAbs->setDecimals(8);
    SpinBox_RAbs->setMaximum(1e+12);
    SpinBox_RAbs->setMinimum(-1e+12);
    SpinBox_RAbs->setSingleStep(0.1);

    gridLayout4->addWidget(SpinBox_RAbs, 2, 1, 1, 1);

    RBRNo = new QRadioButton(GBRefinementThresholds);
    RBRNo->setObjectName(QString::fromUtf8("RBRNo"));

    gridLayout4->addWidget(RBRNo, 3, 0, 1, 1);


    hboxLayout4->addWidget(GBRefinementThresholds);

    GBCoarseningThresholds = new QGroupBox(GBFieldManagement);
    GBCoarseningThresholds->setObjectName(QString::fromUtf8("GBCoarseningThresholds"));
    gridLayout5 = new QGridLayout(GBCoarseningThresholds);
    gridLayout5->setSpacing(6);
    gridLayout5->setMargin(9);
    gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
    RBCPE = new QRadioButton(GBCoarseningThresholds);
    RBCPE->setObjectName(QString::fromUtf8("RBCPE"));
    RBCPE->setCheckable(true);
    RBCPE->setChecked(false);

    gridLayout5->addWidget(RBCPE, 0, 0, 1, 1);

    SpinBox_CPE = new QDoubleSpinBox(GBCoarseningThresholds);
    SpinBox_CPE->setObjectName(QString::fromUtf8("SpinBox_CPE"));
    SpinBox_CPE->setEnabled(false);
    SpinBox_CPE->setDecimals(3);
    SpinBox_CPE->setMaximum(100);
    SpinBox_CPE->setSingleStep(0.1);

    gridLayout5->addWidget(SpinBox_CPE, 0, 1, 1, 1);

    RBCRel = new QRadioButton(GBCoarseningThresholds);
    RBCRel->setObjectName(QString::fromUtf8("RBCRel"));

    gridLayout5->addWidget(RBCRel, 1, 0, 1, 1);

    SpinBox_CRel = new QDoubleSpinBox(GBCoarseningThresholds);
    SpinBox_CRel->setObjectName(QString::fromUtf8("SpinBox_CRel"));
    SpinBox_CRel->setEnabled(false);
    SpinBox_CRel->setDecimals(3);
    SpinBox_CRel->setMaximum(100);
    SpinBox_CRel->setSingleStep(0.1);

    gridLayout5->addWidget(SpinBox_CRel, 1, 1, 1, 1);

    RBCAbs = new QRadioButton(GBCoarseningThresholds);
    RBCAbs->setObjectName(QString::fromUtf8("RBCAbs"));

    gridLayout5->addWidget(RBCAbs, 2, 0, 1, 1);

    SpinBox_CAbs = new QDoubleSpinBox(GBCoarseningThresholds);
    SpinBox_CAbs->setObjectName(QString::fromUtf8("SpinBox_CAbs"));
    SpinBox_CAbs->setEnabled(false);
    SpinBox_CAbs->setDecimals(8);
    SpinBox_CAbs->setMaximum(1e+12);
    SpinBox_CAbs->setMinimum(-1e+12);
    SpinBox_CAbs->setSingleStep(0.1);

    gridLayout5->addWidget(SpinBox_CAbs, 2, 1, 1, 1);

    RBCNo = new QRadioButton(GBCoarseningThresholds);
    RBCNo->setObjectName(QString::fromUtf8("RBCNo"));
    RBCNo->setChecked(true);

    gridLayout5->addWidget(RBCNo, 3, 0, 1, 1);


    hboxLayout4->addWidget(GBCoarseningThresholds);


    gridLayout3->addLayout(hboxLayout4, 2, 0, 1, 1);


    gridLayout->addWidget(GBFieldManagement, 4, 0, 1, 2);

    GBAreaManagement = new QGroupBox(CreateHypothesis);
    GBAreaManagement->setObjectName(QString::fromUtf8("GBAreaManagement"));
    QSizePolicy sizePolicy4(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(GBAreaManagement->sizePolicy().hasHeightForWidth());
    GBAreaManagement->setSizePolicy(sizePolicy4);
    gridLayout6 = new QGridLayout(GBAreaManagement);
    gridLayout6->setSpacing(6);
    gridLayout6->setMargin(9);
    gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
    TWZone = new QTableWidget(GBAreaManagement);
    TWZone->setObjectName(QString::fromUtf8("TWZone"));
    TWZone->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::NoEditTriggers|QAbstractItemView::SelectedClicked);
    TWZone->setShowGrid(true);
    TWZone->setRowCount(0);
    TWZone->setColumnCount(2);

    gridLayout6->addWidget(TWZone, 0, 0, 1, 1);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    vboxLayout2 = new QVBoxLayout();
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(0);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    PBZoneNew = new QPushButton(GBAreaManagement);
    PBZoneNew->setObjectName(QString::fromUtf8("PBZoneNew"));

    vboxLayout2->addWidget(PBZoneNew);

    PBZoneEdit = new QPushButton(GBAreaManagement);
    PBZoneEdit->setObjectName(QString::fromUtf8("PBZoneEdit"));

    vboxLayout2->addWidget(PBZoneEdit);

    PBZoneDelete = new QPushButton(GBAreaManagement);
    PBZoneDelete->setObjectName(QString::fromUtf8("PBZoneDelete"));

    vboxLayout2->addWidget(PBZoneDelete);


    vboxLayout1->addLayout(vboxLayout2);

    spacerItem2 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout1->addItem(spacerItem2);


    gridLayout6->addLayout(vboxLayout1, 0, 1, 1, 1);


    gridLayout->addWidget(GBAreaManagement, 5, 0, 1, 2);

    GBField = new QGroupBox(CreateHypothesis);
    GBField->setObjectName(QString::fromUtf8("GBField"));
    gridLayout7 = new QGridLayout(GBField);
    gridLayout7->setSpacing(6);
    gridLayout7->setMargin(9);
    gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
    gridLayout8 = new QGridLayout();
    gridLayout8->setSpacing(6);
    gridLayout8->setMargin(0);
    gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
    RBFieldNo = new QRadioButton(GBField);
    RBFieldNo->setObjectName(QString::fromUtf8("RBFieldNo"));
    RBFieldNo->setChecked(true);

    gridLayout8->addWidget(RBFieldNo, 0, 0, 1, 1);

    RBFieldAll = new QRadioButton(GBField);
    RBFieldAll->setObjectName(QString::fromUtf8("RBFieldAll"));
    RBFieldAll->setChecked(false);

    gridLayout8->addWidget(RBFieldAll, 0, 1, 1, 1);

    RBFieldChosen = new QRadioButton(GBField);
    RBFieldChosen->setObjectName(QString::fromUtf8("RBFieldChosen"));
    RBFieldChosen->setChecked(false);

    gridLayout8->addWidget(RBFieldChosen, 0, 2, 1, 1);


    gridLayout7->addLayout(gridLayout8, 0, 0, 1, 1);

    TWField = new QTableWidget(GBField);
    TWField->setObjectName(QString::fromUtf8("TWField"));

    gridLayout7->addWidget(TWField, 1, 0, 1, 1);


    gridLayout->addWidget(GBField, 6, 0, 1, 2);

    CBGroupe = new QCheckBox(CreateHypothesis);
    CBGroupe->setObjectName(QString::fromUtf8("CBGroupe"));

    gridLayout->addWidget(CBGroupe, 7, 0, 1, 2);

    CBAdvanced = new QCheckBox(CreateHypothesis);
    CBAdvanced->setObjectName(QString::fromUtf8("CBAdvanced"));

    gridLayout->addWidget(CBAdvanced, 8, 0, 1, 1);

    GBAdvancedOptions = new QGroupBox(CreateHypothesis);
    GBAdvancedOptions->setObjectName(QString::fromUtf8("GBAdvancedOptions"));
    gridLayout9 = new QGridLayout(GBAdvancedOptions);
    gridLayout9->setSpacing(6);
    gridLayout9->setMargin(9);
    gridLayout9->setObjectName(QString::fromUtf8("gridLayout9"));
    spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout9->addItem(spacerItem3, 0, 2, 1, 1);

    TLMinimalDiameter = new QLabel(GBAdvancedOptions);
    TLMinimalDiameter->setObjectName(QString::fromUtf8("TLMinimalDiameter"));
    QSizePolicy sizePolicy5(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy5.setHorizontalStretch(0);
    sizePolicy5.setVerticalStretch(0);
    sizePolicy5.setHeightForWidth(TLMinimalDiameter->sizePolicy().hasHeightForWidth());
    TLMinimalDiameter->setSizePolicy(sizePolicy5);
    TLMinimalDiameter->setWordWrap(false);

    gridLayout9->addWidget(TLMinimalDiameter, 0, 0, 1, 1);

    spinBoxNivMax = new QSpinBox(GBAdvancedOptions);
    spinBoxNivMax->setObjectName(QString::fromUtf8("spinBoxNivMax"));
    spinBoxNivMax->setValue(99);

    gridLayout9->addWidget(spinBoxNivMax, 0, 4, 1, 1);

    doubleSpinBoxDiamMin = new QDoubleSpinBox(GBAdvancedOptions);
    doubleSpinBoxDiamMin->setObjectName(QString::fromUtf8("doubleSpinBoxDiamMin"));
    doubleSpinBoxDiamMin->setDecimals(5);

    gridLayout9->addWidget(doubleSpinBoxDiamMin, 0, 1, 1, 1);

    TLMaximalLevel = new QLabel(GBAdvancedOptions);
    TLMaximalLevel->setObjectName(QString::fromUtf8("TLMaximalLevel"));
    QSizePolicy sizePolicy6(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy6.setHorizontalStretch(0);
    sizePolicy6.setVerticalStretch(0);
    sizePolicy6.setHeightForWidth(TLMaximalLevel->sizePolicy().hasHeightForWidth());
    TLMaximalLevel->setSizePolicy(sizePolicy6);
    TLMaximalLevel->setWordWrap(false);

    gridLayout9->addWidget(TLMaximalLevel, 0, 3, 1, 1);


    gridLayout->addWidget(GBAdvancedOptions, 9, 0, 1, 1);

    GBButtons = new QGroupBox(CreateHypothesis);
    GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
    gridLayout10 = new QGridLayout(GBButtons);
    gridLayout10->setSpacing(6);
    gridLayout10->setMargin(9);
    gridLayout10->setObjectName(QString::fromUtf8("gridLayout10"));
    buttonOk = new QPushButton(GBButtons);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

    gridLayout10->addWidget(buttonOk, 0, 0, 1, 1);

    buttonApply = new QPushButton(GBButtons);
    buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

    gridLayout10->addWidget(buttonApply, 0, 1, 1, 1);

    buttonCancel = new QPushButton(GBButtons);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

    gridLayout10->addWidget(buttonCancel, 0, 2, 1, 1);

    buttonHelp = new QPushButton(GBButtons);
    buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

    gridLayout10->addWidget(buttonHelp, 0, 3, 1, 1);


    gridLayout->addWidget(GBButtons, 10, 0, 1, 2);


    retranslateUi(CreateHypothesis);

    QSize size(717, 1166);
    size = size.expandedTo(CreateHypothesis->minimumSizeHint());
    CreateHypothesis->resize(size);


    QMetaObject::connectSlotsByName(CreateHypothesis);
    } // setupUi

    void retranslateUi(QDialog *CreateHypothesis)
    {
    CreateHypothesis->setWindowTitle(QApplication::translate("CreateHypothesis", "Create an hypothesis", 0, QApplication::UnicodeUTF8));
    Name->setText(QApplication::translate("CreateHypothesis", "Name", 0, QApplication::UnicodeUTF8));
    GBTypeAdaptation->setTitle(QApplication::translate("CreateHypothesis", "Type of adaptation", 0, QApplication::UnicodeUTF8));
    RBUniforme->setText(QApplication::translate("CreateHypothesis", "Uniform", 0, QApplication::UnicodeUTF8));
    RBChamp->setText(QApplication::translate("CreateHypothesis", "Driven by a field", 0, QApplication::UnicodeUTF8));
    RBZone->setText(QApplication::translate("CreateHypothesis", "With geometrical zones", 0, QApplication::UnicodeUTF8));
    GBUniform->setTitle(QApplication::translate("CreateHypothesis", "Uniform adaptation", 0, QApplication::UnicodeUTF8));
    RBUniDera->setText(QApplication::translate("CreateHypothesis", "Coarsening", 0, QApplication::UnicodeUTF8));
    RBUniRaff->setText(QApplication::translate("CreateHypothesis", "Refinement", 0, QApplication::UnicodeUTF8));
    GBFieldFile->setTitle(QString());
    FieldFile->setText(QApplication::translate("CreateHypothesis", "File of the fields", 0, QApplication::UnicodeUTF8));
    GBFieldManagement->setTitle(QApplication::translate("CreateHypothesis", "Governing field for the adaptation", 0, QApplication::UnicodeUTF8));
    FieldName->setText(QApplication::translate("CreateHypothesis", "Field name", 0, QApplication::UnicodeUTF8));
    if (TWCMP->columnCount() < 2)
        TWCMP->setColumnCount(2);

    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("CreateHypothesis", "Selection", 0, QApplication::UnicodeUTF8));
    TWCMP->setHorizontalHeaderItem(0, __colItem);

    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    __colItem1->setText(QApplication::translate("CreateHypothesis", "Component", 0, QApplication::UnicodeUTF8));
    TWCMP->setHorizontalHeaderItem(1, __colItem1);
    RBL2->setText(QApplication::translate("CreateHypothesis", "L2 norm", 0, QApplication::UnicodeUTF8));
    RBInf->setText(QApplication::translate("CreateHypothesis", "Infinite norm", 0, QApplication::UnicodeUTF8));
    CBJump->setText(QApplication::translate("CreateHypothesis", "Jump between elements", 0, QApplication::UnicodeUTF8));
    GBRefinementThresholds->setTitle(QApplication::translate("CreateHypothesis", "Refinement threshold", 0, QApplication::UnicodeUTF8));
    RBRPE->setText(QApplication::translate("CreateHypothesis", "Percentage of meshes", 0, QApplication::UnicodeUTF8));
    SpinBox_RPE->setSuffix(QApplication::translate("CreateHypothesis", " %", 0, QApplication::UnicodeUTF8));
    RBRRel->setText(QApplication::translate("CreateHypothesis", "Relative", 0, QApplication::UnicodeUTF8));
    SpinBox_RRel->setSuffix(QApplication::translate("CreateHypothesis", " %", 0, QApplication::UnicodeUTF8));
    RBRAbs->setText(QApplication::translate("CreateHypothesis", "Absolute", 0, QApplication::UnicodeUTF8));
    RBRNo->setText(QApplication::translate("CreateHypothesis", "No refinement", 0, QApplication::UnicodeUTF8));
    GBCoarseningThresholds->setTitle(QApplication::translate("CreateHypothesis", "Coarsening threshold", 0, QApplication::UnicodeUTF8));
    RBCPE->setText(QApplication::translate("CreateHypothesis", "Percentage of meshes", 0, QApplication::UnicodeUTF8));
    SpinBox_CPE->setSuffix(QApplication::translate("CreateHypothesis", " %", 0, QApplication::UnicodeUTF8));
    RBCRel->setText(QApplication::translate("CreateHypothesis", "Relative", 0, QApplication::UnicodeUTF8));
    SpinBox_CRel->setSuffix(QApplication::translate("CreateHypothesis", " %", 0, QApplication::UnicodeUTF8));
    RBCAbs->setText(QApplication::translate("CreateHypothesis", "Absolute", 0, QApplication::UnicodeUTF8));
    RBCNo->setText(QApplication::translate("CreateHypothesis", "No coarsening", 0, QApplication::UnicodeUTF8));
    GBAreaManagement->setTitle(QApplication::translate("CreateHypothesis", "Zone management", 0, QApplication::UnicodeUTF8));
    if (TWZone->columnCount() < 2)
        TWZone->setColumnCount(2);

    QTableWidgetItem *__colItem2 = new QTableWidgetItem();
    __colItem2->setText(QApplication::translate("CreateHypothesis", "Selection", 0, QApplication::UnicodeUTF8));
    TWZone->setHorizontalHeaderItem(0, __colItem2);

    QTableWidgetItem *__colItem3 = new QTableWidgetItem();
    __colItem3->setText(QApplication::translate("CreateHypothesis", "Zone name", 0, QApplication::UnicodeUTF8));
    TWZone->setHorizontalHeaderItem(1, __colItem3);
    PBZoneNew->setText(QApplication::translate("CreateHypothesis", "New", 0, QApplication::UnicodeUTF8));
    PBZoneEdit->setText(QApplication::translate("CreateHypothesis", "Edit", 0, QApplication::UnicodeUTF8));
    PBZoneDelete->setText(QString());
    GBField->setTitle(QApplication::translate("CreateHypothesis", "Field Interpolation", 0, QApplication::UnicodeUTF8));
    RBFieldNo->setText(QApplication::translate("CreateHypothesis", "None", 0, QApplication::UnicodeUTF8));
    RBFieldAll->setText(QApplication::translate("CreateHypothesis", "All", 0, QApplication::UnicodeUTF8));
    RBFieldChosen->setText(QApplication::translate("CreateHypothesis", "Chosen", 0, QApplication::UnicodeUTF8));
    if (TWField->columnCount() < 2)
        TWField->setColumnCount(2);

    QTableWidgetItem *__colItem4 = new QTableWidgetItem();
    __colItem4->setText(QApplication::translate("CreateHypothesis", "Selection", 0, QApplication::UnicodeUTF8));
    TWField->setHorizontalHeaderItem(0, __colItem4);

    QTableWidgetItem *__colItem5 = new QTableWidgetItem();
    __colItem5->setText(QApplication::translate("CreateHypothesis", "Field Name", 0, QApplication::UnicodeUTF8));
    TWField->setHorizontalHeaderItem(1, __colItem5);
    CBGroupe->setText(QApplication::translate("CreateHypothesis", "Filtering with groups", 0, QApplication::UnicodeUTF8));
    CBAdvanced->setText(QApplication::translate("CreateHypothesis", "Advanced options", 0, QApplication::UnicodeUTF8));
    GBAdvancedOptions->setTitle(QApplication::translate("CreateHypothesis", "Advanced options", 0, QApplication::UnicodeUTF8));
    TLMinimalDiameter->setText(QApplication::translate("CreateHypothesis", "Minimal diameter", 0, QApplication::UnicodeUTF8));
    TLMaximalLevel->setText(QApplication::translate("CreateHypothesis", "Maximal level", 0, QApplication::UnicodeUTF8));
    GBButtons->setTitle(QString());
    buttonOk->setText(QApplication::translate("CreateHypothesis", "OK", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateHypothesis", "Apply", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateHypothesis", "Cancel", 0, QApplication::UnicodeUTF8));
    buttonHelp->setText(QApplication::translate("CreateHypothesis", "Help", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CreateHypothesis);
    } // retranslateUi

};

namespace Ui {
    class CreateHypothesis: public Ui_CreateHypothesis {};
} // namespace Ui

#endif // CREATEHYPOTHESIS_H
