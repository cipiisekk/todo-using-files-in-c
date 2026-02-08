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
    printf("Type ID of the item, please: ");
    if (scanf("%d", id) != 1){
        clearBuffer();
        printf("ERROR: ID isn't an integer\n");
        chooseID(id);
        return;
    }
    clearBuffer();
    if (*id <= 0){
        printf("ERROR: ID cannot be same or smaller than 0\n");
        chooseID(id);
        return;
    }
}
