#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    while(left <= right){
        int i = left + (right - left) / 2;
        int j = (m + n + 1) / 2 - i;
        int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int R1 = (i == m) ? INT_MAX : nums1[i];
        int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int R2 = (j == n) ? INT_MAX : nums2[j];
        if(L1 <= R2 && R1 >= L2){
            if((m + n) % 2 == 0) return (max(L1, R1) + min(L2, R2)) / 2.0;
            // 偶数情况（举例：[1,3]和[2,4]）
            else return (max(L1, L2));
            // 奇数情况（举例：[1,3]和[2,4,5]）
        }else if(L1 > R2){
            right = i -1;
        }else{ left = i + 1;}
    }
    return 0.0;
}

int main(){
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4, 5};
    cout << findMedianSortedArrays(nums1, nums2) << "\n";
    return 0;
}