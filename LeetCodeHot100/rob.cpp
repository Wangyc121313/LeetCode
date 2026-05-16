#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums){
    int ans = 0;
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);//注意这里是i-1
    }
    return dp[n];
}

int main(){
    vector<int> nums = {4, 2, 5, 4};
    cout << rob(nums) << "\n";
    return 0;
}
