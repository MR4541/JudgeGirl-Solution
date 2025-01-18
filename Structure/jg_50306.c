#include<stdio.h>
#include<string.h>

#define MY_CC 13
#define AVERAGE_CC 13.823

struct Classroom{
    char name[20];
    int capacity;
};

struct Time{
  int hour;
  int minute;
};

struct Course{
    char id[10];
    struct Time start;
    struct Time end;
    int number_of_students;
    int day; // 1: Monday, 2: Tuesday, 3: Wednesday, 4: Thursday, 5: Friday
};

int isOverlap(struct Course* c1, struct Course* c2){
    if(c1->day != c2->day) return 0;
    int tmp1 = c1->end.hour*60 + c1->end.minute - c2->start.hour*60 - c2->start.minute;
    int tmp2 = c2->end.hour*60 + c2->end.minute - c1->start.hour*60 - c1->start.minute;
    return tmp1 * tmp2 >= 0;
}

void class_arrangement(int classnum, int coursenum, struct Classroom classrooms[], struct Course courses[]){
    int room_of_course[classnum][coursenum]; //每個room分配到哪幾堂課（存index）
    int room_course_cnt[500] = {0}; //每個room已經分配到幾門課
    int canputflag;
    for(int course_i = 0; course_i < coursenum; course_i++){
        for(int room_i = 0; room_i < classnum; room_i++){
            //capacity不夠
            if(courses[course_i].number_of_students > classrooms[room_i].capacity)
                continue;;
            canputflag = 1;
            //測試有沒有衝堂
            for(int i = 0; i < room_course_cnt[room_i]; i++){
                if(isOverlap(&courses[course_i], &courses[room_of_course[room_i][i]]))
                    canputflag = 0;
            }
            //put course
            if(canputflag == 1){
                room_of_course[room_i][room_course_cnt[room_i]] = course_i;
                room_course_cnt[room_i]++;
                break;
            }
        }
    }

    ///////////////////////////////////////////
    // for(int i = 0; i < classnum; i++){
    //     printf("%s :", classrooms[i].name);
    //     for(int j = 0; j < room_course_cnt[i]; j++){
    //         printf(" %s", courses[room_of_course[i][j]].id);
    //     }
    //     printf("\n");
    // }

    //sort courses at each room by start time
    struct Course* tmp1,* tmp2;
    int tmpi;
    for(int _ = 0; _ < classnum; _++){
        for(int i = room_course_cnt[_]-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                tmp1 = &courses[room_of_course[_][j]];
                tmp2 = &courses[room_of_course[_][j+1]];
                if(tmp1->day > tmp2->day || (tmp1->day == tmp2->day &&
                    tmp1->start.hour*60+tmp1->start.minute > tmp2->start.hour*60+tmp2->start.minute)){
                    tmpi = room_of_course[_][j];
                    room_of_course[_][j] = room_of_course[_][j+1];
                    room_of_course[_][j+1] = tmpi;
                }
            }
        }
    }

    for(int i = 0; i < classnum; i++){
        printf("%s :", classrooms[i].name);
        for(int j = 0; j < room_course_cnt[i]; j++){
            printf(" %s", courses[room_of_course[i][j]].id);
        }
        printf("\n");
    }
}

///////////////////////////////////////////////////////////////////////////////
// int main(){
//     int n, m;
//     scanf("%d %d", &n, &m);
 
//     struct Classroom classrooms[n];
//     for(int i = 0; i < n; i++){
//         scanf("%s %d", classrooms[i].name, &classrooms[i].capacity);
//     }
 
//     struct Course courses[m];
//     for(int i = 0; i < m; i++){
//         scanf("%s %d:%d %d:%d %d %d", courses[i].id, &courses[i].start.hour, &courses[i].start.minute, &courses[i].end.hour, &courses[i].end.minute, &courses[i].number_of_students, &courses[i].day);
//     }
 
//     class_arrangement(n, m, classrooms, courses);
 
//     return 0;
// }