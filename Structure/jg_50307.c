#include <stdio.h>
#include <math.h>
 
#define MY_CC 8
#define AVERAGE_CC 18.266

struct Class {
    int credit, type, score;
    // type = 0 : compulsory, 1 : elective, 2 : others
};
 
struct Student {
    char id[4];
    int k;
    struct Class classes[10];
 
    // calculate values below by yourself
    double gpa_avg, comp_avg, elec_avg;
    int major, total;
};
 
int feq(double a, double b){
    return fabs(a - b) < 1e-9;
}
 
int fless(double a, double b){
    return a - b < -1e-9;
}
 
double GPA(int score){
    return 1.7*(score >= 60) + 0.3*(score >= 63) + 0.3*(score >= 67) + 0.4*(score >= 70) 
    + 0.3*(score >= 73) + 0.3*(score >= 77) + 0.4*(score >= 80) + 0.3*(score >= 85) + 0.3*(score >= 90);
}
 
int compareStruc(struct Student* s1, struct Student* s2){
    int cmp1 = 2*fless(s1->gpa_avg, s2->gpa_avg) + feq(s1->gpa_avg, s2->gpa_avg);
    int cmp2 = 2*fless(s1->comp_avg, s2->comp_avg) + feq(s1->comp_avg, s2->comp_avg);
    int cmp3 = 2*fless(s1->elec_avg, s2->elec_avg) + feq(s1->elec_avg, s2->elec_avg);
    int cmp4 = 2*(s1->major < s2->major) + (s1->major == s2->major);
    int cmp5 = 2*(s1->total < s2->total) + (s1->total == s2->total);
    return ((cmp1>=2 || (cmp1&&(cmp2>=2))) || (((cmp1&&cmp2)&&cmp3>=2) || ((cmp1&&cmp2)&&(cmp3&&cmp4>=2))))
    || ((cmp1&&cmp2)&&(cmp3&&(cmp4&&cmp5>=2)));
}
 
void scholarship(int n, struct Student students[]){
    int comp, elec, exter; //credits of types
    for(int i = 0; i < n; i++){
        students[i].gpa_avg = students[i].comp_avg = students[i].elec_avg = 0;
        comp = elec = exter = 0;
        for(int j = 0; j < students[i].k; j++){
            students[i].gpa_avg += GPA(students[i].classes[j].score) * students[i].classes[j].credit;
            if(students[i].classes[j].type == 0){
                comp += students[i].classes[j].credit;
                students[i].comp_avg += students[i].classes[j].score * students[i].classes[j].credit;
            }else if(students[i].classes[j].type == 1){
                elec += students[i].classes[j].credit;
                students[i].elec_avg += students[i].classes[j].score * students[i].classes[j].credit;
            }else{
                exter += students[i].classes[j].credit;
            }
        }
        students[i].major = comp + elec;
        students[i].total = comp + elec + exter;
        students[i].gpa_avg /= students[i].total;
        students[i].comp_avg /= comp;
        students[i].elec_avg /= elec;
    }
    ////////////////////////////////
    // for(int i = 0; i < n; i++){
    //     printf("ID %s classNum %d\ngpa %f comp %f elec %f\nmajor %d total %d\n",
    //     students[i].id, students[i].k, students[i].gpa_avg, students[i].comp_avg,
    //     students[i].elec_avg, students[i].major, students[i].total);
    // }
    //bubble sort
    struct Student tmp;
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(compareStruc(&students[j], &students[j+1])){
                tmp = students[j];
                students[j] = students[j+1];
                students[j+1] = tmp;
            }
        }
    }
    ////////////////////////////////
    // for(int i = 0; i < n; i++){
    //     printf("ID %s classNum %d\ngpa %f comp %f elec %f\nmajor %d total %d\n",
    //     students[i].id, students[i].k, students[i].gpa_avg, students[i].comp_avg,
    //     students[i].elec_avg, students[i].major, students[i].total);
    // }
    int printed = n/20 + (n%20 != 0);
    printf("%d\n", printed);
    for(int i = 0; i < printed; i++){
        printf("%s\n", students[i].id);
    }
}
 
////////////////////////////////////////////// 
// int main() {
//     int n;
//     scanf("%d", &n);
 
//     struct Student students[505];
//     for (int i = 0; i < n; i++) {
//         scanf("%s", students[i].id);
//         scanf("%d", &students[i].k);
 
//         for (int j = 0; j < students[i].k; j++) {
//             scanf("%d %d %d", &students[i].classes[j].credit, &students[i].classes[j].type, &students[i].classes[j].score);
//         }
//     }
 
//     scholarship(n, students);
// }