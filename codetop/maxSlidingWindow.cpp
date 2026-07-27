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