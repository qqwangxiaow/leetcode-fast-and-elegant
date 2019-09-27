/*recrusive dfs*/
//no global variable
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxcount=0;
        dfs(root,maxcount);
        return maxcount;                                
    }
    int dfs(TreeNode *root,int &maxcount)
    {
        if(!root)
            return 0;
        int left=dfs(root->left,maxcount);
        int right=dfs(root->right,maxcount);
        int arrowleft=0,arrowright=0;
        if(root->left&&root->left->val==root->val)
        {
            arrowleft=left+1;
        }
        if(root->right&&root->right->val==root->val)
        {
            arrowright=right+1;
        }
        maxcount=max(maxcount,arrowleft+arrowright);
        return max(arrowleft,arrowright);
    }
};
//global variable
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        maxcount=0;
        arrowlength(root);
        return maxcount;                                
    }
    int arrowlength(TreeNode *root)
    {
        if(!root)
            return 0;
        int left=arrowlength(root->left);
        int right=arrowlength(root->right);
        int arrowleft=0,arrowright=0;
        if(root->left&&root->left->val==root->val)
        {
            arrowleft=left+1;
        }
        if(root->right&&root->right->val==root->val)
        {
            arrowright=right+1;
        }
        maxcount=max(maxcount,arrowleft+arrowright);
        return max(arrowleft,arrowright);
    }
private:
    int maxcount=0;
};