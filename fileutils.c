#include "fileutils.h"

bool checkIfOk(FILE* f, const char* what){
    if (f == NULL) {
        perror(what);
        return false;
    }
    return true;
}

FILE* openTodo(const char* mode){
    FILE* f = fopen(FILENAME FILEEXTENSION,mode);
    return f;
}

FILE* openTemp(const char* mode){
    FILE* f = fopen(FILENAME".temp",mode);
    return f;
}

bool createFiles(void){
    FILE *todoFile = openTodo("w");
    if(!checkIfOk(todoFile,"openTodo")) return false;
    fclose(todoFile);
    
    FILE *tempFile = openTemp("w");
    if(!checkIfOk(tempFile,"openTemp")) return false;
    fclose(tempFile);

    return true;
}
