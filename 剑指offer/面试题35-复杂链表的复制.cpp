//1.cur->random?cur->random->next:nullptr
//2.cur2->next=cur?cur->next:nullptr;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node *cur=head;
        while(cur)
        {
            Node *copy=new Node(cur->val);
            copy->next=cur->next;
            cur->next=copy;
            cur=copy->next;
        }
        cur=head;
        while(cur)
        {
            cur->next->random=cur->random?cur->random->next:nullptr;
            cur=cur->next->next;
        }
        cur=head;
        Node *head2=cur->next,*cur2=cur->next;
        while(cur)
        {
            cur->next=cur2->next;
            cur=cur->next;
            cur2->next=cur?cur->next:nullptr;
            cur2=cur2->next;
        }
        return head2;

    }
};

//or using map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mymap;
        if(!head)
            return nullptr;
        Node *cur=head;
        while(cur)
        {
            Node *temp=new Node(cur->val);
            mymap[cur]=temp;
            cur=cur->next;
        }
        cur=head;
        while(cur)
        {
            mymap[cur]->next=mymap[cur->next];
            mymap[cur]->random=mymap[cur->random];
            cur=cur->next;
        }
        return mymap[head];
        
    }
};