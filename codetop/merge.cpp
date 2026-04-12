#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int>& nums1, vector<int>& nums2, int m, int n){
    int p1 = m - 1, p2 = n - 1, p = m + n - 1;
    while(p2 >= 0){
        if(p1 >= 0 && nums1[p1] > nums2[p2]){
            nums1[p--] = nums1[p1--];
        }else{
            nums1[p--] = nums2[p2--];
        }
    }
}

int main(){
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, nums2, 3, 3);
    for(int num : nums1){
        cout << num << " ";
    }
    return 0;
}