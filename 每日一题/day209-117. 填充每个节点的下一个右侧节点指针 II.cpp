/*
if(i!=n-1)
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(!root)
            return nullptr;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node *cur=q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                if(i!=n-1)
                    cur->next=q.front();
            }

        }
        return root;
        
    }
};