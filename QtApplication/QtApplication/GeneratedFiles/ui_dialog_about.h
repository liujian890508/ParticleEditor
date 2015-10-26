/********************************************************************************
** Form generated from reading UI file 'dialog_about.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ABOUT_H
#define UI_DIALOG_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_About
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_About)
    {
        if (Dialog_About->objectName().isEmpty())
            Dialog_About->setObjectName(QStringLiteral("Dialog_About"));
        Dialog_About->resize(392, 178);
        Dialog_About->setMinimumSize(QSize(392, 178));
        Dialog_About->setMaximumSize(QSize(392, 178));
        label = new QLabel(Dialog_About);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 144, 124));
        label->setStyleSheet(QStringLiteral(""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/QtApplication/Resources/icon/dialog.png")));
        label_2 = new QLabel(Dialog_About);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 20, 211, 20));
        label_3 = new QLabel(Dialog_About);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 40, 81, 20));
        label_4 = new QLabel(Dialog_About);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 70, 151, 16));
        label_5 = new QLabel(Dialog_About);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 90, 191, 20));
        label_6 = new QLabel(Dialog_About);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 120, 131, 16));
        pushButton = new QPushButton(Dialog_About);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 143, 75, 23));

        retranslateUi(Dialog_About);
        QObject::connect(pushButton, SIGNAL(clicked()), Dialog_About, SLOT(hide()));

        QMetaObject::connectSlotsByName(Dialog_About);
    } // setupUi

    void retranslateUi(QDialog *Dialog_About)
    {
        Dialog_About->setWindowTitle(QApplication::translate("Dialog_About", "About", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("Dialog_About", "Cocos2dx Particle Editor for Windows", 0));
        label_3->setText(QApplication::translate("Dialog_About", "Version 1.0.0", 0));
        label_4->setText(QApplication::translate("Dialog_About", "Copyright 2015 by Moxiang", 0));
        label_5->setText(QApplication::translate("Dialog_About", "Email: liujian890508@gmail.com", 0));
        label_6->setText(QApplication::translate("Dialog_About", "Welcome your feedbook", 0));
        pushButton->setText(QApplication::translate("Dialog_About", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_About: public Ui_Dialog_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ABOUT_H
