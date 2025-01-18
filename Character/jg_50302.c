#include<stdio.h>
#include<string.h>

#define MY_CC 7
#define AVERAGE_CC 12.53

int find(char str[10], char table[15][10]){
    int index = 0;
    while (strcmp("", table[index]) != 0){
        if(strcmp(str, table[index]) == 0)
            return index;
        index++;
    }
    return -1;
    
}

int main(void){
    char table[15][10] = {"yi1","er4","san1","sz4","wu3","lyou4","chi1","ba1","jyou3", //0-8
                      "shr2","bai3","chyan1", //9-11
                      "wan4","yi4",""}; //12-13
    int sum=0, midsum=0, smallsum=0; //回傳sum；萬以內；個位
    char str[10]; int strid;
    while (scanf("%s", str) != EOF){
        //if(str[0] == '-') break;////////////////////////////

        strid = find(str, table);
        if(strid <= 8){
            smallsum += strid + 1;
        }else if(strid <= 11){
            for(int i = 9; i <= strid; i++){
                smallsum *= 10;
            }
            midsum += smallsum;
            smallsum = 0;
        }else if(strid == 12){
            sum += 10000 * (midsum+smallsum);
            midsum = 0;
            smallsum = 0;
        }else{
            sum += 100000000 * (midsum+smallsum);
            midsum = 0;
            smallsum = 0;
        }
    }
    sum += midsum + smallsum;
    printf("%d\n", sum);
}