class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int>ret;
        queue<TreeNode*>q;
        if(!root)
            return ret;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *tmp=q.front();
            q.pop();
            ret.push_back(tmp->val);
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
        return ret;

    }
};