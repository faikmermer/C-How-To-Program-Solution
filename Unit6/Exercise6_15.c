#include <stdio.h>
#define SIZE 20

int main(void){
    unsigned int stock[SIZE];
    unsigned int prevData;
    int inputDataCount;
    int inputData = 0;


    printf("Lutfen 20 ile 100 arasi sayi giriniz:\n");
    for(size_t i = 0; i <SIZE - 1; i++){

        scanf("%u", &inputData);
        ++inputDataCount;
        stock[i] = inputData;
        prevData = stock[i - 1];

        if(inputData != prevData && inputDataCount >= 2){
            printf("%u\n", inputData);
        }
    }




}
