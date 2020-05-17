#include <limits.h>
#include <stdio.h>

int int_shifts_are_arithmetic() {
    // INT只有最高位为1
    int num = INT_MIN;
    //将num首位右移至最后一位，若算数右移则结果的所有位都为1
    return !~(num >> ((sizeof(int) << 3) - 1));
}

int main(void) {
    printf("%d\n", int_shifts_are_arithmetic());
}
