/**
 * @Author: GodSon
 * @Date: 2020-05-28 14:25:27
 * @LastEditTime: 2020-05-28 14:25:28
 * @Description: file content
 */

//#define NDEBUG
#include <assert.h>
#include <limits.h>
#include <stdio.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f) {
  float_bits sig = f >> 31;
  float_bits exp = f >> 23 & 0xff;
  float_bits frac = f & 0x7fffff;
  int is_nan_or_inf = (exp == 0xff);
  int tobeinf = (exp == 0xfe);

  (!is_nan_or_inf && tobeinf && ((exp = 0xff) && (frac = 0)));
  (!is_nan_or_inf && !tobeinf && (exp += 1));

  return (sig << 31) | (exp << 23) | (frac);
}

int main(int argc, char const *argv[]) {
  float f1 = -123123132.4567f;
  float_bits f1_ret = float_twice(*(float_bits *)&f1);
  assert(*(float *)&f1_ret == 2 * -123123132.4567f);

  float_bits f2 = 0xff7fffff;
  float_bits f2_ret = float_twice(f2);
  printf("%f\n", *(float *)&f2);
  printf("%f\n", 2 * *(float *)&f2);
  printf("%f\n", *(float *)&f2_ret);
  assert(*(float *)&f2_ret == 2 * *(float *)&f2);
  return 0;
}