/********************************************************************************
** Form generated from reading ui file 'CreateHypothesis.ui'
**
** Created: Thu Nov 18 15:21:42 2010
**      by: Qt User Interface Compiler version 4.4.3
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
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateHypothesis
{
public:
    QGridLayout *gridLayout_10;
    QLabel *Name;
    QLineEdit *LEHypothesisName;
    QGroupBox *GBTypeAdaptation;
    QHBoxLayout *horizontalLayout;
    QRadioButton *RBUniforme;
    QRadioButton *RBChamp;
    QRadioButton *RBZone;
    QGroupBox *GBUniform;
    QGridLayout *gridLayout_2;
    QRadioButton *RBUniDera;
    QRadioButton *RBUniRaff;
    QGroupBox *GBFieldFile;
    QGridLayout *gridLayout_9;
    QLabel *FieldFile;
    QLineEdit *LEFieldFile;
    QGroupBox *GBFieldManagement;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *FieldName;
    QComboBox *CBFieldName;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QTableWidget *TWCMP;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *RBL2;
    QRadioButton *RBInf;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *GBRefinementThresholds;
    QGridLayout *gridLayout;
    QRadioButton *RBRPE;
    QDoubleSpinBox *SpinBox_RPE;
    QRadioButton *RBRRel;
    QDoubleSpinBox *SpinBox_RRel;
    QRadioButton *RBRAbs;
    QDoubleSpinBox *SpinBox_RAbs;
    QRadioButton *RBRNo;
    QGroupBox *GBCoarseningThresholds;
    QGridLayout *gridLayout_4;
    QRadioButton *RBCPE;
    QDoubleSpinBox *SpinBox_CPE;
    QRadioButton *RBCRel;
    QDoubleSpinBox *SpinBox_CRel;
    QRadioButton *RBCAbs;
    QDoubleSpinBox *SpinBox_CAbs;
    QRadioButton *RBCNo;
    QGroupBox *GBAreaManagement;
    QGridLayout *gridLayout_3;
    QTableWidget *TWZone;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *PBZoneNew;
    QPushButton *PBZoneEdit;
    QPushButton *PBZoneDelete;
    QSpacerItem *verticalSpacer;
    QGroupBox *GBField;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QRadioButton *RBFieldNo;
    QRadioButton *RBFieldAll;
    QRadioButton *RBFieldChosen;
    QTableWidget *TWField;
    QCheckBox *CBGroupe;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout_5;
    QPushButton *buttonOk;
    QPushButton *buttonApply;
    QPushButton *buttonCancel;
    QPushButton *buttonHelp;

    void setupUi(QDialog *CreateHypothesis)
    {
    if (CreateHypothesis->objectName().isEmpty())
        CreateHypothesis->setObjectName(QString::fromUtf8("CreateHypothesis"));
    CreateHypothesis->resize(717, 1005);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(CreateHypothesis->sizePolicy().hasHeightForWidth());
    CreateHypothesis->setSizePolicy(sizePolicy);
    CreateHypothesis->setAutoFillBackground(false);
    CreateHypothesis->setSizeGripEnabled(true);
    gridLayout_10 = new QGridLayout(CreateHypothesis);
    gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
    Name = new QLabel(CreateHypothesis);
    Name->setObjectName(QString::fromUtf8("Name"));

    gridLayout_10->addWidget(Name, 0, 0, 1, 1);

    LEHypothesisName = new QLineEdit(CreateHypothesis);
    LEHypothesisName->setObjectName(QString::fromUtf8("LEHypothesisName"));
    LEHypothesisName->setMinimumSize(QSize(382, 31));
    LEHypothesisName->setMaxLength(32);

    gridLayout_10->addWidget(LEHypothesisName, 0, 1, 1, 1);

    GBTypeAdaptation = new QGroupBox(CreateHypothesis);
    GBTypeAdaptation->setObjectName(QString::fromUtf8("GBTypeAdaptation"));
    horizontalLayout = new QHBoxLayout(GBTypeAdaptation);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    RBUniforme = new QRadioButton(GBTypeAdaptation);
    RBUniforme->setObjectName(QString::fromUtf8("RBUniforme"));
    RBUniforme->setCheckable(true);

    horizontalLayout->addWidget(RBUniforme);

    RBChamp = new QRadioButton(GBTypeAdaptation);
    RBChamp->setObjectName(QString::fromUtf8("RBChamp"));

    horizontalLayout->addWidget(RBChamp);

    RBZone = new QRadioButton(GBTypeAdaptation);
    RBZone->setObjectName(QString::fromUtf8("RBZone"));

    horizontalLayout->addWidget(RBZone);


    gridLayout_10->addWidget(GBTypeAdaptation, 1, 0, 1, 2);

    GBUniform = new QGroupBox(CreateHypothesis);
    GBUniform->setObjectName(QString::fromUtf8("GBUniform"));
    gridLayout_2 = new QGridLayout(GBUniform);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    RBUniDera = new QRadioButton(GBUniform);
    RBUniDera->setObjectName(QString::fromUtf8("RBUniDera"));

    gridLayout_2->addWidget(RBUniDera, 0, 1, 1, 1);

    RBUniRaff = new QRadioButton(GBUniform);
    RBUniRaff->setObjectName(QString::fromUtf8("RBUniRaff"));
    RBUniRaff->setChecked(true);

    gridLayout_2->addWidget(RBUniRaff, 0, 0, 1, 1);


    gridLayout_10->addWidget(GBUniform, 2, 0, 1, 2);

    GBFieldFile = new QGroupBox(CreateHypothesis);
    GBFieldFile->setObjectName(QString::fromUtf8("GBFieldFile"));
    gridLayout_9 = new QGridLayout(GBFieldFile);
    gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
    FieldFile = new QLabel(GBFieldFile);
    FieldFile->setObjectName(QString::fromUtf8("FieldFile"));

    gridLayout_9->addWidget(FieldFile, 0, 0, 1, 1);

    LEFieldFile = new QLineEdit(GBFieldFile);
    LEFieldFile->setObjectName(QString::fromUtf8("LEFieldFile"));
    LEFieldFile->setMinimumSize(QSize(282, 31));

    gridLayout_9->addWidget(LEFieldFile, 0, 1, 1, 1);


    gridLayout_10->addWidget(GBFieldFile, 3, 0, 1, 2);

    GBFieldManagement = new QGroupBox(CreateHypothesis);
    GBFieldManagement->setObjectName(QString::fromUtf8("GBFieldManagement"));
    sizePolicy.setHeightForWidth(GBFieldManagement->sizePolicy().hasHeightForWidth());
    GBFieldManagement->setSizePolicy(sizePolicy);
    gridLayout_6 = new QGridLayout(GBFieldManagement);
    gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
    horizontalLayout_6 = new QHBoxLayout();
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    FieldName = new QLabel(GBFieldManagement);
    FieldName->setObjectName(QString::fromUtf8("FieldName"));

    horizontalLayout_6->addWidget(FieldName);

    CBFieldName = new QComboBox(GBFieldManagement);
    CBFieldName->setObjectName(QString::fromUtf8("CBFieldName"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(CBFieldName->sizePolicy().hasHeightForWidth());
    CBFieldName->setSizePolicy(sizePolicy1);
    CBFieldName->setEditable(false);
    CBFieldName->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    horizontalLayout_6->addWidget(CBFieldName);

    horizontalSpacer_3 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_6->addItem(horizontalSpacer_3);


    gridLayout_6->addLayout(horizontalLayout_6, 0, 0, 1, 1);

    horizontalLayout_7 = new QHBoxLayout();
    horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
    TWCMP = new QTableWidget(GBFieldManagement);
    if (TWCMP->columnCount() < 2)
        TWCMP->setColumnCount(2);
    QTableWidgetItem *__colItem = new QTableWidgetItem();
    TWCMP->setHorizontalHeaderItem(0, __colItem);
    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    TWCMP->setHorizontalHeaderItem(1, __colItem1);
    TWCMP->setObjectName(QString::fromUtf8("TWCMP"));
    TWCMP->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
    TWCMP->setShowGrid(true);
    TWCMP->setRowCount(0);
    TWCMP->setColumnCount(2);

    horizontalLayout_7->addWidget(TWCMP);

    horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_7->addItem(horizontalSpacer_4);

    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    RBL2 = new QRadioButton(GBFieldManagement);
    RBL2->setObjectName(QString::fromUtf8("RBL2"));
    RBL2->setChecked(true);

    horizontalLayout_3->addWidget(RBL2);

    RBInf = new QRadioButton(GBFieldManagement);
    RBInf->setObjectName(QString::fromUtf8("RBInf"));
    RBInf->setChecked(false);

    horizontalLayout_3->addWidget(RBInf);


    verticalLayout_3->addLayout(horizontalLayout_3);


    horizontalLayout_7->addLayout(verticalLayout_3);


    gridLayout_6->addLayout(horizontalLayout_7, 1, 0, 1, 1);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    GBRefinementThresholds = new QGroupBox(GBFieldManagement);
    GBRefinementThresholds->setObjectName(QString::fromUtf8("GBRefinementThresholds"));
    sizePolicy.setHeightForWidth(GBRefinementThresholds->sizePolicy().hasHeightForWidth());
    GBRefinementThresholds->setSizePolicy(sizePolicy);
    gridLayout = new QGridLayout(GBRefinementThresholds);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    RBRPE = new QRadioButton(GBRefinementThresholds);
    RBRPE->setObjectName(QString::fromUtf8("RBRPE"));
    RBRPE->setCheckable(true);
    RBRPE->setChecked(true);

    gridLayout->addWidget(RBRPE, 0, 0, 1, 1);

    SpinBox_RPE = new QDoubleSpinBox(GBRefinementThresholds);
    SpinBox_RPE->setObjectName(QString::fromUtf8("SpinBox_RPE"));
    SpinBox_RPE->setDecimals(3);
    SpinBox_RPE->setMaximum(100);
    SpinBox_RPE->setSingleStep(0.1);
    SpinBox_RPE->setValue(3);

    gridLayout->addWidget(SpinBox_RPE, 0, 1, 1, 1);

    RBRRel = new QRadioButton(GBRefinementThresholds);
    RBRRel->setObjectName(QString::fromUtf8("RBRRel"));

    gridLayout->addWidget(RBRRel, 1, 0, 1, 1);

    SpinBox_RRel = new QDoubleSpinBox(GBRefinementThresholds);
    SpinBox_RRel->setObjectName(QString::fromUtf8("SpinBox_RRel"));
    SpinBox_RRel->setEnabled(false);
    SpinBox_RRel->setDecimals(3);
    SpinBox_RRel->setMaximum(100);
    SpinBox_RRel->setSingleStep(0.1);

    gridLayout->addWidget(SpinBox_RRel, 1, 1, 1, 1);

    RBRAbs = new QRadioButton(GBRefinementThresholds);
    RBRAbs->setObjectName(QString::fromUtf8("RBRAbs"));

    gridLayout->addWidget(RBRAbs, 2, 0, 1, 1);

    SpinBox_RAbs = new QDoubleSpinBox(GBRefinementThresholds);
    SpinBox_RAbs->setObjectName(QString::fromUtf8("SpinBox_RAbs"));
    SpinBox_RAbs->setEnabled(false);
    SpinBox_RAbs->setDecimals(3);
    SpinBox_RAbs->setMaximum(100);
    SpinBox_RAbs->setSingleStep(0.1);

    gridLayout->addWidget(SpinBox_RAbs, 2, 1, 1, 1);

    RBRNo = new QRadioButton(GBRefinementThresholds);
    RBRNo->setObjectName(QString::fromUtf8("RBRNo"));

    gridLayout->addWidget(RBRNo, 3, 0, 1, 1);


    horizontalLayout_2->addWidget(GBRefinementThresholds);

    GBCoarseningThresholds = new QGroupBox(GBFieldManagement);
    GBCoarseningThresholds->setObjectName(QString::fromUtf8("GBCoarseningThresholds"));
    gridLayout_4 = new QGridLayout(GBCoarseningThresholds);
    gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
    RBCPE = new QRadioButton(GBCoarseningThresholds);
    RBCPE->setObjectName(QString::fromUtf8("RBCPE"));
    RBCPE->setCheckable(true);
    RBCPE->setChecked(false);

    gridLayout_4->addWidget(RBCPE, 0, 0, 1, 1);

    SpinBox_CPE = new QDoubleSpinBox(GBCoarseningThresholds);
    SpinBox_CPE->setObjectName(QString::fromUtf8("SpinBox_CPE"));
    SpinBox_CPE->setEnabled(false);
    SpinBox_CPE->setDecimals(3);
    SpinBox_CPE->setMaximum(100);
    SpinBox_CPE->setSingleStep(0.1);

    gridLayout_4->addWidget(SpinBox_CPE, 0, 1, 1, 1);

    RBCRel = new QRadioButton(GBCoarseningThresholds);
    RBCRel->setObjectName(QString::fromUtf8("RBCRel"));

    gridLayout_4->addWidget(RBCRel, 1, 0, 1, 1);

    SpinBox_CRel = new QDoubleSpinBox(GBCoarseningThresholds);
    SpinBox_CRel->setObjectName(QString::fromUtf8("SpinBox_CRel"));
    SpinBox_CRel->setEnabled(false);
    SpinBox_CRel->setDecimals(3);
    SpinBox_CRel->setMaximum(100);
    SpinBox_CRel->setSingleStep(0.1);

    gridLayout_4->addWidget(SpinBox_CRel, 1, 1, 1, 1);

    RBCAbs = new QRadioButton(GBCoarseningThresholds);
    RBCAbs->setObjectName(QString::fromUtf8("RBCAbs"));

    gridLayout_4->addWidget(RBCAbs, 2, 0, 1, 1);

    SpinBox_CAbs = new QDoubleSpinBox(GBCoarseningThresholds);
    SpinBox_CAbs->setObjectName(QString::fromUtf8("SpinBox_CAbs"));
    SpinBox_CAbs->setEnabled(false);
    SpinBox_CAbs->setDecimals(3);
    SpinBox_CAbs->setMaximum(100);
    SpinBox_CAbs->setSingleStep(0.1);

    gridLayout_4->addWidget(SpinBox_CAbs, 2, 1, 1, 1);

    RBCNo = new QRadioButton(GBCoarseningThresholds);
    RBCNo->setObjectName(QString::fromUtf8("RBCNo"));
    RBCNo->setChecked(true);

    gridLayout_4->addWidget(RBCNo, 3, 0, 1, 1);


    horizontalLayout_2->addWidget(GBCoarseningThresholds);


    gridLayout_6->addLayout(horizontalLayout_2, 2, 0, 1, 1);


    gridLayout_10->addWidget(GBFieldManagement, 4, 0, 1, 2);

    GBAreaManagement = new QGroupBox(CreateHypothesis);
    GBAreaManagement->setObjectName(QString::fromUtf8("GBAreaManagement"));
    sizePolicy.setHeightForWidth(GBAreaManagement->sizePolicy().hasHeightForWidth());
    GBAreaManagement->setSizePolicy(sizePolicy);
    gridLayout_3 = new QGridLayout(GBAreaManagement);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));



    TWZone = new QTableWidget(GBAreaManagement);
    if (TWZone->columnCount() < 2)
        TWZone->setColumnCount(2);
    QTableWidgetItem *__colItem2 = new QTableWidgetItem();
    TWZone->setHorizontalHeaderItem(0, __colItem2);
    QTableWidgetItem *__colItem3 = new QTableWidgetItem();
    TWZone->setHorizontalHeaderItem(1, __colItem3);
    TWZone->setObjectName(QString::fromUtf8("TWZone"));
    TWZone->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
    TWZone->setShowGrid(true);
    TWZone->setRowCount(0);
    TWZone->setColumnCount(2);

    gridLayout_3->addWidget(TWZone, 0, 0, 1, 1);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    PBZoneNew = new QPushButton(GBAreaManagement);
    PBZoneNew->setObjectName(QString::fromUtf8("PBZoneNew"));

    verticalLayout->addWidget(PBZoneNew);

    PBZoneEdit = new QPushButton(GBAreaManagement);
    PBZoneEdit->setObjectName(QString::fromUtf8("PBZoneEdit"));

    verticalLayout->addWidget(PBZoneEdit);

    PBZoneDelete = new QPushButton(GBAreaManagement);
    PBZoneDelete->setObjectName(QString::fromUtf8("PBZoneDelete"));

    verticalLayout->addWidget(PBZoneDelete);


    verticalLayout_2->addLayout(verticalLayout);

    verticalSpacer = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer);


    gridLayout_3->addLayout(verticalLayout_2, 0, 1, 1, 1);


    gridLayout_10->addWidget(GBAreaManagement, 5, 0, 1, 2);

    GBField = new QGroupBox(CreateHypothesis);
    GBField->setObjectName(QString::fromUtf8("GBField"));
    gridLayout_8 = new QGridLayout(GBField);
    gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
    gridLayout_7 = new QGridLayout();
    gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
    RBFieldNo = new QRadioButton(GBField);
    RBFieldNo->setObjectName(QString::fromUtf8("RBFieldNo"));
    RBFieldNo->setChecked(true);

    gridLayout_7->addWidget(RBFieldNo, 0, 0, 1, 1);

    RBFieldAll = new QRadioButton(GBField);
    RBFieldAll->setObjectName(QString::fromUtf8("RBFieldAll"));
    RBFieldAll->setChecked(false);

    gridLayout_7->addWidget(RBFieldAll, 0, 1, 1, 1);

    RBFieldChosen = new QRadioButton(GBField);
    RBFieldChosen->setObjectName(QString::fromUtf8("RBFieldChosen"));
    RBFieldChosen->setChecked(false);

    gridLayout_7->addWidget(RBFieldChosen, 0, 2, 1, 1);


    gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);

    TWField = new QTableWidget(GBField);
    if (TWField->columnCount() < 2)
        TWField->setColumnCount(2);
    QTableWidgetItem *__colItem4 = new QTableWidgetItem();
    TWField->setHorizontalHeaderItem(0, __colItem4);
    QTableWidgetItem *__colItem5 = new QTableWidgetItem();
    TWField->setHorizontalHeaderItem(1, __colItem5);
    TWField->setObjectName(QString::fromUtf8("TWField"));

    gridLayout_8->addWidget(TWField, 1, 0, 1, 1);


    gridLayout_10->addWidget(GBField, 6, 0, 1, 2);

    CBGroupe = new QCheckBox(CreateHypothesis);
    CBGroupe->setObjectName(QString::fromUtf8("CBGroupe"));

    gridLayout_10->addWidget(CBGroupe, 7, 0, 1, 2);

    GBButtons = new QGroupBox(CreateHypothesis);
    GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
    gridLayout_5 = new QGridLayout(GBButtons);
    gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
    buttonOk = new QPushButton(GBButtons);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

    gridLayout_5->addWidget(buttonOk, 0, 0, 1, 1);

    buttonApply = new QPushButton(GBButtons);
    buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

    gridLayout_5->addWidget(buttonApply, 0, 1, 1, 1);

    buttonCancel = new QPushButton(GBButtons);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

    gridLayout_5->addWidget(buttonCancel, 0, 2, 1, 1);

    buttonHelp = new QPushButton(GBButtons);
    buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

    gridLayout_5->addWidget(buttonHelp, 0, 3, 1, 1);


    gridLayout_10->addWidget(GBButtons, 8, 0, 1, 2);


    retranslateUi(CreateHypothesis);

    QMetaObject::connectSlotsByName(CreateHypothesis);
    } // setupUi

    void retranslateUi(QDialog *CreateHypothesis)
    {
    CreateHypothesis->setWindowTitle(QApplication::translate("CreateHypothesis", "Create Hypothesis", 0, QApplication::UnicodeUTF8));
    Name->setText(QApplication::translate("CreateHypothesis", "Name", 0, QApplication::UnicodeUTF8));
    GBTypeAdaptation->setTitle(QApplication::translate("CreateHypothesis", "Type of adaptation", 0, QApplication::UnicodeUTF8));
    RBUniforme->setText(QApplication::translate("CreateHypothesis", "Uniform", 0, QApplication::UnicodeUTF8));
    RBChamp->setText(QApplication::translate("CreateHypothesis", "Following a field", 0, QApplication::UnicodeUTF8));
    RBZone->setText(QApplication::translate("CreateHypothesis", "With geometrical zones", 0, QApplication::UnicodeUTF8));
    GBUniform->setTitle(QApplication::translate("CreateHypothesis", "Uniform adaptation", 0, QApplication::UnicodeUTF8));
    RBUniDera->setText(QApplication::translate("CreateHypothesis", "Coarsening", 0, QApplication::UnicodeUTF8));
    RBUniRaff->setText(QApplication::translate("CreateHypothesis", "Refinement", 0, QApplication::UnicodeUTF8));
    GBFieldFile->setTitle(QString());
    FieldFile->setText(QApplication::translate("CreateHypothesis", "File of the fields", 0, QApplication::UnicodeUTF8));
    GBFieldManagement->setTitle(QApplication::translate("CreateHypothesis", "Governing field for the adaptation", 0, QApplication::UnicodeUTF8));
    FieldName->setText(QApplication::translate("CreateHypothesis", "Field Name", 0, QApplication::UnicodeUTF8));
    TWCMP->horizontalHeaderItem(0)->setText(QApplication::translate("CreateHypothesis", "Selection", 0, QApplication::UnicodeUTF8));
    TWCMP->horizontalHeaderItem(1)->setText(QApplication::translate("CreateHypothesis", "Component", 0, QApplication::UnicodeUTF8));
    RBL2->setText(QApplication::translate("CreateHypothesis", "L2 norm", 0, QApplication::UnicodeUTF8));
    RBInf->setText(QApplication::translate("CreateHypothesis", "Infinite norm", 0, QApplication::UnicodeUTF8));
    GBRefinementThresholds->setTitle(QApplication::translate("CreateHypothesis", "Refinement thresholds", 0, QApplication::UnicodeUTF8));
    RBRPE->setText(QApplication::translate("CreateHypothesis", "Percentage of meshes", 0, QApplication::UnicodeUTF8));
    SpinBox_RPE->setSuffix(QApplication::translate("CreateHypothesis", " %", 0, QApplication::UnicodeUTF8));
    RBRRel->setText(QApplication::translate("CreateHypothesis", "Relative", 0, QApplication::UnicodeUTF8));
    SpinBox_RRel->setSuffix(QApplication::translate("CreateHypothesis", " %", 0, QApplication::UnicodeUTF8));
    RBRAbs->setText(QApplication::translate("CreateHypothesis", "Absolute", 0, QApplication::UnicodeUTF8));
    RBRNo->setText(QApplication::translate("CreateHypothesis", "No refinement", 0, QApplication::UnicodeUTF8));
    GBCoarseningThresholds->setTitle(QApplication::translate("CreateHypothesis", "Coarsening thresholds", 0, QApplication::UnicodeUTF8));
    RBCPE->setText(QApplication::translate("CreateHypothesis", "Percentage of meshes", 0, QApplication::UnicodeUTF8));
    SpinBox_CPE->setSuffix(QApplication::translate("CreateHypothesis", " %", 0, QApplication::UnicodeUTF8));
    RBCRel->setText(QApplication::translate("CreateHypothesis", "Relative", 0, QApplication::UnicodeUTF8));
    SpinBox_CRel->setSuffix(QApplication::translate("CreateHypothesis", " %", 0, QApplication::UnicodeUTF8));
    RBCAbs->setText(QApplication::translate("CreateHypothesis", "Absolute", 0, QApplication::UnicodeUTF8));
    RBCNo->setText(QApplication::translate("CreateHypothesis", "No coarsening", 0, QApplication::UnicodeUTF8));
    GBAreaManagement->setTitle(QApplication::translate("CreateHypothesis", "Area management", 0, QApplication::UnicodeUTF8));
    TWZone->horizontalHeaderItem(0)->setText(QApplication::translate("CreateHypothesis", "Selection", 0, QApplication::UnicodeUTF8));
    TWZone->horizontalHeaderItem(1)->setText(QApplication::translate("CreateHypothesis", "Zone name", 0, QApplication::UnicodeUTF8));
    PBZoneNew->setText(QApplication::translate("CreateHypothesis", "New", 0, QApplication::UnicodeUTF8));
    PBZoneEdit->setText(QApplication::translate("CreateHypothesis", "Edit", 0, QApplication::UnicodeUTF8));
    PBZoneDelete->setText(QString());
    GBField->setTitle(QApplication::translate("CreateHypothesis", "Field Interpolation", 0, QApplication::UnicodeUTF8));
    RBFieldNo->setText(QApplication::translate("CreateHypothesis", "None", 0, QApplication::UnicodeUTF8));
    RBFieldAll->setText(QApplication::translate("CreateHypothesis", "All", 0, QApplication::UnicodeUTF8));
    RBFieldChosen->setText(QApplication::translate("CreateHypothesis", "Chosen", 0, QApplication::UnicodeUTF8));
    TWField->horizontalHeaderItem(0)->setText(QApplication::translate("CreateHypothesis", "Selection", 0, QApplication::UnicodeUTF8));
    TWField->horizontalHeaderItem(1)->setText(QApplication::translate("CreateHypothesis", "Field Name", 0, QApplication::UnicodeUTF8));
    CBGroupe->setText(QApplication::translate("CreateHypothesis", "Filtering with groups", 0, QApplication::UnicodeUTF8));
    GBButtons->setTitle(QString());
    buttonOk->setText(QApplication::translate("CreateHypothesis", "&Ok", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateHypothesis", "&Apply", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateHypothesis", "&Cancel", 0, QApplication::UnicodeUTF8));
    buttonHelp->setText(QApplication::translate("CreateHypothesis", "&Help", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CreateHypothesis);
    } // retranslateUi

};

namespace Ui {
    class CreateHypothesis: public Ui_CreateHypothesis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEHYPOTHESIS_H
