#include <vector>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelorder(TreeNode* root){
    if(root == nullptr) return{};
    vector<vector<int>> ans;
    vector<TreeNode*> cur = {root};
    while(cur.size()){
        vector<TreeNode*> next;
        vector<int> vals;
        for(TreeNode* node : cur){
            vals.push_back(node->val);
            if(node->left) next.push_back(node->left);
            if(node->right) next.push_back(node->right);
        }
        ans.push_back(move(vals));
        cur  = move(next);
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* n11 = new TreeNode(2);
    TreeNode* n12 = new TreeNode(4);
    TreeNode* n111 = new TreeNode(3);
    root->left = n11;
    root->right = n12;
    n11->right = n111;
    vector<vector<int>> ans = levelorder(root);
    for(auto a : ans){
        for(int num : a) cout << num << " ";
    }
    return 0;
}