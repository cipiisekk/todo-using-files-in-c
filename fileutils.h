#ifndef FILEUTILS_H
#define FILEUTILS_H

bool checkIfOk(FILE* f, const char* what);
bool createFiles();
FILE* openTodo(const char* mode);
FILE* openTemp(const char* mode);

#endif
