#include<stdio.h>
#include<stdlib.h>
#include"memory.h"
// #define DEBUG

Memory* genBlock(int start, int length, Memory* next){
    Memory* new = (Memory*)malloc(sizeof(Memory));
    new->start = start;
    new->length = length;
    new->next = next;
    return new;
}

void initMemory(Memory *memory, int length){
    memory->start = 0;
    memory->length = length;
    memory->next = NULL;
}

void printMemory(Memory *memory){
    printf("==========\n");
    if(memory->start == -1) return; //////(head) memory == NULL
    Memory* tmp = memory;
    while(tmp != NULL){
        printf("start %d, length %d\n", tmp->start, tmp->length);
        tmp = tmp->next;
    }
}

void allocateMemory(Memory *memory, int start, int length){
    //先找到不大於start的那塊memory now
    Memory *last = NULL, *now = memory;
    while(start < now->start || start >= now->start + now->length){ //不在此區段中
        last = now;
        now = now->next;
    }
    //檢測1頭是否相同、2尾是否相同（已知欲分配的memory必定不會溢出last的範圍）
    int sameStart = (now->start == start);
    int sameEnd = (now->start + now->length == start + length);
    if(sameStart && sameEnd){ //直接消失掉now
        //記得處理特例
        if(last == NULL){
            if(memory->next != NULL){ //list len > 1
                Memory *nextNode = memory->next;
                *memory = *nextNode; // 複製結構體內容
                free(nextNode);      // 釋放原本的頭節點
            }else{ //list len 1 -> 0
                memory->start = -1;
            }
            // memory = memory->next; //直接放掉原本head
        }else{
            last->next = now->next;
            free(now); //head以外的都是malloc出來的所以可以free掉
        }        
    }else if(sameStart){ //移動now->start, 維持end位置
        now->length -= length;
        now->start += length;
    }else if(sameEnd){ //減少length
        now->length -= length;
    }else{ //多產生一塊block（拆分），now->new->next
        //第二塊：new block
        Memory* new = genBlock(start+length, now->start+now->length - start-length, now->next);
        //第一塊：改變長度
        now->length = start - now->start;
        now->next = new;
    }
    return;
}

void freeMemory(Memory *memory, int start, int length){
    if(memory->start == -1){ //memory->start = -1 denote empty list
        Memory* new = genBlock(start, length, NULL);
        *memory = *new;
        free(new);
        return;
    }
    // printf("mem->start %d\n", memory->start);//////////////////////////////////////////////////////////////////////////////////////////

    //找到now, next使得now.start+len <= start < next.start
    Memory *now = NULL, *next = memory;
    // printf("next->start %d\n", next->start);/////////////////////////////////////////////////////////////////////////////////////////////////
    while(next != NULL && start > next->start){
        now = next;
        next = next->next;
    }

    // printf("next->start %d\n", next->start);/////////////////////////////////////////////////////////////////////////////////////////////////

    int contiStart = (now  != NULL) && (now->start+now->length == start);
    int contiEnd   = (next != NULL) && (start+length == next->start);
    if(contiStart && contiEnd){ //drop掉next
        now->length += length + next->length;
        now->next = next->next;
        // free(next);//////////////////////free到不是從malloc拿出來的記憶體會error
    }else if(contiStart){
        now->length += length;
    }else if(contiEnd){
        next->start -= length;
        next->length += length;
    }else{
        if(now == NULL){
            //把原本memory複製到newNext，memory換成start, end, ->newNext
            // printf("here\n");
            Memory* newNext = genBlock(memory->start, memory->length, memory->next);
            memory->next = newNext;
            memory->length = length;
            memory->start = start;
        }else{
            Memory* new = genBlock(start, length, next);
            now->next = new;
        }
    }
    return;
}

//////////////////////////////////////////////////////////////////////
#ifdef DEBUG

int main() {
        Memory myMemory;
        initMemory(&myMemory, 100);
        printMemory(&myMemory);
        allocateMemory(&myMemory, 10, 10);
        printMemory(&myMemory);
        allocateMemory(&myMemory, 0, 10);
        printMemory(&myMemory);
        allocateMemory(&myMemory, 20, 80);
        printMemory(&myMemory);
        freeMemory(&myMemory, 10, 10);
        printMemory(&myMemory);
        freeMemory(&myMemory, 0, 5);
        printMemory(&myMemory);
        // printMemory(&myMemory);
        // allocateMemory(&myMemory, 50, 10);
        // printMemory(&myMemory);
        // allocateMemory(&myMemory, 70, 10);
        // printMemory(&myMemory);
        // allocateMemory(&myMemory, 0, 10);
        // printMemory(&myMemory);
        // allocateMemory(&myMemory, 30, 10);
        // printMemory(&myMemory);
        // freeMemory(&myMemory, 50, 5);
        // printMemory(&myMemory);
        // freeMemory(&myMemory, 70, 10);
        // printMemory(&myMemory);
        // freeMemory(&myMemory, 30, 10);
        // printMemory(&myMemory);
        // freeMemory(&myMemory, 0, 10);
        // printMemory(&myMemory);
        return 0;
}

#endif