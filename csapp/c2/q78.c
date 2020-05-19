#include <assert.h>
#include <limits.h>
//除法应当遵循正数向下舍入，负数向上舍入
//参考书上73页
int divide_power2(int x, int k) {
    int is_neg = x & INT_MIN;
    (is_neg && (x = x + (1 << k) - 1));
    return x >> k;
}

int main(void) {
    assert(divide_power2(10, 3) == 10 / 8);
    assert(divide_power2(-10, 3) == -10 / 8);
    return 0;
}
