//题目看清
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=accumulate(A.begin(),A.end(),0);
        if(sum%3)
            return false;
        int count=0;
        int flag=0;
        for(int i=0;i<A.size();i++)
        {
            count+=A[i];
            if(count==sum/3)
            {
                flag++;
                count=0;
            }
            if(flag==3)
                return true;     
        }
        return false;

    }
};
