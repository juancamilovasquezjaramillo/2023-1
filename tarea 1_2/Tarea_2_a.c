#include <stdio.h>

int main(){
    algoritmo1(100);
    return 0;
}

void algoritmo1(int n){
int i, j = 1;
for(i = n * n; i > 0; i = i / 2){
int suma = i + j;
printf("Suma %d\n", suma);
++j;
}
}