#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& nums){
    int ans = 0;
    int min_price = nums[0];
    for(int num : nums){
        ans = max(ans, num - min_price);
        min_price = min(min_price, num);
    }
    return ans;
}

int main(){
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(nums) << "\n";
    return 0;
}