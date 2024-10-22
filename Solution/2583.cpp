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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        inorderTraversal(root, 0);
        sort(record_.begin(), record_.end(), greater<long long>());

        if (record_.size() < k) return -1;
        else return record_[k-1];
    }

    void inorderTraversal(TreeNode* root, int currLevel) {
        if (!root) return;
        if (record_.size() <= currLevel) record_.emplace_back(root->val);
        else record_[currLevel] += root->val;

        inorderTraversal(root->left, currLevel+1);
        inorderTraversal(root->right, currLevel+1);
    }

private:
    vector<long long> record_;
};