#ifndef L
#define L
#include <stdlib.h>

typedef enum { false, true } bool;


typedef struct intlist {
    int value;
    struct intlist *rest;
} *list;


int head(list l);

list tail(list l);

list newList(int x, list r);

void printList(list l);

int elem(int n, list l);

int length(list l);
int length_zero(list l);

int listIsZero(list n);

int compare(list l1, list l2);

list reverse(list l);

list append(list l1, list l2);

list add_pos(int x, list l, int pos);

list map(int (*f)(int), list l);

list filter(bool (*f)(int), list l);


#endif
