/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    int i = 0;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        traverse(dummy, n);
        return dummy->next;
    }
    void traverse(ListNode* head, int n){
        if(head == nullptr){
            return;
        }
        
        traverse(head->next, n);
        if(i == n){
            ListNode* node = head->next->next;
            head->next->next = nullptr;
            head->next = node;
        }
        i++;
        return;
    }
};
