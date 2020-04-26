//two dimention LIS
//just to push_back height
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int>ret;
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>&v1,const vector<int>&v2){
            if(v1[0]==v2[0])
            {
                return v1[1]>v2[1];
            }
            return v1[0]<v2[0];
        });
        for(auto envelope:envelopes)
        {
            auto f=lower_bound(ret.begin(),ret.end(),envelope[1]);
            if(f==ret.end())
                ret.push_back(envelope[1]);
            else
                *f=envelope[1];
        }
        return ret.size();
        
    }
};