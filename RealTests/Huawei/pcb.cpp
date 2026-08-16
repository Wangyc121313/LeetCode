/*
硬件PCB板上两个芯片之间需要布一条I2C链路，两个芯片分别位于左上角和右下角，PCB走线只能向下和向右移动，但是当前PCB上已经有一些器件或者干扰源，器件和干扰源都要绕开，给一个二维数组，0表示可以布线，1表示已有器件，2表示开关电源，3表示开孔，4表示GND，避开干扰源信号衰减越小，而且转弯次数越少越好，需要你找到从芯片A到芯片B之间通路的最少转弯次数，实现布线方案预评估，如果没有通路，直接返回-1。

输入描述：
第一行2个整型数据m，n分别表示行数和列数，超出边界值直接返回-后面m行n列整数矩阵表示硬件PCB板上已有器件分布情况，0表示可以在线，1表示已有器件，2表示开关电源，3表示开孔，4表示GND。
0 < m,n < 100
0 < pcb[i][j] < 4 

输出描述：
返回最小转弯次数，如果没有通路，返回-1。
*/
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