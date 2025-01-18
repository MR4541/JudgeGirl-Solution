#include<stdio.h>
#include<string.h>

/*7Segs:
  0
1   2
  3
4   5
  6
*/

//印0, 3, 6段
void HorizontalSeg(char segs[7][10], char num[12], int w, int d, int seg){ 
    for(int dig = 0; dig < strlen(num); dig++){//第幾個數字
        printf(" ");
        for(int i = 0; i < w-3; i++){//中間w-3格
            printf("%c", segs[seg][num[dig]-'0']);
        }
        printf("  ");
    }
    printf("\n");
}

//印12, 45段
void VerticalSeg(char segs[7][10], char num[12], int w, int d, int seg){
    for(int line = 2; line <= (d+1)/2 - 1; line++){
        for(int dig = 0; dig < strlen(num); dig++){
            printf("%c", segs[seg][num[dig]-'0']);
            for(int _ = 0; _ < w-3; _++) printf(" ");
            printf("%c", segs[seg+1][num[dig]-'0']);
            printf(" ");
        }
        printf("\n");
    }
}

int main(void){
    //7是燈位置，10對應數字（要印數字還是空白）
    char segs[7][10] = {
        "0 23 56789",
        "0   456789",
        "01234  789",
        "  23456 89",
        "0 2   6 8 ",
        "01 3456789",
        "0 23 56 8 "
    };
    char num[12];
    int w, d;
    while (scanf("%s%d%d", num, &w, &d) != EOF){
        //第一行
        HorizontalSeg(segs, num, w, d, 0);
        //第二到中間-1行
        VerticalSeg(segs, num, w, d, 1);
        //中間行
        HorizontalSeg(segs, num, w, d, 3);
        //中間+1到倒數第二行
        VerticalSeg(segs, num, w, d, 4);
        //最後行
        HorizontalSeg(segs, num, w, d, 6);
    }
    
}