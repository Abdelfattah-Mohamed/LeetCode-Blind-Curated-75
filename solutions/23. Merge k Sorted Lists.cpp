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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        while(n > 1) {
            if((int) n % 2) lists.push_back(NULL), n++;
            vector<ListNode*> temp;
            for(int i = 0; i < n; i++) temp.push_back(merge(lists[i], lists[++i]));
            lists = temp;
            n = lists.size();
        }
        return (n ? lists[0] : NULL);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l2) return l1;
        if(!l1) return l2;
        if(!l1 && !l2) return NULL;
        ListNode* ret = l1;
        if(l2->val <= l1->val) ret = l2;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                while(l1->next && l1->next->val < l2->val) l1 = l1->next;
                ListNode* temp = l1;
                l1 = l1->next;
                temp->next = l2;
            } else {
                while(l2->next && l2->next->val <= l1->val) l2 = l2->next;
                ListNode* temp = l2;
                l2 = l2->next;
                temp->next = l1;
            }
        }
        return ret;
    }
};
​
/*
    Time Complexity  => O(m lg(n))
    Space Complexity => O(n)
    
*/
