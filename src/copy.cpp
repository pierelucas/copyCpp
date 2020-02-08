// Copyright 2020 (C) Julian Huch
// Autor: Julian Huch

#include "copy.h"

//_____________________________________________________________________________
void CatFunc::CatchError(const void* ErrorMessage)
{
    perror((char*)ErrorMessage);
    free(FileName);
    free(NewFileName);
    exit(EXIT_FAILURE);
}

//_____________________________________________________________________________
void CatFunc::ProcessFile()
{
    char ErrorText[kMAXBYTE];
    memset(ErrorText, 0, kMAXBYTE);

    int inputFD, outputFD;
    char buf[1];

    if ( (inputFD = open(FileName, O_RDONLY)) < 0 )
    {
        memset(ErrorText, 0, kMAXBYTE);
        sprintf(ErrorText, "Failed to read %s\n", FileName);
        CatchError(ErrorText);
    }

    if ( (outputFD = open(NewFileName, O_CREAT | O_TRUNC | O_RDWR)) )
    {
        memset(ErrorText, 0, kMAXBYTE);
        sprintf(ErrorText, "Failed to create %s\n", NewFileName);
        CatchError(ErrorText);
    }

    while ( (read(inputFD, buf, 1)) != -1 )
    {
        if ( (write(outputFD, buf, 1)) <= 0 )
        {
            memset(ErrorText, 0, kMAXBYTE);
            sprintf(ErrorText, "Failed to write to %s\n", NewFileName);
            CatchError(ErrorText);
        }
    }

    close(inputFD);
    close(outputFD);
}

//_____________________________________________________________________________
CatFunc::CatFunc(const char* FileNamePtr, const char* NewFileNamePtr)
{
    strcpy(FileName, FileNamePtr);
    strcpy(NewFileName, NewFileNamePtr);
}

//_____________________________________________________________________________
CatFunc::~CatFunc()
{
    free(FileName);
    free(NewFileName);
}

