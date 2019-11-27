//recrusive
//It's easier to transfer parameters like .size()
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildhelper(preorder,inorder,0,preorder.size(),0,inorder.size());
    }
    TreeNode *buildhelper(vector<int>&pre,vector<int>&inorder,int l,int r,int ll,int rr)
    {
        if(l>=r||ll>=r)
            return NULL;
        TreeNode *root=new TreeNode(pre[l]);
        auto f=find(inorder.begin()+ll,inorder.begin()+rr,pre[l]);
        int dis=f-inorder.begin()-ll;
        root->left=buildhelper(pre,inorder,l+1,l+1+dis,ll,ll+dis);
        root->right=buildhelper(pre,inorder,l+dis+1,r,ll+dis+1,rr);
        return root;   
    }
};