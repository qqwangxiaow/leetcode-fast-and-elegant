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

/*用stack非递归*/
class Solution {
public:
    vector<int> preorder(Node* root) {
      vector<int>ret;
      stack<Node*>s;
      if(!root)
        return ret;
      s.push(root);
      while(!s.empty())
      {
          Node* temp=s.top();
          s.pop();
          ret.push_back(temp->val);
          for(int i=temp->children.size()-1;i>=0;i--)
          {
            if(temp->children[i]!=NULL)
              s.push(temp->children[i]);
          }
    
      }
      return ret;
  }
};