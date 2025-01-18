#include <stdio.h>

#define Abs(x) (x - 2*(x)*((x)<0)) //define是直接換詞，所以要把輸入(x)，跟整個輸出都括弧起來避免誤判

void Draw(int x1, int y1, int x2, int y2, int X, int Y, int grid[X][Y]){ 
    //printf("call draw");///////////////////////////////////
    int Udx = (x2 == x1)? 0 : (x2-x1)/Abs(x2-x1);
    int Udy = (y2 == y1)? 0 : (y2-y1)/Abs(y2-y1); //Unit_dxy
    //printf("%d, %d: %d / %d, %d %d / %d\n", x2-x1, Udx, x2-x1, Abs(x2-x1), Udy, y2-y1, Abs(y2-y1));
    for(int i = 0; i <= Abs(x2-x1) || i <= Abs(y2-y1); i++){
        grid[x1 + i*Udx][y1 + i*Udy] = 1;
        //printf("%d %d\n", x1 + i*Udx, y1 + i*Udy);
    }
}


int main(){
    int L, X, Y;
    scanf("%d%d%d", &L, &Y, &X); //發現我整個操作反了，直接改YX比較快
    int grid[X][Y]; //x是橫軸所以處理要變成for j = Y-1 ~ 0 / i = 0 ~ X-1
    for(int j = Y-1; j >= 0; j--){
        for(int i = 0; i < X; i++){
            grid[i][j] = 0;
            //printf("(%d,%d) ", i, j);
        }
        //printf("\n");
    }
    int prev_x, prev_y, curr_x, curr_y, n; //存畫圖點
    for(int Lnow = 1; Lnow <= L; Lnow++){ 
        scanf("%d%d%d", &n, &prev_x, &prev_y); //第一組存到prev，後面存到curr
        if((prev_x>=X || prev_x<0) || (prev_y>=Y || prev_y<0)){ //Out of bound
            printf("ERROR %d %d\n", Lnow, 1);
            return 0; //直接結束程式
        }
        for(int Nnow = 2; Nnow <= n; Nnow++){
            scanf("%d%d", &curr_x, &curr_y);
            int dx = curr_x - prev_x; //計算繪圖方向與判斷輸入合法
            int dy = curr_y - prev_y;
            if((prev_x>=X || prev_x<0) || (prev_y>=Y || prev_y<0)){ //Out of bound
                printf("ERROR %d %d\n", Lnow, Nnow);
                return 0;
            }else if(Abs(dx)!=Abs(dy) && (dx!=0 && dy!=0)){ //Not ver/hor/45degree (p1 == p2 is ok)
                printf("ERROR %d %d\n", Lnow, Nnow);
                return 0;
            }else{
                Draw(prev_x, prev_y, curr_x, curr_y, X, Y, grid);//畫圖
            }

            //prev <- curr
            prev_x = curr_x;
            prev_y = curr_y;
        }
    }
    for(int j = Y-1; j >= 0; j--){
        for(int i = 0; i < X; i++){
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}