#include <stdio.h>

int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    // 若x初始不为0,经过或运算，则最低位到最左侧1之间也全为1，否则全为0
    // x&&1的结果为0或1。若结果为0,0+0=1,若为1,全部1进位
    return (x >> 1) + (x && 1);
}

int main(void) {
    printf("%#x\n", leftmost_one(0xff00));
    return 0;
}
