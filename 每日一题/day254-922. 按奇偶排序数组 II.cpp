//while(even<n)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even=0,odd=1;
        int n=A.size();
        while(even<n&&odd<n)
        {
            while(even<n&&A[even]%2==0)
                even+=2;
            while(odd<n&&A[odd]%2==1)
                odd+=2;
            if(even<n&&odd<n)
                swap(A[even],A[odd]);
        }
        return A;
    }

};