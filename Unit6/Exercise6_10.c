#include <stdio.h>
#include <stdlib.h>

#define SIZE 99

int main(void){

    int satis[SIZE];
    srand(time(NULL));
    int maxKazanc = 3000;
    int minKazanc = 200;
    int komisyon = 0;
    int satislar;

    printf("%32s", "Komisyonlar\n");

    for(size_t i = 0; i < SIZE; i++){
        satis[i] = rand() % (maxKazanc - minKazanc) + minKazanc;
        satislar = satis[i];
        komisyon = (int)(0.09 * satislar + 200);
        if(satis[i] <= 299 && satis[i] >= 200){
            printf("satis[%zu] = %d%11d\n", i, satis[i], komisyon);
        }else if(satis[i] >= 300 && satis[i] <= 399){
            printf("satis[%zu] = %d%11d\n", i, satis[i], komisyon);
        }else if(satis[i] >= 400 && satis[i] <= 499){
            printf("satis[%zu] = %d%11d\n", i, satis[i], komisyon);
        }else if(satis[i] >= 500 && satis[i] < 599){
            printf("satis[%zu] = %d%11d\n", i, satis[i], komisyon);
        }else if(satis[i] >=600 && satis[i] < 699){
            printf("satis[%zu] = %d%11d\n", i, satis[i], komisyon);
        }else if(satis[i] >=700 && satis[i] < 799){
            printf("satis[%zu] = %d%11d\n", i, satis[i], komisyon);
        }else if(satis[i] >=800 && satis[i] < 899){
            printf("satis[%zu] = %d%11d\n", i, satis[i], komisyon);
        }else if(satis[i] >=900 && satis[i] < 999){
            printf("satis[%zu] = %d%11d\n", i, satis[i], komisyon);
        }else{
            printf("satis[%zu] = %d%11d\n", i, satis[i], komisyon);
        }
    }

}
