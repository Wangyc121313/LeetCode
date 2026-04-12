#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeNode(const vector<string>& nodes) {
	if (nodes.empty() || nodes[0] == "null") {
		return nullptr;
	}

	TreeNode* root = new TreeNode(stoi(nodes[0]));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);
	int index = 1;

	while (!nodeQueue.empty() && index < static_cast<int>(nodes.size())) {
		TreeNode* current = nodeQueue.front();
		nodeQueue.pop();

		if (index < static_cast<int>(nodes.size()) && nodes[index] != "null") {
			current->left = new TreeNode(stoi(nodes[index]));
			nodeQueue.push(current->left);
		}
		++index;

		if (index < static_cast<int>(nodes.size()) && nodes[index] != "null") {
			current->right = new TreeNode(stoi(nodes[index]));
			nodeQueue.push(current->right);
		}
		++index;
	}

	return root;
}

int dfs(TreeNode* root, int& ans){
    if(root == nullptr) return -1;// 以边的数量为单位，所以空节点返回-1
    int l = dfs(root->left, ans) + 1;   // 以边的数量为单位，所以要加1
    int r = dfs(root->right, ans) + 1;  // 以边的数量为单位，所以要加1
    ans = max(ans, l + r);
    return max(l, r);// 返回以当前节点为根的子树的最大深度（以边的数量为单位）
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
}

int main() {
    vector<string> nodes = {"1", "2", "3", "4", "5"};
    TreeNode* root = buildTreeNode(nodes);
    int result = diameterOfBinaryTree(root);
    cout << result << endl;
    return 0;
}