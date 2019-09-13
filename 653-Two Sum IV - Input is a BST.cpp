/*using set*/
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int>myset;
        return dfs(root,myset,k);
    }
    bool dfs(TreeNode *root,set<int>&myset,int k)
    {
        if(!root)
            return false;
        if(myset.find(k-root->val)!=myset.end())
        {
            return true;   
        }
        else 
        {
            myset.insert(root->val);
            return dfs(root->left,myset,k)||dfs(root->right,myset,k);
        }
        
    }
    
};
/*inorder then two pointers*/
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l=0,r=myvec.size()-1;
        while(l<r)
        {
            int sum=myvec[l]+myvec[r];
            if(sum==k)
                return true;
            else if(sum<k)
            {
                l++;
                
            }
            else r--;
        }
        return false;
        
    }
    void inorder(TreeNode *root)
    {
        if(!root)
            return;
        inorder(root->left);
        myvec.push_back(root->val);
        inorder(root->right);
    }
private:
    vector<int>myvec;
    
};