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

void pop_back(struct deque *q) {
    if (!q->size)
        printf("0\n");
    else {
        printf("1 %c\n", q->tail->vl);
        q->tail = q->tail->pre, q->size--;
        if (q->tail)
            q->tail->nxt = 0;
    }
}

void pop_front(struct deque *q) {
    if (!q->size)
        printf("0\n");
    else {
        printf("1 %c\n", q->head->vl);
        q->head = q->head->nxt, q->size--;
        if (q->head)
            q->head->pre = 0;
    }
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
    while (q->head && q->head->vl == c) {
        q->head = q->head->nxt, q->size--, cnt++;
        if (q->head)
            q->head->pre = 0;
    }
    while (q->tail && q->tail->vl == c) {
        q->tail = q->tail->pre, q->size--, cnt++;
        if (q->tail)
            q->tail->nxt = 0;
    }
    for (struct node *cr = q->head; cr; cr = cr->nxt) {
        if (cr->vl == c) {
            assert(cr != q->head);
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

signed main() {
    struct deque *dq = newdeque();
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
            pop_front(dq);
            break;
        case 4:
            pop_back(dq);
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
}