/********************************************/
/*	ArFile visa gerar um ficheiro do tipo   
	arf para que se possaincluir no programa 
	weka*/
#include "../inc/analyseinfo.h"

	//CheckDB - Returns -1 if not present and ID if present in db

// int checkDB (char* input){



// return position;
// }


void createList(char* filepath){
	
	FILE * fpdata,*fpfeatures;
    char * line1,*line2 = NULL;
    char tmp[1] , tmp2[1];
    size_t len1=0, len2=0;
    size_t read1,read2;
    int position=0, i;
    int control =0;
    int max_position = 0;

    strcpy(tmp,"");

    fpdata = fopen(filepath, "r");
    max_position=strlen(tmp);
    printf("%d\n", max_position);

    if (fpdata == NULL || fpfeatures==NULL){
    	perror("error createList");
        exit(EXIT_FAILURE);
    }
    
    while ((read1 = getline(&line1, &len1, fpdata)) != -1) {
     	printf("***%s", line1);
     	fpfeatures= fopen("mainDB/featuresDB", "a+");
     	position=0;
     	control =0;
     	 while ((read2 = getline(&line2, &len2, fpfeatures)) != -1) {
		   	 printf("ENTREI CheckDB1:%s %s\n",line1,line2);
	           if(strcmp(line1,line2) == 0){
	           	control =1;
	          	break;
	           }
	          
	          position++;	    	
          }
     	
     	if (control == 0)
     	{
     		fprintf(fpfeatures, "%s",line1);
     	}
printf("AQUI:%d %d\n", position, control);
	strcpy(tmp2, "");
     	if(position <= max_position){
     		printf("Cheguei if: %d +++%d+++\n",position, max_position);
     		tmp[position]="1";
     	}
     	else{

     		for (i=max_position; i<(position); i++){
     			printf("Cheguei else: %d +++%d+++\n",position, i);
     			strcat(tmp2, "0");
     			printf("%s", tmp2);
     			
     		}
     		
     		strcat(tmp2,"1");
     		strcat(tmp, tmp2);
     		max_position = strlen(tmp);
     		//printf("%s\n", tmp);
     	}
     	printf("%s\n", tmp);
fclose(fpfeatures);
    }
    
   //length = sizeof(app)/sizeof(int*);
   //app= (int**) realloc(app,(length)*sizeof(int*));
    
    fclose(fpdata);
}