/********************************************************************************
** Form generated from reading ui file 'CreateZone.ui'
**
** Created: Thu Sep 1 13:03:50 2011
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef CREATEZONE_H
#define CREATEZONE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

class Ui_CreateZone
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonHelp;
    QPushButton *buttonCancel;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QGroupBox *TypeZone;
    QGridLayout *gridLayout2;
    QRadioButton *RBSphere;
    QRadioButton *RBPipe;
    QRadioButton *RBCylinder;
    QRadioButton *RBBox;
    QGroupBox *gBCylindre;
    QGridLayout *gridLayout3;
    QDoubleSpinBox *SpinBox_Haut;
    QLabel *TLHaut;
    QLabel *TLRadius;
    QDoubleSpinBox *SpinBox_Xaxis;
    QDoubleSpinBox *SpinBox_Yaxis;
    QDoubleSpinBox *SpinBox_Zaxis;
    QLabel *TLZaxis;
    QLabel *TLYaxis;
    QLabel *TLXaxis;
    QDoubleSpinBox *SpinBox_Ybase;
    QLabel *TLYbase;
    QLabel *TLZbase;
    QDoubleSpinBox *SpinBox_Zbase;
    QDoubleSpinBox *SpinBox_Radius;
    QLabel *TLXbase;
    QDoubleSpinBox *SpinBox_Xbase;
    QGroupBox *gBSphere;
    QGridLayout *gridLayout4;
    QLabel *TLXcentre;
    QDoubleSpinBox *SpinBox_Xcentre;
    QLabel *TLYcentre;
    QDoubleSpinBox *SpinBox_Ycentre;
    QLabel *TLRayon;
    QDoubleSpinBox *SpinBox_Rayon;
    QLabel *TLZcentre;
    QDoubleSpinBox *SpinBox_Zcentre;
    QGroupBox *gBBox;
    QGridLayout *gridLayout5;
    QLabel *TLXmini;
    QDoubleSpinBox *SpinBox_Xmini;
    QLabel *TLYmini;
    QDoubleSpinBox *SpinBox_Ymini;
    QLabel *TLZmini;
    QDoubleSpinBox *SpinBox_Zmini;
    QLabel *TLXmaxi;
    QLabel *TLZmaxi;
    QDoubleSpinBox *SpinBox_Zmaxi;
    QLabel *TLYmaxi;
    QDoubleSpinBox *SpinBox_Xmaxi;
    QDoubleSpinBox *SpinBox_Ymaxi;
    QLineEdit *LEZoneName;
    QLabel *Name;
    QGroupBox *gBPipe;
    QGridLayout *gridLayout6;
    QLabel *TLHaut_p;
    QDoubleSpinBox *SpinBox_Xbase_p;
    QLabel *TLXbase_p;
    QDoubleSpinBox *SpinBox_Radius_int;
    QDoubleSpinBox *SpinBox_Zbase_p;
    QLabel *TLRadius_int;
    QLabel *TLZbase_p;
    QLabel *TLYbase_p;
    QDoubleSpinBox *SpinBox_Ybase_p;
    QLabel *TLXaxis_p;
    QLabel *TLYaxis_p;
    QLabel *TLZaxis_p;
    QDoubleSpinBox *SpinBox_Zaxis_p;
    QDoubleSpinBox *SpinBox_Yaxis_p;
    QDoubleSpinBox *SpinBox_Xaxis_p;
    QDoubleSpinBox *SpinBox_Radius_ext;
    QLabel *TLRadius_ext;
    QDoubleSpinBox *SpinBox_Haut_p;

    void setupUi(QDialog *CreateZone)
    {
    CreateZone->setObjectName(QString::fromUtf8("CreateZone"));
    CreateZone->setAutoFillBackground(true);
    CreateZone->setSizeGripEnabled(true);
    gridLayout = new QGridLayout(CreateZone);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    GBButtons = new QGroupBox(CreateZone);
    GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(GBButtons->sizePolicy().hasHeightForWidth());
    GBButtons->setSizePolicy(sizePolicy);
    gridLayout1 = new QGridLayout(GBButtons);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    buttonHelp = new QPushButton(GBButtons);
    buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

    gridLayout1->addWidget(buttonHelp, 0, 3, 1, 1);

    buttonCancel = new QPushButton(GBButtons);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

    gridLayout1->addWidget(buttonCancel, 0, 2, 1, 1);

    buttonApply = new QPushButton(GBButtons);
    buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

    gridLayout1->addWidget(buttonApply, 0, 1, 1, 1);

    buttonOk = new QPushButton(GBButtons);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

    gridLayout1->addWidget(buttonOk, 0, 0, 1, 1);


    gridLayout->addWidget(GBButtons, 6, 0, 1, 2);

    TypeZone = new QGroupBox(CreateZone);
    TypeZone->setObjectName(QString::fromUtf8("TypeZone"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(TypeZone->sizePolicy().hasHeightForWidth());
    TypeZone->setSizePolicy(sizePolicy1);
    TypeZone->setMinimumSize(QSize(340, 0));
    gridLayout2 = new QGridLayout(TypeZone);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    RBSphere = new QRadioButton(TypeZone);
    RBSphere->setObjectName(QString::fromUtf8("RBSphere"));
    RBSphere->setIcon(QIcon(QString::fromUtf8("../../resources/zone_spherepoint.png")));

    gridLayout2->addWidget(RBSphere, 0, 3, 1, 1);

    RBPipe = new QRadioButton(TypeZone);
    RBPipe->setObjectName(QString::fromUtf8("RBPipe"));
    RBPipe->setIcon(QIcon(QString::fromUtf8("../../resources/pipe.png")));

    gridLayout2->addWidget(RBPipe, 0, 2, 1, 1);

    RBCylinder = new QRadioButton(TypeZone);
    RBCylinder->setObjectName(QString::fromUtf8("RBCylinder"));
    RBCylinder->setIcon(QIcon(QString::fromUtf8("../../resources/cylinderpointvector.png")));

    gridLayout2->addWidget(RBCylinder, 0, 1, 1, 1);

    RBBox = new QRadioButton(TypeZone);
    RBBox->setObjectName(QString::fromUtf8("RBBox"));
    RBBox->setIcon(QIcon(QString::fromUtf8("../../resources/zone_boxdxyz.png")));
    RBBox->setCheckable(true);
    RBBox->setChecked(true);

    gridLayout2->addWidget(RBBox, 0, 0, 1, 1);


    gridLayout->addWidget(TypeZone, 1, 0, 1, 2);

    gBCylindre = new QGroupBox(CreateZone);
    gBCylindre->setObjectName(QString::fromUtf8("gBCylindre"));
    QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(gBCylindre->sizePolicy().hasHeightForWidth());
    gBCylindre->setSizePolicy(sizePolicy2);
    gBCylindre->setFocusPolicy(Qt::TabFocus);
    gridLayout3 = new QGridLayout(gBCylindre);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(9);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    SpinBox_Haut = new QDoubleSpinBox(gBCylindre);
    SpinBox_Haut->setObjectName(QString::fromUtf8("SpinBox_Haut"));
    SpinBox_Haut->setDecimals(5);
    SpinBox_Haut->setMaximum(1e+09);

    gridLayout3->addWidget(SpinBox_Haut, 4, 1, 1, 1);

    TLHaut = new QLabel(gBCylindre);
    TLHaut->setObjectName(QString::fromUtf8("TLHaut"));
    QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(TLHaut->sizePolicy().hasHeightForWidth());
    TLHaut->setSizePolicy(sizePolicy3);
    TLHaut->setWordWrap(false);

    gridLayout3->addWidget(TLHaut, 4, 0, 1, 1);

    TLRadius = new QLabel(gBCylindre);
    TLRadius->setObjectName(QString::fromUtf8("TLRadius"));
    QSizePolicy sizePolicy4(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(TLRadius->sizePolicy().hasHeightForWidth());
    TLRadius->setSizePolicy(sizePolicy4);
    TLRadius->setWordWrap(false);

    gridLayout3->addWidget(TLRadius, 3, 0, 1, 1);

    SpinBox_Xaxis = new QDoubleSpinBox(gBCylindre);
    SpinBox_Xaxis->setObjectName(QString::fromUtf8("SpinBox_Xaxis"));
    SpinBox_Xaxis->setDecimals(5);
    SpinBox_Xaxis->setMaximum(1e+09);
    SpinBox_Xaxis->setMinimum(-1e+09);
    SpinBox_Xaxis->setValue(0);

    gridLayout3->addWidget(SpinBox_Xaxis, 0, 3, 1, 1);

    SpinBox_Yaxis = new QDoubleSpinBox(gBCylindre);
    SpinBox_Yaxis->setObjectName(QString::fromUtf8("SpinBox_Yaxis"));
    SpinBox_Yaxis->setDecimals(5);
    SpinBox_Yaxis->setMaximum(1e+09);
    SpinBox_Yaxis->setMinimum(-1e+09);
    SpinBox_Yaxis->setValue(0);

    gridLayout3->addWidget(SpinBox_Yaxis, 1, 3, 1, 1);

    SpinBox_Zaxis = new QDoubleSpinBox(gBCylindre);
    SpinBox_Zaxis->setObjectName(QString::fromUtf8("SpinBox_Zaxis"));
    SpinBox_Zaxis->setDecimals(5);
    SpinBox_Zaxis->setMaximum(1e+09);
    SpinBox_Zaxis->setMinimum(-1e+09);
    SpinBox_Zaxis->setValue(0);

    gridLayout3->addWidget(SpinBox_Zaxis, 2, 3, 1, 1);

    TLZaxis = new QLabel(gBCylindre);
    TLZaxis->setObjectName(QString::fromUtf8("TLZaxis"));
    QSizePolicy sizePolicy5(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy5.setHorizontalStretch(0);
    sizePolicy5.setVerticalStretch(0);
    sizePolicy5.setHeightForWidth(TLZaxis->sizePolicy().hasHeightForWidth());
    TLZaxis->setSizePolicy(sizePolicy5);
    TLZaxis->setWordWrap(false);

    gridLayout3->addWidget(TLZaxis, 2, 2, 1, 1);

    TLYaxis = new QLabel(gBCylindre);
    TLYaxis->setObjectName(QString::fromUtf8("TLYaxis"));
    QSizePolicy sizePolicy6(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy6.setHorizontalStretch(0);
    sizePolicy6.setVerticalStretch(0);
    sizePolicy6.setHeightForWidth(TLYaxis->sizePolicy().hasHeightForWidth());
    TLYaxis->setSizePolicy(sizePolicy6);
    TLYaxis->setWordWrap(false);

    gridLayout3->addWidget(TLYaxis, 1, 2, 1, 1);

    TLXaxis = new QLabel(gBCylindre);
    TLXaxis->setObjectName(QString::fromUtf8("TLXaxis"));
    QSizePolicy sizePolicy7(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy7.setHorizontalStretch(0);
    sizePolicy7.setVerticalStretch(0);
    sizePolicy7.setHeightForWidth(TLXaxis->sizePolicy().hasHeightForWidth());
    TLXaxis->setSizePolicy(sizePolicy7);
    TLXaxis->setWordWrap(false);

    gridLayout3->addWidget(TLXaxis, 0, 2, 1, 1);

    SpinBox_Ybase = new QDoubleSpinBox(gBCylindre);
    SpinBox_Ybase->setObjectName(QString::fromUtf8("SpinBox_Ybase"));
    SpinBox_Ybase->setDecimals(5);
    SpinBox_Ybase->setMaximum(1e+09);
    SpinBox_Ybase->setMinimum(-1e+09);
    SpinBox_Ybase->setValue(0);

    gridLayout3->addWidget(SpinBox_Ybase, 1, 1, 1, 1);

    TLYbase = new QLabel(gBCylindre);
    TLYbase->setObjectName(QString::fromUtf8("TLYbase"));
    QSizePolicy sizePolicy8(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy8.setHorizontalStretch(0);
    sizePolicy8.setVerticalStretch(0);
    sizePolicy8.setHeightForWidth(TLYbase->sizePolicy().hasHeightForWidth());
    TLYbase->setSizePolicy(sizePolicy8);
    TLYbase->setWordWrap(false);

    gridLayout3->addWidget(TLYbase, 1, 0, 1, 1);

    TLZbase = new QLabel(gBCylindre);
    TLZbase->setObjectName(QString::fromUtf8("TLZbase"));
    QSizePolicy sizePolicy9(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy9.setHorizontalStretch(0);
    sizePolicy9.setVerticalStretch(0);
    sizePolicy9.setHeightForWidth(TLZbase->sizePolicy().hasHeightForWidth());
    TLZbase->setSizePolicy(sizePolicy9);
    TLZbase->setWordWrap(false);

    gridLayout3->addWidget(TLZbase, 2, 0, 1, 1);

    SpinBox_Zbase = new QDoubleSpinBox(gBCylindre);
    SpinBox_Zbase->setObjectName(QString::fromUtf8("SpinBox_Zbase"));
    SpinBox_Zbase->setDecimals(5);
    SpinBox_Zbase->setMaximum(1e+09);
    SpinBox_Zbase->setMinimum(-1e+09);
    SpinBox_Zbase->setValue(0);

    gridLayout3->addWidget(SpinBox_Zbase, 2, 1, 1, 1);

    SpinBox_Radius = new QDoubleSpinBox(gBCylindre);
    SpinBox_Radius->setObjectName(QString::fromUtf8("SpinBox_Radius"));
    SpinBox_Radius->setDecimals(5);
    SpinBox_Radius->setMaximum(1e+09);

    gridLayout3->addWidget(SpinBox_Radius, 3, 1, 1, 1);

    TLXbase = new QLabel(gBCylindre);
    TLXbase->setObjectName(QString::fromUtf8("TLXbase"));
    QSizePolicy sizePolicy10(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy10.setHorizontalStretch(0);
    sizePolicy10.setVerticalStretch(0);
    sizePolicy10.setHeightForWidth(TLXbase->sizePolicy().hasHeightForWidth());
    TLXbase->setSizePolicy(sizePolicy10);
    TLXbase->setWordWrap(false);

    gridLayout3->addWidget(TLXbase, 0, 0, 1, 1);

    SpinBox_Xbase = new QDoubleSpinBox(gBCylindre);
    SpinBox_Xbase->setObjectName(QString::fromUtf8("SpinBox_Xbase"));
    SpinBox_Xbase->setDecimals(5);
    SpinBox_Xbase->setMaximum(1e+09);
    SpinBox_Xbase->setMinimum(-1e+09);
    SpinBox_Xbase->setValue(0);

    gridLayout3->addWidget(SpinBox_Xbase, 0, 1, 1, 1);


    gridLayout->addWidget(gBCylindre, 4, 0, 1, 2);

    gBSphere = new QGroupBox(CreateZone);
    gBSphere->setObjectName(QString::fromUtf8("gBSphere"));
    QSizePolicy sizePolicy11(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy11.setHorizontalStretch(0);
    sizePolicy11.setVerticalStretch(0);
    sizePolicy11.setHeightForWidth(gBSphere->sizePolicy().hasHeightForWidth());
    gBSphere->setSizePolicy(sizePolicy11);
    gridLayout4 = new QGridLayout(gBSphere);
    gridLayout4->setSpacing(6);
    gridLayout4->setMargin(9);
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    TLXcentre = new QLabel(gBSphere);
    TLXcentre->setObjectName(QString::fromUtf8("TLXcentre"));
    QSizePolicy sizePolicy12(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy12.setHorizontalStretch(0);
    sizePolicy12.setVerticalStretch(0);
    sizePolicy12.setHeightForWidth(TLXcentre->sizePolicy().hasHeightForWidth());
    TLXcentre->setSizePolicy(sizePolicy12);
    TLXcentre->setWordWrap(false);

    gridLayout4->addWidget(TLXcentre, 0, 0, 1, 1);

    SpinBox_Xcentre = new QDoubleSpinBox(gBSphere);
    SpinBox_Xcentre->setObjectName(QString::fromUtf8("SpinBox_Xcentre"));
    SpinBox_Xcentre->setDecimals(5);
    SpinBox_Xcentre->setMaximum(1e+09);
    SpinBox_Xcentre->setMinimum(-1e+09);
    SpinBox_Xcentre->setValue(0);

    gridLayout4->addWidget(SpinBox_Xcentre, 0, 1, 1, 1);

    TLYcentre = new QLabel(gBSphere);
    TLYcentre->setObjectName(QString::fromUtf8("TLYcentre"));
    QSizePolicy sizePolicy13(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy13.setHorizontalStretch(0);
    sizePolicy13.setVerticalStretch(0);
    sizePolicy13.setHeightForWidth(TLYcentre->sizePolicy().hasHeightForWidth());
    TLYcentre->setSizePolicy(sizePolicy13);
    TLYcentre->setWordWrap(false);

    gridLayout4->addWidget(TLYcentre, 1, 0, 1, 1);

    SpinBox_Ycentre = new QDoubleSpinBox(gBSphere);
    SpinBox_Ycentre->setObjectName(QString::fromUtf8("SpinBox_Ycentre"));
    SpinBox_Ycentre->setDecimals(5);
    SpinBox_Ycentre->setMaximum(1e+09);
    SpinBox_Ycentre->setMinimum(-1e+09);
    SpinBox_Ycentre->setValue(0);

    gridLayout4->addWidget(SpinBox_Ycentre, 1, 1, 1, 1);

    TLRayon = new QLabel(gBSphere);
    TLRayon->setObjectName(QString::fromUtf8("TLRayon"));
    QSizePolicy sizePolicy14(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy14.setHorizontalStretch(0);
    sizePolicy14.setVerticalStretch(0);
    sizePolicy14.setHeightForWidth(TLRayon->sizePolicy().hasHeightForWidth());
    TLRayon->setSizePolicy(sizePolicy14);
    TLRayon->setWordWrap(false);

    gridLayout4->addWidget(TLRayon, 1, 2, 1, 1);

    SpinBox_Rayon = new QDoubleSpinBox(gBSphere);
    SpinBox_Rayon->setObjectName(QString::fromUtf8("SpinBox_Rayon"));
    SpinBox_Rayon->setDecimals(5);
    SpinBox_Rayon->setMaximum(1e+09);
    SpinBox_Rayon->setMinimum(-1e+09);
    SpinBox_Rayon->setValue(0);

    gridLayout4->addWidget(SpinBox_Rayon, 1, 3, 1, 1);

    TLZcentre = new QLabel(gBSphere);
    TLZcentre->setObjectName(QString::fromUtf8("TLZcentre"));
    QSizePolicy sizePolicy15(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy15.setHorizontalStretch(0);
    sizePolicy15.setVerticalStretch(0);
    sizePolicy15.setHeightForWidth(TLZcentre->sizePolicy().hasHeightForWidth());
    TLZcentre->setSizePolicy(sizePolicy15);
    TLZcentre->setWordWrap(false);

    gridLayout4->addWidget(TLZcentre, 2, 0, 1, 1);

    SpinBox_Zcentre = new QDoubleSpinBox(gBSphere);
    SpinBox_Zcentre->setObjectName(QString::fromUtf8("SpinBox_Zcentre"));
    SpinBox_Zcentre->setDecimals(5);
    SpinBox_Zcentre->setMaximum(1e+09);
    SpinBox_Zcentre->setMinimum(-1e+09);
    SpinBox_Zcentre->setValue(0);

    gridLayout4->addWidget(SpinBox_Zcentre, 2, 1, 1, 1);


    gridLayout->addWidget(gBSphere, 3, 0, 1, 2);

    gBBox = new QGroupBox(CreateZone);
    gBBox->setObjectName(QString::fromUtf8("gBBox"));
    QSizePolicy sizePolicy16(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy16.setHorizontalStretch(0);
    sizePolicy16.setVerticalStretch(0);
    sizePolicy16.setHeightForWidth(gBBox->sizePolicy().hasHeightForWidth());
    gBBox->setSizePolicy(sizePolicy16);
    gridLayout5 = new QGridLayout(gBBox);
    gridLayout5->setSpacing(6);
    gridLayout5->setMargin(9);
    gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
    TLXmini = new QLabel(gBBox);
    TLXmini->setObjectName(QString::fromUtf8("TLXmini"));
    QSizePolicy sizePolicy17(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy17.setHorizontalStretch(0);
    sizePolicy17.setVerticalStretch(0);
    sizePolicy17.setHeightForWidth(TLXmini->sizePolicy().hasHeightForWidth());
    TLXmini->setSizePolicy(sizePolicy17);
    TLXmini->setWordWrap(false);

    gridLayout5->addWidget(TLXmini, 0, 0, 1, 1);

    SpinBox_Xmini = new QDoubleSpinBox(gBBox);
    SpinBox_Xmini->setObjectName(QString::fromUtf8("SpinBox_Xmini"));
    SpinBox_Xmini->setDecimals(5);
    SpinBox_Xmini->setMaximum(1e+09);
    SpinBox_Xmini->setMinimum(-1e+09);
    SpinBox_Xmini->setValue(0);

    gridLayout5->addWidget(SpinBox_Xmini, 0, 1, 1, 1);

    TLYmini = new QLabel(gBBox);
    TLYmini->setObjectName(QString::fromUtf8("TLYmini"));
    QSizePolicy sizePolicy18(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy18.setHorizontalStretch(0);
    sizePolicy18.setVerticalStretch(0);
    sizePolicy18.setHeightForWidth(TLYmini->sizePolicy().hasHeightForWidth());
    TLYmini->setSizePolicy(sizePolicy18);
    TLYmini->setWordWrap(false);

    gridLayout5->addWidget(TLYmini, 1, 0, 1, 1);

    SpinBox_Ymini = new QDoubleSpinBox(gBBox);
    SpinBox_Ymini->setObjectName(QString::fromUtf8("SpinBox_Ymini"));
    SpinBox_Ymini->setDecimals(5);
    SpinBox_Ymini->setMaximum(1e+09);
    SpinBox_Ymini->setMinimum(-1e+09);
    SpinBox_Ymini->setValue(0);

    gridLayout5->addWidget(SpinBox_Ymini, 1, 1, 1, 1);

    TLZmini = new QLabel(gBBox);
    TLZmini->setObjectName(QString::fromUtf8("TLZmini"));
    QSizePolicy sizePolicy19(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy19.setHorizontalStretch(0);
    sizePolicy19.setVerticalStretch(0);
    sizePolicy19.setHeightForWidth(TLZmini->sizePolicy().hasHeightForWidth());
    TLZmini->setSizePolicy(sizePolicy19);
    TLZmini->setWordWrap(false);

    gridLayout5->addWidget(TLZmini, 2, 0, 1, 1);

    SpinBox_Zmini = new QDoubleSpinBox(gBBox);
    SpinBox_Zmini->setObjectName(QString::fromUtf8("SpinBox_Zmini"));
    SpinBox_Zmini->setDecimals(5);
    SpinBox_Zmini->setMaximum(1e+09);
    SpinBox_Zmini->setMinimum(-1e+09);
    SpinBox_Zmini->setValue(0);

    gridLayout5->addWidget(SpinBox_Zmini, 2, 1, 1, 1);

    TLXmaxi = new QLabel(gBBox);
    TLXmaxi->setObjectName(QString::fromUtf8("TLXmaxi"));
    QSizePolicy sizePolicy20(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy20.setHorizontalStretch(0);
    sizePolicy20.setVerticalStretch(0);
    sizePolicy20.setHeightForWidth(TLXmaxi->sizePolicy().hasHeightForWidth());
    TLXmaxi->setSizePolicy(sizePolicy20);
    TLXmaxi->setWordWrap(false);

    gridLayout5->addWidget(TLXmaxi, 0, 2, 1, 1);

    TLZmaxi = new QLabel(gBBox);
    TLZmaxi->setObjectName(QString::fromUtf8("TLZmaxi"));
    QSizePolicy sizePolicy21(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy21.setHorizontalStretch(0);
    sizePolicy21.setVerticalStretch(0);
    sizePolicy21.setHeightForWidth(TLZmaxi->sizePolicy().hasHeightForWidth());
    TLZmaxi->setSizePolicy(sizePolicy21);
    TLZmaxi->setWordWrap(false);

    gridLayout5->addWidget(TLZmaxi, 2, 2, 1, 1);

    SpinBox_Zmaxi = new QDoubleSpinBox(gBBox);
    SpinBox_Zmaxi->setObjectName(QString::fromUtf8("SpinBox_Zmaxi"));
    SpinBox_Zmaxi->setDecimals(5);
    SpinBox_Zmaxi->setMaximum(1e+09);
    SpinBox_Zmaxi->setMinimum(-1e+09);
    SpinBox_Zmaxi->setValue(0);

    gridLayout5->addWidget(SpinBox_Zmaxi, 2, 3, 1, 1);

    TLYmaxi = new QLabel(gBBox);
    TLYmaxi->setObjectName(QString::fromUtf8("TLYmaxi"));
    QSizePolicy sizePolicy22(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy22.setHorizontalStretch(0);
    sizePolicy22.setVerticalStretch(0);
    sizePolicy22.setHeightForWidth(TLYmaxi->sizePolicy().hasHeightForWidth());
    TLYmaxi->setSizePolicy(sizePolicy22);
    TLYmaxi->setWordWrap(false);

    gridLayout5->addWidget(TLYmaxi, 1, 2, 1, 1);

    SpinBox_Xmaxi = new QDoubleSpinBox(gBBox);
    SpinBox_Xmaxi->setObjectName(QString::fromUtf8("SpinBox_Xmaxi"));
    SpinBox_Xmaxi->setDecimals(5);
    SpinBox_Xmaxi->setMaximum(1e+09);
    SpinBox_Xmaxi->setMinimum(-1e+09);
    SpinBox_Xmaxi->setValue(0);

    gridLayout5->addWidget(SpinBox_Xmaxi, 0, 3, 1, 1);

    SpinBox_Ymaxi = new QDoubleSpinBox(gBBox);
    SpinBox_Ymaxi->setObjectName(QString::fromUtf8("SpinBox_Ymaxi"));
    SpinBox_Ymaxi->setDecimals(5);
    SpinBox_Ymaxi->setMaximum(1e+09);
    SpinBox_Ymaxi->setMinimum(-1e+09);
    SpinBox_Ymaxi->setValue(0);

    gridLayout5->addWidget(SpinBox_Ymaxi, 1, 3, 1, 1);


    gridLayout->addWidget(gBBox, 2, 0, 1, 2);

    LEZoneName = new QLineEdit(CreateZone);
    LEZoneName->setObjectName(QString::fromUtf8("LEZoneName"));
    LEZoneName->setMaxLength(32);

    gridLayout->addWidget(LEZoneName, 0, 1, 1, 1);

    Name = new QLabel(CreateZone);
    Name->setObjectName(QString::fromUtf8("Name"));

    gridLayout->addWidget(Name, 0, 0, 1, 1);

    gBPipe = new QGroupBox(CreateZone);
    gBPipe->setObjectName(QString::fromUtf8("gBPipe"));
    QSizePolicy sizePolicy23(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy23.setHorizontalStretch(0);
    sizePolicy23.setVerticalStretch(0);
    sizePolicy23.setHeightForWidth(gBPipe->sizePolicy().hasHeightForWidth());
    gBPipe->setSizePolicy(sizePolicy23);
    gridLayout6 = new QGridLayout(gBPipe);
    gridLayout6->setSpacing(6);
    gridLayout6->setMargin(9);
    gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
    TLHaut_p = new QLabel(gBPipe);
    TLHaut_p->setObjectName(QString::fromUtf8("TLHaut_p"));
    QSizePolicy sizePolicy24(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy24.setHorizontalStretch(0);
    sizePolicy24.setVerticalStretch(0);
    sizePolicy24.setHeightForWidth(TLHaut_p->sizePolicy().hasHeightForWidth());
    TLHaut_p->setSizePolicy(sizePolicy24);
    TLHaut_p->setWordWrap(false);

    gridLayout6->addWidget(TLHaut_p, 4, 0, 1, 1);

    SpinBox_Xbase_p = new QDoubleSpinBox(gBPipe);
    SpinBox_Xbase_p->setObjectName(QString::fromUtf8("SpinBox_Xbase_p"));
    SpinBox_Xbase_p->setDecimals(5);
    SpinBox_Xbase_p->setMaximum(1e+09);
    SpinBox_Xbase_p->setMinimum(-1e+09);
    SpinBox_Xbase_p->setValue(0);

    gridLayout6->addWidget(SpinBox_Xbase_p, 0, 1, 1, 1);

    TLXbase_p = new QLabel(gBPipe);
    TLXbase_p->setObjectName(QString::fromUtf8("TLXbase_p"));
    QSizePolicy sizePolicy25(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy25.setHorizontalStretch(0);
    sizePolicy25.setVerticalStretch(0);
    sizePolicy25.setHeightForWidth(TLXbase_p->sizePolicy().hasHeightForWidth());
    TLXbase_p->setSizePolicy(sizePolicy25);
    TLXbase_p->setWordWrap(false);

    gridLayout6->addWidget(TLXbase_p, 0, 0, 1, 1);

    SpinBox_Radius_int = new QDoubleSpinBox(gBPipe);
    SpinBox_Radius_int->setObjectName(QString::fromUtf8("SpinBox_Radius_int"));
    SpinBox_Radius_int->setDecimals(5);
    SpinBox_Radius_int->setMaximum(1e+09);

    gridLayout6->addWidget(SpinBox_Radius_int, 3, 1, 1, 1);

    SpinBox_Zbase_p = new QDoubleSpinBox(gBPipe);
    SpinBox_Zbase_p->setObjectName(QString::fromUtf8("SpinBox_Zbase_p"));
    SpinBox_Zbase_p->setDecimals(5);
    SpinBox_Zbase_p->setMaximum(1e+09);
    SpinBox_Zbase_p->setMinimum(-1e+09);
    SpinBox_Zbase_p->setValue(0);

    gridLayout6->addWidget(SpinBox_Zbase_p, 2, 1, 1, 1);

    TLRadius_int = new QLabel(gBPipe);
    TLRadius_int->setObjectName(QString::fromUtf8("TLRadius_int"));
    QSizePolicy sizePolicy26(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy26.setHorizontalStretch(0);
    sizePolicy26.setVerticalStretch(0);
    sizePolicy26.setHeightForWidth(TLRadius_int->sizePolicy().hasHeightForWidth());
    TLRadius_int->setSizePolicy(sizePolicy26);
    TLRadius_int->setWordWrap(false);

    gridLayout6->addWidget(TLRadius_int, 3, 0, 1, 1);

    TLZbase_p = new QLabel(gBPipe);
    TLZbase_p->setObjectName(QString::fromUtf8("TLZbase_p"));
    QSizePolicy sizePolicy27(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy27.setHorizontalStretch(0);
    sizePolicy27.setVerticalStretch(0);
    sizePolicy27.setHeightForWidth(TLZbase_p->sizePolicy().hasHeightForWidth());
    TLZbase_p->setSizePolicy(sizePolicy27);
    TLZbase_p->setWordWrap(false);

    gridLayout6->addWidget(TLZbase_p, 2, 0, 1, 1);

    TLYbase_p = new QLabel(gBPipe);
    TLYbase_p->setObjectName(QString::fromUtf8("TLYbase_p"));
    QSizePolicy sizePolicy28(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy28.setHorizontalStretch(0);
    sizePolicy28.setVerticalStretch(0);
    sizePolicy28.setHeightForWidth(TLYbase_p->sizePolicy().hasHeightForWidth());
    TLYbase_p->setSizePolicy(sizePolicy28);
    TLYbase_p->setWordWrap(false);

    gridLayout6->addWidget(TLYbase_p, 1, 0, 1, 1);

    SpinBox_Ybase_p = new QDoubleSpinBox(gBPipe);
    SpinBox_Ybase_p->setObjectName(QString::fromUtf8("SpinBox_Ybase_p"));
    SpinBox_Ybase_p->setDecimals(5);
    SpinBox_Ybase_p->setMaximum(1e+09);
    SpinBox_Ybase_p->setMinimum(-1e+09);
    SpinBox_Ybase_p->setValue(0);

    gridLayout6->addWidget(SpinBox_Ybase_p, 1, 1, 1, 1);

    TLXaxis_p = new QLabel(gBPipe);
    TLXaxis_p->setObjectName(QString::fromUtf8("TLXaxis_p"));
    QSizePolicy sizePolicy29(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy29.setHorizontalStretch(0);
    sizePolicy29.setVerticalStretch(0);
    sizePolicy29.setHeightForWidth(TLXaxis_p->sizePolicy().hasHeightForWidth());
    TLXaxis_p->setSizePolicy(sizePolicy29);
    TLXaxis_p->setWordWrap(false);

    gridLayout6->addWidget(TLXaxis_p, 0, 2, 1, 1);

    TLYaxis_p = new QLabel(gBPipe);
    TLYaxis_p->setObjectName(QString::fromUtf8("TLYaxis_p"));
    QSizePolicy sizePolicy30(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy30.setHorizontalStretch(0);
    sizePolicy30.setVerticalStretch(0);
    sizePolicy30.setHeightForWidth(TLYaxis_p->sizePolicy().hasHeightForWidth());
    TLYaxis_p->setSizePolicy(sizePolicy30);
    TLYaxis_p->setWordWrap(false);

    gridLayout6->addWidget(TLYaxis_p, 1, 2, 1, 1);

    TLZaxis_p = new QLabel(gBPipe);
    TLZaxis_p->setObjectName(QString::fromUtf8("TLZaxis_p"));
    QSizePolicy sizePolicy31(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy31.setHorizontalStretch(0);
    sizePolicy31.setVerticalStretch(0);
    sizePolicy31.setHeightForWidth(TLZaxis_p->sizePolicy().hasHeightForWidth());
    TLZaxis_p->setSizePolicy(sizePolicy31);
    TLZaxis_p->setWordWrap(false);

    gridLayout6->addWidget(TLZaxis_p, 2, 2, 1, 1);

    SpinBox_Zaxis_p = new QDoubleSpinBox(gBPipe);
    SpinBox_Zaxis_p->setObjectName(QString::fromUtf8("SpinBox_Zaxis_p"));
    SpinBox_Zaxis_p->setDecimals(5);
    SpinBox_Zaxis_p->setMaximum(1e+09);
    SpinBox_Zaxis_p->setMinimum(-1e+09);
    SpinBox_Zaxis_p->setValue(0);

    gridLayout6->addWidget(SpinBox_Zaxis_p, 2, 3, 1, 1);

    SpinBox_Yaxis_p = new QDoubleSpinBox(gBPipe);
    SpinBox_Yaxis_p->setObjectName(QString::fromUtf8("SpinBox_Yaxis_p"));
    SpinBox_Yaxis_p->setDecimals(5);
    SpinBox_Yaxis_p->setMaximum(1e+09);
    SpinBox_Yaxis_p->setMinimum(-1e+09);
    SpinBox_Yaxis_p->setValue(0);

    gridLayout6->addWidget(SpinBox_Yaxis_p, 1, 3, 1, 1);

    SpinBox_Xaxis_p = new QDoubleSpinBox(gBPipe);
    SpinBox_Xaxis_p->setObjectName(QString::fromUtf8("SpinBox_Xaxis_p"));
    SpinBox_Xaxis_p->setDecimals(5);
    SpinBox_Xaxis_p->setMaximum(1e+09);
    SpinBox_Xaxis_p->setMinimum(-1e+09);
    SpinBox_Xaxis_p->setValue(0);

    gridLayout6->addWidget(SpinBox_Xaxis_p, 0, 3, 1, 1);

    SpinBox_Radius_ext = new QDoubleSpinBox(gBPipe);
    SpinBox_Radius_ext->setObjectName(QString::fromUtf8("SpinBox_Radius_ext"));
    SpinBox_Radius_ext->setDecimals(5);
    SpinBox_Radius_ext->setMaximum(1e+09);

    gridLayout6->addWidget(SpinBox_Radius_ext, 3, 3, 1, 1);

    TLRadius_ext = new QLabel(gBPipe);
    TLRadius_ext->setObjectName(QString::fromUtf8("TLRadius_ext"));
    QSizePolicy sizePolicy32(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy32.setHorizontalStretch(0);
    sizePolicy32.setVerticalStretch(0);
    sizePolicy32.setHeightForWidth(TLRadius_ext->sizePolicy().hasHeightForWidth());
    TLRadius_ext->setSizePolicy(sizePolicy32);
    TLRadius_ext->setWordWrap(false);

    gridLayout6->addWidget(TLRadius_ext, 3, 2, 1, 1);

    SpinBox_Haut_p = new QDoubleSpinBox(gBPipe);
    SpinBox_Haut_p->setObjectName(QString::fromUtf8("SpinBox_Haut_p"));
    SpinBox_Haut_p->setDecimals(5);
    SpinBox_Haut_p->setMaximum(1e+09);

    gridLayout6->addWidget(SpinBox_Haut_p, 4, 1, 1, 1);


    gridLayout->addWidget(gBPipe, 5, 0, 1, 2);


    retranslateUi(CreateZone);

    QSize size(551, 880);
    size = size.expandedTo(CreateZone->minimumSizeHint());
    CreateZone->resize(size);


    QMetaObject::connectSlotsByName(CreateZone);
    } // setupUi

    void retranslateUi(QDialog *CreateZone)
    {
    CreateZone->setWindowTitle(QApplication::translate("CreateZone", "Create a zone", 0, QApplication::UnicodeUTF8));
    GBButtons->setTitle(QString());
    buttonHelp->setText(QApplication::translate("CreateZone", "Help", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateZone", "Cancel", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateZone", "Apply", 0, QApplication::UnicodeUTF8));
    buttonOk->setText(QApplication::translate("CreateZone", "OK", 0, QApplication::UnicodeUTF8));
    TypeZone->setTitle(QApplication::translate("CreateZone", "Type of zone", 0, QApplication::UnicodeUTF8));
    RBSphere->setText(QApplication::translate("CreateZone", "Sphere", 0, QApplication::UnicodeUTF8));
    RBPipe->setText(QApplication::translate("CreateZone", "Pipe", 0, QApplication::UnicodeUTF8));
    RBCylinder->setText(QApplication::translate("CreateZone", "Cylinder", 0, QApplication::UnicodeUTF8));
    RBBox->setText(QApplication::translate("CreateZone", "Box", 0, QApplication::UnicodeUTF8));
    gBCylindre->setTitle(QApplication::translate("CreateZone", "Coordinates", 0, QApplication::UnicodeUTF8));
    TLHaut->setText(QApplication::translate("CreateZone", "Height", 0, QApplication::UnicodeUTF8));
    TLRadius->setText(QApplication::translate("CreateZone", "Radius", 0, QApplication::UnicodeUTF8));
    TLZaxis->setText(QApplication::translate("CreateZone", "Z axis", 0, QApplication::UnicodeUTF8));
    TLYaxis->setText(QApplication::translate("CreateZone", "Y axis", 0, QApplication::UnicodeUTF8));
    TLXaxis->setText(QApplication::translate("CreateZone", "X axis", 0, QApplication::UnicodeUTF8));
    TLYbase->setText(QApplication::translate("CreateZone", "Y base", 0, QApplication::UnicodeUTF8));
    TLZbase->setText(QApplication::translate("CreateZone", "Z base", 0, QApplication::UnicodeUTF8));
    TLXbase->setText(QApplication::translate("CreateZone", "X base", 0, QApplication::UnicodeUTF8));
    gBSphere->setTitle(QApplication::translate("CreateZone", "Coordinates", 0, QApplication::UnicodeUTF8));
    TLXcentre->setText(QApplication::translate("CreateZone", "X centre", 0, QApplication::UnicodeUTF8));
    TLYcentre->setText(QApplication::translate("CreateZone", "Y centre", 0, QApplication::UnicodeUTF8));
    TLRayon->setText(QApplication::translate("CreateZone", "Radius", 0, QApplication::UnicodeUTF8));
    TLZcentre->setText(QApplication::translate("CreateZone", "Z centre", 0, QApplication::UnicodeUTF8));
    gBBox->setTitle(QApplication::translate("CreateZone", "Coordinates", 0, QApplication::UnicodeUTF8));
    TLXmini->setText(QApplication::translate("CreateZone", "X mini", 0, QApplication::UnicodeUTF8));
    TLYmini->setText(QApplication::translate("CreateZone", "Y mini", 0, QApplication::UnicodeUTF8));
    TLZmini->setText(QApplication::translate("CreateZone", "Z mini", 0, QApplication::UnicodeUTF8));
    TLXmaxi->setText(QApplication::translate("CreateZone", "X maxi", 0, QApplication::UnicodeUTF8));
    TLZmaxi->setText(QApplication::translate("CreateZone", "Z maxi", 0, QApplication::UnicodeUTF8));
    TLYmaxi->setText(QApplication::translate("CreateZone", "Y maxi", 0, QApplication::UnicodeUTF8));
    Name->setText(QApplication::translate("CreateZone", "Name", 0, QApplication::UnicodeUTF8));
    gBPipe->setTitle(QApplication::translate("CreateZone", "Coordinates", 0, QApplication::UnicodeUTF8));
    TLHaut_p->setText(QApplication::translate("CreateZone", "Height", 0, QApplication::UnicodeUTF8));
    TLXbase_p->setText(QApplication::translate("CreateZone", "X base", 0, QApplication::UnicodeUTF8));
    TLRadius_int->setText(QApplication::translate("CreateZone", "Internal radius", 0, QApplication::UnicodeUTF8));
    TLZbase_p->setText(QApplication::translate("CreateZone", "Z base", 0, QApplication::UnicodeUTF8));
    TLYbase_p->setText(QApplication::translate("CreateZone", "Y base", 0, QApplication::UnicodeUTF8));
    TLXaxis_p->setText(QApplication::translate("CreateZone", "X axis", 0, QApplication::UnicodeUTF8));
    TLYaxis_p->setText(QApplication::translate("CreateZone", "Y axis", 0, QApplication::UnicodeUTF8));
    TLZaxis_p->setText(QApplication::translate("CreateZone", "Z axis", 0, QApplication::UnicodeUTF8));
    TLRadius_ext->setText(QApplication::translate("CreateZone", "External radius", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CreateZone);
    } // retranslateUi

};

namespace Ui {
    class CreateZone: public Ui_CreateZone {};
} // namespace Ui

#endif // CREATEZONE_H
