#include<stdio.h>
#include<string.h>

#define MAX(a, b) ((a) - ((a) - (b)) * ((a) < (b)))

int StrToInt(char str[]){
    int ret = 0;
    for(int i = 0; i < strlen(str); i++){
        ret *= 10;
        ret += str[i]-'0';
    }
    return ret;
}

int main(void){
    char seq[10000] = "";
    //printf("len=%d\n", strlen(seq));/////////////////
    char command[10], param[10];
    char x;
    int from;//插入第k（對k以後進行操作）
    //param可能是right, left, k
    while (scanf("%s%s", command, param) != EOF){
        //if(command[0]=='-') break;////////////////////////////////////////////////////////////////
        //printf("com %s par %s\n", command, param);////////////////////////////////
        if(strcmp(command, "insert") == 0){
            scanf(" %c", &x);//還要再多輸入x
            //" %c"讓char不會吃到空白
            if(strcmp(param, "left") == 0){
                from = 0;
            }else if(strcmp(param, "right") == 0){
                from = strlen(seq);
            }else{ //param = k
                from = StrToInt(param)-1;
            }
            //k以後全部往後推一格
            for(int i = strlen(seq); i >= from; i--){ //strlen是'\0'
                seq[i+1] = seq[i];
            }
            seq[from] = (char)x;
        }else{//delete
            if(strcmp(param, "left") == 0){
                from = 0;
            }else if(strcmp(param, "right") == 0){
                from = strlen(seq)-1; //因為是要pop他，所以要-1才是最後一項
            }else{ //param = k
                from = StrToInt(param)-1;
            }
            //k以後全部往前推一格
            for(int i = from; i < strlen(seq); i++){
                seq[i] = seq[i+1];
            }//此時'\0'不會消失所以不用補
        }

        //printf("%s, len=%d\n", seq, strlen(seq));//////////////////////////
    }

    //process output:先算連續最多是多少、再重跑有連續n次的輸出
    int max_conti = (strlen(seq) > 0);//為了處理str=""的特例（輸出0）
    int tmp_conti = 1;
    for(int i = 1; i < strlen(seq); i++){
        tmp_conti -= tmp_conti*(seq[i]!=seq[i-1]);
        tmp_conti += (tmp_conti==0 || seq[i]==seq[i-1]);
        max_conti = MAX(max_conti, tmp_conti);
    }
    int now_conti = 1;
    if(max_conti == 1) printf("%c ", seq[0]);
    for(int i = 1; i < strlen(seq); i++){
        now_conti -= now_conti*(seq[i]!=seq[i-1]);
        now_conti += (now_conti==0 || seq[i]==seq[i-1]);
        if(now_conti == max_conti) printf("%c ", seq[i]);
    }
    printf("%d", max_conti);
    
}