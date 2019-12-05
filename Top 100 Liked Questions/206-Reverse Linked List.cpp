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
//recrusive
//key :head->next->next=head;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *temp=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
};