#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Image_Class.h"

void convertToGrayscale(Image& image) {
    unsigned int avg = 0;
    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
            avg = 0;
            for (int k = 0; k < 3; k++) {
                avg += image(x, y, k);
            }
            avg /= 3;
            for (int k = 0; k < 3; k++) {
                image(x, y, k) = avg;
            }
        }
    }
    cout << "Grayscale filter applied successfully!\n";
}

void convertToFlipped(Image& image, string flipChoice) {
    cout << "Enter 'h' to flip horizontally or 'v' to flip vertically: ";
    cin >> flipChoice;
    if (flipChoice == "h") {
        for (int y = 0; y < image.height; y++) {
            for (int x = 0; x < image.width / 2; x++) {
                for (int k = 0; k < 3; k++) {
                    unsigned char temp = image(x, y, k);
                    image(x, y, k) = image(image.width - x - 1, y, k);
                    image(image.width - x - 1, y, k) = temp;
                }
            }
        }
        cout << "Image flipped horizontally successfully!\n";
    }
    else if (flipChoice == "v") {
        for (int y = 0; y < image.height / 2; y++) {
            for (int x = 0; x < image.width; x++) {
                for (int k = 0; k < 3; k++) {
                    unsigned char temp = image(x, y, k);
                    image(x, y, k) = image(x, image.height - y - 1, k);
                    image(x, image.height - y - 1, k) = temp;
                }
            }
        }
        cout << "Image flipped vertically successfully!\n";
    }
	else {
		cout << "Invalid choice! Please enter 'h' or 'v'.\n";
	}
}
