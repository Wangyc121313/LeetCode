/*
42. 接雨水

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> nums){
    int n = nums.size();
    vector<int> pre_max(n);
    pre_max[0] = nums[0];
    for(int i = 1; i < n; i++){
        pre_max[i] = max(pre_max[i - 1], nums[i]);
    }
    vector<int> suf_max(n);
    suf_max[n - 1] = nums[n - 1];
    for(int i = n - 2; i >= 0; i--){
        suf_max[i] = max(suf_max[i + 1], nums[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += min(pre_max[i], suf_max[i]) - nums[i];
    }
    return ans;
}

int main(){
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = trap(nums);
    cout << ans << "\n";
    return 0;
}