#include "list.h"
#include "bignum.h"
#include <stdio.h>


bignum newBigNum(int x, bignum bn) {
    return newList(x, bn);
}


void printBigNum(bignum n) {
    n = reverse(n);
    int all_zero = 0;
    if(n->value == 0 && n->rest != NULL){
        n = n->rest;
        all_zero = 1;
    } 
    while (n != NULL) {
        if(n->value != 0) {
            printf("%d", n->value);
            all_zero = 0;
        }
        else if(n->value == 0 && all_zero == 0) {
            printf("%d", n->value);
        }
        n = n->rest;
    }
    if(all_zero == 1)
        printf("0");
    printf("\n");
}


bignum intToBignum(int x) {
    if(x == 0) {
        return NULL;
    }
    int tmp = x % 10;
    x /= 10;
    return newBigNum(tmp, intToBignum(x));
}

/*
bignum StringToBignum(char *x) {
    if(x == 0) {
        return NULL;
    }
    int tmp = x % 10;
    x /= 10;
    return newBigNum(tmp, intToBignum(x));
}*/


bignum addition(bignum n1, bignum n2) {
    bignum b = addition_aux(n1, n2, 0);
    return b;
}


bignum addition_aux(bignum n1, bignum n2, int carry) {
    int tmp, val;
    if(n1 == NULL && n2 == NULL) {
        if(carry != 0)
            return newBigNum(carry, NULL);
        else
            return NULL;
    }
    else {
        if(n1 != NULL && n2 == NULL) {
            if(carry != 0) {
                tmp = head(n1) + carry;
                carry = 0;
            }
            else 
                tmp = head(n1);
            return newBigNum(tmp, addition_aux(tail(n1), n2, carry));
        }   
        else if(n1 == NULL && n2 != NULL)
            return newBigNum(head(n2), addition_aux(n1, tail(n2), carry));
    }
    val = head(n1) + head(n2);
    if(carry != 0) {
        val += carry;
    }
    if(val > 9) {
        tmp = val % 10;
        carry = 1;
    }
    else {
        carry = 0;
        tmp = val;
    }
    return newBigNum(tmp, addition_aux(tail(n1), tail(n2), carry));
}


bignum subtraction(bignum n1, bignum n2) {
    bignum b = subtraction_aux(n1, n2, 0);
    return b;
}


bignum subtraction_aux(bignum n1, bignum n2, int carry) {
    int tmp, val, i;
    tmp = -1;
    if(n1 == NULL && n2 == NULL) {
        if(carry != 0)
            return newBigNum(carry, NULL);
        else
            return NULL;
    }
    else {
        if(n1 != NULL && n2 == NULL) {
            if(carry != 0) {
                if(head(n1) == 0) {
                    tmp = 9;
                    carry = 1;
                }
                else {
                    tmp = head(n1) - carry;
                    carry = 0;
                }
            }
            else 
                tmp = head(n1);
            return newBigNum(tmp, subtraction_aux(tail(n1), n2, carry));
        }
    }
    val = head(n1) - head(n2);
    if(carry != 0) {
        if(val > 0)
            val -= carry;
    }
    if(val < 0) {
        for(i = 0; tmp != head(n1); i++) {
            tmp = head(n2) + i;
            tmp = tmp % 10;
            
        }
        tmp = i-1;
        tmp -= carry;
        carry = 1;
    }
    else {
        if(val == 0 && carry != 0) {
            tmp = 9;
            carry = 1;
        }
        else {
            carry = 0;
            tmp = val;
        }
    }
    return newBigNum(tmp, subtraction_aux(tail(n1), tail(n2), carry));
}


bignum multiplication(bignum n1, bignum n2) {
    bignum b;
    if(length(n1) >= length(n2))
        b = multiplication_aux(n1, n2, 0);
    else
        b = multiplication_aux(n2, n1, 0);
    return b;
}


bignum multiplication_aux(bignum n1, bignum n2, int carry) {
    int value = 0, val, i, j = 1;
    bignum b = NULL;
    bignum b_tmp = newBigNum(0,NULL);
    bignum n_aux = n1;
    while(n2 != NULL) {
        while(n1 != NULL) {
            value = carry + head(n1) * head(n2);
            carry = value / 10;
            value = value % 10; 
            b = newBigNum(value, b);
            n1 = n1->rest;     
        }
        if(carry > 0)
            b = newBigNum(carry, b);
        b = reverse(b);
        b = addition(b, b_tmp);
        b_tmp = b;
        b = NULL;
        for(i = 0; i < j; i++)
            b = newBigNum(0, b);
        n2 = n2->rest;
        n1 = n_aux;
        carry = 0;
        j++;
    }
    return b_tmp;
}


bignum division(bignum n1, bignum n2) {
    printf("division");
}


bignum fibonacci(int x) {
    bignum f[x + 1];
    int i;
    f[0] = newBigNum(0, NULL);
    f[1] = newBigNum(1, NULL);
    for(i = 2; i < x + 1; i++) {
        f[i] = addition(f[i - 1], f[i - 2]);
    }
    return f[x];
}