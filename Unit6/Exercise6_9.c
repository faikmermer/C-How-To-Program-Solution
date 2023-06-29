#include <stdio.h>

int main(void){

    int dizi[2][5] = {0};

    for(size_t i = 0; i < 2 ; i++){
        printf("dizi[%d] satirdaki elemnlari giriniz:\n", i);
        for(size_t j = 0; j < 5; j++){
            scanf("%d", &dizi[i][j]);
            printf("%zu. satir %zu. eleman dizi = %d\n", i, j, dizi[i][j]);
        }
        puts("");
    }

    int enKucuk = dizi[0][0];
    for(size_t i = 0; i < 2; i++){
        for(size_t j = 0; j < 5; j++){
            if(enKucuk >= dizi[i][j]){
                enKucuk = dizi[i][j];
                printf("%zu. satirin en kucugu %d", i, dizi[i][j]);
            }
        }
        puts("");
    }

    printf("Dizinin en kucuk degeri: %d\n", enKucuk);

    printf("%s", "dizi[0]={");
    for(int i = 0; i < 5; i++){
        printf("%d ", dizi[0][i]);
    }
    puts("}");

    int toplam = 0;
    for(int i = 0; i < 2; i++){
        printf("4.sutun elemanlari: %d\n\n\n",dizi[i][3]);
    }

    for(size_t i = 0; i < 5; i++){
        printf("%12sdizi[%zu]", "", i);
    }
    puts("");

    for(size_t i = 0; i < 2; i++){
        printf("dizi[%zu]%14s", i, "");
        for(size_t j = 0; j < 5; j++){
            printf("%d%14s", dizi[i][j], "");
        }
        puts("");
    }

    return 0;
}
