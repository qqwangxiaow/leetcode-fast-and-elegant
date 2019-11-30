//inorder iterative
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        stack<TreeNode*>s;
        s.push(root);
        int x=root->val;
        while(!s.empty())
        {
            while(root->left)
            {
                root=root->left;
                s.push(root);
            }
            root=s.top();
            s.pop();
            if(root->val!=x)
                return false;
            if(root->right)
            {
                s.push(root->right);
                root=root->right;
            }

        }
        return true;
    }
};
//recrusive 
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
       return (!root->left||root->left->val==root->val&&isUnivalTree(root->left))&&
           (!root->right||root->right->val==root->val&&isUnivalTree(root->right));
    }
};