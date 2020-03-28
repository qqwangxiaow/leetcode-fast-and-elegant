//lower_bound
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ret;
        for(int i=0;i<nums.size();i++)
        {
            auto f=lower_bound(ret.begin(),ret.end(),nums[i]);
            if(f==ret.end())
            {
                ret.push_back(nums[i]);
            }
            else
            {
                *f=nums[i];
            }
        }
        return ret.size();
    }
};