/*sort and searsh */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i==0||(nums[i]!=nums[i-1]))
            {
                int l=i+1,r=nums.size()-1,num=0-nums[i];
                while(l<r)
                {
                    if(nums[l]+nums[r]==num)
                    {
                        ret.push_back({nums[i],nums[l],nums[r]});
                        while(l<r&&nums[l]==nums[l+1]) l++;
                        while(l<r&&nums[r]==nums[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if(nums[l]+nums[r]<num)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                    
                }
            }
        }
        return ret;

    }
};

