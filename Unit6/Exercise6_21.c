#include <stdio.h>
#define SIZE 10
#include <stdbool.h>

void ekonomik(int secim, int koltukNo, int kapasite[]);

void birinciSin(int secim, int koltukNo, int kapasite[]);

int main(void){

    int kapasite[SIZE] = {0};
    int secim = 0;
    bool sec = true;
    int koltukNo;


    while(sec){
        printf("\nLutfen \"birinci sinif\" icin 1'e"
               "basiniz\nLutfen \"ekonomik sinif\" icin 2'ye basiniz\n");

        scanf("%d", &secim);

        if(secim == 1){
            birinciSin(secim, koltukNo, kapasite);
        }
        if(secim == 2){
            ekonomik(secim, koltukNo, kapasite);
        }
    }

}


void ekonomik(int secim, int koltukNo, int kapasite[]){
   static int doluBos;
   if(secim == 0){
        printf("Bir sonraki ucus 3 saat onra gerceklesecektir.");
    }else if(secim == 2){
        printf("Koltuk seciniz(6-10 arasi)\n");
        scanf("%d", &koltukNo);
        if(kapasite[koltukNo - 1] != 1){
            kapasite[koltukNo - 1] = 1;
            printf("Koltuk numarasi %d secildi. Bastan %d sirada "
                   "biginize!", koltukNo, koltukNo - 1);
            ++doluBos;
        }else if(doluBos == 5){
            printf("Koltuklar dolu! birinci Siniftan Bilet almak ister misiniz?(al: 1'e bas\nVazgec: 0'a bas )\n");
            scanf("%d ", &secim);
            birinciSin(secim, koltukNo, kapasite);
        }
    }
}


void birinciSin(int secim, int koltukNo, int kapasite[]){
    static int doluBos;
    if(secim == 0){
        printf("Bir sonraki ucus 3 saat sonra!!!\n");
    }
    if(secim == 1){
        printf("Koltuk seciniz(1-5 arasi)\n");
        scanf("%d", &koltukNo);

        if(kapasite[koltukNo - 1] != 1){
            kapasite[koltukNo - 1] = 1;
            printf("Koltuk numarasi %d secildi. Bastan %d sirada "
                   "biginize!", koltukNo, koltukNo - 1);
            ++doluBos;
        }else if(doluBos == 5){
            printf("Koltuklar dolu! ekonomik Siniftan Bilet almak ister misiniz?(al: 2'e bas\nVazgec: 0'a bas )\n");
            scanf("%d", &secim);
            ekonomik(secim, koltukNo, kapasite);
        }else{
            printf("Koltuk dolu\n");
        }

    }
}
