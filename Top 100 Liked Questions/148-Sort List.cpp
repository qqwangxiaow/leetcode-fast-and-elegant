//merge sort bottom-up
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *cur=head;
        int len=0;
        while(cur)
        {
            cur=cur->next;
            len++;
        }
        ListNode dummy(0);
        dummy.next=head;
        ListNode *left,*right,*tail;
        for(int step=1;step<len;step<<=1)
        {
            cur=dummy.next;
            tail=&dummy;
            while(cur)
            {
                left=cur;
                right=split(left,step);
                cur=split(right,step);
                tail=merge(left,right,tail);//append the merged sorted linked list to hhe node head 
            } 
        }
        return dummy.next;
    }
private:
    ListNode *split(ListNode* head,int n)
    {
        for(int i=1;head&&i<n;i++)
        {
            head=head->next;
        }
        if(!head)
            return NULL;
        ListNode *second=head->next;
        head->next=NULL;
        return second;
    }
    ListNode *merge(ListNode *l1,ListNode *l2,ListNode *head)
    {
        ListNode *cur=head;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                cur->next=l1;
                l1=l1->next;
                
            }
            else
            {
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        cur->next=l1?l1:l2;
        while(cur->next)
            cur=cur->next;
        return cur;
        
    }
};