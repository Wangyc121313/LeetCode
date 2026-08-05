/*
给你一个整数数组 nums，请你将该数组升序排列。

你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。
*/
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int partitionArray(vector<int>& nums, int left, int right) {
    int i = left + rand() % (right - left + 1);
    int pivot = nums[i];
    swap(nums[left], nums[i]);
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

void quick_sortArray(vector<int>& nums, int left, int right){
    if(left >= right) return;
    int i = partitionArray(nums, left, right);
    quick_sortArray(nums, left, i - 1);
    quick_sortArray(nums, i + 1, right);
}

int main(){
    vector<int> nums = {5, 2, 3, 1};
    quick_sortArray(nums, 0, 3);
    for(int num : nums) cout << num << "\n";
    return 0;
}