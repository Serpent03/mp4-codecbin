#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SDL_MAIN_HANDLED
#include "SDL/include/SDL2/SDL.h"

typedef unsigned char byte;
typedef unsigned int byte_4;

#define IHDR_OFFSET 16

typedef struct PNG_HDR
{
    byte* fileData;
    byte_4 width;
    byte_4 height;
} PNG_HDR ;

void printByteArray(byte* byteArr, int size);
byte_4 combineByteIntoInt(byte* arr); // take in 4 consecutive bytes => add up into a single 4 byte int
void init_PNG_HDR(PNG_HDR* ptr);
void read_PNG_HDR(PNG_HDR* ptr);