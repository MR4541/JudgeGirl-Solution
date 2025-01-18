#include<stdio.h>
#include<ctype.h>

int correct(int arr1[], int arr2[], int arr3[], int len1, int len2, int len3, int mapint[]){
    int num1 = 0, num2 = 0, num3 = 0;
    for(int i = 0; i < len1; i++) 
        if(arr1[i] <= 0) num1 = num1*10 - arr1[i]; //number
        else num1 = num1*10 + mapint[arr1[i]]; //var(alphabat)
    for(int i = 0; i < len2; i++) 
        if(arr2[i] <= 0) num2 = num2*10 - arr2[i];
        else num2 = num2*10 + mapint[arr2[i]];
    for(int i = 0; i < len3; i++) 
        if(arr3[i] <= 0) num3 = num3*10 - arr3[i];
        else num3 = num3*10 + mapint[arr3[i]];
    // printf("%d * %d = %d\t\t\t", num1, num2, num3);////////////////////////////////
    return num1 * num2 == num3;
}

//n == counter; i = 1~counter-1
void solve(int i, int n, int arr1[], int arr2[], int arr3[], int len1, int len2, int len3, int mapint[], int* compflag){
    // printf("%d ", i);/////////////////////////////////
    if(i > n || *compflag) return;
    if(correct(arr1, arr2, arr3, len1, len2, len3, mapint)){
        *compflag = 1;
        for(int j = 0; j < len1; j++) 
            if(arr1[j] <= 0) printf("%d", -arr1[j]);
            else printf("%d", mapint[arr1[j]]); 
        printf(" x ");
        for(int j = 0; j < len2; j++)
            if(arr2[j] <= 0) printf("%d", -arr2[j]);
            else printf("%d", mapint[arr2[j]]);
        printf(" = ");
        for(int j = 0; j < len3; j++)
            if(arr3[j] <= 0) printf("%d", -arr3[j]);
            else printf("%d", mapint[arr3[j]]);
        printf("\n");
        return;
    }
    for(int j = 1; j <= 9; j++){
        mapint[i] = j;
        solve(i+1, n, arr1,arr2,arr3, len1,len2,len3, mapint, compflag);
    }
    mapint[i] = 1;
    return;
}

void assign(int arr[], char str[], char mapping[40], int* counter, int* len){
    int repeatflag = 0;
    for(*len = 0; str[*len] != '\0'; (*len)++){
        if(isdigit(str[*len])){
            arr[*len] = -(str[*len] - '0'); //-num表示他是數字
            continue;
        }
        repeatflag = 0;
        for(int idx = 1; idx < *counter; idx++){ //察看是否assign過
            if(mapping[idx] == str[*len]){
                arr[*len] = idx;
                repeatflag = 1;
                break;
            }
        }
        if(!repeatflag){ //new char
            mapping[*counter] = str[*len];
            arr[*len] = *counter;
            (*counter)++;
        }
    }
}

int main(){
    char str1[12], str2[12], str3[12];
    scanf("%s%s%s", str1, str2, str3);
    char mapping[40] = {0}; //重新assign變數編號給char
    int mapint[40]; //每個idx對應當前的值(0~9)是多少
    for(int i = 1; i < 40; i++) mapint[i] = 1;
    int counter = 1; //mapping 0存編了幾個數
    int arr1[12], arr2[12], arr3[12]; //從每個char改存他對應的mapping index
    int len1, len2, len3; //arri len
    assign(arr1, str1, mapping, &counter, &len1);
    assign(arr2, str2, mapping, &counter, &len2);
    assign(arr3, str3, mapping, &counter, &len3);
    mapping[0] = counter - 1; //map length

    // printf("counter %d\n", counter);
    // for(int i = 1; i <= mapping[0]; i++) printf("%c ", mapping[i]);
    // printf("\n");
    // for(int i = 0; i < len1; i++) printf("%d ", arr1[i]);
    // printf("\n");
    // for(int i = 0; i < len2; i++) printf("%d ", arr2[i]);
    // printf("\n");
    // for(int i = 0; i < len3; i++) printf("%d ", arr3[i]);
    // printf("\n");

    int compflag = 0;
    solve(1, counter, arr1,arr2,arr3, len1,len2,len3, mapint, &compflag);
}