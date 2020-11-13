/**
while(fast&&fast->next)
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *head1=head,*head2=head->next;
        ListNode *cur=head,*fast=head->next;
        while(fast&&fast->next)
        {
            cur->next=fast->next;
            fast->next=cur->next->next;
            //cur->next->next=fast;
            cur=cur->next;
            fast=fast->next;
        }
        cur->next=head2;
        return head1;
    }
};