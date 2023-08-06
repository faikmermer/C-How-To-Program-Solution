#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ROWS 12
#define COLS 12
#define PATH 2
bool mazeTraverse(char maze[ROWS][COLS], int row, int col);

/*
// Labirenti temsil eden 2 boyutlu karakter dizisi
char maze[ROWS][COLS];

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
}

int main() {
    srand(time(NULL));

    initializeMaze();

    int startX = rand() % (ROWS - 2) + 1;
    int startY = 0;

    int endX = rand() % (ROWS - 2) + 1;
    int endY = COLS - 1;

    maze[startX][startY] = '.';
    maze[endX][endY] = '.';

    for(int i = 1; i < ROWS - 1; ++i){
        for(int j = 1; j < COLS - 1; ++j){
            if(i == startX && j == startY) continue;
            if(i == endX && j == endY) continue;

            if(rand() % 2 == 0 || rand() % 3 == 0){
                maze[i][j] = '.';
            }
        }
    }
    printMaze();
    return 0;
}
*/
void printMaze(char maze[ROWS][COLS]);

void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; ++j){
            printf("%3c", maze[i][j]);

        }
        puts("");
    }
}

int main() {
    char maze[ROWS][COLS] = {
    "############",
    "#...#......#",
    "..#.#.####.#",
    "###.#....#.#",
    "#....###.#..",
    "####.#.#.#.#",
    "#..#.#.#.#.#",
    "##.#.#.#.#.#",
    "#........#.#",
    "######.###.#",
    "#......#...#",
    "############"
    };
    mazeTraverse(maze, 2, 0);
    return 0;
}

bool mazeTraverse(char maze[ROWS][COLS], int row, int col){
    void display(char maze[ROWS][COLS]);

    if(row < 0 || row >= ROWS || col < 0 || col >= COLS){
      return false;
    }

    if(maze[row][col] == '.'){
      maze[row][col] = 'X';
      display(maze);

      if(row == 0 || row == ROWS - 1 || col == COLS - 1){
        return true;
      }

      if(mazeTraverse(maze, row, col + 1)){
        return true;
      }
      if(mazeTraverse(maze, row + 1, col)){
        return true;
      }
      if(mazeTraverse(maze, row, col - 1)){
        return true;
      }
      if(mazeTraverse(maze, row - 1, col)){
        return true;
      }
      maze[row][col] = '.';
   }
    return false;
}



void display(char maze[ROWS][COLS]){
    for(int i = 0; i < ROWS; ++i){
        for(int j = 0; j < COLS; ++j){
            printf("%c ", maze[i][j]);
        }
        puts("");
    }
    puts("");

}

