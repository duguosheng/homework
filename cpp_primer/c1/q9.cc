#include <iostream>

int main(void) {
    int num = 49;
    int sum = 0;
    while (++num != 101) {
        sum += num;
    }
    return 0;
}
