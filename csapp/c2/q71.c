// 1.因为这个函数不能进行符号扩展
// 2.代码如下
#include <assert.h>
#include <stdio.h>
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
    int bytedata = (word >> (bytenum << 3)) & 0xff;
    // 0-符号位(0或1)，结果为0或0xf...f,再将最后一个字节全部设为0
    int sign = (0 - (bytedata >> 7)) & ~0xff;
    return bytedata | sign;
}

int main(void) {
    assert(xbyte(0xaabbccdd, 1) == 0xffffffcc);
    assert(xbyte(0x00112233, 2) == 0x11);
}
