#include <stdio.h>

enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK};
 
struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};

struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

#define POS(a) ((a) * ((a) > 0))

int isLeapYear(int year){
    return ((year%4==0 && year%100!=0) || year%400==0);
}

int datePassed(struct Date from, struct Date to){
    int dateBias[13] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}; //該月之前已過了幾天 
    //如果是潤月記得扣回來
    int dayOfYear_from = dateBias[from.month] + from.day - (!isLeapYear(from.year) && from.month >= 3);
    int dayOfYear_to = dateBias[to.month] + to.day - (!isLeapYear(to.year) && to.month >= 3);
    int daypassed = dayOfYear_to - dayOfYear_from + 1;
    for(int tmpyear = from.year; tmpyear < to.year; tmpyear++){
        daypassed += 365 + isLeapYear(tmpyear);
    }
    return daypassed;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    int allow[4] = {90, 10, 100, 5};
    int overdueDay = POS(datePassed(date_borrowed, date_returned) - allow[book.type]);
    //count importance
    while((book.importance & 1) == 0){ //讓第一個1對齊2^0
        book.importance >>= 1;
    }
    int impDist = 0;
    for(unsigned int test = 1<<1; (book.importance & test) == 0; test <<= 1){
        impDist ++;
    }
    //printf("dueday %d, impDist %d\n", overdueDay, impDist);
    return overdueDay * impDist;
}

//////////////////////////////////////////////////////////
// int main(){
//     struct Book book = {
//         "Neon Genesis Evangelion",
//         COMICS,
//         "978-159-116-400-5",
//         "Yoshiyuki Sadamoto",
//         17
//     };
//     struct Date date_borrowed, date_returned;
//     date_borrowed.year  = 2007;
//     date_borrowed.month = 11;
//     date_borrowed.day   = 14;
//     date_returned.year  = 2007;
//     date_returned.month = 12;
//     date_returned.day   = 3;
//     printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
//     return 0;
// }