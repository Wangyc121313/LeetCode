#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minDistance(string s1, string s2){
    int m = s1.length(), n = s2.length();
    vector<vector<int>> ans(m + 1, vector<int>(n + 1));
    //f[i][j]表示s1[0,...,i-1]变化为s2[0,...,j-1]的最少操作数
    for(int j = 1; j <= n; j++) ans[0][j] = j;
    //边界条件，把空字符串s1变为s2[0,...,j-1]需要j步
    for(int i = 1; i <= m; i++){
        ans[i][0] = i;
    //边界条件，把s1[0,...,i-1]变成空字符串s2需要i步    
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1]) ans[i][j] = ans[i -1][j - 1];
            else ans[i][j] = min({ans[i - 1][j- 1], ans[i - 1][j], ans[i][j - 1]}) + 1;
        }
    }
    return ans[m][n];
}

int main(){
    string s1 = "horse", s2 = "ros";
    int ans = minDistance(s1, s2);
    cout << ans << "\n";
    return 0;
}