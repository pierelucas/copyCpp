// Copyright 2020 (C) Julian Huch
// Autor: Julian Huch

#ifndef COPY_H_
#define COPY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <string>

typedef unsigned int uint;
typedef unsigned long ulong;
typedef __off_t off_t;

static const int kMAXBYTE = 1024;

class CatFunc
{
    private:
        char FileName[kMAXBYTE] = {0L};
        char NewFileName[kMAXBYTE] = {0L};

        void CatchError(const void* ErrorMessage);

    public:
        CatFunc(const char* FileNamePtr, const char* NewFileNamePtr);
        ~CatFunc();

        void ProcessFile();
};

#endif // COPY_H_

