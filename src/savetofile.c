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

int checkDB (char* filename, char* input){

	FILE *fp;
	int line_num=1;
	int find_result=0; //0 if not found e 1 if found

	if((fp = fopen(filename, "r")) == NULL) {
		return(-1);
	}

	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {
			fclose(fp);
			return line_num;
		}
		line_num++;
	}
fclose(fp);
fp = fopen(filename, "a");

fprintf(f, "%s\n", input);
fclose(fp);
return 0;


}
