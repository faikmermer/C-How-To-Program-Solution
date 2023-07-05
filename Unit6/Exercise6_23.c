#include <stdio.h>
#include <stdbool.h>
#define SIZE 10
#define COMMAND 7

int main(){

    int yer[SIZE][SIZE] = {0};
    int com[COMMAND] = {1, 2, 3, 4, 5, 6, 9};
    int komut = 0;
    int atla = 0;
    int redFlag = 0;  // döngüden çıkmamızı sağlar
    int konum = 0;    // anlık konumun yerini verir.


    printf("Komut kodlari:\n");

    // komut verilerin yazdırılması
    for(size_t i = 0; i < COMMAND; i++){
        printf("%d\n", com[i]);
    }

    printf("Kaplumbaga koordinati yer{0, 0}\nBu yuzden ilk saga gidiniz(3)!\n");


    while(true){
        printf("\nKomut Giriniz:\n");
        scanf("%d", &komut);

        if(komut == 6){
            for(size_t i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    if(yer[i][j] == 0){
                        printf(" ");
                    }else{
                        printf("*");
                    }
                }
                puts("");
            }
        }

        if(komut == 2){              // Komut 2 geçetiğimiz yerleri işaretler
            int prevCommand = 0;    // işaretleme kalktığında önceki yönün doğrultusu ile ilerleme
            for(size_t i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    printf("Sag ve Sol donusler icin komut giriniz:\n");
                    prevCommand = komut;
                    scanf("%d", &komut);

                    switch(komut){
                        case 1:
                          if(prevCommand == 4 && konum != 0) {
                            --konum;
                          }else{     // Otomatik sağ ileri yaptığından konum artar.
                            ++konum;
                          }
                          j = konum;
                          printf("Konum: yer{%zu, %d}\n", i, konum);
                          break;
                        case 3:
                          if((konum + 1) >= SIZE ) {
                                printf("Boyut disi\nSatir Basina donuldu!");
                                konum = 0;
                          }else {
                            yer[i][konum] = 1;
                            ++konum;
                            j = konum;
                            printf("Konum: yer{%zu, %d}\n", i, konum );
                            }
                          break;
                        case 4:
                          if(konum > 0){
                            yer[i][konum] = 1;
                            --konum;
                            j = konum;
                            printf("Konum: yer{%zu, %d}\n", i, konum);
                          }
                          if(konum < 0) printf("Boyut disi\n");
                          break;
                        case 5:
                          printf("Ne kadar boslukla atlansin?\n");
                          scanf("%d", &atla);
                          printf("%d, %d\n", komut, atla);
                          if((konum + atla) > SIZE - 1){
                            printf("Boyut disi\n");
                            j = konum;
                            }else{
                              yer[i][konum + atla] = 1;
                              konum = konum + atla;
                              j = konum;
                              printf("Konum: yer{%zu, %d}\n", i, konum);
                            }
                          break;
                        case 9:
                        default:
                            break;
                    }
                    if(komut == 9){
                        redFlag = 1;
                        break;
                    }
                    if(komut == 4 && konum == 0){
                        printf("Zaten baslangic noktadasiniz!\n");
                    }
                }
                if(redFlag == 1){
                break;
                }
            }

        }
    }


    return 0;
}
