/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        queue<TreeNode*>q;
        if(!root)
            return ret;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>temp{};
            for(int i=0;i<n;i++){
                TreeNode* tmp=q.front();
                q.pop();
                temp.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);  
            }
            if(flag % 2 == 1){
                reverse(temp.begin(),temp.end());
            }
            flag++;
            ret.push_back(temp);
        }
        return ret;
    }
};