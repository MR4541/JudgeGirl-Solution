#include<stdio.h>

int main(){
   int tmp, need, max=-1000000, min=1000000;
   scanf("%d", &need);
    while (scanf("%d", &tmp) != EOF)
    {
        //if(tmp == 99999) break;///////////

        if(need == 0){
            printf("%d\n", max);
            max=-1000000;
            min=1000000;
            need = tmp;
            continue;
        }

        need--;
        max = (tmp > max)? tmp : max;
        min = (tmp < min)? tmp : min;
    }

    if(need == 0) printf("%d\n", max);
    else if(need > 0) printf("%d\n", min);
    
}