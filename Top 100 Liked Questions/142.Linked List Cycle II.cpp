//快慢指针相遇后到entry的距离=头结点到entry的距离
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)
        {
            return NULL;
        }
        ListNode *slow=head,*fast=head,*cur=head;
        while(fast->next&&fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                while(cur!=fast)
                {
                    cur=cur->next;
                    fast=fast->next;
                }
                return cur;  
            }
        }
        return NULL;
        
    }
};