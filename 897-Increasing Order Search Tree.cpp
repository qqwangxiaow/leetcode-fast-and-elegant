//inorder 用cur保存上一个node位置
class Solution {
    public:
        TreeNode* increasingBST(TreeNode* root) {
            if(!root)
                return NULL;
            TreeNode *temp=new TreeNode(0);
            cur=temp;
            inorder(root);
            return temp->right;
        
        }
        void inorder(TreeNode *root)
        {
            if(!root)
                return;
            inorder(root->left);
            root->left=NULL;
            cur->right=root;
            cur=root;
            inorder(root->right);
        }
    private:
        TreeNode *cur;
        
    };
//awesome
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root,TreeNode *tail=NULL) {
        if(!root)
            return tail;
        TreeNode *res=increasingBST(root->left,root);
        root->left=NULL;
        root->right=increasingBST(root->right,tail);
        return res;  
    }
    
};