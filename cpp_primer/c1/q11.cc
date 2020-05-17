#include <iostream>

using namespace std;

int main(void) {
    int start = 0;
    int end = 0;
    cout << "请输入两个整数: ";
    cin >> start >> end;
    if (start < end)
        while (++start != end) {
            cout << start << " ";
        }
    else
        while (--start != end) {
            cout << start << " ";
        }

    return 0;
}
