#include<stdio.h>
//#define DEBUG

int CheckWin(int color, int x, int y, int board[5][5]){
    //color贏回傳color，否則回傳0
    int res = ((board[1][y]==board[2][y] && board[2][y]==board[3][y]) || (board[x][1]==board[x][2] && board[x][2]==board[x][3]));//橫直向確認
    res = (res || (x==y && (board[1][1]==board[2][2] && board[2][2]==board[3][3])));//檢測左上右下
    res = (res || (x+y==4 && (board[1][3]==board[2][2] && board[2][2]==board[3][1])));//檢測左下右上
    res *= color; //回傳連成線的是誰
    return res;
}

int main(){
    int step;
    scanf("%d", &step);
    int board[5][5] = {{0}}; //black 1 white -1 index 0和4做為邊界存在
    int color = 1; //每次下完*= -1
    int x, y; //下子位置
    int check = 0;
    while (step--){
        scanf("%d%d", &x, &y);
        x++; y++; //因為以1-base寫
        if(((x<1||x>3) || (y<1||y>3) || board[x][y] != 0)) continue;
        board[x][y] = color; //下棋
        check = CheckWin(color, x, y, board);

#ifdef DEBUG
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++)
                printf("%3d", board[i][j]);
            printf("\n");
        }
#endif

        switch (check){
        case 1:
            printf("Black wins.\n");
            return 0;
        case -1:
            printf("White wins.\n");
            return 0;
        }
        color *= -1; //換邊下   
    }
    printf("There is a draw.\n");
    
}