#ifndef TODO_H
#define TODO_H

#include "fileutils.h"
#include <stdio.h>
#include <stdbool.h>

void add(const char *item);
void list(void);
void remove(int id);
void complete(int id);

#endif
