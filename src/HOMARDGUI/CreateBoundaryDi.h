/********************************************************************************
** Form generated from reading ui file 'CreateBoundaryDi.ui'
**
** Created: Thu Sep 1 16:37:21 2011
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef CREATEBOUNDARYDI_H
#define CREATEBOUNDARYDI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

class Ui_CreateBoundaryDi
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonHelp;
    QPushButton *buttonCancel;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QCheckBox *CBGroupe;
    QLineEdit *LEFileName;
    QPushButton *PushFichier;
    QLabel *Mesh;
    QLineEdit *LEBoundaryName;
    QLabel *Name;

    void setupUi(QDialog *CreateBoundaryDi)
    {
    CreateBoundaryDi->setObjectName(QString::fromUtf8("CreateBoundaryDi"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(CreateBoundaryDi->sizePolicy().hasHeightForWidth());
    CreateBoundaryDi->setSizePolicy(sizePolicy);
    CreateBoundaryDi->setAutoFillBackground(true);
    CreateBoundaryDi->setSizeGripEnabled(true);
    gridLayout = new QGridLayout(CreateBoundaryDi);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    GBButtons = new QGroupBox(CreateBoundaryDi);
    GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
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


    gridLayout->addWidget(GBButtons, 3, 0, 1, 3);

    CBGroupe = new QCheckBox(CreateBoundaryDi);
    CBGroupe->setObjectName(QString::fromUtf8("CBGroupe"));

    gridLayout->addWidget(CBGroupe, 2, 0, 1, 3);

    LEFileName = new QLineEdit(CreateBoundaryDi);
    LEFileName->setObjectName(QString::fromUtf8("LEFileName"));
    LEFileName->setMinimumSize(QSize(370, 21));

    gridLayout->addWidget(LEFileName, 1, 2, 1, 1);

    PushFichier = new QPushButton(CreateBoundaryDi);
    PushFichier->setObjectName(QString::fromUtf8("PushFichier"));

    gridLayout->addWidget(PushFichier, 1, 1, 1, 1);

    Mesh = new QLabel(CreateBoundaryDi);
    Mesh->setObjectName(QString::fromUtf8("Mesh"));

    gridLayout->addWidget(Mesh, 1, 0, 1, 1);

    LEBoundaryName = new QLineEdit(CreateBoundaryDi);
    LEBoundaryName->setObjectName(QString::fromUtf8("LEBoundaryName"));
    LEBoundaryName->setMinimumSize(QSize(382, 21));
    LEBoundaryName->setMaxLength(32);

    gridLayout->addWidget(LEBoundaryName, 0, 1, 1, 2);

    Name = new QLabel(CreateBoundaryDi);
    Name->setObjectName(QString::fromUtf8("Name"));

    gridLayout->addWidget(Name, 0, 0, 1, 1);


    retranslateUi(CreateBoundaryDi);

    QSize size(566, 169);
    size = size.expandedTo(CreateBoundaryDi->minimumSizeHint());
    CreateBoundaryDi->resize(size);


    QMetaObject::connectSlotsByName(CreateBoundaryDi);
    } // setupUi

    void retranslateUi(QDialog *CreateBoundaryDi)
    {
    CreateBoundaryDi->setWindowTitle(QApplication::translate("CreateBoundaryDi", "Create a discrete boundary", 0, QApplication::UnicodeUTF8));
    GBButtons->setTitle(QString());
    buttonHelp->setText(QApplication::translate("CreateBoundaryDi", "Help", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateBoundaryDi", "Cancel", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateBoundaryDi", "Apply", 0, QApplication::UnicodeUTF8));
    buttonOk->setText(QApplication::translate("CreateBoundaryDi", "OK", 0, QApplication::UnicodeUTF8));
    CBGroupe->setText(QApplication::translate("CreateBoundaryDi", "Filtering with groups", 0, QApplication::UnicodeUTF8));
    PushFichier->setText(QString());
    Mesh->setText(QApplication::translate("CreateBoundaryDi", "Mesh", 0, QApplication::UnicodeUTF8));
    Name->setText(QApplication::translate("CreateBoundaryDi", "Name", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CreateBoundaryDi);
    } // retranslateUi

};

namespace Ui {
    class CreateBoundaryDi: public Ui_CreateBoundaryDi {};
} // namespace Ui

#endif // CREATEBOUNDARYDI_H
