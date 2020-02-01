//reverse O(1) space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* cur=head,*pre=nullptr;
        while(cur)
        {
            ListNode *temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }
};
//recursively
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *tmp=head->next;
        ListNode *pre=reverseList(head->next);
        tmp->next=head;
        head->next=nullptr;
        return pre;
    }
};