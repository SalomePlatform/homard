/********************************************************************************
** Form generated from reading ui file 'CreateBoundaryAn.ui'
**
** Created: Fri Sep 2 14:55:24 2011
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef CREATEBOUNDARYAN_H
#define CREATEBOUNDARYAN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

class Ui_CreateBoundaryAn
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonHelp;
    QPushButton *buttonCancel;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QLabel *Name;
    QLineEdit *LEBoundaryName;
    QGroupBox *TypeBoundary;
    QHBoxLayout *hboxLayout;
    QRadioButton *RBCylindre;
    QRadioButton *RBSphere;
    QGroupBox *gBSphere;
    QGridLayout *gridLayout2;
    QDoubleSpinBox *SpinBox_Rayon;
    QDoubleSpinBox *SpinBox_Zcentre;
    QLabel *TLRayon;
    QLabel *TLZcentre;
    QLabel *TLYcentre;
    QDoubleSpinBox *SpinBox_Ycentre;
    QDoubleSpinBox *SpinBox_Xcentre;
    QLabel *TLXcentre;
    QGroupBox *gBCylindre;
    QGridLayout *gridLayout3;
    QDoubleSpinBox *SpinBox_Xcent;
    QLabel *TLXcent;
    QDoubleSpinBox *SpinBox_Radius;
    QDoubleSpinBox *SpinBox_Zcent;
    QLabel *TLradius;
    QLabel *TLZcent;
    QLabel *TLYcent;
    QDoubleSpinBox *SpinBox_Ycent;
    QLabel *TLXaxis;
    QLabel *TLYaxis;
    QLabel *TLZaxis;
    QDoubleSpinBox *SpinBox_Zaxis;
    QDoubleSpinBox *SpinBox_Yaxis;
    QDoubleSpinBox *SpinBox_Xaxis;

    void setupUi(QDialog *CreateBoundaryAn)
    {
    CreateBoundaryAn->setObjectName(QString::fromUtf8("CreateBoundaryAn"));
    CreateBoundaryAn->setAutoFillBackground(true);
    CreateBoundaryAn->setSizeGripEnabled(true);
    gridLayout = new QGridLayout(CreateBoundaryAn);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    GBButtons = new QGroupBox(CreateBoundaryAn);
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


    gridLayout->addWidget(GBButtons, 4, 0, 1, 2);

    Name = new QLabel(CreateBoundaryAn);
    Name->setObjectName(QString::fromUtf8("Name"));

    gridLayout->addWidget(Name, 0, 0, 1, 1);

    LEBoundaryName = new QLineEdit(CreateBoundaryAn);
    LEBoundaryName->setObjectName(QString::fromUtf8("LEBoundaryName"));
    LEBoundaryName->setMaxLength(32);

    gridLayout->addWidget(LEBoundaryName, 0, 1, 1, 1);

    TypeBoundary = new QGroupBox(CreateBoundaryAn);
    TypeBoundary->setObjectName(QString::fromUtf8("TypeBoundary"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(TypeBoundary->sizePolicy().hasHeightForWidth());
    TypeBoundary->setSizePolicy(sizePolicy1);
    TypeBoundary->setMinimumSize(QSize(340, 0));
    hboxLayout = new QHBoxLayout(TypeBoundary);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(9);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    RBCylindre = new QRadioButton(TypeBoundary);
    RBCylindre->setObjectName(QString::fromUtf8("RBCylindre"));
    RBCylindre->setIcon(QIcon(QString::fromUtf8("../../resources/cylinderpointvector.png")));
    RBCylindre->setCheckable(true);
    RBCylindre->setChecked(true);

    hboxLayout->addWidget(RBCylindre);

    RBSphere = new QRadioButton(TypeBoundary);
    RBSphere->setObjectName(QString::fromUtf8("RBSphere"));
    RBSphere->setIcon(QIcon(QString::fromUtf8("../../resources/zone_spherepoint.png")));

    hboxLayout->addWidget(RBSphere);


    gridLayout->addWidget(TypeBoundary, 1, 0, 1, 2);

    gBSphere = new QGroupBox(CreateBoundaryAn);
    gBSphere->setObjectName(QString::fromUtf8("gBSphere"));
    QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(gBSphere->sizePolicy().hasHeightForWidth());
    gBSphere->setSizePolicy(sizePolicy2);
    gridLayout2 = new QGridLayout(gBSphere);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    SpinBox_Rayon = new QDoubleSpinBox(gBSphere);
    SpinBox_Rayon->setObjectName(QString::fromUtf8("SpinBox_Rayon"));
    SpinBox_Rayon->setDecimals(5);
    SpinBox_Rayon->setMaximum(1e+09);
    SpinBox_Rayon->setMinimum(0);
    SpinBox_Rayon->setValue(0);

    gridLayout2->addWidget(SpinBox_Rayon, 1, 3, 1, 1);

    SpinBox_Zcentre = new QDoubleSpinBox(gBSphere);
    SpinBox_Zcentre->setObjectName(QString::fromUtf8("SpinBox_Zcentre"));
    SpinBox_Zcentre->setDecimals(5);
    SpinBox_Zcentre->setMaximum(1e+09);
    SpinBox_Zcentre->setMinimum(-1e+09);
    SpinBox_Zcentre->setValue(0);

    gridLayout2->addWidget(SpinBox_Zcentre, 2, 1, 1, 1);

    TLRayon = new QLabel(gBSphere);
    TLRayon->setObjectName(QString::fromUtf8("TLRayon"));
    QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(TLRayon->sizePolicy().hasHeightForWidth());
    TLRayon->setSizePolicy(sizePolicy3);
    TLRayon->setWordWrap(false);

    gridLayout2->addWidget(TLRayon, 1, 2, 1, 1);

    TLZcentre = new QLabel(gBSphere);
    TLZcentre->setObjectName(QString::fromUtf8("TLZcentre"));
    QSizePolicy sizePolicy4(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(TLZcentre->sizePolicy().hasHeightForWidth());
    TLZcentre->setSizePolicy(sizePolicy4);
    TLZcentre->setWordWrap(false);

    gridLayout2->addWidget(TLZcentre, 2, 0, 1, 1);

    TLYcentre = new QLabel(gBSphere);
    TLYcentre->setObjectName(QString::fromUtf8("TLYcentre"));
    QSizePolicy sizePolicy5(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy5.setHorizontalStretch(0);
    sizePolicy5.setVerticalStretch(0);
    sizePolicy5.setHeightForWidth(TLYcentre->sizePolicy().hasHeightForWidth());
    TLYcentre->setSizePolicy(sizePolicy5);
    TLYcentre->setWordWrap(false);

    gridLayout2->addWidget(TLYcentre, 1, 0, 1, 1);

    SpinBox_Ycentre = new QDoubleSpinBox(gBSphere);
    SpinBox_Ycentre->setObjectName(QString::fromUtf8("SpinBox_Ycentre"));
    SpinBox_Ycentre->setDecimals(5);
    SpinBox_Ycentre->setMaximum(1e+09);
    SpinBox_Ycentre->setMinimum(-1e+09);
    SpinBox_Ycentre->setValue(0);

    gridLayout2->addWidget(SpinBox_Ycentre, 1, 1, 1, 1);

    SpinBox_Xcentre = new QDoubleSpinBox(gBSphere);
    SpinBox_Xcentre->setObjectName(QString::fromUtf8("SpinBox_Xcentre"));
    SpinBox_Xcentre->setDecimals(5);
    SpinBox_Xcentre->setMaximum(1e+09);
    SpinBox_Xcentre->setMinimum(-1e+09);
    SpinBox_Xcentre->setValue(0);

    gridLayout2->addWidget(SpinBox_Xcentre, 0, 1, 1, 1);

    TLXcentre = new QLabel(gBSphere);
    TLXcentre->setObjectName(QString::fromUtf8("TLXcentre"));
    QSizePolicy sizePolicy6(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy6.setHorizontalStretch(0);
    sizePolicy6.setVerticalStretch(0);
    sizePolicy6.setHeightForWidth(TLXcentre->sizePolicy().hasHeightForWidth());
    TLXcentre->setSizePolicy(sizePolicy6);
    TLXcentre->setWordWrap(false);

    gridLayout2->addWidget(TLXcentre, 0, 0, 1, 1);


    gridLayout->addWidget(gBSphere, 3, 0, 1, 2);

    gBCylindre = new QGroupBox(CreateBoundaryAn);
    gBCylindre->setObjectName(QString::fromUtf8("gBCylindre"));
    QSizePolicy sizePolicy7(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy7.setHorizontalStretch(0);
    sizePolicy7.setVerticalStretch(0);
    sizePolicy7.setHeightForWidth(gBCylindre->sizePolicy().hasHeightForWidth());
    gBCylindre->setSizePolicy(sizePolicy7);
    gridLayout3 = new QGridLayout(gBCylindre);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(9);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    SpinBox_Xcent = new QDoubleSpinBox(gBCylindre);
    SpinBox_Xcent->setObjectName(QString::fromUtf8("SpinBox_Xcent"));
    SpinBox_Xcent->setDecimals(5);
    SpinBox_Xcent->setMaximum(1e+09);
    SpinBox_Xcent->setMinimum(-1e+09);
    SpinBox_Xcent->setValue(0);

    gridLayout3->addWidget(SpinBox_Xcent, 0, 1, 1, 1);

    TLXcent = new QLabel(gBCylindre);
    TLXcent->setObjectName(QString::fromUtf8("TLXcent"));
    QSizePolicy sizePolicy8(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy8.setHorizontalStretch(0);
    sizePolicy8.setVerticalStretch(0);
    sizePolicy8.setHeightForWidth(TLXcent->sizePolicy().hasHeightForWidth());
    TLXcent->setSizePolicy(sizePolicy8);
    TLXcent->setWordWrap(false);

    gridLayout3->addWidget(TLXcent, 0, 0, 1, 1);

    SpinBox_Radius = new QDoubleSpinBox(gBCylindre);
    SpinBox_Radius->setObjectName(QString::fromUtf8("SpinBox_Radius"));
    SpinBox_Radius->setDecimals(5);
    SpinBox_Radius->setMaximum(1e+09);

    gridLayout3->addWidget(SpinBox_Radius, 3, 1, 1, 2);

    SpinBox_Zcent = new QDoubleSpinBox(gBCylindre);
    SpinBox_Zcent->setObjectName(QString::fromUtf8("SpinBox_Zcent"));
    SpinBox_Zcent->setDecimals(5);
    SpinBox_Zcent->setMaximum(1e+09);
    SpinBox_Zcent->setMinimum(-1e+09);
    SpinBox_Zcent->setValue(0);

    gridLayout3->addWidget(SpinBox_Zcent, 2, 1, 1, 1);

    TLradius = new QLabel(gBCylindre);
    TLradius->setObjectName(QString::fromUtf8("TLradius"));
    QSizePolicy sizePolicy9(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy9.setHorizontalStretch(0);
    sizePolicy9.setVerticalStretch(0);
    sizePolicy9.setHeightForWidth(TLradius->sizePolicy().hasHeightForWidth());
    TLradius->setSizePolicy(sizePolicy9);
    TLradius->setWordWrap(false);

    gridLayout3->addWidget(TLradius, 3, 0, 1, 1);

    TLZcent = new QLabel(gBCylindre);
    TLZcent->setObjectName(QString::fromUtf8("TLZcent"));
    QSizePolicy sizePolicy10(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy10.setHorizontalStretch(0);
    sizePolicy10.setVerticalStretch(0);
    sizePolicy10.setHeightForWidth(TLZcent->sizePolicy().hasHeightForWidth());
    TLZcent->setSizePolicy(sizePolicy10);
    TLZcent->setWordWrap(false);

    gridLayout3->addWidget(TLZcent, 2, 0, 1, 1);

    TLYcent = new QLabel(gBCylindre);
    TLYcent->setObjectName(QString::fromUtf8("TLYcent"));
    QSizePolicy sizePolicy11(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy11.setHorizontalStretch(0);
    sizePolicy11.setVerticalStretch(0);
    sizePolicy11.setHeightForWidth(TLYcent->sizePolicy().hasHeightForWidth());
    TLYcent->setSizePolicy(sizePolicy11);
    TLYcent->setWordWrap(false);

    gridLayout3->addWidget(TLYcent, 1, 0, 1, 1);

    SpinBox_Ycent = new QDoubleSpinBox(gBCylindre);
    SpinBox_Ycent->setObjectName(QString::fromUtf8("SpinBox_Ycent"));
    SpinBox_Ycent->setDecimals(5);
    SpinBox_Ycent->setMaximum(1e+09);
    SpinBox_Ycent->setMinimum(-1e+09);
    SpinBox_Ycent->setValue(0);

    gridLayout3->addWidget(SpinBox_Ycent, 1, 1, 1, 1);

    TLXaxis = new QLabel(gBCylindre);
    TLXaxis->setObjectName(QString::fromUtf8("TLXaxis"));
    QSizePolicy sizePolicy12(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy12.setHorizontalStretch(0);
    sizePolicy12.setVerticalStretch(0);
    sizePolicy12.setHeightForWidth(TLXaxis->sizePolicy().hasHeightForWidth());
    TLXaxis->setSizePolicy(sizePolicy12);
    TLXaxis->setWordWrap(false);

    gridLayout3->addWidget(TLXaxis, 0, 2, 1, 1);

    TLYaxis = new QLabel(gBCylindre);
    TLYaxis->setObjectName(QString::fromUtf8("TLYaxis"));
    QSizePolicy sizePolicy13(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy13.setHorizontalStretch(0);
    sizePolicy13.setVerticalStretch(0);
    sizePolicy13.setHeightForWidth(TLYaxis->sizePolicy().hasHeightForWidth());
    TLYaxis->setSizePolicy(sizePolicy13);
    TLYaxis->setWordWrap(false);

    gridLayout3->addWidget(TLYaxis, 1, 2, 1, 1);

    TLZaxis = new QLabel(gBCylindre);
    TLZaxis->setObjectName(QString::fromUtf8("TLZaxis"));
    QSizePolicy sizePolicy14(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy14.setHorizontalStretch(0);
    sizePolicy14.setVerticalStretch(0);
    sizePolicy14.setHeightForWidth(TLZaxis->sizePolicy().hasHeightForWidth());
    TLZaxis->setSizePolicy(sizePolicy14);
    TLZaxis->setWordWrap(false);

    gridLayout3->addWidget(TLZaxis, 2, 2, 1, 1);

    SpinBox_Zaxis = new QDoubleSpinBox(gBCylindre);
    SpinBox_Zaxis->setObjectName(QString::fromUtf8("SpinBox_Zaxis"));
    SpinBox_Zaxis->setDecimals(5);
    SpinBox_Zaxis->setMaximum(1e+09);
    SpinBox_Zaxis->setMinimum(-1e+09);
    SpinBox_Zaxis->setValue(0);

    gridLayout3->addWidget(SpinBox_Zaxis, 2, 3, 1, 1);

    SpinBox_Yaxis = new QDoubleSpinBox(gBCylindre);
    SpinBox_Yaxis->setObjectName(QString::fromUtf8("SpinBox_Yaxis"));
    SpinBox_Yaxis->setDecimals(5);
    SpinBox_Yaxis->setMaximum(1e+09);
    SpinBox_Yaxis->setMinimum(-1e+09);
    SpinBox_Yaxis->setValue(0);

    gridLayout3->addWidget(SpinBox_Yaxis, 1, 3, 1, 1);

    SpinBox_Xaxis = new QDoubleSpinBox(gBCylindre);
    SpinBox_Xaxis->setObjectName(QString::fromUtf8("SpinBox_Xaxis"));
    SpinBox_Xaxis->setDecimals(5);
    SpinBox_Xaxis->setMaximum(1e+09);
    SpinBox_Xaxis->setMinimum(-1e+09);
    SpinBox_Xaxis->setValue(0);

    gridLayout3->addWidget(SpinBox_Xaxis, 0, 3, 1, 1);


    gridLayout->addWidget(gBCylindre, 2, 0, 1, 2);


    retranslateUi(CreateBoundaryAn);

    QSize size(458, 500);
    size = size.expandedTo(CreateBoundaryAn->minimumSizeHint());
    CreateBoundaryAn->resize(size);


    QMetaObject::connectSlotsByName(CreateBoundaryAn);
    } // setupUi

    void retranslateUi(QDialog *CreateBoundaryAn)
    {
    CreateBoundaryAn->setWindowTitle(QApplication::translate("CreateBoundaryAn", "Create an analytical boundary", 0, QApplication::UnicodeUTF8));
    GBButtons->setTitle(QString());
    buttonHelp->setText(QApplication::translate("CreateBoundaryAn", "Help", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateBoundaryAn", "Cancel", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateBoundaryAn", "Apply", 0, QApplication::UnicodeUTF8));
    buttonOk->setText(QApplication::translate("CreateBoundaryAn", "OK", 0, QApplication::UnicodeUTF8));
    Name->setText(QApplication::translate("CreateBoundaryAn", "Name", 0, QApplication::UnicodeUTF8));
    TypeBoundary->setTitle(QApplication::translate("CreateBoundaryAn", "Type of boundary", 0, QApplication::UnicodeUTF8));
    RBCylindre->setText(QApplication::translate("CreateBoundaryAn", "Cylinder", 0, QApplication::UnicodeUTF8));
    RBSphere->setText(QApplication::translate("CreateBoundaryAn", "Sphere", 0, QApplication::UnicodeUTF8));
    gBSphere->setTitle(QApplication::translate("CreateBoundaryAn", "Coordinates", 0, QApplication::UnicodeUTF8));
    TLRayon->setText(QApplication::translate("CreateBoundaryAn", "Radius", 0, QApplication::UnicodeUTF8));
    TLZcentre->setText(QApplication::translate("CreateBoundaryAn", "Z centre", 0, QApplication::UnicodeUTF8));
    TLYcentre->setText(QApplication::translate("CreateBoundaryAn", "Y centre", 0, QApplication::UnicodeUTF8));
    TLXcentre->setText(QApplication::translate("CreateBoundaryAn", "X centre", 0, QApplication::UnicodeUTF8));
    gBCylindre->setTitle(QApplication::translate("CreateBoundaryAn", "Coordinates", 0, QApplication::UnicodeUTF8));
    TLXcent->setText(QApplication::translate("CreateBoundaryAn", "X centre", 0, QApplication::UnicodeUTF8));
    TLradius->setText(QApplication::translate("CreateBoundaryAn", "Radius", 0, QApplication::UnicodeUTF8));
    TLZcent->setText(QApplication::translate("CreateBoundaryAn", "Z centre", 0, QApplication::UnicodeUTF8));
    TLYcent->setText(QApplication::translate("CreateBoundaryAn", "Y centre", 0, QApplication::UnicodeUTF8));
    TLXaxis->setText(QApplication::translate("CreateBoundaryAn", "X axis", 0, QApplication::UnicodeUTF8));
    TLYaxis->setText(QApplication::translate("CreateBoundaryAn", "Y axis", 0, QApplication::UnicodeUTF8));
    TLZaxis->setText(QApplication::translate("CreateBoundaryAn", "Z axis", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CreateBoundaryAn);
    } // retranslateUi

};

namespace Ui {
    class CreateBoundaryAn: public Ui_CreateBoundaryAn {};
} // namespace Ui

#endif // CREATEBOUNDARYAN_H
