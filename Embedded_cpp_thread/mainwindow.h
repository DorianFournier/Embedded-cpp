#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "threadelement.h"
#include "decryptfile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ThreadElement *threadElement;
    DecryptFile *decryptFile;

public slots:
    void spinBox(int number);
    void browseFile(void);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
