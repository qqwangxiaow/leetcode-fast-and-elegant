//bottom-up 两两merge 最后merge成一个list
//split 返回list n个node以后的部分
//merge 中tail很关键 tail是当前合并的尾结点 是后面合并的头结点
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* cur=head;
        int len=0;
        while(cur)
        {
            len++;
            cur=cur->next;
        }
        ListNode dummy(0);
        dummy.next=head;
        ListNode* left,*right,*tail;
        for(int step=1;step<len;step<<=1)
        {
            cur=dummy.next;
            tail=&dummy;
            while(cur)
            {
                left=cur;
                right=split(cur,step);
                cur=split(right,step);
                tail=merge(left,right,tail);
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
//一定要保证fast不为nullptr 所以要while(fast->next&&fast->next->next)
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
        return merge(sortList(head),sortList(fast));
        
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode dummy(0);
        ListNode *cur=&dummy;
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
        return dummy.next;
    }
};

