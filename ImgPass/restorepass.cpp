#include "restorepass.h"
#include "ui_restorepass.h"

restorepass::restorepass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::restorepass)
{
    ui->setupUi(this);
}

restorepass::~restorepass()
{
    delete ui;
}


void restorepass::on_btnDecipher_clicked()
{
std::string text = ui->lineEdit->text().toStdString();
DecryptCezar(text, 20);
ui->lblPass->setText(QString::fromStdString(text));

}


void restorepass::DecryptCezar(std::string& text, int symbols)
{
    char* chars = new char[text.size() + 1];
    std::copy(text.begin(), text.end(), chars);
    chars[text.size()] = '\0';


    for (int clk = 0; clk < text.size(); clk++) {
        chars[clk] -= symbols;
    }
    text = chars;
}
