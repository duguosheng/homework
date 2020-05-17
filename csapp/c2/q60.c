#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    if (i < 0 || i > sizeof(unsigned) - 1) {
        printf("error\n");
        return x;
    }
    unsigned tmp = (unsigned)b << (i << 3);
    //先将对应的字节清零，然后再进行或运算
    return (x & ~(0xff << (i << 3)) | tmp);
}

int main(void) {
    printf("%#.8x\n", replace_byte(0x12345678u, 2, 0xab));
    printf("%#.8x\n", replace_byte(0x12345678u, 0, 0xab));
}
