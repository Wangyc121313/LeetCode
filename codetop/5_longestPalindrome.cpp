/*
5.最长回文子串

给你一个字符串 s，找到 s 中最长的 回文 子串。
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

string longestPalindrome(string s){
    //从中间出发，考虑aba和abba两种情况，n个字符，n-1个空隙
    int n = s.length();
    int start = 0, end = 0;
    for(int i = 0; i < 2 * n - 1; i++){
        int l = i / 2;
        int r = (i + 1) / 2;
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        // 有效区间应该是[l+1,r-1]，长度为r-1-l-1+1=r-l-1
        if(r - l - 1> end - start){
            end = r;
            start = l + 1;
        }
    }
    return s.substr(start, end - start);
}

int main(){
    string s = "babad";
    string ans = longestPalindrome(s);
    cout << ans << "\n";
    return 0;
}