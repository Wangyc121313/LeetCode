#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    if(root == nullptr) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> vals;
        int n = q.size();
        for(int i = n; i > 0; i--){
            auto node = q.front();
            q.pop();
            vals.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(ans.size() % 2) reverse(vals.begin(), vals.end());
        ans.push_back(move(vals));
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(3);
    TreeNode* a1 = new TreeNode(9);
    TreeNode* a2 = new TreeNode(20);
    TreeNode* a11 = new TreeNode(2);
    TreeNode* a21 = new TreeNode(15);
    TreeNode* a22 = new TreeNode(7);
    TreeNode* a221 = new TreeNode(8);
    TreeNode* a222 = new TreeNode(9);
    root->left = a1;
    root->right = a2;
    a1->left = a11;
    a2->left = a21;
    a2->right = a22;
    a22->left = a221;
    a22->right = a222;
    vector<vector<int>> ans = zigzagLevelOrder(root);
    for(vector<int> an : ans){
        for(int num : an) cout << num << " ";
        cout << "\n";
    }
    return 0;
}