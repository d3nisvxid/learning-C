#include <stdio.h>
#include <limits.h>

int max(size_t lol){
	size_t lunghezza = sizeof(lol) / sizeof(lol[0]);
	int massimo=INT_MIN;
	for(int i=0; i<lunghezza; i++){
		if(lol[lunghezza] > massimo) massizzzzzzzzzzzzzzzzzzzzmo=lol[lunghezza];
	}
	return massimo;
}

int main(void){
	int arr[] = {1,2,3};
	printf("il massimo valore di arr è %d\n", max(&arr));
}
