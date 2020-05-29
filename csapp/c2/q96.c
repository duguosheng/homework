/**
 * @Author: GodSon
 * @Date: 2020-05-29 10:44:37
 * @LastEditTime: 2020-05-29 10:44:37
 * @Description: file content
 */

//#define NDEBUG
#include <assert.h>
#include <limits.h>
#include <stdio.h>

typedef unsigned float_bits;

int float_f2i(float_bits f) {
    float_bits sig = f >> 31;
    float_bits exp = f >> 23 & 0xff;
    float_bits frac = f & 0x7fffff;
    int can_not_be_int = (exp == 0xff || exp == 0x0);
    int is_pos = !can_not_be_int && !sig;
    unsigned long ulongret = 0;
    int ret = 0;

    if (!can_not_be_int) {
        ulongret |= frac << 9;
        ulongret |= 0x100000000ul; //M=1+frac
        ulongret <<= exp - 127;
        ret |= ulongret >> 32;
    }

    if (!is_pos) {
        ret = -ret;
    }

    return ret;
}

int main(int argc, char const *argv[]) {
    float f1 = -123.8765;
    printf("%#x\n", -123);
    int f1_ret = float_f2i(*(float_bits *)&f1);
    assert(f1_ret == (int)f1);
    return 0;
}
