/*
415.字符串相加

给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string addStrings(string s1, string s2){
    string ans = "";
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0){
        int n1 = (i >= 0) ? (s1[i] - '0') : 0;
        int n2 = (j >= 0) ? (s2[j] - '0') : 0;
        int temp = n1 + n2 + carry;
        carry = temp / 10;
        ans += to_string(temp % 10);
        i--;
        j--;
    }
    if(carry == 1) ans += "1";
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s1 = "11", s2 = "123";
    string ans = addStrings(s1, s2);
    cout << ans << "\n";
    return 0;
}