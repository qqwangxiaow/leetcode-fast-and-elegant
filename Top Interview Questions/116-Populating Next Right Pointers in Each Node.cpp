//这是一棵完美二叉树 
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(!root)
            return nullptr;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            Node *pre=nullptr;
            for(int i=0;i<len;i++)
            {
                Node *temp=q.front();
                q.pop();
                if(i>0)
                {
                    pre->next=temp;
                }
                pre=temp;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right); 
            }
        }
        return root; 
    }
};
//从最左边开始遍历
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        Node *pre=root;
        Node *cur=nullptr;
        while(pre->left)
        {
            cur=pre;
            while(cur)
            {
                cur->left->next=cur->right;
                if(cur->next)
                {
                    cur->right->next=cur->next->left;
                } 
                cur=cur->next;
            }
            pre=pre->left;
        }
        return root; 
    }
};
