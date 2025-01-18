#include<stdio.h>
#define MAXHEAP 100
 
struct Heap{
    int ary[MAXHEAP];
    int num;
};
 
void initialize(struct Heap *heap){
    heap->num = 0;
    return;
}

int removeMin(struct Heap *heap){
    int ret = heap->ary[0];
    for(int i = 1; i < heap->num; i++){
        heap->ary[i-1] = heap->ary[i];
    }
    heap->num --;
    return ret;
}
void add(struct Heap *heap, int i){
    int from = 0;
    while(from < heap->num && i >= heap->ary[from]) from++;
    for(int j = heap->num-1; j >= from; j--)
        heap->ary[j+1] = heap->ary[j];
    heap->ary[from] = i;
    heap->num ++;
}

int isFull(struct Heap *heap){
    return heap->num == MAXHEAP;
}

int isEmpty(struct Heap *heap){
    return heap->num == 0;
}

// ///////////////////////////////////
// int main(){
//     struct Heap h;
//     initialize(&h);
//     printf("%d %d\n", isFull(&h), isEmpty(&h));
//     for(int i = 100; i > 0; i--)
//         add(&h, i);
//     printf("%d %d\n", isFull(&h), isEmpty(&h));
//     for(int i = 0; i < 10; i++)
//         printf("%d ", removeMin(&h));
//     printf("\n%d %d\n", isFull(&h), isEmpty(&h));
    
// }