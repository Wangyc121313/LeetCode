#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int OrangeRotting(vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size();
    int minutes = 0;
    int fresh = 0;
    queue<pair<int, int>> q;
    int directions[4][2] = {{1, 0}, {-1 , 0}, {0, 1}, {0, -1}};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2) q.push({i, j});
            else if(grid[i][j] == 1) fresh++;
        }
    }
    if(fresh == 0) return 0;
    while(!q.empty() && fresh != 0){
        minutes++;
        int size = q.size();
        for(int i = 0; i < size; i++){
            auto [r, c] = q.front();
            q.pop();
            for(auto& d : directions){
                int rc = r + d[0], cc = c + d[1];
                if(rc < m && rc >= 0 && cc < n && cc >=0 && grid[rc][cc] == 1){
                    grid[rc][cc] = 2;
                    fresh--;
                    q.push({rc, cc});
                }
            }
        } 
    }
    return fresh == 0 ? minutes : -1;
}

int main(){
    vector<vector<int>> grid = {{2, 1, 1}, {1 , 1, 0}, {0, 1, 1}};
    cout << OrangeRotting(grid) << "\n";
    return 0;
}