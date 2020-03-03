//*pre not pre
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *cur=head,*pre=nullptr;
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