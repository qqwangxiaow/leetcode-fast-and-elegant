/*DFS*/
class Solution {
public:
    int maxDepth(Node* root) {
       if(!root)
           return 0;
        int depth=0;
        for(auto child:root->children)
            depth=max(depth,maxDepth(child));
        return depth+1;
            
            
        
        
    }
};