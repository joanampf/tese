/********************************************/
/*	ArFile visa gerar um ficheiro do tipo   
	arf para que se possaincluir no programa 
	weka*/
#include "../inc/arfile.h"

void fillStructure(app data, FILE *file){
	
	char buf[256];
	while (fgets (buf, sizeof(buf), file)) {
		printf("line: %s", buf);
	}
  
}

void createArFile(){




}