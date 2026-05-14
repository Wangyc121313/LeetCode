#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int left = 0;
    int n = s.length();
    unordered_map<char, int> mp;
    for(int right = 0; right < n; right++){
        mp[s[right]]++;
        if(mp[s[right]] > 1){
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main(){
    string s = "bbbbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}