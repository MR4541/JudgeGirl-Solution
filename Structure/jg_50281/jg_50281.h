typedef struct{
    int grid[4][4];
    int spacei; //空格位置
    int spacej;
}Puzzle;

void initPuzzle(Puzzle *puzzle, int grid[4][4]);
void movePiece(Puzzle *puzzle, char direction);