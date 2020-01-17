//levelorder store l=q.size()
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
            vector<int>tmp{};
            for(int i=0;i<len;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                tmp.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ret.push_back(tmp);
            
        }
        return ret;
        
    }
};