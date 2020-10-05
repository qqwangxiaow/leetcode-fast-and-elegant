//1.sort
//2.减少循环次数
//3.O(n3)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ret;
        if(nums.size()<4)
            return ret;
        int len=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)
                break;
            if(nums[i]+nums[len-1]+nums[len-2]+nums[len-3]<target)
                continue;
            for(int j=i+1;j<len-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) 
                    break;
                if (nums[i]+nums[j]+nums[len-2]+nums[len-1]<target) 
                    continue;    
                int sum=target-nums[i]-nums[j];
                int l=j+1,r=len-1;
                while(l<r)
                {
                    int sum=nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target)
                    {
                        ret.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;r--;
                        while(l<r&&nums[l]==nums[l-1])
                            l++;
                        while(l<r&&nums[r]==nums[r+1])
                            r--;
                    }
                    else if(sum<target)
                        l++;
                    else
                        r--;
                }  
            }
        }
        return ret;
    }
};