#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>

static const int kMAXBYTES { 1024 };

bool getOpt(int argc, char** argv)
{
    if ( argc < 3 ) return false; // 0

    return true; // 1
}

int main(int argc, char** argv)
{
    if ( !getOpt(argc, argv) )
    {
        fprintf(stderr, "Usage:\n%s: <inputFDfile> <outputfile>\n", (char *) *(argv+0));
        exit(EXIT_SUCCESS);
    }

    int inputFD, outputFD, restbytes;
    char* arrPtr = NULL;
    char buffer[kMAXBYTES];

    arrPtr = buffer; // assign buffer to arrPtr.

    if ( (inputFD = open(*(argv+1), O_RDONLY)) < 0 )
    {
        fprintf(stderr, "Failed to open %s\n", (char *) *(argv+1));
        exit(EXIT_FAILURE);
    }

    if ( (outputFD = open(*(argv+2), O_WRONLY | O_TRUNC | O_CREAT)) < 0 ) // Bitwise
    {
        fprintf(stderr, "Failed to open/create %s\n", (char *) *(argv+2));
    }

    while ( (restbytes = read(inputFD, buffer, kMAXBYTES)) > 0 )
    {
        write(outputFD, buffer, kMAXBYTES);
    }

    close(inputFD);
    close(outputFD);
    
    return(EXIT_SUCCESS);
}

