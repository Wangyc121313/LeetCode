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