#include "stdio.h"

typedef unsigned char* byte_ptr;

int is_little_endian() {
    int num = 0xff;
    byte_ptr start = (byte_ptr)&num;
    if (start[0] == 0xff) return 1;
    return 0;
}

int main(void) {
    printf("%d\n", is_little_endian());
}
