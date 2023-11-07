#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

int main() {
    signed char a, b, c, d, e, f, res_c, res_asm = 0;
    printf("a = "); 
    scanf_s("%hhd", &a);
    printf("b = "); 
    scanf_s("%hhd", &b);
    printf("c = "); 
    scanf_s("%hhd", &c);
    printf("d = "); 
    scanf_s("%hhd", &d);
    printf("e = "); 
    scanf_s("%hhd", &e);
    printf("f = "); 
    scanf_s("%hhd", &f);

    res_c = -(a + c - b) - (d - 1) + 4 - f + e;
    printf("Result C = %d\n", res_c);

    _asm {
        mov al, a;
        add al, c;
        sub al, b;
        neg al;
        mov bl, d;
        dec bl;
        sub al, bl;
        add al, 4;
        sub al, f;
        add al, e;
        mov res_asm, al;
    }

    printf("Result ASM = %d\n", res_asm);
    return 0;
}