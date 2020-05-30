#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_EncryptButton_clicked();

    void on_SourceFileSelectButton_clicked();

    void on_DecryptButton_clicked();

    void on_AdvancedCezarRadio_clicked();

    void on_CezarRadio_clicked();

    void on_NoCipherRadio_clicked();

    void on_TextEditorOpenButton_clicked();

    void on_btnRestorePass_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
