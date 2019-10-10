//recursive
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        addingpar(ret, "", n, 0);
        return ret;
    }
    void addingpar(vector<string>&ret,string temp,int n,int m)
    {
        if(m==0&&n==0)
        {
            ret.push_back(temp);
            return;
        }
        if(n>0) addingpar(ret,temp+'(',n-1,m+1);
        if(m>0) addingpar(ret,temp+')',n,m-1);
    }
    
};
