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
    map<int, int> inorder_m;
    TreeNode* build(vector<int>& inorder, vector<int>& preorder, 
                    int s_in, int e_in, int s_pre, int e_pre){
        if(s_in > e_in || s_pre > e_pre)
            return NULL;
        else{
            TreeNode* root = new TreeNode(preorder[s_pre]);
            int root_idx = inorder_m[preorder[s_pre]];
            int left_num = root_idx - s_in;

            root -> left = build(inorder, preorder, s_in, root_idx - 1, s_pre + 1, s_pre + left_num);
            root -> right = build(inorder, preorder, root_idx + 1, e_in, s_pre + left_num + 1, e_pre);
            
            return root;
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i < inorder.size(); ++i)
            inorder_m[inorder[i]] = i;
        
        return build(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }
};