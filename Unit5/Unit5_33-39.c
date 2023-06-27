#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//5.33 Solution
void tahminEt(void);
int main(void){
    int tahminSayisi = 1;
    printf("%s", "1 ile 1000 arasinda bir sayi tuttum\n ");
    printf("Tahmin etmeye calisacaksin!!!\n");
    printf("Lutfen tahminini gir\n");

    tahminEt();

    if(tahminSayisi < 10){
            puts("Sirri biliyor musun? yada sanslisin");
        }else if(tahminSayisi == 10){
            puts("Ahh! Evet sirri biliyorsun!");
        }else{
            puts("Daha iyisini yapabilirsin");
        }

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
        int tahminSayisi = 1;

        if(tahmin == sonuc){
            puts("Bingo :)");
            printf("Baska Tahmin yapmak ister misin?(e veya h)\n");
            scanf(" %c", &ConStop);
            if(ConStop == 'e'){
                sonuc = rand() % 1000 + 1;
            }
        }else if(tahmin <= sonuc){
            ++tahminSayisi;
             printf("Olmadi Tekrar deneyin!(Ama biraz yusek sayi gir)\n");

        }else{
            ++tahminSayisi;
            puts("Biraz kucuk bir sayi soyle\n");
        }


    }

}


// 5.34 Solution
int power(int, int);

int main(void){
    int base, exponent;
    printf("Ussu alinacak sayiyi giriniz:\n");
    scanf("%d", &base);

    printf("Us giriniz:\n");
    scanf("%d", &exponent);

    int sonuc = power(base, exponent);
    printf("%d uzeri %d sonucu: %d\n ", base, exponent, sonuc);
}

int power(int base, int exponent){

    if(exponent == 1){
        return base;

    }else{
        return base * power(base, exponent - 1);
    }
}


5.35 Solution
unsigned long long int fibonaci(unsigned int);

int main(void){
    int unsigned n;
    printf("Fibonacci icin sayi giriniz:\n");
    scanf("%u", &n);

    unsigned long long int sonuc = fibonaci(n);
    printf("Fibonacci serisi toplami:%llu", sonuc);

}

unsigned long long int fibonaci(unsigned int n){
    if(n == 0 || n == 1){
        return n;
    }else{
        return fibonaci(n - 1) + fibonaci(n - 2);
    }
}


// 5.36 Solution

int hanoiKule(int diskN, int basCivi, int sonCivi, int geciciCivi);

int main(void){
    int diskSayisi = 2;
    hanoiKule(diskSayisi, 1, 3, 2);

    return 0;

}

int hanoiKule(int diskN, int basCivi, int sonCivi, int geciciCivi){

    if(diskN == 1){
       printf("%d -> %d", basCivi, sonCivi);
       return ;
    }
    hanoiKule(diskN - 1, basCivi, geciciCivi, sonCivi);
    printf("\n%d -> %d\n", basCivi, sonCivi);
    hanoiKule(diskN - 1, geciciCivi, sonCivi, basCivi);

    return;

}




//5.39 Solution
int main(void){
    int x, y;

    printf("X degeri giriniz.\n");
    scanf("%d",&x);

    printf("Y degerini giriniz.\n");
    scanf("%d", &y);
    int sonuc = gcd(x, y, 0);


    return 0;

}

int gcd(int x, int y, int level){

    if(x % y == 0 || y == 0){
        printf("%*sgcd(%d, %d, %d) = %d\n", level * 5, "", x, y, level, y);
        return y;
    }
    printf("%*sgcd(%d, %d, %d)\n", level * 5, "", x, y, level + 1);

    int sonuc = gcd(y, x % y, level + 1);

    return sonuc;


}
