//two pointer is better
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len=A.size();
        vector<int>ret(A.size(),0);
        int l=0,r=len-1,index=r;
        while(l<=r)
        {
            if(A[l]*A[l]<A[r]*A[r])
            {
                ret[index--]=A[r]*A[r--];
            }
            else
            {
                ret[index--]=A[l]*A[l++];
            }
        }
        return ret;

    }
};