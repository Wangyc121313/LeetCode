#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& nums){
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
    vector<vector<int>> ans = merge(nums);
    for(auto num : ans){
        cout << num[0] << num[1] << "\n";
    }
    return 0;
}