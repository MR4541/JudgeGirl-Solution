#include<stdio.h>

void printMap(int l, int arr[l][l]){
    for(int i = l-1; i >= 0; i--){
        for(int j = 0; j < l; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void putTile(int fromi, int fromj, int size, int vacant ,int l, int m, int arr[l][l]){
    //當前處理範圍：(fromi, fromj) ~ (fromi+size, fromj+size)
    //vacant表示有被填過的那邊，也就是中間填L形要填哪個形狀
    // OX XO OO OO
    // OO OO XO OX
    if(fromi+size/2 <= l-m || fromj+size/2 <= l-m){//in bound 
        // printMap(l, arr);
        printf("%d %d %d\n", vacant, fromj+size/2, fromi+size/2); //j=x, i=y
    }
    //中心點周圍填一個L
    if(vacant == 1){
        arr[fromi+size/2-1][fromj+size/2] = 1;arr[fromi+size/2][fromj+size/2-1] = 1;arr[fromi+size/2-1][fromj+size/2-1] = 1;
    }else if(vacant == 2){
        arr[fromi+size/2][fromj+size/2] = 1;arr[fromi+size/2-1][fromj+size/2] = 1;arr[fromi+size/2-1][fromj+size/2-1] = 1;
    }else if(vacant == 3){
        arr[fromi+size/2][fromj+size/2] = 1;arr[fromi+size/2-1][fromj+size/2] = 1;arr[fromi+size/2][fromj+size/2-1] = 1;
    }else if(vacant == 4){
        arr[fromi+size/2][fromj+size/2] = 1;arr[fromi+size/2][fromj+size/2-1] = 1;arr[fromi+size/2-1][fromj+size/2-1] = 1;
    }
    if(size == 2) return;
    //切更小塊、如果是沒有被vacant填到的那一邊就維持相同vacant
    putTile(fromi + size/2, fromj + size/2, size/2,(vacant==1)? vacant : 3, l, m, arr);
    putTile(fromi + size/2, fromj         , size/2,(vacant==2)? vacant : 4, l, m, arr);
    putTile(fromi         , fromj + size/2, size/2,(vacant==4)? vacant : 2, l, m, arr);
    putTile(fromi         , fromj         , size/2,(vacant==3)? vacant : 1, l, m, arr);
}

int main(){
    int l, m;
    scanf("%d%d", &l, &m);
    int arr[l][l]; //格子編號=左下角編號
    for(int i = 0; i < l; i++){
        for(int j = 0; j < l; j++){
            if(i >= l-m && j >= l-m) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    putTile(0, 0, l, 1, l, m, arr);
}