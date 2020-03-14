class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>myvec;
        for(auto num:nums)
        {
            auto f=lower_bound(myvec.begin(),myvec.end(),num);
            if(f==myvec.end())
            {
                myvec.push_back(num);
            }
            else
            {
                *f=num;
            }
        }
        return myvec.size();
    }   