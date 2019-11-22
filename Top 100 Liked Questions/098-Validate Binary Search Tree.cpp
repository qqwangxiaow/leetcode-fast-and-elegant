//inorder by adding pre
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *pre=NULL;
        return isvalid(root,pre);
    }
    bool isvalid(TreeNode *root,TreeNode *&pre)
    {
        if(!root)
            return true;
        if(!isvalid(root->left,pre))
            return false;
        if(pre&&pre->val>=root->val)
            return false;
        pre=root;
        return isvalid(root->right,pre);
    }
};

//using interative inorder traversal
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
            root=s.top(),s.pop();
            if(pre&&root->val<=pre->val)
                return false;
            pre=root;
            root=root->right;
        }
        return true;
    }
};