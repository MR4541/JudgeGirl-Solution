#ifndef _MEMORY_H
#define _MEMORY_H

typedef struct memory{
    int start;
    int length;
    struct memory* next;
}Memory;

void initMemory(Memory *memory, int length);
void printMemory(Memory *memory);
void allocateMemory(Memory *memory, int start, int length);
void freeMemory(Memory *memory, int start, int length);

#endif