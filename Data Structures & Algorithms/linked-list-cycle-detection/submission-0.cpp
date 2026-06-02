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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> mp;
        ListNode* cur = head;
        while(cur != nullptr){
            if(!mp.count(cur)){
                mp[cur]++;
            }else{
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
};
