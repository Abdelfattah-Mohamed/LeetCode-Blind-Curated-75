/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode *x = head, *y = head;
        while(n--) y = y->next;
        if(!y) return head->next;
        while(y->next) x = x->next, y = y->next;
        x->next = x->next->next;
        return head;
    }
};
​
/*
    Time Complexity  => O(size of list) (one pass).
    Space Complexity => O(1)
*/
