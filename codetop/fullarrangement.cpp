#include <vector>
#include <iostream>
using namespace std;

void backtrack(const vector<int>& nums, vector<bool>& used, vector<vector<int>>& ans, vector<int>& path){
    if(path.size() == nums.size()){
        ans.push_back(path);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(used[i]) continue;
        path.push_back(nums[i]);
        used[i] = true;
        backtrack(nums, used, ans, path);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    backtrack(nums, used, ans, path);
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for(vector num : ans){
        for(int n : num) cout << n << " ";
        cout << ",";
    }
    return 0;
}