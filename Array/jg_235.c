#include<stdio.h>

#define TLE

int GCD(int a, int b){ //黑魔法
    if(b == 0) return a; //不加會爛
    while((a%=b) && (b%=a));
    return a+b;
}

int main(){
    int n; //number of layer
    scanf("%d", &n);
    int prev_p[16][2] = {{0}}; //上一層機率//0是分子1是分母
    int p[16][2] = {{0}}; //機率（第i層後會用到0~i）
    prev_p[0][0] = 1;
    prev_p[0][1] = 1;
    int pl, pr, gcd;//左右機率
    int tmp0, tmp1; //運算用分子分母
    for(int layer = 1; layer <= n; layer++){
        for(int i = 0; i < layer; i++){ //layer個pin
            scanf("%d%d", &pl, &pr);
            gcd = GCD(pl, pr);
            pl /= gcd;
            pr /= gcd;
            //printf("layer %d pin %d gcd %d pl %d pr %d\n", layer, i, gcd, pl, pr); /////////////////////////////////////////////////////////////////
            //左邊
            tmp0 = prev_p[i][0]*pl; tmp1 = prev_p[i][1]*(pl+pr);
            //tmp取gcd
            gcd = GCD(tmp0, tmp1);
            tmp0 /= gcd; tmp1 /= gcd;
            //printf("prev_i0 %d, prev_i1 %d, tmp0 %d, tmp1 %d\n", prev_p[i][0], prev_p[i][1], tmp0, tmp1); ////////////////////////////////////////////////////////
            if(p[i][0] == 0 || p[i][1] == 0){ //p[i] = 0
                p[i][0] = tmp0; p[i][1] = tmp1;    
            }else{ //本身已有值：分數加法
                //printf("tmp0 %d*p[i][1] %d + tmp1 %d*p[i][0] %d\n",tmp0, p[i][1], tmp1, p[i][0]);///////////////////////////////////////
                p[i][0] = tmp0*p[i][1] + tmp1*p[i][0];
                p[i][1] = p[i][1]*tmp1;
            }
            //左邊進行約分
            gcd = GCD(p[i][0], p[i][1]);
            p[i][0] /= gcd; p[i][1] /= gcd;
            //右邊：一定是新值+0
            tmp0 = prev_p[i][0]*pr; tmp1 = prev_p[i][1]*(pl+pr);
            //tmp取gcd
            gcd = GCD(tmp0, tmp1);
            tmp0 /= gcd; tmp1 /= gcd;
            p[i+1][0] = tmp0; p[i+1][1] = tmp1;;
            //右邊進行約分
            gcd = GCD(p[i+1][0], p[i+1][1]);
            p[i+1][0] /= gcd; p[i+1][1] /= gcd;
        }
        for(int i = 0; i <= layer; i++){ //push
            prev_p[i][0] = p[i][0];
            prev_p[i][1] = p[i][1];
            p[i][0] = 0; p[i][1] = 0;//清空
        }

        // for(int i = 0; i <= layer; i++){ /////////////////////////////////////////////////////////////////
        //     printf("%d/%d\n", prev_p[i][0], prev_p[i][1]);
        // }
        // printf("\n");
    }

    for(int i = 0; i <= n; i++){
        printf("%d/%d\n", prev_p[i][0], prev_p[i][1]);
    }
}