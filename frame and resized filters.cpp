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


void Resize(Image& image)
{
    int newWidth, newHeight;

    cout << "Enter new width: ";
    cin >> newWidth;

    cout << "Enter new height: ";
    cin >> newHeight;

    Image resized(newWidth, newHeight);

    for (int x = 0; x < newWidth; x++)
    {
        for (int y = 0; y < newHeight; y++)
        {
            int old_x = x * image.width / newWidth;
            int old_y = y * image.height / newHeight;

            for (int k = 0; k < 3; k++)
            {
                resized(x, y, k) = image(old_x, old_y, k);
            }
        }
    }

    image = resized;
}
