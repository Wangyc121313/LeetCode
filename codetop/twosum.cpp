#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

vector<int> twosum(vector<int> nums, int k){
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        if(mp.count(k - nums[i])) return {i, mp[k - nums[i]]};
        mp[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans = twosum(nums, 9);
    for(int num : ans) cout << num << " ";
    return 0;
}