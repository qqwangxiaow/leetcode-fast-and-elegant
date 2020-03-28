/**
while(n--)
        {
            last=pstart->next;
            pstart->next=last->next;
            last->next=pre->next;
            pre->next=last;
        }
这一段很牛逼
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)
            return head;
        n-=m;
        ListNode dummy(0);
        ListNode *pre,*cur,*last,*pstart;
        dummy.next=head;
        pre=&dummy;
        while(--m)
        {
            pre=pre->next;
        }
        pstart=pre->next;
        while(n--)
        {
            last=pstart->next;
            pstart->next=last->next;
            last->next=pre->next;
            pre->next=last;
        }
        return dummy.next;
        
    }
};