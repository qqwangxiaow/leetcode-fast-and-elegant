/**
 下一层一定是层数一定+1 如果不是 那么就是空
 getval 获得值
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int start=0;
        return preorder(S,start,0); 
    }
    TreeNode* preorder(string &S,int &start,int lv)
    {
        int nextlv=getlv(S,start);
        if(nextlv!=lv)
            return nullptr;
        start+=lv;
        int val=getval(S,start);
        TreeNode *node=new TreeNode(val);
        node->left=preorder(S,start,lv+1);
        node->right=preorder(S,start,lv+1);
        return node;

    }
    int getlv(string &S,int &start)
    {
        int cnt=0;
        while(start<S.size()&&S[start+cnt]=='-')
        {
            cnt++;
        }
        return cnt;
    }
    int getval(string &S,int &start)
    {
        int ret=0;
        while(start<S.size()&&S[start]!='-')
        {
            ret*=10;
            ret+=S[start]-'0';
            start++;
        }
        return ret;
    }

};