#include<stdio.h>

// #define HUNDRED
// #define APLUS

typedef struct{
    int hundredGrade;
    double rankGrade;
    char rank[4];
}Rank;

Rank* match(int grade){
    static Rank table[10] = {
        {95, 4.3, "A+"}, {87, 4.0, "A"}, {82, 3.7, "A-"}, {78, 3.3, "B+"}, {75, 3.0, "B"}, 
        {70, 2.7, "B-"}, {68, 2.3, "C+"}, {65, 2.0, "C"}, {60, 1.7, "C-"}, {50, 0, "F"}};
    if(grade >= 90) return &table[0];
    else if(grade >= 85) return &table[1];
    else if(grade >= 80) return &table[2];
    else if(grade >= 77) return &table[3];
    else if(grade >= 73) return &table[4];
    else if(grade >= 70) return &table[5];
    else if(grade >= 67) return &table[6];
    else if(grade >= 63) return &table[7];
    else if(grade >= 60) return &table[8];
    else return &table[9];
}

int main(void){
    int grade;
    int n = 0, avgHundred = 0;
    double avgRank = 0.0;
    while(scanf("%d", &grade) != EOF){
        n++;
        #ifdef HUNDRED
            avgHundred += grade;
            printf("%d ", grade);
        #endif
        #ifdef APLUS
            Rank* matched = match(grade);
            avgHundred += matched->hundredGrade;
            avgRank += matched->rankGrade;
            printf("%s ", matched->rank);
        #endif
    }
    #ifdef HUNDRED
        printf("%.1f\n", (double) avgHundred / n);
    #endif
    #ifdef APLUS
        printf("%.1f %.1f\n", avgRank/n, (double)avgHundred/n);
    #endif
}