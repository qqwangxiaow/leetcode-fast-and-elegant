class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto f=lower_bound(nums.begin(),nums.end(),target);
        int ret=0;
        if(f==nums.end())
            return ret;
        else
        {
            for(auto it=f;it!=nums.end()&&*it==target;it++)
            {
                ret++;
            }
        }
        return ret;

    }
};