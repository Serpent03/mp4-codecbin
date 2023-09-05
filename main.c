#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char byte;

static const byte pngsig[8] = {137, 80, 78, 71, 13, 10, 26, 10};

int main()
{
    int byteArrSize = 8;
    byte* fileData = (byte *)malloc(byteArrSize * sizeof(byte));

    FILE* filePointer;
    filePointer = fopen("img.png", "rb");
    assert(filePointer != NULL);
    
    // fseek(filePointer, 1, SEEK_CUR);
    fread(fileData, 1, byteArrSize, filePointer);
    assert(memcmp(pngsig, fileData, sizeof(byte)) == 0);
    printf("this is a png file");
}