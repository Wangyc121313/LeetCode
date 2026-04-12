#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

int lengthofLongestSubString(string s){
    int ans = 0;
    int n = s.length();
    unordered_map<char, int> mp;
    int l = 0;
    for(int r = 0; r < n; r++){
        mp[s[r]]++;
        if(mp[s[r]] > 1){
            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int main(){
    string s = "abcabcbb";
    int ans = lengthofLongestSubString(s);
    cout << ans << "\n";
    return 0;
}