#ifndef DECRYPTFILE_H
#define DECRYPTFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <cstring>
#include <QDebug>

using namespace std;

class DecryptFile
{
public:
    DecryptFile();
    int decrypt_file(const char *filename);
    void extract_bits(int channel, vector<bool>& bits);
};

#endif // DECRYPTFILE_H
