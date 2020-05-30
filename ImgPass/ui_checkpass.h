/********************************************************************************
** Form generated from reading UI file 'checkpass.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKPASS_H
#define UI_CHECKPASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CheckPass
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *lblPass;
    QPushButton *btnDecipher;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *CheckPass)
    {
        if (CheckPass->objectName().isEmpty())
            CheckPass->setObjectName(QString::fromUtf8("CheckPass"));
        CheckPass->resize(400, 300);
        lineEdit = new QLineEdit(CheckPass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 180, 371, 21));
        label = new QLabel(CheckPass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 160, 101, 16));
        label_2 = new QLabel(CheckPass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 240, 51, 16));
        lblPass = new QLabel(CheckPass);
        lblPass->setObjectName(QString::fromUtf8("lblPass"));
        lblPass->setGeometry(QRect(70, 240, 47, 13));
        btnDecipher = new QPushButton(CheckPass);
        btnDecipher->setObjectName(QString::fromUtf8("btnDecipher"));
        btnDecipher->setGeometry(QRect(10, 210, 80, 21));
        label_3 = new QLabel(CheckPass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 361, 16));
        label_4 = new QLabel(CheckPass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 361, 16));
        label_5 = new QLabel(CheckPass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 50, 361, 16));

        retranslateUi(CheckPass);

        QMetaObject::connectSlotsByName(CheckPass);
    } // setupUi

    void retranslateUi(QDialog *CheckPass)
    {
        CheckPass->setWindowTitle(QCoreApplication::translate("CheckPass", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CheckPass", "Password ciphered:", nullptr));
        label_2->setText(QCoreApplication::translate("CheckPass", "Password:", nullptr));
        lblPass->setText(QString());
        btnDecipher->setText(QCoreApplication::translate("CheckPass", "Convert", nullptr));
        label_3->setText(QCoreApplication::translate("CheckPass", "Open image with hex editor and at last part will be something like:", nullptr));
        label_4->setText(QCoreApplication::translate("CheckPass", "\313\231\313\231\313\231EFGHIJKLMD..", nullptr));
        label_5->setText(QCoreApplication::translate("CheckPass", "Paste to textbox only part \"EFGHIJKLMD\" and click Convert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckPass: public Ui_CheckPass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKPASS_H
