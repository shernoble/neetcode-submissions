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
private:
    Node* helper(Node* node1,unordered_map<Node*,Node*> &prevNodes)
    {

        if(node1 == NULL) return NULL;
        if(prevNodes.count(node1)) return prevNodes[node1];

        //else create new node
        Node* newNode = new Node(node1->val);

        //map it
        prevNodes[node1] = newNode;
        //add all the neighbors
        for(auto node:node1->neighbors)
        {
            newNode->neighbors.push_back(helper(node,prevNodes));
        }
        return newNode;

    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> vis;
        return helper(node,vis);
    }
};
