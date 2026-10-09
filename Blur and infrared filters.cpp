#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Image_Class.h"

using namespace std;

void Blur(Image& image) {
    Image blurred(image.width, image.height);

    for (int j = 0; j < image.width; j++) {
        for (int i = 0; i < image.height; i++) {
            if (j == 0 || j == image.width - 1 || i == 0 || i == image.height - 1) {
                for (int k = 0; k < 3; k++) {
                    blurred(j, i, k) = image(j, i, k);
                }
            }
            else {
                for (int k = 0; k < 3; k++) {
                    int sum = 0;

                    sum += image(j - 1, i - 1, k);
                    sum += image(j, i - 1, k);
                    sum += image(j + 1, i - 1, k);

                    sum += image(j - 1, i, k);
                    sum += image(j, i, k);
                    sum += image(j + 1, i, k);

                    sum += image(j - 1, i + 1, k);
                    sum += image(j, i + 1, k);
                    sum += image(j + 1, i + 1, k);

                    blurred(j, i, k) = sum / 9;
                }
            }
        }
    }

    for (int j = 0; j < image.width; j++) {
        for (int i = 0; i < image.height; i++) {
            for (int k = 0; k < 3; k++) {
                image(j, i, k) = blurred(j, i, k);
            }
        }
    }
}

void Infrared(Image& image) {

	for (int j = 0; j < image.width; j++) {
		for (int i = 0;i < image.height; i++) {
			image.setPixel(j, i, 0, 255);
		    image.setPixel(j, i, 1, 255 - image.getPixel(j, i, 1));
			image.setPixel(j, i, 2, 255 - image.getPixel(j, i, 2));

		}
	}


}


