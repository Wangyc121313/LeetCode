#include <vector>
#include <deque>
#include <iostream>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> q;
    //队列里存储元素的下标，保证队列头部是当前窗口的最大值
    for(int i = 0; i < n; i++){
        while(!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
        //比较大小，保持单调递减，同时将较小的元素弹出
        q.push_back(i);
        int l = i - k + 1;
        if(q.front() < l) q.pop_front();
        //如果队列头部的元素已经不在当前窗口了，就弹出
        if(l >= 0) ans.push_back(nums[q.front()]);
    }
    return ans;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for(const auto& x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}