#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SDL_MAIN_HANDLED
#include "SDL/include/SDL2/SDL.h"

typedef unsigned char byte;
typedef unsigned int byte_4;

void print4ByteArray(byte_4* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("->%04x\n", arr[i]);
    }
}

void printByteArray(byte* byteArr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("->%04x\n", byteArr[i]);
    }
}

int main()
{
    int byteArrSize = 8;    
    byte pngsig[8] = {137, 80, 78, 71, 13, 10, 26, 10};
    byte* fileData = (byte *)malloc(byteArrSize * sizeof(byte));
    byte* wh = (byte *)malloc(13 * sizeof(byte));

    FILE* filePointer;
    filePointer = fopen("img.png", "rb");
    assert(filePointer != NULL);
    
    fread(fileData, 1, byteArrSize, filePointer);
    assert(memcmp(pngsig, fileData, sizeof(byte)) == 0);
    fseek(filePointer, 16, SEEK_SET);
    fread(wh, 1, 13, filePointer);
    printByteArray(wh, 13);

    printf("this is a png file");

    // REFER => https://gamedev.stackexchange.com/questions/102490/fastest-way-to-render-image-data-from-buffer
    // REFER => https://www.gamedev.net/forums/topic/683956-blit-a-byte-array-of-pixels-to-screen-in-sdl-fast/5320207/
    // REFER => https://progbook.org/png.html
    // retro theme, menlo

    // read each byte and gather little-endian 4 bytes from 4 different 1 bytes

    // get a RGBA array from this PNG file,
    // and then display it in the SDL blitting window

}