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
    printf("%d ", head(l));
    if (tail(l) != NULL) {
        printList(tail(l));
    }
    else {
        printf("\n");
    }
}


int elem(int n, list l) {
    int x, i = 0;
    while(l != NULL) {
        if(i == n) {
            return head(l);
        }
        else {
            i++;
            l = tail(l);
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


int length_zero(list l) {
    int i = 0, j = 0;
    int is_zero = 0;
    while(l != NULL) {
        if(head(l) == 0) {
            is_zero = 1;
        }
        else if(head(l) != 0) {
            i += j;
            i++;
            j = 0;
            is_zero = 0;
        }
        if(is_zero == 1) {
            j++;
        }
        l = tail(l);
    }
    return i;
}


int compare(list l1, list l2) {
    if(length_zero(l1) < length_zero(l2)) return -1;
    else if(length_zero(l1) > length_zero(l2)) return 1;
    else {
        int zero = 1;
        l1 = reverse(l1);
        l2 = reverse(l2);
        list l1_tmp = l1;
        list l2_tmp = l2;
        while(l1_tmp != NULL) {
            if(head(l1_tmp) == 0 && head(l2_tmp) == 0) {
                l1_tmp = tail(l1_tmp);
                l2_tmp = tail(l2_tmp);
                zero = 1;
            }
            else if(head(l1_tmp) == 0 && tail(l2) == NULL && zero == 1) {
                l1_tmp = tail(l1_tmp);
            }
            else {
                if(head(l1_tmp) < head(l2_tmp)) {
                    l1 = reverse(l1);
                    l2 = reverse(l2);
                    return -1;
                }
                else if(head(l1_tmp) > head(l2_tmp)){
                    l1 = reverse(l1);
                    l2 = reverse(l2);
                    return 1;
                }
                l1_tmp = tail(l1_tmp);
                l2_tmp = tail(l2_tmp);
                zero = 0;
            }
        }
    }
    l1 = reverse(l1);
    l2 = reverse(l2);
    return 0;
}


list reverse(list l) {
    list new_list = NULL;
    list next = NULL;
    while(l != NULL) {
        next = tail(l);
        l->rest = new_list;
        new_list = l;
        l = next;
    }
    return new_list;
}


void append(list l1, list l2) {
    while(tail(l1) != NULL){
        l1 = tail(l1);
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
