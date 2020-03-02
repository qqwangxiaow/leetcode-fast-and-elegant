//using stack
//using queue
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>>mypq;
        stack<TreeNode*>s;
        queue<int>q2;
        while(root||!s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            if(!s.empty())
            {
                root=s.top();
                s.pop();
                q2.push(root->val);
                while(q2.size()>k)
                {
                    q2.pop();
                }
                root=root->right;
            }
            
        }
        return q2.front();
        
    }
};