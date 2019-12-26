//while(l1||l2||carry)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,sum=0;
        ListNode dummy(0);
        ListNode *head=&dummy;
        while(l1&&l2)
        {
            sum=l1->val+l2->val+carry;
            head->next=new ListNode(sum%10);
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
            head=head->next;
        }
        while(l1)
        {
            sum=l1->val+carry;
            head->next=new ListNode(sum%10);
            carry=sum/10;
            head=head->next;
            l1=l1->next;
        }
        while(l2)
        {
            sum=l2->val+carry;
            head->next=new ListNode(sum%10);
            carry=sum/10;
            head=head->next;
            l2=l2->next;
        }
        while(carry)
        {
            head->next=new ListNode(carry);
            carry=0;
            head=head->next;
        }
        head->next=NULL;
        return dummy.next;
        
    }
};