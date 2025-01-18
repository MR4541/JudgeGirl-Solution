#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long ull;

struct node {
    char vl;
    struct node *pre, *nxt;
};

struct deque {
    struct node *head, *tail;
    int size;
};

char pop_back(struct deque *q) {
    if (!q->size)
        return 0;
    char cr = q->tail->vl;
    q->tail = q->tail->pre, q->size--;
    if (q->size)
        q->tail->nxt = 0;
    else
        q->head = 0;
    return cr;
}

char pop_front(struct deque *q) {
    if (!q->size)
        return 0;
    char cr = q->head->vl;
    q->head = q->head->nxt, q->size--;
    if (q->size)
        q->head->pre = 0;
    else
        q->tail = 0;
    return cr;
}

struct node *newnode(char c) {
    struct node *cr = malloc(sizeof(struct node));
    cr->vl = c, cr->nxt = cr->pre = 0;
    return cr;
}

struct deque *newdeque() {
    struct deque *cr = malloc(sizeof(struct deque));
    cr->size = 0, cr->head = cr->tail = 0;
    return cr;
}

void push_back(struct deque *q, char c) {
    struct node *cr = newnode(c);
    if (!q->size) {
        q->head = q->tail = cr;
        q->size = 1;
        return;
    }
    q->tail->nxt = cr, cr->pre = q->tail;
    q->size++, q->tail = cr;
}

void push_front(struct deque *q, char c) {
    struct node *cr = newnode(c);
    if (!q->size) {
        q->head = q->tail = cr;
        q->size = 1;
        return;
    }
    q->head->pre = cr, cr->nxt = q->head;
    q->size++, q->head = cr;
}

void delete(struct deque *q, char c) {
    int cnt = 0;
    while (q->size && q->head->vl == c)
        pop_front(q), cnt++;
    while (q->size && q->tail->vl == c)
        pop_back(q), cnt++;
    for (struct node *cr = q->head; cr; cr = cr->nxt) {
        if (cr->vl == c) {
            cnt++, q->size--;
            cr->pre->nxt = cr->nxt;
            cr->nxt->pre = cr->pre;
        }
    }
    if (cnt)
        printf("%d %c\n", cnt, c);
    else
        printf("0\n");
}

int getone() {
    static FILE *fin;
    static int init = 0;
    static int po = 0;
    static ull cr;
    if (!init)
        init = 1, fin = fopen("file.in", "r");
    if (!po)
        fscanf(fin, "%llu", &cr), po = 64;
    po -= 2;
    if (((cr >> po) & 3) == 3)
        fclose(fin);
    return (cr >> po) & 3;
}

int getvl(int *len, int *vl) {
    int cr = getone();
    *len = 0, *vl = 0;
    while (~cr & 2) {
        (*len)++;
        (*vl) <<= 1;
        (*vl) |= cr;
        cr = getone();
    }
    return cr;
}

signed main() {
    FILE *fout = fopen("file.out", "w");
    struct deque *dq = newdeque();
    char grid[5][1 << 5];
    int x, y, last;
    for (int i = 0; i < 26; i++)
        getvl(&x, &y), grid[x][y] = 'a' + i;
    do {
        last = getvl(&x, &y);
        push_back(dq, grid[x][y]);
    } while (last != 3);
    int q, op;
    char cc[10];
    scanf("%d", &q);
    while (q-- && scanf("%d", &op)) {
        switch (op) {
        case 1:
            scanf("%s", cc);
            push_front(dq, cc[0]);
            break;
        case 2:
            scanf("%s", cc);
            push_back(dq, cc[0]);
            break;
        case 3:
            cc[1] = pop_front(dq);
            if (cc[1])
                printf("1 %c\n", cc[1]);
            else
                printf("0\n");
            break;
        case 4:
            cc[1] = pop_back(dq);
            if (cc[1])
                printf("1 %c\n", cc[1]);
            else
                printf("0\n");
            break;
        case 5:
            scanf("%s", cc);
            delete (dq, cc[0]);
            break;
        default:
            printf("%d\n", dq->size);
            break;
        }
    }
    fprintf(fout, "%d\n", dq->size);
    for (struct node *cr = dq->head; cr; cr = cr->nxt)
        fprintf(fout, "%c\n", cr->vl);
    fclose(fout);
}