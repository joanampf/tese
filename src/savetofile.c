#include "../inc/savetofile.h"


void saveToFile(const xmlChar* filename, char* input){

	FILE *f;
	char* folder = "info/";
	char* extension = ".txt";
	char path[strlen(folder)+strlen((char*)filename)+strlen(extension)+1];
	snprintf(path, sizeof(path), "%s%s%s", folder, (char*)filename, extension);

    f = fopen(path, "a");

    fprintf(f, "%s\n", input);
    fclose(f);
}
