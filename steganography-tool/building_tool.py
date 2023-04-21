from PIL import Image
import argparse


def messageToBinary(message):
    binary = ''.join(format(ord(i), '08b') for i in message)
    return binary + "1111111111111110"


def hideData(image_filename, message):
    img = Image.open(
        r'steganography-tool/images/before_uncrypt/' + image_filename)
    img = img.convert("RGB")  # Conversion en mode RGB
    width, height = img.size
    binary_message = messageToBinary(message)
    index = 0
    for row in range(height):
        for col in range(width):
            r, g, b = img.getpixel((col, row))
            if index < len(binary_message):
                img.putpixel((col, row), (r & 254 | int(
                    binary_message[index]), g, b))
                index += 1
    img.save(r'steganography-tool/images/after_uncrypt/' + image_filename)


def showData(hidden_image_filename):
    img = Image.open(
        r'steganography-tool/images/after_uncrypt/' + hidden_image_filename)
    img = img.convert("RGB")  # Conversion en mode RGB
    binary_message = ""
    for row in range(img.size[1]):
        for col in range(img.size[0]):
            r, g, b = img.getpixel((col, row))
            binary_message += str(r & 1)
            if binary_message[-16:] == "1111111111111110":
                return binaryToString(binary_message[:-16])
    return binaryToString(binary_message)


def binaryToString(binary):
    message = ""
    for i in range(0, len(binary), 8):
        message += chr(int(binary[i:i+8], 2))
    return message


if __name__ == "__main__":
    # construct the argument parse and parse the arguments
    ap = argparse.ArgumentParser()
    ap.add_argument("-f", "--file", required=False, help="file to uncrypt")
    args = vars(ap.parse_args())
    print(args)

    filename = r"i_am_not_a_virus.png"
    message = "Ahah it's a prank ! I am a virus, give me money now !"
    hideData(filename, message)
    hidden_message = showData(filename)
    print(f"hidden message : {hidden_message}")
