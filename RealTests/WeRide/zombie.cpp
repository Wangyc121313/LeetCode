/*
用炸弹炸僵尸，手头初始有m个炸弹，僵尸的初始位置为dist，速度为speed，分钟0开始前进，每分钟获得一个炸弹，当僵尸位置已经等于0或小于0时刻使用炸弹视为失败，返回能炸死的僵尸数量。

输入：第一行为dist，第二行为speed，第三行为m。

示例：
输入：
1，3，4
1，1，1
1
输出：
3 

思路：计算各僵尸到达时间t_i，并从小到大升序
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// 辅助函数，处理特殊的输入情况：未知长度且带英文逗号
vector<int> parseLine(string s){
    replace(s.begin(), s.end(), ',', ' ');
    stringstream ss(s);
    vector<int> res;
    int val;
    while(ss >> val) res.push_back(val);
    return res;
}

int solution(vector<int>& dist, vector<int>& speed, int m){
    int n = dist.size();
    vector<int> arrive(n);
    // 计算每个僵尸的到达时间，向上取整，arrive[i]对应处理第i+1只僵尸
    for(int i = 0;i < n; i++) arrive[i] = (dist[i] + speed[i] - 1) / speed[i];
    sort(arrive.begin(), arrive.end());
    int killed = 0;
    for(int i = 0; i < n; i++){
        // 初始m枚，消灭前i+1只僵尸的最少时间为:
        int t_fire = max(i + 1 - m, 0);
        if(t_fire >= arrive[i]) break;
        killed++;
    }
    return killed;
}

int main(){
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    vector<int> dist = parseLine(s1);
    vector<int> speed = parseLine(s2);
    int m = stoi(s3);
    cout << solution(dist, speed, m) << "\n";
    return 0;
}