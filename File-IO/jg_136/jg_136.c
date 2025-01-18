#include<stdio.h>

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main(){
    char inputName[100], outputName[100];
    scanf("%s%s", inputName, outputName);
    FILE* fin = fopen(inputName, "rb");
    FILE* fout = fopen(outputName, "w");
    Student tmp;

    fprintf(fout, "<table border=\"1\">\n<tbody>\n");
    // printf("<table border=\"1\">\n<tbody>\n");
    while(fread(&tmp, sizeof(Student), 1, fin) != 0){
        // printf("name %s\n", tmp.name);
        fprintf(fout, "<tr>\n"
                "<td>%s</td>\n"
                "<td>%d</td>\n"
                "<td>%s</td>\n"
                "<td>%f, %f, %f, %f</td>\n"
                "<td>%d, %d, %d</td>\n"
                "</tr>\n", tmp.name, tmp.id, tmp.phone, tmp.grade[0], tmp.grade[1],
                tmp.grade[2], tmp.grade[3], tmp.birth_year, tmp.birth_month, tmp.birth_day);
        // printf( "<tr>\n"
        //         "<td>%s</td>\n"
        //         "<td>%d</td>\n"
        //         "<td>%s</td>\n"
        //         "<td>%f, %f, %f, %f</td>\n"
        //         "<td>%d, %d, %d</td>\n"
        //         "</tr>\n", tmp.name, tmp.id, tmp.phone, tmp.grade[0], tmp.grade[1],
        //         tmp.grade[2], tmp.grade[3], tmp.birth_year, tmp.birth_month, tmp.birth_day);
    }
    fprintf(fout, "</tbody>\n</table>\n");
    // printf("</tbody>\n</table>\n");
    fclose(fin); fclose(fout);
}

/*
<table border="1">
<tbody>
<tr>
<td>%s</td>
<td>%d</td>
<td>%s</td>
<td>%f, %f, %f, %f</td>
<td>%d, %d, %d</td>
</tr>
</tbody>
</table>
*/