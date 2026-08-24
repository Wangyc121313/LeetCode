/*
给你一个n，一个数组，要求输出由这个数组中元素组成的不超过n的最大数。

示例：n=23492，nums={2,4,9}，输出：22999。

思路：数字转换为字符串，数组降序，对于不超过n的最大数，有两种考虑。
1. 构建一个长度相同的数（同位数贪心）
- 从最高位开始尽量选择与当前位相等的数字
- 如果某一位满足严格小于n的当前位，后续位无脑填入最大值
- 如果某一位找不到小于等于n的当前位，需要回溯到上一位然后改为更小的数字，再将后续无脑填入最大值
2. 构建一个长度位L-1的数
- 首位回溯失败的情况，所有位填入最大值
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

bool dfs(const string& s, const vector<int>& digits, int index, bool is_limit, string& path){
    if(index == (int)s.size()) return true;
    // 用is_limit表示当前是否受到n对应位的限制
    if(!is_limit){
        path += to_string(digits[0]);
        return dfs(s, digits, index + 1, false, path);
    }
    int target = s[index] - '0';
    for(int d : digits){
        if(d == target){
            // 由于选了相同的数字，后续继续受限
            path += to_string(d);
            // 判断后续是否构建成功，如果后续的所有数位全部成功找到了合适的数字，深层递归就会返回 true
            if(dfs(s, digits, index + 1, true, path)){
                return true;
            }
            // 上面没有执行，说明需要回溯
            path.pop_back();
        }else if(d < target){
            path += to_string(d); // 满足严格小于，后续直接无脑最大值，并且解除限制
            if(dfs(s, digits, index + 1, false, path)){
                return true;
            }
            path.pop_back();
        }
        // d > target时通过循环到下一位（digits已降序）
    }
    return false;
}

int maxNumber(int n, vector<int>& digits){
    sort(digits.begin(), digits.end(), greater<int>());
    string s = to_string(n);
    int len = s.length();
    string res = "";
    // 尝试构建长度相同的数字
    if(dfs(s, digits, 0, true, res)){
        return stoi(res);
    }
    string fallback = "";
    for(int i = 0; i < len - 1; i++) fallback += to_string(digits[0]);
    return fallback.empty() ? -1 : stoi(fallback);
}

int main(){
    int n;
    if(cin >> n){
        string dummy;
        getline(cin, dummy);
        string line;
        getline(cin, line);
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        vector<int> digits;
        int val;
        while(ss >> val) digits.push_back(val);
        cout << maxNumber(n, digits) << "\n";
    }
    return 0;
}