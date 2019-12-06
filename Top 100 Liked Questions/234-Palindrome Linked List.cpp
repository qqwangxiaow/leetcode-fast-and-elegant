//slow and fast pointer and reverse list
//it's easier to reverse second half
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)
            return true;
        ListNode *fast=head,*slow=head;
        while(fast->next&&fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *newhead=slow->next,*pre=NULL;
        slow->next=NULL;
        while(newhead)
        {
            ListNode *temp=newhead->next;
            newhead->next=pre;
            pre=newhead;
            newhead=temp;
        }
        while(pre)
        {
            if(pre->val!=head->val)
                return false;
            pre=pre->next;
            head=head->next;
        }
        return true;
        
    }
};