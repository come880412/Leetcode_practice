/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int currMax) {
        if (!root) return 0;

        currMax = max(currMax, root->val);
        int left = dfs(root->left, currMax);
        int right = dfs(root->right, currMax);
        int curr = root->val >= currMax ? 1 : 0;

        return curr + left + right;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};