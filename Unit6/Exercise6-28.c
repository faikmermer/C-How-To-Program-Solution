#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

void yazdir(int array[]);

int main(void){

    int max = 20;
    int min = 1;
    srand(time(NULL));
    int binarySearch[SIZE] = {0};
    int element;

    for(size_t i = 0; i < SIZE; i++){
        element = rand() % (max + min - 1) + min;
        binarySearch[i] = element;
        
            for(size_t j = 0; j < i; j++){
                if(binarySearch[j] == binarySearch[i]){
                    binarySearch[i] = 0;
                    --i;
                    break;
                }
            }

    }
    yazdir(binarySearch);



}

void yazdir(int array[]){
    printf("%s","{");
   for(size_t i = 0; i < SIZE; i++){
        printf("%4d", array[i]);
   }
   printf("%s", " }");
}
