#ifndef CHECKPASS_H
#define CHECKPASS_H

#include <QDialog>

namespace Ui {
class CheckPass;
}

class CheckPass : public QDialog
{
    Q_OBJECT

public:
    explicit CheckPass(QWidget *parent = nullptr);
    ~CheckPass();

private:
    Ui::CheckPass *ui;
};

#endif // CHECKPASS_H
