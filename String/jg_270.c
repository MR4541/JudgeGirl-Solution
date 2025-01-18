#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h> //for exit
//#define DEBUG

#define NVAR 1000
#define MAXLENGTH 80
#define NLINE 1000

enum Operator{ADD, SUB, MUL, DIV, MOD, EQL, NOTEQL, SMALLER, LARGER, SMALLEREQL, LARGEREOL};
enum StatementType{STOP, IF, GOTO, PRINT, ASSIGN};

/* find the index of table s.t. table[i] = "str" */
int find(char *string, char *table[]){
    int index = 0;
    while (table[index] != NULL){
        if(strcmp(string, table[index]) == 0){
            return index;
        }
        index++;
    }
    return -1; //not found
}

/* return the index of given operator*/
int findOprCode(char *name){
    char *operators[] = {"+", "-", "*", "/", "%", "==", "!=", 
    "<", ">", "<=", ">=", NULL};
    int code = find(name, operators);
    if(code == -1){
        printf("Error: find() returns -1, can't find operator.\n");
        exit(-1); //結束程式
    }
    return code;
}

/* find varindex of given varname*/
int findVariable(char *name, char *varNameTable[]){
    int index = find(name, varNameTable);
    if(index == -1){
        printf("Error: find() returns -1, can't find variable \"%s\".\n", name);
        exit(-1); //結束程式
    }
    return index;
}

/* process if */
void processIF(int lineNum, char* varNameTable[], int code[], int opd1[], int opd2[], int compopr[], int gotoLine[]){
    char gotoStr[MAXLENGTH]; //store goto exist in input;
    char opd[MAXLENGTH], opr[MAXLENGTH]; //變數名、運算符名

    code[lineNum] = IF;
    scanf("%s", opd);
    opd1[lineNum] = findVariable(opd, varNameTable);
    scanf("%s", opr);
    compopr[lineNum] = findOprCode(opr);
    scanf("%s", opd);
    opd2[lineNum] = findVariable(opd, varNameTable);
    scanf("%s", gotoStr);
    assert(strcmp(gotoStr, "GOTO") == 0);
    scanf("%d", &(gotoLine[lineNum]));
    gotoLine[lineNum]+=1;/////////////////範例扣行數是1base，題目是0base
}

/* process assign */
void processASSIGN(int lineNum, char* first, char* varNameTable[], int code[], int opd1[], int opd2[], int compopr[], int target[]){
    char opd[MAXLENGTH], opr[MAXLENGTH]; //儲存變數名、運算子
    code[lineNum] = ASSIGN;
    target[lineNum] = findVariable(first, varNameTable);
    char assignStr[MAXLENGTH]; //for assert == "="
    scanf("%s", assignStr);
    assert(strcmp(assignStr, "=") == 0);
    scanf("%s", opd);
    opd1[lineNum] = findVariable(opd, varNameTable);
    scanf("%s", opr);
    compopr[lineNum] = findOprCode(opr);
    scanf("%s", opd);
    opd2[lineNum] = findVariable(opd, varNameTable);
}

/* process code */
void processCode(char* varNameTable[], int code[], int opd1[], int compopr[], int opd2[], int gotoLine[], int target[]){
    char first[MAXLENGTH]; //store the first word of each line
    char opd[MAXLENGTH]; //for input
    int lineNum = 2; //indicate where we are now
    char* firstTable[] = {"STOP", "IF", "GOTO", "PRINT", NULL}; //跟strcmp組合可以回傳指令種類int
    int firstTableSize = sizeof(firstTable) / sizeof(char*); //5
    while (scanf("%s", first) != EOF){
        int firstType = find(first, firstTable); //找first對應的table[i]
        switch(firstType){
            case GOTO:
                code[lineNum] = GOTO;
                scanf("%d", &(gotoLine[lineNum]));
                gotoLine[lineNum]+=1;/////////////////範例扣行數是1base，題目是0base
                break;
            case STOP:
                code[lineNum] = STOP;
                break;
            case IF:
                code[lineNum] = IF;
                processIF(lineNum, varNameTable, code, opd1, opd2, compopr, gotoLine);
                break;
            case PRINT:
                code[lineNum] = PRINT;
                scanf("%s", opd);
                target[lineNum] = findVariable(opd, varNameTable); //紀錄這裡print要取誰的值
                break;
            default: //ASSIGN
                code[lineNum] = ASSIGN;
                processASSIGN(lineNum, first, varNameTable, code, opd1, opd2, compopr, target);
                break;
        }
        lineNum++;
    }
}

/* runCode: compare*/
int compare(int operand1, int operand2, int operator){
    switch (operator){
    case EQL:
        return (operand1 == operand2);
    case NOTEQL:
        return (operand1 != operand2);
    case SMALLER:
        return (operand1 <  operand2);
    case LARGER:
        //printf("IF > opd1 %d opd2 %d\n", operand1, operand2);///////////////////////////////////////
        return (operand1 >  operand2);
    case SMALLEREQL:
        return (operand1 <= operand2);
    case LARGEREOL:
        return (operand1 >= operand2);
    default:
        printf("Error in compare(): invalid operator %d\n", operator);
        exit(-1);
    }
}

/*runCode: arithmatic*/
int arithmatic(int operand1, int operand2, int operator){
    switch (operator){
    case ADD:
        //printf("ADD\n");//////////////////////////////////////////////
        return (operand1 + operand2);
    case SUB:
        return (operand1 - operand2);
    case MUL:
        return (operand1 * operand2);
    case DIV:
        return (operand1 / operand2);
    case MOD:
        return (operand1 % operand2);
    default:
        printf("Error in arithmatic(): invalid operator %d\n", operator);
        exit(-1);
    }
}

/* run code */
void runCode(char varName[][MAXLENGTH], int varValue[], int code[], int opd1[], int opd2[], int compopr[], int gotoLine[], int target[]){
    int line = 2; //line 1 is for input
    while (code[line] != STOP){
        switch (code[line]){
        case IF:
            if(compare(varValue[opd1[line]], varValue[opd2[line]], compopr[line]))
                line = gotoLine[line]; //if then goto
            else
                line++;
            break;
        case GOTO:
            line = gotoLine[line];
            break;
        case ASSIGN:
            //printf("%d + %d\n", varValue[opd1[line]], varValue[opd2[line]]);////////////////////////////////////////    
            varValue[target[line]] = arithmatic(varValue[opd1[line]], varValue[opd2[line]], compopr[line]);
            line++;
            break;
        case PRINT:
            printf("%d\n", varValue[target[line]]);
            line++;
            break;
        default:
            printf("Error in runCode(): invalid codetype %d\n", code[line]);
            exit(-1);
        }

        //printf("Sys Line now: %d\n", line);////////////////////////////////////////////////
    }
    
}

/* read variable */
void readVariable(char varName[][MAXLENGTH], int varValue[], char *varNameTable[]){
    int count = 0;
    char newName[MAXLENGTH];
    char assignStr[MAXLENGTH];///用來保證是"="
    scanf("%s", newName);
    while (strcmp(newName, "END") != 0){
        strcpy(varName[count], newName);
        scanf("%s", assignStr); //"="
        //printf("newName %s assignStr %s\n", newName, assignStr);////////////////////////////
        assert(strcmp(assignStr, "=") == 0);
        scanf("%d", &(varValue[count]));
        varNameTable[count] = varName[count]; //獲得指向i名字的指標
        count++;
        scanf("%s", newName);
    }
    varNameTable[count] = NULL;//標示結尾
}

int main(){
    char varName[NVAR][MAXLENGTH]; 
    int varValue[NVAR];
    char *varNameTable[NVAR]; //讓我們可以把varName和varValue連結
    readVariable(varName, varValue, varNameTable);
#ifdef DEBUG
    printf("\t/* Input Test */\n");
    for(int i = 0; varNameTable[i] != NULL; i++){
        printf("%s is %d\n", varNameTable[i], varValue[i]);
    }
#endif
    int code[NLINE]; //indicate type of the line
    int opd1[NLINE], compopr[NLINE], opd2[NLINE]; //for arithmatic and if
    //first = opd1 compor opd2;
    //IF opd1 compor opd2 GOTO gotoLine;
    int gotoLine[NLINE]; //for if
    int target[NLINE]; //indicate the var; for print and arithmatic assign
    processCode(varNameTable, code, opd1, compopr, opd2, gotoLine, target);
#ifdef DEBUG
    printf("\t/* Outputs */\n");
#endif
    runCode(varName, varValue, code, opd1, opd2, compopr, gotoLine, target);
    return 0;
}

/*
當前狀態
GOTO PRINT ASSIGN正常
IF爛的
*/