from rich.console import Console
from PIL import Image
import argparse

# Define the input and output directories for images
BEFORE_ENCRYPTION_FOLDER = r'steganography-tool/images/before_encryption/'
AFTER_ENCRYPTION_FOLDER = r'steganography-tool/images/after_encryption/'
END_OF_MESSAGE_INDICATOR = "1111111111111110"

console = Console()


# Convert a message to binary format
def message_to_binary(message):
    binary = ''.join(format(ord(i), '08b') for i in message)
    return binary + END_OF_MESSAGE_INDICATOR


# Encrypt a message into an image
def encrypt_message(image_filename, message):
    console.print("\nStarting encryption ... ", style="bold italic yellow")
    img = Image.open(
        BEFORE_ENCRYPTION_FOLDER + image_filename)
    img = img.convert("RGB")
    width, height = img.size
    binary_message = message_to_binary(message)
    index = 0
    for row in range(height):
        for col in range(width):
            r, g, b = img.getpixel((col, row))
            if index < len(binary_message):
                img.putpixel((col, row), (r & 254 | int(
                    binary_message[index]), g, b))
                index += 1
    img.save(AFTER_ENCRYPTION_FOLDER + image_filename)
    console.print(
        f"\tThe message [bold green]'{message}'[/bold green] has been encrypted into [bold bright_magenta]'{image_filename}'[/bold bright_magenta]")
    console.print(
        f"\tPath : {AFTER_ENCRYPTION_FOLDER + image_filename}", style="blink italic grey54")
    console.print("Encryption done !\n", style="bold italic yellow")


# Decrypt a message from an encrypted image
def decrypt_message(hidden_image_filename):
    console.print("\nStarting decryption ... ", style="bold italic yellow")
    img = Image.open(
        AFTER_ENCRYPTION_FOLDER + hidden_image_filename)
    img = img.convert("RGB")
    binary_message = ""
    for row in range(img.size[1]):
        for col in range(img.size[0]):
            r, g, b = img.getpixel((col, row))
            binary_message += str(r & 1)
            if binary_message[-16:] == END_OF_MESSAGE_INDICATOR:
                return binary_to_string(binary_message[:-16])
    return binary_to_string(binary_message)


# Convert a binary message to a string
def binary_to_string(binary):
    message = ""
    for i in range(0, len(binary), 8):
        message += chr(int(binary[i:i+8], 2))
    return message


if __name__ == "__main__":
    console.print("\nBUILDING TOOL FOR ENCRYPT AN IMAGE\n",
                  style="bold dark_orange")
    # construct the argument parse and parse the arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--file", required=True, help="file to uncrypt")
    args = parser.parse_args()

    if args.file:
        console.print(
            f"[grey70]Filename to encrypt :[/grey70] [bold bright_magenta]{args.file}[/bold bright_magenta]")
        filename = rf'{args.file}'
        message = console.input(
            "[grey70]Enter the message you want to encrypt into the file : [/grey70]")
        encrypt_message(filename, message)
        decrypted_message = decrypt_message(filename)
        console.print(
            f"\tDecrypted message : [bold green]{decrypted_message}[/bold green]")
        console.print("Decryption done !", style="bold italic yellow")
        console.print("\nENDING PROCESS\n",
                      style="bold dark_orange")
    else:
        console.print("No filename provided.", style="bold red")
