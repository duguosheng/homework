#include <limits.h>
#include <stdio.h>

unsigned srl(unsigned x, int k) {
    //将x强转为int，如果为负数则算数右移
    unsigned xsra = (int)x >> k;
    int int_bits = sizeof(int) << 3;
    // INT_MIN只有首位为1，通过算数右移k-1位获得前k位为1的数
    int mask = INT_MIN >> (k - 1);
    return xsra & ~mask;
}

int sra(int x, int k) {
    int xsrl = (unsigned)x >> k;
    int int_bits = sizeof(int) << 3;
    int mask = INT_MIN >> (k - 1);
    //如果符号位为0,则逻辑右移，如果为1则算数右移
    //(x&INT_MIN)取得符号位
    //!使符号位为1,则结果为0,若符号位为0,结果为1
    //在通过-1,若上一步结果为0,减1得所有位全为1，否则所有位全为0
    //最后&运算
    //所有过程的结果是，如果符号位为0,则不改变mask，否则将mask全部清零
    mask &= !(x & INT_MIN) - 1;
    printf("%#x\n", mask);
    return xsrl | mask;
}

int main(void) {
    printf("%#.8x\n", srl(0x80000000, 3));
    printf("%#.8x\n", sra(0x80000000, 3));
}
