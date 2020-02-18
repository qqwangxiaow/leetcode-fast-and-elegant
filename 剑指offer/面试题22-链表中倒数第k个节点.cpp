//slow and fast pointer
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *slow=head,*fast=head;
        for(int i=0;i<k;i++)
        {
            if(fast)
                fast=fast->next;
        }
        while(slow&&fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};