#include <stdio.h>

int odd_ones(unsigned x) {
    //将前16位与后16位异或，异或后后16位中1的奇偶对应了原x中的奇偶
    //之后就只需判断后16位，之后以此类推
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    x &= 0x1;
    return x;
}

int main(void) {
    printf("%d\n", odd_ones(0b101));
    printf("%d\n", odd_ones(0b1));
}
