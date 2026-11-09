#include <stdio.h>
#include <stdlib.h> //per aver malloc
#include <stdint.h>


/*
this function creates a prefixed len string using malloc function
malloc will allocate memory space 
length of the string + 1 byte for its
length prefix at the beginning
then that memory space will be filled
with all the chars from the string
*/
char *ps_init(char *init, int len){
	char *s = malloc(4+len+1);
	//una volta allocata la memoria
	//il primo byte lo occupo con
	unsigned char *lenptr=(unsigned char*) s;
	//len at s[0]
	*lenptr = len;

	s+=4;
	for(int j=0; j<len; j++){
		s[j] = init[j];
	}
	s[len] = 0; //termino la stringa
	return s;
}


void ps_print(char *s){
	unsigned char *lenptr = (unsigned char*)s-4;
	for(int j=0; j < *lenptr; j++){
		putchar(s[j]);
	}
	printf("\n");
}

void ps_free(char *s){
	free(s-4);
}

int ps_len(char *s){
	unsigned int *lenptr=(unsigned int*)(s-4);
	return *lenptr;
}

int main(void){
	//stringa con prefix,
	//11 di lunghezza prefissata
	//metto una stringa di 11
	char *mystr = ps_init("hell\000 world", 11);
	ps_print(mystr);
	//siccome ps init ritorna il puntatore
	//alla stringa +4
	//è C compatibile visto che 
	//partendo da 4 non vede il primo byte
	//di lunghezza
	printf("%s è lunga %d\n", mystr, ps_len(mystr));
	//posso quindi ottenre la length 
	//andando a fare semplice get s-4
	ps_free(mystr);
	return 0;
}
