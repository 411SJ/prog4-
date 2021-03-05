//----------------------
//	Sourivong Thepsimoung
//  Professor Herve 
//  Assignment: Program 4.3 Rotate
//  Code Taken from main function
//----------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imageIO_TGA.h"
#include "RasterImage.h"

//----------------------------------------------------------------------
//  Function Protoypes
//----------------------------------------------------------------------
void rotate90right(ImageStruct *img1, ImageStruct *img2);
void rotate90left(ImageStruct *img1, ImageStruct *img2);
void rotate180(ImageStruct *img1, ImageStruct *img2);

// function to rotate image 90 degree right
void rotate90right(ImageStruct *image1, ImageStruct *image2){
    int *rstr1 = (int*)(image1->raster);
    int *rstr2 = (int*)(image2->raster);
    for(unsigned i = 0; i < image1->height-1; i++){
        for(unsigned j = 0; j < image1->width; j++){
            rstr2[(image2->height-j-1)*image2->width+i]=rstr1[i*image2->width+j];
        }
    }

}


// function to rotate image 90 degree left
void rotate90left(ImageStruct *image1, ImageStruct *image2){
    int* raster1 = (int*)(image1->raster);
	int* raster2 = (int*)(image2->raster);
    for(unsigned i = 0; i < image1->height-1; i++){
        for(unsigned j = 0; j < image1->width; j++){
            raster2[j*image2->width+image2->width-i-1] = raster1[i*image1->width+j];
        }
    }
}

//	mirror function that was copied from the main function
void rotate180(ImageStruct* image1, ImageStruct* image2){
	int* raster1 = (int*)(image1->raster);
	int* raster2 = (int*)(image2->raster);
	unsigned int effectiveWidth  = image1->bytesPerRow / image1->bytesPerPixel;
    for (unsigned int i=0, mirrorI=image1->height-1; i<image1->height; i++, mirrorI--){
		for (unsigned int j=0; j<image1->width; j++){
            raster2[i*effectiveWidth + j] = raster1[mirrorI*effectiveWidth + j];	
        }
	}
}

int main(int argc, char *argv[]){

    printf("Reading in Rasters . . . \n");
    ImageStruct image1 = readTGA(argv[1]);
    ImageStruct image2 = newImage(image1.width, image1.height, RGBA32_RASTER);

    //	We only work with color images
	if (image1.type != RGBA32_RASTER)
	{
		printf("The file %s does not contain a color image.\n", argv[1]);
		exit(10);
	}


    printf("Determining which roatation to make. \n");
    if(argc > 3 || argc < 2){
        printf("Usage: [FILENAME] [-r -rr -l -ll] \n");
        exit(1);
    } else if((!strcmp(argv[2],"-l") || (!strcmp(argv[2], "-L")))){
        printf("Rotating the image left by 90 degrees...\n");
        rotate90left(&image1,&image2);
        writeTGA("../Output/myImage[L].tga", &image2);
    } else if ((!strcmp(argv[2],"-r") || (!strcmp(argv[2], "-R")))){
        printf("Rotating the image right by 90 degrees...\n");
        rotate90right(&image1, &image2);
        writeTGA("../Output/myImage[R].tga", &image2);
    } else if ((!strcmp(argv[2],"-ll") || (!strcmp(argv[2], "-LL") || (!strcmp(argv[2],"-rr")) || (!strcmp(argv[2],"-RR"))))){
        printf("Rotating the image by 180 degrees...\n");
        rotate180(&image1, &image2);
        printf("The file is outputted...\n");
        writeTGA("../Output/myImage[LL].tga" ,&image2);

    } else{
        printf("Invalid rotation specifier...\n");
        exit(1);
    }


    free(image1.raster);
	free(image2.raster);

    return 0;
}