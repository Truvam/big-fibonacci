#ifndef B
#define B
#include "list.h"


typedef list bignum;


bignum newBigNum(int x, list r);

void printBigNum(bignum n);

bignum intToBigNum(int x);

bignum stringToBigNum(char *x);
bignum stringToBigNum_aux(char *x, int i);

bignum addition(bignum n1, bignum n2);
bignum addition_aux(bignum n1, bignum n2, int carry);

bignum subtraction(bignum n1, bignum n2);
bignum subtraction_aux(bignum n1, bignum n2, int carry);

bignum multiplication(bignum n1, bignum n2);
bignum multiplication_aux(bignum n1, bignum n2, int carry);

bignum division(bignum n1, bignum n2);

bignum fibonacci(int x);


#endif
