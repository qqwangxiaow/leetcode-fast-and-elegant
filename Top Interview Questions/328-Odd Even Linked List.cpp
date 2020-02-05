/*
while(cur2&&cur2->next) key!
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next)
            return head;
        ListNode *head1=head,*head2=head->next;
        ListNode *cur=head1,*cur2=head2;
        while(cur2&&cur2->next)
        {
            cur->next=cur->next->next;
            cur2->next=cur2->next->next;
            cur=cur->next;
            cur2=cur2->next;
        }
        cur->next=head2;
        return head1;
    }
};