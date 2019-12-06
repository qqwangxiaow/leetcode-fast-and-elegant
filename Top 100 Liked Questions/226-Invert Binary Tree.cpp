//recrusive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        return root;
    }
};
//non-recrusive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *temp=s.top();
            s.pop();
            if(temp)
            {
                s.push(temp->left);
                s.push(temp->right);
                swap(temp->left,temp->right);
            }
            
        }
        return root;
    }
};