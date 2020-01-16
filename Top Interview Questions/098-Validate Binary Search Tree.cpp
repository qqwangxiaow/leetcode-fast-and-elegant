//inorder with stack and keep pre
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode *pre=NULL;
        while(root||!s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(pre&&pre->val>=root->val)
                return false;
            pre=root;
            root=root->right;
        }
        return true;
    }
};
//using pre
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *pre=NULL;
        return isValid(root,pre);
    }
    bool isValid(TreeNode* root,TreeNode* &pre)
    {
        if(!root)
            return true;
        if(!isValid(root->left,pre))
            return false;
        if(pre&&root->val<=pre->val)
            return false;
        pre=root;
        return isValid(root->right,pre);
    }
};