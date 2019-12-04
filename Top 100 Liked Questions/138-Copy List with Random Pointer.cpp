//1.each node make copy at next
//2.set copy node random pointer
//3.seperate
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *cur=head;
        while(cur)
        {
            cur->next=new Node(cur->val,cur->next,NULL);
            cur=cur->next->next;
        }
        cur=head;
        while(cur)
        {
            if(cur->random)
            {
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }
        cur=head;
        Node *newhead=head->next,*newcur;
        while(cur)
        {
            newcur=cur->next;
            cur->next=newcur->next;
            if(newcur->next)
            {
                newcur->next=newcur->next->next;
            }
            cur=cur->next;
        }
        return newhead;
        
    }
};