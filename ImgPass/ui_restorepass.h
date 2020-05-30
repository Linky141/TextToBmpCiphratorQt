/********************************************************************************
** Form generated from reading UI file 'restorepass.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTOREPASS_H
#define UI_RESTOREPASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_restorepass
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *lblPass;
    QPushButton *btnDecipher;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *restorepass)
    {
        if (restorepass->objectName().isEmpty())
            restorepass->setObjectName(QString::fromUtf8("restorepass"));
        restorepass->resize(426, 327);
        centralwidget = new QWidget(restorepass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 160, 101, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 50, 361, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 361, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 361, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 180, 371, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 240, 51, 16));
        lblPass = new QLabel(centralwidget);
        lblPass->setObjectName(QString::fromUtf8("lblPass"));
        lblPass->setGeometry(QRect(70, 240, 311, 16));
        btnDecipher = new QPushButton(centralwidget);
        btnDecipher->setObjectName(QString::fromUtf8("btnDecipher"));
        btnDecipher->setGeometry(QRect(10, 210, 80, 21));
        restorepass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(restorepass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 426, 20));
        restorepass->setMenuBar(menubar);
        statusbar = new QStatusBar(restorepass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        restorepass->setStatusBar(statusbar);

        retranslateUi(restorepass);

        QMetaObject::connectSlotsByName(restorepass);
    } // setupUi

    void retranslateUi(QMainWindow *restorepass)
    {
        restorepass->setWindowTitle(QCoreApplication::translate("restorepass", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("restorepass", "Password ciphered:", nullptr));
        label_5->setText(QCoreApplication::translate("restorepass", "Paste to textbox only part \"EFGHIJKLMD\" and click Convert", nullptr));
        label_3->setText(QCoreApplication::translate("restorepass", "Open image with hex editor and at last part will be something like:", nullptr));
        label_4->setText(QCoreApplication::translate("restorepass", "\313\231\313\231\313\231EFGHIJKLMD..", nullptr));
        label_2->setText(QCoreApplication::translate("restorepass", "Password:", nullptr));
        lblPass->setText(QString());
        btnDecipher->setText(QCoreApplication::translate("restorepass", "Convert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class restorepass: public Ui_restorepass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTOREPASS_H
