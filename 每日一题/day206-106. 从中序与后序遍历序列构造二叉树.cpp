/**
dont forget  dis=int dis=f-inorder.begin()-l;
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode *helper(vector<int>&inorder,vector<int>&postorder,int l,int r,int ll,int rr)
    {
        if(l>r||ll>rr)
            return nullptr;
        auto f=find(inorder.begin()+l,inorder.begin()+r,postorder[rr]);
        int dis=f-inorder.begin()-l;
        TreeNode *root=new TreeNode(postorder[rr]);
        root->left=helper(inorder,postorder,l,l+dis-1,ll,ll+dis-1);
        root->right=helper(inorder,postorder,l+dis+1,r,ll+dis,rr-1);
        return root;

    }
};