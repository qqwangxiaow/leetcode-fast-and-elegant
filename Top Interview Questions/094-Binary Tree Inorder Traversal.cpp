//iteratively
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
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
            ret.push_back(root->val);
            root=root->right;
        }
        return ret;
    }
};

//recrusive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        inorder(root,ret);
        return ret;
    }
    void inorder(TreeNode* root,vector<int>&ret)
    {
        if(!root)
            return;
        if(root->left)
            inorder(root->left,ret);
        ret.push_back(root->val);
        if(root->right)
            inorder(root->right,ret);
        
    }
};
//iteratively version 2
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        stack<TreeNode*>s;
        if(!root)
            return ret;
        s.push(root);
        TreeNode *temp=NULL;
        while(!s.empty())
        {
            temp=s.top();
            if(temp->left)
            {
                s.push(temp->left);
                temp->left=NULL;
            }
            else
            {
                ret.push_back(temp->val);
                s.pop();
                if(temp->right)
                    s.push(temp->right);
            }
            
        }
        return ret;
        
    }
};