#include <stdio.h>
#include <cstdlib>

int main() {
    signed long a, b, c, d, e, f, res_c, res_asm;
    printf("a = "); scanf_s("%d", &a);
    printf("b = "); scanf_s("%d", &b);
    printf("c = "); scanf_s("%d", &c);
    printf("d = "); scanf_s("%d", &d);
    printf("e = "); scanf_s("%d", &e);
    printf("f = "); scanf_s("%d", &f);
    res_c = -(a + c - b) - (d - 1) + 4 - f + e;
    printf("Result C = %d\n", res_c);
    _asm {
        mov eax, a; // eax = a
        add eax, c; // eax = a + c
        sub eax, b; // eax = a + c - b
        neg eax; // eax = -(a + c - b)
        mov ebx, d; // ebx = d
        dec ebx; // ebx = d - 1
        sub eax, ebx; // eax = -(a + c - b) - (d - 1)
        add eax, 4; // eax = -(a + c - b) - (d - 1) + 4
        sub eax, f; // eax = -(a + c - b) - (d - 1) + 4 - f
        add eax, e; // eax = -(a + c - b) - (d - 1) + 4 - f + e
        mov res_asm, eax; // res_asm = eax
    }
    printf("Result ASM = %d\n", res_asm);
    return 0;
}