#include <stdio.h>
int main(){
    int cantidad;
    int tiendas;
    scanf("%i", &cantidad);
    int n;
    for(n = 0; n < cantidad; n++){
    scanf("%i",&tiendas);
    int ctiendas[99];
    int i;
    for(i=0;i<tiendas;i++){
        scanf("%i", &ctiendas[i]);
    }
    int maximo = ctiendas[0];
    int minimo = ctiendas[0];
    int r;
    for (r=0;r<tiendas;r++){
        if(ctiendas[r]<minimo){
            minimo=ctiendas[r];
        }
        if(ctiendas[r]>maximo){
            maximo=ctiendas[r];
        }
    }
    int ans;
    int form = (maximo - minimo)*2;
    ans = form;
    printf("%i\n",ans);
    }
    return 0;
}
    