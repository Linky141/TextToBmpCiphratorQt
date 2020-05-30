/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *SourceFileSelectButton;
    QPushButton *EncryptButton;
    QSpinBox *CezarNumberSpinBox;
    QLineEdit *SoruceFileTextBox;
    QLabel *label_2;
    QRadioButton *AdvancedCezarRadio;
    QRadioButton *CezarRadio;
    QLabel *label;
    QRadioButton *radioButton;
    QLabel *label_3;
    QRadioButton *NoCipherRadio;
    QLineEdit *CipherTextBox;
    QPushButton *DecryptButton;
    QPushButton *TextEditorOpenButton;
    QPushButton *btnRestorePass;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 44, 44);\n"
"border-color: rgb(59, 255, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 1151, 751));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        SourceFileSelectButton = new QPushButton(frame);
        SourceFileSelectButton->setObjectName(QString::fromUtf8("SourceFileSelectButton"));
        SourceFileSelectButton->setGeometry(QRect(650, 20, 80, 21));
        SourceFileSelectButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        EncryptButton = new QPushButton(frame);
        EncryptButton->setObjectName(QString::fromUtf8("EncryptButton"));
        EncryptButton->setEnabled(false);
        EncryptButton->setGeometry(QRect(0, 410, 721, 31));
        EncryptButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        CezarNumberSpinBox = new QSpinBox(frame);
        CezarNumberSpinBox->setObjectName(QString::fromUtf8("CezarNumberSpinBox"));
        CezarNumberSpinBox->setEnabled(false);
        CezarNumberSpinBox->setGeometry(QRect(110, 120, 42, 22));
        CezarNumberSpinBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        SoruceFileTextBox = new QLineEdit(frame);
        SoruceFileTextBox->setObjectName(QString::fromUtf8("SoruceFileTextBox"));
        SoruceFileTextBox->setEnabled(false);
        SoruceFileTextBox->setGeometry(QRect(0, 20, 641, 21));
        SoruceFileTextBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 260, 47, 13));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        AdvancedCezarRadio = new QRadioButton(frame);
        AdvancedCezarRadio->setObjectName(QString::fromUtf8("AdvancedCezarRadio"));
        AdvancedCezarRadio->setGeometry(QRect(0, 100, 111, 19));
        AdvancedCezarRadio->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        AdvancedCezarRadio->setChecked(true);
        CezarRadio = new QRadioButton(frame);
        CezarRadio->setObjectName(QString::fromUtf8("CezarRadio"));
        CezarRadio->setGeometry(QRect(0, 120, 84, 19));
        CezarRadio->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 711, 16));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        radioButton = new QRadioButton(frame);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(0, 140, 84, 19));
        radioButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 80, 301, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        NoCipherRadio = new QRadioButton(frame);
        NoCipherRadio->setObjectName(QString::fromUtf8("NoCipherRadio"));
        NoCipherRadio->setGeometry(QRect(0, 160, 84, 19));
        NoCipherRadio->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        CipherTextBox = new QLineEdit(frame);
        CipherTextBox->setObjectName(QString::fromUtf8("CipherTextBox"));
        CipherTextBox->setGeometry(QRect(0, 280, 721, 21));
        CipherTextBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        DecryptButton = new QPushButton(frame);
        DecryptButton->setObjectName(QString::fromUtf8("DecryptButton"));
        DecryptButton->setEnabled(false);
        DecryptButton->setGeometry(QRect(0, 450, 721, 31));
        DecryptButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        TextEditorOpenButton = new QPushButton(frame);
        TextEditorOpenButton->setObjectName(QString::fromUtf8("TextEditorOpenButton"));
        TextEditorOpenButton->setGeometry(QRect(670, 490, 80, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        TextEditorOpenButton->setFont(font);
        TextEditorOpenButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        btnRestorePass = new QPushButton(frame);
        btnRestorePass->setObjectName(QString::fromUtf8("btnRestorePass"));
        btnRestorePass->setGeometry(QRect(0, 490, 101, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SourceFileSelectButton->setText(QCoreApplication::translate("MainWindow", "Wybierz", nullptr));
        EncryptButton->setText(QCoreApplication::translate("MainWindow", "Szyfruj", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Szyfr", nullptr));
        AdvancedCezarRadio->setText(QCoreApplication::translate("MainWindow", "AdvancedCezar", nullptr));
        CezarRadio->setText(QCoreApplication::translate("MainWindow", "Cezar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Plik \305\272r\303\263d\305\202owy", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Coming Soon", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Metoda szyfrowania w tekstu pliku", nullptr));
        NoCipherRadio->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        DecryptButton->setText(QCoreApplication::translate("MainWindow", "Deszyfruj", nullptr));
        TextEditorOpenButton->setText(QCoreApplication::translate("MainWindow", "Text Editor", nullptr));
        btnRestorePass->setText(QCoreApplication::translate("MainWindow", "Restore Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
