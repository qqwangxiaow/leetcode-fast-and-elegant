//two points
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head,*low=head;
        while(n--)
        {
            fast=fast->next;
        }
        while(fast&&fast->next)
        {
            low=low->next;
            fast=fast->next;
        }
        if(!fast)
        {
            return low->next;
        }
        else
        {
            low->next=low->next->next;
        }
        return head;
        
    }
};