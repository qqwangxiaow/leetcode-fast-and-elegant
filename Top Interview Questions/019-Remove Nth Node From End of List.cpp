//pay attention to delete head 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next)
            return NULL;
        ListNode *slow=head,*fast=head;
        while(n--)
        {
            fast=fast->next;
        }
        if(!fast)
            return head->next;
        while(fast&&fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};