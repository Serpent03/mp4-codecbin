#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SDL_MAIN_HANDLED
#include "SDL/include/SDL2/SDL.h"

typedef unsigned char byte;
typedef unsigned int byte_4;

#define IHDR_OFFSET 16

byte pngsig[4] = {137, 80, 78, 71};

typedef struct PNG_HDR
{
    byte* fileData;
    byte_4 width;
    byte_4 height;
} PNG_HDR ;


void printByteArray(byte* byteArr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("->%02d\n", byteArr[i]);
    }
}

byte_4 combineByteIntoInt(byte* arr)
{
    // arr[0]
    //        arr[1]
    //               arr[2]
    //                      arr[3]

    // OR OPERATION ON ALL OF THESE:
    // arr[0] arr[1] arr[2] arr[3]

    return (arr[0] << 24 | arr[1] << 16 | arr[2] << 8 | arr[3]);
}

void init_PNG_HDR(PNG_HDR* ptr)
{
    ptr->fileData = (byte *)calloc(12, sizeof(byte));
}

void read_PNG_HDR(PNG_HDR* ptr)
{
    FILE* filePointer = fopen("img.png", "rb");
    assert(filePointer != NULL);
    fread(ptr->fileData, 1, 4, filePointer);
    assert(memcmp(pngsig, ptr->fileData, sizeof(byte)) == 0);

    fseek(filePointer, IHDR_OFFSET, SEEK_SET); // move to the end of the IHDR declaration
    fread(&ptr->fileData[4], 1, 8, filePointer);

    ptr->width = combineByteIntoInt(&ptr->fileData[4]);
    ptr->height = combineByteIntoInt(&ptr->fileData[8]);

    printf("Width/Height: %d/%d", ptr->width, ptr->height);

    // printByteArray(ptr->fileData, 12);
    fclose(filePointer);
    free(filePointer);
}

int main()
{
    PNG_HDR* png_header = (PNG_HDR *)malloc(sizeof(PNG_HDR));
    init_PNG_HDR(png_header);
    read_PNG_HDR(png_header);

    //TODO: check how the compression is working under the hood.
    // sounds like concatenation of zeros to reduce file size.

    // REFER => https://gamedev.stackexchange.com/questions/102490/fastest-way-to-render-image-data-from-buffer
    // REFER => https://www.gamedev.net/forums/topic/683956-blit-a-byte-array-of-pixels-to-screen-in-sdl-fast/5320207/
    // REFER => https://progbook.org/png.html

    // nineties -> apple dark / capitola | menlo

    // get a RGBA array from this PNG file,
    // and then display it in the SDL blitting window

}