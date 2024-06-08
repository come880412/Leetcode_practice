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
    bool traverse(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        else if (!p && q) return false;
        else if (p && !q) return false;
        else if (p -> val != q -> val) return false;

        return traverse(p -> left, q -> left) && traverse(p -> right, q -> right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traverse(p, q);
    }
};