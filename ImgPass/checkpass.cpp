#include "checkpass.h"
#include "ui_checkpass.h"

CheckPass::CheckPass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckPass)
{
    ui->setupUi(this);
}

CheckPass::~CheckPass()
{
    delete ui;
}
