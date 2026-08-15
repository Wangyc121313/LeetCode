/*
165. 比较版本号

给你两个 版本号字符串 version1 和 version2 ，请你比较它们。版本号由被点 '.' 分开的修订号组成。修订号的值 是它 转换为整数 并忽略前导零。
比较版本号时，请按 从左到右的顺序 依次比较它们的修订号。如果其中一个版本字符串的修订号较少，则将缺失的修订号视为 0。
返回规则如下：
如果 version1 < version2 返回 -1，
如果 version1 > version2 返回 1，
除此之外返回 0。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compareVersion(string s1, string s2){
    int n1 = s1.length(), n2 = s2.length();
    int i = 0, j = 0;//标记遍历位置
    while(i < n1 || j < n2){
        int num1 = 0, num2 = 0;//记录两个.之间的数值
        while(i < n1 && s1[i] != '.'){
            num1 = num1 * 10 + (s1[i] - '0');//对于前面的0会自动忽略
            i++;
        }
        i++;//跳过.
        while(j < n2 && s2[j] != '.'){
            num2 = num2 * 10 + (s2[j] - '0');
            j++;
        }
        j++;
        if(num1 > num2) return 1;
        if(num1 < num2) return -1;  
    }
    return 0;
}

int main(){
    cout << compareVersion("1.2", "1.10") << "\n";
    cout << compareVersion("1.01", "1.001") << "\n";
    cout << compareVersion("2.0", "1.10") << "\n";
    cout << compareVersion("1.0", "1.0.0.0") << "\n";
    return 0;
}