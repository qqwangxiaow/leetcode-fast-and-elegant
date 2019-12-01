//take K itselft as a carry
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        for(int i=A.size()-1;i>=0&&K>0;i--)
        {
            A[i]+=K;
            K=A[i]/10;
            A[i]=A[i]%10;
        }
        while(K)
        {
            A.insert(A.begin(),K%10);
            K=K/10;
        }
        return A;
    }
};