#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(void) {
    for (Sales_item item; cin >> item; cout << item << endl)
        ;
    return 0;
}
