//more elegent binary search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l=0,r=A.size()-1,m;
        while(l<r)
        {
            m=l+(r-l)/2;
            if(A[m]<A[m+1])
                l=m+1;
            else 
                r=m;   
        }
        return r;
    }
};
//more concise
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return max_element(A.begin(),A.end())-A.begin();
    }
};

//easy
class Solution {
public:
    int peakIndexInMountainArray(vector<int> A) {
        for (int i = 1; i + 1 < A.size(); ++i) if (A[i] > A[i + 1]) return i;
        return 0;
    }
};