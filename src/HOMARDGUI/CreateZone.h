/********************************************************************************
** Form generated from reading ui file 'CreateZone.ui'
**
** Created: Thu Feb 24 09:10:36 2011
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

class Ui_CreateZone
{
public:
    QGridLayout *gridLayout;
    QLabel *Name;
    QLineEdit *LEZoneName;
    QGroupBox *TypeZone;
    QHBoxLayout *hboxLayout;
    QRadioButton *RBBox;
    QRadioButton *RBSphere;
    QGroupBox *gBBox;
    QGridLayout *gridLayout1;
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
    QGroupBox *gBSphere;
    QGridLayout *gridLayout2;
    QLabel *TLXcentre;
    QDoubleSpinBox *SpinBox_Xcentre;
    QLabel *TLYcentre;
    QDoubleSpinBox *SpinBox_Ycentre;
    QLabel *TLRayon;
    QDoubleSpinBox *SpinBox_Rayon;
    QLabel *TLZcentre;
    QDoubleSpinBox *SpinBox_Zcentre;
    QGroupBox *GBButtons;
    QHBoxLayout *hboxLayout1;
    QPushButton *buttonOk;
    QPushButton *buttonApply;
    QPushButton *buttonCancel;
    QPushButton *buttonHelp;

    void setupUi(QDialog *CreateZone)
    {
    CreateZone->setObjectName(QString::fromUtf8("CreateZone"));
    CreateZone->setAutoFillBackground(true);
    CreateZone->setSizeGripEnabled(true);
    gridLayout = new QGridLayout(CreateZone);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    Name = new QLabel(CreateZone);
    Name->setObjectName(QString::fromUtf8("Name"));

    gridLayout->addWidget(Name, 0, 0, 1, 1);

    LEZoneName = new QLineEdit(CreateZone);
    LEZoneName->setObjectName(QString::fromUtf8("LEZoneName"));
    LEZoneName->setMaxLength(32);

    gridLayout->addWidget(LEZoneName, 0, 1, 1, 1);

    TypeZone = new QGroupBox(CreateZone);
    TypeZone->setObjectName(QString::fromUtf8("TypeZone"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(TypeZone->sizePolicy().hasHeightForWidth());
    TypeZone->setSizePolicy(sizePolicy);
    TypeZone->setMinimumSize(QSize(340, 0));
    hboxLayout = new QHBoxLayout(TypeZone);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(9);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    RBBox = new QRadioButton(TypeZone);
    RBBox->setObjectName(QString::fromUtf8("RBBox"));
    RBBox->setIcon(QIcon(QString::fromUtf8("../../resources/zone_boxdxyz.png")));
    RBBox->setCheckable(true);
    RBBox->setChecked(true);

    hboxLayout->addWidget(RBBox);

    RBSphere = new QRadioButton(TypeZone);
    RBSphere->setObjectName(QString::fromUtf8("RBSphere"));
    RBSphere->setIcon(QIcon(QString::fromUtf8("../../resources/zone_spherepoint.png")));

    hboxLayout->addWidget(RBSphere);


    gridLayout->addWidget(TypeZone, 1, 0, 1, 2);

    gBBox = new QGroupBox(CreateZone);
    gBBox->setObjectName(QString::fromUtf8("gBBox"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(gBBox->sizePolicy().hasHeightForWidth());
    gBBox->setSizePolicy(sizePolicy1);
    gridLayout1 = new QGridLayout(gBBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    TLXmini = new QLabel(gBBox);
    TLXmini->setObjectName(QString::fromUtf8("TLXmini"));
    QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(TLXmini->sizePolicy().hasHeightForWidth());
    TLXmini->setSizePolicy(sizePolicy2);
    TLXmini->setWordWrap(false);

    gridLayout1->addWidget(TLXmini, 0, 0, 1, 1);

    SpinBox_Xmini = new QDoubleSpinBox(gBBox);
    SpinBox_Xmini->setObjectName(QString::fromUtf8("SpinBox_Xmini"));
    SpinBox_Xmini->setDecimals(5);
    SpinBox_Xmini->setMaximum(1e+09);
    SpinBox_Xmini->setMinimum(-1e+09);
    SpinBox_Xmini->setValue(0);

    gridLayout1->addWidget(SpinBox_Xmini, 0, 1, 1, 1);

    TLYmini = new QLabel(gBBox);
    TLYmini->setObjectName(QString::fromUtf8("TLYmini"));
    QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(TLYmini->sizePolicy().hasHeightForWidth());
    TLYmini->setSizePolicy(sizePolicy3);
    TLYmini->setWordWrap(false);

    gridLayout1->addWidget(TLYmini, 1, 0, 1, 1);

    SpinBox_Ymini = new QDoubleSpinBox(gBBox);
    SpinBox_Ymini->setObjectName(QString::fromUtf8("SpinBox_Ymini"));
    SpinBox_Ymini->setDecimals(5);
    SpinBox_Ymini->setMaximum(1e+09);
    SpinBox_Ymini->setMinimum(-1e+09);
    SpinBox_Ymini->setValue(0);

    gridLayout1->addWidget(SpinBox_Ymini, 1, 1, 1, 1);

    TLZmini = new QLabel(gBBox);
    TLZmini->setObjectName(QString::fromUtf8("TLZmini"));
    QSizePolicy sizePolicy4(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(TLZmini->sizePolicy().hasHeightForWidth());
    TLZmini->setSizePolicy(sizePolicy4);
    TLZmini->setWordWrap(false);

    gridLayout1->addWidget(TLZmini, 2, 0, 1, 1);

    SpinBox_Zmini = new QDoubleSpinBox(gBBox);
    SpinBox_Zmini->setObjectName(QString::fromUtf8("SpinBox_Zmini"));
    SpinBox_Zmini->setDecimals(5);
    SpinBox_Zmini->setMaximum(1e+09);
    SpinBox_Zmini->setMinimum(-1e+09);
    SpinBox_Zmini->setValue(0);

    gridLayout1->addWidget(SpinBox_Zmini, 2, 1, 1, 1);

    TLXmaxi = new QLabel(gBBox);
    TLXmaxi->setObjectName(QString::fromUtf8("TLXmaxi"));
    QSizePolicy sizePolicy5(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy5.setHorizontalStretch(0);
    sizePolicy5.setVerticalStretch(0);
    sizePolicy5.setHeightForWidth(TLXmaxi->sizePolicy().hasHeightForWidth());
    TLXmaxi->setSizePolicy(sizePolicy5);
    TLXmaxi->setWordWrap(false);

    gridLayout1->addWidget(TLXmaxi, 0, 2, 1, 1);

    TLZmaxi = new QLabel(gBBox);
    TLZmaxi->setObjectName(QString::fromUtf8("TLZmaxi"));
    QSizePolicy sizePolicy6(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy6.setHorizontalStretch(0);
    sizePolicy6.setVerticalStretch(0);
    sizePolicy6.setHeightForWidth(TLZmaxi->sizePolicy().hasHeightForWidth());
    TLZmaxi->setSizePolicy(sizePolicy6);
    TLZmaxi->setWordWrap(false);

    gridLayout1->addWidget(TLZmaxi, 2, 2, 1, 1);

    SpinBox_Zmaxi = new QDoubleSpinBox(gBBox);
    SpinBox_Zmaxi->setObjectName(QString::fromUtf8("SpinBox_Zmaxi"));
    SpinBox_Zmaxi->setDecimals(5);
    SpinBox_Zmaxi->setMaximum(1e+09);
    SpinBox_Zmaxi->setMinimum(-1e+09);
    SpinBox_Zmaxi->setValue(0);

    gridLayout1->addWidget(SpinBox_Zmaxi, 2, 3, 1, 1);

    TLYmaxi = new QLabel(gBBox);
    TLYmaxi->setObjectName(QString::fromUtf8("TLYmaxi"));
    QSizePolicy sizePolicy7(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy7.setHorizontalStretch(0);
    sizePolicy7.setVerticalStretch(0);
    sizePolicy7.setHeightForWidth(TLYmaxi->sizePolicy().hasHeightForWidth());
    TLYmaxi->setSizePolicy(sizePolicy7);
    TLYmaxi->setWordWrap(false);

    gridLayout1->addWidget(TLYmaxi, 1, 2, 1, 1);

    SpinBox_Xmaxi = new QDoubleSpinBox(gBBox);
    SpinBox_Xmaxi->setObjectName(QString::fromUtf8("SpinBox_Xmaxi"));
    SpinBox_Xmaxi->setDecimals(5);
    SpinBox_Xmaxi->setMaximum(1e+09);
    SpinBox_Xmaxi->setMinimum(-1e+09);
    SpinBox_Xmaxi->setValue(0);

    gridLayout1->addWidget(SpinBox_Xmaxi, 0, 3, 1, 1);

    SpinBox_Ymaxi = new QDoubleSpinBox(gBBox);
    SpinBox_Ymaxi->setObjectName(QString::fromUtf8("SpinBox_Ymaxi"));
    SpinBox_Ymaxi->setDecimals(5);
    SpinBox_Ymaxi->setMaximum(1e+09);
    SpinBox_Ymaxi->setMinimum(-1e+09);
    SpinBox_Ymaxi->setValue(0);

    gridLayout1->addWidget(SpinBox_Ymaxi, 1, 3, 1, 1);


    gridLayout->addWidget(gBBox, 2, 0, 1, 2);

    gBSphere = new QGroupBox(CreateZone);
    gBSphere->setObjectName(QString::fromUtf8("gBSphere"));
    QSizePolicy sizePolicy8(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy8.setHorizontalStretch(0);
    sizePolicy8.setVerticalStretch(0);
    sizePolicy8.setHeightForWidth(gBSphere->sizePolicy().hasHeightForWidth());
    gBSphere->setSizePolicy(sizePolicy8);
    gridLayout2 = new QGridLayout(gBSphere);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    TLXcentre = new QLabel(gBSphere);
    TLXcentre->setObjectName(QString::fromUtf8("TLXcentre"));
    QSizePolicy sizePolicy9(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy9.setHorizontalStretch(0);
    sizePolicy9.setVerticalStretch(0);
    sizePolicy9.setHeightForWidth(TLXcentre->sizePolicy().hasHeightForWidth());
    TLXcentre->setSizePolicy(sizePolicy9);
    TLXcentre->setWordWrap(false);

    gridLayout2->addWidget(TLXcentre, 0, 0, 1, 1);

    SpinBox_Xcentre = new QDoubleSpinBox(gBSphere);
    SpinBox_Xcentre->setObjectName(QString::fromUtf8("SpinBox_Xcentre"));
    SpinBox_Xcentre->setDecimals(5);
    SpinBox_Xcentre->setMaximum(1e+09);
    SpinBox_Xcentre->setMinimum(-1e+09);
    SpinBox_Xcentre->setValue(0);

    gridLayout2->addWidget(SpinBox_Xcentre, 0, 1, 1, 1);

    TLYcentre = new QLabel(gBSphere);
    TLYcentre->setObjectName(QString::fromUtf8("TLYcentre"));
    QSizePolicy sizePolicy10(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy10.setHorizontalStretch(0);
    sizePolicy10.setVerticalStretch(0);
    sizePolicy10.setHeightForWidth(TLYcentre->sizePolicy().hasHeightForWidth());
    TLYcentre->setSizePolicy(sizePolicy10);
    TLYcentre->setWordWrap(false);

    gridLayout2->addWidget(TLYcentre, 1, 0, 1, 1);

    SpinBox_Ycentre = new QDoubleSpinBox(gBSphere);
    SpinBox_Ycentre->setObjectName(QString::fromUtf8("SpinBox_Ycentre"));
    SpinBox_Ycentre->setDecimals(5);
    SpinBox_Ycentre->setMaximum(1e+09);
    SpinBox_Ycentre->setMinimum(-1e+09);
    SpinBox_Ycentre->setValue(0);

    gridLayout2->addWidget(SpinBox_Ycentre, 1, 1, 1, 1);

    TLRayon = new QLabel(gBSphere);
    TLRayon->setObjectName(QString::fromUtf8("TLRayon"));
    QSizePolicy sizePolicy11(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy11.setHorizontalStretch(0);
    sizePolicy11.setVerticalStretch(0);
    sizePolicy11.setHeightForWidth(TLRayon->sizePolicy().hasHeightForWidth());
    TLRayon->setSizePolicy(sizePolicy11);
    TLRayon->setWordWrap(false);

    gridLayout2->addWidget(TLRayon, 1, 2, 1, 1);

    SpinBox_Rayon = new QDoubleSpinBox(gBSphere);
    SpinBox_Rayon->setObjectName(QString::fromUtf8("SpinBox_Rayon"));
    SpinBox_Rayon->setDecimals(5);
    SpinBox_Rayon->setMaximum(1e+09);
    SpinBox_Rayon->setMinimum(-1e+09);
    SpinBox_Rayon->setValue(0);

    gridLayout2->addWidget(SpinBox_Rayon, 1, 3, 1, 1);

    TLZcentre = new QLabel(gBSphere);
    TLZcentre->setObjectName(QString::fromUtf8("TLZcentre"));
    QSizePolicy sizePolicy12(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy12.setHorizontalStretch(0);
    sizePolicy12.setVerticalStretch(0);
    sizePolicy12.setHeightForWidth(TLZcentre->sizePolicy().hasHeightForWidth());
    TLZcentre->setSizePolicy(sizePolicy12);
    TLZcentre->setWordWrap(false);

    gridLayout2->addWidget(TLZcentre, 2, 0, 1, 1);

    SpinBox_Zcentre = new QDoubleSpinBox(gBSphere);
    SpinBox_Zcentre->setObjectName(QString::fromUtf8("SpinBox_Zcentre"));
    SpinBox_Zcentre->setDecimals(5);
    SpinBox_Zcentre->setMaximum(1e+09);
    SpinBox_Zcentre->setMinimum(-1e+09);
    SpinBox_Zcentre->setValue(0);

    gridLayout2->addWidget(SpinBox_Zcentre, 2, 1, 1, 1);


    gridLayout->addWidget(gBSphere, 3, 0, 1, 2);

    GBButtons = new QGroupBox(CreateZone);
    GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
    QSizePolicy sizePolicy13(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy13.setHorizontalStretch(0);
    sizePolicy13.setVerticalStretch(0);
    sizePolicy13.setHeightForWidth(GBButtons->sizePolicy().hasHeightForWidth());
    GBButtons->setSizePolicy(sizePolicy13);
    hboxLayout1 = new QHBoxLayout(GBButtons);
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(9);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    buttonOk = new QPushButton(GBButtons);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

    hboxLayout1->addWidget(buttonOk);

    buttonApply = new QPushButton(GBButtons);
    buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

    hboxLayout1->addWidget(buttonApply);

    buttonCancel = new QPushButton(GBButtons);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

    hboxLayout1->addWidget(buttonCancel);

    buttonHelp = new QPushButton(GBButtons);
    buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

    hboxLayout1->addWidget(buttonHelp);


    gridLayout->addWidget(GBButtons, 4, 0, 1, 2);


    retranslateUi(CreateZone);

    QSize size(454, 472);
    size = size.expandedTo(CreateZone->minimumSizeHint());
    CreateZone->resize(size);


    QMetaObject::connectSlotsByName(CreateZone);
    } // setupUi

    void retranslateUi(QDialog *CreateZone)
    {
    CreateZone->setWindowTitle(QApplication::translate("CreateZone", "Create a zone", 0, QApplication::UnicodeUTF8));
    Name->setText(QApplication::translate("CreateZone", "Name", 0, QApplication::UnicodeUTF8));
    TypeZone->setTitle(QApplication::translate("CreateZone", "Type of zone", 0, QApplication::UnicodeUTF8));
    RBBox->setText(QString());
    RBSphere->setText(QString());
    gBBox->setTitle(QApplication::translate("CreateZone", "Coordinates", 0, QApplication::UnicodeUTF8));
    TLXmini->setText(QApplication::translate("CreateZone", "X mini", 0, QApplication::UnicodeUTF8));
    TLYmini->setText(QApplication::translate("CreateZone", "Y mini", 0, QApplication::UnicodeUTF8));
    TLZmini->setText(QApplication::translate("CreateZone", "Z mini", 0, QApplication::UnicodeUTF8));
    TLXmaxi->setText(QApplication::translate("CreateZone", "X maxi", 0, QApplication::UnicodeUTF8));
    TLZmaxi->setText(QApplication::translate("CreateZone", "Z maxi", 0, QApplication::UnicodeUTF8));
    TLYmaxi->setText(QApplication::translate("CreateZone", "Y maxi", 0, QApplication::UnicodeUTF8));
    gBSphere->setTitle(QApplication::translate("CreateZone", "Coordinates", 0, QApplication::UnicodeUTF8));
    TLXcentre->setText(QApplication::translate("CreateZone", "X centre", 0, QApplication::UnicodeUTF8));
    TLYcentre->setText(QApplication::translate("CreateZone", "Y centre", 0, QApplication::UnicodeUTF8));
    TLRayon->setText(QApplication::translate("CreateZone", "Radius", 0, QApplication::UnicodeUTF8));
    TLZcentre->setText(QApplication::translate("CreateZone", "Z centre", 0, QApplication::UnicodeUTF8));
    GBButtons->setTitle(QString());
    buttonOk->setText(QApplication::translate("CreateZone", "OK", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateZone", "Apply", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateZone", "Cancel", 0, QApplication::UnicodeUTF8));
    buttonHelp->setText(QApplication::translate("CreateZone", "Help", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CreateZone);
    } // retranslateUi

};

namespace Ui {
    class CreateZone: public Ui_CreateZone {};
} // namespace Ui

#endif // CREATEZONE_H
