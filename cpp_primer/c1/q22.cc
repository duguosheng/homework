#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(void) {
    Sales_item sum;
    if (cin >> sum)
        for (Sales_item item; cin >> item && item.isbn() == sum.isbn();
             sum += item)
            ;
    return 0;
}
