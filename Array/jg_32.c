#include<stdio.h>

//helped by ChatGPT
/*
    （seq1）選from = 0 ~ n-1, to= from ~ n-1
    如果是回文則進行第二段檢測
    from2 = to+1, to2 = to+1 ~ n-1
    全跑完，只要是回文就檢查更新maxfrom, maxlen
*/

int IsPalin(int l, int r, int arr[100]){ //左閉右閉檢查
    while (l < r){
        if(arr[l] != arr[r]) //非回文
            return 0;
        l++; r--;
    }
    return 1;
}

int main(){
    int arr[100];
    int n = 0;
    while (scanf("%d", &arr[n]) != EOF){
        n++;
        //if(arr[n-1] == 99) break;
    }

    int maxfrom = 0, maxlen = 2; //arr[0], arr[1]就是最小符合情況
    int l2; //序列二開頭
    for(int l1 = 0; l1 < n-1; l1++){ //因為arr[n-1]不可能是seq1（否則seq2沒地方放）
        for(int r1 = l1; r1 < n-1; r1++){
            if(IsPalin(l1, r1, arr)){
                l2 = r1 + 1;
                for(int r2 = l2; r2 < n; r2++){
                    if(IsPalin(l2, r2, arr)){
                        //達成double palin
                        if(r2+1-l1 > maxlen || (r2+1-l1 == maxlen && l1 > maxfrom)){
                            maxlen = r2+1-l1;
                            maxfrom = l1;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < maxlen; i++){
        printf("%d", arr[maxfrom+i]);
        if(i == maxlen-1) printf("\n");
        else printf(" ");
    }
}