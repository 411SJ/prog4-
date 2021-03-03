//---------------------------------------
//	Sourivong Thepsimoung
//	Professor Herve
//  Program 4 - Image Operator - Dimensions
//  Due Date: 3/4/2021
//---------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "imageIO_TGA.h"
#include "RasterImage.h"

//---------------------------------------
//	Image utility functions.
//	Should be return the dimensions of the
//  image that is given.
//---------------------------------------

int main(int argc, char* argv[]){

	ImageStruct image = readTGA(argv[0]);
	//	We only work with color images
	if (image.type != RGBA32_RASTER)
	{
		printf("The file %s does not contain a color image.\n", argv[1]);
		exit(10);
	}

	for(unsigned i = 1; i < argc; i++){
		if(!strcmp(argv[i+1], "-h")){
			printf("dimensions ../Images/%s -> %d", argv[i], image.height);
		} else if(!strcmp(argv[i+1],"-w")){
			printf("dimensions ../Images/%s -> %d", argv[i], image.width);
		} else if(!strcmp(argv[i+1],"-v")){
			printf("dimensions ../Images/%s -> width: %d, height: %d", argv[i], image.width, image.height);
		} else if(!strcmp(argv[i+1],"-vh")){
			printf("dimensions ../Images/%s -> height: %d", argv[i],image.height);
		} else if(!strcmp(argv[i+1],"-wv")){
			printf("dimensions ../Images/%s -> width: %d", argv[i],image.width);
		} else if(strcmp(argv[i+1], "-")){
			printf("unknown option \n");
			exit(1);
		} else if (argc-i > 2) {
      		printf("Usage: [dimension]");
			exit(1);
		} else{
			break;
		}
	}

	return 0;
}
