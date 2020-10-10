/**

 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head,*cur=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
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
        return nullptr;;
        
    }
};