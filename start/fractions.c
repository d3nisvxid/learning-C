#include <stdio.h>
#include <stdlib.h>

/*numeratore
denominatore*/

/*
crea una nuova frazione setting
numerator and denominator
returning the pointer to the fraction*/
int *create_fraction(int num, int den){
	int *f =malloc(sizeof(int)*2);
	//creo un pezzo di memoria di 8 byte
	//sizeof int *2 sarebbe 8 perche sz(int)=4
	//quindi sostanzialmente posso
	//tenere due interi dentro sto f
	if(f==NULL) return NULL; //check memoria libera
	f[0] = num;
	f[1] = den;
	return f;
}

void print_fraction(int *f){
	printf("%d/%d\n", f[0], f[1]);
}

int main(void){
	int *f1 = create_fraction(1,2);
	int *f2 = create_fraction(3,4);
	print_fraction(f1);
	print_fraction(f2);



	return 0;
}