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
    ListNode* removeDuplicateNodes(ListNode* head) {
        set<int>myset;
        if(!head||!head->next)
            return head;
        ListNode *cur=head->next,*pre=head;
        myset.insert(head->val);
        while(cur)
        {
            if(myset.count(cur->val))
            {
                pre->next=cur->next;
                cur=pre->next;
            }
            else
            {
                myset.insert(cur->val);
                cur=cur->next;
                pre=pre->next;
            }     
        }
        return head;

    }
};