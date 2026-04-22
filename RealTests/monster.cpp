#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void solve() {
    long long E;
    if (!(cin >> E)) return;

    string line;//数组长度未固定，需要使用getline读取整行输入，再用stringstream解析
    getline(cin, line); 
    // 防止 E 后面只有回车导致第一行读空，过滤掉空行
    if (line.empty() || line.find_first_not_of(" \t\r\n") == string::npos) {
        getline(cin, line);
    }
    
    // 用 stringstream 将整行文本转为数字数组
    vector<long long> damage;
    stringstream ss(line);
    long long val;
    while (ss >> val) {
        damage.push_back(val);
    }
    int n = damage.size();
    vector<long long> reward(n);
    for(int i = 0; i < n; i++){
        cin >> reward[i];
    }
    vector<long long> dp(n + 1, -1);//dp[i]表示恰好击败i个怪兽时保留的最大能量
    dp[0] = E;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j > 0; j--){
            if(dp[j - 1] != -1 && dp[j - 1] > damage[i]){
                long long new_energy = dp[j - 1] - damage[i] + reward[i];
                dp[j] = max(dp[j], new_energy);
            }
        }
    }
    int result = 0;
    for(int i = n; i >= 0; i--){
        if(dp[i] != -1){
            result = i;
            break;
        }
    }
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}