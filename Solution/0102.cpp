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
        queue<TreeNode*> tmp;
        vector<vector<int>> output;        

        if(root != nullptr) {
            tmp.push(root);
            while(tmp.size() != 0) {
                vector<int> levelOutput;
                int levelSize = tmp.size();
                for(int i=0; i<levelSize; ++i) {
                    TreeNode* tmpNode = tmp.front();
                    tmp.pop();
                    levelOutput.push_back(tmpNode -> val);
                    if(tmpNode -> left != nullptr)
                        tmp.push(tmpNode -> left);
                    if(tmpNode -> right != nullptr)
                        tmp.push(tmpNode -> right);
                }
                output.push_back(levelOutput);
            }
        }
        
        return output;
    }
};