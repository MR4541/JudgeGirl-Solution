#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string_count {
        char seen[80];
        int count;
}String_count;

int compare_and_add(char *string, String_count strings[]) {
    int idx = 0;
    while(strings[idx].count != 0){ //重複的
        if(strcmp(string,  strings[idx].seen) == 0){
            strings[idx].count++;
            return 1;
        }
        idx++;
    }
    //new str
    strcpy(strings[idx].seen, string);
    strings[idx].count = 1;
    return 0;
}

int compare(const void *a, const void *b){
    String_count *sa = (String_count*)a; 
    String_count *sb = (String_count*)b;
    if(sa->count > sb->count) return 1;
    if(sa->count < sb->count) return -1;
    return strcmp(sa->seen, sb->seen); 
}

int strArrLen(String_count strings[]){
    int n = 0;
    while(strings[n].count != 0) n++;
    return n;
}

void sort(String_count strings[]) {
    int n = strArrLen(strings);
    qsort(strings, n, sizeof(String_count), compare);
}
void print(String_count strings[]) {
    int n = strArrLen(strings);
    for(int i = 0; i < n; i++){
        printf("%d %s\n", strings[i].count ,strings[i].seen);
    }
}

//////////////////////////////////////////////////////////////////
// int main() {
//         struct string_count strings[20];
//         int i;
//         for( i=0 ; i<20 ; i++ )
//                 strings[i].count = 0;
//         compare_and_add( "This", strings );
//         compare_and_add( "is", strings );
//         compare_and_add( "an", strings );
//         compare_and_add( "apple,", strings );
//         compare_and_add( "and", strings );
//         compare_and_add( "this", strings );
//         compare_and_add( "is", strings );
//         compare_and_add( "a", strings );
//         compare_and_add( "book.", strings );
//         sort( strings );
//         print( strings );
//         return 0;
// }