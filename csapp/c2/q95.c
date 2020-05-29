/**
 * @Author: GodSon
 * @Date: 2020-05-28 15:20:47
 * @LastEditTime: 2020-05-28 15:20:47
 * @Description: file content
 */
#define NDEBUG
#include <assert.h>
#include <limits.h>
#include <stdio.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f) {
    float_bits sig = f >> 31;
    float_bits exp = f >> 23 & 0xff;
    float_bits frac = f & 0x7fffff;

    int is_nan_or_inf = (exp == 0xff);
    int very_small = (exp == 0);

    (!is_nan_or_inf && !very_small && (exp -= 1));
    (very_small && (frac >>= 1));

    return (sig << 31) | (exp << 23) | frac;
}

int main(int argc, char const *argv[]) {
    float f1 = 123.4567;
    float_bits f1_ret = float_half(*(float_bits *)&f1);
    assert(f1 / 2 == *(float *)&f1_ret);

    float_bits f2 = 0x000000ff;
    float_bits f2_ret = float_half(f2);
    float f2_div2 = *(float *)&f2 / 2;

    printf("f2:%#X f2/2:%#X f2_ret:%#X\n", f2, *(unsigned *)&f2_div2, f2_ret);
    printf("%#X\n", f2_ret);
    printf("f2:%f f2/2:%f f2_ret:%f\n", *(float *)&f2, *(float *)&f2 / 2,
           *(float *)&f2_ret);
    assert(*(float *)&f2 / 2 == *(float *)&f2_ret);
    return 0;
}
