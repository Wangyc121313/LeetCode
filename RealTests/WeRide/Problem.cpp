/*
小明闯关，有初始脑力值，每道题有脑力门槛和对应脑力值，达到门槛后解决后减去对应脑力值，脑力值不可恢复，需要返回额外需要的脑力值，解题顺序任意。

输入：
第一行为用例数T
第二行为N和K，分别对应初始脑力值和题目数
后面每行前者为p1门槛，后者为p2所需脑力值

示例输入：
2
0 2
100 50
50 50
150 2
100 100
50 50

示例输出：
100
0

分析：
假设有两道题，分别为A(p1A, p2A)和B(p1B, p2B)。
先做A再做B，做A时需要门槛>=p1A，做完A消耗p2A后再做B，需要E-p2A>=p1B即E>=p2A+p1B，总共需要初始脑力为max(p1A, p2A+p1B)；
同理，对于先做B，初始脑力为max(p1B, p1A+p2B)。
为了初始脑力尽可能小，希望：p1B+p2A < p1A+p2B 即 p1B-p2B < p1A-p2A
贪心的准则即：按照p1-p2的大小进行排序
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Problem{
    long long p1;
    long long p2;
};

void solve() {
    long long N;
    int K;
    if(!(cin >> N >> K)) return;
    vector<Problem> probs(K);
    for(int i = 0; i < K; i++){
        cin >> probs[i].p1 >> probs[i].p2;
    }
    // 贪心排序
    sort(probs.begin(), probs.end(), [](const Problem& a, const Problem& b) {
        return (a.p1 - a.p2) > (b.p1 - b.p2); 
    });
    long long cur = N;
    long long need = 0;
    for(const auto& prob : probs){
        if(cur < prob.p1) {
            need += (prob.p1 - cur);
            cur = prob.p1; //补齐到门槛
        }
        cur -= prob.p2;
    }
    cout << need << "\n";
}

int main(){
    int T;
    if(cin >> T) {
        while(T--) solve();
    }
    return 0;
}