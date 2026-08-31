/*
给定若干个闭区间[start, end]，要求输出合并后的区间，按起点升序排列。
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
    if(intervals.empty()) return {};
    // 按照区间起点升序排序
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++){
        // 当前区间的起点小于等于merged中最后一个合并区间的终点
        if(intervals[i][0] <= merged.back()[1]){
            merged.back()[1] = max(intervals[i][1], merged.back()[1]);
        }else merged.push_back(intervals[i]);
    }
    return merged;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<vector<int>> ans = mergeIntervals(intervals);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
    return 0;
}