#include <stdio.h>

/**
 * 这道题没看懂问什么，抄了一下答案
 */
int fit_bits(int x, int n) {
    size_t int_bits = sizeof(int) << 3;
    size_t offset = int_bits - n;
    return (x << offset >> offset) == x;
}

int main(void) {
    return 0;
}
