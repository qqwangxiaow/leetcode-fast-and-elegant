/**
carry
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,sum=0;
        ListNode dummy(0);
        ListNode* p=&dummy;
        while(l1||l2||carry)
        {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry=sum/10;
            p->next=new ListNode(sum%10);
            p=p->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return dummy.next;
    }
};