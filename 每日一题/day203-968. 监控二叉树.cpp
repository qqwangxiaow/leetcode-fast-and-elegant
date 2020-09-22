/**
0无覆盖
1有摄像头
2有覆盖
 */
class Solution {
public:
    int ret;
    int minCameraCover(TreeNode* root) {
        ret=0;
        if(traversal(root)==0)
        {
            ret++;
        }
        return ret;
    }
    int traversal(TreeNode *root)
    {
        if(!root)
        {
            return 2;
        }
        int left=traversal(root->left);
        int right=traversal(root->right);
        if(left==2&&right==2)
            return 0;
        if(!left||!right)
        {
            ret++;
            return 1;
        }
        if(left==1||right==1)
            return 2;
        
        return -1;
    }
    
};