#ifndef IMAGE_STEGANOGRAPHY_H
#define IMAGE_STEGANOGRAPHY_H

#include <string>

class ImageSteganography {
public:
    ImageSteganography(std::string filename);
    std::string extractMessage();
private:
    std::string filename_;
};

#endif // IMAGE_STEGANOGRAPHY_H
