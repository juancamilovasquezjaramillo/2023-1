#include <stdio.h>

int main() {
    int pos, comb1, comb2, comb3;
    
    while (1) {
        scanf("%d %d %d %d", &pos, &comb1, &comb2, &comb3);
        if (pos == 0 && comb1 == 0 && comb2 == 0 && comb3 == 0) {
            break;
        }
        int total_degrees = 0;
        total_degrees += 2 * 360;
        total_degrees= (pos - comb1 + 40) % 40;
        total_degrees += 360;
        total_degrees = (comb2 - comb1 + 40) % 40 * 9;
        total_degrees = (comb2 - comb3 + 40) % 40 * 9;
        printf("%d\n", total_degrees);
    }
    
    return 0;
}