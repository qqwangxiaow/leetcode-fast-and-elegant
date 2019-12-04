//slow and fast pointer
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow,*fast;
        if(!head||!head->next)
        {
            return false;
        }
        slow=head;
        fast=head;
        while(fast->next&&fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                return true;
        }
        return false;  
    }
};