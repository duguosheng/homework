#include <limits.h>
#include <stdio.h>

//方法1
int lower_one_mask(int n) {
    int int_bits = sizeof(int) << 3;
    //算数右移再取反
    int x = INT_MIN >> (int_bits - n - 1);
    return ~x;
}

//方法2
int lower_one_mask1(int n) {
    int int_bits = sizeof(int) << 3;
    //强转为unsigned,执行逻辑右移
    return (unsigned)-1 >> (int_bits - n);
}

int main(void) {
    printf("%#x\n", lower_one_mask(6));
    printf("%#x\n", lower_one_mask1(6));
    printf("%#x\n", lower_one_mask(17));
    printf("%#x\n", lower_one_mask1(17));
    return 0;
}
