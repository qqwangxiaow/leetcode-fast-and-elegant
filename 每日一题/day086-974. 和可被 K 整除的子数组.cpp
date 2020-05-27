//prefix sum
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int,int>mymap={{0,1}};
        int sum=0,ret=0;
        for(auto each:A)
        {
            sum+=each;
            int mod=(sum%K+K)%K;
            if(mymap.count(mod))
            {
                ret+=mymap[mod];
            }
            mymap[mod]++;
            
        }
        return ret;
    }
};