#include <stdio.h>

int judge(int x) {
    return !(~x) || (!x) || !(x & ~0xff) ||
           !(x & ~(0xff << ((sizeof(int) - 1) << 3)));
}

int main(void) {
    printf("%d\n", judge(0x0));
    printf("%d\n", judge(0xffffffff));
    printf("%d\n", judge(0xff));
    printf("%d\n", judge(0xff000000));
    printf("%d\n", judge(0xffab));
    return 0;
}
