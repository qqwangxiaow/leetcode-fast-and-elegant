class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
            return {};
        return helper(1,n);
    }
    vector<TreeNode*>helper(int start,int end)
    {
        if(start>end)
        {
            return {nullptr};
        }
        vector<TreeNode*>ret;
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*>left=helper(start,i-1);
            vector<TreeNode*>right=helper(i+1,end);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode *root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ret.emplace_back(root);
                }
            }
        }
        return ret;
    }
};