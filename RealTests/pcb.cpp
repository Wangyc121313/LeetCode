#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 定义一个无穷大

void solve() {
    int m, n;
    if (!(cin >> m >> n)) return;

    if (m <= 0 || n <= 0 || m > 100 || n > 100) {
        cout << "-1\n";
        return;
    }

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0) {
        cout << "-1\n";
        return;
    }

    if (m == 1 && n == 1) {
        cout << "0\n";
        return;
    }

    // dp[i][j][0]：最后一步向右；dp[i][j][1]：最后一步向下
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, INF)));

    dp[0][0][0] = 0;
    dp[0][0][1] = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != 0) continue;
            if (i == 0 && j == 0) continue;

            // 如果从左边走过来（向右走）
            if (j > 0 && grid[i][j - 1] == 0) {
                dp[i][j][0] = min(dp[i][j - 1][0], dp[i][j - 1][1] + 1);
                //想要向右走，原来朝右则不用加，原来朝下则加一，两者取最小值
            }

            // 如果从上边走过来（向下走）
            if (i > 0 && grid[i - 1][j] == 0) {
                dp[i][j][1] = min(dp[i - 1][j][1], dp[i - 1][j][0] + 1);
            }
        }
    }

    int ans = min(dp[m - 1][n - 1][0], dp[m - 1][n - 1][1]);
    
    if (ans >= INF) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    // 开启快速 I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}