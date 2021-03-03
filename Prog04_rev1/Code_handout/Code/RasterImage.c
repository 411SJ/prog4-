#include <stdio.h>
#include <stdlib.h>
//
#include "RasterImage.h"

//---------------------------------------
//	Image utility functions.
//	Should be moved to some Image.c file
//---------------------------------------
ImageStruct newImage(unsigned int width, unsigned int height, ImageType type)
{
	if (width<3 || height<3)
	{
		printf("Image size should be at least 3x3\n");
		exit(14);
	}

	ImageStruct img;
	img.width = width;
	img.height = height;
	img.type = type;
	switch (type)
	{
		case RGBA32_RASTER:
		img.bytesPerPixel = 4;
		break;
		
		case GRAY_RASTER:
		img.bytesPerPixel = 1;
		break;
		
		case FLOAT_RASTER:
		img.bytesPerPixel = sizeof(float);
		break;
	}

	img.bytesPerRow = img.bytesPerPixel * width;

	unsigned int effectiveWidth = img.bytesPerRow / img.bytesPerPixel;	
	img.raster = (void*) calloc(height*effectiveWidth, img.bytesPerPixel);

	return img;
}
