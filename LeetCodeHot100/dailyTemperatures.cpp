#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for(int i = 0;i < n; i++){
        while(!st.empty() && nums[i] > nums[st.top()]){
            int pre = st.top();
            st.pop();
            ans[pre] = i - pre;
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> nums = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(nums);
    for(int an : ans){
        cout << an << " ";
    }
    cout << "\n";
    return 0;
}