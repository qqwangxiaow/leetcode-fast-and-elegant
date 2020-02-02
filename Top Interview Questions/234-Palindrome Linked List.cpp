//reverse the right half list
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)
            return true;
        ListNode *slow=head,*fast=head;
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;   
        }
        slow=slow->next;
        ListNode *pre=nullptr;
        while(slow)
        {
            ListNode *temp=slow->next;
            slow->next=pre;
            pre=slow;
            slow=temp;   
        }
        while(pre&&head)
        {
            if(pre->val!=head->val)
                return false;
            pre=pre->next;
            head=head->next;
        }
        return true;

    }
};