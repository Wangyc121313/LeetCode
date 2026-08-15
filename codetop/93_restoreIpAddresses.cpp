/*
93. 复原 IP 地址

有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址。
返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
你不能重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> ans;
string s;
int path[4];//每段的下标+1

void restoreIpAddresses(int i, int j, int ipVal){
    if(i == n){
        if(j == 4){
            int a = path[0], b = path[1], c = path[2];
            ans.push_back(s.substr(0, a) + '.' + s.substr(a, b - a) + '.' + s.substr(b, c - b) + '.' + s.substr(c));
        }
        return;
    }
    if(j == 4) return;
    ipVal = ipVal * 10 + (s[i] - '0');
    if(ipVal > 255) return;
    if(ipVal > 0) restoreIpAddresses(i + 1, j, ipVal);//不分割
    path[j] = i + 1;
    restoreIpAddresses(i + 1, j + 1, 0);
}

int main(){
    s = "25525511135";
    n = s.length();
    if(n >= 4 && n <= 12) restoreIpAddresses(0, 0, 0);
    for(const string& ip : ans) cout << ip << "\n";
    return 0;
}