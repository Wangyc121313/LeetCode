/*
704. 二分查找

给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果 target 存在返回下标，否则返回 -1。
你必须编写一个具有 O(log n) 时间复杂度的算法。
*/
#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size() - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(nums[m] == target) return m;
        if(nums[m] > nums[r]){
            if(nums[l] <= target && nums[m] > target) r = m - 1;
            else l = m + 1;
        }else{
            if(nums[m] < target && nums[r] >= target) l = m + 1;
            else r = m - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {-1, 3, 7, 10, 23};
    int target = 3;
    int ans = search(nums, target);
    cout << ans << "\n";
    return 0;
}