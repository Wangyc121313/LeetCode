#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n - 2; i++){
        int x = nums[i];
        if(i > 0 && x == nums[i - 1]) continue; 
        //由于排序了，所以相同的数一定在一起，跳过重复的数  
        int j = i + 1, k = n - 1;
        while(j < k){
            int sum = x + nums[j] + nums[k];
            if(sum == 0){
                ans.push_back({x, nums[j], nums[k]});
                j++;
                k--;
                while(j < k && nums[j] == nums[j - 1]) j++;//去重
                while(k > j && nums[k] == nums[k + 1]) k--;//去重
            }else if(sum < 0) j++;
            else k--;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for(auto& v : ans){
        for(auto& x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}