#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->decryptButton->setDisabled(true);
    decrypt_process = new DecryptProcess();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chooseFile(void)
{
    _hidden_file_name = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    _initial_directory,
                                                    tr("Images (*.png)"));

    QRegularExpression pattern("[^/]+$");
    QRegularExpressionMatch match = pattern.match(_hidden_file_name);
    if (match.hasMatch()) {
        ui->chosenFileLabel->setText(match.captured());
        qDebug() << "Filename:" << match.captured();
        ui->decryptButton->setDisabled(false);
    }
}

void MainWindow::decryptFile(void)
{
    _hidden_message = decrypt_process->showData(_hidden_file_name);
    qDebug() << "Hidden word is : " << _hidden_message<<"";
    ui->textBrowser->setText(_hidden_message);
}
