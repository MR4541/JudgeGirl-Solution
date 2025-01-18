#include<stdio.h>

#define MY_CC 2
#define AVERAGE_CC 3

int main(){
    int maxdigitsum = 0, minlength = 100, maxnum = 0;
    int pushflag;
    int num,tmp, digitsum, length;
    while(scanf("%d", &num) != EOF){
        digitsum = 0; length = 0;
        tmp = num;
        while(tmp > 0){
            length++;
            digitsum += tmp%10;
            tmp /= 10;
        }
        pushflag = ((maxdigitsum<digitsum || (maxdigitsum==digitsum && minlength>length)) 
        || (maxdigitsum==digitsum && (minlength==length && maxnum<num)));
        maxdigitsum -= pushflag*(maxdigitsum-digitsum);
        minlength -= pushflag*(minlength-length);
        maxnum -= pushflag*(maxnum-num);
    }
    printf("%d\n", maxnum);
}