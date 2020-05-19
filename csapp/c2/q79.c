//#define NDEBUG
#include <assert.h>
#include <limits.h>
#include <stdio.h>

int mul3div4(int x) {
    int mul3 = x + (x << 1);
    int is_neg = mul3 & INT_MIN;
    (is_neg && (mul3 = mul3 + (1 << 2) - 1));
    return mul3 >> 2;
}
int main(void) {
    assert(mul3div4(100) == 3 * 100 / 4);
    assert(mul3div4(-100) == 3 * -100 / 4);
    int x = 0x87654321;
    assert(mul3div4(x) == 3 * x / 4);
    //不要使用assert(mul3div4(0x87654321) == 3 * 0x87654321 / 4);
    //因为0x87654321会自动升级成为unsigned，从而执行无符号乘除法
    return 0;
}
