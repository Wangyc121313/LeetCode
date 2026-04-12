#include <vector>
#include <iostream>
using namespace std;

vector<int> findAnagrams(string s,string p){
    int n = p.length(), m = s.length();
    vector<int> ans;
    vector<char> array1(26, 0);
    for(char c : p) array1[c- 'a']++;
    vector<char> array2(26, 0);
    for(int l = 0; l < m - n + 1; l++){
        array2[s[l] - 'a']++;
        int r = l + n - 1;
        if(array1 == array2) ans.push_back(l);
        array2[s[l] - 'a']--;
    }
    return ans;
}

int main(){
    string s = "cbaebabacd", p = "abc";
    vector<int> ans = findAnagrams(s, p);
    for(int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}