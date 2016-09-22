/***********************************************************
 * Bitmap.h                                                *
 * Bitmap reading library                                  *
 * IMPLEMENTATION                                          *
 *                                                         *
 * Author: Artemy Belousov (aka whitemoustache, WM, whimo) *
 ***********************************************************/

#include "Bitmap.h"

Bitmap::Bitmap (const char* filename) //The constructor
{
    FILE* bmp = fopen (filename, "rb"); //Open the bitmap

    if (bmp == NULL)
        throw (char*) "Argument Exception";

    uchar_t header [header_size];
    fread (header, uchar_size, header_size, bmp); //Read the header

    if (header [0] != 'B' || header [1] != 'M')
        throw (char*) "Format exception";

    width  = *(int*) &header [18]; // | Extract image width  |
    height = *(int*) &header [22]; // |and height from header|

    size_t row_size = (width*3 + 3) & (~3); //BMP format adds 3 zero bytes after every pixels row. Remove them

    //{============== Initialize the bitmap ===============
    bitmap = new pixel* [height];
    for (size_t i = 0; i < height; i++)
        bitmap [i] = new pixel [width];
    //}====================================================

    //{=================== Read pixels ====================
    uchar_t* row = new uchar_t [row_size];

	for (int32_t i = height - 1; i >= 0; i--)
	{
		fread (row, uchar_size, row_size, bmp); //Read the pixels row by row

		for (size_t j = 0; j < width*3; j += 3)
		{
			(bitmap [j/3][i]).red   = row [j + 2]; //| BMP format stores pixels as |
			(bitmap [j/3][i]).green = row [j + 1]; //| sets of 3 bytes:            |
			(bitmap [j/3][i]).blue  = row [j];     //| 1 byte of each color        |
		}
	}
	//}===================================================
}

pixel Bitmap::get_pixel (size_t x, size_t y) {return bitmap [x][y];} //Returns color of the pixel at (x;y)

//{================== "Get"-methods ===================
size_t Bitmap::get_width  () {return width; } //Get image width
size_t Bitmap::get_height () {return height;} //Get image height
//}====================================================
