#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for(int i = 0; i < strs.size(); i++){
        string s = strs[i];
        sort(s.begin(), s.end());
        mp[s].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for(const auto& it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for(const auto& group : ans){
        for(const auto& str : group){
            cout << str << " ";
        }
        cout << "\n";
    }
    return 0;
}