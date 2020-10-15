/*
可以不用queue，
1.将左右两个儿子节点连接起来
2.利用父节点的next,将cur->right->next=cur->next->left
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<int>myvec;
        if(!root)  
            return root;
        queue<Node*>q;
        q.push(root);
        Node *pre=nullptr;
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                Node *temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                if(i!=len-1)
                {
                    temp->next=q.front();
                }
            }
        }
        return root;
        
    }
};