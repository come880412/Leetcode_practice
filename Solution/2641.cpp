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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        q.emplace(root->val, root);
        while (!q.empty()) {
            int n = q.size();
            int levelSum = 0;
            for (int i = 0; i < n; ++i) {
                auto [localSum, currNode] = q.front();
                q.pop();
                levelSum += currNode->val;
                q.emplace(localSum, currNode);
            }

            for (int i = 0; i < n; ++i) {
                auto [localSum, currNode] = q.front();
                q.pop();

                int childSum = 0;
                if (currNode->left) childSum += currNode->left->val;
                if (currNode->right) childSum += currNode->right->val;

                if (currNode->left) q.emplace(childSum, currNode->left);
                if (currNode->right) q.emplace(childSum, currNode->right);

                currNode->val = levelSum - localSum;
            }
        }
        return root;
    }
};