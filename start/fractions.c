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
struct frac *create_fraction(int num, int den){
	struct frac *f =malloc(sizeof(*f));
	//creo un pezzo di memoria dei byte di frac
	if(f==NULL) return NULL; //check memoria libera
	f->num = num;
	f->den = den;
	return f;
}

void print_fraction(struct frac *f){
	printf("%d/%d\n", f->num, f->den);
}

/*non farci caso è solo per provare*/
void simplify_fraction(struct frac *f){
	for(int d=2; d<=f->num && d<=f->den; d++){
		while(f->num % d==0 &&
			f->den % d==0)
		{
			f->num /= d;
			f->den /= d;
		}
	}
}

int main(void){
	printf("%d\n\n", (int)sizeof(struct frac));

	struct frac *f1 = create_fraction(4,20);
	struct frac *f2 = create_fraction(3,4);
	print_fraction(f1);
	print_fraction(f2);
	simplify_fraction(f1);
	print_fraction(f1);
	return 0;
}