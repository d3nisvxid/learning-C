#include <stdio.h>

int sum(int a, int b){
   return a+b;
}

int incr(int a){
   return a+1;
}

int main(){
   setvbuf(stdout, NULL, _IONBF, 0);
   printf("welcome in calcolatrice\n");
   int num1, num2;
   printf("ins primo numero\n");
   scanf("%d", &num1);
   printf("inserisci secondo numero\n");
   scanf(" %d", &num2);
   printf("\nsum of inserted numbers: %d\n", sum(num1,num2));
   return 0;
//this is my primo programma
    
}
