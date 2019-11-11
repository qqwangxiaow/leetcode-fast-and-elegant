//clean code
vector<int> sortArrayByParity(vector<int> &A) {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) swap(A[i++], A[j]);
        return A;

}
//partition
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l=0,r=A.size()-1;
        while(l<r)
        {
            while(A[l]%2==0&&l<r)
                l++;
            while(A[r]%2==1&&l<r)
                r--;
            if(l<r)
                swap(A[l],A[r]);
        }
        return A;
    }
};