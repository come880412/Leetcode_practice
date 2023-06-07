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
    int DFS(TreeNode* root){
        
        if(root == nullptr)
            return 0;
        
        int left_depth = 1, right_depth = 1;
        
        left_depth += DFS(root->left);
        right_depth += DFS(root->right);
                
        return max(left_depth, right_depth);
    }
    
    int maxDepth(TreeNode* root) {
        return DFS(root);

    }
};