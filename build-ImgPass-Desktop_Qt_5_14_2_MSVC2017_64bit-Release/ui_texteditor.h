/********************************************************************************
** Form generated from reading UI file 'texteditor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDITOR_H
#define UI_TEXTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextEditor
{
public:
    QWidget *centralwidget;
    QPushButton *newButton;
    QPushButton *SaveButton;
    QPushButton *SaveAsButton;
    QPushButton *OpenButton;
    QPushButton *generateExampleButton;
    QPlainTextEdit *MainTextArea;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TextEditor)
    {
        if (TextEditor->objectName().isEmpty())
            TextEditor->setObjectName(QString::fromUtf8("TextEditor"));
        TextEditor->resize(640, 480);
        centralwidget = new QWidget(TextEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        newButton = new QPushButton(centralwidget);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        newButton->setGeometry(QRect(10, 10, 80, 21));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setEnabled(false);
        SaveButton->setGeometry(QRect(100, 10, 80, 21));
        SaveAsButton = new QPushButton(centralwidget);
        SaveAsButton->setObjectName(QString::fromUtf8("SaveAsButton"));
        SaveAsButton->setGeometry(QRect(190, 10, 80, 21));
        OpenButton = new QPushButton(centralwidget);
        OpenButton->setObjectName(QString::fromUtf8("OpenButton"));
        OpenButton->setGeometry(QRect(280, 10, 80, 21));
        generateExampleButton = new QPushButton(centralwidget);
        generateExampleButton->setObjectName(QString::fromUtf8("generateExampleButton"));
        generateExampleButton->setGeometry(QRect(460, 10, 101, 21));
        MainTextArea = new QPlainTextEdit(centralwidget);
        MainTextArea->setObjectName(QString::fromUtf8("MainTextArea"));
        MainTextArea->setGeometry(QRect(10, 40, 611, 401));
        MainTextArea->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhMultiLine);
        TextEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TextEditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 20));
        TextEditor->setMenuBar(menubar);
        statusbar = new QStatusBar(TextEditor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TextEditor->setStatusBar(statusbar);

        retranslateUi(TextEditor);

        QMetaObject::connectSlotsByName(TextEditor);
    } // setupUi

    void retranslateUi(QMainWindow *TextEditor)
    {
        TextEditor->setWindowTitle(QCoreApplication::translate("TextEditor", "MainWindow", nullptr));
        newButton->setText(QCoreApplication::translate("TextEditor", "New", nullptr));
        SaveButton->setText(QCoreApplication::translate("TextEditor", "Save", nullptr));
        SaveAsButton->setText(QCoreApplication::translate("TextEditor", "Save As", nullptr));
        OpenButton->setText(QCoreApplication::translate("TextEditor", "Open", nullptr));
        generateExampleButton->setText(QCoreApplication::translate("TextEditor", "Generate Example", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextEditor: public Ui_TextEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDITOR_H
