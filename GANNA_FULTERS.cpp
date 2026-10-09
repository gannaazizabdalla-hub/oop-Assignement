#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include "Image_Class.h"
using namespace std;

void invert_image(Image& img) {
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            for (int k = 0; k < img.channels; k++) {
                int current_color = img.getPixel(j, i, k);
                int inverted_color = 255 - current_color;
                img.setPixel(j, i, k, inverted_color);
            }
        }
    }
}



void lighten_and_darken(Image& img) {
    int value_light_or_dark;
    cout << "Please Enter The Lighting Value (Positive) , Darking Value (Negative)\n";
    cin >> value_light_or_dark;

    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            for (int k = 0; k < img.channels; k++) {
                int current_color = img.getPixel(j, i, k);
                int fixed_color = current_color + value_light_or_dark;
                if (fixed_color > 255) {
                    fixed_color = 255;
                }
                else if (fixed_color < 0) {
                    fixed_color = 0;
                }
                img.setPixel(j, i, k, fixed_color);
            }
        }
    }
}



