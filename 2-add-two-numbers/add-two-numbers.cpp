#include <iostream>

// Definition for singly-linked list.


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Stack allocation prevents memory leak for dummy node
        ListNode* curr = &dummy;
        int carry = 0;
        
        // Loop while there are nodes to process or a carry left over
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate current digit and carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            // Create a new node with the single-digit remainder
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            
            // Advance original list pointers if available
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        return dummy.next;
    }
};
