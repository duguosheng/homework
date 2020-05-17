#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(void) {
    Sales_item curitem;
    if (cin >> curitem) {
        Sales_item valitem;
        size_t cnt = 0;
        while (cin >> valitem) {
            if (valitem.isbn() == curitem.isbn())
                ++cnt;
            else {
                cout << curitem << "共计" << cnt << "本。" << endl;
                curitem = valitem;
                cnt = 1;
            }
        }
        cout << curitem << "共计" << cnt << "本。" << endl;
    }
    return 0;
}
