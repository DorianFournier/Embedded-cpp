#ifndef DECRYPTPROCESS_H
#define DECRYPTPROCESS_H

#include <QString>
#include <QImage>

class DecryptProcess
{
public:
    DecryptProcess();
    QString showData(QString hiddenImageFilename);

private:
    QString messageToBinary(QString message);
    QString binaryToString(QString binary);
};

#endif // DECRYPTPROCESS_H
