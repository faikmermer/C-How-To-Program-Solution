#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 10

bool binarySearch(int first, int last, int ara, int array[]);

int main(void){
    int array[SIZE];
    size_t index;
    int ara;



    for(size_t i = 0; i < SIZE; i++){
        array[i] = (i + 1) * 3;
    }

    int first = 0;
    int last  = sizeof(array) / sizeof(array[0]);
    printf("%s","Aranacak Sayi: ");
    scanf("%d", &ara);

    if(!binarySearch(first, last, ara, array)){
        printf("Eleman yok\n");
    }else{
        printf("\nBingo!!!\n");
    }
    return 0;

}

bool binarySearch(int first, int last, int ara, int array[]){

    int mid = (last + first) / 2;
    if(last == first){
        return 0;
    }

    if(ara == array[mid]){
        printf("%d elemani %d. indiste bulunmaktadir\n", ara, mid);
        return true;
    }else if(ara < array[mid] ){
        return binarySearch(first, mid - 1, ara, array );
    }else{
       return binarySearch(mid + 1, last, ara, array);
    }

    return 0;
}
