//two pass
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n=S.size();
        vector<int>res(n,n);
        int pos=-n;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]==C) pos=i;
            res[i]=min(abs(i-pos),res[i]);
        
        }
        for(int i=n-1;i>=0;i--)
        {
            if(S[i]==C)
                pos=i;
            res[i]=min(res[i],abs(i-pos));
        }
        return res;
        
        
    }
};