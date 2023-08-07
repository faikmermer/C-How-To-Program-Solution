#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ROWS 12
#define COLS 12


// Labirenti temsil eden 2 boyutlu karakter dizisi
char maze[ROWS][COLS];
bool mazeTraverse(char maze[ROWS][COLS], int row, int col, int endX, int endY);
int mazeGenerator(int *endX, int *endY, int *startX, int *startY);

int main(void){
    int endx = 0, endy = 0, startx = 0, starty = 0;
    mazeGenerator(&endx, &endy, &startx, &starty);
    if(!mazeTraverse(maze, startx, starty, endx, endy)){
        printf("Not exit from the Maze!");
    }else{
        printf("Congratulations u SURVIVED");
    }




}

bool mazeTraverse(char maze[ROWS][COLS], int row, int col, int endX, int endY){
    void printMaze();

    if(row < 0 || row >= ROWS || col < 0 || col >= COLS){
        return false;
    }

    if(maze[row][col] == '.'){
        maze[row][col] = 'X';
        printMaze();

        if(row == endX && col == endY){
            return true;
        }
        if(mazeTraverse(maze, row, col + 1, endX, endY)){
            return true;
        }
        if(mazeTraverse(maze, row + 1, col, endX, endY)){
            return true;
        }
        if(mazeTraverse(maze, row, col - 1, endX, endY)){
            return true;
        }
        if(mazeTraverse(maze, row - 1, col, endX, endY)){
            return true;
        }
        maze[row][col] = '.';
        printMaze();
    }
    return false;

}
void initializeMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = '#'; // Duvarları '#' ile dolduruyoruz
        }
    }
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; ++j){
            printf("%3c", maze[i][j]);
        }
        puts("");
    }
    puts("");
}

int mazeGenerator(int *endX, int *endY, int *startX, int *startY) {

    void initializeMaze();
    srand(time(NULL));

    initializeMaze();

     *startX = rand() % ROWS;

    switch(*startX){
        case 0:
             *startY = rand() % (COLS - 2) + 1;
             *endX = ROWS - 1;
             *endY = rand() % (COLS - 2) + 1;
             maze[*startX + 1][*startY] = '.';
             maze[*endX - 1][*endY] = '.';
             break;

        case ROWS - 1:
            *startY = rand() % (COLS - 2) + 1;
            *endX = 0;
            *endY = rand() % (COLS - 2) + 1;
            maze[*startX - 1][*startY] = '.';
            maze[*endX + 1][*endY] = '.';
            break;

        default:
            *startY = 0;
            *endX = rand() % (ROWS - 2) + 1;
            *endY = COLS - 1;
            maze[*startX][*startY + 1] = '.';
            maze[*endX][*endY - 1] = '.';
            break;
    }



    maze[*startX][*startY] = '.';
    maze[*endX][*endY] = '.';



    for(int i = 1; i < ROWS - 1; ++i ){
        for(int j = 1 ; j < COLS - 1; ++j ){

             if (rand() % 3 == 0 || rand() % 2 == 0) {

                    maze[i][j] = '.';
            }
        }
    }
    printMaze();
    return 0;

}


