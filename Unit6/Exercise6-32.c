#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 50

bool linearSearch(int x, size_t index, int array[]);

int main(void){
    int array[SIZE];
     size_t index;
    srand(time(NULL));

    for(size_t i = 0; i < SIZE; i++){
        array[i] = (rand() % 100) + 1;
    }
    int ara;
    printf("%s","Aranacak Sayi: ");
    scanf("%d", &ara);
    index = 0;

    if(!linearSearch(ara, index, array)){
        printf("Eleman yok\n");
    }else{
        printf("\nBingo!!!\n");
    }



}


bool linearSearch(int x, size_t index, int array[SIZE]){
    if(x == array[index]){
        printf("%d sayisi %zu siradadir.\n", x, index);
        return true;
    }
    if(index <SIZE){
        return linearSearch(x, ++index , array);
    }

    return false;
}
