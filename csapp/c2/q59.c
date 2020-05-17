#include <stdio.h>
int change_word(int x, int y) {
    //取x的低字节和y的其他字节
    return ((x & 0xff) | (y & ~0xff));
}

int main(void) {
    printf("%#x", change_word(0x89abcdef, 0x76543210));
}
