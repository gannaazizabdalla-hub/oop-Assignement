#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include "Image_Class.h"

using namespace std;

// ==========================================
// Filter 2: Black and White (Threshold)
// ==========================================
void applyBlackAndWhite(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int y = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            if (y > 140) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
            else {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
    cout << "Black and White filter applied successfully!\n";
}

// ==========================================
// Filter 6: Rotate Image (90 / 180 / 270)
// ==========================================
void rotateImage(Image& image) {
    int angle;
    cout << "Enter angle value (90 / 180 / 270): ";
    cin >> angle;

    if (angle == 90) {
        Image newImage(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                int newX = image.height - 1 - j;
                int newY = i;
                for (int c = 0; c < 3; ++c) {
                    newImage(newX, newY, c) = image(i, j, c);
                }
            }
        }
        image = newImage;
        cout << "Image rotated 90 degrees successfully!\n";
    }
    else if (angle == 180) {
        Image newImage(image.width, image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                int newX = image.width - 1 - i;
                int newY = image.height - 1 - j;
                for (int c = 0; c < 3; ++c) {
                    newImage(newX, newY, c) = image(i, j, c);
                }
            }
        }
        image = newImage;
        cout << "Image rotated 180 degrees successfully!\n";
    }
    else if (angle == 270) {
        Image newImage(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                int newX = j;
                int newY = image.width - 1 - i;
                for (int c = 0; c < 3; ++c) {
                    newImage(newX, newY, c) = image(i, j, c);
                }
            }
        }
        image = newImage;
        cout << "Image rotated 270 degrees successfully!\n";
    }
    else {
        cout << "Invalid angle!\n";
    }
}
