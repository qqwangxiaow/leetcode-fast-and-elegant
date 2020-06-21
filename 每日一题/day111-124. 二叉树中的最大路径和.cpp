
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ret=INT_MIN;
        maxfromroot(root,ret);
        return ret;
    }
    int maxfromroot(TreeNode *root,int &sum)
    {
        if(!root)
            return 0;
        int l=max(0,maxfromroot(root->left,sum));
        int r=max(0,maxfromroot(root->right,sum));
        sum=max(l+r+root->val,sum);
        return max(l,r)+root->val;
    }

    
};