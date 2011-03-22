/********************************************************************************
** Form generated from reading ui file 'EditFile.ui'
**
** Created: Tue Mar 15 10:38:58 2011
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef EDITFILE_H
#define EDITFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

class Ui_EditFile
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonPrint;
    QPushButton *buttonQuit;
    QSpacerItem *spacerItem1;
    QTextBrowser *QTBEditFile;

    void setupUi(QWidget *EditFile)
    {
    EditFile->setObjectName(QString::fromUtf8("EditFile"));
    gridLayout = new QGridLayout(EditFile);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    spacerItem = new QSpacerItem(331, 49, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(spacerItem, 2, 1, 1, 1);

    GroupButtons = new QGroupBox(EditFile);
    GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
    gridLayout1 = new QGridLayout(GroupButtons);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    buttonPrint = new QPushButton(GroupButtons);
    buttonPrint->setObjectName(QString::fromUtf8("buttonPrint"));

    gridLayout1->addWidget(buttonPrint, 0, 1, 1, 1);

    buttonQuit = new QPushButton(GroupButtons);
    buttonQuit->setObjectName(QString::fromUtf8("buttonQuit"));
    buttonQuit->setAutoDefault(true);
    buttonQuit->setDefault(true);
    buttonQuit->setFlat(true);

    gridLayout1->addWidget(buttonQuit, 0, 0, 1, 1);


    gridLayout->addWidget(GroupButtons, 2, 0, 1, 1);

    spacerItem1 = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem1, 1, 0, 1, 2);

    QTBEditFile = new QTextBrowser(EditFile);
    QTBEditFile->setObjectName(QString::fromUtf8("QTBEditFile"));
    QTBEditFile->setMinimumSize(QSize(530, 800));
    QFont font;
    font.setFamily(QString::fromUtf8("Courier New"));
    QTBEditFile->setFont(font);

    gridLayout->addWidget(QTBEditFile, 0, 0, 1, 2);


    retranslateUi(EditFile);

    QSize size(675, 901);
    size = size.expandedTo(EditFile->minimumSizeHint());
    EditFile->resize(size);


    QMetaObject::connectSlotsByName(EditFile);
    } // setupUi

    void retranslateUi(QWidget *EditFile)
    {
    EditFile->setWindowTitle(QApplication::translate("EditFile", "Edit a file", 0, QApplication::UnicodeUTF8));
    GroupButtons->setTitle(QString());
    buttonPrint->setText(QApplication::translate("EditFile", "Print", 0, QApplication::UnicodeUTF8));
    buttonQuit->setText(QApplication::translate("EditFile", "Quit", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(EditFile);
    } // retranslateUi

};

namespace Ui {
    class EditFile: public Ui_EditFile {};
} // namespace Ui

#endif // EDITFILE_H
