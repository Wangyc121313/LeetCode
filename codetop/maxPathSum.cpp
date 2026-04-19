#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int ans = INT_MIN;

int MaxPathSum(TreeNode* node){
    if(node == nullptr) return 0;
    int left = MaxPathSum(node->left);//左子树的最大路径和
    int right = MaxPathSum(node->right);//右子树的最大路径和
    ans = max(ans, left + right + node->val);//更新全局最大路径和
    return max(max(left, right) + node->val, 0);
    //返回值为当前节点的值加上左子树或右子树的最大路径和，如果小于0则返回0，表示不选择该路径
}

int main(){
    TreeNode* root = new TreeNode(-10);
    TreeNode* a1 = new TreeNode(9);
    TreeNode* a2 = new TreeNode(20);
    TreeNode* a3 = new TreeNode(15);
    TreeNode* a4 = new TreeNode(7);
    root->left = a1;
    root->right = a2;
    a2->left = a3;
    a2->right = a4;
    MaxPathSum(root);
    cout << ans << "\n";
    return 0;
}