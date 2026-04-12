#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i = 0; i < nums.size() - 2; i++){
        int x = nums[i];
        if(i > 0 && x == nums[i - 1]) continue;
        int j = i + 1;
        int k = nums.size() - 1;
        while(j < k){
            int s = x + nums[j] + nums[k];
            if(s > 0) k--;
            else if(s < 0) j++;
            else {
                ans.push_back({x, nums[j], nums[k]});
                for(j++; j < k  && nums[j] == nums[j - 1]; j++);
                for(k++; j < k  && nums[k] == nums[k - 1]; k--);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for(auto v : ans){
        for(int num : v) cout << num << " ";
        cout << "\n";
    }
    return 0;
}