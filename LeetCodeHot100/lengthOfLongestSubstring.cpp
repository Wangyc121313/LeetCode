#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int n = s.length();
    int l = 0;
    unordered_map<char, int> mp;
    // 右指针不断向右移动，直到遇到重复的字符
    for(int r = 0; r < n; r++){
        mp[s[r]]++;
        if(mp[s[r]] > 1){// 如果遇到重复的字符，左指针不断向右移动，直到不再有重复的字符
            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }
        }
        ans = max(ans, r - l + 1);// 更新答案
    }
    return ans;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}