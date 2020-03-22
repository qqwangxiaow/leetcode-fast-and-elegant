//sort and count
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        int ret=0;
        for(int i=1;i<A.size();i++)
        {
            if(A[i]<=A[i-1])
            {
                int temp=(A[i-1]-A[i]+1);
                A[i]+=temp;
                ret+=temp;
            }
        }
        return ret;
    }
};