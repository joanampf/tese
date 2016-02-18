
#include <stdio.h>
#include <string.h>

#include "../inc/analyseinfo.h"

void createArFile(){

}

int main(int argc, char **argv) {
    if (argc != 2)
        return(1);

    app * mainStructure;


    printf("%s\n", argv[1]);
    fillStructure(mainStructure, argv[1]);

    return(0);
}