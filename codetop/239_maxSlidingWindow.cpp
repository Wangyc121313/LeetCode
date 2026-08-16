/*
239. 滑动窗口最大值

给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。
*/
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int> nums, int k) {
    int n = nums.size();
    deque<int> q;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        while(!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
        q.push_back(i);
        int l = i - k + 1;
        if(q.front() < l) q.pop_front();
        if(l >= 0) ans.push_back(nums[q.front()]);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for(int x : ans) cout << x << "";
    cout << "\n";
    return 0;
}