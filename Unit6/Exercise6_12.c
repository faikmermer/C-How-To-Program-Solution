#include <stdio.h>


int main(void){
    //a)
    int counts[10];
    for(size_t i = 0; i < 10; i++){
        counts[i] = 0;
        printf("% d ", counts[i]);
    }
    puts("");
    //b)
    int bonus[15];
    for(size_t i = 0; i < 15; i++){
        bonus[i] = 1;
        printf(" %d ", bonus[i]);
    }
    puts("");
    //c)
    float monthlyTemperatures[12];
    for(size_t i = 0; i < 12; i++){
        scanf("%f", &monthlyTemperatures[i]);
    }
    for(size_t i = 0; i < 12; i++){
        printf(" %f ", monthlyTemperatures[i]);
    }
    //d)
    int bestScores[5] = {5, 4, 3, 2, 1};
    for(size_t i = 0; i < 5; i++){
        printf("%d\n", bestScores[i]);
    }

}
