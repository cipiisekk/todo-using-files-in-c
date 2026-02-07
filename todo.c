void add(const char *item, int *itemCount)
{
    *(itemCount)++;
    FILE* todoFile = openTodo("a");
    if (!checkIfOk(todoFile, "Open todoFile")) return;
    fprintf(todoFile, "%d\n%s\n0\n", *itemCount, item);
    fclose(todoFile);
}

void list(void)
{
    FILE* todoFile = openTodo("r");
    if(!checkIfOk(todoFile, "Open TodoFile")) return;
    char c[255] = {0};
    int lineCount = 0;
    while (fscanf(todoFile, "%254s", c) != EOF){
        linecount++;
        if (linecount % 3 == 1) printf("ID: %s, ", c);
        if (linecount % 3 == 2) printf("%s, ", c);
        if (linecount % 3 == 0) printf("%s\n", c);
    }
    fclose(todoFile);
}

void remove(int id){
    FILE* todoFile = openTodo("r");
    if (!checkIfOk(todoFile, "Open todoFile")) return;
    FILE* tempFile = openTemp("w");
    if (!checkIfOk(tempFile, "Open tempFile")) return;

    char c[255] = {0};
    int lineCount = 0;
    while (fscanf(todoFile, "%254s", c) != EOF){
        linecount++;
        if (id == lineCount * 3 - 2 || id == lineCount * 3 - 1 || id == lineCount*3) {
            // do noth
        } else {
            fprintf(tempFile, "%s\n", c);
        }
    }
    
    fclose(todoFile);
    fclose(tempFile);

    FILE* todoFile = openTodo("w");
    if (!checkIfOk(todoFile, "Open todoFile")) return;
    FILE* tempFile = openTemp("r");
    if (!checkIfOk(tempFile, "Open tempFile")) return;
    
    while(fscaf(tempFile, "%s", c) != EOF){
        fprintf(todoFile, "%s", c);
    }
    fclose(todoFile);
    fclose(tempFile);
}

void complete(int id){
    FILE* todoFile = openTodo("r");
    if (!checkIfOk(todoFile, "Open todoFile")) return;
    FILE* tempFile = openTemp("w");
    if (!checkIfOk(tempFile, "Open tempFile")) return;

    char c[255] = {0};
    int lineCount = 0;
    while (fscanf(todoFile, "%254s", c) != EOF){
        linecount++;
        if (id == lineCount *3 ) {
            fprintf(tempFile, "1\n", c);
        } else {
            fprintf(tempFile, "%s\n", c);
        }
    }
    
    fclose(todoFile);
    fclose(tempFile);

    FILE* todoFile = openTodo("w");
    if (!checkIfOk(todoFile, "Open todoFile")) return;
    FILE* tempFile = openTemp("r");
    if (!checkIfOk(tempFile, "Open tempFile")) return;
    
    while(fscaf(tempFile, "%s", c) != EOF){
        fprintf(todoFile, "%s", c);
    }
    fclose(todoFile);
    fclose(tempFile);
}




