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
    bool ValidBST(TreeNode* root, long left_min, long right_max){
        if(root == nullptr) return true;
        if(root -> val >= left_min || root -> val <= right_max) return false;

        return ValidBST(root -> left, root -> val, right_max) && 
               ValidBST(root -> right, left_min, root -> val);        

    }
    bool isValidBST(TreeNode* root) {
        return ValidBST(root, LONG_MAX, LONG_MIN);
    }
};