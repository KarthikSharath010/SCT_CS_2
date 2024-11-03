//Develop a simple image encryption tool using pixel manipulation. Support operations like swapping pixel values or applying a basic mathematical operation to each pixel.
#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;
using namespace std;

// Function to generate a random key with the same dimensions as the image
Mat generateKey(Size imageSize) {
    Mat key(imageSize, CV_8UC3);
    randu(key, Scalar::all(0), Scalar::all(256));  // Random values between 0 and 255
    return key;
}

// Function to encrypt an image
void encryptImage(const string& imagePath, const Mat& key) {
    // Read the image
    Mat img = imread(imagePath, IMREAD_COLOR);
    if (img.empty()) {
        cout << "Error: Could not open or find the image!" << endl;
        return;
    }

    // Ensure the key has the same size as the image
    Mat resizedKey;
    resize(key, resizedKey, img.size());

    // Encrypt each pixel using XOR with the key
    Mat encryptedImg;
    bitwise_xor(img, resizedKey, encryptedImg);

    // Save the encrypted image
    imwrite("encrypted_image.png", encryptedImg);
    cout << "Image encrypted successfully." << endl;
}

// Function to decrypt an image
void decryptImage(const string& encryptedImagePath, const Mat& key) {
    // Read the encrypted image
    Mat encryptedImg = imread(encryptedImagePath, IMREAD_COLOR);
    if (encryptedImg.empty()) {
        cout << "Error: Could not open or find the encrypted image!" << endl;
        return;
    }

    // Ensure the key has the same size as the encrypted image
    Mat resizedKey;
    resize(key, resizedKey, encryptedImg.size());

    // Decrypt each pixel using XOR with the key
    Mat decryptedImg;
    bitwise_xor(encryptedImg, resizedKey, decryptedImg);

    // Save the decrypted image
    imwrite("decrypted_image.png", decryptedImg);
    cout << "Image decrypted successfully." << endl;
}

int main() {
    cout << "Image Encryption and Decryption using Pixel Manipulation" << endl;

    // Get the image path from the user
    string imagePath;
    cout << "Enter the path to the image file: ";
    cin >> imagePath;

    // Generate a random key with the same dimensions as the image
    Mat key = generateKey(Size(500, 500));  // Adjust the size based on your image

    // Encrypt the image
    encryptImage(imagePath, key);

    // Decrypt the image
    decryptImage("encrypted_image.png", key);

    return 0;
}
