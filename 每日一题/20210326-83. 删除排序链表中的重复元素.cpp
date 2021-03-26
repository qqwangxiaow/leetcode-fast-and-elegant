/**
two pointers
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *l1 = head, *l2 = head->next;
        while(l2){
            if(l1->val == l2->val){
                l1->next = l2->next;
                l2 = l2->next;
            }
            else{
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        return head;
    }
};