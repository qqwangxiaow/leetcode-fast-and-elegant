//dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
//bfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ret=0;
        while(!q.empty())
        {
            ++ret;
            for(int i=0,n=q.size();i<n;i++)
            {
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
     
        }
        return ret;
    }
};