//temp(len)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        if(!root)
            return ret;
        queue<TreeNode*>q;
        q.push(root);
        bool fromleft=true;
        while(!q.empty())
        {
            int len=q.size();
            vector<int>tmp(len);
            for(int i=0;i<len;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(fromleft)
                    tmp[i]=temp->val;
                else
                    tmp[len-i-1]=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            fromleft=!fromleft;
            ret.push_back(tmp);
        }
        return ret;

        
    }
};