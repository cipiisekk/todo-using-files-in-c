#include "strutils.h"
#include "fileutils.h"
#include "todo.h"
#include "apputils.h"

#include <stdio.h>
#include <stdbool.h>

void app(void){
    if(createFiles()) {
        printf("Files has been created succesfully!\n");
    } else {
        return;
    }

    char *menu[6] = {"add","remove","list","complete","end", NULL};
    int id = 0, itemCount = 0;
    char choice[30] = {0};
    char itemName[255] = {0};

    while (1){

        printMenu(menu);
        chooseChoice(choice);

        if (isSame(choice, menu[0])) {

            chooseName(itemName);
            add_item(itemName, &itemCount);

        } else if (isSame(choice, menu[1])) {

            chooseID(&id);
            remove_item(id);

        } else if (isSame(choice, menu[2])) {

            list_items();
        
        } else if (isSame(choice, menu[3])) {

            chooseID(&id);
            complete_item(id);

        } else if (isSame(choice, menu[4])) {
            return;
        }
    
    }
}

int main(void){
    app();
    return 0;
}
