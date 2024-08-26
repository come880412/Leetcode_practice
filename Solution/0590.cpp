/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void PostorderTraverse(Node* root) {
        if ((root -> children).size() != 0) {
            for (int i = 0; i < (root -> children).size(); ++i) {
                postorder((root -> children)[i]);
            }
            result.push_back(root -> val);
        } else result.push_back(root -> val);
    }
    vector<int> postorder(Node* root) {
        if (root != nullptr)
            PostorderTraverse(root);
        return result;
    }

private:
    vector<int> result;
};