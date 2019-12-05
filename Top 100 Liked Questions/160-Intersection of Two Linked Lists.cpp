//l1!=l2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1=headA,*l2=headB;
        while(l1!=l2)
        {
            l1=l1?l1->next:headA;
            l2=l2?l2->next:headB;
        }
        return l1;      
    }
};