#include <assert.h>
#include <limits.h>

int tsub_ok(int x, int y) {
    int sign_mask = INT_MIN;
    int sub = x - y;
    //负数-正数才会溢出
    // x为正数或者y为负数都直接返回
    // 前两者都不满足时判断sub是否为正数
    return !(x & sign_mask) || (y & sign_mask) || (sub & sign_mask);
}

int main(void) {
    assert(tsub_ok(INT_MIN, 1) == 0);
    assert(tsub_ok(-1000, INT_MAX) == 0);
    assert(tsub_ok(1, INT_MIN) == 1);
}
