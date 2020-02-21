//using n to represent q.size()
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
            vector<int>temp{};
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *tmp=q.front();
                q.pop();
                temp.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};