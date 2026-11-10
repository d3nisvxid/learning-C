#include <stdio.h>
#include <stdlib.h>

/*numeratore
denominatore*/

//tipo di dato aggregato
//prima volta che non manipolo numeri
//ma creo una struttura

//internal layout
// c  |  num | den 
//ogni tipo verra allineato alla dimensione
//Del tipo massimo che contiene
//in questo caso quindi avremo 12 byte
struct frac{
	unsigned char color;
	int num;
	int den;
};


//getter setter normali
void set_fraction_num(int *f, int num){
	f[0] = num;

}

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

/*non farci caso è solo per provare*/
void simplify_fraction(int *f){
	for(int d=2; d<=f[0] && d<=f[1]; d++){
		while(f[0] % d==0 &&
			f[1] % d==0)
		{
			f[0] /= d;
			f[1] /= d;
		}
	}
}

int main(void){
	printf("%d\n", (int)sizeof(struct frac));

	int *f1 = create_fraction(4,20);
	int *f2 = create_fraction(3,4);
	print_fraction(f1);
	print_fraction(f2);
	simplify_fraction(f1);
	print_fraction(f1);
	return 0;
}