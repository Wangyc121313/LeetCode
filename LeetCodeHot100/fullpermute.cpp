#include <iostream>
#include <vector>
using namespace std;

void backtrack(const vector<int>& nums, vector<bool> & used, vector<vector<int>>& ans, vector<int>& path){
    if(path.size() == nums.size()){
        ans.push_back(path);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        backtrack(nums, used, ans, path);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> fullpermute(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    backtrack(nums, used, ans, path);
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = fullpermute(nums);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << "";
        }
        cout << "\n";
    }
    return 0;
}