#include "../inc/savetofile.h"
#include <stdio.h>


void saveToFile(const xmlChar* name, const xmlChar*attribute){

	FILE *f;
	char* folder = "info/";
	char* extension = ".txt";
	char path[strlen(folder)+strlen(name)+strlen(extension)+1];
	snprintf(path, sizeof(path), "%s%s%s", folder, name, extension);

    f = fopen(path, "a");

    fprintf(f, "%s %s", name, attribute);
    fclose(f);
}