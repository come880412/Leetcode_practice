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
    bool findSubtree(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr) return true;
        else if(root == nullptr && subRoot != nullptr) return false; 
        else if(root != nullptr && subRoot == nullptr) return false; 
        else{
            if(root -> val != subRoot -> val) return false;
        }
        return findSubtree(root -> left, subRoot ->left) && findSubtree(root -> right, subRoot -> right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(findSubtree(root, subRoot)) return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};