// 5.31 Solution

enum ZAR{TURA, YAZI};
void flip(void);

int main(void){

    flip();

}

void flip(){

    int atildi = 0;
    int yazi = 0;
    int tura = 0;

    while(atildi <= 100){
        int zar = rand() % 2;

        ++atildi;

        switch(zar){
            case TURA:
                ++tura;
                break;
            case YAZI:
                ++yazi;
                break;
        }
    }
    printf("Toplam yazi:%d\n Toplam tura:%d", yazi, tura);
}

// 5.32 Solution

void tahminEt(void);
int main(void){

    printf("%s", "1 ile 1000 arasinda bir sayi tuttum\n ");
    printf("Tahmin etmeye calisacaksin!!!\n");
    printf("Lutfen tahminini gir\n");

    tahminEt();

    return 0;
}
void tahminEt(){
    int sonuc, tahmin;
    int seed = 1;
    char ConStop = 'e';

    srand(2 * seed);
    sonuc = rand() % 1000 + 1;
    printf("%d", sonuc);

    while(ConStop == 'e'){

        scanf("%d", &tahmin);
        ++seed;

        if(tahmin == sonuc){
            puts("Bingo :)");
            printf("Baska Tahmin yapmak ister misin?(e veya h)\n");
            scanf(" %c", &ConStop);
            if(ConStop == 'e'){
                sonuc = rand() % 1000 + 1;
            }
        }else if(tahmin <= sonuc){
             printf("Olmadi Tekrar deneyin!(Ama biraz yusek sayi gir)\n");

        }else{
            puts("Biraz kucuk bir sayi soyle\n");
        }
    }

}
