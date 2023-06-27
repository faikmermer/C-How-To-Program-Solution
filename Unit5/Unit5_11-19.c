#include <stdio.h>
#include <math.h>
// 5.11 Solution
int main(void){
    double sayi;

    printf("%s","Sayilari girin (Durmak için 0'ı girin)\n");

    while(1){
        printf("sayi: ");
        scanf("%lf", &sayi);

        if(sayi == 0) break;

        double yuvarlanmis_sayi = floor(sayi + 0.5);

        printf("Orjinal sayi: %.2f\n", sayi);
        printf("Yavarlanmis sayi: %.0f\n", yuvarlanmis_sayi);
    }
    return 0;

}

//5.15
double hypotenus(double, double);
int main(void){
    double kenar1, kenar2, hypo;

    printf("Lutfen kenarlari ilk kenari giriniz:");
    scanf("%lf", &kenar1);

    printf("İkinci kenari giriniz:");
    scanf("%lf", &kenar2);

    hypo = hypotenus(kenar1, kenar1);

    printf("%s%12s", "Kenar1", "Kenar2\n");
    printf("%lf%12f\n", kenar1, kenar2);

    printf("%s %lf", "Sonuc:", hypo);


    return 0;
}

double hypotenus(double kenar1, double kenar2){

    return kenar1 * kenar1 + kenar2 * kenar2;
}

// 5.16 Solution
unsigned int integerPower(int, int);

int main(void){
  unsigned int base, exponent;

  printf("%s","Base giriniz:");
  scanf("%u", &base);

  printf("%s","Us giriniz:");
  scanf("%u", &exponent);

  printf("%s%12s\n", "Base", "Us");
  printf("%u%12u", base, exponent);

  printf("\nSonuc:%u", integerPower(base, exponent));

}
unsigned int integerPower(int base, int exponent){
    int sonuc = 1;
    for(int i = 1; i <= exponent; i++){
         sonuc *= base;
    }
    return sonuc;
}


// 5.19 Solution
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
