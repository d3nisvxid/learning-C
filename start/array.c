#include <stdio.h>
#include <limits.h>

//da capire bene lol
/*int max(size_t lol){
	size_t lunghezza = sizeof(lol) / sizeof(lol[0]);
	int massimo=INT_MIN;
	for(int i=0; i<lunghezza; i++){
		if(lol[lunghezza] > massimo) massizzzzzzzzzzzzzzzzzzzzmo=lol[lunghezza];
	}
	return massimo;
}*/

void incr(int *p){
	*p = *p+1; //assegni al indirizzo di memoria p, quello che ce in indirizzo di memoria p, +1
}

int main(void){
	//int arr[] = {1,2,3};
	//printf("il massimo valore di arr è %d\n", max(&arr));

	int x = 5;
	int *y = NULL;
	printf("x was %d\n", x);

	y = &x;
	printf("x is stored at the address: %p\n", y);
	
	*y=10; //all'indirizzo di memoria dentro y (Che è un intero per dichiarazione)
	//ci scrivi 10 ! quindi poi facendo print(x), avro 10 e non 5!
	//è stato SOVRASCRITTO come se avessi fato x=10, ma in realta l'ho fatto attraverso
	//l'indrizzo di memoria del tipo 0x323232 = 10

	printf("x now is %d and still at address %p\n", x, y);

	incr(&x); //da 10 aumenta a 11 usando direttamente il pointer senza metterlo in una var

	printf("x after increase: %d\n",x);

	return 0;


}
