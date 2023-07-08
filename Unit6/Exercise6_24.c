#include <stdio.h>
#include <stdbool.h>
#define SIZE 8

int safe(int x, int y, int mat[][SIZE]);
void knightsMap(int mat[][SIZE]);
int knightsTour(int nextRow, int nextCol, int locatin, int mat[][SIZE]);

int main(void){
    int locatin = 1;
    int prevRow = 3;
    int prevCol = 4;
    int mat[SIZE][SIZE] = {0};
    //baslangic noktasi. En iyi yolu kendiniz tercih edip düzenleyebilirsiniz.
    mat[prevRow][prevCol] = 1;
    if(knightsTour(prevRow, prevCol, locatin, mat) == 0){
        printf("%*s%s\n\n", 4, "", "Hamle alanina yer yok");
    }
    knightsMap(mat);

    return 0;
}

void knightsMap(int mat[][SIZE]){
    for(size_t i = 0; i < SIZE; i++){
        for(size_t j = 0; j < SIZE; j++){
            printf("%4d", mat[i][j]);
        }
        puts("");
    }

}

int knightsTour(int nextRow, int nextCol, int locatin, int mat[][SIZE]){

    int currentRow = 0;
    int currentCol = 0;
    int verti[8] = {-1, -2,  1,  2,  2, 1, 1, -1};
    int hori[8] = {  2, -1, -2, -1, -1, 2, 2, 2};
    int prevRow = nextRow;
    int prevCol = nextCol;


    if(locatin == SIZE * SIZE){
        return true;
    }

    for(int i = 0; i < SIZE; i++){
        currentRow = verti[i];
        currentCol = hori[i];
        nextRow = nextRow + currentRow;
        nextCol = nextCol + currentCol;
        if(safe(nextRow, nextCol, mat)){
            mat[nextRow][nextCol] = ++locatin;
        }else{ // matrix'in dışına çıkılırsa veya kare dolu ise eski konuma geri döner.
            nextRow -= currentRow;
            nextCol -= currentCol;
        }
        if( i == 7){
            // adım atılacak yer kalmadı ise programı durdur.
            if(prevRow == nextRow && prevCol == nextCol){
                break;
            }
            knightsTour(nextRow, nextCol, locatin, mat);
        }
    }


    return 0;
}

int safe(int x, int y, int mat[][SIZE]){
    if(mat[x][y] == 0 && x >= 0 && x < SIZE && y >= 0 && y < SIZE){
        return 1;
    }
    return 0;
}

