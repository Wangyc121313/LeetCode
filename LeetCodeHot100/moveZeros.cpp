#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = 0;
    for(int x : nums){
        if(x) nums[j++] = x;
    }
    fill(nums.begin() + j, nums.end(), 0);
}

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for(int x : nums) cout << x << " ";
    cout << "\n";
    return 0;
}