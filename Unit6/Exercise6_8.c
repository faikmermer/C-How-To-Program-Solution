#include <stdio.h>
#include <stdlib.h>


int main(void){
	
   
    //ornek 6.8

    int c[100];
    srand(time(NULL));

    for(size_t i = 0; i < 100; i++){
        c[i] = rand() %10;
        printf("c[%zu] = %d\n", i, c[i]);
    }
    int toplam;
    for(size_t i = 0; i < 100; i++){
        toplam += c[i];
    }
    printf("toplam eleman: %d\n", toplam);

    int enKucuk = 100;
    for(size_t i = 0; i < 100; i++){
        if(enKucuk >= c[i]){
            enKucuk = c[i];
        }
    }
    printf("En kucuk sayimi: %d\n", enKucuk);

    int enBuyuk = 0;

    for(size_t i = 0; i < 100; i++){
        if(enBuyuk <= c[i]){
            enBuyuk = c[i];
        }
    }
    printf("En buyuk sayimiz: %d\n", enBuyuk);


    return 0;

}
