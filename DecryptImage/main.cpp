#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Decrypt Message");
    w.setFixedSize(644, 314);
    w.show();
    return a.exec();
}
