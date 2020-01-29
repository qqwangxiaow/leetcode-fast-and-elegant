//用map保存副本 一个结点对应一个copy结点
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *,Node *>mymap;
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
            Node *tmp=mymap[cur];
            tmp->next=mymap[cur->next];
            tmp->random=mymap[cur->random];
            cur=cur->next;
        }
        return mymap[head];
    }
};