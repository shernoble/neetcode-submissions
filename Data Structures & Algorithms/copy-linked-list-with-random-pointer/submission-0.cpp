/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* head2 = new Node(head->val);
        Node* curr = head;

        unordered_map<Node*, Node*> mpp;
        while(curr)
        {
            mpp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        //got the mapping, now map the pointers to the nodes
        curr = head;
        while(curr)
        {
            mpp[curr]->next = mpp[curr->next];
            mpp[curr]->random = mpp[curr->random];
            curr = curr->next;
        }
        return mpp[head];
    }
};
