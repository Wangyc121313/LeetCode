#include <iostream>
#include <vector>
using namespace std;

vector<int> SprialOrder(vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size();
    if(m == 0) return {};
    vector<int> ans;
    int u = 0, d = m - 1, l = 0, r = n - 1;
    while(true){
        for(int i = l; i <= r; i++) ans.push_back(grid[u][i]);
        if(++u > d) break;
        for(int i = u; i <= d; i++) ans.push_back(grid[i][r]);
        if(--r < l) break;
        for(int i = r; i >= l; i--) ans.push_back(grid[d][i]);
        if(--d < u) break;
        for(int i = d; i >= u; i--) ans.push_back(grid[i][l]);
        if(++l > r) break;
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = SprialOrder(grid);
    for(int num : ans) cout << num << "\n";
    return 0;
}