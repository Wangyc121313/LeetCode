/*
4. 寻找两个正序数组的中位数

给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1); // 总是保证第一个数组的长度小于等于第二个数组的长度
    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    while(left <= right){
        int i = left + (right - left) / 2;
        int j = (m + n + 1) / 2 - i;
        // 将nums1分为[0,...,i-1]和[i,...,m-1]，将nums2分为[0,...,j-1]和[j,...,n-1]
        int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int R1 = (i == m) ? INT_MAX : nums1[i];
        int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int R2 = (j == n) ? INT_MAX : nums2[j];
        // 核心目标是保证L1<=R2且R1>=L2
        if(L1 <= R2 && R1 >= L2){
            if((m + n) % 2 == 0) return (max(L1, R1) + min(L2, R2)) / 2.0;  // 偶数情况（举例：[1,3]和[2,4]）
            else return (max(L1, L2));                                      // 奇数情况（举例：[1,3]和[2,4,5]）
        }else if(L1 > R2){
            right = i - 1; // nums1的左半部分太大
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