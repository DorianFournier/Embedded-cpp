#include "decryptprocess.h"

#include <QFile>
#include <QTextStream>
#include <QBitArray>

DecryptProcess::DecryptProcess()
{
}

QString DecryptProcess::messageToBinary(QString message)
{
    QString binary;
    for (int i = 0; i < message.length(); i++) {
        binary += QString("%1").arg(message[i].unicode(), 8, 2, QChar('0'));
    }
    return binary + "1111111111111110";
}

QString DecryptProcess::binaryToString(QString binary)
{
    QString message;
    for (int i = 0; i < binary.length(); i += 8) {
        message += QChar(binary.mid(i, 8).toInt(nullptr, 2));
    }
    return message;
}

QString DecryptProcess::showData(QString hiddenImageFilename)
{
    QImage img(hiddenImageFilename);
    QString binary_message;
    for (int row = 0; row < img.height(); row++) {
        for (int col = 0; col < img.width(); col++) {
            QRgb rgb = img.pixel(col, row);
            binary_message += QString::number(qRed(rgb) & 1);
            if (binary_message.right(16) == "1111111111111110") {
                return binaryToString(binary_message.left(binary_message.length() - 16));
            }
        }
    }

    return binaryToString(binary_message);
}
