#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    threadElement = new ThreadElement(this);
    // connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::spinBox);
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::spinBox);
    connect(threadElement, &ThreadElement::my_signal, this, &MainWindow::spinBox);
    threadElement->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::spinBox(int number)
{
    ui->label->setText("coucou caca " + QString::number(number));
}
