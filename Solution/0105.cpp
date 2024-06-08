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
    TreeNode* Traverse(vector<int> &preorder, vector<int> &inorder) {
        int preorderVal = preorder[0];

        vector<int>::iterator itr = find(inorder.begin(), inorder.end(), preorderVal);
        if (itr == inorder.end()) return nullptr; // not find the value in the inorder vector.
        else {
            vector<int> leftTreeInorder(inorder.begin(), itr);
            vector<int> rightTreeInorder(itr + 1, inorder.end());

            TreeNode *root = new TreeNode(preorderVal);
            preorder.erase(preorder.begin());
            root -> left = Traverse(preorder, leftTreeInorder);
            root -> right = Traverse(preorder, rightTreeInorder);
            return root;
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root;
        root = Traverse(preorder, inorder);
        return root;
    }
};