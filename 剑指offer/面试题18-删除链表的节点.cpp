class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *cur=head;
        if(!cur)
            return nullptr;
        if(cur->val==val)
            return cur->next;
        while(cur&&cur->next)
        {
            if(cur->next->val==val)
            {
                cur->next=cur->next->next;
            }
            cur=cur->next;
        }
        return head;
    
    }
};