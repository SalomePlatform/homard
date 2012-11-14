/********************************************************************************
** Form generated from reading UI file 'CreateHypothesis.ui'
**
** Created: Wed Nov 14 11:07:43 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateHypothesis
{
public:
    QGridLayout *gridLayout_3;
    QLineEdit *LEHypothesisName;
    QGroupBox *GBTypeAdaptation;
    QHBoxLayout *hboxLayout;
    QRadioButton *RBUniforme;
    QRadioButton *RBChamp;
    QRadioButton *RBZone;
    QCheckBox *CBGroupe;
    QGroupBox *GBUniform;
    QGridLayout *gridLayout;
    QRadioButton *RBUniDera;
    QRadioButton *RBUniRaff;
    QGroupBox *GBFieldFile;
    QGridLayout *gridLayout1;
    QLabel *FieldFile;
    QLineEdit *LEFieldFile;
    QGroupBox *GBFieldManagement;
    QGridLayout *gridLayout2;
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
    QGridLayout *gridLayout3;
    QRadioButton *RBRPE;
    QDoubleSpinBox *SpinBox_RPE;
    QRadioButton *RBRRel;
    QDoubleSpinBox *SpinBox_RRel;
    QRadioButton *RBRAbs;
    QDoubleSpinBox *SpinBox_RAbs;
    QRadioButton *RBRNo;
    QGroupBox *GBCoarseningThresholds;
    QGridLayout *gridLayout4;
    QRadioButton *RBCPE;
    QDoubleSpinBox *SpinBox_CPE;
    QRadioButton *RBCRel;
    QDoubleSpinBox *SpinBox_CRel;
    QRadioButton *RBCAbs;
    QDoubleSpinBox *SpinBox_CAbs;
    QRadioButton *RBCNo;
    QGroupBox *GBAreaManagement;
    QGridLayout *gridLayout_4;
    QTableWidget *TWZone;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *vboxLayout1;
    QVBoxLayout *vboxLayout2;
    QPushButton *PBZoneNew;
    QPushButton *PBZoneEdit;
    QPushButton *PBZoneDelete;
    QSpacerItem *spacerItem2;
    QGroupBox *GBField;
    QGridLayout *gridLayout5;
    QGridLayout *gridLayout6;
    QRadioButton *RBFieldNo;
    QRadioButton *RBFieldAll;
    QRadioButton *RBFieldChosen;
    QTableWidget *TWField;
    QCheckBox *CBAdvanced;
    QGroupBox *GBAdvancedOptions;
    QGridLayout *gridLayout_1;
    QLabel *TLMinimalDiameter;
    QDoubleSpinBox *doubleSpinBoxDiamMin;
    QLabel *TLMaximalLevel;
    QSpinBox *spinBoxNivMax;
    QGroupBox *GBAdapInit;
    QGridLayout *gridLayout_2;
    QRadioButton *RBAIN;
    QRadioButton *RBAIR;
    QRadioButton *RBAID;
    QCheckBox *CBLevelOutput;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout7;
    QPushButton *buttonOk;
    QPushButton *buttonApply;
    QPushButton *buttonCancel;
    QPushButton *buttonHelp;
    QLabel *Name;

    void setupUi(QDialog *CreateHypothesis)
    {
        if (CreateHypothesis->objectName().isEmpty())
            CreateHypothesis->setObjectName(QString::fromUtf8("CreateHypothesis"));
        CreateHypothesis->resize(770, 1453);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateHypothesis->sizePolicy().hasHeightForWidth());
        CreateHypothesis->setSizePolicy(sizePolicy);
        CreateHypothesis->setAutoFillBackground(true);
        CreateHypothesis->setSizeGripEnabled(true);
        gridLayout_3 = new QGridLayout(CreateHypothesis);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        LEHypothesisName = new QLineEdit(CreateHypothesis);
        LEHypothesisName->setObjectName(QString::fromUtf8("LEHypothesisName"));
        LEHypothesisName->setMinimumSize(QSize(382, 31));
        LEHypothesisName->setMaxLength(32);

        gridLayout_3->addWidget(LEHypothesisName, 0, 1, 1, 1);

        GBTypeAdaptation = new QGroupBox(CreateHypothesis);
        GBTypeAdaptation->setObjectName(QString::fromUtf8("GBTypeAdaptation"));
        hboxLayout = new QHBoxLayout(GBTypeAdaptation);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
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


        gridLayout_3->addWidget(GBTypeAdaptation, 1, 0, 1, 2);

        CBGroupe = new QCheckBox(CreateHypothesis);
        CBGroupe->setObjectName(QString::fromUtf8("CBGroupe"));

        gridLayout_3->addWidget(CBGroupe, 2, 0, 1, 2);

        GBUniform = new QGroupBox(CreateHypothesis);
        GBUniform->setObjectName(QString::fromUtf8("GBUniform"));
        gridLayout = new QGridLayout(GBUniform);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RBUniDera = new QRadioButton(GBUniform);
        RBUniDera->setObjectName(QString::fromUtf8("RBUniDera"));

        gridLayout->addWidget(RBUniDera, 0, 1, 1, 1);

        RBUniRaff = new QRadioButton(GBUniform);
        RBUniRaff->setObjectName(QString::fromUtf8("RBUniRaff"));
        RBUniRaff->setChecked(true);

        gridLayout->addWidget(RBUniRaff, 0, 0, 1, 1);


        gridLayout_3->addWidget(GBUniform, 3, 0, 1, 2);

        GBFieldFile = new QGroupBox(CreateHypothesis);
        GBFieldFile->setObjectName(QString::fromUtf8("GBFieldFile"));
        gridLayout1 = new QGridLayout(GBFieldFile);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        FieldFile = new QLabel(GBFieldFile);
        FieldFile->setObjectName(QString::fromUtf8("FieldFile"));

        gridLayout1->addWidget(FieldFile, 0, 0, 1, 1);

        LEFieldFile = new QLineEdit(GBFieldFile);
        LEFieldFile->setObjectName(QString::fromUtf8("LEFieldFile"));
        LEFieldFile->setMinimumSize(QSize(282, 31));

        gridLayout1->addWidget(LEFieldFile, 0, 1, 1, 1);


        gridLayout_3->addWidget(GBFieldFile, 4, 0, 1, 2);

        GBFieldManagement = new QGroupBox(CreateHypothesis);
        GBFieldManagement->setObjectName(QString::fromUtf8("GBFieldManagement"));
        sizePolicy.setHeightForWidth(GBFieldManagement->sizePolicy().hasHeightForWidth());
        GBFieldManagement->setSizePolicy(sizePolicy);
        gridLayout2 = new QGridLayout(GBFieldManagement);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        FieldName = new QLabel(GBFieldManagement);
        FieldName->setObjectName(QString::fromUtf8("FieldName"));

        hboxLayout1->addWidget(FieldName);

        CBFieldName = new QComboBox(GBFieldManagement);
        CBFieldName->setObjectName(QString::fromUtf8("CBFieldName"));
        sizePolicy.setHeightForWidth(CBFieldName->sizePolicy().hasHeightForWidth());
        CBFieldName->setSizePolicy(sizePolicy);
        CBFieldName->setEditable(false);
        CBFieldName->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        hboxLayout1->addWidget(CBFieldName);

        spacerItem = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);


        gridLayout2->addLayout(hboxLayout1, 0, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        TWCMP = new QTableWidget(GBFieldManagement);
        if (TWCMP->columnCount() < 2)
            TWCMP->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TWCMP->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TWCMP->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        TWCMP->setObjectName(QString::fromUtf8("TWCMP"));
        TWCMP->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        TWCMP->setShowGrid(true);
        TWCMP->setRowCount(0);
        TWCMP->setColumnCount(2);

        hboxLayout2->addWidget(TWCMP);

        spacerItem1 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem1);

        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
#endif
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


        gridLayout2->addLayout(hboxLayout2, 1, 0, 1, 1);

        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        GBRefinementThresholds = new QGroupBox(GBFieldManagement);
        GBRefinementThresholds->setObjectName(QString::fromUtf8("GBRefinementThresholds"));
        sizePolicy.setHeightForWidth(GBRefinementThresholds->sizePolicy().hasHeightForWidth());
        GBRefinementThresholds->setSizePolicy(sizePolicy);
        gridLayout3 = new QGridLayout(GBRefinementThresholds);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        RBRPE = new QRadioButton(GBRefinementThresholds);
        RBRPE->setObjectName(QString::fromUtf8("RBRPE"));
        RBRPE->setCheckable(true);
        RBRPE->setChecked(true);

        gridLayout3->addWidget(RBRPE, 0, 0, 1, 1);

        SpinBox_RPE = new QDoubleSpinBox(GBRefinementThresholds);
        SpinBox_RPE->setObjectName(QString::fromUtf8("SpinBox_RPE"));
        SpinBox_RPE->setDecimals(3);
        SpinBox_RPE->setMaximum(100);
        SpinBox_RPE->setSingleStep(0.1);
        SpinBox_RPE->setValue(2);

        gridLayout3->addWidget(SpinBox_RPE, 0, 1, 1, 1);

        RBRRel = new QRadioButton(GBRefinementThresholds);
        RBRRel->setObjectName(QString::fromUtf8("RBRRel"));

        gridLayout3->addWidget(RBRRel, 1, 0, 1, 1);

        SpinBox_RRel = new QDoubleSpinBox(GBRefinementThresholds);
        SpinBox_RRel->setObjectName(QString::fromUtf8("SpinBox_RRel"));
        SpinBox_RRel->setEnabled(false);
        SpinBox_RRel->setDecimals(3);
        SpinBox_RRel->setMaximum(100);
        SpinBox_RRel->setSingleStep(0.1);

        gridLayout3->addWidget(SpinBox_RRel, 1, 1, 1, 1);

        RBRAbs = new QRadioButton(GBRefinementThresholds);
        RBRAbs->setObjectName(QString::fromUtf8("RBRAbs"));

        gridLayout3->addWidget(RBRAbs, 2, 0, 1, 1);

        SpinBox_RAbs = new QDoubleSpinBox(GBRefinementThresholds);
        SpinBox_RAbs->setObjectName(QString::fromUtf8("SpinBox_RAbs"));
        SpinBox_RAbs->setEnabled(false);
        SpinBox_RAbs->setDecimals(8);
        SpinBox_RAbs->setMinimum(-1e+12);
        SpinBox_RAbs->setMaximum(1e+12);
        SpinBox_RAbs->setSingleStep(0.1);

        gridLayout3->addWidget(SpinBox_RAbs, 2, 1, 1, 1);

        RBRNo = new QRadioButton(GBRefinementThresholds);
        RBRNo->setObjectName(QString::fromUtf8("RBRNo"));

        gridLayout3->addWidget(RBRNo, 3, 0, 1, 1);


        hboxLayout4->addWidget(GBRefinementThresholds);

        GBCoarseningThresholds = new QGroupBox(GBFieldManagement);
        GBCoarseningThresholds->setObjectName(QString::fromUtf8("GBCoarseningThresholds"));
        gridLayout4 = new QGridLayout(GBCoarseningThresholds);
#ifndef Q_OS_MAC
        gridLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout4->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        RBCPE = new QRadioButton(GBCoarseningThresholds);
        RBCPE->setObjectName(QString::fromUtf8("RBCPE"));
        RBCPE->setCheckable(true);
        RBCPE->setChecked(false);

        gridLayout4->addWidget(RBCPE, 0, 0, 1, 1);

        SpinBox_CPE = new QDoubleSpinBox(GBCoarseningThresholds);
        SpinBox_CPE->setObjectName(QString::fromUtf8("SpinBox_CPE"));
        SpinBox_CPE->setEnabled(false);
        SpinBox_CPE->setDecimals(3);
        SpinBox_CPE->setMaximum(100);
        SpinBox_CPE->setSingleStep(0.1);

        gridLayout4->addWidget(SpinBox_CPE, 0, 1, 1, 1);

        RBCRel = new QRadioButton(GBCoarseningThresholds);
        RBCRel->setObjectName(QString::fromUtf8("RBCRel"));

        gridLayout4->addWidget(RBCRel, 1, 0, 1, 1);

        SpinBox_CRel = new QDoubleSpinBox(GBCoarseningThresholds);
        SpinBox_CRel->setObjectName(QString::fromUtf8("SpinBox_CRel"));
        SpinBox_CRel->setEnabled(false);
        SpinBox_CRel->setDecimals(3);
        SpinBox_CRel->setMaximum(100);
        SpinBox_CRel->setSingleStep(0.1);

        gridLayout4->addWidget(SpinBox_CRel, 1, 1, 1, 1);

        RBCAbs = new QRadioButton(GBCoarseningThresholds);
        RBCAbs->setObjectName(QString::fromUtf8("RBCAbs"));

        gridLayout4->addWidget(RBCAbs, 2, 0, 1, 1);

        SpinBox_CAbs = new QDoubleSpinBox(GBCoarseningThresholds);
        SpinBox_CAbs->setObjectName(QString::fromUtf8("SpinBox_CAbs"));
        SpinBox_CAbs->setEnabled(false);
        SpinBox_CAbs->setDecimals(8);
        SpinBox_CAbs->setMinimum(-1e+12);
        SpinBox_CAbs->setMaximum(1e+12);
        SpinBox_CAbs->setSingleStep(0.1);

        gridLayout4->addWidget(SpinBox_CAbs, 2, 1, 1, 1);

        RBCNo = new QRadioButton(GBCoarseningThresholds);
        RBCNo->setObjectName(QString::fromUtf8("RBCNo"));
        RBCNo->setChecked(true);

        gridLayout4->addWidget(RBCNo, 3, 0, 1, 1);


        hboxLayout4->addWidget(GBCoarseningThresholds);


        gridLayout2->addLayout(hboxLayout4, 2, 0, 1, 1);


        gridLayout_3->addWidget(GBFieldManagement, 5, 0, 1, 2);

        GBAreaManagement = new QGroupBox(CreateHypothesis);
        GBAreaManagement->setObjectName(QString::fromUtf8("GBAreaManagement"));
        sizePolicy.setHeightForWidth(GBAreaManagement->sizePolicy().hasHeightForWidth());
        GBAreaManagement->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(GBAreaManagement);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        TWZone = new QTableWidget(GBAreaManagement);
        if (TWZone->columnCount() < 3)
            TWZone->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TWZone->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TWZone->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TWZone->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        TWZone->setObjectName(QString::fromUtf8("TWZone"));
        TWZone->setMinimumSize(QSize(400, 0));
        TWZone->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        TWZone->setShowGrid(true);
        TWZone->setRowCount(0);
        TWZone->setColumnCount(3);

        gridLayout_4->addWidget(TWZone, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 1, 1, 1);

        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
#endif
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


        gridLayout_4->addLayout(vboxLayout1, 0, 2, 1, 1);


        gridLayout_3->addWidget(GBAreaManagement, 6, 0, 1, 2);

        GBField = new QGroupBox(CreateHypothesis);
        GBField->setObjectName(QString::fromUtf8("GBField"));
        gridLayout5 = new QGridLayout(GBField);
#ifndef Q_OS_MAC
        gridLayout5->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout5->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        gridLayout6 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout6->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout6->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
        RBFieldNo = new QRadioButton(GBField);
        RBFieldNo->setObjectName(QString::fromUtf8("RBFieldNo"));
        RBFieldNo->setChecked(true);

        gridLayout6->addWidget(RBFieldNo, 0, 0, 1, 1);

        RBFieldAll = new QRadioButton(GBField);
        RBFieldAll->setObjectName(QString::fromUtf8("RBFieldAll"));
        RBFieldAll->setChecked(false);

        gridLayout6->addWidget(RBFieldAll, 0, 1, 1, 1);

        RBFieldChosen = new QRadioButton(GBField);
        RBFieldChosen->setObjectName(QString::fromUtf8("RBFieldChosen"));
        RBFieldChosen->setChecked(false);

        gridLayout6->addWidget(RBFieldChosen, 0, 2, 1, 1);


        gridLayout5->addLayout(gridLayout6, 0, 0, 1, 1);

        TWField = new QTableWidget(GBField);
        if (TWField->columnCount() < 2)
            TWField->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TWField->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        TWField->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        TWField->setObjectName(QString::fromUtf8("TWField"));

        gridLayout5->addWidget(TWField, 1, 0, 1, 1);


        gridLayout_3->addWidget(GBField, 7, 0, 1, 2);

        CBAdvanced = new QCheckBox(CreateHypothesis);
        CBAdvanced->setObjectName(QString::fromUtf8("CBAdvanced"));

        gridLayout_3->addWidget(CBAdvanced, 8, 0, 1, 2);

        GBAdvancedOptions = new QGroupBox(CreateHypothesis);
        GBAdvancedOptions->setObjectName(QString::fromUtf8("GBAdvancedOptions"));
        gridLayout_1 = new QGridLayout(GBAdvancedOptions);
        gridLayout_1->setObjectName(QString::fromUtf8("gridLayout_1"));
        TLMinimalDiameter = new QLabel(GBAdvancedOptions);
        TLMinimalDiameter->setObjectName(QString::fromUtf8("TLMinimalDiameter"));
        sizePolicy.setHeightForWidth(TLMinimalDiameter->sizePolicy().hasHeightForWidth());
        TLMinimalDiameter->setSizePolicy(sizePolicy);
        TLMinimalDiameter->setWordWrap(false);

        gridLayout_1->addWidget(TLMinimalDiameter, 0, 0, 1, 1);

        doubleSpinBoxDiamMin = new QDoubleSpinBox(GBAdvancedOptions);
        doubleSpinBoxDiamMin->setObjectName(QString::fromUtf8("doubleSpinBoxDiamMin"));
        doubleSpinBoxDiamMin->setDecimals(5);

        gridLayout_1->addWidget(doubleSpinBoxDiamMin, 0, 1, 1, 1);

        TLMaximalLevel = new QLabel(GBAdvancedOptions);
        TLMaximalLevel->setObjectName(QString::fromUtf8("TLMaximalLevel"));
        sizePolicy.setHeightForWidth(TLMaximalLevel->sizePolicy().hasHeightForWidth());
        TLMaximalLevel->setSizePolicy(sizePolicy);
        TLMaximalLevel->setWordWrap(false);

        gridLayout_1->addWidget(TLMaximalLevel, 1, 0, 1, 1);

        spinBoxNivMax = new QSpinBox(GBAdvancedOptions);
        spinBoxNivMax->setObjectName(QString::fromUtf8("spinBoxNivMax"));
        spinBoxNivMax->setValue(99);

        gridLayout_1->addWidget(spinBoxNivMax, 1, 1, 1, 1);

        GBAdapInit = new QGroupBox(GBAdvancedOptions);
        GBAdapInit->setObjectName(QString::fromUtf8("GBAdapInit"));
        gridLayout_2 = new QGridLayout(GBAdapInit);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        RBAIN = new QRadioButton(GBAdapInit);
        RBAIN->setObjectName(QString::fromUtf8("RBAIN"));
        RBAIN->setChecked(true);

        gridLayout_2->addWidget(RBAIN, 0, 0, 1, 1);

        RBAIR = new QRadioButton(GBAdapInit);
        RBAIR->setObjectName(QString::fromUtf8("RBAIR"));

        gridLayout_2->addWidget(RBAIR, 0, 1, 1, 1);

        RBAID = new QRadioButton(GBAdapInit);
        RBAID->setObjectName(QString::fromUtf8("RBAID"));

        gridLayout_2->addWidget(RBAID, 0, 2, 1, 1);


        gridLayout_1->addWidget(GBAdapInit, 2, 0, 1, 2);

        CBLevelOutput = new QCheckBox(GBAdvancedOptions);
        CBLevelOutput->setObjectName(QString::fromUtf8("CBLevelOutput"));

        gridLayout_1->addWidget(CBLevelOutput, 3, 0, 1, 1);


        gridLayout_3->addWidget(GBAdvancedOptions, 9, 0, 1, 2);

        GBButtons = new QGroupBox(CreateHypothesis);
        GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
        gridLayout7 = new QGridLayout(GBButtons);
#ifndef Q_OS_MAC
        gridLayout7->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout7->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
        buttonOk = new QPushButton(GBButtons);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

        gridLayout7->addWidget(buttonOk, 0, 0, 1, 1);

        buttonApply = new QPushButton(GBButtons);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

        gridLayout7->addWidget(buttonApply, 0, 1, 1, 1);

        buttonCancel = new QPushButton(GBButtons);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        gridLayout7->addWidget(buttonCancel, 0, 2, 1, 1);

        buttonHelp = new QPushButton(GBButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

        gridLayout7->addWidget(buttonHelp, 0, 3, 1, 1);


        gridLayout_3->addWidget(GBButtons, 10, 0, 1, 2);

        Name = new QLabel(CreateHypothesis);
        Name->setObjectName(QString::fromUtf8("Name"));

        gridLayout_3->addWidget(Name, 0, 0, 1, 1);

        LEHypothesisName->raise();
        GBTypeAdaptation->raise();
        GBUniform->raise();
        GBFieldFile->raise();
        GBFieldManagement->raise();
        GBAreaManagement->raise();
        GBField->raise();
        CBGroupe->raise();
        CBAdvanced->raise();
        GBAdvancedOptions->raise();
        GBButtons->raise();
        Name->raise();

        retranslateUi(CreateHypothesis);

        QMetaObject::connectSlotsByName(CreateHypothesis);
    } // setupUi

    void retranslateUi(QDialog *CreateHypothesis)
    {
        CreateHypothesis->setWindowTitle(QApplication::translate("CreateHypothesis", "Create an hypothesis", 0, QApplication::UnicodeUTF8));
        GBTypeAdaptation->setTitle(QApplication::translate("CreateHypothesis", "Type of adaptation", 0, QApplication::UnicodeUTF8));
        RBUniforme->setText(QApplication::translate("CreateHypothesis", "Uniform", 0, QApplication::UnicodeUTF8));
        RBChamp->setText(QApplication::translate("CreateHypothesis", "Driven by a field", 0, QApplication::UnicodeUTF8));
        RBZone->setText(QApplication::translate("CreateHypothesis", "With geometrical zones", 0, QApplication::UnicodeUTF8));
        CBGroupe->setText(QApplication::translate("CreateHypothesis", "Filtering with groups", 0, QApplication::UnicodeUTF8));
        GBUniform->setTitle(QApplication::translate("CreateHypothesis", "Uniform adaptation", 0, QApplication::UnicodeUTF8));
        RBUniDera->setText(QApplication::translate("CreateHypothesis", "Coarsening", 0, QApplication::UnicodeUTF8));
        RBUniRaff->setText(QApplication::translate("CreateHypothesis", "Refinement", 0, QApplication::UnicodeUTF8));
        GBFieldFile->setTitle(QString());
        FieldFile->setText(QApplication::translate("CreateHypothesis", "File of the fields", 0, QApplication::UnicodeUTF8));
        GBFieldManagement->setTitle(QApplication::translate("CreateHypothesis", "Governing field for the adaptation", 0, QApplication::UnicodeUTF8));
        FieldName->setText(QApplication::translate("CreateHypothesis", "Field name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = TWCMP->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CreateHypothesis", "Selection", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = TWCMP->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CreateHypothesis", "Component", 0, QApplication::UnicodeUTF8));
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
        QTableWidgetItem *___qtablewidgetitem2 = TWZone->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("CreateHypothesis", "Refinement", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = TWZone->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("CreateHypothesis", "Coarsening", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = TWZone->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("CreateHypothesis", "Zone name", 0, QApplication::UnicodeUTF8));
        PBZoneNew->setText(QApplication::translate("CreateHypothesis", "New", 0, QApplication::UnicodeUTF8));
        PBZoneEdit->setText(QApplication::translate("CreateHypothesis", "Edit", 0, QApplication::UnicodeUTF8));
        PBZoneDelete->setText(QString());
        GBField->setTitle(QApplication::translate("CreateHypothesis", "Field Interpolation", 0, QApplication::UnicodeUTF8));
        RBFieldNo->setText(QApplication::translate("CreateHypothesis", "None", 0, QApplication::UnicodeUTF8));
        RBFieldAll->setText(QApplication::translate("CreateHypothesis", "All", 0, QApplication::UnicodeUTF8));
        RBFieldChosen->setText(QApplication::translate("CreateHypothesis", "Chosen", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = TWField->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("CreateHypothesis", "Selection", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = TWField->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("CreateHypothesis", "Field Name", 0, QApplication::UnicodeUTF8));
        CBAdvanced->setText(QApplication::translate("CreateHypothesis", "Advanced options", 0, QApplication::UnicodeUTF8));
        GBAdvancedOptions->setTitle(QApplication::translate("CreateHypothesis", "Advanced options", 0, QApplication::UnicodeUTF8));
        TLMinimalDiameter->setText(QApplication::translate("CreateHypothesis", "Minimal diameter", 0, QApplication::UnicodeUTF8));
        TLMaximalLevel->setText(QApplication::translate("CreateHypothesis", "Maximal level", 0, QApplication::UnicodeUTF8));
        GBAdapInit->setTitle(QApplication::translate("CreateHypothesis", "Initialization of adaptation", 0, QApplication::UnicodeUTF8));
        RBAIN->setText(QApplication::translate("CreateHypothesis", "Nothing", 0, QApplication::UnicodeUTF8));
        RBAIR->setText(QApplication::translate("CreateHypothesis", "Refinement", 0, QApplication::UnicodeUTF8));
        RBAID->setText(QApplication::translate("CreateHypothesis", "Coarsening", 0, QApplication::UnicodeUTF8));
        CBLevelOutput->setText(QApplication::translate("CreateHypothesis", "Output of the level of refinement", 0, QApplication::UnicodeUTF8));
        GBButtons->setTitle(QString());
        buttonOk->setText(QApplication::translate("CreateHypothesis", "OK", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("CreateHypothesis", "Apply", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CreateHypothesis", "Cancel", 0, QApplication::UnicodeUTF8));
        buttonHelp->setText(QApplication::translate("CreateHypothesis", "Help", 0, QApplication::UnicodeUTF8));
        Name->setText(QApplication::translate("CreateHypothesis", "Name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateHypothesis: public Ui_CreateHypothesis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEHYPOTHESIS_H
