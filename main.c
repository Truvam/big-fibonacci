#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "bignum.h"


int fib_rec(int x);
int fib_dinamic(int x);
void calculate(int op, int n1, int n2);


int main() {
    int n1, n2, op;
    printf("1: Recursive Fibonacci\n");
    printf("2: Optimized Fibonacci\n");
    printf("3: Big Numbers\n");
    printf("Option: ");
    scanf("%d", &op);
    if(op == 1) {
        printf("Number: ");        
        scanf("%d", &n1);
        printf("Result: %d\n", fib_rec(n1));
    }
    else if(op == 2) {
        printf("Number: ");        
        scanf("%d", &n1);
        printf("Result: %d\n", fib_dinamic(n1));
    }
    else {
        printf("1: Addition\n");
        printf("2: Subtraction\n");
        printf("3: Multiplication\n");
        printf("4: Division\n");
        printf("5: Fibonacci\n");
        printf("Option: ");
        scanf("%d", &op);
        if(op == 5) {
            printf("Number: ");        
            scanf("%d", &n1);
            bignum fib = fibonacci(n1);
            printf("Result: ");
            printBigNum(fib);
        }
        else {
            printf("First Number: ");
            scanf("%d", &n1);
            printf("Second Number: ");
            scanf("%d", &n2);
            calculate(op, n1, n2);
        }
    }
    
}


void calculate(int op, int n1, int n2) {
    bignum b1 = intToBignum(n1);
    bignum b2 = intToBignum(n2);
    if(op == 1) {
        bignum add = addition(b1, b2);
        printf("Result: ");
        printBigNum(add);
    }
    else if(op == 2) {
        bignum sub = subtraction(b1, b2);
        printf("Result: ");
        //printList(sub);
        printBigNum(sub);
    }
    else if(op == 3) {
        bignum mult = multiplication(b1, b2);
        printf("Result: ");
        printBigNum(mult);
    }
    else {
        bignum div = division(b1, b2);
    }
}


int fib_rec(int x) {
    if(x < 2) 
        return x;
    else 
        return fib_rec(x - 1) + fib_rec(x - 2);
}


int fib_dinamic(int x) {
    int f[x + 1], i;
    f[0] = 0;
    f[1] = 1;
    for(i = 2; i < x + 1; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[x];
}

