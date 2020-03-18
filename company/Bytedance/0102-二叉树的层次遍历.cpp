//bfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        if(!root)
            return ret;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            vector<int>temp(len);
            for(int i=0;i<len;i++)
            {
                temp[i]=q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
//dfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        int level=0;
        dfs(ret,root,level);
        return ret;
    }
    void dfs(vector<vector<int>>&ret,TreeNode *root,int level)
    {
        if(!root)
            return;
        if(ret.size()==level)
            ret.resize(level+1);
        ret[level].push_back(root->val);
        dfs(ret,root->left,level+1);
        dfs(ret,root->right,level+1);
    }
};