/**
 * @Author: GodSon
 * @Date: 2020-05-29 10:44:37
 * @LastEditTime: 2020-05-29 10:44:37
 * @Description: file content
 */

#include <assert.h>
#include <limits.h>

typedef unsigned float_bits;

int float_f2i(float_bits f) {
  float_bits sig = f >> 31;
  float_bits exp = f >> 23 & 0xff;
  float_bits frac = f & 0x7fffff;
  int can_not_be_int = (exp == 0xff || exp == 0x0);
  unsigned long ulongret = 0;
  (sig && ulongret | ~0x0ul);
  (can_not_be_int &&)
}

int main(int argc, char const *argv[]) {
  float f1 = 123.4567;
  int f1_ret = float_f2i(*(float_bits *)&f1);
  assert(f1_ret == (int)f1);
  return 0;
}
