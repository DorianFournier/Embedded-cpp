#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QFileDialog"
#include "decryptprocess.h"
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    DecryptProcess *decrypt_process;

public slots:
    void chooseFile(void);
    void decryptFile(void);

private:
    Ui::MainWindow *ui;
    QString _hidden_file_name = "";
    QString _hidden_message = "";
    QString _initial_directory = "../steganography-build-file/images/after_uncrypt/";
};
#endif // MAINWINDOW_H
