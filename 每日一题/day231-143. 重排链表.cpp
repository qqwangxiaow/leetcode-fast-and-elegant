/**
1.find mid
2.reverse
3.merge
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow=head,*fast=head;
        if(!head||!head->next)
            return;
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *newhead=slow->next;
        slow->next=nullptr;
        ListNode *pre=nullptr;
        while(newhead)
        {
            ListNode *temp=newhead->next;
            newhead->next=pre;
            pre=newhead;
            newhead=temp;
        }
        newhead=pre;
        while(head&&newhead)
        {
            ListNode *temp=head->next;
            ListNode *tempnew=newhead->next;
            head->next=newhead;
            newhead->next=temp;
            head=temp;
            newhead=tempnew;
        }

    }
};