#include <stdio.h>
#include <cstdlib>

int main() {
    signed short int a, b, c, d, e, f, res_c, res_asm;
    printf("a = "); scanf_s("%d", &a);
    printf("b = "); scanf_s("%d", &b);
    printf("c = "); scanf_s("%d", &c);
    printf("d = "); scanf_s("%d", &d);
    printf("e = "); scanf_s("%d", &e);
    printf("f = "); scanf_s("%d", &f);
    res_c = -(a + c - b) - (d - 1) + 4 - f + e;
    printf("Result C = %d\n", res_c);
    _asm {
        mov ax, a; // ax = a
        add ax, c; // ax = a + c
        sub ax, b; // ax = a + c - b
        neg ax; // ax = -(a + c - b)
        mov bx, d; // bx = d
        dec bx; // bx = d - 1
        sub ax, bx; // ax = -(a + c - b) - (d - 1)
        add ax, 4; // ax = -(a + c - b) - (d - 1) + 4
        sub ax, f; // ax = -(a + c - b) - (d - 1) + 4 - f
        add ax, e; // ax = -(a + c - b) - (d - 1) + 4 - f + e
        mov res_asm, ax; // res_asm = ax
    }
    printf("Result ASM = %d\n", res_asm);
    return 0;
}