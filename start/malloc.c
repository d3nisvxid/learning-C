#include <stdio.h>
#include <stdlib.h>


/*
this function creates a prefixed len string using malloc function
malloc will allocate memory space 
length of the string + 1 byte for its
length prefix at the beginning
then that memory space will be filled
with all the chars from the string
*/
char *ps_init(char *init, int len){
	char *s = malloc(1+len+1);
	//una volta allocata la memoria
	//il primo byte lo occupo con
	unsigned char *lenptr=(unsigned char*) s;
	//len at s[0]
	*lenptr = len;
	for(int j=0; j<len; j++){
		s[j+1] = init[j];
	}
	s[len+1] = 0; //termino la stringa
	return s;
}


void ps_print(char *s){
	unsigned char *lenptr = (unsigned char*)s;
	for(int j=0; j < *lenptr; j++){
		putchar(s[j+1]);
	}
	printf("\n");
}

int main(void){
	char *mystr = ps_init("hell\000 world", 11);
	ps_print(mystr);
	ps_print(mystr);
	free(mystr);
	return 0;
}
