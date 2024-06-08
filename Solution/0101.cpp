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
    bool traverse(TreeNode *leftTree, TreeNode *rightTree) {
        if (!leftTree && !rightTree) return true;
        else if (!leftTree && rightTree) return false;
        else if (leftTree && !rightTree) return false;
        else if (leftTree -> val != rightTree -> val) return false;

        return traverse(leftTree -> left, rightTree -> right) && traverse(leftTree -> right, rightTree -> left);
    }

    bool isSymmetric(TreeNode* root) {
        return traverse(root -> left, root -> right);
    }
};