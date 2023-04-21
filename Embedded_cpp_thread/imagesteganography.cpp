#include "imagesteganography.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QFile>
#include <QImage>
#include <QColor>

using namespace std;

ImageSteganography::ImageSteganography(string filename) : filename_(filename) {}

string ImageSteganography::extractMessage() {
    QFile file(QString::fromStdString(filename_));
    if (!file.exists()) {
        cerr << "Could not open or find the image" << endl;
        exit(1);
    }
    QImage image(filename_.c_str());
    if (image.isNull()) {
        cerr << "Not a valid image file" << endl;
        exit(1);
    }
    string message;
    for (int row = 0; row < image.height(); row++) {
        for (int col = 0; col < image.width(); col++) {
            QColor color = image.pixelColor(col, row);
            // Extrayez les 2 bits de poids faible de chaque canal de couleur
            int bit1 = color.red() & 1;
            int bit2 = (color.red() >> 1) & 1;
            int bit3 = color.green() & 1;
            int bit4 = (color.green() >> 1) & 1;
            int bit5 = color.blue() & 1;
            int bit6 = (color.blue() >> 1) & 1;
            // Ajouter les bits au message
            message += to_string(bit1);
            message += to_string(bit2);
            message += to_string(bit3);
            message += to_string(bit4);
            message += to_string(bit5);
            message += to_string(bit6);
        }
    }
    return message;
}
