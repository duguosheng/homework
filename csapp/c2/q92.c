/**
 * @Author: GodSon
 * @Date: 2020-05-28 11:02:32
 * @LastEditTime: 2020-05-28 11:02:32
 * @Description: file content
 */

#include <assert.h>
#include <limits.h>
typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
    float_bits ret = f ^ INT_MIN;
    (((f >> 23 & 0xff) == 0xff && !(f << 9)) && (ret = f));
    return ret;
}

int main(int argc, char const *argv[]) {
    float f1 = 123.45678;
    float_bits f1_ret = float_negate(*(float_bits *)&f1);
    assert(f1 == -*(float *)&f1_ret);
    return 0;
}
