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
void class_arrangement(int classnum,int coursenum,struct Classroom classrooms[],struct Course courses[]);