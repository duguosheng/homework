#include <limits.h>
#include <stdio.h>
typedef struct {
  unsigned s : 1;
  unsigned e : 8;
  unsigned f : 23;
} float_description;

float_description get_float_desc(unsigned u) {
  float_description fd;
  fd.s = (u >> 31) & 0x1;
  fd.e = (u >> 23) & 0xff;
  fd.f = u & 0x7fffff;
  return fd;
}

void print_float_desc(float_description fd) {
  printf("s: %d---%#x\n", fd.s, fd.s);
  printf("e: %d---%#x\n", fd.e, fd.e);
  printf("e: %d---%#x\n", fd.f, fd.f);
}

int main(void) {
  float_description fd = get_float_desc(0x40490fdb);
  print_float_desc(fd);
}
