/*
在潘多拉星球上，有一群怪兽组成一道阵线，奥特曼必须要按顺序与这些怪兽战斗。
奥特曼有一个初始能量值E，每个怪兽都有一个攻击力damage和击败奖励reward(击败后奥特曼可以恢复相应的能量值)。
当奥特曼面对第i个怪兽时，有以下选择：
1. 如果当前能量值大于怪兽攻击力damage[i]，奥特曼可以选择战斗，此时会先消耗掉damage[i]点能量，然后增加reward[i]点能量;
2. 如果当前能量值小于或等于怪兽攻击力damage[i]，奥特曼不能与该怪兽战斗(因为奥特曼剩余能量不能≤0)，此时只能跳过该怪兽;
3. 无论能否打过，都可以选择跳过该怪兽，此时奥特曼不消耗也不增加能量。

奥特曼的目标是尽可能多的击败怪兽(即最大化击败数量)，现在需要计算奥特曼最多能击败多少个怪兽。

注意：奥特曼与怪兽战斗的顺序不能改变。

约束条件：
- len(damage) = len(reward) <= 100
- 1 <= E <= 10^9
- 1 <= damage[i], reward[i] <= 10^9

输入描述：
- E:整数，奥特曼初始能量值
- damage:整数数组，每个怪兽的攻击力值。
- reward:整数数组，击败每个怪兽后获得能量值奖励。

输出描述：
整数，最多击败的怪兽数量。
*/
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