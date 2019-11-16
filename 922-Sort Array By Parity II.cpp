//注意把判断条件写在&前面 否则越界
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even=0,odd=1;
        while(even<A.size()&&odd<A.size())
        {
            while(even<A.size()&&A[even]%2==0)
                even+=2;
            while(odd<A.size()&&A[odd]%2==1)
                odd+=2;
            if(even<A.size()&&odd<A.size())
                swap(A[even],A[odd]);
        }
        return A;
        
    }
};