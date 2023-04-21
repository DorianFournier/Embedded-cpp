#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagesteganography.h"
#include "steganography.h"

#include "QFileDialog"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //threadElement = new ThreadElement(this);
    //decryptFile = new DecryptFile();
    // connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::spinBox);
    //connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::spinBox);
    //connect(threadElement, &ThreadElement::my_signal, this, &MainWindow::spinBox);
    //->start();

    //ImageSteganography steganography("/home/dorian/Bureau/Ynov/M1/C++/projets/Embedded-cpp/images/aigris_steganography.jpg");
    //string message = steganography.extractMessage();
    //cout << "The hidden message is: " << message << std::endl;

    Steganography stegano;

    // Exemple d'utilisation
    QString message = "AigrisManDEDE";
    stegano.hideData("/home/dorian/Bureau/frigo.png", message);
    QString hidden_message = stegano.showData("/home/dorian/Bureau/hidden_frigo.png");
    qDebug() << "hidden message:" << hidden_message;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::spinBox(int number)
{
    ui->label->setText("coucou caca " + QString::number(number));
}

void MainWindow::browseFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home/dorian/Bureau/Ynov/M1/C++/projets/Embedded-cpp/images",
                                                    tr("Images (*.jpg)"));
    qDebug() << "Le fichier : " << fileName << " a été choisis";
    //const char *fileName_char = fileName.toLocal8Bit().constData();
    //decryptFile->decrypt_file(fileName_char);
}
