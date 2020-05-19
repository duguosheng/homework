#include <assert.h>
#include <limits.h>
#include <stdio.h>

int threeforths(int x) {
    int is_neg = x & INT_MIN;
    int h = x & ~0x3;
    int l = x & 0x3;

    //加了偏置后右移还会舍去，因此不需要
    //(is_neg && (h = h + (1 << 2) - 1));
    int hd4 = h >> 2;
    int hd4m3 = hd4 + (hd4 << 1);

    int lm3 = l + (l << 1);
    (is_neg && (lm3 = lm3 + (1 << 2) - 1));
    int lm3d4 = lm3 >> 2;

    return hd4m3 + lm3d4;
}

int main() {
    assert(threeforths(8) == 6);
    assert(threeforths(9) == 6);
    assert(threeforths(10) == 7);
    assert(threeforths(11) == 8);
    assert(threeforths(12) == 9);
    assert(threeforths(-8) == -6);
    assert(threeforths(-9) == -6);
    assert(threeforths(-10) == -7);
    assert(threeforths(-11) == -8);
    assert(threeforths(-12) == -9);
    return 0;
}
