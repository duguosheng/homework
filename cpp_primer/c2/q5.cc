#include <iostream>
#include <string>

using namespace std;

int main(void) {
    char16_t s1 = u'a';  // unicode16字符
    char32_t s2 = U'a';  // unicode32字符
    wchar_t s3 = L'a';   // 宽字符
    char s4[] = u8"a";   // UTF-8，仅用于字符串字面常量
    return 0;
}
