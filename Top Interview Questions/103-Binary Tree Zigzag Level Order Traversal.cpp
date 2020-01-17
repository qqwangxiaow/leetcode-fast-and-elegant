//one vector and index=i or len-i-1 base on lefttoright 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        queue<TreeNode*>q;
        if(!root)
            return ret;
        q.push(root);
        bool lefttoright=true;
        while(!q.empty())
        {
            int len=q.size();
            vector<int>tmp(len);
            for(int i=0;i<len;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                int index=lefttoright?i:len-i-1;
                tmp[index]=(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            lefttoright=!lefttoright;
            ret.push_back(tmp);
            
        }
        return ret;
        
    }
};