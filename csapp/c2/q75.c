#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
int signed_high_prod(int x, int y) {
    int64_t mul = (int64_t)x * y;
    size_t w = sizeof(int) << 3;
    return (int)(mul >> w);
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    unsigned sig_x = x >> 31;
    unsigned sig_y = y >> 31;
    int signed_prod = signed_high_prod(x, y);
    return signed_prod + (x & (0 - sig_x)) + (y & (0 - sig_y));
}

unsigned unsigned_high_prod_for_test(unsigned x, unsigned y) {
    uint64_t mul = (uint64_t)x * y;
    size_t w = sizeof(unsigned) << 3;
    return (unsigned)(mul >> w);
}

int main(void) {
    assert(unsigned_high_prod(INT_MAX, INT_MAX) ==
           unsigned_high_prod_for_test(INT_MAX, INT_MAX));
    assert(unsigned_high_prod(INT_MAX / 4, INT_MAX) ==
           unsigned_high_prod_for_test(INT_MAX / 4, INT_MAX));
    assert(unsigned_high_prod(INT_MAX / 8, INT_MAX / 8) ==
           unsigned_high_prod_for_test(INT_MAX / 8, INT_MAX / 8));
}
