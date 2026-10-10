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



void crop_image(Image& image)
{

	int start_x, start_y, new_height, new_width;
	cout << "\nPlease enter start point Y\n";
	cin >> start_y;
	cout << "\nPlease enter start point X\n";
	cin >> start_x;
	cout << "\nPlease enter New_Height\n";
	cin >> new_height;
	cout << "\nPlease enter New_width\n";
	cin >> new_width;
	Image new_img(new_width, new_height);

	for (int i = 0; i < new_height;i++)
	{
		for (int j = 0;j < new_width;j++)
		{
			for (int k = 0;k < image.channels;k++)
			{
				int past_color = image.getPixel(j + start_x, i + start_y, k);
				new_img.setPixel(j, i, k, past_color);
			}
		}
	}
}



void purple_night_effect(Image& image)
{
	for (int i = 0;i < image.height;i++)
	{
		for (int j = 0;j < image.width;j++)
		{
			for (int k = 0;k < image.channels;k++)
			{
				int current_color = image.getPixel(j, i, k);
				int new_color;
				if (k == 0)
				{
					new_color = current_color + 50;
				}
				else if (k == 2)
				{
					new_color = current_color + 60;
				}
				else
				{
					new_color = current_color - 30;
				}

				if (new_color > 255)
				{
					new_color = 255;
				}
				else if (new_color < 0)
				{
					new_color = 0;
				}

				image.setPixel(j, i, k, new_color);
			}
		}
	}
}