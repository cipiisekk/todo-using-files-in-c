#ifndef TODO_H
#define TODO_H

#include "fileutils.h"
#include <stdio.h>
#include <stdbool.h>

void addItem(const char *item, int *itemCount);
void listItems(void);
void removeItem(int id);
void completeItem(int id);

#endif
