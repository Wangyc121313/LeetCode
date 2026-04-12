#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* head = nullptr;

void flatten(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    flatten(root->right);
    flatten(root->left);
    root->left = nullptr;
    root->right = head;
    head = root;
}

int main() {
    // 手动构建 root = [1,2,5,3,4,null,6]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    flatten(root);
    TreeNode* cur = root;
    while(cur){
        cout << cur->val << " ";
        cur = cur->right;
    }
    return 0;
}