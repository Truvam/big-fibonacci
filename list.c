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
    /*
     * Returns the length of the list without counting the zeros at the left.
     */
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


int listIsZero(list n) {
    /*
     * Used to verify if the list only has 0's.
     */
    int all_zero = 1;
    while (n != NULL) {
        if(head(n) != 0) {
            all_zero = 0;
        }
        n = tail(n);
    }
    return all_zero;
}


int compare(list l1, list l2) {
    /*
     * This function is used to compare two lists;
     * Returns:
     *   -1, if list l1 is smaller than l2;
     *    1, if list l1 is bigger than l2;
     *    0, if list l1 is equal to l2.
     */
    if(length_zero(l1) < length_zero(l2)) return -1;
    else if(length_zero(l1) > length_zero(l2)) return 1;
    else {
        int zero = 1;
        l1 = reverse(l1);
        l2 = reverse(l2);
        list l1_tmp = l1;
        list l2_tmp = l2;
        //printList(l1_tmp);
        //printList(l2_tmp);
        while(l1_tmp != NULL) {
            //printf("h1:%d   h2:%d\n", head(l1_tmp), head(l2_tmp));
            if(head(l1_tmp) == 0 && head(l2_tmp) == 0 && zero == 1) {
                l1_tmp = tail(l1_tmp);
                l2_tmp = tail(l2_tmp);
            }
            else if(head(l1_tmp) == 0 && tail(l2) == NULL && zero == 1) {
                l1_tmp = tail(l1_tmp);
            }
            else if(head(l1_tmp) == 0 &&  head(l2_tmp) != 0 && zero == 1 && tail(l2_tmp) != NULL) {
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


list append(list l1, list l2) {
    if(l1 == NULL) {
        return newList(head(l2), tail(l2));
    }
    list l3 = append(tail(l1), l2);
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
