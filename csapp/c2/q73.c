#include <assert.h>
#include <limits.h>

int saturating_add(int x, int y) {
    int sum = x + y;
    int sign_mask = INT_MIN;
    //正溢出：x>0 y>0 sum<0
    int pos_over = !(x & sign_mask) && !(y & sign_mask) && (sum & sign_mask);
    //负溢出：x<0 y<0 sum>0
    int neg_over = (x & sign_mask) && (y & sign_mask) && !(sum & sign_mask);
    //短路原则，并且&&优先级高于||
    ((pos_over && (sum = INT_MAX)) || neg_over && (sum = INT_MIN));
    return sum;
}

int main(void) {
    assert(saturating_add(1000, 10000) == 11000);
    assert(saturating_add(1000, -10000) == -9000);
    assert(saturating_add(INT_MAX, 1000) == INT_MAX);
    assert(saturating_add(INT_MIN, -1000) == INT_MIN);
    return 0;
}
