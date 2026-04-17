#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int solution(vector<vector<int>>& adj, vector<int>& init, vector<int>& goal, int n){
    // BFS 计算深度和父节点
    vector<int> parent(n + 1, 0);
    vector<int> depth(n + 1, 0);
    queue<int> q;
    q.push(1);      // 根节点入队
    parent[1] = -1; // 根节点的父节点设为-1表示没有父节点
    depth[1] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(v == parent[u]) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            q.push(v);
        }
    }

    int ans = 0;
    struct State{int node, even, odd;};
    stack<State> st;
    st.push({1, 0, 0});
    while(!st.empty()){
        State cur = st.top();
        st.pop();
        int u = cur.node, even = cur.even, odd = cur.odd;
        int flip = (depth[u] % 2 == 0) ? even : odd;
        int delta = goal[u] ^ init[u];
        if(flip != delta){
            ans++;
            if(depth[u] % 2 == 0) even ^= 1;
            else odd ^= 1;
        }
        for(int v : adj[u]){
            if(v == parent[u]) continue;
            st.push({v, even, odd});
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> init(n);
    vector<int> goal(n);
    for(int i = 0; i < n; i++) cin >> init[i];
    for(int i = 0; i < n; i++) cin >> goal[i];
    int ans = solution(adj, init, goal, n);
    cout << ans << "\n";
    return 0;
}