#include "apputils.h"

void printMenu(char *menu[]){
    printf("---------Menu---------\n");
    for (int i = 0; menu[i] != NULL; i++) printf("- %s\n", menu[i]);
}

void chooseChoice(char *choice) {
    printf("Type what u want to do, please (max 29ch): ");
    scanf("%29s", choice);
    clearBuffer();
}

void chooseName(char *name) {
    printf("Type name of the item (max 254ch): ");
    scanf("%254s", name);
    clearBuffer();
}

void chooseID(int *id){
    printf("Type *ID* of the item, please: ");
    scanf("%d", id);
    if (*id <= 0){
        printf("ERROR: ID cannot be smaller than 0");
        chooseID(id);
    }
}
