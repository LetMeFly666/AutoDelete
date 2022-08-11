/*
 * @Author: LetMeFly
 * @Date: 2022-08-11 21:29:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-11 21:48:27
 */
#include "AutoDelete.h"

void f(string s = "55", int t = 9, char c = '0') {
    cout << s << " ";
    cout << t << " ";
    cout << c << " ";
    puts("");
}

int main() {
    f();
    f("))");
    f("--", 0);
    f("[", 6678, '=');
    AutoDelete autoDelete();
    return 0;
}