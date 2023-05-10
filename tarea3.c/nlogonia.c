#include <stdio.h>
void nlogonia(){
     int veces;
     scanf("%i",&veces);
     while(veces != 0){
        int cor1, cor2, i;
        scanf("%d %d", &cor1, &cor2);
        for(i = 0; i < veces; i++){
            int corde1, corde2;
            scanf("%d %d", &corde1, &corde2);
            if (corde1 < cor1 && corde2 > cor2){
                printf("NO\n");
            } else if (corde1 < cor1 && corde2 < cor2){
                printf("SO\n");
            } else if (corde1 > cor1 && corde2 > cor2){
                printf("NE\n");  
            } else if (corde1 > cor1 && corde2 < cor2){
                printf("SE\n");
            } else {
                printf("divisa\n");
            }
        }
        scanf("%i",&veces);
     }  
}

int main(){
    nlogonia();
    return 0;
}