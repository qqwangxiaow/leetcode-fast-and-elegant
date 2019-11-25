//recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return ismirror(root->left,root->right);
    }
    bool ismirror(TreeNode *root1,TreeNode *root2)
    {
        if(!root1||!root2)
            return root1==root2;
        if(root1->val!=root2->val)
            return false;
        else 
            return ismirror(root1->left,root2->right)&&ismirror(root1->right,root2->left);
        return true;
    }
};

//iterative using two queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *t1,*t2;
        if(!root)
            return true;
        queue<TreeNode *>q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty()&&!q2.empty())
        {
            t1=q1.front();
            q1.pop();
            t2=q2.front();
            q2.pop();
            if(!t1&&!t2)
                continue;
            if(!t1||!t2)
                return false;
            if(t1->val!=t2->val)
                return false;
            q1.push(t1->left);
            q1.push(t1->right);
            q2.push(t2->right);
            q2.push(t2->left);
        }
        return true;
    }
    
};
