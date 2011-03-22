/********************************************************************************
** Form generated from reading ui file 'CreateCase.ui'
**
** Created: Mon Jan 31 13:48:20 2011
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
#include <QtGui/QWidget>

class Ui_CreateCase
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonOk;
    QPushButton *buttonApply;
    QPushButton *buttonCancel;
    QPushButton *buttonHelp;
    QGroupBox *GBBoundaryA;
    QWidget *layoutWidget;
    QVBoxLayout *vboxLayout;
    QPushButton *PBBoundaryAnNew;
    QPushButton *PBBoundaryAnHelp;
    QTableWidget *TWBoundary;
    QHBoxLayout *hboxLayout;
    QLabel *Name;
    QLineEdit *LECaseName;
    QHBoxLayout *hboxLayout1;
    QLabel *Directory;
    QPushButton *PushDir;
    QLineEdit *LEDirName;
    QHBoxLayout *hboxLayout2;
    QLabel *Mesh_2;
    QPushButton *PushFichier;
    QLineEdit *LEFileName;
    QSpacerItem *spacerItem;
    QGroupBox *GBTypeConf;
    QHBoxLayout *hboxLayout3;
    QRadioButton *RBConforme;
    QRadioButton *RBNonConforme;
    QSpacerItem *spacerItem1;
    QGroupBox *GBTypeNoConf;
    QHBoxLayout *hboxLayout4;
    QRadioButton *RB1NpM;
    QRadioButton *RB1NpA;
    QRadioButton *RBQuelconque;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout5;
    QCheckBox *CBBoundaryD;
    QCheckBox *CBBoundaryA;
    QSpacerItem *spacerItem3;
    QSpacerItem *spacerItem4;
    QGroupBox *GBBoundaryD;
    QGridLayout *gridLayout2;
    QPushButton *PBBoundaryDiHelp;
    QPushButton *PBBoundaryDiNew;
    QPushButton *PBBoundaryDiEdit;
    QSpacerItem *spacerItem5;
    QComboBox *CBBoundaryDi;

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
    GroupButtons = new QGroupBox(CreateCase);
    GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
    gridLayout1 = new QGridLayout(GroupButtons);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    buttonOk = new QPushButton(GroupButtons);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
    buttonOk->setAutoDefault(false);

    gridLayout1->addWidget(buttonOk, 0, 0, 1, 1);

    buttonApply = new QPushButton(GroupButtons);
    buttonApply->setObjectName(QString::fromUtf8("buttonApply"));
    buttonApply->setAutoDefault(false);

    gridLayout1->addWidget(buttonApply, 0, 1, 1, 1);

    buttonCancel = new QPushButton(GroupButtons);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
    buttonCancel->setAutoDefault(false);

    gridLayout1->addWidget(buttonCancel, 0, 2, 1, 1);

    buttonHelp = new QPushButton(GroupButtons);
    buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
    buttonHelp->setAutoDefault(false);

    gridLayout1->addWidget(buttonHelp, 0, 3, 1, 1);


    gridLayout->addWidget(GroupButtons, 13, 0, 1, 2);

    GBBoundaryA = new QGroupBox(CreateCase);
    GBBoundaryA->setObjectName(QString::fromUtf8("GBBoundaryA"));
    GBBoundaryA->setMinimumSize(QSize(548, 300));
    layoutWidget = new QWidget(GBBoundaryA);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(410, 20, 120, 110));
    vboxLayout = new QVBoxLayout(layoutWidget);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    PBBoundaryAnNew = new QPushButton(layoutWidget);
    PBBoundaryAnNew->setObjectName(QString::fromUtf8("PBBoundaryAnNew"));
    PBBoundaryAnNew->setAutoDefault(false);

    vboxLayout->addWidget(PBBoundaryAnNew);

    PBBoundaryAnHelp = new QPushButton(layoutWidget);
    PBBoundaryAnHelp->setObjectName(QString::fromUtf8("PBBoundaryAnHelp"));
    PBBoundaryAnHelp->setAutoDefault(false);

    vboxLayout->addWidget(PBBoundaryAnHelp);

    TWBoundary = new QTableWidget(GBBoundaryA);
    TWBoundary->setObjectName(QString::fromUtf8("TWBoundary"));
    TWBoundary->setGeometry(QRect(4, 20, 371, 270));
    TWBoundary->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::NoEditTriggers|QAbstractItemView::SelectedClicked);
    TWBoundary->setShowGrid(true);
    TWBoundary->setRowCount(0);
    TWBoundary->setColumnCount(1);

    gridLayout->addWidget(GBBoundaryA, 12, 0, 1, 2);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    Name = new QLabel(CreateCase);
    Name->setObjectName(QString::fromUtf8("Name"));

    hboxLayout->addWidget(Name);

    LECaseName = new QLineEdit(CreateCase);
    LECaseName->setObjectName(QString::fromUtf8("LECaseName"));
    LECaseName->setMinimumSize(QSize(382, 21));

    hboxLayout->addWidget(LECaseName);


    gridLayout->addLayout(hboxLayout, 0, 0, 1, 2);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
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


    gridLayout->addLayout(hboxLayout1, 1, 0, 1, 1);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
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


    gridLayout->addLayout(hboxLayout2, 3, 0, 1, 2);

    spacerItem = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem, 4, 0, 1, 1);

    GBTypeConf = new QGroupBox(CreateCase);
    GBTypeConf->setObjectName(QString::fromUtf8("GBTypeConf"));
    hboxLayout3 = new QHBoxLayout(GBTypeConf);
    hboxLayout3->setSpacing(6);
    hboxLayout3->setMargin(9);
    hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
    RBConforme = new QRadioButton(GBTypeConf);
    RBConforme->setObjectName(QString::fromUtf8("RBConforme"));
    RBConforme->setChecked(true);

    hboxLayout3->addWidget(RBConforme);

    RBNonConforme = new QRadioButton(GBTypeConf);
    RBNonConforme->setObjectName(QString::fromUtf8("RBNonConforme"));

    hboxLayout3->addWidget(RBNonConforme);


    gridLayout->addWidget(GBTypeConf, 5, 0, 1, 2);

    spacerItem1 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem1, 6, 0, 1, 1);

    GBTypeNoConf = new QGroupBox(CreateCase);
    GBTypeNoConf->setObjectName(QString::fromUtf8("GBTypeNoConf"));
    hboxLayout4 = new QHBoxLayout(GBTypeNoConf);
    hboxLayout4->setSpacing(6);
    hboxLayout4->setMargin(9);
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


    gridLayout->addWidget(GBTypeNoConf, 7, 0, 1, 2);

    spacerItem2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem2, 8, 0, 1, 1);

    hboxLayout5 = new QHBoxLayout();
    hboxLayout5->setSpacing(6);
    hboxLayout5->setMargin(0);
    hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
    CBBoundaryD = new QCheckBox(CreateCase);
    CBBoundaryD->setObjectName(QString::fromUtf8("CBBoundaryD"));

    hboxLayout5->addWidget(CBBoundaryD);

    CBBoundaryA = new QCheckBox(CreateCase);
    CBBoundaryA->setObjectName(QString::fromUtf8("CBBoundaryA"));

    hboxLayout5->addWidget(CBBoundaryA);


    gridLayout->addLayout(hboxLayout5, 9, 0, 1, 1);

    spacerItem3 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem3, 10, 0, 1, 1);

    spacerItem4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem4, 2, 1, 1, 1);

    GBBoundaryD = new QGroupBox(CreateCase);
    GBBoundaryD->setObjectName(QString::fromUtf8("GBBoundaryD"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(GBBoundaryD->sizePolicy().hasHeightForWidth());
    GBBoundaryD->setSizePolicy(sizePolicy1);
    gridLayout2 = new QGridLayout(GBBoundaryD);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    PBBoundaryDiHelp = new QPushButton(GBBoundaryD);
    PBBoundaryDiHelp->setObjectName(QString::fromUtf8("PBBoundaryDiHelp"));
    PBBoundaryDiHelp->setAutoDefault(false);

    gridLayout2->addWidget(PBBoundaryDiHelp, 0, 4, 1, 1);

    PBBoundaryDiNew = new QPushButton(GBBoundaryD);
    PBBoundaryDiNew->setObjectName(QString::fromUtf8("PBBoundaryDiNew"));
    PBBoundaryDiNew->setAutoDefault(false);

    gridLayout2->addWidget(PBBoundaryDiNew, 0, 3, 1, 1);

    PBBoundaryDiEdit = new QPushButton(GBBoundaryD);
    PBBoundaryDiEdit->setObjectName(QString::fromUtf8("PBBoundaryDiEdit"));
    PBBoundaryDiEdit->setAutoDefault(false);

    gridLayout2->addWidget(PBBoundaryDiEdit, 0, 2, 1, 1);

    spacerItem5 = new QSpacerItem(40, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

    gridLayout2->addItem(spacerItem5, 0, 1, 1, 1);

    CBBoundaryDi = new QComboBox(GBBoundaryD);
    CBBoundaryDi->setObjectName(QString::fromUtf8("CBBoundaryDi"));
    CBBoundaryDi->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    gridLayout2->addWidget(CBBoundaryDi, 0, 0, 1, 1);


    gridLayout->addWidget(GBBoundaryD, 11, 0, 1, 1);


    retranslateUi(CreateCase);

    QSize size(597, 850);
    size = size.expandedTo(CreateCase->minimumSizeHint());
    CreateCase->resize(size);


    CBBoundaryDi->setCurrentIndex(-1);


    QMetaObject::connectSlotsByName(CreateCase);
    } // setupUi

    void retranslateUi(QDialog *CreateCase)
    {
    CreateCase->setWindowTitle(QApplication::translate("CreateCase", "Create Case", 0, QApplication::UnicodeUTF8));
    GroupButtons->setTitle(QString());
    buttonOk->setText(QApplication::translate("CreateCase", "&Ok", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateCase", "&Apply", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateCase", "&Cancel", 0, QApplication::UnicodeUTF8));
    buttonHelp->setText(QApplication::translate("CreateCase", "&Help", 0, QApplication::UnicodeUTF8));
    GBBoundaryA->setTitle(QApplication::translate("CreateCase", "Analytic Boundary", 0, QApplication::UnicodeUTF8));
    PBBoundaryAnNew->setText(QApplication::translate("CreateCase", "New", 0, QApplication::UnicodeUTF8));
    PBBoundaryAnHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
    if (TWBoundary->columnCount() < 1)
        TWBoundary->setColumnCount(1);

    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("CreateCase", "a_virer", 0, QApplication::UnicodeUTF8));
    TWBoundary->setHorizontalHeaderItem(0, __colItem);
    Name->setText(QApplication::translate("CreateCase", "Name", 0, QApplication::UnicodeUTF8));
    Directory->setText(QApplication::translate("CreateCase", "Directory", 0, QApplication::UnicodeUTF8));
    PushDir->setText(QString());
    Mesh_2->setText(QApplication::translate("CreateCase", "Mesh", 0, QApplication::UnicodeUTF8));
    PushFichier->setText(QString());
    GBTypeConf->setTitle(QApplication::translate("CreateCase", "Conformity Type", 0, QApplication::UnicodeUTF8));
    RBConforme->setText(QApplication::translate("CreateCase", "Conformal", 0, QApplication::UnicodeUTF8));
    RBNonConforme->setText(QApplication::translate("CreateCase", "Non conformal", 0, QApplication::UnicodeUTF8));
    GBTypeNoConf->setTitle(QApplication::translate("CreateCase", "Non Conformal option", 0, QApplication::UnicodeUTF8));
    RB1NpM->setText(QApplication::translate("CreateCase", "1 hanging node per mesh", 0, QApplication::UnicodeUTF8));
    RB1NpA->setText(QApplication::translate("CreateCase", "1 node per edge", 0, QApplication::UnicodeUTF8));
    RBQuelconque->setText(QApplication::translate("CreateCase", "free", 0, QApplication::UnicodeUTF8));
    CBBoundaryD->setText(QApplication::translate("CreateCase", "Discrete Boundary ", 0, QApplication::UnicodeUTF8));
    CBBoundaryA->setText(QApplication::translate("CreateCase", "Analytic Boundary ", 0, QApplication::UnicodeUTF8));
    GBBoundaryD->setTitle(QApplication::translate("CreateCase", "Discrete Boundary", 0, QApplication::UnicodeUTF8));
    PBBoundaryDiHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
    PBBoundaryDiNew->setText(QApplication::translate("CreateCase", "New", 0, QApplication::UnicodeUTF8));
    PBBoundaryDiEdit->setText(QApplication::translate("CreateCase", "Edit", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CreateCase);
    } // retranslateUi

};

namespace Ui {
    class CreateCase: public Ui_CreateCase {};
} // namespace Ui

#endif // CREATECASE_H
