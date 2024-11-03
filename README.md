# Image Encryption and Decryption Tool using Pixel Manipulation

This project is a simple image encryption and decryption tool developed using C++. The tool performs pixel manipulation through XOR operations, allowing users to encrypt and decrypt images using a randomly generated key. This code is designed for learning and demonstration purposes, particularly in the field of image security.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Setup and Installation](#setup-and-installation)
- [Usage](#usage)
- [Example Input and Output](#example-input-and-output)
- [Project Structure](#project-structure)

## Overview

This tool encrypts an image by performing XOR operations on each pixel with a randomly generated key. The same key is then used to decrypt the image back to its original form. The project serves as a basic demonstration of pixel-level encryption using C++ and OpenCV.

## Features

- Encrypts an image using pixel manipulation with a randomly generated key.
- Decrypts an encrypted image back to its original form using the same key.
- Simple console interface to input file paths for encryption and decryption.

## Prerequisites

This tool requires [OpenCV](https://opencv.org/) for handling images in C++. Follow the instructions below to install OpenCV on your system if it’s not already installed.

### OpenCV Installation (Windows)
1. Download the latest version of OpenCV from the [official website](https://opencv.org/releases/).
2. Extract the downloaded files and set up environment variables as described in the OpenCV installation guide.
3. Link OpenCV libraries in your project configuration (e.g., in VS Code, update `tasks.json` and `launch.json` for building and debugging).

## Setup and Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/image-encryption-tool.git
   cd image-encryption-tool
   ```

2. **Open in VS Code**:
   - Open this folder in VS Code if you’re using it as your IDE.

3. **Setup OpenCV Configuration**:
   - Update `tasks.json` and `launch.json` files (provided in the repository) to ensure the code can compile and run with OpenCV.

4. **Compile the Code**:
   - Use the build task in VS Code or compile via the command line:
     ```bash
     g++ image_encryption.cpp -o image_encryption -I<path-to-opencv-include> -L<path-to-opencv-lib> -lopencv_core -lopencv_highgui -lopencv_imgcodecs
     ```

## Usage

### Running the Tool

1. **Encrypt an Image**:
   - Run the compiled executable and enter the path to the image file when prompted.
   
2. **Decrypt the Encrypted Image**:
   - The tool automatically decrypts the encrypted image after encryption using the same key.
   
### Example Command
```bash
./image_encryption
```

- You’ll be prompted to enter the path of the image you want to encrypt:
  ```
  Enter the path to the image file: sample_image.png
  ```

## Example Input and Output

- **Original Image**: `sample_image.png` (the user-provided input image).
- **Encrypted Image**: `encrypted_image.png` (a scrambled version of the original image).
- **Decrypted Image**: `decrypted_image.png` (identical to the original if decryption is successful).

Example console output:
```
Image encrypted successfully.
Image decrypted successfully.
```

## Project Structure

```plaintext
image-encryption-tool/
│
├── image_encryption.cpp    # Main C++ source file for encryption and decryption
├── sample_image.png        # Sample image for testing (optional)
├── encrypted_image.png     # Generated encrypted image
├── decrypted_image.png     # Generated decrypted image (matches original)
├── README.md               # Project documentation
├── tasks.json              # VS Code tasks for compiling with OpenCV
├── launch.json             # VS Code launch configuration for debugging
└── .gitignore              # Git ignore file
```
