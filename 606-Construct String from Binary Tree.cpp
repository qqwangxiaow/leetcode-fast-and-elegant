/*注意左子树为空，加（）*/
class Solution {
public:
    string tree2str(TreeNode* t) {
        string ret;
        if(!t) return "";
        ret+=to_string(t->val);
        string left=tree2str(t->left);
        string right=tree2str(t->right);
        if(left==""&&right=="") return ret;
        if(left=="") return ret+"()"+"("+right+")";
        if(right=="") return ret+"("+left+")";
        return ret+"("+left+")"+"("+right+")";
        return ret;
 
    }
};