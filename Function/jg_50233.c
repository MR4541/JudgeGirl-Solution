#include<stdio.h>

#define MY_CC 7
#define AVERAGE_CC 8.54

#define MAXN 131072 //131072 = 2^17會爆

int GetLargest(int heap[MAXN], int index, int *heapSize){
    int left = index*2;//left child
    int right = index*2+1;
    int largest = index;
    largest -= (largest-left)*(left<=*heapSize&&heap[index]<heap[left]);//如果首條件不成立就會
    largest -= (largest-right)*(right<=*heapSize&&heap[largest]<heap[right]);//直接false，不會跳re
    return largest;
}

void MaxHeapify(int heap[MAXN], int index, int *heapSize){
    int largest = GetLargest(heap, index, heapSize);
    int tmp;
    while (largest != index){ //sink heap[i] to suitable place
        //swap
        tmp=heap[index];heap[index]=heap[largest];heap[largest]=tmp;
        index = largest;
        largest = GetLargest(heap, index, heapSize);//再往下搜
    }
}

void BuildMaxHeap(int heap[MAXN], int *heapSize){
    for(int i = *heapSize/2; i >= 1; i--){ //最下面那層不用排
        MaxHeapify(heap, i, heapSize);
    }
}

int HeapExtractMax(int heap[MAXN], int* heapSize){
    //因為保證不會在heap空呼叫，不用處理error
    int max = heap[1];
    heap[1] = heap[*heapSize]; //隨便丟最底下的一個上去
    //然後再sink他
    *heapSize -= 1;
    MaxHeapify(heap, 1, heapSize);
    return max;
}

void MaxHeapInsert(int heap[MAXN], int key, int *heapSize){//插入新值
    *heapSize += 1;
    int i = *heapSize; //新值接在最底下
    heap[i] = key;
    //然後浮上去
    int tmp;
    while (i>1 && heap[i/2]<heap[i]){ //父節點比較小：swap
        tmp=heap[i/2];heap[i/2]=heap[i];heap[i]=tmp;
        i/=2;
    }
}

int main(){
    int heapSize, M;
    int heap[MAXN];
    scanf("%d", &heapSize);
    for(int i = 1; i <= heapSize; i++)
        scanf("%d", &heap[i]);
    //Build and print first line
    BuildMaxHeap(heap, &heapSize);
    for(int i = 1; i <= heapSize; i++)
        printf("%d ", heap[i]);
    printf("\n");
    //M modify
    scanf("%d", &M);
    int i;
    while (M--){
        scanf("%d", &i);
        if(i == -1){
            printf("%d ", HeapExtractMax(heap, &heapSize));
        }else{
            MaxHeapInsert(heap, i, &heapSize);
        }
    }
    printf("\n");
}