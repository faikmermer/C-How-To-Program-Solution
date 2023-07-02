#include <stdio.h>
#include <stdlib.h>
#define SIZE 13


int main(void){

    srand(time(NULL));
    int zarYuzeyi[SIZE] = {0};
    int zar1, zar2, toplam;

    for(size_t i = 0; i <= 36000; i++){
        zar1 = 1 + rand() % 6;
        zar2 = 1 + rand() % 6;
        toplam = zar1 + zar2;
        zarYuzeyi[toplam]++;

    }

    printf("     1     2     3     4     5     6\n");
    for(size_t i = 0; i < 6; i++){
            printf("%zu", i + 1 );
        for(size_t j = 2; j <= 7; j++){
            printf("%6d", zarYuzeyi[j  + i]);
        }
        puts("");
    }


}
