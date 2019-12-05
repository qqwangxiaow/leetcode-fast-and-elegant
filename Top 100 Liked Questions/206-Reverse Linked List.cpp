//target pre
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *pre=NULL;
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