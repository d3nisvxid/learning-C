#include <stdio.h>


//primo approccio agli args
//Da approfondire
//primo parametro quanti
//Secondo puntatore ai args stessi
int main(int argc, char **argv){
	if(argc!=2){
		printf("Missing file name\n");
		return 1;
	}
	
	//apro file all'arg 1 come read
	FILE *fp = fopen(argv[1], "r");
	if(fp==NULL){
		printf("\nfile dosent exist\n");
		return 1;
	}



	fclose(fp);
	return 0;


	for(int i=0; i<argc;i++){
		printf("%d: %s\n", i, argv[i]);
	}
}