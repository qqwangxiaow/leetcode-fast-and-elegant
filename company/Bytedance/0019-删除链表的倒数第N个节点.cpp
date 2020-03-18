//pay attention to head
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head,*slow=head;
        ListNode dummy(0);
        dummy.next=head;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        if(!fast)
        {
            dummy.next=head->next;
        }
        else
            slow->next=slow->next->next;
        return dummy.next;
    }
};