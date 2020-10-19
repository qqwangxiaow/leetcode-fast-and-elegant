/**
 注意删除首结点 判断fast是不是空
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *slow=head,*fast=head;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;    
        }
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        if(!fast)
        {
            dummy->next=head->next;
            delete head;
        }
        else
        {
            slow->next=slow->next->next;
        }
        head=dummy->next;
        delete dummy;
        return head;

    }
};