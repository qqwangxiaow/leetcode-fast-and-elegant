/**
 recursive
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur=head;
        for(int i=0;i<k-1;i++)
        {
            if(!cur)
                return head;
            else    
                cur=cur->next;
        }
        if(!cur)
            return head;
        ListNode *next=reverseKGroup(cur->next,k);
        cur->next=nullptr;
        ListNode *ret=reverselist(head);
        head->next=next;
        return ret;
    }
    ListNode *reverselist(ListNode *head)
    {
        if(!head||!head->next)
            return head;
        ListNode *cur=head;
        ListNode *pre=nullptr;
        while(cur)
        {
            ListNode *temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre; 
    }
};