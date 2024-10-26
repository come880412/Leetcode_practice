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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root, 0);
        m_[root->val] = 0;
        updateSiblingHeight(root, 0);

        vector<int> ans;
        for (int query : queries) ans.emplace_back(m_[query]);
        return ans;
    }

    int findHeight(TreeNode* root, int currHeight) {
        if (!root) return currHeight-1;

        int left = findHeight(root->left, currHeight + 1);
        int right = findHeight(root->right, currHeight + 1);
        // When removing the node, the height depends on its sibling node.
        if (root->left) m_[root->left->val] = right;
        if (root->right) m_[root->right->val] = left;
        return max(left, right);
    }

    // Check max height is correct for global comparible.
    void updateSiblingHeight(TreeNode* root, int maxH) {
        if (!root) return;

        if (m_[root->val] > maxH) 
            maxH = m_[root->val];
        if (root->left && maxH > m_[root->left->val])
            m_[root->left->val] = maxH;
        if (root->right && maxH > m_[root->right->val])
            m_[root->right->val] = maxH;

        updateSiblingHeight(root->left, maxH);
        updateSiblingHeight(root->right, maxH);
    }


private:
    unordered_map<int, int> m_;
};