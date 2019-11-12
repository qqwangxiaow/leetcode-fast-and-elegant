//math
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxx=A[0],minx=A[0];
        for(auto each:A)
        {
            maxx=max(maxx,each);
            minx=min(minx,each);
        }
        return max(0,maxx-minx-2*K);
    }
};