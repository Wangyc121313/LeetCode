/*
给定一个长度为n的整数数组a1,.a2...an(下标从1开始)。对于任意两个不同下标i和j，定义它们的“斜率”为|a_i-a_j|/|i-j|
设所有下标对中斜率的最小值为(即主目标)，在所有取到r的对中，下标距离|i-j|的最大值记为D(即次目标)。给定数组，请求出最小斜率r和最大距离D。

输入描述
第一行一个整数n.其中2<=n<=200000
第二行n个整数a1,a2...,an，空格分隔，其中-10^9<=ai<=10^9

输出描述
第一行一个最简分数p/q，表示最小斜率r;当p/q为整数时，直接给出整数
第二行一个整数D，表示取到最小斜率的下标对中的最大距离|i-j|。

示例
输入：
5
0 100 50 1 101
输出：
1/3
3

分析
1.最小斜率必定在数值相邻的点之间取得：假设按照ai进行排序，对于排序好的三个点A、B、C，连接AC的斜率不会小于min(AB斜率，BC斜率)
2.假设存在相同数值的情况，只需要考虑尽可能让|i-j|大
3.数值互不相同的情况下，r>0，遍历排序后的相邻元素对，维护p/q
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

// 辅助函数，比较p1/q1是否小于p2/q2
bool isLess(long long p1, long long q1, long long p2, long long q2){
    return (__int128)p1 * q2 < (__int128)p2 * q1;
}

// 辅助函数，比较p1/q1是否等于p2/q2
bool isEqual(long long p1, long long q1, long long p2, long long q2) {
    return (__int128)p1 * q2 == (__int128)p2 * q1;
}

// 辅助函数，辗转相除法计算最简分数
long long gcd(long long a, long long b){
    // 举例：[60, 18]->[18, 6]->[6, 0]
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

struct Element{
    long long val;
    int idx;
};

int main(){
    int n;
    cin >> n;
    vector<Element> a(n);
    unordered_map<long long, pair<int, int>> pos;   // val -> {min_idx, max_idx}
    bool has_zero = false;
    for(int i = 0; i < n; i++){
        cin >> a[i].val;
        a[i].idx = i + 1; // 索引更新为1~n
        // 哈希表记录首次出现和末次出现的下标，分别为min_idx和max_idx
        // 如果没出现过，pair的first和second均更新为首次出现的下标
        // 即使后续排序，也已经绑定val和idx
        if(!pos.count(a[i].val)){
            pos[a[i].val] = {a[i].idx, a[i].idx};
        }else{
            has_zero = true;
            pos[a[i].val].second = a[i].idx;
        }
    }
    // 存在相同元素
    if(has_zero){
        int max_D = 0;
        for(auto& kv : pos){
            int d = kv.second.second - kv.second.first;
            if(d > max_D) max_D = d;
        }
        cout << 0 << "\n";
        cout << max_D << "\n";
        return 0;
    }
    // 不存在相同元素
    // 按数值升序排列
    sort(a.begin(), a.end(), [](const Element& e1, const Element& e2) {
        return e1.val < e2.val;
    });
    long long best_p = 2e18;
    long long best_q = 1;
    long long max_D = 0;
    // 以相邻元素为单位计算
    for(int i = 0; i < n - 1; i++){
        long long p = a[i + 1].val - a[i].val;
        long long q = abs(a[i + 1].idx - a[i].idx);
        if(isLess(p, q, best_p, best_q)){
            best_p = p;
            best_q = q;
            max_D = q;
        }else if(isEqual(p, q, best_p, best_q)){
            max_D = max(max_D, q);
        }
    }
    long long g = gcd(best_p, best_q);
    best_p /= g;
    best_q /= g;
    if(best_q == 1){
        cout << best_p << "\n";
    }else{
        cout << best_p << "/" << best_q << "\n";
    }
    cout << max_D << "\n";
    return 0;
}