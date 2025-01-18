#include<stdio.h>
#include<string.h>

typedef struct person {
    unsigned int id;
    char name[32];
}Person;

typedef struct friends {
    unsigned id1;
    unsigned id2;
}Friends;

int findName(char* name, Person* peopleTable, int P){
    for(int idx = 0; idx < P; idx++){
        if(strcmp(peopleTable[idx].name, name) == 0)
            return peopleTable[idx].id;
    }
    // printf("findName(): Not Found!\n");
    return -1;
}

int main(){
    int P, F;
    Person people[10000];
    Friends friendship[10000];
    FILE* fp = fopen("friends", "rb");
    fread(&P, sizeof(int), 1, fp);
    fread(people, sizeof(Person), P, fp);
    fread(&F, sizeof(int), 1, fp);
    fread(friendship, sizeof(Friends), F, fp);
    // for(int i = 0 ; i < P; i++) printf("id %04d Name %s\n", people[i].id, people[i].name);
    // for(int i = 0 ; i < F; i++) printf("friend: %04d %04d\n", friendship[i].id1 , friendship[i].id2);
    while(1){
        char name1[32], name2[32];
        scanf("%s%s", name1, name2);
        if(strcmp(name1, "end") == 0)break;
        int id1 = findName(name1, people, P), id2 = findName(name2, people, P);
        // printf("id: %d %d\n", id1, id2);
        if(id1 == -1 || id2 == -1){
            printf("no\n");
            continue;
        }
        int yesflag = 0;
        for(int j = 0; j < F; j++){
            if((friendship[j].id1 == (unsigned)id1 && friendship[j].id2 == (unsigned)id2) ||
               (friendship[j].id1 == (unsigned)id2 && friendship[j].id2 == (unsigned)id1)){
                printf("yes\n");
                yesflag = 1;
                break;
            }
        } 
        if(!yesflag)
            printf("no\n");
    }
    fclose(fp);
}