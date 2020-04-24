//upper_bound 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ret;
        for(auto num:nums)
        {
            auto f=lower_bound(ret.begin(),ret.end(),num);
            if(f==ret.end())
                ret.push_back(num);
            else
                *f=num;
        }
        return ret.size();
    }
};