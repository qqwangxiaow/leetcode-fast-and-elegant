//stack and carry
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*>s1;
        stack<ListNode*>s2;
        while(l1)
        {
            s1.push(l1);
            l1=l1->next;
        }
        while(l2)
        {
            s2.push(l2);
            l2=l2->next;
        }
        ListNode *dummy=nullptr;
        int carry=0;
        while(!s1.empty()||!s2.empty()||carry)
        {
            int temp1=0,temp2=0;
            if(!s1.empty())
            {
                temp1=s1.top()->val;
                s1.pop();
            }
            if(!s2.empty())
            {
                temp2=s2.top()->val;
                s2.pop();
            }
            int sum=carry+temp1+temp2;
            ListNode *newnode=new ListNode(sum%10);
            newnode->next=dummy;
            dummy=newnode;
            carry=sum/10;
        }
        return dummy;

    }
};