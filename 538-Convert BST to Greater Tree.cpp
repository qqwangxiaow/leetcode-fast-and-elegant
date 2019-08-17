/*逆中序遍历*/
class Solution {
public:
    int cur_sum=0;
    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
    void travel(TreeNode *root)
    {
        if(!root)
            return;
        if(root->right)
            travel(root->right);
        cur_sum+=root->val;
        root->val=cur_sum;
        if(root->left)
            travel(root->left);
        
    }
};


/*没局部变量版本*/
class Solution {
public:
    int cur_sum=0;
    TreeNode* convertBST(TreeNode* root) {
        travel(root,0);
        return root;
    }
    int travel(TreeNode *root,int val)
    {
        if(!root)
           return val;
        int right=travel(root->right,val);
        int left=travel(root->left,root->val+right);
        root->val+=right;
        return left;
        
    }
};