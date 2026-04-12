#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<char>>& grid, int row, int col){
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') return;
    grid[row][col] = '0';
    dfs(grid, row - 1, col);
    dfs(grid, row + 1, col);
    dfs(grid, row, col - 1);
    dfs(grid, row, col + 1);
}

int numsIslands(vector<vector<char>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '1'){
                ans++;
                dfs(grid, i, j);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},{'1', '1', '1', '1', '0'}, {'0', '0', '0', '0', '1'}};
    int ans = numsIslands(grid);
    cout << ans << "\n";
    return 0;
}