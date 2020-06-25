class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ret=1e7;
        auto update=[&](int sum)
        {
            if(abs(sum-target)<abs(ret-target))
                ret=sum;
        };
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==target)
                {
                   return sum;
                }
                update(sum);
                if(sum<target)
                {
                    l++;
                    while(l<r&&nums[l]==nums[l-1])
                    {
                        l++;
                    }
                }
                else
                {
                    r--;
                    while(l<r&&nums[r]==nums[r+1])
                    {
                        r--;
                    }
                }

            }
        }
        return ret;
    }
};