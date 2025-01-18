#include<stdio.h>
#include<string.h>

int main(void){
    char ans[130];
    scanf("%s", ans); //輸入第一次
    char tmp[130];
    int max_repeat; //有多少位一樣
    int flag;
    while (scanf("%s", tmp) != EOF){
        //if(tmp[0]=='-' && tmp[1]=='1') break;
        max_repeat = 0;
        for(int repeat = 1; repeat <= strlen(ans) && repeat <= strlen(tmp); repeat++){
            flag = 1;
            //測試repeat次是否合
            for(int i = 0; i < repeat; i++){
                flag *= (tmp[i]==ans[strlen(ans)-repeat+i]);
            }
            max_repeat -= (max_repeat-repeat)*flag;
        }
        //printf("rep %d\n", max_repeat);//////////////////////
        strcat(ans, tmp+max_repeat);
    }
    printf("%s\n", ans);
    
}