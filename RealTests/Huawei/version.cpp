/*
一个项目中，除了自研的代码外，还会依赖很多二进制包(后续简称为包)，这些包也会依赖其它的包，每个被依赖的包还有版本号的要求本题借鉴了包管理的思想。
需要完成一个简易的包依赖关系分析和处理的模型，要求对输入的一串依赖关系进行分析，判断是否存在循环依赖，如果有循环依赖则输出不合理;否则进一步对被依赖包的版本号进行规整，并输出规整后的依赖关系串。

简单的依赖关系如下：
- 依赖关系1:(1.3,11)，表示包1依赖包3的11版本;
- 依赖关系2:(2.3.12)，表示包2依赖包3的12版本

因此，该依赖关系的数据结构由三个属性组成
- 序号:任意正整数，用于唯一标识一个二进制包(如上图中的”包1")。
- 依赖包序号:任意正整数，表示该包所依赖的另一个包的序号(如上图中的“包3")。
- 依赖包版本号:正整数(如上图中的“包3”的”11版本")。而且1<=版本号<=99

基于该依赖关系的数据结构，我们需要进行如下的判断和处理:
1. 判断包依赖关系中是否存在循环依赖：
包之间的依赖关系不能形成循环。例如，包1依赖包2，包2依赖包3，包3又依赖包1，这种情况属于循环依赖，不合理。版本号不纳入循环依赖与否的判断。

2. 对包依赖关系的版本号进行规整处理：
如果判断包依赖关系是合理的，我们需要进一步对依赖包的版本号进行规整处理。对于多个包依赖同一个包的情况，我们需要判断被依赖包的不同版本号，取其中的最大值，然后输出新的依赖关系。

输入描述：
每次会输入两组依赖关系的信息，分别解析和输出两组结果，每组的格式定义如下:
- 包依赖关系的个数:正整数n($0 \le n \le 100$)，表示待输入的包依赖关系的个数。
- 包依赖关系:每行表示一个依赖关系，格式为:序号，依赖包序号，依赖包版本号。共n行。
- 序号，依赖包序号，依赖包版本号的定义参考前文的数据定义章节。
  
注意:这两组依赖关系是完成独立的，建议从方法复用角度，合理对方法进行抽取，避免出现重复代码。

输出描述：
若存在循环依赖，则输出"false"；否则输出规整后的依赖关系，每行一个，格式为:序号，依赖包序号，依赖包版本号。共n行。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<Edge> edges(n);
    unordered_map<int, int> id_map;
    int num_nodes = 0;

    auto get_id = [&](int real_id) {
        if (id_map.find(real_id) == id_map.end()) {
            id_map[real_id] = num_nodes++;
        }
        return id_map[real_id];
    };

    // 适当放大数组，防止节点数略微超标
    vector<vector<int>> adj(300); 
    vector<int> in_degree(300, 0); 
    unordered_map<int, int> max_version; 

    for (int i = 0; i < n; i++) {
        char comma1, comma2;
        cin >> edges[i].u >> comma1 >> edges[i].v >> comma2 >> edges[i].w;
        
        int u_idx = get_id(edges[i].u);
        int v_idx = get_id(edges[i].v);

        // u 依赖 v，所以 v 是前置条件。v 指向 u。
        adj[v_idx].push_back(u_idx);
        in_degree[u_idx]++; // u 依赖别人，所以 u 的入度增加

        max_version[edges[i].v] = max(max_version[edges[i].v], edges[i].w);
    }

    queue<int> q;
    for (int i = 0; i < num_nodes; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    int visited_count = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        visited_count++;

        for (int next_node : adj[curr]) {
            in_degree[next_node]--;
            if (in_degree[next_node] == 0) {
                q.push(next_node);
            }
        }
    }

    if (visited_count != num_nodes) {
        cout << "false" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << edges[i].u << "," << edges[i].v << "," << max_version[edges[i].v] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 2; 
    while (t--) {
        solve();
    }
    return 0;
}