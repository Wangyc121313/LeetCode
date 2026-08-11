/* 
一个二维数组，要得到里面k*k区域之和的最大值和左上角的索引，考虑时间复杂度。

思路：构建前缀和矩阵P，其中P[i][j]表示原矩阵从(0,0)到(i-1,j-1)的子矩阵元素之和。
对于(r,c)为左上角索引的k✖k区域，其右下角索引为(r+k-1,c+k-1)，可以O(1)得到Sum=P[r+k][c+k] - P[r][c+k] - P[r+k][c] + P[r][c]
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Result{
    int maxSum;
    int row;
    int col;
};

Result maxKbyKSum(vector<vector<int>>& grid, int k){
    int m = grid.size();
    int n = grid[0].size();
    if(m < k || n < k) return {0, -1, -1};
    vector<vector<int>> P(m + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            P[i + 1][j + 1] = grid[i]
        }
    }
}