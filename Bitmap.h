/***********************************************************
 * Bitmap.h                                                *
 * Bitmap reading library                                  *
 *                                                         *
 * Author: Artemy Belousov (aka whitemoustache, WM, whimo) *
 ***********************************************************/

#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <iostream>

#define uchar_t unsigned char
const size_t uchar_size = sizeof (uchar_t);

const size_t header_size = 54; //Each .bmp file has a 54-byte header

struct pixel {uchar_t red, green, blue; pixel ():
    red (0), green (0), blue (0) {} }; //RGB pixel struct

class Bitmap //The main bitmap class
{
    private:
        pixel** bitmap; //The image is here
        size_t width, height;

    public:
        Bitmap (const char* filename); //The constructor

        pixel get_pixel (size_t x, size_t y); //Returns color of the pixel at (x;y)

		//{================== "Get"-methods ===================
        size_t get_width  (); //Get image width
        size_t get_height (); //Get image height
		//}====================================================
};

#endif //BITMAP_H
