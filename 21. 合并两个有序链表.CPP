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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode* cur = dummy;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        while (cur1 && cur2) {
            if (cur1 -> val <= cur2 -> val) {
                cur -> next = cur1;
                cur1 = cur1 -> next;
            }
            else {
                cur -> next = cur2;
                cur2 = cur2 -> next;
            }
            cur = cur -> next;
        }
        cur -> next = cur1 == nullptr ? cur2 : cur1;
        return dummy -> next;
    }
};
