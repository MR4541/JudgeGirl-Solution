#include<stdio.h>
#include<string.h>

int main(void){
    char str[1002];
    char ans[2][5] = {"no", "yes"};
    scanf("%s", str);
    int cnt3, cnt11, sign11;
    while (str[0] != '-'){
        cnt3 = 0; cnt11 = 0; sign11 = 1;
        for(int i = 0; i < strlen(str); i++){
            cnt3 += str[i] - '0';
            cnt11 += sign11 * (str[i]-'0');
            sign11 *= -1;
        }
        //printf("cnt3 %d cnt11 %d ans[n] %d\n", cnt3, cnt11, str[strlen(str)-1]-'0');
        printf("%s %s ", ans[(str[strlen(str)-1]-'0')%2==0], ans[cnt3%3==0]);
        printf("%s %s\n", ans[(str[strlen(str)-1]-'0')%5==0], ans[cnt11%11==0]);
        scanf("%s", str);
    }
    
}