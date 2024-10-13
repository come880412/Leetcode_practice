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
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        postOrder(root);

        sort(perfectBT_.begin(), perfectBT_.end(), greater<int>());
        cout << perfectBT_.size();
        if (perfectBT_.size() < k) return -1;
        else return perfectBT_[k-1];
    }

    pair<int, int> postOrder(TreeNode* root) {
        if (!root) return {0, 0};

        auto [leftHeight, leftLevel] = postOrder(root->left);
        auto [rightHeight, rightLevel] = postOrder(root->right);
        
        if (rightLevel != -1 && leftLevel != -1 && leftHeight == rightHeight) {
            int size = leftLevel + rightLevel + 1;
            perfectBT_.emplace_back(size);
            return {leftHeight + 1, size};
        }
        return {max(leftHeight, rightHeight) + 1, -1};
    }

private:
    vector<int> perfectBT_;
};