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
struct Info {
    int sum;
    int count;
};

class Solution {
public:
    Info Traverse(TreeNode* root, int& out) {
        if (root == nullptr)
            return {0, 0};
        
        Info left = Traverse(root -> left, out);
        Info right = Traverse(root -> right, out);
        int count = 1 + left.count + right.count;
        int sum = root -> val + left.sum + right.sum; 
        if (sum / count == root -> val)
            out += 1;
        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int out = 0;
        Info result = Traverse(root, out);
        return out;
    }
};