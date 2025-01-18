#include<stdio.h>
#include<string.h>

int main(void){
    char str1[82], str2[82];
    char ans[2][5] = {"no", "yes"};
    int n;
    scanf("%d", &n);
    int i, dif;
    int sameflag = 0;
    int swapflag = 0;
    int vacantflag = 0;
    while (n--){
        scanf("%s%s", str1, str2);
        i = 0; sameflag = swapflag = vacantflag = 0;
        //停下來直到搜完或出現不同解
        while ((i<strlen(str1)&&i<strlen(str2)) && str1[i]==str2[i]){
            i++;
        }
        //全同或最後差一個
        if((i==strlen(str1)&&i==strlen(str2)) && (strlen(str1)-strlen(str2)<2 && strlen(str1)-strlen(str2)>-2)){
            sameflag = 1;
        }else if(str1[i]==str2[i+1]&&str1[i+1]==str2[i]){ //出現不同解、停下來看是不是ab.ba
            swapflag = 1;
            i += 2;
            for(;i<strlen(str1)&&i<strlen(str2);i++){
                if(str1[i]!=str2[i]){
                    swapflag = 0;
                    break;
                }
            }
            swapflag *= (strlen(str1)==strlen(str2));
        }else{
            dif = 1*(str1[i]==str2[i+1]) -1*(str1[i+1]==str2[i]);
            i += (str1[i+1]==str2[i]);
            vacantflag = 1;
            for(;i<strlen(str1);i++){
                if(str1[i]!=str2[i+dif]){
                    vacantflag = 0;
                    break;
                }
            }
            vacantflag *= (strlen(str1)+dif == strlen(str2));
        }

        printf("%s\n", ans[vacantflag || (swapflag || sameflag)]);
    }
}