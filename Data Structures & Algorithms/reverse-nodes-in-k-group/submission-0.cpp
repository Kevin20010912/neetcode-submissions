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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* groupPrev = dummy;

        while(true){
            ListNode* kth = groupPrev;
            for(int i = 0; i < k; i++){
                kth = kth->next;
                if(kth == nullptr){
                    return dummy->next;
                }
                
            }

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* cur = groupPrev->next;

            while(cur != groupNext){
                ListNode* nextNode = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nextNode;
            }

            ListNode* oldGroupHead = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = oldGroupHead;

        }
        return dummy->next;
            
            
            
            

        
    }
};
