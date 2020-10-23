/**
two pointers and reverse and tranverse
 */
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
        ListNode *newhead=slow->next;
        slow->next=nullptr;
        newhead=reverselist(newhead);
        while(head&&newhead)
        {
            if(head->val!=newhead->val)
                return false;
            head=head->next;
            newhead=newhead->next;
        }
        return true;
        
    }
    ListNode *reverselist(ListNode *head)
    {
        if(!head||!head->next)
            return head;
        ListNode *pre=nullptr;
        while(head)
        {
            ListNode *temp=head->next;
            head->next=pre;
            pre=head;
            head=temp;
        }
        return pre;

    }
};