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

    Node* dfs(Node* node, unordered_map<Node*,Node*> &oldToNew)
    {
        // if node is null
        if(node == NULL) return NULL;

        // if previously configured
        if(oldToNew.count(node)) return oldToNew[node];

        // go through all the neighbors of the curr node and yk
        Node* copy = new Node(node->val);
        // map it
        oldToNew[node] = copy;

        for(auto it: node->neighbors)
        {
            // copy gets created anyways so just make the call for it
            // add the neighbors to the copy version
            copy->neighbors.push_back(dfs(it, oldToNew));
        }
        return copy;
        
    }

    Node* cloneGraph(Node* node) {
        // unordered_map<int,bool> mpp;
        unordered_map<Node*,Node*> mpp;
        return dfs(node, mpp);
    }
};
