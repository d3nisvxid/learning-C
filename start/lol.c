#include <stdio.h>


//ricorsione stupida si puo fare melgio ovviamente
int count(int now){
	if(now>=10) {
		printf("%d\n", now);
		return now;
	}
	else {
		printf("%d\n", now);
		return count(++now);
	} //IN QUESTO MODO CREI UN NUOVO STACK FRAME A OGNI CHIAMATA DI COUNT, CON I GOTO SEI SEMPRE DENTRO LO STESSO FRAME
}

int main(void){

	printf("test recursion\n");
	count(0);

	int i=8;
	{
		int i=5; //la variabile in questo blocco è solo in questo scope ed è totalmente in un altro indirizzo di memoria
		if(i>3) printf("i (%zu bytes) is stored at %p\n", sizeof(i), &i);	//con & prendi l'indirizzo di memoria
	} //zu ti garantisce il massimo spazio di questa architettura, è per il tipo di ritorno (size_t) di sizeof()
	printf("i (%zu bytes) is stored at %p\n\n", sizeof(i), &i); //possiamo vedere che sono a 4 byte di distanza, da 68 a 6c


	l10: //etichetta !!!!! CI PUOI ANDARE CON GOTO COME SE FOSSE UNA JUMP
		printf("ciao\n");

	int z = 0;

	again:
		printf("%d\n", z);
		z++;
		if(z<=10) goto again;

	//stessa cosa di fare

	z = 0;
	while(z<10){
		printf("%d\n",z);
		z++;
	}

	printf("\n");

	//CICLO WHILE DOPO COMPILAZIONE
	int l=0;
	loop:
		if(l>10) goto exit;
		{
			l++; 
			printf("%d\n", l);
			goto loop;
		}
	exit:
	

	
	return 0;
}