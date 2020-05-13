class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        queue<TreeNode*>q;
        if(!root)
            return ret;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            vector<int>temp;
            for(int i=0;i<len;i++)
            {
                TreeNode *tmp=q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                temp.push_back(tmp->val);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};