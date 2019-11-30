//straight forward
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int>ret;
        int sum=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]%2==0)
                sum+=A[i];
        }
        for(auto querie:queries)
        {
            if(querie[0]%2==0&&A[querie[1]]%2==0)
                sum+=querie[0];
            else if(querie[0]%2!=0&&A[querie[1]]%2!=0)
                sum+=(A[querie[1]]+querie[0]);
            else if(querie[0]%2==0&&A[querie[1]]%2!=0)
                sum=sum;
            else if(querie[0]%2!=0&&A[querie[1]]%2==0)  
                sum-=A[querie[1]]; 
            A[querie[1]]+=querie[0];
            ret.push_back(sum);
        }
        return ret;

    }
};