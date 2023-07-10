#include <stdio.h>
#include <stdbool.h>
#define SIZE 8

int safe(int x, int y, int mat[][SIZE]);
void knightsMap(int mat[][SIZE]);
bool knightsTour(int nextRow, int nextCol, int locatin, int mat[][SIZE]);

int main(void){
    int locatin = 1;
    int prevRow = 0;
    int prevCol = 0;
    int mat[SIZE][SIZE] = {0};
    // başlangıç noktası. En iyi yolu kendiniz tercih edip düzenleyebilirsiniz.
    mat[prevRow][prevCol] = 1;
    if(!knightsTour(prevRow, prevCol, locatin, mat)){
        printf("%*s%s\n\n", 4, "", "Hamle alanına yer yok");
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

bool knightsTour(int nextRow, int nextCol, int locatin, int mat[][SIZE]){
    if(locatin == SIZE * SIZE){
        return true;
    }

    int verti[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int hori[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for(int i = 0; i < SIZE; i++){
        int currentRow = verti[i];
        int currentCol = hori[i];
        nextRow = nextRow + currentRow;
        nextCol = nextCol + currentCol;
        if(safe(nextRow, nextCol, mat)){
            mat[nextRow][nextCol] = ++locatin;
            if(knightsTour(nextRow, nextCol, locatin, mat)){
                return true;
            }
            mat[nextRow][nextCol] = 0; 
            --locatin;
        }
        nextRow -= currentRow;
        nextCol -= currentCol;
    }

    return false;
}

int safe(int x, int y, int mat[][SIZE]){
    if(x >= 0 && x < SIZE && y >= 0 && y < SIZE && mat[x][y] == 0){
        return 1;
    }
    return 0;
}
