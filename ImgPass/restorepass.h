#ifndef RESTOREPASS_H
#define RESTOREPASS_H

#include <QMainWindow>

namespace Ui {
class restorepass;
}

class restorepass : public QMainWindow
{
    Q_OBJECT

public:
    explicit restorepass(QWidget *parent = nullptr);
    ~restorepass();

private slots:
    void on_btnDecipher_clicked();

private:
    Ui::restorepass *ui;
    void DecryptCezar(std::string& text, int symbols);
};

#endif // RESTOREPASS_H
