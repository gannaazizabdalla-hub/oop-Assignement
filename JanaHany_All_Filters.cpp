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

void MergeImages(Image& currentImage) {
    string secondFilename;
    cout << "Enter the second image filename to merge with: ";
    cin >> secondFilename;

    Image img2;
    try {
        img2.loadNewImage(secondFilename);
    }
    catch (...) {
        cout << "Failed to load the second image. Check filename.\n";
        return;
    }

    int choice;
    cout << "Choose merge option:\n";
    cout << "1. Resize both to maximum dimensions\n";
    cout << "2. Crop/Merge using common area (minimum dimensions)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    float opacity = 0.5f;

    if (choice == 1) {
        int maxW = max(currentImage.width, img2.width);
        int maxH = max(currentImage.height, img2.height);

        Image mergedImg(maxW, maxH);

        for (int i = 0; i < maxW; i++) {
            for (int j = 0; j < maxH; j++) {
                int x1 = i * currentImage.width / maxW;
                int y1 = j * currentImage.height / maxH;
                int x2 = i * img2.width / maxW;
                int y2 = j * img2.height / maxH;

                for (int k = 0; k < 3; k++) {
                    double color = (1.0 - opacity) * currentImage(x1, y1, k) + opacity * img2(x2, y2, k);
                    mergedImg(i, j, k) = min(255, max(0, (int)color));
                }
            }
        }
        currentImage = mergedImg;
        cout << "Images merged successfully (Max dimensions)!\n";
    }
    else if (choice == 2) {
        int minW = min(currentImage.width, img2.width);
        int minH = min(currentImage.height, img2.height);

        Image mergedImg(minW, minH);

        for (int i = 0; i < minW; i++) {
            for (int j = 0; j < minH; j++) {
                for (int k = 0; k < 3; k++) {
                    double color = (1.0 - opacity) * currentImage(i, j, k) + opacity * img2(i, j, k);
                    mergedImg(i, j, k) = min(255, max(0, (int)color));
                }
            }
        }
        currentImage = mergedImg;
        cout << "Images merged successfully (Common area / Min dimensions)!\n";
    }
    else {
        cout << "Invalid choice!\n";
    }
}


void WanoSunlightFilter(Image& img) {
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {

            int red = img(i, j, 0);
            int green = img(i, j, 1);
            int blue = img(i, j, 2);

            red = min(255, (int)(red * 1.2));
            green = min(255, (int)(green * 1.1));
            blue = max(0, (int)(blue * 0.9));

            img(i, j, 0) = red;
            img(i, j, 1) = green;
            img(i, j, 2) = blue;
        }
    }
    cout << "WanoSunlightFilter applied successfully!\n";
}
