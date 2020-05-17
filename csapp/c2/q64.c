#include <stdio.h>

int any_odd_one(unsigned x) {
    return !!(x & 0xaaaaaaaa);
}

int main(void) {
    printf("%d\n", any_odd_one(0x2));
}
