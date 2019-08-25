/*stack，再逆转*/
class Solution {
public:
    vector<int> postorder(Node* root) {
     if(!root)
         return {};
        vector<int>res;
        stack<Node*>s;
        s.push(root);
        while(!s.empty())
        {
            Node *temp=s.top();
            s.pop();
            for(int i=0;i<temp->children.size();i++)
                s.push(temp->children[i]);
            res.push_back(temp->val);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};