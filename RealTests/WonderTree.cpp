#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long minOperations(int n, vector<long long>& a, vector<vector<int>>& tree){
    vector<int> order;
    vector<int> parent(n + 1, 0); 
    queue<int> q;

    q.push(1);
    parent[1] = -1; 

    // 1. BFS 层序遍历
    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);
        
        for(int v : tree[u]){
            if(parent[v] == 0){ 
                parent[v] = u;
                q.push(v);
            }
        }
    }

    long long total_ops = 0;

    // 2. 倒序遍历（自底向上）
    for(int i = order.size() - 1; i >= 0; i--){
        int u = order[i];
        long long sum_children = 0;
        bool is_leaf = true;
        
        for(int v : tree[u]){
            if(v != parent[u]){
                is_leaf = false;
                sum_children += a[v]; 
            }
        }
        
        // 3. 补足差价并更新自身
        if(!is_leaf && a[u] < sum_children){
            total_ops += (sum_children - a[u]);
            a[u] = sum_children; 
        }
    }
    
    return total_ops;
}

int main(){
    // 提升 IO 速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // 这里的读取保证了不会卡死
    if (!(cin >> n)) return 0; 
    
    // 务必开 n + 1 的空间，防止 1-indexed 越界崩溃
    vector<long long> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i]; 
    
    vector<vector<int>> tree(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    long long ans = minOperations(n, a, tree);
    
    // 使用 endl 强制刷新本地控制台缓冲区，确保一定能看到输出
    cout << ans << endl; 
    
    return 0;
}