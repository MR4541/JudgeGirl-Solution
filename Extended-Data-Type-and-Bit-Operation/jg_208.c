#include <stdio.h>

int main(void){
    char cprint[2];
    int w, h;
    scanf("%d%d %c %c", &w, &h, &cprint[1], &cprint[0]);
    // printf("%d %d %c %c\n", w, h, cprint[0], cprint[1]);
    int tolcnt = 0;
    unsigned int num;
    while (scanf("%u", &num) != EOF){
        for(unsigned int i = (1 << 31); i > 0; i >>= 1){
            printf("%c", cprint[(num&i)!=0]);
            tolcnt++;
            if(tolcnt%w == 0) printf("\n");
            if(tolcnt == w*h) return 0;
        }
    }
    
}