#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//5.19 Solution

void asteriks(int);
int main(void){
    unsigned int ciz;
    printf("%s","Cizmek istediğiniz seklin sayisini giriniz:\n");
    scanf("%u", &ciz);
    asteriks(ciz);

}
void asteriks(int ciz){
    for(int i=1; i <= ciz; i++){
        for(int j=1; j<=ciz; j++){
            printf("*");
        }
        printf("\n");
    }
}


//5.19 Solution
void asteriksSekil(int ciz, char s);

int main(void){
    unsigned int ciz;
    char s;

    printf("%s", "Seklin boyutu icin giriniz(ornegin 4x4 sekil icin 4 rakam):\n");
    scanf("%u", &ciz);

    printf("%s", "Girmek istediiniz sekli belirtiniz: ");
    scanf(" %c", &s);
    asteriksSekil(ciz, s);

    return 0;
}


void asteriksSekil(int ciz, char s){
    for(int i = 1; i<=ciz; i++){
        for(int j = 1; j<= ciz; j++){
            printf("%c", s);
        }
        printf("\n");
    }

}


// 5.22.a)
int bolumBul(int bolunen, int bolen);

int main(void){
    unsigned int bolunen;
    unsigned int bolen;

    printf("%s"," Lutfen bolunen sayiyi giriniz!\n");
    scanf("%u", &bolunen);

    printf("%s","Lutfen bolen sayiyi giriniz!\n");
    scanf("%u", &bolen);

    int sonuc = bolumBul(bolunen, bolen);
    printf("bolum = %d ", sonuc);

    return 0;

}

int bolumBul(int bolunen, int bolen){
    int kalan = bolunen % bolen;
    int bolum = (bolunen - kalan) / bolen;

    return bolum;
}


// 5.22.b
int kalan(int, int);

int main(void){
    unsigned int bolunen;
    unsigned int bolen;

    printf("%s"," Lutfen bolunen sayiyi giriniz!\n");
    scanf("%u", &bolunen);

    printf("%s","Lutfen bolen sayiyi giriniz!\n");
    scanf("%u", &bolen);

    int kalanDurum =  kalan(bolunen, bolen);
    printf("Sonuc:%d", kalanDurum);

    return 0;
}

int kalan(int bolunen, int bolen){
    int kalan = bolunen - (bolunen / bolen) * bolen; //

    return kalan;

}

//5.22.C) 
void basamakAyir(int, int);

int main (void){
    unsigned int seed;
    int digCount = 0;

    printf("Random girilecek cekirdek algoritmasini giriniz:\n");
    scanf("%u", &seed);

    srand(seed);

    int num = rand();
    printf("Sayimiz:%d\n", num);
    int ayir = num;

    if(ayir < 10){
        digCount = 1;
    }else{
        while(ayir != 0){
            ayir /= 10;
            digCount++;
        }
    }
    printf("%d sayimizin basamak sayisi:%d\n", num, digCount);
    basamakAyir(num, digCount);

    return 0;
}

void basamakAyir(int num, int digCount){
    int bolunen;
    int mod;
    for(int i = digCount - 1; i >= 0; i--){
        bolunen = num / pow(10, i);
        mod = bolunen % 10;
        printf("%3d", mod);


    }

}
