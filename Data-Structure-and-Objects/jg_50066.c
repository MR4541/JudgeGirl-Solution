#include <stdio.h>
#include <stdlib.h>

typedef struct RoomStatus {
    int capacity;
    struct Reservation *reservation;
} RoomStatus;
 
typedef struct Reservation {
    int nP;
    int StartTime;
    int EndTime;
    struct Reservation *next;
} Reservation;

//start == end不算 overlap
//用乘的判斷會overlap
int isOverlap(Reservation* a, int StartTime, int EndTime){
    return !(a->StartTime >= EndTime || StartTime >= a->EndTime);
}

Reservation* genNode(int nP, int StartTime, int EndTime, Reservation* next){
    Reservation* new = (Reservation*)malloc(sizeof(Reservation));
    new->nP = nP;
    new->StartTime = StartTime;
    new->EndTime = EndTime;
    new->next = next;
    return new;
}

int ReserveRoom(RoomStatus list[], int nR, int nP, int StartTime, int EndTime){
    for(int roomi = 0; roomi < nR; roomi++){
        if(nP > list[roomi].capacity) continue;
        int canInsert = 1;
        Reservation *scanner = list[roomi].reservation;
        for(; scanner != NULL; scanner = scanner->next){
            if(isOverlap(scanner, StartTime, EndTime)){
                canInsert = 0;
                break;
            }
        }
        if(canInsert){ //new = head: len = 0 or new < prev_head 
            if(list[roomi].reservation == NULL || StartTime < list[roomi].reservation->StartTime){
                Reservation* new = genNode(nP, StartTime, EndTime, list[roomi].reservation);
                list[roomi].reservation = new;
            }else{ //sink in order of time
                Reservation* last = list[roomi].reservation;
                while(last->next != NULL && last->next->StartTime < StartTime){
                    last = last->next;
                }
                Reservation* new = genNode(nP, StartTime, EndTime, last->next);
                last->next = new;
            }

            
            return 1;
        }
    }
    return 0;
}


// //////////////////////////////////////////////////////////////////////////////////////////
// int main(){
//     int n = 3;
//     RoomStatus list[n];
//     for(int i=0; i < n; i++){
//         list[i].capacity = i+2;
//         list[i].reservation = NULL;
//     }
//     int nP, sTime, eTime;
//     while(scanf("%d %d %d", &nP, &sTime, &eTime)!=EOF)
//         printf("%d", ReserveRoom(list, n, nP, sTime, eTime));
//     puts("");
//     printf("---Room Status List---\n");
//     for(int i=0; i<n; i++){
//         printf("%d ---", list[i].capacity);
//         for(Reservation *tmp = list[i].reservation; tmp!=NULL; tmp=tmp->next)
//             printf("->(%d:%d, %d)", tmp->nP, tmp->StartTime, tmp->EndTime);
//         puts("");
//     }
//     printf("---      End       ---\n");
//     return 0;
// }