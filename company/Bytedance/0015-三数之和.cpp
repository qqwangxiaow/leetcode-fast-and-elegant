//don't forget if(i==0||nums[i]!=nums[i-1])
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ret;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0||nums[i]!=nums[i-1])
            {
                int l=i+1,r=nums.size()-1,target=0-nums[i];
                while(l<r)
                {
                    if(nums[l]+nums[r]==target)
                    {
                        ret.push_back({nums[i],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l<r&&nums[l-1]==nums[l])
                            l++;
                        while(l<r&&nums[r]==nums[r+1])
                            r--;
                    }
                    else if(nums[l]+nums[r]<target)
                        l++;
                    else
                        r--;
                }
                
            }
            
        }
        return ret;

    }
};