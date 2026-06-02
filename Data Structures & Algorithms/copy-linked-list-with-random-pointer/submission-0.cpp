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
        // old_node, new_node;
        unordered_map<Node*, Node*> mp;

        Node* cur1 = head;
        Node* dummy = new Node(-1);
        Node* cur2 = dummy;

        while(cur1 != nullptr){
            Node* new_node = new Node(cur1->val);
            cur2->next = new_node;
            mp[cur1] = new_node;
            cur2 = cur2->next;
            cur1 = cur1->next;
        }
        cur1 = head;
        cur2 = dummy->next;
        while(cur1 != nullptr){
            cur2->random = mp[cur1->random];
            cur2 = cur2->next;
            cur1 = cur1->next;
        }
        return dummy->next;
    }
};





