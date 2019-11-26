//leverorder 用count==q.size()来代表哪一层
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
            int count=q.size();
            vector<int>temp={};
            while(count--)
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
//recrusive if ret.size()==depth then new a vector
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root,0);
        return ret;
    }
    void helper(TreeNode *root,int depth)
    {
        if(!root)
            return;
        if(ret.size()==depth)
        {
            ret.push_back(vector<int>());
        }
        ret[depth].push_back(root->val);
        helper(root->left,depth+1);
        helper(root->right,depth+1);
    }
    
private:
    vector<vector<int>>ret;
};
