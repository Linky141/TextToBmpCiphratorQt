#include "texteditor.h"
#include "ui_texteditor.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::on_newButton_clicked()
{
    ui->MainTextArea->clear();
    ui->SaveButton->setEnabled(false);
    path = "";
}

void TextEditor::on_SaveAsButton_clicked()
{
    path = QFileDialog::getSaveFileName(this, tr("Save Text File"),  QDir::homePath()+"\\Desktop", tr("Text (*.txt);"));
    if (path.isEmpty())
           return;
       else {
           QFile file(path);
           if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
               QMessageBox::information(this, tr("Unable to open file"),
                   file.errorString());
               return;
           }
           QTextStream out(&file);
           out << ui->MainTextArea->toPlainText() << "\nxD";
           ui->SaveButton->setEnabled(true);
           file.close();
        }
    }

void TextEditor::on_OpenButton_clicked()
{

    path = QFileDialog::getOpenFileName(this, tr("Open Text File"), QDir::homePath()+"\\Desktop", tr("Text (*.txt);"));

    if (path.isEmpty())
            return;
        else {

            QFile file(path);

            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }

            QTextStream in(&file);
            ui->MainTextArea->clear();
            QString tmp = "";
            while (!in.atEnd()){
                tmp.append(in.readLine()+"\n");
            }
            ui->MainTextArea->setPlainText(tmp);
            ui->SaveButton->setEnabled(true);
            file.close();
            }
}


void TextEditor::on_SaveButton_clicked()
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }
    QTextStream out(&file);
     out << ui->MainTextArea->toPlainText();
     file.close();
}

void TextEditor::on_generateExampleButton_clicked()
{
    ui->MainTextArea->setPlainText("Nessun dorma! Nessun dorma!\n"
                                   "Tu pure, oh Principessa\n"
                                   "Nella tua fredda stanza\n"
                                   "Guardi le stelle che tremano\n"
                                   "Damore e di speranza\n"
                                   "Ma il mio mistero è chiuso in me\n"
                                   "Il nome mio nessun saprà\n"
                                   "No, no, sulla tua bocca lo dirò\n"
                                   "Quando la luce splenderà\n"
                                   "Ed il mio bacio scioglierà\n"
                                   "Il silenzio che ti fa mia\n"
                                   "(ll nome suo nessun saprà\n"
                                   "E noi dovrem, ahimè, morir, morir)\n"
                                   "Dilegua, oh notte\n"
                                   "Tramontate, stelle\n"
                                   "Tramontate, stelle\n"
                                   "Allalba vincerò\n"
                                   "Vincerà\n"
                                   "Vincerò");
}
