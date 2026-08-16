/*
给定一个长度为n数列A=[A1,A2,...An]，由于某种原因，这个数列不够合法。
定义一个合法的数列是，每个在数列中出现的数值，其出现的次数都是唯一的。
假设A=[1,1,2,2]，1和2都出现了2次，那么这个数列是不合法的。
现在你可以从该数列A中删除一些数，使得每个数值出现次数都是唯一的，删除一个数的代价为这个数的大小。
例如，对于A=[1，1,2,2]，最少删除一个数变成[1,2,2]或[1,1,2]，代价分别为1和2，最小代价为1。
输出将该数列变成合法的最小代价。

示例：
输入：
4
1 2 2 1
输出：1

输入：
4
1 2 3 4
输出：6
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

int uniqueFrequency(vector<int>& nums){
    // 建立[数值，频次]的哈希表
    unordered_map<long long, int> map;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        map[nums[i]]++;
    }
    int max_f = 0;
    for(auto& p : map){
        max_f = max(max_f, p.second);
    }
    // 每个频次分组加入对应的数字
    vector<vector<long long>> freq_groups(max_f + 1);
    for(auto& p : map) freq_groups[p.second].push_back(p.first);

    // 贪心，每个频次只保留最大的数字
    priority_queue<long long> pq;
    long long total_cost = 0;
    long long pq_sum = 0; // 堆中所有元素之和
    // 从频次最高值进行遍历，因为每个
    for(int f = max_f; f >= 1; f--){
        for(long long x : freq_groups[f]){
            pq.push(x); // 先将所有频次为f对应的数字加入优先队列中，堆顶为最大元素
            pq_sum += x;
        }
        if(!pq.empty()){
            long long max = pq.top(); // 每个频次的最大数字
            pq.pop(); // 这里弹出最大数字，而其他数字自动保留至下一次判断中！
            pq_sum -= max;
        }
        total_cost += pq_sum;
    }
    return total_cost;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; 
        nums.push_back(x);
    }
    cout << uniqueFrequency(nums) << "\n";
    return 0;
}