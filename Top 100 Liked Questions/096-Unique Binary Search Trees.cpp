//cantalan tree
class Solution {
public:
    int numTrees(int n) {
        vector<int>ret(n+1,0);
        ret[0]=ret[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                ret[i]+=ret[j-1]*ret[i-j];
            }
        }
        return ret[n];
        
    }
};