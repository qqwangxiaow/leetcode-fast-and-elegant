//must add return 0;
//iterative
//while(root||!s.empty())
//while(root)
//root=root->right
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        stack<TreeNode*>s;
        while(root||!s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            count++;
            if(count==k)
                return root->val;
            root=root->right;  
        } 
        return 0;
    }   
};
//recrusive
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ret=0;
        int count=0;
        inorder(root,count,k,ret);
        return ret;
    }
    void inorder(TreeNode *root,int &count,int k,int &ret)
    {
        if(!root)
            return;
        inorder(root->left,count,k,ret);
        count++;
        if(count==k)
            ret=root->val;
        inorder(root->right,count,k,ret);
    }
};