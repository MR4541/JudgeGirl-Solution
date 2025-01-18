#include<stdio.h>
#include<ctype.h>

int main(void){
    char str[102];
    int cur, right, flag;
    while (scanf("%c", &str[cur]) != EOF){
        while (str[cur] != '\n'){
            cur++;
            scanf("%c", &str[cur]);
        }
        for(right = cur-1; right >= 0 && isspace(str[right]); right--);
        flag = 0;
        for(int i = 0; i <= right; i++){
            if(flag || !isspace(str[i])){
                flag = 1;
                printf("%c", str[i]);
            }
        }
        printf("\n");
        cur = 0;
    }
    
}