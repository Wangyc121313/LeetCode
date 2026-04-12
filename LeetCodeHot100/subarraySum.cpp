#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> s(n + 1);
    for(int i = 0; i < n; i++) s[i + 1] = s[i] + nums[i];//前缀和
    unordered_map<int, int> cnt;    //key为和，value为出现次数
    int ans = 0;
    for(int sj : s){
        if(cnt.count(sj - k)) ans += cnt[sj - k];
        //如果存在前缀和为sj-k的情况，则说明存在一个子数组的和为k
        cnt[sj]++;
    }
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int ans = subarraySum(nums, k);
    cout << ans << "\n";
    return 0;
}