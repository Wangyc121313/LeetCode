/*
236.二叉树的最近公共祖先

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
*/
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == nullptr || root == p || root == q) return root;//找到就返回
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if(l && r) return root;//两边都非空说明当前节点就是公共
    return l ? l : r;
}

int main(){
    TreeNode* root = new TreeNode(3);
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n11 = new TreeNode(6);
    TreeNode* n12 = new TreeNode(2);
    TreeNode* n121 = new TreeNode(7);
    TreeNode* n122 = new TreeNode(4);
    TreeNode* n21 = new TreeNode(0);
    TreeNode* n22 = new TreeNode(8);
    root->left = n1;
    root->right = n2;
    n1->left = n11;
    n1->right = n12;
    n12->left = n121;
    n12->right = n122;
    n2->left = n21;
    n2->right = n22;
    TreeNode* node = lowestCommonAncestor(root, n1, n2);
    cout << node->val << "\n";
    return 0;
}