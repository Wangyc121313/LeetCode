#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector<int>& nums, int left, int right){
    int i = left + rand()%(right - left + 1);
    int pivot = nums[i];
    swap(nums[i], nums[left]);
    i = left + 1;
    int j = right;
    while(true){
        while(i <= j && nums[i] < pivot) i++;
        while(j >= i && nums[j] > pivot) j--;
        if(i >= j) break;
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
    swap(nums[left], nums[j]);
    return j;
}
        
int findKthLargest(vector<int>& nums, int k){
    srand(time(NULL));
    int n = nums.size();
    int target_index = n - k;
    int left = 0;
    int right = n - 1;
    while(true){
        int i = partition(nums, left, right);
        if(i == target_index) return nums[i];
        else if(i > target_index) right = i - 1;
        else left = i + 1;
    }
}

int main(){
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int ans = findKthLargest(nums, 2);
    cout << ans << "\n";
    return 0;
}