//new vector and use two pointers
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>ret(A.size(),0);
        int i=0,j=A.size()-1;
        for(int p=A.size()-1;p>=0;p--)
        {
            if(A[i]*A[i]<A[j]*A[j])
            {
                ret[p]=A[j]*A[j];
                j--;
            }
            else
            {
                ret[p]=A[i]*A[i];
                i++;
            }
        }
        return ret;
    }
};