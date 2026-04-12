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
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int ans = search(nums, target);
    cout << ans << "\n";
    return 0;
}