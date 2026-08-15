/*
56.合并区间

以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeInterval(vector<vector<int>>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    ans.push_back(nums[0]);
    for(int i = 1; i < nums.size(); i++){
        if(ans.back()[1] > nums[i][0]) ans.back()[1] = max(ans.back()[1], nums[i][1]);
        else ans.push_back(nums[i]);
    }
    return ans;
}

int main(){
    vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {9, 12}};
    vector<vector<int>> ans = mergeInterval(nums);
    for(auto num : ans){
        cout << num[0] << num[1] << "\n";
    }
    return 0;
}