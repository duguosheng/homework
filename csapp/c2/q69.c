#include <stdio.h>

unsigned rotate_left(unsigned x, int n) {
    size_t int_bits = sizeof(int) << 3;
    //注意n为0的情况
    return x << n | x >> (int_bits - n - 1) >> 1;
}

int main(void) {
    printf("%#x\n", rotate_left(0x12345678, 0));
    printf("%#x\n", rotate_left(0x12345678, 4));
    printf("%#x\n", rotate_left(0x12345678, 20));
    return 0;
}
