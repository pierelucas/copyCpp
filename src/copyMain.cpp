// Copyright 2020 (C) Julian Huch
// Autor: Julian Huch

#include <stdbool.h>
#include <string.h>

#include "copy.h"

static char fname[kMAXBYTE];
static char newfname[kMAXBYTE];

// Parse commandline arguments. _______________________________________________
static void parseCMDArguments(int argc, char** argv)
{
    if ( argc < 3 )
    {
        fprintf(stderr, "Not enough arguments passed!\n");
        exit(EXIT_FAILURE);
    }

    if ( strlen(*(argv+1)) > 1023 || strlen(*(argv+2)) > 1023 )
    {
        fprintf(stderr, "Filename is too long!\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(fname, *(argv+1));
    strcpy(newfname, *(argv+2));
}

// Main Function. _____________________________________________________________
int main(int argc, char** argv)
{
    parseCMDArguments(argc, argv);
   
    CatFunc copyObj(fname, newfname);
    copyObj.ProcessFile();

    return EXIT_SUCCESS;
}

