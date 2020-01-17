//recrusive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
    }
    bool ismirror(TreeNode *t1,TreeNode *t2)
    {
        if(!t1||!t2)
            return t1==t2;
        else if(t1->val!=t2->val)
            return false;
        else return ismirror(t1->left,t2->right)&&ismirror(t1->right,t2->left);
    }
};
//using two queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *t1,*t2;
        if(!root)
            return true;
        queue<TreeNode*>q1,q2;
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