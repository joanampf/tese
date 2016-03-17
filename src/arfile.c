
#include <stdio.h>
#include <string.h>

#include "../inc/analyseinfo.h"

int main(int argc, char **argv) {
    if (argc != 2)
        return(1);

   
   // featuresDB= (char**) malloc(sizeof(char*));
   // app= (int**) malloc(sizeof(int*));

    printf("%s\n", argv[1]);
    createList(argv[1]);

    return(0);
}