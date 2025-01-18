#include<stdio.h>
#include<stdio.h>
#include"classroom_arrangement.h"
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    struct Classroom classrooms[n];
    struct Course courses[m];
    for(int i=0; i<n; i++){
        scanf("%s %d", classrooms[i].name, &classrooms[i].capacity);
    }
    for(int i=0; i<m; i++){
        scanf("%s %d:%d %d:%d %d %d", courses[i].id, &courses[i].start.hour, &courses[i].start.minute, &courses[i].end.hour, &courses[i].end.minute, &courses[i].number_of_students, &courses[i].day);
    }
    class_arrangement(n, m, classrooms, courses);
}