/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 快速排序，使用双指针相向分割扫描，随机选择一个pibot = nums[i]，以pivot为基准，
// 左边发现大于它的值就和右边发现小于它的值交换，最后形成[<] pivot [>]的情况，返回下标（即它正确的位置）
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