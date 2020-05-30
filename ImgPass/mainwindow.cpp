#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TextFileOI.h"
#include "EncryptEngine.h"
#include "texteditor.h"

#include <QFileDialog>
#include <QMessageBox>



bool CheckCipher(std::string val);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SourceFileSelectButton_clicked()
{
    QString location = QFileDialog::getOpenFileName(this, tr("Plik do zaszyfrowania"), QDir::homePath()+"\\Desktop", tr("Plik tekstowy (*.txt);;Plik tekstowy (*.bmp)"));
    ui->SoruceFileTextBox->setText(location);
    if(location.endsWith("txt",Qt::CaseInsensitive)){
            ui->EncryptButton->setEnabled(true);
            ui->DecryptButton->setEnabled(false);
    }
    else if(location.endsWith("bmp",Qt::CaseInsensitive)){
        ui->EncryptButton->setEnabled(false);
        ui->DecryptButton->setEnabled(true);
}
}

void MainWindow::on_EncryptButton_clicked()
{
    QMessageBox msgBox;

    //Wybór szyfrowania
    int typeTextCipher=-1;
    if(ui->AdvancedCezarRadio->isChecked()) typeTextCipher=2;
    else if(ui->CezarRadio->isChecked()) typeTextCipher=1;
    else if(ui->NoCipherRadio->isChecked()) typeTextCipher=4;

    //pobór lokalizacji pliku
    QString location = ui->SoruceFileTextBox->text();
    if(location.isEmpty()){//W przypadku barku ścieżki pliku przerywa działanie
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Błąd");
    msgBox.setText("Nie podano ścieżki pliku");
    msgBox.exec();
    return;
}
    location.truncate(location.lastIndexOf('.'));

    //odczytywanie tekstu z pliku
    TextFileIO textFileIO;
    std::string text;
    textFileIO.ReadFile(text, location.toStdString());

    //pobieranie szyfru z textboxa oraz rozdzielanie na 2 człony
    EncryptEngine encryptEngine;
    std::string cipher = ui->CipherTextBox->text().toStdString();
    if(!CheckCipher(cipher)) { //W przypadku długości szyfru przerywa działanie
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Błąd");
        msgBox.setText("Długość szyfru jest nieprawidłowa");
        msgBox.exec();
        return;
        }
    int noisePx;
    std::string password;
    encryptEngine.SeparateCode(cipher, noisePx, password);


    //szyforwanie tekstu z wykorzystaniem wybranej metody szyfrowania
    switch(typeTextCipher){
    case 1:
        encryptEngine.EncryptCezar(text, ui->CezarNumberSpinBox->value());
        break;
    case 2:
        encryptEngine.Encrypt(text, password);
        break;
    case 4:
        break;
    default:
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Błąd");
        msgBox.setText("Wybrano nieprawidłową opcję szyfrowania");
        msgBox.exec();
        return;
        break; //W przypadku błędnej metody szyfrowania przerywa działanie
    }

    //Szyfrowanie do pliku
    bool succes = encryptEngine.Export(text, location.toStdString(), noisePx, cipher);
    if(!succes) {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Błąd");
        msgBox.setText("Nie udało się utworzyć pliku");
        msgBox.exec();
        return;
        }
    else{
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Powodzenie");
        msgBox.setText("Utworzono plik");
        msgBox.exec();
        return;
    }
}

void MainWindow::on_DecryptButton_clicked()
{
    QMessageBox msgBox;

    //Wybór szyfrowania
    int typeTextCipher=-1;
    if(ui->AdvancedCezarRadio->isChecked()) typeTextCipher=2;
    else if(ui->CezarRadio->isChecked()) typeTextCipher=1;
    else if(ui->NoCipherRadio->isChecked()) typeTextCipher=4;

    //pobór lokalizacji pliku
    QString location = ui->SoruceFileTextBox->text();
    if(location.isEmpty()){//W przypadku barku ścieżki pliku przerywa działanie
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Błąd");
    msgBox.setText("Nie podano ścieżki pliku");
    msgBox.exec();
    return;
}
    location.truncate(location.lastIndexOf('.'));

    //pobieranie szyfru z textboxa oraz rozdzielanie na 2 człony
    EncryptEngine encryptEngine;
    std::string cipher = ui->CipherTextBox->text().toStdString();
    if(!CheckCipher(cipher)) { //W przypadku długości szyfru przerywa działanie
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Błąd");
        msgBox.setText("Długość szyfru jest nieprawidłowa");
        msgBox.exec();
        return;
        }
    int noisePx;
    std::string password;
    encryptEngine.SeparateCode(cipher, noisePx, password);



    //tworzenie zmiennej z textem
    std::string text;

    //Odczytywanie z pliku
    bool succes = encryptEngine.Import(text, location.toStdString(), noisePx);
    if(!succes) {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Błąd");
        msgBox.setText("Nie udało się otworzyć pliku");
        msgBox.exec();
        return;
        }

    //deszyforwanie tekstu z wykorzystaniem wybranej metody szyfrowania
    switch(typeTextCipher){
    case 1:
        encryptEngine.DecryptCezar(text, ui->CezarNumberSpinBox->value());
        break;
    case 2:
        encryptEngine.Decrypt(text, password);
        break;
    case 4:
        break;
    default:
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Błąd");
        msgBox.setText("Wybrano nieprawidłową opcję szyfrowania");
        msgBox.exec();
        return;
        break; //W przypadku błędnej metody szyfrowania przerywa działanie
    }


    //zapisywanie tekstu do pliku
    TextFileIO textFileIO;
    textFileIO.WriteFile(text, location.toStdString());
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Powodzenie");
    msgBox.setText("Utworzono plik");
    msgBox.exec();
    return;
}

/*
 * dodatkowe metody
 */

bool CheckCipher(std::string val){
    if(val.length()<=3)return false;
    return true;
}


/*
 * Obsługo dodatkowych akcji
 * */

void MainWindow::on_AdvancedCezarRadio_clicked()
{
     ui->CezarNumberSpinBox->setEnabled(false);
}

void MainWindow::on_CezarRadio_clicked()
{
     ui->CezarNumberSpinBox->setEnabled(true);
}

void MainWindow::on_NoCipherRadio_clicked()
{
    ui->CezarNumberSpinBox->setEnabled(false);
}

void MainWindow::on_TextEditorOpenButton_clicked()
{
    TextEditor *te = new TextEditor(this);
    te->show();


    if(te->getUsePathPermit()){
        QString path = te->getPath();
        ui->SoruceFileTextBox->setText(path);
        ui->EncryptButton->setEnabled(true);
        ui->DecryptButton->setEnabled(false);
    }
}
