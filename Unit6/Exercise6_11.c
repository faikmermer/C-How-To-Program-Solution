#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int main(void){

    srand(time(NULL));
    int dizi[SIZE];

    printf("%s", "Dizimizin orjinal hali\n");
    for(size_t i = 0; i < SIZE; i++){
        dizi[i] = (rand() % 100 - 10) + 10;
        printf("%d ", dizi[i]);
    }

    int swap = 0;

    for(size_t i = 1; i < SIZE; i++){
        for(size_t j = 0; j < SIZE - i; j++){
            if(dizi[j] > dizi[j + 1]){
                ++swap;
                int temp = dizi[j + 1];
                dizi[j + 1] = dizi[j];
                dizi[j] = temp;
            }
        }
        if(swap == 0){
            break;
        }
    }

    printf("Siralanmis dizi:\n");
    for(size_t i = 0; i < SIZE; i++){
        printf("%d ", dizi[i]);
    }

}
