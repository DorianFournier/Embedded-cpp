#include "decryptfile.h"

DecryptFile::DecryptFile()
{

}

// Fonction pour extraire les bits de poids faible d'un canal de couleur
void DecryptFile::extract_bits(int channel, vector<bool>& bits)
{
    for (int i = 0; i < channel; i++) {
        int pixel;
        cin >> pixel;
        bits.push_back(pixel % 2);
    }
}

int DecryptFile::decrypt_file(const char* filename)
{
    qDebug()<<"file : "<< filename;
    // Ouvrir le fichier image cachée
    ifstream in(filename, ios::binary);
    if (!in.is_open()) {
        qDebug()<<"Impossible d'ouvrir le fichier : "<< filename;
        return 1;
    }
    qDebug()<<"Starting decryption ...";
    // Extraire les données cachées de l'image
    vector<bool> bits;
    int channels = 0;
    in >> channels;

    qDebug()<<"channels : "<< channels;
    while (!in.eof()) {
        for (int i = 0; i < 3; i++) {
            //qDebug()<<channels << " : " << i;
            extract_bits(i, bits);
        }
    }

    qDebug()<<"Starting convertion ...";
    // Convertir les bits en texte
    string message = "";
    for (int i = 0; i < bits.size(); i += 8) {
        bitset<8> byte;
        for (int j = 0; j < 8; j++) {
            byte[j] = bits[i + j];
        }
        message += char(byte.to_ulong());
    }

    // Afficher le message caché
    cout << "Le message caché est : " << message << endl;
    qDebug()<<"Done.";
    return 0;
}
