#include <stdio.h>

int main()
{
    algoritmo2(100);
    return 0;
}
int algoritmo2(int n){
    int res = 1, i, j;

    for(i = 1; i <= 2 * n; i += 4)
        for(j = 1; j * j <= n; j++)
            res += 2;
    return res;
}
