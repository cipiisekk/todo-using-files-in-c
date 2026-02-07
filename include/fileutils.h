#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "config.h"
#include <stdio.h>
#include <stdbool.h>

bool checkIfOk(FILE* f, const char* what);
bool createFiles(void);
FILE* openTodo(const char* mode);
FILE* openTemp(const char* mode);

#endif
