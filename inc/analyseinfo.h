#ifndef ARFILE_H_INCLUDED
#define ARFILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct App {
   int *permissions;
   int *actions;
   int *category;
   int *libs;
   struct node * next;
} app;


int checkDB (char* filepath, char* input);
void fillStructure(app * data, char* filepath);


#endif