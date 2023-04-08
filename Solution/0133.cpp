/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* DFS(Node* node, unordered_map<Node*, Node*>& visited){
        Node* copyNode = new Node(node->val);

        visited.insert({node, copyNode});

        for(int i=0 ; i<node->neighbors.size(); ++i){
            if(visited.find(node->neighbors[i]) != visited.end())
                copyNode->neighbors.push_back(visited[node->neighbors[i]]);
            else{
                Node* newNode = DFS(node->neighbors[i], visited);
                copyNode->neighbors.push_back(newNode);
            }
        }
        return copyNode;
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> visited;

        return DFS(node, visited);
    }
};