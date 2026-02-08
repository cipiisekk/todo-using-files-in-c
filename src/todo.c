#include "todo.h"

void addItem(const char *item, int *itemCount)
{
    (*itemCount)++;
    FILE* todoFile = openTodo("a");
    if (!checkIfOk(todoFile, "Open todoFile")) return;
    fprintf(todoFile, "%d\n%s\n0\n", *itemCount, item);
    fclose(todoFile);
    printf("Item added, use list to list all items\n");
}

void listItems(void)
{
    FILE* todoFile = openTodo("r");
    if(!checkIfOk(todoFile, "Open TodoFile")) return;
    char c[255] = {0};
    int lineCount = 0;
    printf("---------List---------\n");
    while (fscanf(todoFile, "%254s", c) != EOF){
        lineCount++;
        if (lineCount % 3 == 1) printf("ID: %s, ", c);
        if (lineCount % 3 == 2) printf("%s, ", c);
        if (lineCount % 3 == 0) printf("%s\n", c);
    }
    fclose(todoFile);
}

void removeItem(int id){
    FILE* todoFile = openTodo("r");
    if (!checkIfOk(todoFile, "Open todoFile")) return;
    FILE* tempFile = openTemp("w");
    if (!checkIfOk(tempFile, "Open tempFile")) return;

    bool completed = false;
    char c[255] = {0};
    int lineCount = 0;
    while (fscanf(todoFile, "%254s", c) != EOF){
        lineCount++;
        if (lineCount == id * 3 - 2 || lineCount == id * 3 - 1 || lineCount == id*3) {
            completed = true;
        } else {
            fprintf(tempFile, "%s\n", c);
        }
    }

    if (completed == false) {
        printf("ERROR: this ID doesnt exist!\n");
        return;
    }

    fclose(todoFile);
    fclose(tempFile);

    todoFile = openTodo("w");
    if (!checkIfOk(todoFile, "Open todoFile")) return;
    tempFile = openTemp("r");
    if (!checkIfOk(tempFile, "Open tempFile")) return;
    
    while(fscanf(tempFile, "%s", c) != EOF){
        fprintf(todoFile, "%s", c);
    }
    fclose(todoFile);
    fclose(tempFile);

    printf("Item was removed\n");
}

void completeItem(int id){
    FILE* todoFile = openTodo("r");
    if (!checkIfOk(todoFile, "Open todoFile")) return;
    FILE* tempFile = openTemp("w");
    if (!checkIfOk(tempFile, "Open tempFile")) return;

    bool completed = false;
    char c[255] = {0};
    int lineCount = 0;
    while (fscanf(todoFile, "%254s", c) != EOF){
        lineCount++;
        if (lineCount == id*3 ) {
            fprintf(tempFile, "1\n");
            completed = true;
        } else {
            fprintf(tempFile, "%s\n", c);
        }
    }

    if (completed == false) {
        printf("ERROR: this ID doesnt exist!\n");
        return;
    }
    
    fclose(todoFile);
    fclose(tempFile);

    todoFile = openTodo("w");
    if (!checkIfOk(todoFile, "Open todoFile")) return;
    tempFile = openTemp("r");
    if (!checkIfOk(tempFile, "Open tempFile")) return;
    
    while(fscanf(tempFile, "%s", c) != EOF){
        fprintf(todoFile, "%s\n", c);
    }
    fclose(todoFile);
    fclose(tempFile);

    printf("Item was set to completed!\n");
}




