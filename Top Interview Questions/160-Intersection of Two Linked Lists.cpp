//必须用p1 p2记录两个 head 不改变两个head的地址 不然死循环
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1=headA,*p2=headB;
        while(p1!=p2)
        {
            p1=p1?p1->next:headB;
            p2=p2?p2->next:headA;
        }
        return p1;
    }
};