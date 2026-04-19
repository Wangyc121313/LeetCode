#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequence(string s1, string s2){
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    //dp[i][j]表示s1[0,...,i-1]与s2[0,...,j-1]的最长公共子序列
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main(){
    string s1 = "ace", s2 = "abscelljde";
    cout << longestCommonSubsequence(s1, s2) << "\n";
    return 0;
}