#include "../inc/savetofile.h"

void saveToFile(const xmlChar* filename, const xmlChar* string){

	FILE *f;
	char* folder = "info/";
	char* extension = ".txt";
	char path[strlen(folder)+strlen(filename)+strlen(extension)+1];
	snprintf(path, sizeof(path), "%s%s%s", folder, filename, extension);

    f = fopen(path, "a");

    fprintf(f, "%s\n", string);
    fclose(f);
}