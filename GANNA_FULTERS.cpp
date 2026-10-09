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

// ==========================================
// Filter 10: Detect Image Edges
// ==========================================
void detectImageEdges(Image& img) {
    for (int x = 0; x < img.width - 1; ++x) {
        for (int y = 0; y < img.height; ++y) {
            int diff = abs(img(x, y, 0) - img(x + 1, y, 0)) +
                abs(img(x, y, 1) - img(x + 1, y, 1)) +
                abs(img(x, y, 2) - img(x + 1, y, 2));

            unsigned char val = (diff > 40) ? 0 : 255;
            img(x, y, 0) = img(x, y, 1) = img(x, y, 2) = val;
        }
    }
    cout << "Edge detection filter applied successfully!\n";
}

// ==========================================
// Filter 14: TV / Old Den Den Mushi Effect
// ==========================================
void oldTV(Image& img) {
    for (int y = 0; y < img.height; ++y) {
        if (y % 2 == 0) {
            for (int x = 0; x < img.width; ++x) {
                img(x, y, 0) /= 2;
                img(x, y, 1) /= 2;
                img(x, y, 2) /= 2;
            }
        }
    }
    cout << "Old TV filter applied successfully!\n";
}

// ==========================================
// Helper Functions: Load & Save Image
// ==========================================
bool loadImage(Image& img) {
    string filename;
    cout << "Enter input image filename (e.g. image.jpg): ";
    cin >> filename;
    try {
        if (img.loadNewImage(filename)) {
            cout << "Image loaded successfully!\n";
            return true;
        }
    }
    catch (...) {}
    cout << "Failed to load image!\n";
    return false;
}

void saveImage(Image& img) {
    string filename;
    cout << "Enter output image filename to save (e.g. result.jpg): ";
    cin >> filename;
    if (img.saveImage(filename)) {
        cout << "Image saved successfully!\n";
    }
    else {
        cout << "Failed to save image!\n";
    }
}

// ==========================================
// Main Function & Application Menu
// ==========================================
int main() {
    Image currentImage;
    bool isLoaded = false;
    int choice = 0;

    cout << "========================================\n";
    cout << "   CS213 Assignment 1 - Filters Menu    \n";
    cout << "========================================\n";

    while (true) {
        cout << "\n--- MAIN MENU ---\n";
        cout << "1. Load Image\n";
        cout << "2. Apply Black and White Filter\n";
        cout << "3. Apply Rotate Filter (90 / 180 / 270)\n";
        cout << "4. Apply Detect Edges Filter\n";
        cout << "5. Apply Old TV Filter\n";
        cout << "6. Save Current Image\n";
        cout << "7. Exit\n";
        cout << "Choose an option (1-7): ";
        cin >> choice;

        if (choice == 1) {
            isLoaded = loadImage(currentImage);
        }
        else if (choice == 2) {
            if (!isLoaded) { cout << "Please load an image first!\n"; continue; }
            applyBlackAndWhite(currentImage);
        }
        else if (choice == 3) {
            if (!isLoaded) { cout << "Please load an image first!\n"; continue; }
            rotateImage(currentImage);
        }
        else if (choice == 4) {
            if (!isLoaded) { cout << "Please load an image first!\n"; continue; }
            detectImageEdges(currentImage);
        }
        else if (choice == 5) {
            if (!isLoaded) { cout << "Please load an image first!\n"; continue; }
            oldTV(currentImage);
        }
        else if (choice == 6) {
            if (!isLoaded) { cout << "No image loaded to save!\n"; continue; }
            saveImage(currentImage);
        }
        else if (choice == 7) {
            cout << "Exiting program. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}