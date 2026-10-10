#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Image_Class.h"

void Blur(Image& image) {
    Image blurred(image.width, image.height);

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            if (i == 0 || i == image.width - 1 || j == 0 || j == image.height - 1) {
                for (int k = 0; k < 3; k++) {
                    blurred(i, j, k) = image(i, j, k);
                }
            }
            else {
                for (int k = 0; k < 3; k++) {
                    int sum = 0;

                    sum += image(i - 1, j - 1, k);
                    sum += image(i, j - 1, k);
                    sum += image(i + 1, j - 1, k);

                    sum += image(i - 1, j, k);
                    sum += image(i, j, k);
                    sum += image(i + 1, j, k);

                    sum += image(i - 1, j + 1, k);
                    sum += image(i, j + 1, k);
                    sum += image(i + 1, j + 1, k);

                    blurred(i, j, k) = sum / 9;
                }
            }
        }
    }

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) = blurred(i, j, k);
            }
        }
    }
}
void Infrared(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            image.setPixel(i, j, 0, 255);
            image.setPixel(i, j, 1, 255 - image.getPixel(i, j, 1));
            image.setPixel(i, j, 2, 255 - image.getPixel(i, j, 2));
        }
    }
}
