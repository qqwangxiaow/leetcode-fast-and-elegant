class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ret=0,mx=A[0]+0;
        for(int i=1;i<A.size();i++)
        {
            ret=max(ret,mx+A[i]-i);
            mx=max(mx,A[i]+i);
        }
        return ret;

    }
};