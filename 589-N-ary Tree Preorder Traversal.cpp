/*递归*/
class Solution {
public:
    vector<int> preorder(Node* root) {
      vector<int>ret;
      travel(root,ret);
      return ret;   
    }
  void travel(Node *root,vector<int>&ret)
  {
        if(!root) return;
        ret.push_back(root->val);
    for(auto each:root->children)
    {
      travel(each,ret);
    }
  }
};