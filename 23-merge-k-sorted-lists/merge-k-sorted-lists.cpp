class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        while (lists.size() > 1) {
            std::vector<ListNode*> merged;
            for (size_t i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                merged.push_back(mergeTwo(l1, l2));
            }
            lists = merged;
        }
        
        return lists[0];
    }
    
private:
    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};