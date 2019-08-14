// 利用carry表示进位
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode dummy(0);
        int temp=0,carry=0;
        ListNode *head=&dummy;
        while(l1||l2||carry)
        {
            temp=0;
            if(l1)
            {
                temp+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                temp+=l2->val;
                l2=l2->next;
            }
            temp+=carry;
            ListNode *tmp=new ListNode(temp%10);
            head->next=tmp;
            head=tmp;
            carry=temp/10;
        }
        return dummy.next;
        
    }
};