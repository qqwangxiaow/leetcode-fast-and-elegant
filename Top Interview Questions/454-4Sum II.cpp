//using map
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int>mymap;
        int ret=0;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                mymap[A[i]+B[j]]++;
            }
        }
        for(int i=0;i<C.size();i++)
        {
            for(int j=0;j<D.size();j++)
            {
                int tmp=-(C[i]+D[j]);
                ret+=mymap[tmp];
            }
        }
        return ret;

        
    }
};