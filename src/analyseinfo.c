/********************************************/
/*	ArFile visa gerar um ficheiro do tipo   
	arf para que se possaincluir no programa 
	weka*/
#include "../inc/analyseinfo.h"

int checkDB (char* filepath, char* input){

	FILE *fp;
	int line_num=1;
	int find_result=0; //0 if not found e 1 if found
	char temp[512];

	if((fp = fopen(filepath, "r")) == NULL) {
		return(-1);
	}

	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, input)) != NULL) {
			fclose(fp);
			return line_num;
		}
		line_num++;
	}
fclose(fp);
fp = fopen(filepath, "a");

fprintf(fp, "%s\n", input);
fclose(fp);
return 0;


}


void fillStructure(app data, char* filepath){
	
	//Permissions
	FILE * fpdata;
	FILE * fpDB;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fpdata = fopen(filepath, "r");

    fpDB = fopen("mainDB/permissionsDB", "r");

    while ((read = getline(&line, &len, fpdata)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
        line=strtok(line," - ");
        printf("%s", line);
    }

}