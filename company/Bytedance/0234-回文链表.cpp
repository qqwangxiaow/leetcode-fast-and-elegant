//reverse
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)
            return true;
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *head2=slow->next;
        slow->next=nullptr;
        ListNode *pre=nullptr;
        while(head2)
        {
            ListNode *temp=head2->next;
            head2->next=pre;
            pre=head2;
            head2=temp;
        }
        while(head&&pre)
        {
            if(head->val!=pre->val)
                return false;
            head=head->next;
            pre=pre->next;
        }
        return true;
        

    }
};