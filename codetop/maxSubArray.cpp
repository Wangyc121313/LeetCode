/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组是数组中的一个连续部分。
*/
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums){
    int ans = INT_MIN;
    int s = 0;
    int s_min = 0;//最小前缀和
    for(int num : nums){ // 对于每个索引，只要去找前面的最小前缀和减去即可
        s += num;
        ans = max(ans, s - s_min);
        s_min = min(s_min, s);
    }
    return ans;
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << "\n";
    return 0;
}