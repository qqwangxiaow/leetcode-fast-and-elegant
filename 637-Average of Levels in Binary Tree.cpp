/*BFS*/
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        vector<double>ret;
        int temp=0;
        while(!q.empty())
        {
            long sum=0;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *cur=q.front();
                q.pop();
                sum+=cur->val;
                if(cur->left)
                {
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    q.push(cur->right);
                }
                
            }
            ret.push_back((double)sum/n);
        }
        return ret;
        
        
    }
};