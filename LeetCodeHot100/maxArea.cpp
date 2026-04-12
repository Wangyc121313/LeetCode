#include <vector>
#include <iostream>
using namespace std;

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1, ans = 0;
    //盛水的面积取决于两个边界较短的那个，所以每次移动较短的边界
    while(l < r){
        int area = 0;
        area = (r - l) * min(height[l], height[r]);
        if(height[l] < height[r]) l++;
        else r--;
        ans = max(ans, area);
    }
    return ans;
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << "\n";
    return 0;
}