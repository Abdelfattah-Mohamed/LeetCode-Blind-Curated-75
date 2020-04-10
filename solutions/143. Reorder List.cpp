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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next) slow = slow->next, fast = fast->next->next;
        if(fast) slow = slow->next;
        ListNode* n = slow->next;
        slow->next = NULL;
        while(n) {
            ListNode* temp = n->next;
            n->next = slow;
            slow = n;
            n = temp;
        }
        fast = slow;
        slow = head;
        while(fast->next) {
            ListNode* temp = slow->next;
            ListNode* temp2 = fast->next;
            slow->next = fast;
            fast->next = temp;
            slow = temp, fast = temp2;
        }
    }
};
​
/*
​
    Time Complexity  => O(n)
    Space Complexity => O(1)
​
*/
