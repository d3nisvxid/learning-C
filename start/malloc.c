#include <stdio.h>

void ps_init(char *s, char *init, int len){
	unsigned char *lenptr=(unsigned char*) s;
	*lenptr = len;
	for(int j=0; j<len; j++){
		s[j+1] = init[j];
	} //praticamente metto al primo
	//byte del buffer la LEN cosi da
	//avere la lunghezza prefissata
	//poi ad ogni byte successivo
	//metto un char della stringa 
}


void ps_print(char *s){
	unsigned char *lenptr = (unsigned char*)s;
	for(int j=0; j < *lenptr; j++){
		putchar(s[j+1]);
	}
	printf("\n");
}

int main(void){
	char buf[256];
	ps_init(buf, "hell\000 world", 11);
	ps_print(buf);
	ps_print(buf);
	return 0;
}
