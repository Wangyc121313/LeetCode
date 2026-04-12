#include <vector>
#include <string>
#include <iostream>
using namespace std;

string longestPalindrome(string s){
    //从中间出发
    int n = s.length();
    int start = 0, end = 0;
    for(int i = 0; i < 2 * n - 1; i++){
        int l = i / 2;
        int r = (i + 1) / 2;
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
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