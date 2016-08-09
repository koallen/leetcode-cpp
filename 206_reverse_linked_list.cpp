/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // termination step
        if (!head || !head->next)
            return head;
        
        // recursive step
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
};
