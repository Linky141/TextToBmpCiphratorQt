#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>

namespace Ui {
class TextEditor;
}

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = nullptr);
    ~TextEditor();
    bool getUsePathPermit() {return usePathPermit; }
    bool getWindowStatus() {return windowIsActive; }
    QString getPath() {return path; }

private slots:
    void on_newButton_clicked();

    void on_SaveAsButton_clicked();

    void on_OpenButton_clicked();

    void on_SaveButton_clicked();

    void on_generateExampleButton_clicked();

private:
    Ui::TextEditor *ui;
    QString path = "";
    bool usePathPermit = false;
    bool windowIsActive = true;
};

#endif // TEXTEDITOR_H
