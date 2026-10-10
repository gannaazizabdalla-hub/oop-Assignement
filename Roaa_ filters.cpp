#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Image_Class.h"
using namespace std;
void frame(Image& image)
{
    int choice;

    cout << "Choose frame type:\n";
    cout << "1. Simple\n";
    cout << "2. Fancy\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int r1, g1, b1;

    cout << "Enter first frame color (R G B): ";
    cin >> r1 >> g1 >> b1;

    if (choice == 1)
    {
        for (int i = 0; i < image.width; ++i)
        {
            for (int j = 0; j < image.height; ++j)
            {
                if (i == 0 || i == image.width - 1 ||
                    j == 0 || j == image.height - 1)
                {
                    image(i, j, 0) = r1;
                    image(i, j, 1) = g1;
                    image(i, j, 2) = b1;
                }
            }
        }
    }
    else if (choice == 2)
    {
        int r2, g2, b2;

        cout << "Enter second frame color (R G B): ";
        cin >> r2 >> g2 >> b2;

        for (int i = 0; i < image.width; ++i)
        {
            for (int j = 0; j < image.height; ++j)
            {
                if (j < 6 || j >= image.height - 6)
                {
                    if ((i / 3) % 2 == 0)
                    {
                        image(i, j, 0) = r1;
                        image(i, j, 1) = g1;
                        image(i, j, 2) = b1;
                    }
                    else
                    {
                        image(i, j, 0) = r2;
                        image(i, j, 1) = g2;
                        image(i, j, 2) = b2;
                    }
                }
                else if (i < 6 || i >= image.width - 6)
                {
                    if ((j / 3) % 2 == 0)
                    {
                        image(i, j, 0) = r1;
                        image(i, j, 1) = g1;
                        image(i, j, 2) = b1;
                    }
                    else
                    {
                        image(i, j, 0) = r2;
                        image(i, j, 1) = g2;
                        image(i, j, 2) = b2;
                    }
                }
            }
        }
    }
    else
    {
        cout << "Invalid choice!\n";
    }
}


void Resize(Image& image) {
    int newWidth, newHeight;

    cout << "Enter new width: ";
    cin >> newWidth;

    cout << "Enter new height: ";
    cin >> newHeight;

    Image resized(newWidth, newHeight);

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            int old_i = i * image.width / newWidth;
            int old_j = j * image.height / newHeight;

            for (int k = 0; k < 3; k++) {
                resized(i, j, k) = image(old_i, old_j, k);
            }
        }
    }

    image = resized;
}
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
