#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums){
    int ans = INT_MIN;
    int s = 0;
    int s_min = 0;//最小前缀和
    for(int num : nums){
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