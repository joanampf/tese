#ifndef ARFILE_H_INCLUDED
#define ARFILE_H_INCLUDED

#include <stdio.h>
#include <string.h>

struct App {
   int permissions[134];
   int actions[33];
   int category[16];
   int *libs;
} app;



#endif