//----------------------
//  Sourivong Thepsimoung
//  Professor Herve 
//  Assignment: Program 4
//  Code Taken from main function
//----------------------

#include <stdio.h>
#include <stdlib.h>	//	for malloc & calloc
#include <string.h>	//	for memcpy
//
#include "imageIO_TGA.h"
#include "RasterImage.h"

//----------------------
//	Hard-coded paths
//----------------------
#define INPUT_PATH		"../Images/bottles.tga"
#define INPUT_PATH		"../Images/Tyler.tga"
#define OUTPUT_PATH1	"../Output/out1.tga"
#define OUTPUT_PATH2	"../Output/out2.tga"


int main(int argc, char* argv[])
{
	//-----------------------------------------------------------------------------
	//	Part 1
	//	I read my image using a hard-coded path.  Obviously, you would want to
	//	get the path from the list of arguments.
	//-----------------------------------------------------------------------------
	ImageStruct image1 = readTGA(INPUT_PATH);
	
	//	We only work with color images
	if (image1.type != RGBA32_RASTER)
	{
		printf("The file %s does not contain a color image.\n", INPUT_PATH);
		exit(10);
	}

	//-----------------------------------------------------------------------------
	//	I perform some simple operations on my image
	//-----------------------------------------------------------------------------
    char input[4];
    printf("Options: -h -w -v -vh -wv END\nEND will end the program \n");
    while(1){
        scanf("%s", input);
        if (!strcmp(input, "END"))return 0;
        else if(!strcmp(input, "")){
            printf("Invalid Command.");
            return 1;
        }
        else if(!strcmp(input, "-h"))printf("dimensions -h %s -> %d \n", INPUT_PATH, image1.height);
        else if(!strcmp(input,"-w")) printf("dimensions -w %s -> %d \n", INPUT_PATH, image1.width);
		else if(!strcmp(input,"-v")) printf("dimensions -v %s -> width: %d, height: %d \n", INPUT_PATH, image1.width, image1.height);
		else if(!strcmp(input,"-vh")) printf("dimensions -vh %s -> height: %d \n", INPUT_PATH, image1.height);
		else if(!strcmp(input,"-wv"))printf("dimensions -wv %s -> width: %d \n", INPUT_PATH, image1.width);
        else{
            printf("Options: -h -w -v -vh -wv");
            return 0;
        }
    }

	//	Here I am in the main function, so all memory allocated would get freed when 
	//	I quit, but, just for the purpose of keeping good habits, I delete my rasters.
	free(image1.raster);

	
	return 0;
}

//====================================================================
#if 0
#pragma mark -
#pragma mark Image Processing Functions
#endif
//====================================================================
