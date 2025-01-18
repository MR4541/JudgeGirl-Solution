#include <stdio.h>
 
#define MY_CC 6
#define AVERAGE_CC 7.72

typedef struct{
    int grid[4][4];
    int spacei; //空格位置
    int spacej;
}Puzzle;

void initPuzzle(Puzzle *puzzle, int grid[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            puzzle->grid[i][j] = grid[i][j];
            if(grid[i][j] == 0){
                puzzle->spacei = i;
                puzzle->spacej = j;
            }
        }
    }
}

void getDir(char dir, int *di, int *dj){
    *di = (dir == 'D') - (dir == 'U');
    *dj = (dir == 'R') - (dir == 'L');
    return;
}

void movePiece(Puzzle *puzzle, char direction){
    int di, dj;
    getDir(direction, &di, &dj);
    //move out of bound
    if((puzzle->spacei+di < 0 || puzzle->spacei+di > 3)
    || (puzzle->spacej+dj < 0 || puzzle->spacej+dj > 3)){
        printf("Invalid move\n");
        return;
    }
    puzzle->grid[puzzle->spacei][puzzle->spacej] = puzzle->grid[puzzle->spacei+di][puzzle->spacej+dj];
    puzzle->grid[puzzle->spacei+di][puzzle->spacej+dj] = 0;
    puzzle->spacei += di; puzzle->spacej += dj;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", puzzle->grid[i][j]);
        }
        printf("\n");
    }
}
 
// ///////////////////////////////////////////
// int main(void) {
//     int grid[4][4] = {0};
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             scanf("%d", &grid[i][j]);
//         }
//     }
//     Puzzle puzzle;
//     initPuzzle(&puzzle, grid);
//     int numMoves;
//     scanf("%d", &numMoves);
//     char move;
//     for (int i = 0; i < numMoves; i++) {
//         scanf(" %c", &move);
//         movePiece(&puzzle, move);
//     }
//     return 0;
// }