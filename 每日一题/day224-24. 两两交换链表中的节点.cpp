/**
 recursive
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *temp=swapPairs(head->next->next);
        ListNode *cur=head->next;
        cur->next=head;
        head->next=temp;
        return cur;
        
    }
};