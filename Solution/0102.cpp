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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int level = q.size();

            vector<int> tmp;
            for (int i = 0; i < level; ++i) {
                TreeNode *tmpNode = q.front();
                if (tmpNode -> left) q.push(tmpNode -> left);
                if (tmpNode -> right) q.push(tmpNode -> right);
                tmp.push_back(tmpNode -> val);
                q.pop();
            }
            result.push_back(tmp);
        }
        return result;
    }
};