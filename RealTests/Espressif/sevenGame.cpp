/*
有一个数n，m个孩子玩逢7游戏，1->...->m->1循环，数到n，初始每个孩子的难度为0，遇到7的倍数或者含有7就跳过，同时难度+1，要求输出最大的难度。

示例输入与输出：
输入3 20
输出2
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 辅助函数，判断是否为7的倍数或十进制含有7
bool hasorDiv7(int x){
    if(x % 7 == 0) return true;
    while(x){
        if(x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

int maxDiff(int m, int n){
    vector<int> difficulty(m, 0);
    int cur_child = 0; //0-based，表示当前轮到哪个孩子报数
    for(int num = 1; num <= n; num++){
        if(hasorDiv7(num)){
            difficulty[cur_child]++;
        }else{
            cur_child = (cur_child + 1) % m;
        } 
    }
    return *max_element(difficulty.begin(), difficulty.end()); //O(m)获得最大值
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (cin >> m >> n) {
        cout << solution(m, n) << "\n";
    }
    return 0;
}