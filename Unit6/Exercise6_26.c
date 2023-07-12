#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 8

int eigQueens(int row, int queens, int chess[][SIZE]);
void forbiddenMove(int row, int col, int queens, int chess[][SIZE]);
bool safe(int x, int y, int chess[][SIZE]);
void printfchess(int chess[][SIZE]);
void backtrack(int row, int queens, int chess[][SIZE]);


int main(void){

    int chess[SIZE][SIZE] = {0};
    int queens = 0;
    int row = 0;

    eigQueens(row, queens, chess);
    printfchess(chess);

}

int eigQueens(int row, int queens, int chess[][SIZE]){
    if(queens == 8){
        return 1;
    }

    for(int i = 0; i < SIZE; i++){

        if(safe(row, i, chess)){
            chess[row][i] = ++queens;
            forbiddenMove(row, i, queens, chess);
            if(eigQueens(row + 1, queens, chess)){
                return 1;
            }
            //vezir eğer hareket edemezse kareyi "0" yap.
            chess[row][i] = 0;
            //backtrack ile hamle yapılacak yerleri siliyoruz.
            backtrack(row, queens, chess);
            --queens;
        }
    }
    return 0;

}

void backtrack(int row, int queens, int chess[][SIZE]){
    for(size_t i = row; i < SIZE; i++){
        for(size_t j = 0; j < SIZE; j++){
            if(chess[i][j] == -queens){
                chess[i][j] = 0;
            }
        }
    }


}

bool safe(int x, int y, int chess[][SIZE]){

    return(chess[x][y] == 0);

}

void forbiddenMove(int row, int col, int queens, int chess[][SIZE]){

    // aynı sütuna denk gelmemesi için vezirin hareket alanını  olusturuyoruz.
    for(size_t i = row + 1 ; i < SIZE; i++){
        if(chess[i][col] < 0 || chess[i][col] > 0){
            continue;
        }
        chess[i][col] = -queens;
    }
    //aynı satira denk gelmemesi için vezirin hareket alanını  olusturuyoruz.
    for(size_t j = 0; j < SIZE; j++){
        if(chess[row][j] < 0 || chess[row][j] > 0){
            continue;
        }
        chess[row][j] = -queens;
    }
    // sağ çarpraz olarak vezirin hareket alanını  olusturuyoruz.
    int jp = col + 1;
    for(size_t i = row + 1; i < SIZE; i++){
        if(jp >= 8){
            break;
        }
        if(chess[i][jp] < 0){
            ++jp;
            continue;
        }
        chess[i][jp] = -queens;
        ++jp;
    }
    // sol çarpraz olarak vezirin hareket alanını  olusturuyoruz.
    int jn = col - 1;
    for(size_t i = row + 1; i < SIZE; i++){
        if(jn < 0){
            break;
        }
        if(chess[i][jn] < 0){
            --jn;
            continue;
        }
        chess[i][jn] = -queens;
        --jn;
    }

}

// Santranç tahtamızı yazıyoruz.
void printfchess(int chess[][SIZE]){

    for(size_t i = 0; i < SIZE; i++){
        for(size_t j = 0; j < SIZE; j++){
            if(chess[i][j] < 0){
                chess[i][j] = 0;
            }
            printf("%4d", chess[i][j]);
        }
        puts("");
    }


}
