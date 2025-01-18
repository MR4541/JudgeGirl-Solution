#include<stdio.h>

int main(){
    int a,b,v,w,x,y,z;
    scanf("%d%d%d%d%d%d%d", &a,&b,&v,&w,&x,&y,&z);
    //檢測範圍 a to b+2
    int d, maxd=0, maxp=1; //折價，有最大折價率時資訊（若都是0就輸出1）
    int maxflag;
    for(int p = a; p < b+3; p++){
        //決定d值
        d = w - (w-v)*(p%2); //p = [a, b)
        d += (p >= b)*(x*(p%3==0) + y*(p%3==1) + z*(p%3==2) - d); //p = [b, b+2]

        maxflag = (d*maxp > p*maxd); //是否要更新max d/p
        maxd += (d-maxd)*maxflag;
        maxp += (p-maxp)*maxflag;
        //因為d/p相等時不會觸發，所以d/p相等一定是保留最小p，不用另外處理
    }
    printf("%d\n", maxp);
}