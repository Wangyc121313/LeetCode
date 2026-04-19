#include <vector>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> ans;

void rightSideView(TreeNode* node, int depth){
    if(node == nullptr) return;
    if(depth == ans.size()){
        ans.push_back(node->val);
    }
    rightSideView(node->right, depth + 1);
    rightSideView(node->left, depth + 1);
}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* a1 = new TreeNode(2);
    TreeNode* a12 = new TreeNode(5);
    TreeNode* a2 = new TreeNode(3);
    TreeNode* a21 = new TreeNode(4);
    root->left = a1;
    root->right = a2;
    a1->right = a12;
    a2->left = a21;
    rightSideView(root, 0);
    for(int num : ans){
        cout << num << "\n";
    }
    return 0;
}