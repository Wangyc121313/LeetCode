/*
十进制整数（字符串形式）转换为七进制数。
*/
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int convert(string s) {
    // 1. 字符串 -> 十进制整数（Horner 法）
    int sum = 0;
    for (char c : s) sum = sum * 10 + (c - '0');

    // 2. 反复除 7 取余，余数低位在前
    string path = "";
    if (sum == 0) path.push_back('0');   // 单独处理 0
    while (sum != 0) {
        path.push_back('0' + (sum % 7)); // 转成数字字符 '0'~'6'
        sum /= 7;
    }
    reverse(path.begin(), path.end());
    int ans = 0;
    for (char c : path) ans = ans * 10 + (c - '0');
    return ans;
}

int main() {
    cout << convert("100") << endl;   // 202
    cout << convert("7")   << endl;   // 10
    cout << convert("0")   << endl;   // 0
    return 0;
}
