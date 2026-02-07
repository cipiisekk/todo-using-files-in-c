#ifndef TODO_H
#define TODO_H

#include "fileutils.h"
#include <stdio.h>
#include <stdbool.h>

void add_item(const char *item, int *itemCount);
void list_items(void);
void remove_item(int id);
void complete_item(int id);

#endif
