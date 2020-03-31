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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(!l1 && !l2) return l1;
        ListNode* ret = l1;
        if(l2->val <= l1->val) ret = l2;
        ListNode* temp1 = NULL, *temp2 = NULL;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                while(l1->next && l1->next->val < l2->val) l1 = l1->next;
                if(!l1->next) {
                    l1->next = l2;
                    return ret;
                }
                ListNode* temp = l1;
                l1 = l1->next;
                temp->next = l2;
            } else {
                while(l2->next && l2->next->val <= l1->val) l2 = l2->next;
                if(!l2->next) {
                    l2->next = l1;
                    return ret;
                }
                ListNode* temp = l2;
                l2 = l2->next;
                temp->next = l1;
            }
        }
        return ret;
    }
};
​
​
/*
    Time Complexity  => O(n + m)
    Space Complexity => O(1)
*/
