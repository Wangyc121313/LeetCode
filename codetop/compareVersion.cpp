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