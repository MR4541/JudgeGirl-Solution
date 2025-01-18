#include <stdio.h>

/*
    撞到牆先變方向
    然後再處理球之間的碰撞
    舉例
    O     |
      ↘   |
        ★｜
      ↗   |
    X     |
    球O撞牆變成往球X方向，再撞球X變往原本反方向
    撞牆角時也是同理，兩向分別處理也會變成180度

    隱憂？開局在邊界時，不一定保證開局走的第一步不會往牆外走
*/
void CheckWall(int X, int Y, int px, int py, int* dx, int* dy){ //盒子範圍、點座標、點方向
    //dx等存的是記憶體位置，每次使用都要加*
    *dx -= 2 * *dx * ((px == 1 && *dx < 0) || (px == X && *dx > 0));
    *dy -= 2 * *dy * ((py == 1 && *dy < 0) || (py == Y && *dy > 0));
}


int main(){
    int X,Y, x1,y1, x2,y2, dx1,dy1, dx2,dy2, time; //盒子範圍,點1座標值, 點2座標值, 點1方向, 點2方向
    scanf("%d%d%d%d%d%d%d%d%d%d%d", &X,&Y,&x1,&y1,&x2,&y2,&dx1,&dy1,&dx2,&dy2,&time);
    int tmpx, tmpy, collideBall; //swap用
    while(time--){ //先扣完再判斷，共執行n次(time = 0 ~ n-1)
        //先算撞牆的方向變化
        CheckWall(X, Y, x1, y1, &dx1, &dy1); //傳入記憶體位址才能直接改
        CheckWall(X, Y, x2, y2, &dx2, &dy2);

        //計算球互撞的影響（其實就兩球dxy互換）
        collideBall = (x1 == x2 && y1 == y2);
        tmpx = dx1; tmpy = dy1;
        dx1 += collideBall*(dx2 - dx1);
        dy1 += collideBall*(dy2 - dy1);
        dx2 += collideBall*(tmpx - dx2);
        dy2 += collideBall*(tmpy - dy2);

        //移動
        x1 += dx1; y1 += dy1;
        x2 += dx2; y2 += dy2;
    }
    printf("%d\n%d\n%d\n%d\n", x1, y1, x2, y2);
}