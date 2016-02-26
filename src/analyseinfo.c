/********************************************/
/*	ArFile visa gerar um ficheiro do tipo   
	arf para que se possaincluir no programa 
	weka*/
#include "../inc/analyseinfo.h"


	//CheckDB - Returns -1 if not present and ID if present in db

int checkDB (char* input){

int i=0;

  while (featuresDB[i] != NULL) {
        printf("features checkDB: %s", featuresDB[i]);
        printf("Input checkDB: %s\n", input);

        if(strcmp(featuresDB[i],input) == 0)
        	return i;
        i++;
        printf("Resulado compara:%d\n", i);
        printf("features checkDBfinal: %s\n", featuresDB[i]);	    	
          }
i++;
printf("%d",i);
featuresDB = (char**) realloc(featuresDB,(i+1)*sizeof(char*));
featuresDB[i-1]= (char*) malloc (100*sizeof(char));
strcpy(featuresDB[i-1], input);
featuresDB[i]=NULL;
printf("After:%s", featuresDB[i-1]);

return i;
}


void createList(char* filepath){
	
	FILE * fpdata;
    char * line = NULL;
    size_t len = 0;
    size_t read;
    int position=0;
    int length=0;
    //char * path = "Info/com.whatsapp.txt";

    fpdata = fopen(filepath, "r");
    if (fpdata == NULL){
    	perror("error createList");
        exit(EXIT_FAILURE);
    }

    
    printf("%d\n", length);

    app= (int**) realloc(app,(length+1)*sizeof(int*));

    while ((read = getline(&line, &len, fpdata)) != -1) {
    
        line=strtok(line,";");
     	line=strtok(NULL,";");
     	printf("***%s", line);
     	position=checkDB(line);
     	printf("%s\n", featuresDB[position]);
    }

}