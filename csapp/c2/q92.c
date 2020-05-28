/**
 * @Author: GodSon
 * @Date: 2020-05-28 11:02:32
 * @LastEditTime: 2020-05-28 11:02:32
 * @Description: file content
 */

#include <assert.h>
typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
    int a = 1;    // aaa
    int num = 1;  // nnn
    if ((f >> 23) == 0xff && !(f << 9))
        return f;


}
