#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Pointer Array points to two char arrays
    void* arrayPtr[2];

    char arrayTwo[10] = "Hello";
    char arrayOne[10] = "World";

    *(arrayPtr+0) = arrayOne;
    *(arrayPtr+1) = arrayTwo;

    printf("%s\n", *(arrayPtr+0));
    printf("%s\n", *(arrayPtr+1));

    return 0;
}
