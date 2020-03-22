//while(fast->next&&fast->next->next)
//一定要二分
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *slow=head,*fast=head;
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=nullptr;
        return merge(sortList(fast),sortList(head));

    }
    ListNode *merge(ListNode *l1,ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *head=&dummy;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                head->next=l1;
                l1=l1->next;
            }
            else
            {
                head->next=l2;
                l2=l2->next;
            }
            head=head->next;
        }
        head->next=l1?l1:l2;
        return dummy.next;
    }
};