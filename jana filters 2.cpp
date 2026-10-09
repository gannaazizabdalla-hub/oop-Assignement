#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include "Image_Class.h"

using namespace std;


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

