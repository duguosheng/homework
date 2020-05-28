#include <assert.h>
#include <stdio.h>

unsigned f2u(float x) {
    return *(unsigned*)&x;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return
        //均为0
        (ux << 1 == 0 && uy << 1 == 0) ||
        // x<=0&&y>0 or x<0&&y>=0
        (sx && !sy) ||
        //符号位相同，先比较指数位，最后比较小数位
        (!sx && !sy && ux <= uy) || (sx && sy && ux >= uy);
}

int main(void) {
    assert(float_le(-0, +0));
    assert(float_le(+0, -0));
    assert(float_le(0, 3));
    assert(float_le(-4, -0));
    assert(float_le(-4, 4));
    return 0;
}
