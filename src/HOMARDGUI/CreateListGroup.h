/********************************************************************************
** Form generated from reading ui file 'CreateListGroup.ui'
**
** Created: Thu Sep 1 16:35:32 2011
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef CREATELISTGROUP_H
#define CREATELISTGROUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

class Ui_CreateListGroup
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonHelp;
    QPushButton *buttonCancel;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QGroupBox *GBOptions;
    QGridLayout *gridLayout2;
    QTableWidget *TWGroupe;

    void setupUi(QDialog *CreateListGroup)
    {
    CreateListGroup->setObjectName(QString::fromUtf8("CreateListGroup"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(CreateListGroup->sizePolicy().hasHeightForWidth());
    CreateListGroup->setSizePolicy(sizePolicy);
    CreateListGroup->setAutoFillBackground(true);
    CreateListGroup->setSizeGripEnabled(true);
    gridLayout = new QGridLayout(CreateListGroup);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    GBButtons = new QGroupBox(CreateListGroup);
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


    gridLayout->addWidget(GBButtons, 1, 0, 1, 1);

    GBOptions = new QGroupBox(CreateListGroup);
    GBOptions->setObjectName(QString::fromUtf8("GBOptions"));
    gridLayout2 = new QGridLayout(GBOptions);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    TWGroupe = new QTableWidget(GBOptions);
    TWGroupe->setObjectName(QString::fromUtf8("TWGroupe"));
    TWGroupe->setShowGrid(true);
    TWGroupe->setRowCount(0);
    TWGroupe->setColumnCount(2);

    gridLayout2->addWidget(TWGroupe, 0, 0, 1, 1);


    gridLayout->addWidget(GBOptions, 0, 0, 1, 1);


    retranslateUi(CreateListGroup);

    QSize size(717, 600);
    size = size.expandedTo(CreateListGroup->minimumSizeHint());
    CreateListGroup->resize(size);


    QMetaObject::connectSlotsByName(CreateListGroup);
    } // setupUi

    void retranslateUi(QDialog *CreateListGroup)
    {
    CreateListGroup->setWindowTitle(QApplication::translate("CreateListGroup", "Selection of groups", 0, QApplication::UnicodeUTF8));
    GBButtons->setTitle(QString());
    buttonHelp->setText(QApplication::translate("CreateListGroup", "Help", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateListGroup", "Cancel", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateListGroup", "Apply", 0, QApplication::UnicodeUTF8));
    buttonOk->setText(QApplication::translate("CreateListGroup", "OK", 0, QApplication::UnicodeUTF8));
    GBOptions->setTitle(QApplication::translate("CreateListGroup", "Selected groups", 0, QApplication::UnicodeUTF8));
    if (TWGroupe->columnCount() < 2)
        TWGroupe->setColumnCount(2);

    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("CreateListGroup", "Selection", 0, QApplication::UnicodeUTF8));
    TWGroupe->setHorizontalHeaderItem(0, __colItem);

    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    __colItem1->setText(QApplication::translate("CreateListGroup", "Group", 0, QApplication::UnicodeUTF8));
    TWGroupe->setHorizontalHeaderItem(1, __colItem1);
    Q_UNUSED(CreateListGroup);
    } // retranslateUi

};

namespace Ui {
    class CreateListGroup: public Ui_CreateListGroup {};
} // namespace Ui

#endif // CREATELISTGROUP_H
