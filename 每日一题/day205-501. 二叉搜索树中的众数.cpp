/**
inorder and keep pre
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        ret.clear();
        pre=nullptr;
        maxcount=0;
        count=0;
        search(root);
        return ret;
    }
    void search(TreeNode *root)
    {
        if(!root)
            return;
        search(root->left);
        if(pre&&pre->val==root->val)
        {
            count++;
        }
        else
        {
            count=1;
        }
        pre=root;
        if(count>maxcount)
        {
            maxcount=count;
            ret.clear();
            ret.push_back(root->val);
        }
        else if(count==maxcount)
            ret.push_back(root->val);


        search(root->right);
    }
private:
    vector<int>ret;
    TreeNode *pre;
    int maxcount;
    int count;
};