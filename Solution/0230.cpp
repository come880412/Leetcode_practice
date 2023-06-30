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
    void inorder(TreeNode* root) {
        if (root != nullptr) {
            inorder(root -> left);
            inorderTmp.push_back(root -> val);
            inorder(root -> right);
        }
            
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return inorderTmp[k-1];
    }

private:
    vector<int> inorderTmp;
};