#include<stdio.h>

#define MY_CC 6
#define AVERAGE_CC 16.57

/*
特別注意：輸入座標是(j, i)
*/

int BoundCheck(int i, int j, int h, int w){
    //檢查是否出界
    int ret = 1;
    ret *= (i>=0 && j>=0);
    ret *= (i<h  && j<w );
    return ret;
}

int main(){
    int h, w;
    scanf("%d%d", &h, &w);
    int board[500][500] = {{0}};
    int dir[8][2] = {
        {1, 1}, {-1, 1}, {1, -1}, {-1, -1},
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    }; //0-3 bishop, 4-7 rook
    int type, i, j, tmpi, tmpj;
    while (scanf("%d%d%d", &type, &j, &i) != EOF){
        if(type == -1) break;//////////////////////////////////////////////////////////
        board[i][j] = 1; //踩過
        //0->4to4   1->0to8   2->0to4   3->4to8
        for(int index = 4*(type==0 || type==3); index<4+4*(type%2==1); index++){
            tmpi = i+dir[index][0]; tmpj = j+dir[index][1];
            while (BoundCheck(tmpi, tmpj, h, w) && board[tmpi][tmpj] == 0){
                board[tmpi][tmpj] = 1;
                tmpi += dir[index][0];
                tmpj += dir[index][1];
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
}