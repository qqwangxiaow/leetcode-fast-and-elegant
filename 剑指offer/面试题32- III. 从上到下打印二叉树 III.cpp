//it's better to use deque. push_front() and push_back()
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        if(!root)
            return ret;
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>tmp{};
            for(int i=0;i<n;i++)
            {
                TreeNode *cur=q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(flag%2)
                reverse(tmp);
            ret.push_back(tmp);
        }
        return ret;
    }
};