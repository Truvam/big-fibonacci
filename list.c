#include <stdlib.h>
#include <stdio.h>
#include "list.h"


list newList(int x, list r) {
    list l = malloc(sizeof(struct intlist));
    l->value = x;
    l->rest = r;
    return l;
}


int head(list l) {
    return l->value;
}


list tail(list l) {
    return l->rest;
}


void printList(list l) {
    printf("%d ", l->value);
    if (l->rest != NULL) {
        printList(l->rest);
    }
    else {
        printf("\n");
    }
}


int elem(int n, list l) {
    int x, i = 0;
    while(l != NULL) {
        if(i == n) {
            return l->value;
        }
        else {
            i++;
            l = l->rest;
        }
    }
    return -1;
}


int length(list l) {
    int i = 0;
    while(l != NULL) {
        i++;
        l = l->rest;
    }
    return i;
}


list reverse(list l) {
    list new_list = NULL;
    list next = NULL;
    while(l != NULL) {
        next = l->rest;
        l->rest = new_list;
        new_list = l;
        l = next;
    }
    return new_list;
}


void append(list l1, list l2) {
    while(l1->rest != NULL){
        l1 = l1->rest;
    }
    l1->rest = l2;
}


list append_new(list l1, list l2) {
    if(l1 == NULL) {
        return newList(head(l2), tail(l2));
    }
    list l3 = append_new(tail(l1), l2);
    list l4 = newList(head(l1), l3);
    return l4;
}


list add_pos(int x, list l, int pos) {
    if(pos > length(l)){
        printf("Length of the list is smaller than %d", pos);
        return l;
    } 
    if(pos == 0) return newList(x, l);
    else {
        return newList(head(l), add_pos(x, tail(l), --pos));
    }
}


list map(int (*f)(int), list l) {
    if(l == NULL) {
        return NULL;
    }
    else {
        int x = head(l);
        list r = tail(l);
        return newList(f(x), map(f, r));
    }        
}


list filter(bool (*f)(int), list l) {
    if(l == NULL) {
        return NULL;
    }
    else {
        int x = head(l);
        list r = tail(l);
        if (f(x) == true) {
            return newList(x, filter(f, r));
        }
        else {
            filter(f, r);
        }
    }  
}






