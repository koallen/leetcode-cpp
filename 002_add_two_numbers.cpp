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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* currPosition = result;
        
        int carry = 0;
        while (1) {
            int currVal = 0;
            currVal += (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
            
            // set carry for next iteration
            carry = currVal > 9 ? 1 : 0;
            currVal = currVal > 9 ? currVal - 10 : currVal;
            currPosition->val = currVal;
            
            // advance input list
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
            
            if (l1 == nullptr && l2 == nullptr && carry == 0)
                break;
            
            // setup next node in result list
            currPosition->next = new ListNode();
            currPosition = currPosition->next;
        }
        
        return result;
    }
};
