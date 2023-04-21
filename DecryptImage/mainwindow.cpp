#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    qDebug() << ": " << _hidden_file_name << " a été choisis";

    QRegularExpression pattern("[^/]+$");  // motif pour trouver le nom de fichier
    QRegularExpressionMatch match = pattern.match(_hidden_file_name);
    if (match.hasMatch()) {
        ui->chosenFileLable->setText(match.captured());
        qDebug() << "Nom de fichier:" << match.captured();
    }
}

void MainWindow::decryptFile(void)
{
    _hidden_message = decrypt_process->showData(_hidden_file_name);
    qDebug() << "Le message caché est" << _hidden_message<<"";
    ui->textBrowser->setText(_hidden_message);
}
