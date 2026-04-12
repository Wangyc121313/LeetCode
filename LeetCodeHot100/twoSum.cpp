#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        if(mp.count(target - nums[i])) return {mp[target - nums[i]], i};
        mp[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}