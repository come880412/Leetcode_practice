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
    int DFS(TreeNode* p, TreeNode* q){
        int isSame = 1;
        
        if(p != nullptr && q != nullptr && p->val == q->val){
            isSame *= DFS(p->left, q->left);
            isSame *= DFS(p->right, q->right);
        }
        else if(p == nullptr && q == nullptr){
            return 1;
        }
            
        else{
            return 0;
        }
            
        return isSame;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(DFS(p, q))
            return true;
        else
            return false;
    }
};